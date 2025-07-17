#ifndef _ADMIN_H
#define _ADMIN_H

#include <stdio.h>
#include <produtos.h>

typedef struct MACHINE_INFO
{
    char greetings[100];
} MACHINE_INFO;

extern MACHINE_INFO machineInfo;

//TODO: LOGS
void criarLogVenda(PRODUTO_HEADER produtoVendido);

/// @brief Inicia o gerenciador de admin
void iniciarGerenciadorAdmin();

/// @brief Limpa o gerenciador de admin
void limparGerenciadorAdmin();

FILE *criarArquivoAdminPadrao();
FILE *criarArquivoLogPadrao();

#endif