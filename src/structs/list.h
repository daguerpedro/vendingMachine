#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>
#include "no.h"

/// @brief Lista duplamente encadeada
typedef struct LIST
{
    NO* inicio;
    NO* final;

    int count;
} LIST;

/// @brief Inicia a lista
/// @param list 
void iniciarList(LIST* list);
/// @brief Limpa a lista
/// @param list 
void limparList(LIST* list);
/// @brief Verifica se a lista está vazia (inicio == NULL)
/// @param list 
/// @return true se vazia 
bool listVazia(LIST* list);
/// @brief Insere no final da lista
/// @param list 
/// @param data void*, estrutura genérica
void pushList(LIST* list, void* data);
/// @brief Remove e libera da memória o nó na posição idx
/// @param list 
/// @param idx 
void removeList(LIST* list, int idx);
/// @brief Insere na lista em uma posição.
/// @param list 
/// @param idx 
/// @param data void*, estrutura genérica
void insertList(LIST* list, int idx, void* data);
/// @brief Retorna a estrutura genérica na posição idx
/// @param list 
/// @param idx 
/// @return 
void* getList(LIST* list, int idx);
void printList(LIST* list);

/// @brief Retorna a posição de um valor na lista
/// @param list Ref para lista 
/// @param data Valor
/// @return numero/posicao na lista
int indexOf(LIST* list, void*data);

#endif