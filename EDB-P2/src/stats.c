#include <stdio.h>
#include "headers/stats.h"
#include "headers/concurso.h"
#include "headers/hash_table.h"

void calcular_frequencia(HashTable* ht, int frequencia[61]) {
    for (int i = 1; i <= 60; i++) {
        frequencia[i] = 0;
    }

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* atual = ht->tabela[i];
        while (atual != NULL) {
            for (int j = 0; j < MAX_NUMEROS; j++) {
                frequencia[atual->numeros[j]]++;
            }
            atual = atual->proximo;
        }
    }
}

void listar_mais_menos_sorteados(int frequencia[61]) {
    int mais_sorteados[10] = {0}, menos_sorteados[10] = {0};

    // Lógica para identificar os 10 números mais e menos sorteados
    // (Essa parte pode ser desenvolvida conforme a necessidade)

    printf("10 Números Mais Sorteados:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d vezes\n", mais_sorteados[i], frequencia[mais_sorteados[i]]);
    }

    printf("10 Números Menos Sorteados:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d vezes\n", menos_sorteados[i], frequencia[menos_sorteados[i]]);
    }
}

int contar_concursos_por_ano(HashTable* ht, int ano) {
    int count = 0;
    char ano_str[5];
    sprintf(ano_str, "%d", ano);

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* atual = ht->tabela[i];
        while (atual != NULL) {
            if (strstr(atual->data, ano_str) != NULL) {
                count++;
            }
            atual = atual->proximo;
        }
    }

    return count;
}
