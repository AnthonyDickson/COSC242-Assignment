#ifndef RBT_H_
#define RBT_H_
/** 
 * rbt.h
 * An implentation of a red-black tree ADT.
 * A new rbt (red-black tree) should be created like this: rbt r = rbt_new();
 * Must free memory associated with the rbt by calling the method rbt_free.
 */

/** Defines the node colours of a rbt. */
typedef enum {RED, BLACK} rbt_colour;

/** Defines a rbt node. */
typedef struct rbt_node *rbt;

/**
 * Deallocates the memory associated with a rbt. 
 * @param rbt r The rbt to deallocate.
 * @return A NULL pointer.
 */
extern rbt rbt_free(rbt r);

/** 
 * Performs an in-order traversal of a rbt and applies the given function 
 * to each node.
 * @param rbt r The rbt to traverse.
 * @param void f(char *key) The function to apply.
 */
 extern void rbt_inorder(rbt r, void f(char *key));

/**
 * Inserts a key into a rbt.
 * Must assign the result to the original rbt to have an effect. 
 * For example, rbt r = rbt_insert(r, key);
 * @param rbt r The rbt to insert into.
 * @param char *key The key to insert.
 * @return The rbt after the key is inserted.
 */
 extern rbt rbt_insert(rbt r, char *key);

/** 
 * Creates a new, empty rbt.
 * @return The new rbt.
 */
extern rbt rbt_new();

/** 
 * Performs a post-order traversal of a tree and applies the given function 
 * to each node.
 * @param rbt r The rbt to traverse.
 * @param void f(char *key) The function to apply.
 */
extern void rbt_postorder(rbt r, void f(char *key));

/** 
* Performs a pre-order traversal of a tree and applies the given function 
* to each node.
* @param rbt r The rbt to traverse.
* @param void f(char *key) The function to apply.
*/
extern void rbt_preorder(rbt r, void f(char *key));

/**
 * Searches a rbt for a key.
 * @param rbt r The rbt to search.
 * @param char *key The key to search for.
 * @return 1 if key was found, 0 otherwise.
 */
 extern int rbt_search(rbt r, char *key);

#endif