// Created by PC1 on 3.3.2026.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 1000      // Maksimi rivien maara CSV
#define MAX_NAME_LEN 100    // Maksimi huoneen nimen pituus
#define LINE_LEN 256        // Maksimi yhden rivin pituus

//Huoneen nimi ja lampotila
typedef struct {
    char room[MAX_NAME_LEN];
    double temp;
} Record;

// Talla poistetaan valilyonnit alusta ja lopusta annetusta merkkijonosta
void trim(char *s) {
    char *p = s;
    size_t len = strlen(p);

    // Tama poistaa valilyonnit lopusta
    while (len > 0 && isspace((unsigned char)p[len - 1])) {
        p[--len] = '\0';
    }
    // Siirtaa osoitinta
    while (*p && isspace((unsigned char)*p)) {
        p++;
        len--;
    }
    // Kopioi siistityn merkkijono takaisin alkuun
    if (p != s) {
        memmove(s, p, len + 1);
    }
}

// Tassa lukee CSV tiedoston ja tayttaa records taulukon
int read_csv(const char *filename, Record records[], int max_records) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Virhe: ei voida avata tiedostoa.\n");
        return -1;
    }

    char line[LINE_LEN];
    int count = 0;

    // Lue otsikkorivi ja ohita se
    if (!fgets(line, sizeof(line), f)) {
        printf("Virhe: tiedosto tyhja.\n");
        fclose(f);
        return -1;
    }

    // Lue data rivit yksi kerrallaan
    while (fgets(line, sizeof(line), f)) {
        char *p = strchr(line, '\n');
        if (p) *p = '\0';

        // Ohita tyhjat rivit
        if (line[0] == '\0') {
            continue;
        }

        // Rivit oikein: ensin lampotila, sitten huone
        char *temp_str = strtok(line, ",");
        char *room_str = strtok(NULL, ",");

        if (!temp_str || !room_str) {
            printf("Varoitus: virheellinen rivi ohitetaan.\n");
            continue;
        }

        trim(temp_str);
        trim(room_str);

        // Tassa lampotila tekstista doubleksi
        char *endptr;
        double t = strtod(temp_str, &endptr);
        if (endptr == temp_str || *endptr != '\0') {
            printf("Varoitus: virheellinen lampotila ohitetaan.\n");
            continue;
        }

        // Tarkistus ettei taulukko tayty yli
        if (count >= max_records) {
            printf("Varoitus: liikaa riveja, loput ohitetaan.\n");
            break;
        }

        // Tama Tallentaa lampotilan ja huoneen nimet taulukkoon
        records[count].temp = t;
        strncpy(records[count].room, room_str, MAX_NAME_LEN - 1);
        records[count].room[MAX_NAME_LEN - 1] = '\0';
        count++;
    }

    fclose(f);
    return count;
}

// Tarkistus loytyyko annettu huone taulukosta
int room_exists(Record records[], int n, const char *room) {
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].room, room) == 0) {
            return 1;
        }
    }
    return 0;
}

// Tulostus: Huoneen lampotilat ja palkit
void print_bars_for_room(Record records[], int n, const char *room) {
    printf("%s\n", room);
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].room, room) == 0) {
            double t = records[i].temp;
            printf("%.1f ", t);

            // Lampotila ulkona valilta 0-30 -> tulostetaan X
            if (t < 0.0 || t > 30.0) {
                printf("X\n");
            } else {
                // Yksi viiva vastaa 0.5 astetta
                int dashes = (int)(t / 0.5 + 0.5);
                for (int j = 0; j < dashes; j++) {
                    putchar('-');
                }
                putchar('\n');
            }
        }
    }
}

int main(void) {
    Record records[MAX_LINES];

    // Lue CSV tiedosto taulukkoon
    int n = read_csv("Temperatures.csv", records, MAX_LINES);
    if (n <= 0) {
        return 1;
    }

    char room[MAX_NAME_LEN];

    // Kysy huonetta kunnes saadaan kelvollinen nimi
    while (1) {
        printf("Valitse huone: ");
        if (!fgets(room, sizeof(room), stdin)) {
            printf("Virhe: ei voitu lukea huonetta.\n");
            return 1;
        }

        char *p = strchr(room, '\n');
        if (p) *p = '\0';
        trim(room);

        if (room[0] == '\0') {
            printf("Virhe: tyhja huoneen nimi, yrita uudestaan.\n");
            continue;
        }

        if (!room_exists(records, n, room)) {
            printf("Virhe: huonetta ei loydy, yrita uudestaan.\n");
            continue;
        }

        // Oikea huone loytyi
        break;
    }

    print_bars_for_room(records, n, room);

    return 0;
}

