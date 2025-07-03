#ifndef _NO_H
#define _NO_H
/// @brief Nó genérico usado em todas as estruturas
typedef struct NO
{
    struct NO *anterior;
    struct NO *proximo;
    
    void *valor;
} NO;
#endif