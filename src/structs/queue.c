#include <stdio.h>
#include <stdlib.h>

#include <queue.h>

void iniciarQueue(QUEUE *queue)
{
    queue->primeiro = NULL;
    queue->ultimo = NULL;
}

bool queueVazia(QUEUE *queue)
{
    return (queue->primeiro == NULL);
}

void limparQueue(QUEUE *queue)
{
    while (queueVazia(queue) == false)
    {
        NO *no = queue->primeiro;
        queue->primeiro = no->proximo;
        free(no);
    };
}

void enQueue(QUEUE *queue, void *valor)
{
    NO *no = malloc(sizeof(NO));
    if(no == NULL)
    {
        printf("[ERRO] Falha ao alocar elemento para fila.\n");
        return;
    }
    no->valor = valor;
    no->proximo = NULL;
    no->anterior = NULL;

    if (queueVazia(queue))
    {
        queue->primeiro = no;
        queue->ultimo = no;
    }
    else
    {
        NO *ultimo = queue->ultimo;
        no->anterior = ultimo;

        ultimo->proximo = no;

        queue->ultimo = no;
    }
}
void *deQueue(QUEUE *queue)
{
    if (queueVazia(queue))
        return NULL;

    NO *primeiroFila = queue->primeiro;
    void *dado = primeiroFila->valor;

    if (primeiroFila != queue->ultimo)
    {
        primeiroFila->proximo->anterior = NULL;
        queue->primeiro = primeiroFila->proximo;
    }
    else
    {
        queue->primeiro = NULL;
        queue->ultimo = NULL;
    }

    free(primeiroFila);
    return dado;
}