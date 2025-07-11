#include "selecionar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <input.h>
#include <gerenciadores/produtos/produtos.h>

/// @brief Verificar se produto é valido (!deletado & estoque & listado)
/// @param i idx do produto
/// @return true se valido
bool verificarProduto(int i)
{
    return produtoValido(i);
}

/// @brief Seleciona um produto, verificando acao de voltar/sair/menu_configuracoes
/// @param result Variavel que armazenara o resultado
void selecionar(RESULTADO_ESTADO* result)
{
    int entrada = captarEntrada();
    switch (entrada)
    {
    case -1:
        *result = SAIR;
        return;
    case 0:
        *result = VOLTAR;
        return;
    case -9:
        *result = MENU_ADM;
        return;
    default: // Se nao queremos sair nem ir para o menu de configuração, vamos verificar se o produto é valido
        break;
    }

    if (verificarProduto(entrada-1))
    {
        *result = PROXIMO;
        selecionaProduto(entrada-1);
    }
    else 
        selecionar(result);

}

RESULTADO_ESTADO estadoSelecionar()
{
    printf("[SELECIONAR| -1: SAIR | 0 VOLTAR]: ");
    RESULTADO_ESTADO res;
    selecionar(&res);
    return res;
}