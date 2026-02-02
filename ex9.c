// Created by PC Juuso on 2.2.2026.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int etsi_ensimmainen(const unsigned int *taulukko, unsigned int haettava) {
    int i = 0;

    while (taulukko[i] != 0) {
        if (taulukko[i] == haettava) {
            return i;
        }
        i++;
    }

    return -1;
}

int main(void) {
    unsigned int taulukko[20];

    srand((unsigned)time(NULL));

    // 19 ensimmäistä: satunnaiset luvut 1–20
    for (int i = 0; i < 19; i++) {
        taulukko[i] = (rand() % 20) + 1;
    }
    taulukko[19] = 0;

    printf("Taulukon sisalto:\n");
    for (int i = 0; i < 20; i++) {
        printf("%u\n", taulukko[i]);
    }

    while (1) {
        unsigned int haettava;
        printf("Anna etsittava luku (0 lopettaa): ");

        int ok = scanf("%u", &haettava);
        if (ok != 1) {
            while (getchar() != '\n')
                ;
            printf("Virheellinen syote\n");
            continue;
        }

        if (haettava == 0) {
            break;
        }

        int indeksi = etsi_ensimmainen(taulukko, haettava);
        if (indeksi == -1) {
            printf("Lukua ei loytynyt\n");
        } else {
            printf("Luku loytyi indeksista %d\n", indeksi);
        }
    }

    return 0;
}

