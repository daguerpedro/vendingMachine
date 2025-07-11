#ifndef _MOEDAS_H
#define _MOEDAS_H

#include <stdio.h>

/// @brief Inicia o gerenciador de moedas.
void iniciarGerenciadorMoedas();
/// @brief Finaliza e limpa as memórias utilizadas pelo gerenciador.
void limparGerenciadorMoedas();

void inserirMoeda(float v);
float recolherMoeda();
void esvaziarMoedas();

#endif