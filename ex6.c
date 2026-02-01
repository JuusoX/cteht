// Created by PC Juuso on 1.2.2026.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tulostaa valikon //
void tulosta_valikko(void) {
    printf("\nValitse toiminto:\n");
    printf("1) Heita D6\n");
    printf("2) Heita D10\n");
    printf("3) Lopeta\n");
}

// Lukee valinnan 1–3 ja validoi syotteen. //
int lue_valinta(void) {
    int valinta;
    int ok;

    while (1) {
        printf("Syota valinta (1-3): ");
        ok = scanf("%d", &valinta);

        if (ok != 1) {
            // ei kokonaislukua //
            while (getchar() != '\n') {
            }
            printf("Virhe: syote ei ollut kokonaisluku.\n");
            continue;
        }

        while (getchar() != '\n') {
        }

        if (valinta < 1 || valinta > 3) {
            printf("Virhe: valinnan tulee olla 1 - 3.\n");
        } else {
            return valinta;
        }
    }
}

// Arpoo nopan tuloksen //
int heita_noppa(int min, int max) {
    int tulos;
    tulos = rand() % (max - min + 1) + min;
    return tulos;
}

int main(void) {
    int valinta;
    int tulos;
    int jatka = 1;

    srand((unsigned int)time(NULL));

    while (jatka == 1) {
        tulosta_valikko();
        valinta = lue_valinta();

        if (valinta == 1) {
            tulos = heita_noppa(1, 6);
            printf("D6 tulos: %d\n", tulos);
        } else if (valinta == 2) {
            tulos = heita_noppa(1, 10);
            printf("D10 tulos: %d\n", tulos);
        } else {
            printf("Lopetetaan. Hei!\n");
            jatka = 0;
        }
    }

    return 0;
}
