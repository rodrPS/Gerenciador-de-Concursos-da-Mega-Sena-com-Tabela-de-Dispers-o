#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/concurso.h"

Concurso* criar_concurso(int numero_concurso, const char* data, int numeros[MAX_NUMEROS]) {
    Concurso* novo_concurso = (Concurso*)malloc(sizeof(Concurso));
    novo_concurso->numero_concurso = numero_concurso;
    strcpy(novo_concurso->data, data);
    for (int i = 0; i < MAX_NUMEROS; i++) {
        novo_concurso->numeros[i] = numeros[i];
    }
    novo_concurso->proximo = NULL;
    return novo_concurso;
}

void imprimir_concurso(Concurso* concurso) {
    if (concurso != NULL) {
        printf("Concurso %d - Data: %s - Numeros: ", concurso->numero_concurso, concurso->data);
        for (int i = 0; i < MAX_NUMEROS; i++) {
            printf("%d ", concurso->numeros[i]);
        }
        printf("\n");
    }
}
