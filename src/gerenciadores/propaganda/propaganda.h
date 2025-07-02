#ifndef _PROPAGANDA_H
#define _PROPAGANDA_H

#include <stdio.h>

void iniciarGerenciadorPropaganda();
void limparGerenciadorPropaganda();
void carregarPropagandas();

void devolverPropaganda(char* propaganda);
char* pegarPropaganda();

FILE *criarArquivoPropagandasPadrao();

#endif