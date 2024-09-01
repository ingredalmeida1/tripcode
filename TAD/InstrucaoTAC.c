#include "InstrucaoTAC.h"

#define MAX_INSTRUCOES 100

TACInstrucao lista_instrucoes[MAX_INSTRUCOES];
int num_instrucoes = 0;

void adicionar_instrucao_TAC(const char *op, const char *arg1, const char *arg2, const char *result) {
    if (num_instrucoes < MAX_INSTRUCOES) {
        TACInstrucao instr = {0};
        strcpy(instr.op, op);
        if (arg1) strcpy(instr.arg1, arg1);
        if (arg2) strcpy(instr.arg2, arg2);
        if (result) strcpy(instr.result, result);
        lista_instrucoes[num_instrucoes++] = instr;
    }
}

void imprimir_TAC() {
    printf("\n----------------------- Código de Três Endereços -----------------------\n\n");

    for (int i = 0; i < num_instrucoes; i++) {
        printf("%d: ", i + 1);
        
        printf("%s = %s %s %s\n",
               lista_instrucoes[i].result,
               lista_instrucoes[i].arg1,
               lista_instrucoes[i].op,
               lista_instrucoes[i].arg2);
    }
}