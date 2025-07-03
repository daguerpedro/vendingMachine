#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// @brief Inicia a lista
/// @param list 
void iniciarList(LIST *list)
{
    list->count = 0;
    list->inicio = NULL;
    list->final = NULL;
}

/// @brief Limpa a lista
/// @param list 
void limparList(LIST *list)
{
    NO *temp;
    while (!listVazia(list))
    {
        temp = list->inicio;
        list->inicio = temp->proximo;
        free(temp);
    }

    list->final = NULL;
    list->inicio = NULL;
}

/// @brief Verifica se a lista está vazia (inicio == NULL)
/// @param list 
/// @return true se vazia 
bool listVazia(LIST *list)
{
    return (list->inicio == NULL);
}

/// @brief Insere no final da lista
/// @param list 
/// @param data void*, estrutura genérica
void pushList(LIST *list, void *data)
{
    NO *novo = malloc(sizeof(NO));
    novo->valor = data;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if (listVazia(list))
    {
        list->inicio = novo;
        list->final = novo;
    }
    else
    {
        list->final->proximo = novo;
        novo->anterior = list->final;
        list->final = novo;
    }
    list->count++;
}

/// @brief Remove e libera da memória o nó na posição idx
/// @param list 
/// @param idx 
void removeList(LIST *list, int idx)
{
    if (listVazia(list) || idx < 0)
        return;
    if (idx >= list->count)
        return;

    NO *no = list->inicio;
    for (int i = 0; (i < idx && no != NULL); i++)
        no = no->proximo;
    if (no == NULL)
        return;

    NO *anterior = no->anterior;
    NO *proximo = no->proximo;

    if (anterior)
        anterior->proximo = proximo;
    else
        list->inicio = proximo;

    if (proximo)
        proximo->anterior = anterior;
    else
        list->final = anterior;

    free(no);
    list->count--;
}

/// @brief Insere na lista em uma posição.
/// @param list 
/// @param idx 
/// @param data void*, estrutura genérica
void insertList(LIST *list, int idx, void *data)
{
    if (idx <= 0)
    {
        NO *novo = malloc(sizeof(NO));
        novo->valor = data;
        novo->anterior = NULL;
        novo->proximo = list->inicio;

        if (list->inicio)
            list->inicio->anterior = novo;
        else
            list->final = novo;

        list->inicio = novo;
        list->count++;
        return;
    }

    if (idx >= list->count)
    {
        pushList(list, data);
        return;
    }

    NO *no = list->inicio;
    for (int i = 0; i < idx; i++)
        no = no->proximo;

    NO *anterior = no->anterior;
    NO *novo = malloc(sizeof(NO));

    novo->valor = data;
    novo->anterior = anterior;
    novo->proximo = no;

    anterior->proximo = novo;
    no->anterior = novo;

    list->count++;
}

/// @brief Retorna a estrutura genérica na posição idx
/// @param list 
/// @param idx 
/// @return 
void *getList(LIST *list, int idx)
{
    if (listVazia(list) || idx < 0 || idx >= list->count)
        return NULL;

    NO *no = list->inicio;
    for (int i = 0; (i < idx && no != NULL); i++)
        no = no->proximo;

    if (no == NULL)
        return NULL;

    return no->valor;
}

void printList(LIST *list)
{
    if (listVazia(list))
        return;

    NO *temp = list->inicio;
    int i = 0;

    printf("INICIO --> ");

    while (temp != NULL)
    {
        printf("| %02i: %i | --> ", i, *(int *)temp->valor);
        temp = temp->proximo;
        i++;
    }

    printf("FIM\n");
}