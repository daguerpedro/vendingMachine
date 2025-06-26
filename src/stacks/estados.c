#include <stdio.h>
#include <stdlib.h>

#include "estados.h"

/// @brief Inicia uma stack
/// @param stack Referência para stack
void iniciarStack(STACK *stack)
{
    stack->topo = NULL;
}

/// @brief Verifica se stack está vazia
/// @param stack Ref para stack
/// @return verdadiro se vazia
bool stackVazia(STACK *stack)
{
    return stack->topo == NULL;
}

/// @brief Adiciona um valor à stack
/// @param stack Ref para stack
/// @param valor Dado genérico
void pushStack(STACK *stack, void* valor)
{
    NO *no = malloc(sizeof(NO));
    no->anterior = stack->topo;
    no->valor = valor;
    stack->topo = no;
}

void* popEstado(STACK *stack)
{
    if (stackVazia(stack))
        return NULL;

    NO *no = malloc(sizeof(NO));
    no = stack->topo;
    stack->topo = no->anterior;

    void* e = no->valor;
    free(no);
    return e;
}

void limparStack(STACK *stack)
{
    NO *no = stack->topo;
    while (!stackVazia(stack))
    {
        popEstado(stack);
        no = stack->topo;
    }
}