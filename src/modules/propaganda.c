#include "propaganda.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Para o uso do stateMachine
Queue* _proplist;

Queue* getPropagandaList()
{
    return _proplist;
}

/// @brief Carrega o arquivo de propagandas dentro da fila de propagandas
/// @param propagandaQueue ptr para file de propagandas
/// @param fileName Arquivo que contem as propagandas
void loadPropagandas(Queue *propagandaQueue, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL) //AD-BLOCKER!
    {
#ifdef DEBUG
        printf("[DEBUG] loadPropagandas() Failed to open file %s.\n", fileName);
#endif
        return;
    }

    char propagandaBuffer[1024];
    while (fgets(propagandaBuffer, sizeof(propagandaBuffer), file))
    {
        propagandaBuffer[strcspn(propagandaBuffer, "\n")] = '\0';
        char *propaganda = strdup(propagandaBuffer);
        if (propaganda == NULL)
        {
#ifdef DEBUG
            printf("[DEBUG] loadPropagandas() Failed to strdup %s.\n", propagandaBuffer);
#endif
            return;
        }

        if (!enqueue(propagandaQueue, (void *)propaganda))
        {
#ifdef DEBUG
            printf("[DEBUG] loadPropagandas() Failed to enqueue %s.\n", propaganda);
#endif
        }
    }

    fclose(file);

    _proplist = propagandaQueue;
}

void showPropaganda(Queue *propagandaQueue)
{
    void *data;
    if (!dequeue(propagandaQueue, &data))
    {
#ifdef DEBUG
        printf("[DEBUG] showPropaganda() Failed to dequeue.\n");
#endif
        return;
    }

    printf("%s", (char *)data);
    if (!enqueue(propagandaQueue, data))
    {
        printf("\n");
#ifdef DEBUG
        printf("[DEBUG] showPropaganda() Failed to requeue..\n");
#endif
    }
}