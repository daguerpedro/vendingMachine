#include "produtos.h"
#include <list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <admin.h>

FILE *productFile;
LIST produtosLista;

void iniciarGerenciadorProdutos()
{
    iniciarList(&produtosLista);
    carregarProdutos();
}

void limparGerenciadorProdutos()
{
    fclose(productFile);
    limparList(&produtosLista);
}

void listarProdutos(bool showAdminInfo)
{
    if (listVazia(&produtosLista))
        return;

    printf("PRODUTOS: \n\n");
    NO *temp = produtosLista.inicio;

    while (temp != NULL)
    {
        PRODUTO_HEADER produto = *(PRODUTO_HEADER *)temp->valor;

        if (!showAdminInfo)
        {
            if (produto.naVitrine && !produto.deletado)
            {
                printf("(%02i) %s R$ %0.2f [x%01i]%s\n",
                       indexOf(&produtosLista, temp->valor) + 1,
                       produto.name,
                       produto.preço,
                       produto.estoque);
            }
        }
        else
        {
            printf("#%i %s:\n - Preço R$ %0.2f\n - Estoque: %01i\n - Na vitrine: %s\n - Deletado: %s\n",
                   indexOf(&produtosLista, temp->valor),
                   produto.name,
                   produto.preço,
                   produto.estoque,
                   produto.naVitrine ? "Sim" : "Não",
                   produto.deletado ? "Sim" : "Não");
        }
        temp = temp->proximo;
    }
}

PRODUTO_HEADER *criarProduto(char *name, float preço, int estoque, bool naVitrine)
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
    long posAnterior = ftell(productFile);

    // Vamos pre-definir a posição de escrita no final do arquivo pois caso nao tenha posição livre, escrevemos no fim.
    long posEscrita = -1;
    // Voltamos ao inicio do arquivo para procurarmos por uma posicao livre.
    rewind(productFile);

    // Tentamos varrer todos os produtos registrados. Caso nao encontre nenhuma, ja temos o final do arquivo pre-setado.
    PRODUTO_HEADER idx;
    while (fread(&idx, sizeof(PRODUTO_HEADER), 1, productFile) == 1)
    {
        if (idx.deletado == true)
        {
            posEscrita = ftell(productFile) - sizeof(PRODUTO_HEADER);
            break;
        }
    }

    // Vamos até a posicao disponivel e escrevemos o produto novo.
    fseek(productFile, posEscrita, SEEK_SET);
    fwrite(novo, sizeof(PRODUTO_HEADER), 1, productFile);
    fflush(productFile);
    fseek(productFile, posAnterior, SEEK_SET);

    return novo;
}

FILE *criarArquivoProdutosPadrao()
{
    FILE *file = fopen("produtos.bin", "wb+");
    if (file != NULL)
    {
        productFile = file;

        // Vamos dar free depois de criar pois não vamos registrar esses produtos na memória, deixaremos a função carregar produtos fazer isso.
        free(criarProduto("Pureza", 1.5, 5, true));
        free(criarProduto("Guaraná Jesus", 1.5, 3, true));
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
    limparList(&produtosLista);
    
    productFile = fopen("produtos.bin", "rb+");
    if (productFile == NULL)
    {
        productFile = criarArquivoProdutosPadrao();
        if (productFile == NULL)
        {
            printf("[ERRO FATAL] NÃO FOI POSSIVEL ABRIR NEM CRIAR O ARQUIVO DE PRODUTOS!\n");
            exit(EXIT_FAILURE);
        }
    }

    rewind(productFile);

    PRODUTO_HEADER idx;
    while (fread(&idx, sizeof(PRODUTO_HEADER), 1, productFile) == 1)
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

bool produtoExiste(int i)
{
    if (listVazia(&produtosLista))
        return false;

    PRODUTO_HEADER *produto = getList(&produtosLista, i);

    return produto != NULL;
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

PRODUTO_HEADER *getProductOnList(int i)
{
    return (PRODUTO_HEADER *)getList(&produtosLista, i);
}

void selecionaProduto(int i)
{
    if (produtoValido(i))
        selecionado = (PRODUTO_HEADER *)getList(&produtosLista, i);
}

PRODUTO_HEADER produtoSelecionado()
{
    return *selecionado;
}

void venderProduto()
{
    selecionado->estoque--;

    if (productFile != NULL)
    {
        int pos = indexOf(&produtosLista, selecionado);

        long ondeEstava = ftell(productFile);
        fseek(productFile, sizeof(PRODUTO_HEADER) * pos, SEEK_SET);
        fwrite(selecionado, sizeof(PRODUTO_HEADER), 1, productFile);
        fseek(productFile, ondeEstava, SEEK_SET);
    }
    else
    {
        printf("[ERRO] Falha ao salvar informação de diminuir estoque do produto após venda!\n");
    }

    criarLogVenda(*selecionado);
}

void atualizarProduto(int i)
{
    if (productFile == NULL)
    {
        printf("[ERRO] Falha ao abrir arquivo de produtos para atualizar um produto!\n");
        return;
    }

    PRODUTO_HEADER *produto = getList(&produtosLista, i);
    if (produto == NULL)
    {
        printf("[ERRO] Produto %i retornou null!\n", i);
        return;
    }

    long ondeEstava = ftell(productFile);

    fseek(productFile, sizeof(PRODUTO_HEADER) * i, SEEK_SET);
    fwrite(produto, sizeof(PRODUTO_HEADER), 1, productFile);
    fseek(productFile, ondeEstava, SEEK_SET);
}