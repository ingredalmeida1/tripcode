#include "TabelaSimbolos.h"

#define TAM_MAX 100

void inicializar_tabela(TabelaSimbolos **tabela_simbolos, TabelaSimbolos *tabela_anterior, char *nome_bloco) {

    (*tabela_simbolos) = (TabelaSimbolos *)malloc(sizeof(TabelaSimbolos));
    if (*tabela_simbolos == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tabela de símbolos.\n");
        exit(EXIT_FAILURE);
    }
    
    (*tabela_simbolos)->nome_bloco = strdup(nome_bloco); 
    
    (*tabela_simbolos)->tamanho = 0;

    // aloca memória para um array de ponteiros para simbolo:
    (*tabela_simbolos)->simbolos = (Simbolo **)malloc(TAM_MAX * sizeof(Simbolo*));
    if ((*tabela_simbolos)->simbolos == NULL) {
        fprintf(stderr, "Erro ao alocar memória para os símbolos.\n");
        free((*tabela_simbolos)->nome_bloco); 
        free(*tabela_simbolos);
        exit(EXIT_FAILURE);
    }

    (*tabela_simbolos)->anterior = tabela_anterior;
}

void liberar_tabela(TabelaSimbolos *tabela_simbolos) {
    free(tabela_simbolos);
}

void adicionar_simbolo(TabelaSimbolos **tabela_simbolos, char *tipo, char *nome_identificador, char *valor_inicial) {

    int indice = (*tabela_simbolos)->tamanho;

    Simbolo *novo_simbolo = (Simbolo *)malloc(sizeof(Simbolo));
    novo_simbolo->indice = indice; 
    novo_simbolo->tipo = strdup(tipo); 
    novo_simbolo->identificador = strdup(nome_identificador);
    novo_simbolo->valor = strdup(valor_inicial); 

    (*tabela_simbolos)->simbolos[indice] = novo_simbolo;

    // incrementar o tamanho da tabela para refletir o novo símbolo adicionado
    (*tabela_simbolos)->tamanho += 1;

    // printf("Símbolo '%s' adicionado na posição %d da tabela '%s'.\n", nome_identificador, indice, (*tabela_simbolos)->nome_bloco);
}

void imprimir_tabela_simbolos(TabelaSimbolos tabela_simbolos) {

    char titulo[200] = "         TABELA DE SIMBOLOS ";
    strcat(titulo, tabela_simbolos.nome_bloco);
    
    printf("-------------------------------------------------------------------------------------------\n");
    printf("| \033[1;35m%-87s\033[0m |\n", titulo);
    printf("\033[35m-------------------------------------------------------------------------------------------\033[0m \n");
    printf("| \033[1;35m%-6s\033[0m | \033[1;35m%-50s\033[0m | \033[1;35m%-15s\033[0m | \033[1;35m%-7s\033[0m |\n", 
            "indice",
            "identificador", 
            "tipo",  
            "valor"); //colocar tipo do retorna da funcao, por enquanto? 
    printf("\033[35m-------------------------------------------------------------------------------------------\033[0m \n");
    
    for (int i = 0; i < tabela_simbolos.tamanho; i++) {
        printf("| %-6d | %-50s | %-15s | %-7s |\n", 
            tabela_simbolos.simbolos[i]->indice,
            tabela_simbolos.simbolos[i]->identificador,
            tabela_simbolos.simbolos[i]->tipo,
            tabela_simbolos.simbolos[i]->valor);
    }
    
    printf("-------------------------------------------------------------------------------------------\n");
}