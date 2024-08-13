%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TAD/tabela-simbolos/tabelaSimbolos.h"

extern char *yytext; // a que ja tem no lex
extern int yylineno; // contar as linhas
void yyerror(const char *s); // imprimir erro

%}

%code requires {
     #include "TADs/SymbolTable.h" 
}

// especifica os diferentes tipos de valores que os tokens podem armazenar
%union {
    char *str;
    int iValue;
    float real;
}

// declara os tokens que são retornados pelo Lex e especifica o tipo de valor que eles retornam

%token CAMBIO COTACAO CLASSE ALFANDEGA ISENTO TRIBUTADO CHECKOUT CHECKIN ITINERARIO ROTA
%token POUSAR IMPREVISTO DESCANSAR TRABALHAR ROTEIRO EMBARCAR DESPACHAR DECOLAR ORIGEM
%token DESTINO ESCALA TURISTANDO TURISTAR DURANTE MAPA PASSAPORTE BAGAGEM MILHAS DOLAR
%token VOUCHER TRIP STATUS EXTERIOR FERIAS DIAUTIL FERIADO COMMA DOT_COMMA DOT OPEN_PARENTHESES
%token CLOSE_PARENTHESES OPEN_BRACKET CLOSE_BRACKET OPEN_CODEBLOCK CLOSE_CODEBLOCK ATRIBUICAO

%token <str> OP
%token <str> RELOP
%token <str> LOGICOP

%token <real> FLOAT
%token <str>  STRING
%token <iValue> INTEIRO

%token <id> ID

%start p

%%

// Regras da gramática

p : 
    main { yylineno++; printf("1/t"); }
    ;

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES 
    ;


%%

// caso encontre um erro 
void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s na linha %d\n", s, yylineno);
}