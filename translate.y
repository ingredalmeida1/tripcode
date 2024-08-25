/*====================================================================================================
        Analisador Sintático e Semântico para a Linguagem TripCode
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
Funcao* funcao_temp = NULL; //variavel para armazenar ponteiro para a funcao temporaria para comparar com o prototipo

int prototipo = 0;   //flag para saber se os parametros formais sao relacionados ao prototipo de uma funcao
int definicao = 0;

int yylex();

char* strdup(const char*);
double atof(const char*);
int atoi(const char*);

extern int yylineno;          // contar as linhas

char msg_erro[200];           //construir mensagem de erro

void yyerror();               // reportar erros léxicos e sintaticos

void semantic_error();        // reportar erros semâticos

//funcoes auxiliares para analise semantica
int identificador_disponivel(char *identificador);
int comparar_definicao_com_prototipo();

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

      printf("%d\t", yylineno++); //inicializar contagem linhas do arquivo
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
        strcpy(msg_erro,""); //esvazia mensagem de erro
        strcat(msg_erro, "Definição de Constante: ");

        //conferir se já tem algo na tabela global com mesmo nome
        int resultado = identificador_disponivel($2);
        if (resultado){
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro

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
                                                strcpy(msg_erro,""); //esvazia mensagem de erro
                                                strcat(msg_erro, "Definição de Variável: ");
                                                int resultado = identificador_disponivel($3);
                                                if (resultado){
                                                    semantic_error();
                                                }
                                                strcpy(msg_erro,""); //reseta msg de erro
                                               
                                                adicionar_simbolo(&escopo_atual, $2, $3, "-");
                                            }
    ;

dec_variavel:
    BAGAGEM TYPE ID DOT_COMMA {
                                                strcpy(msg_erro,""); //esvazia mensagem de erro
                                                strcat(msg_erro, "Declaração de Variável: ");
                                                int resultado = identificador_disponivel($3);
                                                if (resultado){
                                                    semantic_error();
                                                }
                                                strcpy(msg_erro,""); //reseta msg de erro

                                                adicionar_simbolo(&escopo_atual, $2, $3, "-");
                                            }
    ;


functions_header:
    functions_header function_header 
    |
    ;

function_header:
    ROTEIRO ID OPEN_PARENTHESES 
    {
        strcpy(msg_erro,""); //esvazia mensagem de erro
        strcat(msg_erro, "Protótipo de Funcao: ");

        int resultado = identificador_disponivel($2);
        if (resultado){
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro

        //inicializar estrutura para armazenar informacoes da funcao
        Funcao *nova_funcao = NULL;
        inicializar_funcao(&nova_funcao, $2);
        adicionar_nova_funcao(&funcoes, nova_funcao, &numero_de_funcoes);
        funcao_atual = nova_funcao;

        prototipo = 1; //mudar a flag para verdadeiro para que os parametros sejam adicionados na funcao atual

    }
    params_form function_header_end
    ;

    function_header_end:
    CLOSE_PARENTHESES OPEN_CODEBLOCK TYPE CLOSE_CODEBLOCK 
    {
        set_tipo(&funcao_atual, $3);
        adicionar_simbolo(&escopo_atual, "FUNCAO", funcao_atual->identificador, $3);

        prototipo = 0; //voltar a flag para falso
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
        if (prototipo){
            adicionar_parametro(&funcao_atual, $2, $1);
        }
        if (definicao){
            //se nao for o prototipo tem que conferir se declarou igual está no prototipo = semantica
            adicionar_parametro(&funcao_temp, $2, $1);
        }
    }
    ;

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK 
    {
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
    ROTEIRO ID OPEN_PARENTHESES 
    {
        Funcao **funcao = buscar_funcao(funcoes, $2, numero_de_funcoes); 
        if (funcao == NULL){

            strcpy(msg_erro,"");
            strcat(msg_erro, "Definição de Função: Protótipo da função '"); 
            strcat(msg_erro, $2); 
            strcat(msg_erro, "' não foi declarado\n"); 
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro
        
        definicao = 1; //aproveitar a flag para indicar que vai mudar o escopo atual e assim que fechar o bloco da funcao tem que restaurar para o escopo anterior
    
        inicializar_tabela_simbolos_funcao(&funcao, escopo_atual);
        adicionar_nova_tabela(&tabelas_simbolos, (*funcao)->escopo, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = (*funcao)->escopo;

        funcao_atual = *funcao;
        
        //inicializar estrutura temporar para armazenar informacoes da definicao da funcao
        Funcao *aux = NULL;
        inicializar_funcao(&aux, $2);
        funcao_temp = aux;  
    }
    params_form CLOSE_PARENTHESES OPEN_CODEBLOCK stmt stmts function_end
    ;

function_end:
    CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK
    {
        if (definicao){

            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Definicao de Funcao: ");

            if (funcao_temp==NULL){
                printf("temporario nula");
            }
            if (funcao_atual==NULL){
                printf("atual nula");
            }

            set_tipo(&funcao_temp, $2);

            int resultado = comparar_definicao_com_prototipo();
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
        definicao = 0; 
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
        inicializar_tabela(&nova_tabela, escopo_atual, "TURISTANDO");
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
    EMBARCAR ID OPEN_PARENTHESES
    {
        Funcao **funcao = buscar_funcao(funcoes, $2, numero_de_funcoes); 

        if (funcao == NULL){
            prototipo = 0;

            strcpy(msg_erro,"");
            strcat(msg_erro, "Chamada de Função: Protótipo da função '"); 
            strcat(msg_erro, $2); 
            strcat(msg_erro, "' não foi declarado\n"); 
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro
    } 
    params_real CLOSE_PARENTHESES 

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
     
    // printf("\n\n\033[1;31mPrograma sintaticamente incorreto.\033[0m\n\n");
    printf("\n\n");
    
    //imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas); // até o momento do erro

    // encerrar a análise prematuramente (assim que encontra um erro):
    exit(0);
}

void semantic_error() {
     // imprimir mensagem de erro na cor vermelha
     fprintf(stderr, "\n\033[1;31mErro semântico próximo à linha %d:\033[0m\n\033[31m---> %s\033[0m\n", yylineno-1, msg_erro);
     
     // printf("\n\n\033[1;31mPrograma semanticamente incorreto.\033[0m\n\n");
     printf("\n\n");

     exit(0);
}

int identificador_disponivel(char *identificador){
    //define a mensagem de erro:
    strcat(msg_erro, "O identificador '"); 
    strcat(msg_erro, identificador); 
    
    //percorrer funcoes para vê se identificador já foi usado:
    if (buscar_funcao(funcoes, identificador, numero_de_funcoes) != NULL){
        strcat(msg_erro, "' já está sendo usado para uma função!\n");
        return 1;
    }

    //percorreter tabela de simbolos do bloco local para vê se identificador já foi usado no escopo local:
    //se escopo local nao for o global tem que conferir se já existe constante com mesmo identificador?
    if (verificar_simbolo_escopo_local(escopo_atual, identificador)) {
        strcat(msg_erro, "' já está sendo usado!\n");
        return 1;
    }
    return 0;
}

int comparar_definicao_com_prototipo() {
    if (funcao_atual->qtd_parametros != funcao_temp->qtd_parametros) {
        strcat(msg_erro, "Quantidade de Parâmetros Diferente!\n");
        return 1; 
    }

    for (int i = 0; i < funcao_atual->qtd_parametros; i++) {
        if (strcmp(funcao_atual->parametros[i]->tipo, funcao_temp->parametros[i]->tipo) != 0) {
            char buffer[100]; 
            snprintf(buffer, sizeof(buffer), "Erro no %dº parâmetro: esperado '%s'!\n", 
                     i + 1, 
                     funcao_atual->parametros[i]->tipo);
            strcat(msg_erro, buffer);
            return 1;
        }
    }

    if (strcmp(funcao_atual->tipo_retorno, funcao_temp->tipo_retorno) != 0) {
        strcat(msg_erro, "Tipo de Retorno diferente: esperado ");
        strcat(msg_erro, funcao_atual->tipo_retorno);
        strcat(msg_erro, "!");
        return 1;
    }

    return 0;
}

int main(void) {
    yyparse();     
    
    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas);

    return 0;
}