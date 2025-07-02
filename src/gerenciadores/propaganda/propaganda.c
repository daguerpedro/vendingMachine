#include "propaganda.h"
#include <structs/queue.h>

QUEUE qPropagandas;

/// @brief Inicia o gerenciador de propagandas, assim como a fila de propagandas.
void iniciarGerenciadorPropaganda()
{
    iniciarQueue(&qPropagandas);
    carregarPropagandas();
}

/// @brief Finaliza e limpa as memórias utilizadas pelo gerenciador.
void limparGerenciadorPropaganda()
{
    limparQueue(&qPropagandas);
}

/// @brief Carrega o arquivo de propagandas.
void carregarPropagandas()
{
    char* propaganda1 = "Propaganda 1!";
    char* propaganda2 = "Essa é a segunda propaganda.";
    char* propaganda3 = "Terceira e ultima ad?";
    
    enQueue(&qPropagandas, (void*)propaganda1);
    enQueue(&qPropagandas, (void*)propaganda2);
    enQueue(&qPropagandas, (void*)propaganda3);    
}

/// @brief Pega a próxima propaganda da fila de propagandas
/// @return Retorna a propaganda.
char* pegarPropaganda()
{
    void* ref = deQueue(&qPropagandas);
    return (char*) ref;
}

/// @brief Devolve uma propaganda para a fila de propagandas.
/// @param propaganda 
void devolverPropaganda(char* propaganda)
{
    enQueue(&qPropagandas, (void*)propaganda);
}