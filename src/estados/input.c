#include "input.h"

#include <stdio.h>

int captarEntrada()
{
    int input;
    int code = 0;
    do
    {
        code = scanf("%i", &input);
        fflush(stdin);
    } while (code <= 0);
    return input;
}