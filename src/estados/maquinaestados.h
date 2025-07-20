/**
 * @file maquinaestados.h
 * @author daguer
 * @brief Máquina de estados, controla e processa cada estado individualmente.
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef MAQUINA_ESTADOS_H
#define MAQUINA_ESTADOS_H

/// @brief Enumeração de estado.
typedef enum ESTADO
{
    INICIAL,
    SELECIONAR,
    PAGAR,
    CONFIGURAR
} ESTADO;

/// @brief Inicia a máquina de estados | entry point.
void iniciarMaquinaEstados();

#endif // !MAQUINA_ESTADOS_H