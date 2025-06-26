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