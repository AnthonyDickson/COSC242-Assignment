#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "mylib.h"

void *emalloc(size_t s) {
    void *result = malloc(s);

    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

void *erealloc(void *p, size_t s) {
    void *result = realloc(p, s);

    if (NULL == result) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);

    /* skip to the start of the word */
    while (!isalnum(c = getc(stream)) && EOF != c);

    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
        *w++ = tolower(c);
    }

    while (--limit > 0) {        
        if (isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }

    *w = '\0';
    return w - s;
}

/* performs an insertion sort on an integer array, a
   char **a array of integers
   int n size of the array */
void insertion_sort(char **a, int n) {
    int i, j;
    char *key;
    
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && strcmp(a[j], key) > 0) {
            a[j + 1] = a[j];       
            
            j--;
        }

        a[j+1] = key;
    }
}

/* Merges two sorted subarrays.
   char **a The array that contains two sorted subarrays.
   int *w The workspace for merging the subarrays.
   int len The length of the array.
*/
void merge(char **a, char **w, int len) {
    /* i Position in 1st subarray
       j Position in 2nd subarray
       k Position in workspace (w)
    */
    int i, j, k; 
    i = k = 0;
    j = len / 2;

    while (i < len / 2 && j < len) {
        if (strcmp(a[i], a[j]) < 0) w[k++] = a[i++];
        else w[k++] = a[j++];
    }

    /* Copy over any remaining items. */
    while (i < len / 2) w[k++] = a[i++];
    while (j < len) w[k++] = a[j++];
}

/* performs mergesort on an array.
   char **a The array to sort.
   char **w The workspace for the merge.
   int n  The number of items in the array.
*/
void merge_sort(char **a, char **w, int n) {
    int i;
    int n1, n2;
    char **w1, **w2;
    
    if (n < 2) return;

    if (n < 10) {
        insertion_sort(a, n);
        return;
    }

    n1 = n / 2;
    n2 = n - n1;
    w1 = emalloc(sizeof(char*) * n1);
    w2 = emalloc(sizeof(char*) * n2);

    merge_sort(a, w1, n1);
    merge_sort((a + (n / 2)), w2, n2);

    merge(a, w, n);
    for (i = 0; i < n; i++) a[i] = w[i];

    free(w1);
    free(w2);
}