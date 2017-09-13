#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>
#include <stdio.h>

/** 
 * mylib.h
 * Provides various utility functions.
 */

/**
 * Error checking version of malloc. Exits on failure.
 * @param size_t s The size of memory to allocate.
 * @return The pointer to the allocated memory.
 */
 extern void *emalloc(size_t s);
 
 /** 
 * Error checking version of realloc. Exits on Failure.
 * @param void *p The memory block to reallocate.
 * @param size_s s The size of memory to reallocate.
 * @return The pointer to the reallocated memory.
 */
extern void *erealloc(void *p, size_t s);

/**
 * Reads a word from a stream.
 * @param char *s Where to read the word into.
 * @param int limit Maximum number of characters we should read.
 * @param FILE *stream The stream to read from.
 * @return Returns EOF if end of stream reached or returns non-zero value.
 */
extern int getword(char *s, int limit, FILE *stream);


#endif