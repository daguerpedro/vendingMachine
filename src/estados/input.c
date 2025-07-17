#include "input.h"

#include <stdio.h>
#include <stdbool.h>

int captarEntrada(bool mostrarNav)
{
    
    int input;
    int code = 0;
    do
    {
        if(mostrarNav)
        {
            printf("[-1: SAIR | 0 VOLTAR]: ");
            fflush(stdout);
        }
        code = scanf("%i", &input);
        fflush(stdin);
    } while (code <= 0);
    return input;
}