/**
 * @file resultadoestado.h
 * @author daguer
 * @brief Define o resultado de saída de cada estado para ser processado na máquina de estados.
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _RESULTADO_ESTADO
#define _RESULTADO_ESTADO

/// @brief Indica o resultado de um estado após processamento. Sendo: VOLTAR, MENU_ADM, PROXIMO 
typedef enum RESULTADO_ESTADO
{
    VOLTAR,
    PROXIMO,
    MENU_ADM,
    SAIR,
} RESULTADO_ESTADO;
#endif // !_RESULTADO_ESTADO