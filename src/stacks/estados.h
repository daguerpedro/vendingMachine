#include <stdbool.h>
//TODO: MOVER ISSO PARA DENTRO DO ARQUIVO DE MAQUINA DE ESTADo
typedef enum ESTADO
{
    LISTAR,
    SELECIONAR,
    PAGAR,
    CONFIGURAR
} ESTADO;

//TODO: FAZER UMA STACK GENERICA DE INTEIROS E CONVERTER O ESTADO COM CAST
typedef struct NO_ESTADO
{
    struct NO_ESTADO *anterior;
    ESTADO estado;
} NO_ESTADO;

typedef struct STACK_ESTADOS
{
    NO_ESTADO *topo;
} STACK_ESTADOS;

void iniciarStackEstados(STACK_ESTADOS *stack);
void limparStackEstados(STACK_ESTADOS *stack);
bool stackEstadoVazia(STACK_ESTADOS *stack);
void pushEstado(STACK_ESTADOS *stack, ESTADO estado);
ESTADO popEstado(STACK_ESTADOS *stack);