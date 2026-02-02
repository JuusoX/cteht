// Created by PC Juuso on 2.2.2026.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tulostaa kokonaislukuja taulukosta.//
void tulosta_luvut(const int *taulukko, int maara) {
    for (int i = 0; i < maara; i++) {
        printf("%8d\n", taulukko[i]);
    }
}

int main(void) {
    int luvut[15];

    srand((unsigned)time(NULL));  // satunnaisluku

    for (int i = 0; i < 15; i++) {
        luvut[i] = rand();
    }

    tulosta_luvut(luvut, 15);
    return 0;
}
