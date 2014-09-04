#include <stdio.h>
#include "deblah.h"

void print(struct dlist *l){
	
	struct dnode *t;
	int i;

	for (t = l->head, i = 0; t != NULL; i++, t = t->next)
		printf("%i -> (%i,%s)\n", i, t->key, (char*)t->data);
	
}

void printn(struct dlist *l){
	
	struct dnode *t;
	int i;

	for (t = l->tail, i = 0; t != NULL; i++, t = t->previous)
		printf("%i -> (%i,%s)\n", i, t->key, (char*)t->data);
}

int main(){

	struct dlist *l = dd_new();

	if (l == NULL){
		printf("malloc err\n");
		return -1;
	}

	dd_insert(l, "Gislene", 1);	
	dd_insert(l, "Antonio", 3);	
	dd_insert(l, "Emma", 5);
	dd_insertn(l, "Filip", 2, -2);
	
	print(l);
	putchar('\n');
	printn(l);

	dd_free(l);
	
return 0;
}	

	

	
	
