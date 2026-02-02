// Created by PC Juuso on 2.2.2026. //
#include <stdio.h>
#include <stdbool.h>

// Lukee positiivisen kokonaisluvun. Tallennusn tarkistus kelvollinen ja positiivinen. //
bool lue_positiivinen(int *arvo) {
    int syote;

    printf("Anna positiivinen luku: ");
    if (scanf("%d", &syote) != 1) {
        while (getchar() != '\n');   // tyhjennetään väärän syötteen
        return false;
    }
    if (syote <= 0) {
        return false;
    }

    *arvo = syote;
    return true;
}

int main(void) {
    int arvaus;
    int virhe_kertoja = 0;

    while (virhe_kertoja < 3) {
        printf("Arvaa paljonko minulla on rahaa!\n");

        if (!lue_positiivinen(&arvaus)) {
            printf("Virheellinen syote\n");
            virhe_kertoja++;
            continue;
        }

        int rahat = arvaus * 2 + 20;
        printf("Et arvannut oikein. Minulla on %d euroa.\n", rahat);
    }

    printf("Luovutan! Nahaan myohemmin!\n");
    return 0;
}

