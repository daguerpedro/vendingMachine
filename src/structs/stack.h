#include <stdbool.h>
#include <no.h>

typedef struct STACK
{
    NO *topo;
} STACK;

void iniciarStack(STACK *stack);
void limparStack(STACK *stack);
bool stackVazia(STACK *stack);
void pushStack(STACK *stack, void* valor);
void* popEstado(STACK *stack);