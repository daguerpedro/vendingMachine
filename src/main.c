#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <statemachine.h>

#include <queue.h>
#include <list.h>

#include <propaganda.h>
#include <products.h>


Queue propagandaQueue;
List productList;

void setup()
{
    initQueue(&propagandaQueue);
    initList(&productList);

    loadPropagandas(&propagandaQueue, "propaganda.txt");
    loadProducts(&productList);
    
    setState(PRODUCT_SHOWCASE);
}

void clean()
{
    freeQueue(&propagandaQueue);
    freeList(&productList);
}

int main()
{
    setup();
    
    runMachine();

    clean();
}