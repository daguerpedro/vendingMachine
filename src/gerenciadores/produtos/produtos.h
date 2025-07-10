#ifndef _PRODUTOS_H
#define _PRODUTOS_H

#include <stdbool.h>
#include <stdio.h>

/// @brief Estrutura para produtos.
typedef struct PRODUTO_HEADER
{
    char name[20];
    float preço;
    int estoque;
    bool naVitrine;
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

void selecionaProduto(int i);
PRODUTO_HEADER produtoSelecionado();

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