#include <stdio.h>
#include "src/headers/hash_table.h"
#include "src/headers/file_reader.h"
#include "src/headers/stats.h"

void menu(HashTable* ht) {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Carregar Dados de Concursos\n");
        printf("2. Inserir Concurso\n");
        printf("3. Buscar Concurso\n");
        printf("4. Remover Concurso\n");
        printf("5. Mostrar Concursos\n");
        printf("6. Calcular Estatísticas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char nome_arquivo[256];
                printf("Digite o nome do arquivo: ");
                scanf("%s", nome_arquivo);
                ler_arquivo(ht, nome_arquivo);
                break;
            }
            case 2: {
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
            case 3: {
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
            case 4: {
                int numero_concurso;
                printf("Digite o número do concurso: ");
                scanf("%d", &numero_concurso);
                remover_concurso(ht, numero_concurso);
                break;
            }
            case 5:
                mostrar_concursos(ht);
                break;
            case 6: {
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
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    HashTable ht;
    inicializar_tabela(&ht);

    // Carregando os dados do arquivo sorteios.csv ao iniciar o programa
    // ler_arquivo(&ht, "sorteios_teste.csv");

    menu(&ht);

    return 0;
}
