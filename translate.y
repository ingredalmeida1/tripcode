/*====================================================================================================
        Analisador Sintático para a Linguagem TripCode
====================================================================================================*/
%{
/*----------------------------------------------------------------------------------------------------
        Bibliotecas C, codigos C e Definicoes de Tokens 
----------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "TAD/TabelaSimbolos.h"

TabelaSimbolos** tabelas_simbolos = NULL; //armazenar todas as tabelas de simbolos pra poder imprimir
int numero_de_tabelas = 0;

TabelaSimbolos* escopo_atual = NULL; //variavel para armazenar ponteiro para a tabela de simbolos do bloco atual

Funcao** funcoes = NULL; //armazenar todas as funcoes 
int numero_de_funcoes = 0;

Funcao* funcao_atual = NULL; //variavel para armazenar ponteiro para a funcao que esta sendo avaliada no momento
int prototipos_funcao = 1;   //flag para sabe se os parametros formais sao do momento do prototipo ou nao

int yylex();

char* strdup(const char*);
double atof(const char*);
int atoi(const char*);

extern int yylineno;          // contar as linhas

char msg_erro[200];           //construir mensagem de erro

void yyerror();               // reportar erros

%}

%code requires {
     #include "TAD/TabelaSimbolos.h"
}

/*----------------------------------------------------------------------------------------------------
        Registros Semânticos
----------------------------------------------------------------------------------------------------*/
/* especificar os tipos de valores que os tokens podem armazenar                                    */
%union {
    int inteiro;
    float real;
    char *string;
}
/* avaliar se compensa criar os tipo Tipo, Identificador e Funcao                                  */


/*----------------------------------------------------------------------------------------------------
        Tokens
----------------------------------------------------------------------------------------------------*/
%token TRIP 
%token BAGAGEM EXTERIOR 
%token CHECKIN CHECKOUT
%token ALFANDEGA ISENTO TRIBUTADO
%token POUSAR FERIADO
%token DECOLAR ORIGEM DESTINO ESCALA
%token TURISTANDO 
%token ROTEIRO EMBARCAR DESPACHAR
%token COMMA DOT_COMMA DOT COLON
%token OPEN_PARENTHESES CLOSE_PARENTHESES 
%token OPEN_BRACKET CLOSE_BRACKET
%token OPEN_CODEBLOCK CLOSE_CODEBLOCK
%token ASSIGN CONCAT
%token TYPE
%token INT FLOAT STRING BOOL ID
%token OP RELOP LOGICOP LOGICOP_UNARY

/* especificar o tipo do atributo armazenado no token                                               */
%type <inteiro> INT
%type <real>    FLOAT
%type <string>  STRING
%type <string>  BOOL

%type <string>  TYPE

%type <string>  ID

%type <string> OP
%type <string> RELOP
%type <string> LOGICOP
%type <string> LOGICOP_UNARY

/* definir variavel de partida da gramatica                                                        */
%start tripcode

/*----------------------------------------------------------------------------------------------------
        Associatividade e Precedência dos Operadores
----------------------------------------------------------------------------------------------------*/
%left OP
%left RELOP 
%left LOGICOP
%right LOGICOP_UNARY

/*----------------------------------------------------------------------------------------------------
        Regras da Gramática
----------------------------------------------------------------------------------------------------*/
/* Anotacoes:
 * Tabela de Simbolos Multinivel 
    => para cada bloco de codigo inicia uma nova tabela
        - producoes que contem OPEN_CODEBLOCK ou 'function'
            - para funcoes temos que inserir as variaveis dos parametros na tabela de simbolos
            - os demais blocos nao precisa   

 * ter sepado variaveis globais e constantes ?

 * como sempre tem que definir o prototipo da funcao e a definicao da funcao só vai vim depois do main, 
   quando ler os cabecalhos das funcoes ja vai saber quais funcoes podem ser chamadas dentro do codigo principal e de outras funcoes
   e tambem a quantidade de parametros
   e depois quando definir a funcao, completa com as variaveis declaradas dentro declaradas

 * sempre que definiu um prototipo de funcao tem que conferir se ja nao tem variavel global com o mesmo identificador
 * sempre que definir ou declarar variavel, tem que conferir se ja nao existe funcao ou outra variavel global ou no mesmo bloco com mesmo identificador 
 
*/

%%
tripcode:  
    { //inicializar tabela de simbolos global 
      inicializar_tabela(&escopo_atual, NULL, "GLOBAL");  

      //inicializar lista para armazenar todas as tabelas de simbolos     
      tabelas_simbolos = (TabelaSimbolos**) malloc(100 * sizeof(TabelaSimbolos*));
     
      //adicionar nova tabela na lista de tabelas
      adicionar_nova_tabela(&tabelas_simbolos, escopo_atual, &numero_de_tabelas);

      //já inicializar lista para armazenar funcoes
      funcoes = (Funcao**) malloc(10 * sizeof(Funcao*));   

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
     {
        adicionar_simbolo(&escopo_atual, "CONSTANTE", $2, "-");
     }
    ;

variaveis: 
    variaveis def_variavel
    | variaveis dec_variavel
    |
    ;

def_variavel: 
    BAGAGEM TYPE ID ASSIGN expr DOT_COMMA {
                                               //percorrer a tabela de simbolos do bloco atual, de variaveis globais e de funcoes para verifica se já existe identificador com mesmo nome
                                               //se encontra: erro de sintaxe
                                               //se não encontra: insere na tabela o valor do identificador($3) e seu tipo($2)  [o valor só vai ser armazenado proxima etapa do trabalho]
                                               int resultado = adicionar_simbolo(&escopo_atual, $2, $3, "-");
                                               //if(resultado == 1){
                                               //         strcpy(msg_erro,""); //esvazia mensagem de erro
                                               //         strcat(msg_erro, "O identificador '"); 
                                               //         strcat(msg_erro, $3); 
                                               //         strcat(msg_erro, "' já está sendo usado!\n"); 
                                               //         yyerror();
                                               //}

                                           }
    ;

dec_variavel:
    BAGAGEM TYPE ID DOT_COMMA {
                                               //percorrer a tabela de simbolos do bloco atual, de variaveis globais e de funcoes para verifica se já existe identificador com mesmo nome
                                               //se encontra: erro de sintaxe
                                               //se não encontra: insere na tabela o valor do identificador($1) e seu tipo($2)  [o valor só vai ser armazenado proxima etapa do trabalho]
                                               int resultado = adicionar_simbolo(&escopo_atual, $2, $3, "-");
                                               //if(resultado == 1){
                                               //         strcpy(msg_erro,""); //esvazia mensagem de erro
                                               //         strcat(msg_erro, "O identificador '"); 
                                               //         strcat(msg_erro, $3); 
                                               //         strcat(msg_erro, "' já está sendo usado!\n"); 
                                               //         yyerror();
                                               //}
                                           }
    ;


functions_header:
    functions_header function_header 
    |
    ;

function_header:
    ROTEIRO ID OPEN_PARENTHESES 
    {
        printf("funcao %s", $2);
        //inicializar estrutura para armazenar informacoes da funcao
        Funcao *nova_funcao = NULL;
        inicializar_funcao(&nova_funcao, $2);
        adicionar_nova_funcao(&funcoes, nova_funcao, &numero_de_funcoes);
        funcao_atual = nova_funcao;

    }
    params_form function_header_end
    ;

function_header_end:
    CLOSE_PARENTHESES OPEN_CODEBLOCK TYPE CLOSE_CODEBLOCK 
    {
        set_tipo(&funcao_atual, $3);
        adicionar_simbolo(&escopo_atual, "FUNCAO", funcao_atual->identificador, $3);
    }
    ;


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
    {
        if (prototipos_funcao){
            adicionar_parametro(&funcao_atual, $2, $1);
        }
        //else{
            //se nao for o prototipo tem que conferir se declarou igual está no prototipo = semantica
        // }
        

    }
    ;

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK 
    {
        
        prototipos_funcao = 0; //antes de começar o bloco main, muda a flag de definicao de prototipos para false
     
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "MAIN");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
    stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
    ;

functions:
    functions function 
    |
    ;

function:
    ROTEIRO ID OPEN_PARENTHESES params_form CLOSE_PARENTHESES OPEN_CODEBLOCK 
    {
        printf("comecou");
        Funcao **funcao = buscar_funcao(funcoes, $2, numero_de_funcoes); 

        //conseiderando que sempre vai declarar o prototipo da funcao: apesar de ser semantico, se nao tiver vai dar falha de segmentação
        
        inicializar_tabela_simbolos_funcao(&funcao, escopo_atual);
            
        adicionar_nova_tabela(&tabelas_simbolos, (*funcao)->escopo, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = (*funcao)->escopo;
    }
    stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK
    {
        
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
    ;

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
    DECOLAR OPEN_PARENTHESES ORIGEM term COMMA DESTINO term COMMA ESCALA term CLOSE_PARENTHESES OPEN_CODEBLOCK 
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "DECOLAR");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }

    stmt stmts CLOSE_CODEBLOCK 
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
    ;    

while:
    TURISTANDO OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "WHILE");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
    stmt stmts CLOSE_CODEBLOCK
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }

if: 
    ALFANDEGA OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK 
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "ALFANDEGA");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
    stmt stmts CLOSE_CODEBLOCK
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
    else
    ;

else:
     ISENTO OPEN_CODEBLOCK 
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "ISENTO");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
    stmt stmts CLOSE_CODEBLOCK
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
    
    | TRIBUTADO OPEN_CODEBLOCK 
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "TRIBUTADO");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
    stmt stmts CLOSE_CODEBLOCK
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
     else
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
    ID ASSIGN expr DOT_COMMA
    ;

ids:
    id id_list
    ;

id_list:
    id_list COMMA id
    |
    ;

id : ID 
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
/*----------------------------------------------------------------------------------------------------
        Funcoes em C
----------------------------------------------------------------------------------------------------*/
void yyerror() {
    // imprimir mensagem de erro na cor vermelha
    fprintf(stderr, "\n\033[1;31mErro de sintaxe próximo à linha %d: %s\033[0m\n\n", yylineno-1, msg_erro);
     
    printf("\n\n\033[1;31mPrograma sintaticamente incorreto.\033[0m\n\n");

    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas); // até o momento do erro
    // imprimir_todas_funcoes(funcoes, numero_de_funcoes);

    // encerrar a análise prematuramente (assim que encontra um erro):
    exit(0);
}

int main(void) {
    yyparse();     
    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas);
    // imprimir_todas_funcoes(funcoes, numero_de_funcoes);

    return 0;
}