#include "pagar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <input.h>
#include <gerenciadores/produtos/produtos.h>

float saldo = 0;
//TODO: CRIAR STACK DE MOEDAS INSERIDAS PARA PODER DESFAZER A AÇÃO.
//TODO: TROCO
//TPDP: ENTREGAR PRODUTO

void pegarInfoProduto()
{
    PRODUTO_HEADER selecionado = produtoSelecionado();
    printf("> %s custa R$ %0.2f\n", selecionado.name, selecionado.preço);
    printf("> Seu saldo: %0.2f\n", saldo);
}

void mostrarMoedas()
{
    printf("[INSIRA MOEDAS] (1) R$ 0.25 (2) R$ 0.50 (3) R$ 1.00: ");
}
RESULTADO_ESTADO estadoPagar()
{
   pegarInfoProduto();
   mostrarMoedas();

   return PROXIMO;
}