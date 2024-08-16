#include "TabelaSimbolos.h"

// Funcoes Relacionadas à Todas às Tabelas de Símblos:
void adicionar_nova_tabela(TabelaSimbolos ***tabelas_simbolos, TabelaSimbolos *nova_tabela, int *numero_de_tabelas){
    (*tabelas_simbolos)[*numero_de_tabelas] = nova_tabela;
    (*numero_de_tabelas)+= 1;
}

void imprimir_todas_tabelas_simbolos(TabelaSimbolos **tabelas_simbolos, int total) {
    for (int i = 0; i < total; i++) {
        imprimir_tabela_simbolos((*tabelas_simbolos[i]));
    }
}

// Funcoes Relacionadas à Tabela de Símblos:
void inicializar_tabela(TabelaSimbolos **tabela_simbolos, TabelaSimbolos *tabela_anterior, char *nome_bloco) {

    (*tabela_simbolos) = (TabelaSimbolos *)malloc(sizeof(TabelaSimbolos));
    if (*tabela_simbolos == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tabela de símbolos.\n");
        exit(EXIT_FAILURE);
    }
    
    (*tabela_simbolos)->nome_bloco = strdup(nome_bloco); 
    
    (*tabela_simbolos)->tamanho = 0;

    // aloca memória para um array de ponteiros para simbolo:
    (*tabela_simbolos)->simbolos = (Simbolo **)malloc(100 * sizeof(Simbolo*));
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

int verificar_simbolo_existente(TabelaSimbolos *tabela_simbolos, char *identificador) {
    for (int i = 0; i < tabela_simbolos->tamanho; i++) {
        if (strcmp(tabela_simbolos->simbolos[i]->identificador, identificador) == 0) {
            return 1; // símbolo já existe
        }
    }
    return 0; // símbolo ainda não existe
}

int adicionar_simbolo(TabelaSimbolos **tabela_simbolos, char *tipo, char *nome_identificador, char *valor_inicial) {
    // verificar se o símbolo já existe na tabela
    // if (verificar_simbolo_existente(*tabela_simbolos, nome_identificador)) {
    //     // printf("Erro: O símbolo '%s' já existe na tabela.\n", nome_identificador);
    //     return 1;
    // }

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
    return 0;
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

// Funcoes Relacionadas à Funcoes:
void adicionar_nova_funcao(Funcao ***funcoes, Funcao *nova_funcao, int *numero_de_funcoes){
    printf("adicionar funcao %s", nova_funcao->identificador); 
    (*funcoes)[*numero_de_funcoes] = nova_funcao;
    (*numero_de_funcoes)+= 1;
}

void imprimir_todas_funcoes(Funcao **funcoes, int total){
    printf("Funcoes adicionadas: ");
    for (int i = 0; i < total; i++) {
        printf("%s",(*funcoes)[i].identificador);    
    }
    printf("\n");
}

void inicializar_funcao(Funcao **funcao, char *identificador, char *tipo) {
    (*funcao) = (Funcao *)malloc(sizeof(Funcao));
    if (*funcao == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a função.\n");
        exit(EXIT_FAILURE);
    }

    (*funcao)->tipo_retorno = strdup(tipo); 
    
    (*funcao)->identificador = strdup(identificador); 

    (*funcao)->parametros = NULL; // Inicialmente não há parâmetros
    // aloca memória para um array de ponteiros para parametros:
    (*funcao)->parametros = (Parametro **)malloc(10 * sizeof(Parametro*));
    if ((*funcao)->parametros == NULL) {
        fprintf(stderr, "Erro ao alocar memória para os símbolos.\n");

        exit(EXIT_FAILURE);
    }

    (*funcao)->qtd_parametros = 0; 

    (*funcao)->escopo = NULL; //vai iniciar a funcao quando declarar o prototipo, entao ainda nao tem escopo
}

void adicionar_parametro(Funcao **funcao, char *identificador, char *tipo) {

    int indice = (*funcao)->qtd_parametros;

    Parametro *novo_parametro = (Parametro *)malloc(sizeof(Parametro));

    novo_parametro->indice = indice; 
    novo_parametro->tipo = strdup(tipo); 
    novo_parametro->identificador = strdup(identificador); 

    (*funcao)->parametros[indice] = novo_parametro;
    (*funcao)->qtd_parametros += 1; 
}

// depois ajustar pro ponteiro anterior apontar pro bloco de escopo global
void inicializar_tabela_simbolos_funcao(Funcao **funcao) {

    char nome_bloco[200] = "FUNCAO ";
    strcat(nome_bloco, (*funcao)->identificador);

    TabelaSimbolos *tabela_funcao = NULL;
    inicializar_tabela(&tabela_funcao, NULL, nome_bloco) ;

    (*funcao)->escopo = tabela_funcao;
}

