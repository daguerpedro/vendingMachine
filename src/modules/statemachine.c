#include "statemachine.h"

#include <stdio.h>
#include <stdlib.h>

STATES machineState;

void setState(STATES newState)
{
    machineState = newState;
}

void listProducts();
void selectProduct();

void runMachine()
{
    bool isRunning = true;

    while (isRunning)
    {
        switch (machineState)
        {
        case MAINTENANCE:
            break;

        case PRODUCT_SHOWCASE:
            listProducts();
            setState(PRODUCT_SELECT);
            break;

        case PRODUCT_SELECT:
            // TODO: LIMITAR A PRODUTOS COM ESTOQUE
            // TODO: FAZER ALGUMA COISA?
            selectProduct();
            break;

        case PRODUCT_DELIVER:
            // TODO: DIMINUIR O ESTOQUE DO BANCO DE DADOS.
            // TODO: ANIMAÇÂO?
            setState(PRODUCT_SHOWCASE);
            break;

        case EXIT:
            isRunning = false;
            break;

        default:
            break;
        }
    }
}
