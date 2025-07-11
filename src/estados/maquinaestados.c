#include <maquinaestados.h>
#include <structs/stack.h>

#include <config/config.h>
#include <listar/listar.h>
#include <pagar/pagar.h>
#include <selecionar.h>

#include <propaganda.h>
#include <produtos.h>
#include <moedas.h>

#include <stdio.h>
#include <stdlib.h>

/// @brief Variável que controla se a máquina de estados deve rodar.
bool rodar;

/// @brief Utiliza a stack de histórico de estados para voltar um estado.
/// @param stack Stack que contêm o histórico de estados.
/// @param estadoAtual
void voltarEstado(STACK *stack, ESTADO *estadoAtual)
{
    if (stackVazia(stack))
        return;
    *estadoAtual = *(ESTADO *)popStack(stack);
}

/// @brief Processa o resultado de um estado em específico.
/// @param stack Stack que contêm o histórico de estados.
/// @param resultado Resultado do estado.
/// @param proximo Próximo estado.
void processarResultado(STACK *stack, RESULTADO_ESTADO resultado, ESTADO *estadoAtual, ESTADO proximo)
{
    if (resultado == VOLTAR)
    {
        voltarEstado(stack, estadoAtual);
        return;
    }

    if (resultado == PROXIMO)
    {
        // TODO: Check malloc error
        ESTADO *copia = malloc(sizeof(ESTADO));
        *copia = *estadoAtual;
        pushStack(stack, (void *)copia);

        // TODO: limpar saldo / devolver troco
        if (*copia == PAGAR)
        {
            limparStack(stack);
        }

        *estadoAtual = proximo;
        return;
    }

    if (resultado == SAIR)
    {
        rodar = false;
        return;
    }

    if (resultado == MENU_ADM)
    {
        // TODO: Check malloc error
        ESTADO *copia = malloc(sizeof(ESTADO));
        *copia = *estadoAtual;
        pushStack(stack, (void *)copia);
        *estadoAtual = CONFIGURAR;
        return;
    }
}

/// @brief Processa os estados enquanto a variável rodar for verdadeira
/// @param stack Stack que conterá o histórico de estados
/// @param estadoAtual Estado a ser processado
void processarEstados(STACK *stack, ESTADO *estadoAtual)
{
    while (rodar)
    {

        // FIXME: QUANDO VOLTAMOS DO ESTADO PAGAR PARA ESTADO SELECIONAR, A INFORMACAO DOS PRODUTOS NAO APARECE NA TELA, POIS O ESTADO QUE MOSTRA AS INFOS É O DE LISTAR E NAO DE SELECIONAR!
        switch (*estadoAtual)
        {
        case LISTAR:
            system("clear || cls");
            printf("\033[2J\033[H");
            fflush(stdout);
            processarResultado(stack, estadoListar(), estadoAtual, SELECIONAR);
            break;

        case SELECIONAR:
            processarResultado(stack, estadoSelecionar(), estadoAtual, PAGAR);
            break;

        case PAGAR:
            processarResultado(stack, estadoPagar(), estadoAtual, LISTAR);
            break;

        case CONFIGURAR:
            processarResultado(stack, estadoConfig(), estadoAtual, LISTAR);
            break;

        default:
            break;
        }
    }
}

/// @brief Inicia a máquina de estados
void iniciarMaquinaEstados()
{
    rodar = true;
    STACK stack;
    ESTADO estadoAtual = LISTAR;

    iniciarStack(&stack);
    iniciarGerenciadorPropaganda();
    iniciarGerenciadorProdutos();
    iniciarGerenciadorMoedas();

    processarEstados(&stack, &estadoAtual);

    limparGerenciadorMoedas();
    limparGerenciadorProdutos();
    limparGerenciadorPropaganda();
    limparStack(&stack);
}