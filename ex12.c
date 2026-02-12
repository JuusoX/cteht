// Created by PC Juuso on 13.2.2026.
#include <stdio.h>
#include <string.h>

int count_words(const char *str, const char *word) {
    int count = 0;
    const char *p;
    size_t wlen;

    if (str == NULL || word == NULL) {
        return 0;
    }

    wlen = strlen(word);
    if (wlen == 0) {
        return 0;
    }

    p = str;
    while (1) {
        const char *found = strstr(p, word);
        if (found == NULL) {
            break;
        }
        count++;

        p = found + wlen;
    }

    return count;
}

int main(void) {
    char line[200];
    char word[100];

    while (1) {
        printf("Anna merkkijono: ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0;
        }
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        printf("Anna sana: ");
        if (fgets(word, sizeof(word), stdin) == NULL) {
            return 0;
        }
        len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }

        if (strcmp(word, "stop") == 0) {
            break;
        }

        printf("Loytyi %d kertaa.\n", count_words(line, word));
    }

    return 0;
}
