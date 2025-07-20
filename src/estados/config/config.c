#include "config.h"
#include <stdio.h>
#include <admin.h>
#include <input.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mostrarOpções()
{
    clear();
    
    printf("------------------------------------------------\n");
    printf("> MENU CONFIGURAÇÃO MÁQUINA DE REFRIS\n");
    printf("------------------------------------------------\n");
    printf(" *  0: Sair do modo configuração.\n");
    printf("------------------------------------------------\n");
    printf(" *  1: Imprimir logs de vendas.\n");
    printf(" *  2: Salvar logs de vendas no arquivo de logs.\n");
    printf("------------------------------------------------\n");
    printf(" *  3: Editar mensagem do menu inicial.\n");
    printf("------------------------------------------------\n");
    printf(" *  4: Editar um produto.\n");     
    printf("------------------------------------------------\n");
    printf(" * -1: Desligar máquina.\n");        
    printf("------------------------------------------------\n> ");
};

void mostrarLogs()
{
    clear();
    printf("> Logs de vendas:\n\n");
    imprimirLogs();
    pause();
}

void forcarSalvamento()
{
    salvarLogs(true);
    printf("> Logs salvos!\n");
    pause();
}

//TODO: EDITAR CRIAR E DELETAR PRODUTOS
//TODO: EDITAR MACHINE INFO
void input(RESULTADO_ESTADO* result)
{
    mostrarOpções();

    int entrada = captarEntrada(false);
    switch (entrada)
    {
    case 0:
        *result = PROXIMO;
        return;
        break;
    case 1:
        mostrarLogs();
        break;
    case 2:
        forcarSalvamento();
        break;
    case -1:
        *result = SAIR;
        return;
        break;
    }

    input(result);
}

RESULTADO_ESTADO estadoConfig()
{
    RESULTADO_ESTADO res;

    input(&res);

    return res;
}