#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

typedef struct {
    char *identificador;                     
    char *tipo;           //em vez de armazenar como string podemos armazenar como enum, nao sei facilitaria                   
} Simbolo; //cada simbolo possui um identificador e um tipo associado (o valor que será armazenado será adicionado na próximata etapa)

typedef struct TabelaSimbolos TabelaSimbolos;

struct TabelaSimbolos{
    Simbolo **simbolos;
    TabelaSimbolos* prox;
    char nome_bloco[100];
};

void inicializar_tabela(int capacidade_inicial);

void liberar_tabela();

void adicionar_simbolo(Simbolo novo_simbolo);

void imprimir_tabela_simbolos();

#endif // TABELA_SIMBOLOS_H