#include "inicial.h"
#include <stdio.h>
#include <stdlib.h>

#include <gerenciadores/admin/admin.h>
#include "input.h"

#include <stdbool.h>

void inicio(RESULTADO_ESTADO* result)
{
    int entrada = captarEntrada(false);
    switch (entrada)
    {
    case 1:
        *result = PROXIMO;
        return;
        break;
    case -1:
        *result = SAIR;
        return;
        break;
    case -9:
        *result = MENU_ADM;
        return;
        break;
    }

    inicio(result);
}

RESULTADO_ESTADO estadoInicial()
{
    RESULTADO_ESTADO res;

    printf("%s\n", machineInfo.greetings);
    inicio(&res);

    return res;
}