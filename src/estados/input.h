/**
 * @file input.h
 * @author daguer
 * @brief  Define a captura numérica do usuario 
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
/// @brief Captura a entrada numérica do usuario 
/// @param mostrarNav Mostrar [-1 sair | 0 voltar]
int captarEntrada(bool mostrarNav);
/// @brief Limpa tela.
void clear();
/// @brief Pausa tela.
void pause();
#endif