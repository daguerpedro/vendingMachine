#ifndef MAQUINA_ESTADOS_H
#define MAQUINA_ESTADOS_H

typedef enum ESTADO
{
    LISTAR,
    SELECIONAR,
    PAGAR,
    CONFIGURAR
} ESTADO;

void iniciarMaquinaEstados();

#endif // !MAQUINA_ESTADOS_H