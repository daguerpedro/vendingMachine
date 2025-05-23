#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <propaganda.h>
#include <products.h>

void listProducts()
{
    system("cls || clear");

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