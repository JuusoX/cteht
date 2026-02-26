// Created by PC Juuso on 26.2.2026.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LEN 80

int main(void) {
    char filename[256];
    char lines[MAX_LINES][MAX_LEN + 1];
    int count = 0;

    printf("Anna tiedoston nimi: ");
    scanf("%255s", filename);

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Virhe: tiedostoa '%s' ei voitu avata.\n", filename);
        return 1;
    }

    while (count < MAX_LINES && fgets(lines[count], MAX_LEN + 1, f)) {
        count++;
    }
    fclose(f);

    for (int i = 0; i < count; i++) {
        for (int j = 0; lines[i][j]; j++) {
            lines[i][j] = toupper((unsigned char)lines[i][j]);
        }
    }

    f = fopen(filename, "w");
    if (f == NULL) {
        fprintf(stderr, "Kirjoitusvirhe '%s'\n", filename);
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fputs(lines[i], f);
    }
    fclose(f);

    return 0;
}


