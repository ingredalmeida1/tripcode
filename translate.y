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

p : {
    yylineno++;
    printf("1/t");
    inicializar_tabela(100); }
    consts |
    variaveis |
    decl_structs |
    functions_header |
    main |
    functions
    ;

main:
    ROTEIRO trip (list_params_form) stmts MILHAS consts {} // essas chaves são ação semântica para o main (todas as regras tem esse {}, igual na p)
    ;

consts:
    const consts {}
    | /* ε - palavra vazia */
    ;

const:
    EXTERIOR ID term {}
    ;

decl_structs:
    decl_struct decl_structs {}
    | /* ε - palavra vazia */
    ;

decl_struct:
    PASSAPORTE ID {}
    ;

functions_header:
    function_header functions_header {}
    | /* ε - palavra vazia */
    ;

function_header:
    ROTEIRO ID '(' list_params_form ')' type {}
    ;

functions:
    function functions {}
    | /* ε - palavra vazia */
    ;

function:
    ROTEIRO ID '(' list_params_form ')' stmts type {}
    ;

list_params_form:
    param_form params_form {}
    | /* ε - palavra vazia */
    ;

params_form:
    param_form params_form {}
    | /* ε - palavra vazia */
    ;

param_form:
    type id {}
    ;


%%

// caso encontre um erro 
void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s na linha %d\n", s, yylineno);
}