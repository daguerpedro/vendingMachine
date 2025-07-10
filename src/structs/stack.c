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
    // TODO: Check malloc error
    NO *no = malloc(sizeof(NO));
    no->anterior = stack->topo;
    no->valor = valor;
    stack->topo = no;
}

void *popStack(STACK *stack)
{
    if (stackVazia(stack))
        return NULL;

    // TODO: Check malloc error
    NO *no = malloc(sizeof(NO));
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