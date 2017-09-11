#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>

/** 
 * htable.h
 * A hash table implementation.
 */

/** Outlines the structure of a htable. */
typedef struct htablerec *htable;

/**
 * Frees the memory associated with a htable.
 * @param htable h The htable to free.
 */
extern void htable_free(htable h);

/**
 * Inserts a string into a htable.
 * @param htable h The htable to insert into.
 * @param char *str The string to insert.
 */
extern void htable_insert(htable h, char *str);

 /**
 * Creates a new empty htable.
 * @param int capacity The size of the htable.
 * @param int use_robust_chaining Set to 1 for robust chaining, or 0 otherwise.
 * @return A pointer to the new htable.
 */
extern htable htable_new(int capacity, int use_robust_chaining);

/**
 * Prints a htable.
 * @param htable h The htable to print.
 */
extern void htable_print(htable h);

/**
 * Searchs a htable for a string.
 * @param htable h The htable to search.
 * @param char *str The string to search for.
 * @return 1 if string was found, 0 otherwise.
 */
extern int htable_search(htable h, char *str);

#endif