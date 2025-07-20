/**
 * @file produtos.h
 * @author daguer
 * @brief Gerencia os produtos, manipula em arquivo binário e cria lista de produtos na memória.
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _PRODUTOS_H
#define _PRODUTOS_H

#include <stdbool.h>
#include <stdio.h>

/// @brief Estrutura para produtos.
typedef struct PRODUTO_HEADER
{
    /// @brief Nome do produto
    char name[20];
    /// @brief Preço do produto
    float preço;
    /// @brief Quantidade em estoque
    int estoque;
    /// @brief Deve mostrar na vitrine
    bool naVitrine;
    /// @brief Produto está deletado
    bool deletado;
} PRODUTO_HEADER;

/// @brief Inicia o gerenciador de produtos
void iniciarGerenciadorProdutos();

/// @brief Limpa o gerenciador de produtos
void limparGerenciadorProdutos();

/// @brief Carrega o arquivo de produtos para a lista de produtos na memória.
void carregarProdutos();

/// @brief Lista todos os produtos
void listarProdutos();

/// @brief Verifica se um produto é valido
/// @param i numero equivalente na lista
/// @return true se valido
bool produtoValido(int i);

/// @brief Seleciona um produto.
/// @param i Index do produto.
void selecionaProduto(int i);

/// @brief Armazena informações do produto selecionado
/// @return Informações do produto.
PRODUTO_HEADER produtoSelecionado();

/// @brief Cria o arquivo padrão.
/// @return Ptr para arquivo.
FILE *criarArquivoProdutosPadrao();

/// @brief Cria um produto
/// @param name Nome do produto
/// @param preço Preço do produto
/// @param estoque Valor em estoque
/// @param ativo Está ativo para listagem
/// @param database Ponteiro para o arquivo de produtos
/// @return Ponteiro para estrutura do produto
PRODUTO_HEADER* criarProduto(char* name, float preço, int estoque, bool naVitrine, FILE* databse);
#endif