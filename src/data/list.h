#pragma once

#include <stdbool.h>

typedef struct ListNode
{
    struct ListNode *next;
    struct ListNode *previous;

    void *data;
} ListNode;

typedef struct List
{
    ListNode *first;
    ListNode *last;
} List;

List *initList();
void freeList(List *list);

bool isListEmpty(List *list);
int listCount(List *list);

void pushList(List *list, void *data);
void popList(List *list);

ListNode *listGetAt(List *list, int pos);