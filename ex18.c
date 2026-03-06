// Created by PC Juuso on 6.3.2026.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static unsigned int better_seed(void) {
    unsigned int s = (unsigned int)time(NULL);
    s ^= (unsigned int)(size_t)&s;
    return s;
}

int main(void) {
    srand(better_seed());

    char input[64];

    while (1) {
        printf("Syota luku (0-15) tai negatiivinen lopettaaksesi: ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        input[strcspn(input, "\n")] = '\0';

        char *endptr;
        long val = strtol(input, &endptr, 10);

        if (*endptr != '\0' || endptr == input) {
            printf("Virheellinen syote!\n");
            continue;
        }

        int shift = (int)val;

        if (shift < 0) {
            break;
        }

        if (shift > 15) {
            printf("Luku ei ole valilla 0-15!\n");
            continue;
        }

        unsigned int rnd = ((unsigned int)rand() << 16) ^ (unsigned int)rand();
        printf("Satunnaisluku (hex): %x\n", rnd);

        unsigned int shifted = rnd >> shift;
        unsigned int result = shifted & 0x3F;

        printf("Tulos (hex): %02x\n", result);
    }

    return 0;
}
