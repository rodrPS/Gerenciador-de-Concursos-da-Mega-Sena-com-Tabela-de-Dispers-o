#include <stdio.h>
#include "hash_table.h"
#include "file_manager.h"
#include "stats.h"

void menu(HashTable* ht) {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir Concurso\n");
        printf("2. Buscar Concurso\n");
        printf("3. Remover Concurso\n");
        printf("4. Mostrar Concursos\n");
        printf("5. Calcular Estatísticas\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int numero_concurso, numeros[MAX_NUMEROS];
                char data[11];
                printf("Número do concurso: ");
                scanf("%d", &numero_concurso);
                printf("Data (dd/mm/aaaa): ");
                scanf("%s", data);
                printf("Digite os %d números sorteados: ", MAX_NUMEROS);
                for (int i = 0; i < MAX_NUMEROS; i++) {
                    scanf("%d", &numeros[i]);
                }
                Concurso* concurso = criar_concurso(numero_concurso, data, numeros);
                inserir_concurso(ht, concurso);
                break;
            }
            case 2: {
                int numero_concurso;
                printf("Digite o número do concurso: ");
                scanf("%d", &numero_concurso);
                Concurso* concurso = buscar_concurso(ht, numero_concurso);
                if (concurso) {
                    imprimir_concurso(concurso);
                } else {
                    printf("Concurso não encontrado.\n");
                }
                break;
            }
            case 3: {
                int numero_concurso;
                printf("Digite o número do concurso: ");
                scanf("%d", &numero_concurso);
                remover_concurso(ht, numero_concurso);
                break;
            }
            case 4:
                mostrar_concursos(ht);
                break;
            case 5: {
                int frequencia[61];
                calcular_frequencia(ht, frequencia);
                listar_mais_menos_sorteados(frequencia);
                int ano;
                printf("Digite o ano para contar os concursos: ");
                scanf("%d", &ano);
                int count = contar_concursos_por_ano(ht, ano);
                printf("Número de concursos no ano %d: %d\n", ano, count);
                break;
            }
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
}

int main() {
    HashTable ht;
    inicializar_tabela(&ht);

    // Carregando os dados do arquivo sorteios.csv ao iniciar o programa
    ler_arquivo(&ht, "sorteios.csv");

    menu(&ht);

    return 0;
}
