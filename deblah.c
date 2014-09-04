
#include <stdlib.h>

#include "deblah.h"

#ifndef NULL
#define NULL 0
#endif

/*
void dd_sort(struct dlist *list);
*/

void dd_remove(struct dlist *list, const unsigned int key){
	
	struct dnode *node;

	node = dd_get(list, key);

	if ( node == NULL )
		return;

	if ( node->previous != NULL )
		node->previous->next = node->next;
	if ( node->next != NULL )
		node->next->previous = node->previous;

	free(node);
	list->len -= 1;
	
}

struct dlist *dd_new(){

	struct dlist *l;

	l = (struct dlist *)malloc( sizeof(struct dlist) );

	if (l != NULL){
		l->head = l->tail = NULL;
		l->len = 0; 
	}
	
	return l;

}

struct dnode *dd_insertn(struct dlist *list, void *data, const unsigned int key, int position){

	struct dnode *node = (struct dnode*) malloc( sizeof(struct dnode) );
	struct dnode *tnode; //temporary node
	unsigned int index;

	if ( node == NULL )
		return NULL;

	node->data = data;
	node->key = key;

	if ( list->head == NULL ){
		node->next = node->previous = NULL;
		list->head = list->tail = node;
		list->len = 1;
	}
	else{
		
		if ( dd_get(list, key) != NULL )
			return NULL;

		if ( position == -1 || -position > list->len ) {
			/* Incerting as last element */
			tnode = list->tail;
			tnode->next = node;
			node->previous = tnode;
			node->next = NULL;
			list->tail = node;
			return node;
		}
		else if ( position >= 0  && position < list->len ){
			/* Forward */
			tnode = list->head;
			for (index = 0; index < position && tnode->next != NULL; index++ ) 
				tnode = tnode->next;
		} else {
			/* Backward */
			position = -1 * position - 1;
			tnode = list->tail;
			for (index = 0; index < position && tnode->previous != NULL; index++ )
				tnode = tnode->previous;
		} 
		

		node->previous = tnode->previous;
		if ( tnode->previous != NULL )
			tnode->previous->next = node;
		if ( tnode != NULL )
			tnode->previous = node;
		node->next = tnode;

		if ( position == 0 )
			list->head = node;
		if ( position >= list->len )
			list->tail = node;
		
		list->len += 1;

	}

	return node;
}

struct dnode *dd_get(struct dlist *list, const unsigned int key){
	
	unsigned int index;
	struct dnode *t = list->head;

	for ( index = 0; t != NULL ; index++, t = t->next)
		if ( t->key == key )
			return t;

	return NULL;
}


struct dnode *dd_insert(struct dlist *list, void *data, const unsigned int key){
	return dd_insertn(list, data, key, 0);
}


void dd_free(struct dlist *list){
	
	struct dnode *node;
	void *ptr;

	for ( node = list->head; node != NULL; ){
		ptr = node->next;
		node->data = node->next = node->previous = NULL;
		free(node);
		node = (struct dnode*)ptr;
	}

	free(list);

}

