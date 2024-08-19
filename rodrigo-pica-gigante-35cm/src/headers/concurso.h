#ifndef CONCURSO_H
#define CONCURSO_H

#include "hash_table.h"

void carregar_concursos(HashTable *hash_table, const char *filename);
int contar_frequencia(HashTable *hash_table, int number);
void mostrar_top_numeros(HashTable *hash_table, int n, int most_frequent);
int contar_concursos_ano(HashTable *hash_table, int year);

#endif // CONCURSO_H
