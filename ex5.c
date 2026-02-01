// Created by PC Juuso on 1.2.2026.
#include <stdio.h>

/* Lukee kokonaisluvun 1-6. */
int read_range(int low, int high) {
    int n;

    while (1) {
        printf("Syota luku valilta %d - %d: ", low, high);
        int ok = scanf("%d", &n);

        if (ok != 1) {
            /* vaaran tyyppinen syote, esim. teksti */
            while (getchar() != '\n') {
            }
            printf("Virhe: syote ei ollut kokonaisluku.\n");
            continue;
        }

        /* tyhjennetaan rivin loppu onnistuneen luvun jalkeen */
        while (getchar() != '\n') {
        }

        if (n < low || n > high) {
            printf("Virhe: luvun tulee olla valilta %d - %d.\n", low, high);
        } else {
            return n;  /* kelvollinen luku */
        }
    }
}

int main(void) {
    int kierros;
    int pelaaja;
    int kone;

    printf("Pelataan noppa-pelia!\n");

    for (kierros = 1; kierros <= 3; kierros = kierros + 1) {
        printf("Heita noppaa ja syota tulos.\n");
        pelaaja = read_range(1, 6);

        if (pelaaja == 6) {
            kone = 6;
            printf("Minulla on %d. Tasapeli!\n", kone);
        } else {
            kone = pelaaja + 1;
            printf("Minulla on %d. Mina voitin!\n", kone);
        }
    }

    printf("Parempi onni ensi kerralla. Hei hei!\n");

    return 0;
}



