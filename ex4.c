// Created by PC Juuso on 1.2.2026.
#include <stdio.h>

// Lukee yhden kokonaisluvun ja kysyy uudestaan kunnes onnistuu. //
int read_integer(void) {
    int n;
    int ok;

    while (1) {
        ok = scanf("%d", &n);

        if (ok == 1) {
            // tyhjennetaan rivin loppu //
            while (getchar() != '\n') {
            }
            return n;
        } else {
            // lukeminen epaonnistuu ja tyhjennetaan //
            while (getchar() != '\n') {
            }
            printf("vaara syote\n");
            printf("Syota positiivinen luku jatkaaksesi tai negatiivinen lopettaaksesi: ");
        }
    }
}

int main(void) {
    int luku;
    int summa = 0;
    int maara = 0;

    while (1) {
        printf("Syota positiivinen luku jatkaaksesi tai negatiivinen lopettaaksesi: ");
        luku = read_integer();

        if (luku < 0) {
            break;
        }

        summa = summa + luku;
        maara = maara + 1;
    }

    if (maara > 0) {
        double keskiarvo = (double)summa / (double)maara;
        printf("Syotit %d positiivista lukua. Keskiarvo on: %.3f\n",
               maara, keskiarvo);
    } else {
        printf("Et syottanyt yhtakaan positiivista lukua.\n");
    }

    return 0;
}


