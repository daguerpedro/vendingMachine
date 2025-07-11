#include "propaganda.h"
#include <structs/stack.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

STACK stackMoedas;

void iniciarGerenciadorMoedas()
{
    iniciarStack(&stackMoedas);
}

void limparGerenciadorMoedas()
{
    limparStack(&stackMoedas);
}

void inserirMoeda(float v)
{
    float* valor = malloc(sizeof(float));
    *valor = v;
    pushStack(&stackMoedas, valor);
}

float recolherMoeda()
{
    void* valor = popStack(&stackMoedas);
    if(valor == NULL) return 0;

    float valorMoeda  = *(float*)valor;
    free(valor);
    return valorMoeda;
}

void esvaziarMoedas()
{
    limparStack(&stackMoedas);
}