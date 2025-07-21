#include "pagar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <input.h>

#include <gerenciadores/produtos/produtos.h>
#include <gerenciadores/moedas/moedas.h>
#include <propaganda.h>

float saldo = 0;

void pegarInfoProduto()
{
    PRODUTO_HEADER selecionado = produtoSelecionado();

    printf("> %s custa R$ %0.2f\n", selecionado.name, selecionado.preço);
    printf("> Seu saldo R$ %0.2f\n\n", saldo);
}

void informacoes()
{
    pegarInfoProduto();
    printf("[INSIRA MOEDAS | 4: DESFAZER]: \n\n");
    printf(" (1) R$ 0.25 \n (2) R$ 0.50 \n (3) R$ 1.00\n");
}

void darTroco()
{
    if (saldo > 0)
    {
        float troco = saldo;

        if (saldo >= produtoSelecionado().preço)
            troco = saldo - produtoSelecionado().preço;

        printf("> Seu troco R$ %0.2f\n\n", troco);
    }

    saldo = 0;
    esvaziarMoedas();
}

/// @brief Coleta moedas, verificando acao de voltar/sair/menu_configuracoes
/// @param result Variavel que armazenara o resultado
void coletarMoedas(RESULTADO_ESTADO *result)
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

    case 1:
        inserirMoeda(0.25);
        saldo += 0.25f;
        break;
    case 2:
        inserirMoeda(0.50);
        saldo += 0.50f;
        break;
    case 3:
        inserirMoeda(1.00);
        saldo += 1.00f;
        break;
    case 4:
        if (saldo <= 0)
            break;

        float recolher = recolherMoeda();
        printf("\n> Pegue sua moeda de volta R$ %0.2f\n\n", recolher);
        saldo -= recolher;
        pause();

        break;

    default:
        break;
    }

    if (saldo >= produtoSelecionado().preço)
    {
        printf("\n> Aproveite seu refri!\n");
        venderProduto();
        *result = PROXIMO;
        return;
    }
    else
    {
        clear();
        mostrarPropaganda();
        informacoes();
        coletarMoedas(result);
    }
}

RESULTADO_ESTADO estadoPagar()
{
    RESULTADO_ESTADO res;

    informacoes();

    coletarMoedas(&res);

    darTroco();

    pause(); 

    return res;
}