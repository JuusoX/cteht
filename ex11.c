// Created by PC Juuso on 13.2.2026.
#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl) {
    int count = 0;
    int i;

    if (repl == NULL || repl[0] == '\0' || repl[1] == '\0') {
        return 0;
    }

    char from = repl[0];
    char to   = repl[1];

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == from) {
            str[i] = to;
            count++;
        }
    }

    return count;
}

int main(void) {
    char text[200];
    char repl[10];
    int count;

    printf("Anna muunnettava merkkijono: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 0;
    }

    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    printf("Anna 2 merkin merkkijono: ");
    if (fgets(repl, sizeof(repl), stdin) == NULL) {
        return 0;
    }
    len = strlen(repl);
    if (len > 0 && repl[len - 1] == '\n') {
        repl[len - 1] = '\0';
    }

    count = replace_char(text, repl);

    if (count > 0) {
        printf("Korvattiin %d merkki.\n", count);
        printf("Tulos: %s\n", text);
    } else {
        printf("String was not modified\n");
    }

    return 0;
}
