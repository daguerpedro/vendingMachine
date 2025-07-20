/**
 * @file admin.h
 * @author daguer
 * @brief Gerenciador de configurações da máquina.
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _ADMIN_H
#define _ADMIN_H

#include <stdio.h>
#include <produtos.h>

/// @brief Carrega as informações da máquina que são exibidas no menu inicial.
typedef struct MACHINE_INFO
{
    char greetings[100];
} MACHINE_INFO;

extern MACHINE_INFO machineInfo;

//TODO: LOGS, salva os logs de venda na memoria e quando a maquina vai fechar ou vendas > 3, escreve nos arquivos;
void criarLogVenda(PRODUTO_HEADER produtoVendido);

/// @brief Inicia o gerenciador de admin
void iniciarGerenciadorAdmin();

/// @brief Limpa o gerenciador de admin
void limparGerenciadorAdmin();

/// @brief Cria arquivo padrão
/// @return Ptr para arquivo.
FILE *criarArquivoAdminPadrao();

/// @brief Cria arquivo padrão
/// @return Ptr para arquivo.
FILE *criarArquivoLogPadrao();

#endif