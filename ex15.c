// Created by PC Juuso on 26.2.2026.
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main(void) {
    char filename[256];
    menu_item items[MAX_ITEMS];
    int count = 0;

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

    while (count < MAX_ITEMS &&
           fscanf(f, " %49[^;]; %lf", items[count].name, &items[count].price) == 2) {
        count++;
           }

    fclose(f);

    for (int i = 0; i < count; i++) {
        printf("%8.2f  %s\n", items[i].price, items[i].name);
    }

    return 0;
}

