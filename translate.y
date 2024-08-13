%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);

extern int yylineno;
extern char *yytext; /* Para acessar o texto reconhecido pelo scanner */

void yyerror(const char *s);

%}

%token ROTEIRO TRIP MILHAS 
%token OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK CLOSE_CODEBLOCK

%token ID

%start p

%%

// Regras da gramática
p: {printf("%d\t", yylineno++);} main 
    ;

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES {printf("ROTEIRO trip()");} open bloco close MILHAS CLOSE_CODEBLOCK {printf("MILHAS <<<");}
    ;

open: OPEN_CODEBLOCK {printf(">>>");}

close: CLOSE_CODEBLOCK {printf("<<<");}

bloco: ID {printf("valor_id");}
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
