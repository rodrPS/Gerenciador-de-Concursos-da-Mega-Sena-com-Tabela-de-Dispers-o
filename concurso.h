#ifndef CONCURSO_H
#define CONCURSO_H

#define MAX_NUMEROS 6

typedef struct Concurso {
    int numero_concurso;
    char data[11]; // formato "dd/mm/aaaa"
    int numeros[MAX_NUMEROS];
    struct Concurso* proximo; // para o encadeamento
} Concurso;

// Funções relacionadas a concursos
Concurso* criar_concurso(int numero_concurso, const char* data, int numeros[MAX_NUMEROS]);
void imprimir_concurso(Concurso* concurso);

#endif // CONCURSO_H
