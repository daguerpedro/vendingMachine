#include <settings.h>

#include <maquinaestados.h>
#include <structs/stack.h>

#include <estados/config/config.h>
#include <estados/listar/listar.h>
#include <estados/pagar/pagar.h>
#include <estados/selecionar/selecionar.h>

#include <gerenciadores/propaganda/propaganda.h>

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
    *estadoAtual = *(ESTADO *)popEstado(stack);
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
        ESTADO *copia = malloc(sizeof(ESTADO));
        *copia = *estadoAtual;
        pushStack(stack, (void *)copia);

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
        switch (*estadoAtual)
        {
        case LISTAR:
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

    processarEstados(&stack, &estadoAtual);

    limparGerenciadorPropaganda();
    limparStack(&stack);
}