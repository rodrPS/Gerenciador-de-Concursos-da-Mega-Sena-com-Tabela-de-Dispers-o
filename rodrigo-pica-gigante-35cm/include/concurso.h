#ifndef CONCURSO_H
#define CONCURSO_H

#include "hash_table.h"

void load_concursos_from_file(HashTable *hash_table, const char *filename);
int count_number_frequency(HashTable *hash_table, int number);
void display_top_n_numbers(HashTable *hash_table, int n, int most_frequent);
int count_concursos_in_year(HashTable *hash_table, int year);

#endif // CONCURSO_H
