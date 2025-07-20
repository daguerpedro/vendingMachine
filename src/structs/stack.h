/**
 * @file stack.h
 * @author daguer
 * @brief Estrutura de dados do tipo stack genérica
 * @version 1.0.0
 * @date 2025-07-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdbool.h>
#include <no.h>

/// @brief Stack genérica
typedef struct STACK
{
    /// @brief Topo da stack
    NO *topo;
} STACK;

/// @brief Inicia uma stack
/// @param stack Referência para stack
void iniciarStack(STACK *stack);
void limparStack(STACK *stack);

/// @brief Verifica se stack está vazia
/// @param stack Ref para stack
/// @return verdadiro se vazia
bool stackVazia(STACK *stack);

/// @brief Adiciona um valor à stack
/// @param stack Ref para stack
/// @param valor Dado genérico
void pushStack(STACK *stack, void* valor);

/// @brief Tira um valor da stack
/// @param stack Ref para stack
/// @return Dado genérico
void* popStack(STACK *stack);