#include "pagar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saldo = 0;

RESULTADO_ESTADO estadoPagar()
{
    saldo ++;
    printf("Você está no estado de pagar.\nSaldo: $%02i.\n1. VOLTAR\n2. PROXIMO\n3. MENU CONFIG\n4. SAIR\n", saldo);
    int r;
    int k = 0;
    do
    {
        k = scanf("%i", &r);
    } while (k <= 0 && r < 4);

    if(r == 1) 
        return VOLTAR;
    if(r == 2)
        return PROXIMO;
    if(r == 3)
        return MENU_ADM;
    if(r == 4)
        return SAIR;
}