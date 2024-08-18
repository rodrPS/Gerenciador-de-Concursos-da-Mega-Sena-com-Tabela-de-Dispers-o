#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_manager.h"
#include "concurso.h"
#include "hash_table.h"

void ler_arquivo(HashTable* ht, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), arquivo);  // Ignorar o cabeçalho

    while (fgets(linha, sizeof(linha), arquivo)) {
        int numero_concurso;
        char data[11];
        int numeros[MAX_NUMEROS];

        sscanf(linha, "%d,%[^,],%d,%d,%d,%d,%d,%d", &numero_concurso, data,
               &numeros[0], &numeros[1], &numeros[2], &numeros[3], &numeros[4], &numeros[5]);

        Concurso* concurso = criar_concurso(numero_concurso, data, numeros);
        inserir_concurso(ht, concurso);
    }

    fclose(arquivo);
}
