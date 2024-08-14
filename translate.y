%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);

extern char *yytext; // para acessar o texto reconhecido pelo scanner/lex */
extern int yylineno; // contar as linhas

void yyerror(const char *s); //imprimir erro

%}

// especifica os diferentes tipos de valores que os tokens podem armazenar
%union {
    char *str;
    int iValue;
    float real;
}

// declara os tokens que são retornados pelo Lex e especifica o tipo de valor que eles retornam

%token TRIP 
%token BAGAGEM EXTERIOR 
%token CHECKIN CHECKOUT
%token ALFANDEGA ISENTO TRIBUTADO
%token ITINERARIO ROTA IMPREVISTO
%token POUSAR FERIADO
%token DECOLAR ORIGEM DESTINO ESCALA
%token TURISTANDO TURISTAR DURANTE
%token ROTEIRO EMBARCAR DESPACHAR
%token COMMA DOT_COMMA DOT COLON
%token OPEN_PARENTHESES CLOSE_PARENTHESES 
%token OPEN_BRACKET CLOSE_BRACKET
%token OPEN_CODEBLOCK CLOSE_CODEBLOCK
%token ASSIGN
%token TYPE

%token <str> OP
%token <str> RELOP
%token <str> LOGICOP
%token <str> LOGICOP_UNARY

%token <iValue> INT
%token <real> FLOAT
%token <str>  STRING
%token <str>  BOOL
%token <str> ID

%start p

%%

// Regras da gramática
p: {printf("%d\t", yylineno++);} consts variaveis main 
    ;

consts: 
    consts const
    |
    ;

const: 
     EXTERIOR ID {printf("EXTERIOR valor_ID ");} term 
    ;

variaveis: 
    variaveis def_variavel
    | variaveis dec_variavel
    |
    ;

def_variavel: 
    BAGAGEM TYPE ID ASSIGN {printf("BAGAGEM valor_TYPE valor_ID <-> ");} term
    ;

dec_variavel:
    BAGAGEM TYPE ID DOT_COMMA

term: 
    INT        {printf("valor_INT");}
    | FLOAT    {printf("valor_FLOAT");}
    | STRING   {printf("valor_STRING");}
    | BOOL     {printf("valor_BOOL");}
    | ID       {printf("valor_ID");}
    ;

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES {printf("ROTEIRO trip() ");} open bloco close TYPE CLOSE_CODEBLOCK {printf(" valor_TYPE <<<");}
    ;

open: OPEN_CODEBLOCK {printf(">>> ");}

close: CLOSE_CODEBLOCK {printf(" <<<");}

bloco: ID {printf("%s", "valor_ID");}
    ;

%%

int main(void) {
    printf("Resultado da Analise Lexica:\n");
    yyparse();
    printf("\n");
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s  na linha:", s); 
}
