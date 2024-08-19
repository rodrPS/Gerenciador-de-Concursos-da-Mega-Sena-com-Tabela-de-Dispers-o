#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct Prato {
    char nome[50];
    struct Prato* proximo;
} Prato;

typedef struct Pedido {
    int id;
    Prato* pratos;
    struct Pedido* proximo;
} Pedido;

Pedido* criar_pedido(int id);
void adicionar_prato(Pedido* pedido, const char* nome_prato);
void remover_prato(Pedido* pedido, const char* nome_prato);
void listar_pratos(Pedido* pedido);
void liberar_pedido(Pedido* pedido);

#endif
