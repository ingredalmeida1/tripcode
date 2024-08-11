#include "tabelaSimbolos.h"

void inicializar_tabela(int capacidade_inicial) {
    capacidade_tabela = capacidade_inicial;
    tabela_simbolos = (struct Simbolo *)malloc(capacidade_tabela * sizeof(struct Simbolo));

    if (tabela_simbolos == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tabela de símbolos.\n");
        exit(EXIT_FAILURE);
    }

    printf("\033[0;32m"); 
    printf("Tabela inicializada com sucesso!\n");
    printf("\033[0m");
}

void liberar_tabela() {
    free(tabela_simbolos);
}

void adicionar_simbolo(struct Simbolo novo_simbolo) {
    if (tamanho_tabela >= capacidade_tabela) {
        capacidade_tabela *= 2; 
        tabela_simbolos = (struct Simbolo *)realloc(tabela_simbolos, capacidade_tabela * sizeof(struct Simbolo));

        if (tabela_simbolos == NULL) {
            fprintf(stderr, "Erro ao realocar memória para a tabela de símbolos.\n");
            exit(EXIT_FAILURE);
        }
    }

    tabela_simbolos[tamanho_tabela] = novo_simbolo;
    tamanho_tabela += 1;
}

void imprimir_tabela_simbolos() {
    printf("-----------------------------------------------------------------\n");
    printf("| \033[33m%-15s\033[0m | \033[33m%-10s\033[0m | \033[33m%-10s\033[0m | \033[33m%-10s\033[0m | \033[33m%-5s\033[0m | \033[33m%-10s\033[0m |\n", 
            "Nome", 
            "Tipo", 
            "Categoria", 
            "Escopo", 
            "Linha", 
            "Valor Inicial");
    printf("-----------------------------------------------------------------\n");
    
    for (int i = 0; i < tamanho_tabela; i++) {
        printf("| %-15s | %-10s | %-10s | %-10s | %-5d | %-10s |\n", 
               tabela_simbolos[i].nome, 
               tabela_simbolos[i].tipo, 
               tabela_simbolos[i].categoria, 
               tabela_simbolos[i].escopo, 
               tabela_simbolos[i].linha_declaracao, 
               tabela_simbolos[i].valor_inicial ? tabela_simbolos[i].valor_inicial : "\033[36mNULL\033[0m");
    }
    
    printf("-----------------------------------------------------------------\n");
}