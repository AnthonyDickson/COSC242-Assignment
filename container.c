#include <stdlib.h>
#include "container.h"
#include "rbt.h"
#include "flexarray.h"
#include "mylib.h"

struct containerrec {
    container_t type;
    void *contents;
};

/** Helper method used to print container contents */
static void print_key(char *key) {
    printf("%s ", key);
}

void container_add(container c, char *word) {
    if (c->type == RED_BLACK_TREE) {
        c->contents = rbt_insert(c->contents, word);
    } else {
        flexarray_append(c->contents, word);
    }
}

void container_free(container c) {
    if (NULL != c) {            
        if (c->type == RED_BLACK_TREE) {
            rbt_free(c->contents);
        } else {
            flexarray_free(c->contents);
        }
    
        free(c);
    }
}

container container_new(container_t t) {
    container c = emalloc(sizeof *c);
    c->type = t;

    if (t == FLEX_ARRAY) {
        c->contents = flexarray_new();
    } else {
        c->contents = rbt_new();
    }
    
    return c;
}

void container_print(container c) {
    if (c->type == RED_BLACK_TREE) {
        rbt_preorder(c->contents, print_key);
    } else {
        flexarray_visit(c->contents, print_key);
    }
}

int container_search(container c, char * word) {
    if (c->type == RED_BLACK_TREE) {
        return rbt_search(c->contents, word);
    } else {
        return flexarray_is_present(c->contents, word);
    }
}