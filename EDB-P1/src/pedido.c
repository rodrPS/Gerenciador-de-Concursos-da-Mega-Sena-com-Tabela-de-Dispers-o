#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

Pedido* criar_pedido(int id) {
    Pedido* novo_pedido = (Pedido*)malloc(sizeof(Pedido));
    novo_pedido->id = id;
    novo_pedido->pratos = NULL;
    novo_pedido->proximo = NULL;
    return novo_pedido;
}

void adicionar_prato(Pedido* pedido, const char* nome_prato) {
    Prato* novo_prato = (Prato*)malloc(sizeof(Prato));
    strcpy(novo_prato->nome, nome_prato);
    novo_prato->proximo = pedido->pratos;
    pedido->pratos = novo_prato;
}

void remover_prato(Pedido* pedido, const char* nome_prato) {
    Prato* atual = pedido->pratos;
    Prato* anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome_prato) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->proximo = atual->proximo;
        } else {
            pedido->pratos = atual->proximo;
        }
        free(atual);
        printf("Prato '%s' removido do pedido %d.\n", nome_prato, pedido->id);
    } else {
        printf("Prato '%s' não encontrado no pedido %d.\n", nome_prato, pedido->id);
    }
}

void listar_pratos(Pedido* pedido) {
    Prato* prato_atual = pedido->pratos;
    while (prato_atual != NULL) {
        printf("  - %s\n", prato_atual->nome);
        prato_atual = prato_atual->proximo;
    }
}

void liberar_pedido(Pedido* pedido) {
    Prato* prato_atual = pedido->pratos;
    while (prato_atual != NULL) {
        Prato* temp = prato_atual;
        prato_atual = prato_atual->proximo;
        free(temp);
    }
    free(pedido);
}
