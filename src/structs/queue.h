#include <stdbool.h>
#include <no.h>

typedef struct QUEUE
{
    NO *primeiro;
    NO *ultimo;
} QUEUE;

void iniciarQueue(QUEUE *queue);
void limparQueue(QUEUE *queue);
bool queueVazia(QUEUE *queue);
void enQueue(QUEUE *queue, void* valor);
void* deQueue(QUEUE *queue);