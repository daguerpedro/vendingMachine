#include "admin.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

MACHINE_INFO machineInfo;

void iniciarGerenciadorAdmin()
{
    FILE *file = fopen("config.bin", "rb");
    if (file == NULL)
    {
        file = criarArquivoAdminPadrao();
        if (file == NULL)
        {
            printf("[ERRO FATAL] NÃO FOI POSSIVEL ABRIR NEM CRIAR O ARQUIVO DE CONFIGURAÇÃO!\n");
            exit(EXIT_FAILURE);
        }
    }

    fread(&machineInfo, sizeof(MACHINE_INFO), 1, file);
    fclose(file);
}

void limparGerenciadorAdmin()
{
}

FILE *criarArquivoLogPadrao()
{
    FILE *file = fopen("logs.txt", "w");
    if (file != NULL)
    {
        rewind(file);
    }
    else
    {
        printf("[ERRO] Falha ao criar arquivo log padrão.\n");
    }

    return file;
}

FILE *criarArquivoAdminPadrao()
{
    FILE *file = fopen("config.bin", "wb+");
    if (file != NULL)
    {
        MACHINE_INFO info;
        snprintf(info.greetings, sizeof(info.greetings), "> Bem vindo à máquina de refris!\n\n (1) Iniciar compras. \n (-1) Sair\n");
        machineInfo = info;

        fwrite(&info, sizeof(MACHINE_INFO), 1, file);
        rewind(file);
    }
    else
    {
        printf("[ERRO] Falha ao criar arquivo admin padrão.\n");
    }

    return file;
}

//TODO
void criarLogVenda(PRODUTO_HEADER produtoVendido)
{
}