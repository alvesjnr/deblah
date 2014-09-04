

#ifndef __DEBLAH_H
#define __DEBLAH_H


struct dnode{
	void *data;
	unsigned int key;
	struct dnode *next;
	struct dnode *previous;
};


struct dlist{
	struct dnode *head;
	struct dnode *tail;
	unsigned int len;
};

/*
 * Create a new dlist and initilize all the internals
 */
struct dlist *dd_new();

/*
 * Create a copy of a list
 */
struct dlist *dd_copy(struct dlist *list);

/*
 * Insert an element in the begining (head) of the list
 */
struct dnode *dd_insert(struct dlist *list, void *data, const unsigned int key);

/*
 * Insert an element in the n-th position of the list
 */
struct dnode *dd_insertn(struct dlist *list, void *data, const unsigned int key, int position);

/*
 * Get an element from its key
 */
struct dnode *dd_get(struct dlist *list, const unsigned int key);

/*
 * Remove an element from the list by its key
 */
void dd_remove(struct dlist *list, const unsigned int key);

/*
 * Sort a list (in place)
 */
void dd_sort(struct dlist *list);

/*
 * Remove a list from memory
 */
void dd_free(struct dlist *list);




#endif
