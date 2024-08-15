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
%token ASSIGN CONCAT
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
    BAGAGEM TYPE ids ASSIGN expr DOT_COMMA
    ;

dec_variavel:
    BAGAGEM TYPE ids DOT_COMMA 

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

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK
    ;

functions:
    functions function 
    |
    ;

function:
    ROTEIRO ID OPEN_PARENTHESES params_form CLOSE_PARENTHESES OPEN_CODEBLOCK stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK

expr: 
    expr operador term
    | OPEN_PARENTHESES expr CLOSE_PARENTHESES
    | term
    | expr LOGICOP_UNARY
    ;

operador:
    OP
    | RELOP
    | LOGICOP
    ;

term: 
    INT        
    | FLOAT    
    | STRING   
    | BOOL     
    | ID     
    | call_function  
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
    | call_function DOT_COMMA
    | return
    | CHECKIN OPEN_PARENTHESES OPEN_BRACKET types CLOSE_BRACKET COMMA ids CLOSE_PARENTHESES DOT_COMMA
    | CHECKOUT OPEN_PARENTHESES result_form CLOSE_PARENTHESES DOT_COMMA
    | POUSAR DOT_COMMA
    | FERIADO DOT_COMMA
    ;

call_function:
    EMBARCAR ID OPEN_PARENTHESES params_real CLOSE_PARENTHESES 

params_real: 
    param_real list_params_real
    | 
    ;

list_params_real:
    list_params_real COMMA param_real
    |
    ;

param_real:
    expr
    ;

return:
    DESPACHAR expr DOT_COMMA
    ;

atribuicao:
    ids ASSIGN expr DOT_COMMA
    ;

ids:
    ID id_list
    ;

id_list:
    id_list COMMA ID
    |
    ;

types:
    TYPE type_list
    ;

type_list:
    type_list COMMA TYPE
    |
    ;

result_form:
    result results

results: 
    results CONCAT result 
    | 
    ;

result:
    STRING
    | param_form
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
