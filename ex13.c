// Created by PC Juuso on 26.2.2026.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    char filename[256];
    int value;
    int count = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    printf("Anna tiedoston nimi: ");
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Virhe: tiedoston nimea ei voitu lukea.\n");
        return 1;
    }

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Virhe: tiedostoa '%s' ei voitu avata.\n", filename);
        return 1;
    }

    while (fscanf(f, "%d", &value) == 1) {
        count++;
        if (value < min) min = value;
        if (value > max) max = value;
    }

    fclose(f);

    if (count == 0) {
        printf("Tiedostosta ei loytynyt yhtaan kokonaislukua.\n");
    } else {
        printf("Lukuja: %d\n", count);
        printf("Pienin: %d\n", min);
        printf("Suurin: %d\n", max);
    }

    return 0;
}

