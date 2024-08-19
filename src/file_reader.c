#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/file_reader.h"
#include "headers/concurso.h"
#include "headers/hash_table.h"

void ler_arquivo(HashTable* ht, const char* nome_arquivo) {
    char extensao_arquivo;
    
    if (strstr(nome_arquivo, ".csv")) extensao_arquivo = 'c';
    else if (strstr(nome_arquivo, ".tsv")) extensao_arquivo = 't';
    else {
        printf("Formato de arquivo não suportado. Use .csv ou .tsv.\n");
        return;
    }
    
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), arquivo);

    if (extensao_arquivo == 'c') {
        while (fgets(linha, sizeof(linha), arquivo)) {
            int numero_concurso;
            char data[11];
            int numeros[MAX_NUMEROS];

            sscanf(linha, "%d,%[^,],%d,%d,%d,%d,%d,%d", &numero_concurso, data,
                   &numeros[0], &numeros[1], &numeros[2], &numeros[3], &numeros[4], &numeros[5]);

            Concurso* concurso = criar_concurso(numero_concurso, data, numeros);
            inserir_concurso(ht, concurso);
        }
    } else if (extensao_arquivo == 't') {
        while (fgets(linha, sizeof(linha), arquivo)) {
            int numero_concurso;
            char data[11];
            int numeros[MAX_NUMEROS];

            sscanf(linha, "%d\t%[^,]\t%d\t%d\t%d\t%d\t%d\t%d", &numero_concurso, data,
                   &numeros[0], &numeros[1], &numeros[2], &numeros[3], &numeros[4], &numeros[5]);

            Concurso* concurso = criar_concurso(numero_concurso, data, numeros);
            inserir_concurso(ht, concurso);
        }
    }

    // while (fgets(linha, sizeof(linha), arquivo)) {
    //     int numero_concurso;
    //     char data[11];
    //     int numeros[MAX_NUMEROS];

    //     sscanf(linha, "%d,%[^,],%d,%d,%d,%d,%d,%d", &numero_concurso, data,
    //            &numeros[0], &numeros[1], &numeros[2], &numeros[3], &numeros[4], &numeros[5]);

    //     Concurso* concurso = criar_concurso(numero_concurso, data, numeros);
    //     inserir_concurso(ht, concurso);
    // }

    fclose(arquivo);
}
