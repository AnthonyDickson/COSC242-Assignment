#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

/*
 * flexarray.h
 * A dymanic array whose size grows as necessary.
 */

/** Outlines the structure of a flexarray. */
typedef struct flexarrayrec *flexarray;

/**
 * Appends a string to a flexarray.
 * @param flexarray f The flexarray to append to.
 * @param char *word The string to append.
 */
extern void flexarray_append(flexarray f, char *word);

/** 
 * Frees the memory associated with a flexarray.
 * @param flexarray f The flexarray to free.
 */
extern void flexarray_free(flexarray f);

/** 
 * Checks if a string is contained within a flexarray.
 * @param flexarray f The flexarray to check.
 * @param char *word The string to check for.
 * @return 1 if the string was found, 0 otherwise.
 */
extern int flexarray_is_present(flexarray f, char *word);

/**
 * Creates a new, empty flexarray.
 * @return A pointer to the new flexarray.
 */
extern flexarray flexarray_new();

/** 
* Prints the contents of a flexarray.
* @param flexarray f The flexarray to print.
*/
extern void flexarray_print(flexarray f);

/**
 * Sorts a flexarray.
 * @param flexarray f The flexarray to sort.
 */
extern void flexarray_sort(flexarray f);

/** 
 * Visits each element in the flexarray, and applies the given function.
 * @param flexarray f The flexarray to traverse.
 * @param void func(char *word) The function to apply at to each element.
 */
extern void flexarray_visit(flexarray f, void func(char *word));

#endif