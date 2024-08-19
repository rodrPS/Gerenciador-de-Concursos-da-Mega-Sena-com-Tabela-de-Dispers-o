#ifndef STATS_H
#define STATS_H

#include "hash_table.h"

// Funções de cálculo de estatísticas
void calcular_frequencia(HashTable* ht, int frequencia[61]);
void listar_mais_menos_sorteados(int frequencia[61]);
int contar_concursos_por_ano(HashTable* ht, int ano);

#endif // STATS_H
