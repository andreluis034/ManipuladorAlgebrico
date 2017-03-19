#include "list.h"
#include <stdlib.h>

List* createList(void* data)
{
	if(data == NULL){
		return NULL;
	}

	List* list = malloc(sizeof(List));
	list->value = data;
	list->next = NULL;
	return list;
}

List * createEmptyList()
{
	return createList(NULL);
}

void deleteList(List ** node)
{
	free(*node);
	*node = NULL;
}

List * prependList(List * list, void * data)
{
	List* newList = createList(data);
	newList->next = list;
	return newList;
}

