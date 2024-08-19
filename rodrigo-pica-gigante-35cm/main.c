#include "src/headers/concurso.h"
#include "src/headers/hash_table.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("\nMenu:\n");
    printf("1. Carregar Concursos\n");
    printf("2. Inserir Concurso\n");
    printf("3. Buscar Concurso\n");
    printf("4. Remover Concurso\n");
    printf("5. Mostrar Concursos\n");
    printf("6. Contar frequência de um número específico\n");
    printf("7. Exibir números mais frequentes\n");
    printf("8. Exibir números menos frequentes\n");
    printf("9. Contar Concursos em determinado ano\n");
    printf("0. Sair\n");
}

int main() {
    HashTable *hash_table = criar_tabela();
    int zerodata = 0;

    if (!hash_table) {
        printf("Erro ao criar tabela hash.\n");
        return 1;
    }

    int choice;
    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char filename[256];
                printf("Digite o caminho/nome do arquivo: ");
                scanf("%s", filename);
                carregar_concursos(hash_table, filename);

                if (zerodata == 0) zerodata == 1;
                break;
            }
            case 2:
                int concurso, numbers[6];
                char date[11];

                printf("Digite o número do concurso: ");
                scanf("%d", &concurso);
                printf("Digite a data (formato: DD-MM-AAAA): ");
                scanf("%s", date);
                printf("Digite os 6 números (separe-os por um espaço): ");
                for (int i = 0; i < 6; i++) {
                    scanf("%d", &numbers[i]);
                }

                inserir_concursos(hash_table, concurso, date, numbers);

                if (zerodata == 0) zerodata == 1;
                break;
            case 3:
                if (zerodata == 0) {
                    printf("Nenhum concurso carregado.\n");
                    break;
                }
                else {
                    int concurso;
                    printf("Digite o número do concurso a buscar: ");
                    scanf("%d", &concurso);

                    Concurso* result = buscar_concursos(hash_table, concurso);
                    if (result) {
                        printf("Concurso: %d, Data: %s, Números: ", result->id, result->date);
                        for (int i = 0; i < 6; i++) {
                            printf("%d ", result->numbers[i]);
                        }
                        printf("\n");
                    } else {
                        printf("Concurso %d não encontrado.\n", concurso);
                    }
                    break;
                }
            case 4:
                if (zerodata == 0) {
                    printf("Nenhum concurso carregado.\n");
                    break;
                }
                else {
                    int concurso;
                    printf("Número do concurso a remover: ");
                    scanf("%d", &concurso);

                    remover_concurso(hash_table, concurso);
                }
                break;
            case 5:
                display_concursos(hash_table);
                break;
            case 6:
                if (zerodata == 0) {
                    printf("Nenhum concurso carregado.\n");
                    break;
                }
                else {
                    int number;

                    printf("Digite o número para contar a frequência: ");
                    scanf("%d", &number);
                    printf("O número %d foi sorteado %d vezes.\n", number, contar_frequencia(hash_table, number));
                    break;
                }
            case 7: {
                if (zerodata == 0) {
                    printf("Nenhum concurso carregado.\n");
                    break;
                }
                else {
                    int n;
                    printf("Digite o número N: ");
                    scanf("%d", &n);
                    mostrar_top_numeros(hash_table, n, 1); // 1 para mais frequentes
                    break;
                }
            }
            case 8: {
                if (zerodata == 0) {
                    printf("Nenhum concurso carregado.\n");
                    break;
                }
                else {
                    int n;
                    printf("Digite o número N: ");
                    scanf("%d", &n);
                    mostrar_top_numeros(hash_table, n, 0); // 0 para menos frequentes
                    break;
                }
            }
            case 9: {
                if (zerodata == 0) {
                    printf("Nenhum concurso carregado.\n");
                    break;
                }
                else {
                    int year;
                    printf("Digite o ano: ");
                    scanf("%d", &year);
                    int count = contar_concursos_ano(hash_table, year);
                    printf("Número de concursos no ano %d: %d\n", year, count);
                    break;
                }
            }
            case 0:
                free_table(hash_table);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
