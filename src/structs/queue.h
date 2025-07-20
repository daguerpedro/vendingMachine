/**
 * @file queue.h
 * @author daguer
 * @brief Estrutura de dados do tipo queue genérica
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdbool.h>
#include <no.h>

/// @brief Queue/Fila genérica
typedef struct QUEUE
{
    /// @brief Primeiro da fila
    NO *primeiro;
    /// @brief Último da fila
    NO *ultimo;
} QUEUE;

/// @brief Inicia uma queue
/// @param queue ref para queue
void iniciarQueue(QUEUE *queue);

/// @brief Limpa uma queue
/// @param queue ref para queue
void limparQueue(QUEUE *queue);

/// @brief Verifica se queue está vazia
/// @param queue ref para queue
/// @return true se vazia
bool queueVazia(QUEUE *queue);

/// @brief Enfileira um valor
/// @param queue ref para queue
/// @param valor estrutura genérica
void enQueue(QUEUE *queue, void* valor);

/// @brief Pega o primeiro valor da queue
/// @param queue ref para queue
/// @return estrutura genérica
void* deQueue(QUEUE *queue);