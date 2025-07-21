#include <maquinaestados.h>
#include <structs/stack.h>

#include <admin.h>
#include <config/config.h>
#include <inicial/inicial.h>
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
        ESTADO *copia = malloc(sizeof(ESTADO));
        if (copia == NULL)
        {
            printf("[ERRO] Falha ao cópia de estado.\n");
            return;
        }

        *copia = *estadoAtual;
        pushStack(stack, (void *)copia);

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
        ESTADO *copia = malloc(sizeof(ESTADO));
        if (copia == NULL)
        {
            printf("[ERRO] Falha ao cópia de estado.\n");
            return;
        }
        
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
        system("clear || cls");
        fflush(stdout);

        if(*estadoAtual != INICIAL && *estadoAtual != CONFIGURAR)
            mostrarPropaganda();
                
        switch (*estadoAtual)
        {
        case INICIAL:
            processarResultado(stack, estadoInicial(), estadoAtual, SELECIONAR);
            break;

        case SELECIONAR:
            processarResultado(stack, estadoSelecionar(), estadoAtual, PAGAR);
            break;

        case PAGAR:
            processarResultado(stack, estadoPagar(), estadoAtual, INICIAL);
            break;

        case CONFIGURAR:
            processarResultado(stack, estadoConfig(), estadoAtual, INICIAL);
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
    STACK stackEstados;
    ESTADO estadoAtual = INICIAL;

    iniciarStack(&stackEstados);

    iniciarGerenciadorAdmin();
    iniciarGerenciadorPropaganda();
    iniciarGerenciadorProdutos();
    iniciarGerenciadorMoedas();

    processarEstados(&stackEstados, &estadoAtual);

    limparGerenciadorMoedas();
    limparGerenciadorProdutos();
    limparGerenciadorPropaganda();
    limparGerenciadorAdmin();
    
    limparStack(&stackEstados);
}