#include "produtos.h"
#include <list.h>

LIST listaProdutos;

void iniciarGerenciadorProdutos()
{
    iniciarList(&listaProdutos);
}

void limparGerenciadorProdutos()
{
    limparList(&listaProdutos);
}

void carregarProdutos()
{
}