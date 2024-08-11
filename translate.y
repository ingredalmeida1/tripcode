%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *yytext; // var definida pelo Lex
void yyerror(const char *s);

%}

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

%token <str> ID