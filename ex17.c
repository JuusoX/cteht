// Created by PC Juuso on 6.3.2026.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

char random_printable(void) {
    return (char)(33 + rand() % 94);
}

bool generate_password(char *buf, int size, const char *word) {
    int word_len = (int)strlen(word);
    int pass_len = word_len * 2 + 1;

    if (pass_len + 1 > size) {
        return false;
    }

    // Rakennetaan salasana
    int buf_i = 0;
    buf[buf_i++] = random_printable();
    for (int i = 0; i < word_len; i++) {
        buf[buf_i++] = word[i];
        buf[buf_i++] = random_printable();
    }
    buf[buf_i] = '\0';

    return true;
}

int main(void) {
    srand((unsigned int)time(NULL));

    char word[32];

    while (1) {
        printf("Syota sana (tai 'stop' lopettaaksesi): ");
        if (fgets(word, sizeof(word), stdin) == NULL) break;

        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, "stop") == 0) {
            break;
        }

        int pass_size = (int)strlen(word) * 2 + 2;
        char *password = malloc(pass_size);
        if (!password) {
            printf("Muistin varaus epaonnistui!\n");
            break;
        }

        if (generate_password(password, pass_size, word)) {
            printf("Salasana: %s\n", password);
        } else {
            printf("Virhe: salasana ei mahdu taulukkoon!\n");
        }

        free(password);
    }

    return 0;
}
