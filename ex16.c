// Created by PC Juuso on 4.3.2026.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

nnode *add_node(nnode *head, int number) {
    nnode *new_node = malloc(sizeof(nnode));
    if (!new_node) {
        printf("Muistin varaus epaonnistui!\n");
        return head;
    }
    new_node->number = number;
    new_node->next = head;
    return new_node;
}

void print_and_free(nnode *head) {
    nnode *current = head;
    while (current != NULL) {
        printf("%d\n", current->number);
        nnode *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(void) {
    nnode *head = NULL;
    char input[64];

    while (1) {
        printf("Syota luku tai 'end' lopettaaksesi: ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        // Poista rivinvaihto
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "end") == 0) {
            break;
        }

        // Yritetaan lukea luku
        char *endptr;
        long num = strtol(input, &endptr, 10);

        if (*endptr != '\0' || endptr == input) {
            printf("Virheellinen syote!\n");
        } else {
            head = add_node(head, (int)num);
        }
    }

    printf("\nSyotetyt luvut:\n");
    print_and_free(head);

    return 0;
}
