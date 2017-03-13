typedef struct _list
{
    void* Value;
    struct _list* Next;
} List;


void deleteList(Node** node);