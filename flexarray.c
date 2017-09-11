#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    char **items;
    int sorted; /** Keeps track if flexarray was sorted since last append. */
};

void flexarray_append(flexarray f, char *word) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity; 
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }

    f->items[f->itemcount] = emalloc(strlen(word) + 1);
    strcpy(f->items[f->itemcount], word);
    f->itemcount++; 
    f->sorted = 0;
}

void flexarray_free(flexarray f) {
    int i;

    for (i = 0; i < f->itemcount; i++) {
        free(f->items[i]);
    }

    free(f->items);
    free(f);
}

int flexarray_is_present(flexarray f, char *word) {
    if (f->itemcount == 0) {
        return 0;
    }
    /* If flexarray hasn't been sorted since last insert */
    if (f->sorted == 0) {
        flexarray_sort(f);
    }

    return binary_search(f->items, word, f->itemcount);
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);

    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    result->sorted = 0;

    return result;
}

void flexarray_sort(flexarray f) {
    char **temp = emalloc(f->itemcount * sizeof(f->items[0]));
    merge_sort(f->items, temp, f->itemcount);
    free(temp);
    f->sorted = 1;
}

void flexarray_visit(flexarray f, void func(char *word)) {
    int i;

    for (i = 0; i < f->itemcount; i++) {
        func(f->items[i]);
    }
}