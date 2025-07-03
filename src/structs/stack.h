#include <stdbool.h>
#include <no.h>

/// @brief Stack
typedef struct STACK
{
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