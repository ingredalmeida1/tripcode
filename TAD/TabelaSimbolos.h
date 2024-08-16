#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

typedef struct {
    char *tipo;           //em vez de armazenar como string podemos armazenar como enum, nao sei facilitaria                   
    char *identificador;      
    int  indice;          //armazenar o indice na tabela de simbolos para otimizar o acesso interno e a manipulação das informações.   
} Simbolo; //cada simbolo possui um identificador e um tipo associado (o valor que será armazenado será adicionado na próximata etapa)

typedef struct TabelaSimbolos TabelaSimbolos;

struct TabelaSimbolos{
    char *nome;
    int tamanho;              //facilar a busca dentro da tabela: usar for  
    Simbolo **simbolos; 
    TabelaSimbolos* anterior; //temos que manter a referência para a tabela anterior
};

typedef struct {
    char *tipo;               //em vez de armazenar como string podemos armazenar como enum, nao sei facilitaria                   
    char *identificador;      
    int  indice;              //armazenar a ordem dele?
} Parametro;

typedef struct {
    char *tipo_retorno;
    Parametro** parametros;   //lista de parametros da funcao
    int qtd_parametros;       
    TabelaSimbolos* escopo;   //cada funcao tem seu proprio escopo
} Funcao;

void inicializar_tabela(int capacidade_inicial);

void liberar_tabela();

void adicionar_simbolo(Simbolo novo_simbolo);

void imprimir_tabela_simbolos();

#endif // TABELA_SIMBOLOS_H

/*
Se você tem uma string que assume sempre os mesmos valores em diferentes partes do código, 
é uma boa prática usar uma enumeração. 
Enums são úteis para representar um conjunto fixo de valores com nomes significativos, 
em vez de trabalhar diretamente com strings ou números mágicos. Isso torna o código mais legível, 
menos propenso a erros e facilita a manutenção.

typedef enum { 
    INT,
    FLOAT,
    STRING,
    BOOL,
    FUNCAO,
} Tipo;

DiaSemana stringParaEnum(const char *dia) {
    if (strcmp(dia, "DOMINGO") == 0) return DOMINGO;
    if (strcmp(dia, "SEGUNDA") == 0) return SEGUNDA;
    if (strcmp(dia, "TERCA") == 0) return TERCA;
    if (strcmp(dia, "QUARTA") == 0) return QUARTA;
    if (strcmp(dia, "QUINTA") == 0) return QUINTA;
    if (strcmp(dia, "SEXTA") == 0) return SEXTA;
    if (strcmp(dia, "SABADO") == 0) return SABADO;

    // Se a string não corresponder a nenhum valor, retorne um valor padrão
    return -1; // Ou algum valor especial para indicar erro
}

const char* enumParaString(DiaSemana dia) {
    switch (dia) {
        case DOMINGO: return "DOMINGO";
        case SEGUNDA: return "SEGUNDA";
        case TERCA:   return "TERCA";
        case QUARTA:  return "QUARTA";
        case QUINTA:  return "QUINTA";
        case SEXTA:   return "SEXTA";
        case SABADO:  return "SABADO";
        default:      return "DIA INVALIDO";
    }
}
*/