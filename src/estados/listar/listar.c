#include "listar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gerenciadores/propaganda/propaganda.h>
#include <gerenciadores/produtos/produtos.h>

/// @brief Mostra propaganda na tela e devolve ao fim da fila
void mostrarPropaganda()
{
    char *propaganda = pegarPropaganda();
    printf("> %s <\n\n", propaganda);
    devolverPropaganda(propaganda);
}

RESULTADO_ESTADO estadoListar()
{
    mostrarPropaganda();
    listarProdutos();
    printf("\n");
    return PROXIMO;
}