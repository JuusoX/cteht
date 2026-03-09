// Created by PC Juuso on 9.3.2026.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));

    int level = -1;
    do {
        printf("Enter debug level (0-4): ");
        if (scanf("%d", &level) != 1) {
            while (getchar() != '\n');
            level = -1;
        }
        if (level < 0 || level > 4)
            printf("Invalid level!\n");
    } while (level < 0 || level > 4);

    set_debug_level(level);

    for (int i = 1; i <= 5; i++) {
        int msg_level = rand() % 5;
        dprintf(msg_level, "Message number %d, debug level %d\n", i, msg_level);
    }

    return 0;
}
