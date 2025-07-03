#include <stdio.h>
#include <stdlib.h>

#include "settings.h"
#include <maquinaestados.h>

int main()
{
    #ifdef DEBUG
    printf("[DEBUG] Você está na versão de debug, mude isso em settings.h antes de usar em prod.\n");
    #endif
        
    iniciarMaquinaEstados();
}