// Created by PC1 on 9.3.2026.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verify_nmea(const char *line) {
    const char *start = strchr(line, '$');
    if (!start) return 0;

    const char *star = strchr(start, '*');
    if (!star) return 0;

    unsigned char checksum = 0;
    for (const char *p = start + 1; p < star; p++)
        checksum ^= (unsigned char)*p;

    unsigned int expected = 0;
    if (sscanf(star + 1, "%2X", &expected) != 1)
        return 0;

    return checksum == (unsigned char)expected;
}

int main(void) {
    char filename[100];
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '$' && strchr(line, '*')) {
            if (verify_nmea(line))
                printf("[ OK ] %s\n", line);
            else
                printf("[FAIL] %s\n", line);
        }
    }

    fclose(f);
    return 0;
}
