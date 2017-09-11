#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
#include "container.h"

struct htablerec {
    int num_keys;
    int capacity;
    container *keys;
    container_t type;
};

/**
 * Creates a int representation of a string.
 * @param char *word The string to convert.
 * @return The int representation of the string.
 */
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    
    return result;
}

void htable_free(htable h) {
    int i;

    for (i = 0; i < h->capacity; i++) {
        container_free(h->keys[i]);
    }
    
    free(h->keys);
    free(h);
}

void htable_insert(htable h, char *str) {
    int hash = htable_word_to_int(str) % h->capacity;
    
    if (h->keys[hash] == NULL) {            
        h->keys[hash] = container_new(h->type);
        h->num_keys++;
    }

    container_add(h->keys[hash], str);
}

htable htable_new(int capacity, int use_robust_chaining) {
    int i;
    htable result = emalloc(sizeof *result);

    result->num_keys = 0;
    result->capacity = capacity;
    result->keys = emalloc(capacity * sizeof result->keys[0]);
    result->type = (use_robust_chaining == 1) ? RED_BLACK_TREE : FLEX_ARRAY;

    for (i = 0; i < capacity; i++) {
        result->keys[i] = NULL;
    }

    return result;
}

int htable_search(htable h, char *str) {
    int hash = htable_word_to_int(str) % h->capacity;
    
    return container_search(h->keys[hash], str);
}

void htable_print(htable h) {
    int i;
    
    for (i = 0; i < h->capacity; i++) {
        if (h->keys[i] != NULL) {
            /* Print the position in the htable, */
            printf("%d ", i);
            /* followed by container contents on the same line. */
            container_print(h->keys[i]);
        }
    }
}