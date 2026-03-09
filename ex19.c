// Created by PC Juuso on 9.3.2026.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int compare_by_name(const void *a, const void *b) {
    const menu_item *ia = (const menu_item *)a;
    const menu_item *ib = (const menu_item *)b;
    return strcmp(ia->name, ib->name);
}

int compare_by_price(const void *a, const void *b) {
    const menu_item *ia = (const menu_item *)a;
    const menu_item *ib = (const menu_item *)b;
    if (ia->price < ib->price) return -1;
    if (ia->price > ib->price) return  1;
    return 0;
}

int main(void) {
    menu_item items[MAX_ITEMS];
    int count = 0;
    char filename[100];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    while (count < MAX_ITEMS) {
        char line[200];
        if (!fgets(line, sizeof(line), f)) break;
        char *sep = strchr(line, ';');
        if (!sep) continue;
        *sep = '\0';
        strncpy(items[count].name, line, 49);
        items[count].name[49] = '\0';
        items[count].price = atof(sep + 1);
        count++;
    }
    fclose(f);

    printf("Sort by:\n1) Name\n2) Price\nEnter selection: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
        qsort(items, count, sizeof(menu_item), compare_by_name);
    else if (choice == 2)
        qsort(items, count, sizeof(menu_item), compare_by_price);

    for (int i = 0; i < count; i++)
        printf("%8.2f  %s\n", items[i].price, items[i].name);

    return 0;
}
