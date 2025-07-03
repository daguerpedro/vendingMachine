#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>
#include "no.h"

typedef struct LIST
{
    NO* inicio;
    NO* final;

    int count;
} LIST;

void iniciarList(LIST* list);
void limparList(LIST* list);

bool listVazia(LIST* list);

void pushList(LIST* list, void* data);
void removeList(LIST* list, int idx);
void insertList(LIST* list, int idx, void* data);

void* getList(LIST* list, int idx);
void printList(LIST* list);

#endif