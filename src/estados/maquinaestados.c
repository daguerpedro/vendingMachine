#include <maquinaestados.h>
#include <stacks/estados.h>

#include <estados/config/config.h>
#include <estados/listar/listar.h>
#include <estados/pagar/pagar.h>
#include <estados/selecionar/selecionar.h>

#include <stdio.h>

bool rodar;

void voltarEstado(STACK_ESTADOS* stack, ESTADO* estadoAtual)
{
    if(stackEstadoVazia(stack)) return;
    *estadoAtual = popEstado(stack);
}

void processarEstado(STACK_ESTADOS* stack, ESTADO* estadoAtual)
{
    switch (*estadoAtual)
    {
    case LISTAR:
        RESULTADO_ESTADO result = estadoListar();

        if(result == VOLTAR)
            voltarEstado(stack, estadoAtual);
        if(result == PROXIMO)
        {
            pushEstado(stack, *estadoAtual);
            *estadoAtual = SELECIONAR;
        }
        if(result == ADM)
        {
            pushEstado(stack, *estadoAtual);
            *estadoAtual = CONFIGURAR;
        }
        
        break;

    case SELECIONAR:
        result = estadoSelecionar();

        if(result == VOLTAR)
            voltarEstado(stack, estadoAtual);
        if(result == PROXIMO)
        {
            pushEstado(stack, *estadoAtual);
            *estadoAtual = PAGAR;
        }
        break;

    case PAGAR:
        result = estadoPagar();

        if(result == VOLTAR)
            voltarEstado(stack, estadoAtual);
        if(result == PROXIMO)
        {
            pushEstado(stack, *estadoAtual);
            *estadoAtual = LISTAR;
        }
        break;

    case CONFIGURAR:
        result = estadoConfig();

        if(result == VOLTAR)
            voltarEstado(stack, estadoAtual);
        if(result == PROXIMO)
        {
            pushEstado(stack, *estadoAtual);
            *estadoAtual = LISTAR;
        }
        break;

    default:
        break;
    }
}

void processarEstados(STACK_ESTADOS* stack, ESTADO* estadoAtual)
{
    while (rodar)
    {
        processarEstado(stack, estadoAtual);
    }
    
}

void iniciarMaquinaEstados()
{
    rodar = true;
    STACK_ESTADOS stack;
    ESTADO estadoAtual = LISTAR;

    iniciarStackEstados(&stack);
    processarEstados(&stack, &estadoAtual);
    limparStackEstados(&stack);   
}