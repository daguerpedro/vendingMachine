#include "produtos.h"
#include <list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

LIST produtosLista;

void iniciarGerenciadorProdutos()
{
    iniciarList(&produtosLista);
    carregarProdutos();
}

void limparGerenciadorProdutos()
{
    limparList(&produtosLista);
}

void listarProdutos()
{
    if (listVazia(&produtosLista))
        return;

    printf("PRODUTOS: \n\n");
    NO *temp = produtosLista.inicio;

    while (temp != NULL)
    {
        PRODUTO_HEADER produto = *(PRODUTO_HEADER *)temp->valor;
        if (produto.naVitrine)
        {
            printf("(%02i) %s R$ %0.2f [%01i]\n", indexOf(&produtosLista, temp->valor) + 1, produto.name, produto.preço, produto.estoque);
        }
        temp = temp->proximo;
    }
}

PRODUTO_HEADER *criarProduto(char *name, float preço, int estoque, bool naVitrine, FILE *database)
{
    PRODUTO_HEADER *novo = malloc(sizeof(PRODUTO_HEADER));
    if (novo == NULL)
    {
        printf("[ERRO] Falha ao alocar produto.\n");
        return NULL;
    }

    strncpy(novo->name, name, sizeof(novo->name) - 1);
    novo->name[sizeof(novo->name) - 1] = '\0';

    novo->naVitrine = naVitrine;
    novo->estoque = estoque;
    novo->preço = preço;
    novo->deletado = false;

    // Salvar onde estavamos para podermos restaurar depois.
    long posAnterior = ftell(database);

    // Vamos pre-definir a posição de escrita no final do arquivo.
    fseek(database, 0, SEEK_END);
    long posEscrita = ftell(database);

    // Voltamos ao inicio do arquivo para procurarmos por uma posicao livre.
    rewind(database);

    // Tentamos varrer todos os produtos registrados. Caso nao encontre nenhuma, ja temos o final do arquivo pre-setado.
    PRODUTO_HEADER idx;
    while (fread(&idx, sizeof(PRODUTO_HEADER), 1, database) == 1)
    {
        if (idx.deletado == true)
        {
            posEscrita = ftell(database) - sizeof(PRODUTO_HEADER);
            break;
        }
    }

    // Vamos até a posicao disponivel e escrevemos o produto novo.
    fseek(database, posEscrita, SEEK_SET);
    fwrite(novo, sizeof(PRODUTO_HEADER), 1, database);
    fflush(database);
    fseek(database, posAnterior, SEEK_SET);

    return novo;
}

FILE *criarArquivoProdutosPadrao()
{
    FILE *file = fopen("produtos.bin", "wb+");
    if (file != NULL)
    {
        // Vamos dar free depois de criar pois não vamos registrar esses produtos na memória, deixaremos a função carregar produtos fazer isso.
        free(criarProduto("Pureza", 1.5, 5, true, file));
        free(criarProduto("Guaraná Jesus", 1.5, 3, true, file));
        rewind(file);
    }
    else
    {
        printf("[ERRO] Falha ao criar arquivo produtos padrão.\n");
    }

    return file;
}

void carregarProdutos()
{
    FILE *file = fopen("produtos.bin", "rb");
    if (file == NULL)
    {
        file = criarArquivoProdutosPadrao();
        if (file == NULL)
        {
            printf("[ERRO FATAL] NÃO FOI POSSIVEL ABRIR NEM CRIAR O ARQUIVO DE PRODUTOS!\n");
            exit(EXIT_FAILURE);
        }
    }

    PRODUTO_HEADER idx;
    while (fread(&idx, sizeof(PRODUTO_HEADER), 1, file) == 1)
    {
        if (idx.deletado == false)
        {
            PRODUTO_HEADER *registro = malloc(sizeof(PRODUTO_HEADER));
            if (registro == NULL)
            {
                printf("[ERRO] Falha ao alocar produto.\n");
                return;
            }

            *registro = idx;
            pushList(&produtosLista, (void *)registro);
        }
    }
    fclose(file);
}

bool produtoValido(int i)
{
    if (listVazia(&produtosLista))
        return false;
    PRODUTO_HEADER *produto = getList(&produtosLista, i);
    if (produto == NULL)
        return false;
    if (produto->deletado || produto->naVitrine == false || produto->estoque <= 0)
        return false;
    return true;
}

PRODUTO_HEADER *selecionado;

void selecionaProduto(int i)
{
    if (produtoValido(i))
        selecionado = (PRODUTO_HEADER *)getList(&produtosLista, i);
}

PRODUTO_HEADER produtoSelecionado()
{
    return *selecionado;
}