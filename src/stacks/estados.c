#include <stdio.h>
#include <stdlib.h>

#include "estados.h"

void iniciarStackEstados(STACK_ESTADOS *stack)
{
    stack->topo = NULL;
}

bool stackEstadoVazia(STACK_ESTADOS *stack)
{
    return stack->topo == NULL;
}

void pushEstado(STACK_ESTADOS *stack, ESTADO estado)
{
    NO_ESTADO *no = malloc(sizeof(NO_ESTADO));
    no->anterior = stack->topo;
    no->estado = estado;
    stack->topo = no;
}

ESTADO popEstado(STACK_ESTADOS *stack)
{
    if (stackEstadoVazia(stack))
        return LISTAR;

    NO_ESTADO *no = malloc(sizeof(NO_ESTADO));
    no = stack->topo;
    stack->topo = no->anterior;

    ESTADO e = no->estado;
    free(no);
    return e;
}

void limparStackEstados(STACK_ESTADOS *stack)
{
    NO_ESTADO *no = stack->topo;
    while (no != NULL)
    {
        popEstado(stack);
        no = stack->topo;
    }
}