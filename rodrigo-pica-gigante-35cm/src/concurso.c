#include "concurso.h"
#include "hash_table.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char determine_delimiter(const char *filename) {
    if (strstr(filename, ".csv") != NULL) return ',';
    if (strstr(filename, ".tsv") != NULL) return '\t';
    return '\0';
}

void load_concursos_from_file(HashTable *hash_table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char line[256];
    char delimiter = determine_delimiter(filename);
    if (delimiter == '\0') {
        printf("Formato de arquivo não suportado. Use .csv ou .tsv.\n");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        int concurso;
        char date[11];
        int numbers[6];

        char *token = strtok(line, &delimiter);
        concurso = token ? atoi(token) : 0;

        token = strtok(NULL, &delimiter);
        strncpy(date, token ? token : "", 10);

        for (int i = 0; i < 6; i++) {
            token = strtok(NULL, &delimiter);
            numbers[i] = token ? atoi(token) : 0;
        }

        if (concurso != 0 && strlen(date) > 0) {
            insert_concurso(hash_table, concurso, date, numbers);
        }
    }

    printf("Concursos carregados de %s.\n", filename);
    fclose(file);
}

int count_number_frequency(HashTable *hash_table, int number) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hash_table->table[i];
        while (current) {
            for (int j = 0; j < 6; j++) {
                if (current->numbers[j] == number) count++;
            }
            current = current->next;
        }
    }
    return count;
}

void display_top_n_numbers(HashTable *hash_table, int n, int most_frequent) {
    int frequency[60] = {0};

    for (int i = 1; i <= 60; i++) {
        frequency[i - 1] = count_number_frequency(hash_table, i);
    }

    for (int i = 0; i < n; i++) {
        int max_index = 0;
        for (int j = 1; j < 60; j++) {
            if ((most_frequent && frequency[j] > frequency[max_index]) ||
                (!most_frequent && frequency[j] < frequency[max_index])) {
                max_index = j;
            }
        }

        printf("%d: %d vezes\n", max_index + 1, frequency[max_index]);
        frequency[max_index] = most_frequent ? -1 : 999999;
    }
}

int count_concursos_in_year(HashTable *hash_table, int year) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hash_table->table[i];
        while (current) {
            int concurso_year;
            sscanf(current->date + 6, "%d", &concurso_year);
            if (concurso_year == year) count++;
            current = current->next;
        }
    }
    return count;
}
