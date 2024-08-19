#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "concurso.h"

#define TAMANHO_TABELA 100

typedef struct {
    Concurso* tabela[TAMANHO_TABELA];
} HashTable;

// Funções relacionadas à tabela de dispersão
void inicializar_tabela(HashTable* ht);
int funcao_hash(int numero_concurso);
void inserir_concurso(HashTable* ht, Concurso* concurso);
Concurso* buscar_concurso(HashTable* ht, int numero_concurso);
void remover_concurso(HashTable* ht, int numero_concurso);
void mostrar_concursos(HashTable* ht);

#endif // HASH_TABLE_H
