#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 1000

typedef struct Concurso {
    int id;
    char date[11];
    int numbers[6];
    struct Concurso* next;
} Concurso;

typedef struct HashTable {
    Concurso* table[TABLE_SIZE];
} HashTable;

Concurso* create_node(int concurso, const char* date, int numbers[6]);
unsigned int hash_function(int concurso);
HashTable* criar_tabela();
void inserir_concursos(HashTable* hash_table, int concurso, const char* date, int numbers[6]);
Concurso* buscar_concursos(HashTable* hash_table, int concurso);
void remover_concurso(HashTable* hash_table, int concurso);
void display_concursos(HashTable* hash_table);
void free_table(HashTable* hash_table);

#endif // HASH_TABLE_H
