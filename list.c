#include "list.h"

void deleteNode(Node** node)
{
    free(*node);
    *node = NULL;
}