#pragma once
typedef struct _list
{
    void* value;
    struct _list* next;
} List;

List* createList(void* data);
List* createEmptyList();
void deleteList(List** node);
List* prependList(List* list, void* data);