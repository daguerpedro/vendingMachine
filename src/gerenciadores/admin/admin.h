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

#include <stdbool.h>
#include <stdio.h>
#include <produtos.h>

/// @brief Carrega as informações da máquina que são exibidas no menu inicial.
typedef struct MACHINE_INFO
{
    char greetings[100];
} MACHINE_INFO;

extern MACHINE_INFO machineInfo;

/// @brief Cria um log de produto vendido
/// @param produtoVendido Ref/Cópia do produto.
void criarLogVenda(PRODUTO_HEADER produtoVendido);

/// @brief Inicia o gerenciador de admin
void iniciarGerenciadorAdmin();

/// @brief Limpa o gerenciador de admin
void limparGerenciadorAdmin();

/// @brief Carrega o arquivo de configuração.
void carregarArquivoAdmin();

/// @brief Carrega o arquivo de logs.
void carregarArquivoLog();

/// @brief Salva os logs 
/// @param force true = salva na hora | false = salva se count da lista de logs >= 3
void salvarLogs(bool force);

/// @brief Cria arquivo padrão
/// @return Ptr para arquivo.
FILE *criarArquivoAdminPadrao();

/// @brief Mostra todos os logs.
void imprimirLogs();

#endif