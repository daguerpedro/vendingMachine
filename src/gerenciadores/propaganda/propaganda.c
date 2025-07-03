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

/// @brief Finaliza e limpa as memórias utilizadas pelo gerenciador.
void limparGerenciadorPropaganda()
{
    limparQueue(&qPropagandas);
}

/// @brief Carrega o arquivo de propagandas.
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

    return file;
}