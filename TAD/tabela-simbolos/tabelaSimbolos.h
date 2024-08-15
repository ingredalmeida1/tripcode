#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

typedef struct {
    char *nome;                      // o nome do id
    char *tipo;                     // se é int, float
    char *categoria;               // se é uma variavel ou uma funcao 
    char *escopo;                 // global ou local
    int linha_declaracao;        // a linha onde foi declarado no codigo-fonte
    char *valor_inicial;        // se tiver tido algum valor atribuido
} Simbolo;

void inicializar_tabela(int capacidade_inicial);

void liberar_tabela();

void adicionar_simbolo(Simbolo novo_simbolo);

void imprimir_tabela_simbolos();

#endif // TABELA_SIMBOLOS_H