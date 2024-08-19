#ifndef LISTA_H
#define LISTA_H

#include "pedido.h"

typedef struct {
    Pedido* cabeca;
    int prox_id;
} ListaPedidos;

ListaPedidos* criar_lista();
void adicionar_pedido(ListaPedidos* lista, const char** pratos, int num_pratos);
Pedido* obter_proximo_pedido(ListaPedidos* lista);
void listar_pedidos_pendentes(ListaPedidos* lista);
void liberar_lista(ListaPedidos* lista);

#endif
