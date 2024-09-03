#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Three-Address Code (TAC)
typedef struct {
    char op[10];
    char arg1[50];
    char arg2[50];
    char result[50];
} TACInstrucao;

void adicionar_instrucao_TAC(const char *op, const char *arg1, const char *arg2, const char *result);

void imprimir_TAC();

char* new_temp();