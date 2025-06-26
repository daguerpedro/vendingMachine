#include "listar.h"
#include <stdio.h>
RESULTADO_ESTADO estadoListar()
{
    printf("Você está no estado de listar\n1. VOLTAR\n2. PROXIMO\n3. MENU CONFIG\n4. SAIR\n");

    int r;
    int k = 0;
    do
    {
        k = scanf("%i", &r);
    } while (k <= 0 && r < 4);

    if (r == 1)
        return VOLTAR;
    if (r == 2)
        return PROXIMO;
    if (r == 3)
        return MENU_ADM;
    if (r == 4)
        return SAIR;
}