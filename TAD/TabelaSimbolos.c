#include "TabelaSimbolos.h"

int tamanho_tabela = 0;
int capacidade_tabela = 0;
Simbolo *tabela_simbolos = NULL;

void inicializar_tabela(int capacidade_inicial) {
    capacidade_tabela = capacidade_inicial;
    tabela_simbolos = (Simbolo *)malloc(capacidade_tabela * sizeof(Simbolo));

    if (tabela_simbolos == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tabela de símbolos.\n");
        exit(EXIT_FAILURE);
    }
}

void liberar_tabela() {
    free(tabela_simbolos);
}

void adicionar_simbolo(Simbolo novo_simbolo) {
    if (tamanho_tabela >= capacidade_tabela) {
        capacidade_tabela *= 2; 
        tabela_simbolos = (Simbolo *)realloc(tabela_simbolos, capacidade_tabela * sizeof(Simbolo));

        if (tabela_simbolos == NULL) {
            fprintf(stderr, "Erro ao realocar memória para a tabela de símbolos.\n");
            exit(EXIT_FAILURE);
        }
    }

    tabela_simbolos[tamanho_tabela] = novo_simbolo;
    tamanho_tabela += 1;
}

void imprimir_tabela_simbolos() {
    printf("-------------------------------------------------------------------------------------------\n");
    printf("| \033[1;35m%-88s\033[0m |\n", "        Tabela de Símbolos <nome_bloco>");
    printf("\033[35m-------------------------------------------------------------------------------------------\033[0m \n");
    printf("| %-5s | \033[1;35m%-50s\033[0m | \033[1;35m%-15s\033[0m | \033[1;35m%-8s\033[0m |\n", 
            " ",
            "Identificador", 
            "Tipo",  
            "Valor"); //colocar tipo do retorna da funcao, por enquanto? 
    printf("\033[35m-------------------------------------------------------------------------------------------\033[0m \n");
    
    for (int i = 0; i < tamanho_tabela; i++) {
        printf("| %-5d | %-50s | %-15s | %-8s |\n", 
            i+1,
            tabela_simbolos[i].identificador,
            tabela_simbolos[i].tipo,
            "  -");
    }
    
    printf("-------------------------------------------------------------------------------------------\n");

}