#include "statemachine.h"
#include <products.h>
#include <stdio.h>
#include <stdlib.h>

#include <propaganda.h>

STATES machineState;

void setState(STATES newState)
{
    machineState = newState;
}

void listProducts()
{
    printf("\033[2J\033[H"); // Limpar tela

    printf("> "); // Propaganda superior
    showPropaganda(getPropagandaList());
    printf(" <\n\n");

    if (getProductList() != NULL)
    {
        for (int i = 0; i < listCount(getProductList()); i++)
        {
            PRODUCT *product = listGetAt(getProductList(), i)->data;
            printf(" (%02i) %s - $%.2f [R:%i]\n", i + 1, product->name, product->price, product->stock);
        }
    }

    printf("\n (-1) Para sair.\n");

    printf("\n> "); // Propaganda inferior
    showPropaganda(getPropagandaList());
    printf(" <\n");
}

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