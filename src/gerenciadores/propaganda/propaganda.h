#ifndef _PROPAGANDA_H
#define _PROPAGANDA_H

#include <stdio.h>

/// @brief Inicia o gerenciador de propagandas, assim como a fila de propagandas.
void iniciarGerenciadorPropaganda();
/// @brief Finaliza e limpa as memórias utilizadas pelo gerenciador.
void limparGerenciadorPropaganda();
/// @brief Carrega o arquivo de propagandas.
void carregarPropagandas();
/// @brief Devolve uma propaganda para a fila de propagandas.
/// @param propaganda
void devolverPropaganda(char* propaganda);
/// @brief Pega a próxima propaganda da fila de propagandas
/// @return Retorna a propaganda.
char* pegarPropaganda();

FILE *criarArquivoPropagandasPadrao();

/// @brief Mostra propaganda na tela e devolve ao fim da fila
void mostrarPropaganda();

#endif