#ifndef _PRODUTOS_H
#define _PRODUTOS_H

#include <stdbool.h>

typedef struct PRODUTO_HEADER
{
    char name[20];
    float preço;
    int estoque;
    bool ativo;
} PRODUTO_HEADER;

void iniciarGerenciadorProdutos();
void limparGerenciadorProdutos();
void carregarProdutos();

#endif