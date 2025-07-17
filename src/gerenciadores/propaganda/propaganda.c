#include "propaganda.h"
#include <structs/queue.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

QUEUE qPropagandas;

void iniciarGerenciadorPropaganda()
{
    iniciarQueue(&qPropagandas);
    carregarPropagandas();
}

void limparGerenciadorPropaganda()
{
    limparQueue(&qPropagandas);
}

void carregarPropagandas()
{
    FILE *file = fopen("propagandas.bin", "rb");
    if (file == NULL)
    {
        file = criarArquivoPropagandasPadrao();
        if (file == NULL)
        {
            printf("[ERRO FATAL] NÃO FOI POSSIVEL ABRIR NEM CRIAR O ARQUIVO DE PROPAGANDAS!\n");
            exit(EXIT_FAILURE);
        }
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        size_t len = strlen(buffer);
        if (buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';

        char *propaganda = malloc(strlen(buffer) + 1);
        if (propaganda != NULL)
        {
            strcpy(propaganda, buffer);
            enQueue(&qPropagandas, (void *)propaganda);
        }
        else
        {
            printf("[ERRO] Falha ao alocar buffer para propaganda.\n");
        }
    }
    fclose(file);
}

char *pegarPropaganda()
{
    void *ref = deQueue(&qPropagandas);
    return (char *)ref;
}

void devolverPropaganda(char *propaganda)
{
    enQueue(&qPropagandas, (void *)propaganda);
}

FILE *criarArquivoPropagandasPadrao()
{
    FILE *file = fopen("propagandas.bin", "wb+");
    if (file != NULL)
    {
        fprintf(file, "Volt - Sinta a energia que move você.\n");
        fprintf(file, "Zest - Mais que um sabor, uma revolução.\n");
        fprintf(file, "Nexo - Tecnologia que entende o seu mundo.\n");
        fprintf(file, "Vira - Vista o que você acredita.\n");
        fprintf(file, "Lume - O futuro começa com uma escolha.\n");
        rewind(file);
    }
    else
    {
        printf("[ERRO] Falha ao criar arquivo propaganda padrão.\n");
    }
    
    return file;
}

void mostrarPropaganda()
{
    char *propaganda = pegarPropaganda();
    printf("> %s <\n\n", propaganda);
    devolverPropaganda(propaganda);
}
