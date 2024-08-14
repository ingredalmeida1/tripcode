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
p: {printf("%d\t", yylineno++);} consts variaveis functions_header main functions
    ;

consts: 
    consts const
    |
    ;

const: 
     EXTERIOR ID term 
    ;

variaveis: 
    variaveis def_variavel
    | variaveis dec_variavel
    |
    ;

def_variavel: 
    BAGAGEM TYPE ID ASSIGN expr DOT_COMMA
    ;

dec_variavel:
    BAGAGEM TYPE ID DOT_COMMA 

functions_header:
    functions_header function_header 
    |
    ;

function_header:
    ROTEIRO ID OPEN_PARENTHESES params_form CLOSE_PARENTHESES OPEN_CODEBLOCK TYPE CLOSE_CODEBLOCK 

params_form: 
    param_form list_params_form
    |
    ;

list_params_form:
    list_params_form COMMA param_form
    |
    ;

param_form:
    TYPE ID
    ;

functions:
    functions function 
    |
    ;

function:
    ROTEIRO ID OPEN_PARENTHESES params_form CLOSE_PARENTHESES OPEN_CODEBLOCK expr CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK

expr: 
    expr OP term
    | OPEN_PARENTHESES expr CLOSE_PARENTHESES
    | term
    ;

term: 
    INT        
    | FLOAT    
    | STRING   
    | BOOL     
    | ID       
    ;


main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK
    ;

stmts:
    stmts stmt
    |
    ;

stmt: 
    for
    | while
    | if
    | command
    ;

for:
    DECOLAR OPEN_PARENTHESES ORIGEM term COMMA DESTINO term COMMA ESCALA term CLOSE_PARENTHESES OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK
    ;    

while:
    TURISTANDO OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK

if: 
    ALFANDEGA OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK else
    ;

else:
     ISENTO OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK
    | TRIBUTADO OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK else
    |
    ;

command:
    def_variavel
    | dec_variavel
    | atribuicao
    ;

atribuicao:
    ID ASSIGN expr DOT_COMMA
    ;

%%

int main(void) {
    printf("Resultado da Analise Lexica:\n");
    yyparse();
    // if (yyparse()) {
    //     fprintf(stderr, "Análise falhou.\n");
    // } else {
    //     fprintf(stderr, "Análise concluída com sucesso.\n");
    // }
    printf("\n");
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n------> Line ", s); 
}
