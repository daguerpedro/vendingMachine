/**
 * @file moedas.h
 * @author daguer
 * @brief Gerencia o saldo do usuário.
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _MOEDAS_H
#define _MOEDAS_H

#include <stdio.h>

/// @brief Inicia o gerenciador de moedas.
void iniciarGerenciadorMoedas();
/// @brief Finaliza e limpa as memórias utilizadas pelo gerenciador.
void limparGerenciadorMoedas();

/// @brief Insere moeda na máquina
/// @param v valor da moeda
void inserirMoeda(float v);

/// @brief Recolhe de volta a última moeda inserida
/// @return Valor da moeda.
float recolherMoeda();

/// @brief Remove todas as moedas inseridas.
void esvaziarMoedas();

#endif