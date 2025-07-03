#include <stdbool.h>
#include <no.h>

/// @brief Queue/Fila
typedef struct QUEUE
{
    NO *primeiro;
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