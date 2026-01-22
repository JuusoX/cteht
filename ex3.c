// Created by PC Juuso on 22.1.2026.
#include <stdio.h>

int main(void)
{
    int maara;      //oppilaiden maara
    int i;

    //kysymys
    printf("Kuinka monta opiskelijaa: ");
    if (scanf("%d", &maara) != 1 || maara <= 0) {
        printf("Virheellinen opiskelijamaara.\n");
        return 1;
    }

    //arvosanat
    int arvosanat[maara];
    for (i = 0; i < maara; i++) {
        arvosanat[i] = -1;
    }

    while (1) {
        int nro;

        printf("\nAnna opiskelijanumero (1 - %d) tai 0 lopettaaksesi: ",
               maara);
        if (scanf("%d", &nro) != 1) {
            while (getchar() != '\n');
            printf("Virheellinen syote!\n");
            continue;
        }

        if (nro == 0) {
            //lopettaa
            break;
        }

        if (nro < 1 || nro > maara) {
            printf("Virheellinen opiskelijanumero!\n");
            continue;
        }

        //kysymyksiä
        while (1) {
            int arvo;

            printf("Anna arvosana (0 - 5) opiskelijalle %d tai -1 peruuttaaksesi: ",
                   nro);

            if (scanf("%d", &arvo) != 1) {
                while (getchar() != '\n');
                printf("Virheellinen syote!\n");
                continue;
            }

            if (arvo == -1) {
                //arvosana ei muutu
                break;
            }

            if (arvo < 0 || arvo > 5) {
                printf("Virheellinen arvosana!\n");
            } else {
                arvosanat[nro - 1] = arvo;
                break;
            }
        }
    }

    //printtaa taulukon
    printf("\nOpiskelija   Arvosana\n");
    for (i = 0; i < maara; i++) {
        printf("%-11d ", i + 1);
        if (arvosanat[i] == -1) {
            printf("N/A\n");
        } else {
            printf("%d\n", arvosanat[i]);
        }
    }

    return 0;
}
