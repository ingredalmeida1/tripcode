%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaração do yylval
extern char *yytext; // var definida pelo Lex
void yyerror(const char *s);

// definição de yylval como uma união de tipos possíveis
%}

// especifica os diferentes tipos de valores que os tokens podem armazenar
%union {
    char *str;
    int ival;
    float fval;
}

// declara os tokens que são retornados pelo Lex e especifica o tipo de valor que eles retornam 
%token <str> OP
