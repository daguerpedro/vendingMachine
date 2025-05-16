#include "queue.h"

void initQueue(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}


bool isQueueEmpty(Queue *queue)
{
    return queue->head == NULL;
}


bool enqueue(Queue *queue, void *data)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if (node == NULL)
    {
#ifdef DEBUG
        printf("[DEBUG] Failed to malloc at enqueue.\n");
#endif
        return false;
    }

    node->data = data;
    node->next = NULL;

    if (isQueueEmpty(queue))
    {
        queue->head = node;
        queue->tail = node;
        return true;
    }

    if (queue->tail != NULL)
        queue->tail->next = node;

    queue->tail = node;
    return true;
}

bool dequeue(Queue *queue, void** dataDestiny)
{
    if (isQueueEmpty(queue))
    {
#ifdef DEBUG
        printf("[DEBUG] Tried to dequeue an empty queue.\n");
#endif
        return false;
    }

    QueueNode* head = queue->head;
    *dataDestiny = head->data;

    if (head->next != NULL) // Isn't last node
        queue->head = head->next;
    else
    {
        queue->head = NULL;
        queue->tail = NULL;
    }

    free(head);
    return true;
}

void freeQueue(Queue* queue)
{
    void* data;
    while(!isQueueEmpty(queue))
    {
        dequeue(queue, &data);
        if(data != NULL) free(data);
    }
}