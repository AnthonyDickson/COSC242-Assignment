#ifndef CONTAINER_H_
#define CONTAINER_H_

/**
 * container.h
 * A wrapper for the flexarray and rbt (red-black tree) types.
 */

/** Defines the container types. */
typedef enum container_e {FLEX_ARRAY, RED_BLACK_TREE} container_t;

/** Outlines the structure of a container. */
typedef struct containerrec *container;

/**
 * Adds a string to the container.
 * @param container c The container to add to.
 * @param char *word The word to add.
 */
extern void container_add(container c, char *word);

/**
 * Frees memory associated with a container.
 * @param container c The container to free.
 */
extern void container_free(container c);

/**
 * Creates a new, empty container.
 * @param container_t t The type the container should use. 
 * @return A pointer to the new container.
 */
extern container container_new(container_t t);

/** 
 * Prints out the contents of the container.
 * @param container c The container to print.
 */
extern void container_print(container c);

/**
 * Searches the container for a string.
 * @param container c The container to search.
 * @param char *word The word to search for.
 * @return 1 if the word was found, 0 otherwise.
 */
extern int container_search(container c, char *word);

#endif