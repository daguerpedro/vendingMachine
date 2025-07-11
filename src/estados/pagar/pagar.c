#include "pagar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <input.h>

#include <gerenciadores/produtos/produtos.h>
#include <gerenciadores/moedas/moedas.h>

float saldo = 0;

void clear()
{
    system("clear || cls");
    printf("\033[2J\033[H");
    fflush(stdout);
}

void pause()
{
    system("pause");
}

void pegarInfoProduto()
{
    PRODUTO_HEADER selecionado = produtoSelecionado();

    printf("> %s custa R$ %0.2f\n", selecionado.name, selecionado.preço);
    printf("> Seu saldo: %0.2f\n\n", saldo);
}

void mostrarMoedas()
{
    printf("[INSIRA MOEDAS] (1) R$ 0.25 (2) R$ 0.50 (3) R$ 1.00\n");
}

void informacoes()
{
    pegarInfoProduto();
    mostrarMoedas();
    printf("[PAGAMENTO| -1: SAIR | 0 VOLTAR | 4: DESFAZER]: ");
}

void darTroco()
{
    if (saldo > 0)
    {
        float troco = saldo;

        if (saldo >= produtoSelecionado().preço)
            troco = saldo - produtoSelecionado().preço;

        printf("[TROCO] Seu troco: %0.2f\n", troco);
    }

    saldo = 0;
    esvaziarMoedas();
}

/// @brief Coleta moedas, verificando acao de voltar/sair/menu_configuracoes
/// @param result Variavel que armazenara o resultado
void coletarMoedas(RESULTADO_ESTADO *result)
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
        printf("[DEVOLUÇÃO] %0.2f\n", recolher);
        saldo -= recolher;
        pause();

        break;

    default:
        break;
    }

    if (saldo >= produtoSelecionado().preço)
    {
        *result = PROXIMO;
        return;
    }
    else
    {
        clear();
        informacoes();
        coletarMoedas(result);
    }
}

RESULTADO_ESTADO estadoPagar()
{
    clear();

    RESULTADO_ESTADO res;

    informacoes();

    coletarMoedas(&res);

    darTroco();

    pause(); 

    return res;
}