// Created by PC Juuso on 13.2.2026.
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];

    while (1) {
        printf("Anna merkkijono: ");
        if (fgets(str, sizeof(str), stdin) == NULL) {
            return 0;
        }

        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }

        printf("Pituus: %zu\n", len);

        if (strcmp(str, "stop") == 0) {
            break;
        }
    }

    return 0;
}
