/**
 * @file no.h
 * @author daguer
 * @brief Estrutura nó utilizada em qualquer estrutura de dados genérica.
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _NO_H
#define _NO_H
/// @brief Nó genérico usado em todas as estruturas
typedef struct NO
{
    /// @brief Ref para nó anterior
    struct NO *anterior;
    /// @brief Ref para próximo nó
    struct NO *proximo;
    /// @brief Valor armazenado no nó
    void *valor;
} NO;
#endif