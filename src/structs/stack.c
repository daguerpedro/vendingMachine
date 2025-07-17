#include <stdio.h>
#include <stdlib.h>

#include <no.h>

#include "stack.h"

void iniciarStack(STACK *stack)
{
    stack->topo = NULL;
}

bool stackVazia(STACK *stack)
{
    return stack->topo == NULL;
}

void pushStack(STACK *stack, void *valor)
{
    NO *no = malloc(sizeof(NO));
    if(no == NULL)
    {
        printf("[ERRO] Falha ao alocar stack.\n");
        return;
    }
    no->anterior = stack->topo;
    no->valor = valor;
    stack->topo = no;
}

void *popStack(STACK *stack)
{
    if (stackVazia(stack))
        return NULL;

    NO *no = malloc(sizeof(NO));
    if(no == NULL)
    {
        printf("[ERRO] Falha ao alocar stack.\n");
        return NULL;
    }
    no = stack->topo;
    stack->topo = no->anterior;

    void *e = no->valor;
    free(no);
    return e;
}

void limparStack(STACK *stack)
{
    NO *no = stack->topo;
    while (!stackVazia(stack))
    {
        popStack(stack);
        no = stack->topo;
    }
}