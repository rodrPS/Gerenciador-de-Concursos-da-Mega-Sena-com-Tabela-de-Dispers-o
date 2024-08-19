#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* create_node(int concurso, const char* date, int numbers[6]) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return NULL;

    new_node->concurso = concurso;
    strncpy(new_node->date, date, 11);
    memcpy(new_node->numbers, numbers, 6 * sizeof(int));
    new_node->next = NULL;

    return new_node;
}

unsigned int hash_function(int concurso) {
    return concurso % TABLE_SIZE;
}

HashTable* create_hash_table() {
    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
    if (!hash_table) return NULL;

    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table->table[i] = NULL;
    }

    return hash_table;
}

void insert_concurso(HashTable* hash_table, int concurso, const char* date, int numbers[6]) {
    unsigned int index = hash_function(concurso);

    Node* current = hash_table->table[index];
    while (current) {
        if (current->concurso == concurso) {
            printf("Concurso %d já existe e não pode ser duplicado.\n", concurso);
            return;
        }
        current = current->next;
    }

    int number_check[61] = {0};
    for (int i = 0; i < 6; i++) {
        if (numbers[i] < 1 || numbers[i] > 60) {
            printf("Número inválido %d no concurso %d. Os números devem estar entre 1 e 60.\n", numbers[i], concurso);
            return;
        }
        if (number_check[numbers[i]] == 1) {
            printf("Número repetido %d no concurso %d. Não pode haver números repetidos em um concurso.\n", numbers[i], concurso);
            return;
        }
        number_check[numbers[i]] = 1;
    }

    Node* new_node = create_node(concurso, date, numbers);
    if (!new_node) {
        printf("Falha na alocação de memória para o novo concurso.\n");
        return;
    }

    if (!hash_table->table[index]) {
        hash_table->table[index] = new_node;
    } else {
        current = hash_table->table[index];
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    printf("Concurso %d inserido com sucesso.\n", concurso);
}

Node* search_concurso(HashTable* hash_table, int concurso) {
    unsigned int index = hash_function(concurso);
    Node* current = hash_table->table[index];

    while (current) {
        if (current->concurso == concurso) return current;
        current = current->next;
    }

    return NULL;
}

void remove_concurso(HashTable* hash_table, int concurso) {
    unsigned int index = hash_function(concurso);
    Node* current = hash_table->table[index];
    Node* previous = NULL;

    while (current && current->concurso != concurso) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        printf("Concurso %d não encontrado.\n", concurso);
        return;
    }

    if (!previous) {
        hash_table->table[index] = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Concurso %d removido.\n", concurso);
}

void display_concursos(HashTable* hash_table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table->table[i];
        while (current) {
            printf("Concurso: %d, Data: %s, Números: ", current->concurso, current->date);
            for (int j = 0; j < 6; j++) {
                printf("%d ", current->numbers[j]);
            }
            printf("\n");
            current = current->next;
        }
    }
}

void free_hash_table(HashTable* hash_table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table->table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);
}
