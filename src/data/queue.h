#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode
{
    struct QueueNode *next;
    void *data;
} QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;

} Queue;

/// @brief Initialize a queue
/// @param queue ptr to a queue
void initQueue(Queue *queue);

/// @brief The state of the queue
/// @param queue ptr to a queue
/// @return true if is empty
bool isQueueEmpty(Queue *queue);

/// @brief Tries to enqueue
/// @param queue
/// @param data
/// @return false if failed, true if succeed
bool enqueue(Queue *queue, void *data);

/// @brief Tries to dequeue
/// @param queue ptr to a queue
/// @param dataDestiny ptr to a void* that will hold queue's tail data.
/// @return false if failed, true if succeed
bool dequeue(Queue *queue, void** dataDestiny);

void freeQueue(Queue* queue);