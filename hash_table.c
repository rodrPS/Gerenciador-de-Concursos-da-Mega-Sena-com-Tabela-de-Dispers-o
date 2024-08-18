#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "concurso.h"

void inicializar_tabela(HashTable* ht) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        ht->tabela[i] = NULL;
    }
}

int funcao_hash(int numero_concurso) {
    return numero_concurso % TAMANHO_TABELA;
}

void inserir_concurso(HashTable* ht, Concurso* concurso) {
    int indice = funcao_hash(concurso->numero_concurso);
    concurso->proximo = ht->tabela[indice];
    ht->tabela[indice] = concurso;
}

Concurso* buscar_concurso(HashTable* ht, int numero_concurso) {
    int indice = funcao_hash(numero_concurso);
    Concurso* atual = ht->tabela[indice];
    while (atual != NULL) {
        if (atual->numero_concurso == numero_concurso) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void remover_concurso(HashTable* ht, int numero_concurso) {
    int indice = funcao_hash(numero_concurso);
    Concurso* atual = ht->tabela[indice];
    Concurso* anterior = NULL;

    while (atual != NULL && atual->numero_concurso != numero_concurso) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return;

    if (anterior == NULL) {
        ht->tabela[indice] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

void mostrar_concursos(HashTable* ht) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* atual = ht->tabela[i];
        while (atual != NULL) {
            imprimir_concurso(atual);
            atual = atual->proximo;
        }
    }
}
