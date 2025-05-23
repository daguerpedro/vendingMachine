#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


List *initList()
{
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL)
    {
#ifdef DEBUG
        printf("[LIST] Memory allocation failed.\n");
#endif
        return NULL;
    }

    list->first = NULL;
    list->last = NULL;

    return list;
}

int listCount(List *list)
{
    int i = 0;
    ListNode *idx = list->first;
    while (idx != NULL)
    {
        idx = idx->next;
        i++;
    }
    return i;
}

bool isListEmpty(List *list)
{
    // list->last deve ser null se nao tiver um primeiro elemento.
    return list->first == NULL;
}

void freeList(List *list)
{
    ListNode *node = list->first;
    while (node != NULL)
    {
        list->first = list->first->next;
        if (node->data != NULL)
            free(node->data);
        free(node);
        node = list->first;
    }

    //FIXME: free(): invalid pointer
    free(list);
}

void pushList(List *list, void *data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    if (isListEmpty(list))
        list->first = node;
    else
    {
        ListNode *lastNode = list->last;
        lastNode->next = node;
        node->previous = lastNode;
    }

    list->last = node;
}

void popList(List *list)
{
    ListNode *lastNode = list->last;
    if (lastNode == NULL)
        return;

    list->last = lastNode->previous;

    if (list->last != NULL)
        list->last->next = NULL;
    else
        list->first = NULL; // lista agora está vazia

    if (lastNode->data != NULL)
        free(lastNode->data);
    free(lastNode);
}
ListNode *listGetAt(List *list, int pos)
{
    ListNode *node = NULL;
    if (isListEmpty(list) || pos >= listCount(list) || pos < 0)
    {
#ifdef DEBUG
        printf("[DEBUG] listGetAt at invalid position: %i | list size: %i.\n", pos, listCount(list));
#endif
        return node;
    }

    node = list->first;
    for (int i = 0; i < pos; i++)
        node = node->next;

    if (node == NULL)
    {
#ifdef DEBUG
        printf("[DEBUG] listGetIntAt node was null.\n", pos);
#endif
    }
    return node;
}