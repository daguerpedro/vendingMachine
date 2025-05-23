#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "statemachine.h"

int getUserInput()
{
    printf("\n> Selecione o produto: ");
    int user = 0;

    bool converteu = false;
    do
    {
        converteu = scanf("%i", &user) > 0;
        fflush(stdin);
    } while (!converteu);

    return user;
}

void selectProduct()
{
    int produto = getUserInput();

    if (produto == -1)
    {
        setState(EXIT);
        return;
    }

    setState(PRODUCT_DELIVER);
}