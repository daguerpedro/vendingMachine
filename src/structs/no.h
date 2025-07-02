#ifndef _NO_H
#define _NO_H
/// @brief Nó genérico 
typedef struct NO
{
    struct NO *anterior;
    struct NO *proximo;
    
    void *valor;
} NO;
#endif