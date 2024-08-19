#include "concurso.h"
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("Menu:\n");
    printf("1. Carregar concursos\n");
    printf("2. Exibir top N números mais frequentes\n");
    printf("3. Exibir top N números menos frequentes\n");
    printf("4. Contar concursos em um ano específico\n");
    printf("5. Mostrar todos os concursos\n");
    printf("6. Sair\n");
}

int main() {
    HashTable *hash_table = create_hash_table();
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
                printf("Digite o nome do arquivo: ");
                scanf("%s", filename);
                load_concursos_from_file(hash_table, filename);
                break;
            }
            case 2: {
                int n;
                printf("Digite o número N: ");
                scanf("%d", &n);
                display_top_n_numbers(hash_table, n, 1); // 1 para mais frequentes
                break;
            }
            case 3: {
                int n;
                printf("Digite o número N: ");
                scanf("%d", &n);
                display_top_n_numbers(hash_table, n, 0); // 0 para menos frequentes
                break;
            }
            case 4: {
                int year;
                printf("Digite o ano: ");
                scanf("%d", &year);
                int count = count_concursos_in_year(hash_table, year);
                printf("Número de concursos no ano %d: %d\n", year, count);
                break;
            }
            case 5:
                display_concursos(hash_table);
                break;
            case 6:
                free_hash_table(hash_table);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
