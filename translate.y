%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD/tabela-simbolos/tabelaSimbolos.h"

char* strdup(const char*);
double atof(const char*);
int atoi(const char*);

int yylex();

extern char *yytext; // para acessar o texto reconhecido pelo scanner/lex */
extern int yylineno; // contar as linhas

char error_message[200];   //construir mensagem de erro
void yyerror();            //imprimir erro

%}

%code requires {
     #include "TAD/tabela-simbolos/tabelaSimbolos.h"
}

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

%token INT FLOAT STRING BOOL ID

%type <iValue> INT
%type <real> FLOAT
%type <str>  STRING
%type <str>  BOOL
%type <str> ID

%start p

%%

// Regras da gramática
p:  
    { inicializar_tabela(50);    //inicializar tabela de simbolos global 

      printf("%d\t", yylineno++); //inicializa contagem linhas do arquivo
    } 
    consts variaveis functions_header main functions 
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
    INT {printf("int %d", $1); }
    | FLOAT     
    | STRING {printf("string %s", $1); }
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
    id id_list
    ;

id_list:
    id_list COMMA id
    |
    ;

id : ID { Simbolo identificador;
          printf("identificador %s", $1);
          identificador.nome = strdup($1);  
          printf("identificador %s", identificador.nome);
          adicionar_simbolo(identificador);
         }
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

void yyerror() {
    // printar mensagem de erro na cor vermelha
    fprintf(stderr, "\n\033[1;31mErro de sintaxe próximo à linha %d: %s\033[0m\n\n", yylineno-1, error_message);
     
    printf("\n\n\033[1;31mPrograma sintaticamente incorreto.\033[0m\n\n");

    // encerrar analise prematuramente:
    exit(0);
}

int main(void) {
    yyparse();     
    imprimir_tabela_simbolos();
    return 0;
}