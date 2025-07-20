/**
 * @file main.c
 * @author daguer
 * @brief Entry point da máquina de refrigerantes
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include <maquinaestados.h>

#define WINDOWS 

#ifdef WINDOWS
#include <windows.h>
#endif

/// @brief Entry point
/// @return 
int main()
{        
    #ifdef WINDOWS
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    iniciarMaquinaEstados();
} 