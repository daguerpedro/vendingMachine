#include "selecionar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <input.h>
#include <gerenciadores/produtos/produtos.h>

#include <stdbool.h>

/// @brief Seleciona um produto
/// @param result Variavel que armazenara o resultado
void selecionar(RESULTADO_ESTADO* result)
{
    printf("\n");
    
    int entrada = captarEntrada(true);
    switch (entrada)
    {
    case -1:
        *result = SAIR;
        return;
    case 0:
        *result = VOLTAR;
        return;
    default: // Vamos verificar se o produto é valido
        break;
    }

    //Passamos entrada - 1 pois a listagem de produtos adiciona 1 para nao conflitar com o 0 de voltar.
    if (produtoValido(entrada-1))
    {
        *result = PROXIMO;
        selecionaProduto(entrada-1);
    }
    else //Se não é um produto que exista/válido/disponível captamos a entrada dnv.
        selecionar(result);
}

RESULTADO_ESTADO estadoSelecionar()
{
    RESULTADO_ESTADO res;
    listarProdutos(false);
    selecionar(&res);
    return res;
}