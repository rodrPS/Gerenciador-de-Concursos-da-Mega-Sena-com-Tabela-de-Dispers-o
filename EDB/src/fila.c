#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

FilaPedidos* criar_fila() {
    FilaPedidos* fila = (FilaPedidos*)malloc(sizeof(FilaPedidos));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

void processar_pedido(FilaPedidos* fila, Pedido* pedido) {
    if (fila->frente == NULL) {
        fila->frente = pedido;
        fila->tras = pedido;
    } else {
        fila->tras->proximo = pedido;
        fila->tras = pedido;
    }
    pedido->proximo = NULL;
    printf("Pedido %d em processamento.\n", pedido->id);
}

void listar_pedidos_em_processamento(FilaPedidos* fila) {
    Pedido* atual = fila->frente;
    if (atual == NULL) {
        printf("Nenhum pedido em processamento.\n");
        return;
    }
    printf("Pedidos em Processamento:\n");
    while (atual != NULL) {
        printf("Pedido %d:\n", atual->id);
        listar_pratos(atual);
        atual = atual->proximo;
    }
}

void liberar_fila(FilaPedidos* fila) {
    Pedido* atual = fila->frente;
    while (atual != NULL) {
        Pedido* temp = atual;
        atual = atual->proximo;
        liberar_pedido(temp);
    }
    free(fila);
}
