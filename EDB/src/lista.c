#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

ListaPedidos* criar_lista() {
    ListaPedidos* lista = (ListaPedidos*)malloc(sizeof(ListaPedidos));
    lista->cabeca = NULL;
    lista->prox_id = 1;
    return lista;
}

void adicionar_pedido(ListaPedidos* lista, const char** pratos, int num_pratos) {
    Pedido* novo_pedido = criar_pedido(lista->prox_id++);
    novo_pedido->proximo = lista->cabeca;
    lista->cabeca = novo_pedido;

    for (int i = 0; i < num_pratos; i++) {
        adicionar_prato(novo_pedido, pratos[i]);
    }

    printf("Pedido %d adicionado com sucesso!\n", novo_pedido->id);
}

Pedido* obter_proximo_pedido(ListaPedidos* lista) {
    if (lista->cabeca == NULL) {
        return NULL;
    }
    Pedido* pedido = lista->cabeca;
    lista->cabeca = lista->cabeca->proximo;
    return pedido;
}

void listar_pedidos_pendentes(ListaPedidos* lista) {
    Pedido* atual = lista->cabeca;
    if (atual == NULL) {
        printf("Nenhum pedido pendente.\n");
        return;
    }
    printf("Pedidos Pendentes:\n");
    while (atual != NULL) {
        printf("Pedido %d:\n", atual->id);
        listar_pratos(atual);
        atual = atual->proximo;
    }
}

void liberar_lista(ListaPedidos* lista) {
    Pedido* atual = lista->cabeca;
    while (atual != NULL) {
        Pedido* temp = atual;
        atual = atual->proximo;
        liberar_pedido(temp);
    }
    free(lista);
}
