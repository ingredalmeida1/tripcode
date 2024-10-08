#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

typedef struct {
    int  indice;              //armazenar o indice na tabela de simbolos para otimizar o acesso interno e a manipulação das informações.
    char *descricao;          //se é variavel, constante ou funcao 
    char *tipo;               //armazenar como string e usar strcmp para conferir                 
    char *identificador;  
    char* valor;
    int inicializado;         // 0 se não inicializado, 1 se inicializado  -> conferir se antes de usar a variável já voi armazenado valor nela  
} Simbolo;                    //cada simbolo possui um identificador e um tipo associado 

typedef struct TabelaSimbolos TabelaSimbolos;

struct TabelaSimbolos{
    char *nome_bloco;
    int tamanho;              //facilar a busca dentro da tabela: usar for  
    Simbolo **simbolos; 
    TabelaSimbolos* anterior; //temos que manter a referência para a tabela anterior
};

typedef struct {
    int  indice;              //armazenar a ordem dele?
    char *tipo;               //em vez de armazenar como string podemos armazenar como enum, nao sei facilitaria                   
    char *identificador;      
} Parametro;

typedef struct {
    char *tipo_retorno;
    char *identificador;
    Parametro** parametros;   //lista de parametros da funcao
    int qtd_parametros;       
    TabelaSimbolos* escopo;   //cada funcao tem seu proprio escopo
    int chamada;              //verificar se a função foi chamada pelo menos uma vez
    int definida;             //verificar se a função foi definida
    int retorno;              //verificar se tem pelo menos um retorno
} Funcao; 

// Funcoes Relacionadas à Todas às Tabelas de Símblos:
void adicionar_nova_tabela(TabelaSimbolos ***tabelas_simbolos, TabelaSimbolos *nova_tabela, int *numero_de_tabelas);

void imprimir_todas_tabelas_simbolos(TabelaSimbolos **tabelas_simbolos, int total);

// Funcoes Relacionadas à Tabela de Símblos:
void inicializar_tabela(TabelaSimbolos **tabela_simbolos, TabelaSimbolos *tabela_anterior, char *nome_bloco);

void liberar_tabela(TabelaSimbolos *tabela_simbolos);

int verificar_simbolo_escopo_local(TabelaSimbolos *tabela_simbolos, char *identificador);

int verificar_constante(TabelaSimbolos *tabela_simbolos, char *identificador);

void adicionar_simbolo(TabelaSimbolos **tabela_simbolos, char *descricao, char *tipo, char *nome_identificador, char *valor, int inicializado);

Simbolo* buscar_simbolo(TabelaSimbolos *tabela_atual, char *identificador);

void imprimir_tabela_simbolos(TabelaSimbolos tabela_simbolos);

// Funcoes Relacionadas à Funcoes:
void adicionar_nova_funcao(Funcao ***funcoes, Funcao *nova_funcao, int *numero_de_funcoes);

void imprimir_todas_funcoes(Funcao **funcoes, int total);

void inicializar_funcao(Funcao **funcao, char *identificador);

void adicionar_parametro(Funcao **funcao, char *identificador, char *tipo);

void set_tipo(Funcao **funcao, char *tipo);

void set_chamada(Funcao **funcao);

void set_definida(Funcao **funcao);

Funcao** buscar_funcao(Funcao **funcoes, char* identificador, int total);

void inicializar_tabela_simbolos_funcao(Funcao ***funcao, TabelaSimbolos *anterior);

void imprimir_funcao(Funcao *funcao);

#endif 