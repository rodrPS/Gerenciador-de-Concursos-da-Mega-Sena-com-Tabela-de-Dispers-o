#include "headers/helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remover_espacos(char* str) {
    char* end;

    while (*str == ' ') str++;
    if (*str == 0) return str;

    end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;

    *(end + 1) = '\0';
    return str;
}
