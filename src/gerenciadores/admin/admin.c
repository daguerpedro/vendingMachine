#include "admin.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <time.h>
#include <produtos.h>

MACHINE_INFO machineInfo;
LIST logList;

void iniciarGerenciadorAdmin()
{
    iniciarList(&logList);

    carregarArquivoAdmin();
    carregarArquivoLog();
}

void carregarArquivoAdmin()
{
    FILE *file = fopen("config.bin", "rb");
    if (file == NULL)
    {
        file = criarArquivoAdminPadrao();
        if (file == NULL)
        {
            printf("[ERRO FATAL] NÃO FOI POSSIVEL ABRIR NEM CRIAR O ARQUIVO DE CONFIGURACAO!\n");
            exit(EXIT_FAILURE);
        }
    }

    fread(&machineInfo, sizeof(MACHINE_INFO), 1, file);
    fclose(file);
}

void carregarArquivoLog()
{
    FILE *file = fopen("logs.txt", "r");
    if (file != NULL)
    {
        int i = 0;
        char buffer[1024 * 3];
        while (fgets(buffer, sizeof(buffer), file))
        {
            pushList(&logList, strdup(buffer));
        }

        fclose(file);
    }
}

void limparGerenciadorAdmin()
{
    salvarLogs(true);
    limparList(&logList);
}

void atualizarArquivoAdmin()
{
    FILE *file = fopen("config.bin", "wb+");
    if (file != NULL)
    {
        fwrite(&machineInfo, sizeof(MACHINE_INFO), 1, file);
        fclose(file);
    }
    else
    {
        printf("[ERRO] Falha ao sobrescrever arquivo configuração.\n");
    }
}

FILE *criarArquivoAdminPadrao()
{
    FILE *file = fopen("config.bin", "wb+");
    if (file != NULL)
    {
        MACHINE_INFO info;
        snprintf(info.greetings, sizeof(info.greetings), "> Bem vindo à máquina de refris!\n\n ( 1) Iniciar compras. \n\n (-1) Sair\n");
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

void criarLogVenda(PRODUTO_HEADER produtoVendido)
{
    PRODUTO_HEADER *produto = malloc(sizeof(PRODUTO_HEADER));
    *produto = produtoVendido;

    char buffer[1024 * 3];

    time_t agora;
    time(&agora);
    struct tm *info_tempo;
    info_tempo = localtime(&agora);

    strftime(buffer, sizeof(buffer), "[%d/%m/%Y] %H:%M:%S ", info_tempo);
    snprintf(buffer + strlen(buffer),
             sizeof(buffer) - strlen(buffer),
             "%s vendido por R$%0.2f | Novo estoque: %i\n",
             produtoVendido.name,
             produtoVendido.preço,
             produtoVendido.estoque); // buffer + strlen(buffer) para escrever no final da string existente.
    pushList(&logList, strdup(buffer));
    salvarLogs(false);
}

FILE *logFilePTR;
void writeLog(void *data)
{
    if (logFilePTR == NULL)
    {
        printf("[ERRO] Falha ao salvar log pois arquivo logs.txt é nulo!\n");
        return;
    }

    char *buffer = (char *)data;
    fprintf(logFilePTR, "%s", buffer);
};

void salvarLogs(bool force)
{
    if (force == false && logList.count < 3)
        return;

    // Vamos sobrescrever o arquivo | existem maneiras melhor, como ir ao final do arquivo e inserir lá.
    // O problema é que quando carregamos o arquivo de logs no inicio do programa, inserimos TODOS os logs ná lista de logs que será salva.
    logFilePTR = fopen("logs.txt", "w");
    if (logFilePTR == NULL)
    {
        printf("[ERRO] Falha ao criar arquivo logs.txt para salvar logs!\n");
        return;
    }

    iterarLista(&logList, writeLog);

    fclose(logFilePTR);
}

void printLog(void* data)
{
    char *buffer = (char *)data;
    printf("> %s", buffer);
}

void imprimirLogs()
{
    iterarLista(&logList, printLog);
}