// Created by PC Juuso on 23.1.2026.
#include <stdio.h>

int main(void) {
    double tulot[12];
    double verot[12];

    double vero_prosentti = 0.0;
    double raja = 0.0;
    double korkea_vero_prosentti = 0.0;

    printf("Anna vero prosentti: ");
    scanf("%lf", &vero_prosentti);

    printf("Anna tuloraja: ");
    scanf("%lf", &raja);

    printf("Anna suurempi vero prosentti rajan ylittaville tuloille: ");
    scanf("%lf", &korkea_vero_prosentti);

    // Luetaan 12 kuukauden tulot
    for (int i = 0; i < 12; i++) {
        printf("Anna tulot kuukaudelle %d: ", i + 1);
        scanf("%lf", &tulot[i]);
    }

    double vuoden_tulot = 0.0;
    // Laskee kk verot
    for (int i = 0; i < 12; i++) {
        const double tulo = tulot[i];
        double vero_kuukaudelle = 0.0;

        double ennen = vuoden_tulot;
        double jalkeen = vuoden_tulot + tulo;

        if (ennen >= raja) {
            // tarkistaa rajaa
            vero_kuukaudelle = tulo * korkea_vero_prosentti / 100.0;
        } else if (jalkeen <= raja) {
            // tarkistaa rajaa
            vero_kuukaudelle = tulo * vero_prosentti / 100.0;
        } else {
            // muuttaa veroa
            double osa_matala = raja - ennen;
            double osa_korkea = jalkeen - raja;

            vero_kuukaudelle =
                osa_matala * vero_prosentti / 100.0 +
                osa_korkea * korkea_vero_prosentti / 100.0;
        }

        verot[i] = vero_kuukaudelle;
        vuoden_tulot = jalkeen;
    }

    printf("kk        tulot      vero\n");

    for (int i = 0; i < 12; i++) {
        int kk = i + 1;
        printf("%5d %10.2f %9.2f\n", kk, tulot[i], verot[i]);
    }

    return 0;
}
