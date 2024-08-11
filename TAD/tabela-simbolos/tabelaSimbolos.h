#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Simbolo {
    char *nome;                      // o nome do id
    char *tipo;                     // se é int, float
    char *categoria;               // se é uma variavel ou uma funcao 
    char *escopo;                 // global ou local
    int linha_declaracao;        // a linha onde foi declarado no codigo-fonte
    char *valor_inicial;        // se tiver tido algum valor atribuido
};

struct Simbolo *tabela_simbolos = NULL;

int tamanho_tabela = 0;
int capacidade_tabela = 0;

void inicializar_tabela(int capacidade_inicial);

void liberar_tabela();

void adicionar_simbolo(struct Simbolo novo_simbolo);

void imprimir_tabela_simbolos();