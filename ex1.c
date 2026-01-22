// Created by PCJuuso on 22.1.2026.
#include <stdio.h>

int main(void) {
    double bussi_hinta = 0.0;
    double taksi_hinta = 0.0;
    double rahat = 0.0;

    printf("Anna bussilipun hinta: ");
    scanf("%lf", &bussi_hinta);

    printf("Anna taksimatkan hinta: ");
    scanf("%lf", &taksi_hinta);

    printf("Kuinka paljon rahaa sinulla on: ");
    scanf("%lf", &rahat);

    // tarkistetaan varat
    if (rahat < bussi_hinta && rahat < taksi_hinta) {
        printf("Sinun taytyy kavella. Heippa\n");
        return 0;
    }

    while (1) {
        // alku tarkistus
        if (rahat < bussi_hinta && rahat < taksi_hinta) {
            printf("Sinun taytyy kavella. Heippa\n");
            break;
        }

        printf("Sinulla on %.2f euroa rahaa.\n", rahat);
        printf("Haluatko ottaa\n");
        printf(" 1) bussin (%.2f euroa)\n", bussi_hinta);
        printf(" 2) taksin (%.2f euroa)\n", taksi_hinta);
        printf("Anna valintasi: ");

        int valinta = 0;
        if (scanf("%d", &valinta) != 1) {
            while (getchar() != '\n')
                ;
            printf("Virheellinen syote\n");
            continue;
        }

        if (valinta == 1) {
            printf("Valitsit bussin.\n");
            if (rahat >= bussi_hinta) {
                rahat -= bussi_hinta;
            } else {
                printf("Sinulla ei ole tarpeeksi rahaa bussiin.\n");
            }
        } else if (valinta == 2) {
            printf("Valitsit taksin.\n");
            if (rahat >= taksi_hinta) {
                rahat -= taksi_hinta;
            } else {
                printf("Sinulla ei ole tarpeeksi rahaa taksiin.\n");
            }
        } else {
            printf("Virheellinen valinta.\n");
        }
    }

    return 0;
}



