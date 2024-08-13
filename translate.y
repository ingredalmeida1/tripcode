%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;

int yylex(void);
void yyerror(const char *s);

%}

%token ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES

%start p

%%

// Regras da gramática

p : 
    trip { yylineno++; printf("1/t"); }
    ;

trip:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES 
    ;

%%

int main(void) {
    printf("Resultado da Analise Lexica:\n");
    yyparse();
    printf("\n");
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}
