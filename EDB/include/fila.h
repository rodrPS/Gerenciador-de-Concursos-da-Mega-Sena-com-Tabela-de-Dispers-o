#ifndef FILA_H
#define FILA_H

#include "pedido.h"

typedef struct {
    Pedido* frente;
    Pedido* tras;
} FilaPedidos;

FilaPedidos* criar_fila();
void processar_pedido(FilaPedidos* fila, Pedido* pedido);
void listar_pedidos_em_processamento(FilaPedidos* fila);
void liberar_fila(FilaPedidos* fila);

#endif
