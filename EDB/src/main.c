#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"
#include "fila.h"
#include "lista.h"
#include "util.h"

int main() {
    ListaPedidos* lista_pedidos = criar_lista();
    FilaPedidos* fila_pedidos = criar_fila();
    int opcao, num_pratos;
    char prato[50];
    char* pratos[10];
    int id_pedido;

    while (1) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantos pratos deseja adicionar ao pedido? ");
                scanf("%d", &num_pratos);
                for (int i = 0; i < num_pratos; i++) {
                    printf("Nome do prato %d: ", i + 1);
                    scanf("%s", prato);
                    pratos[i] = strdup(prato);
                }
                adicionar_pedido(lista_pedidos, (const char**)pratos, num_pratos);
                for (int i = 0; i < num_pratos; i++) {
                    free(pratos[i]);
                }
                break;
            case 2:
                printf("Digite o ID do pedido: ");
                scanf("%d", &id_pedido);
                Pedido* pedido_atual = lista_pedidos->cabeca;
                while (pedido_atual != NULL && pedido_atual->id != id_pedido) {
                    pedido_atual = pedido_atual->proximo;
                }
                if (pedido_atual != NULL) {
                    printf("Nome do prato a remover: ");
                    scanf("%s", prato);
                    remover_prato(pedido_atual, prato);
                } else {
                    printf("Pedido não encontrado.\n");
                }
                break;
            case 3:
                {
                    Pedido* proximo_pedido = obter_proximo_pedido(lista_pedidos);
                    if (proximo_pedido != NULL) {
                        processar_pedido(fila_pedidos, proximo_pedido);
                    } else {
                        printf("Nenhum pedido pendente para processar.\n");
                    }
                }
                break;
            case 4:
                listar_pedidos_pendentes(lista_pedidos);
                break;
            case 5:
                listar_pedidos_em_processamento(fila_pedidos);
                break;
            case 6:
                printf("Saindo...\n");
                liberar_lista(lista_pedidos);
                liberar_fila(fila_pedidos);
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
