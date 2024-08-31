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

int qtd_parametros_reais = 0;
char* tipos_parametros_reais[10]; 

int prototipo = 0;   //flag para saber se os parametros formais sao relacionados ao prototipo de uma funcao
int definicao = 0;   //flag para saber se os parametros formais sao relacionados ao prototipo de uma funcao
int checkout = 0;    //flag para saber se os parametros formais sao relacionados a chamada da funcao chekcout

int qtd_tipos_checkin = 0;
char* tipos_checkin[10]; 
int qtd_ids_checkin = 0;
char* ids_checkin[10]; 

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
void verificar_definicao_funcoes_chamadas();

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
%token ALFANDEGA ISENTO
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
%token INT FLOAT STRING BOOL ID ID_CONST
%token OP RELOP LOGICOP LOGICOP_UNARY

/* especificar o tipo do atributo armazenado no token                                               */
%type <inteiro> INT
%type <real>    FLOAT
%type <string>  STRING
%type <string>  BOOL

%type <string>  TYPE

%type <string>  ID
%type <string>  ID_CONST

%type <string> OP
%type <string> RELOP
%type <string> LOGICOP
%type <string> LOGICOP_UNARY

/* especificar o tipo de variaveis da gramatica                                               */
%type <string> expr
%type <string> term
%type <string> call_function
%type <string> return
%type <string> const

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
    {   //inicializar tabela de simbolos global 
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
    {
        verificar_definicao_funcoes_chamadas();
    }
    ;

consts: 
    consts const
    |
    ;

const: 
    EXTERIOR ID_CONST term 
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Definição de Constante: ");

            //conferir se já tem algo na tabela global com mesmo nome
            int resultado = identificador_disponivel($2);
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            adicionar_simbolo(&escopo_atual, $3, $2, "CONSTANTE", 1);
        }
    ;

variaveis: 
    variaveis  dec_variavel 
    | variaveis def_variavel
    |
    ;

dec_variavel:
    BAGAGEM TYPE ID DOT_COMMA 
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Declaração de Variável: ");
            int resultado = identificador_disponivel($3);
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            adicionar_simbolo(&escopo_atual, $2, $3, "-",0);
        }
    ;

def_variavel: 
    BAGAGEM TYPE ID ASSIGN expr DOT_COMMA   
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Definição de Variável: ");
            int resultado = identificador_disponivel($3);
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            if ((strcmp($2, $5) != 0)){
                strcat(msg_erro, "Definição de Variável: ");
                strcat(msg_erro, "O tipo do valor atribuido à variável '");
                strcat(msg_erro, $3);
                strcat(msg_erro, "' é incompatível com tipo esperado! ('");
                strcat(msg_erro, $2);
                strcat(msg_erro, "' <-> '");
                strcat(msg_erro, $5);
                strcat(msg_erro, "' => X)\n");
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro
            
            adicionar_simbolo(&escopo_atual, $2, $3, "-",1);
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
        adicionar_simbolo(&escopo_atual, $3, funcao_atual->identificador, "FUNCAO",3);

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
            if (checkout){
                        
                Simbolo *simbolo = buscar_simbolo(escopo_atual,  $2);
                if (simbolo == NULL){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Chamada comando CHECKOUT: A variável '"); 
                    strcat(msg_erro, $2); 
                    strcat(msg_erro, "' não foi previamente declarada!'\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");

                if (strcmp(simbolo->tipo, $1) != 0){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Chamada comando CHECKOUT:  A variável'");
                    strcat(msg_erro, $2);  
                    strcat(msg_erro, "' é uma variavel do tipo '"); 
                    strcat(msg_erro, simbolo->tipo); 
                    strcat(msg_erro, "' e não do tipo '"); 
                    strcat(msg_erro, $1); 
                    strcat(msg_erro, "'\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");

                //pra poder usar uma variável ela precisar ter sido inicializada
                if (simbolo->inicializado == 0){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "A variável '"); 
                    strcat(msg_erro, $2); 
                    strcat(msg_erro, "' não foi previamente definida/inicializada!'\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");
            }
        }
    ;

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK  
        {
            Funcao *nova_funcao = NULL;
            inicializar_funcao(&nova_funcao, "TRIP"); //pra poder verificar se tem pelo menos um retorno e se o tipo é MILHAS
            funcao_atual = nova_funcao;
            set_tipo(&funcao_atual, "MILHAS");

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

            if (funcao_atual->retorno == 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Programa Principal 'TRIP': Está faltando retorno do tipo MILHAS\n"); 
                semantic_error();
            }
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

            //mudar flag que indica que funcao foi definida
            set_definida(&funcao_atual);

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

                set_tipo(&funcao_temp, $2);

                int resultado = comparar_definicao_com_prototipo();
                if (resultado){
                    semantic_error();
                }
                strcpy(msg_erro,""); //reseta msg de erro

                if (funcao_atual->retorno == 0){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Definicao de Funcao '");
                    strcat(msg_erro, funcao_atual->identificador);
                    strcat(msg_erro, "': Faltando retorno do tipo '");
                    strcat(msg_erro, funcao_atual->tipo_retorno);
                    strcat(msg_erro, "'\n");
                    semantic_error();
                }

                // restaura o escopo anterior como o escopo atual
                escopo_atual = escopo_atual->anterior;
            }
            definicao = 0; 
        }
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
            if (strcmp($4, "MILHAS") != 0 || strcmp($7, "MILHAS") != 0 || strcmp($10, "MILHAS") != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Bloco de Repeticao DECOLAR: todos termos devem ser do tipo 'MILHAS'\n");
                semantic_error();
            }
            strcpy(msg_erro,"");
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "DECOLAR");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            //ADICIONAR ORIGEM COMO UMA VARIAVEL NA TABELA? teria que mudar a gramática

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
            if (strcmp($3, "BOOL") != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Bloco de Repeticao TURISTANDO: a condicao deve ser do tipo 'BOOL' e nao do tipo '");
                strcat(msg_erro, $3); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

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
            if (strcmp($3, "BOOL") != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Bloco Condicional ALFANDEGA: a condicao deve ser do tipo 'BOOL' e nao do tipo '");
                strcat(msg_erro, $3); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

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
    | CHECKIN OPEN_PARENTHESES OPEN_BRACKET 
        {qtd_tipos_checkin = 0;} 
        types CLOSE_BRACKET COMMA 
        { qtd_ids_checkin=0; } 
        ids 
            {
                if (qtd_tipos_checkin != qtd_ids_checkin){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Chamada comando CHECKIN: Quantidade de Tipos != Quantidade de Variáveis!\n"); 
                    semantic_error();
                }
                for (int i=0; i<qtd_ids_checkin; i++){
                    Simbolo *simbolo = buscar_simbolo(escopo_atual,  ids_checkin[i]);
                    if (simbolo == NULL){
                        strcpy(msg_erro,"");
                        strcat(msg_erro, "Chamada comando CHECKIN: A variável '"); 
                        strcat(msg_erro, ids_checkin[i]); 
                        strcat(msg_erro, "' não foi previamente declarada!'\n"); 
                        semantic_error();
                    }
                    strcpy(msg_erro,"");

                    if (strcmp(simbolo->tipo, tipos_checkin[i]) != 0){
                        strcpy(msg_erro,"");
                        strcat(msg_erro, "Chamada comando CHECKOUT:  A variável'");
                        strcat(msg_erro, ids_checkin[i]);  
                        strcat(msg_erro, "' é uma variavel do tipo '"); 
                        strcat(msg_erro, simbolo->tipo); 
                        strcat(msg_erro, "' e não do tipo '"); 
                        strcat(msg_erro, tipos_checkin[i]); 
                        strcat(msg_erro, "'\n"); 
                        semantic_error();
                    }
                    strcpy(msg_erro,"");

                    //pra poder usar uma variável ela precisar ter sido inicializada
                    if (simbolo->inicializado == 0){
                        strcpy(msg_erro,"");
                        strcat(msg_erro, "A variável '"); 
                        strcat(msg_erro, ids_checkin[i]); 
                        strcat(msg_erro, "' não foi previamente definida/inicializada!'\n"); 
                        semantic_error();
                    }
                    strcpy(msg_erro,"");
                }
            }
        CLOSE_PARENTHESES DOT_COMMA
    | CHECKOUT OPEN_PARENTHESES {checkout = 1;} result_form {checkout = 0;} CLOSE_PARENTHESES DOT_COMMA 
    | POUSAR DOT_COMMA
    | FERIADO DOT_COMMA
    ;

call_function:
    EMBARCAR ID OPEN_PARENTHESES
        {
            qtd_parametros_reais = 0; //sempre reiniciando o contador vai sobreescrevendo
        }
    params_real CLOSE_PARENTHESES 
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

            // Verifica a quantidade de parâmetros
            if (qtd_parametros_reais != (*funcao)->qtd_parametros) {
                strcpy(msg_erro, "Chamada de Função: Número incorreto de parâmetros na função '");
                strcat(msg_erro, $2); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }

            //tipos dos parâmetros
            for (int i = 0; i < qtd_parametros_reais; i++) {
                if (strcmp(tipos_parametros_reais[i], (*funcao)->parametros[i]->tipo) != 0) {
                    strcpy(msg_erro, "Chamada de Função: Tipos de parâmetros incompatíveis na função '");
                    strcat(msg_erro, $2); 
                    strcat(msg_erro, "'\n"); 
                    semantic_error();
                }
            }

            (*funcao)->chamada = 1;

            $$ = (*funcao)->tipo_retorno;
        } 
    ;

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
        {
            tipos_parametros_reais[qtd_parametros_reais] = $1;
            qtd_parametros_reais += 1;
        }
    ;

return:
    DESPACHAR expr DOT_COMMA 
        {
            if((strcmp($2, funcao_atual->tipo_retorno) != 0)){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Retorno função '");
                strcat(msg_erro, funcao_atual->identificador);
                strcat(msg_erro, "': Tipo Incompatível, esperado: '");
                strcat(msg_erro, funcao_atual->tipo_retorno);
                strcat(msg_erro, "'\n");
                semantic_error();
            }

            funcao_atual->retorno = 1;
        }
    ;

atribuicao:
    ID ASSIGN expr DOT_COMMA 
        { 
            Simbolo *simbolo = buscar_simbolo(escopo_atual,  $1);
            if (simbolo == NULL){
                strcpy(msg_erro,"");
                strcat(msg_erro, "A variável '"); 
                strcat(msg_erro, $1); 
                strcat(msg_erro, "' não foi previamente declarada!'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            if (strcmp(simbolo->valor, "CONSTANTE") == 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Atribuição: Não é possível fazer reatribuição de CONSTANTE\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            if (strcmp(simbolo->tipo, $3) != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Atribuição: Não é possível atribuir um valor do tipo '");
                strcat(msg_erro, $3);  
                strcat(msg_erro, "' a uma variavel do tipo '"); 
                strcat(msg_erro, simbolo->tipo); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            //se foi possível fazer atribuição foi armazenado um valor na variável então ela foi inicializada
            simbolo->inicializado = 1;
        }
    |
    ID_CONST ASSIGN expr DOT_COMMA 
        { 
                strcpy(msg_erro,"");
                strcat(msg_erro, "Atribuição: Não é possível fazer reatribuição de CONSTANTE\n"); 
                semantic_error();
        }
    ;

expr: 
    expr OP term   
        { 
            if ( (strcmp($1, "VOUCHER") == 0) || (strcmp($3, "VOUCHER") == 0) ){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Aritimética: Ainda não está disponível manipular variáveis do tipo VOUCHER com operações aritméticas =(");
                semantic_error();
            }
            strcpy(msg_erro,"");

            if ( (strcmp($1, "BOOL") == 0) || (strcmp($3, "BOLL") == 0) ){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Aritimética: Operandos devem ser de tipos numéricos (MILHAS ou DOLAR)");
                semantic_error();
            }
            strcpy(msg_erro,"");
            
            //o resultado só vai ser do tipo MILHAS se os dois operandos forem do tipo MILHAS (inclusive na divisao)
            if ( (strcmp($1, "MILHAS") == 0) && (strcmp($3, "MILHAS") == 0) ){
                $$ = "MILHAS";
            }
            else{
                $$ = "DOLAR";
            }
        }

    | expr RELOP term   
        { 
            if ( (strcmp($1, "VOUCHER") == 0) || (strcmp($3, "VOUCHER") == 0) ){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Relacional: Ainda não está diponível para variáveis do tipo VOUCHER =(");
                semantic_error();
            }
            strcpy(msg_erro,"");


            if ( (strcmp($1, "BOOL") == 0) || (strcmp($3, "BOLL") == 0) ){
                if ( (strcmp($2, "#") != 0) && (strcmp($2, "=") != 0) ) //se não está vendo se igual nem se diferente
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Operação Relacionados: Para que os operandos sejam booleanos o operados tem que ser '=' ou '#'");
                    semantic_error();
            }
            strcpy(msg_erro,"");

            //para valores numéricos não tem restrição
            $$ = "BOOL"; 
        }

    | expr LOGICOP term 
        { 
            if ((strcmp($1, "BOOL") != 0) || (strcmp($3, "BOOL") != 0)){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Lógica: Operadores lógicos só podem ser aplicados ao tipo BOOL\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
            $$ = $1;
        }
    
    | expr LOGICOP_UNARY 
            {
                if (strcmp($1, "BOOL") != 0) {
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Operação Lógica Unária: O operador NOT não pode ser aplicado ao tipo'"); 
                    strcat(msg_erro, $1); 
                    strcat(msg_erro, "' apenas ao tipo BOOL\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");
                
                $$ = $1;
            }
    | term {$$ = $1;}
    | OPEN_PARENTHESES term CLOSE_PARENTHESES {$$ = $2;}
    ;

term: 
    INT             {$$ = "MILHAS";}
    | FLOAT         {$$ = "DOLAR";}
    | STRING        {$$ = "VOUCHER";}
    | BOOL          {$$ = "BOOL";}
    | call_function {$$ = $1;}
    | ID            
        {
            //sempre que for usar um identificador tem que coneferir se ele existe no escopo interno ou externo e quardar seu tipo pra fazer verificacao de tipo
            Simbolo *simbolo = buscar_simbolo(escopo_atual,  $1);
            if (simbolo == NULL){
                strcpy(msg_erro,"");
                strcat(msg_erro, "A variável '"); 
                strcat(msg_erro, $1); 
                strcat(msg_erro, "' não foi previamente declarada!'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
            
            //pra poder usar uma variável ela precisar ter sido inicializada
            if (simbolo->inicializado == 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "A variável '"); 
                strcat(msg_erro, $1); 
                strcat(msg_erro, "' não foi previamente definida/inicializada!'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
            $$ = simbolo->tipo;
        }
    | ID_CONST    
        {
            //sempre que for usar um identificador tem que coneferir se ele existe no escopo interno ou externo e quardar seu tipo pra fazer verificacao de tipo
            Simbolo *simbolo = buscar_simbolo(escopo_atual,  $1);
            if (simbolo == NULL){
                strcpy(msg_erro,"");
                strcat(msg_erro, "A constante '"); 
                strcat(msg_erro, $1); 
                strcat(msg_erro, "' não foi previamente definida!'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
            
            $$ = simbolo->tipo;
        }
    ;

//relacionado com checkin e checkout
types:
    type type_list
    ;

type_list:
    type_list COMMA type
    |
    ;

type: 
    TYPE 
        {      
            tipos_checkin[qtd_tipos_checkin] = $1;
            qtd_tipos_checkin += 1;
        }
    ;
ids:
    id id_list
    ;

id_list:
    id_list COMMA id
    |
    ;

id:
    ID
        {      
            ids_checkin[qtd_ids_checkin] = $1;
            qtd_ids_checkin += 1;
        }
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

int identificador_disponivel(char *identificador) {
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


void verificar_definicao_funcoes_chamadas() {
    for (int i = 0; i < numero_de_funcoes; i++) {
        if (funcoes[i]->chamada){
            if (funcoes[i]->definida == 0){
                strcat(msg_erro, "A função '");
                strcat(msg_erro, funcoes[i]->identificador);
                strcat(msg_erro, "' não foi definida, existe apenas seu protótipo!");
                semantic_error();
            }
        } 
    }
}

int main(void) {
    yyparse();     
    
    printf("\n\n\033[1;32mPrograma sintaticamente correto.\033[0m\n\n");

    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas);

    return 0;
}