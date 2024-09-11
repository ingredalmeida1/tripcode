/*====================================================================================================
        Analisador Sintático para a Linguagem TripCode
====================================================================================================*/
%{
/*----------------------------------------------------------------------------------------------------
        Bibliotecas C, codigos C e Definicoes de Tokens 
----------------------------------------------------------------------------------------------------*/
    #include "node.h"
    #include <cstdio>
    #include <cstdlib>
    #include <iostream>

    NBlock *programBlock; // parte da raiz do programa, a trip
    extern char* yytext;
    extern int yylineno;
    int yylex();
    char* removeQuotes(const char* str) ;
    std::string* get_formated_type(std::string type);

    #define ERROR(str)                                                                                                   \
    std::cerr << "\n\033[1;31mErro de sintaxe próximo à linha " << yylineno << "! Token com erro: '" << yytext << "'\033[0m\n\n"; \
    exit(1);
	void yyerror(const char *s) {ERROR(s)}

%}

/*----------------------------------------------------------------------------------------------------
        Registros Semânticos
----------------------------------------------------------------------------------------------------*/
%union {
    Node *node;
    NBlock *block;
    NExpression *expr;
	NStatement *stmt;
	NId *ident;
	NBagagem *var_decl;
	std::vector<NBagagem*> *varvec;
	std::vector<NExpression*> *exprvec;
	std::string *string;

    int token;
    struct {
        NExpression* expr;
        std::string* formatString;
    } print_content;
    struct {
        std::vector<NExpression*> *exprvec;
        std::string *formatString;
    } print_contents;
    struct {
        std::string* type;
        NExpression* expr;
    } reading;
}

/*----------------------------------------------------------------------------------------------------
        Tokens
----------------------------------------------------------------------------------------------------*/
%token <token> TRIP 
%token <token> CHECKOUT ALFANDEGA ISENTO ROTEIRO
%token <token> DOT_COMMA COMMA
%token <token> OPEN_PARENTHESES CLOSE_PARENTHESES 
%token <token> OPEN_CODEBLOCK CLOSE_CODEBLOCK
%token <token> ASSIGN
%token <string> INT TYPE L_STR FLOAT
%token <string> OP RELOP
%token <string> ID

%type <ident> ident type
%type <expr>  expr call_funct term assign initial_assign print
%type <block> main stmts block else
%type <stmt> stmt var_decl var_def if
%type <reading> reading
%type <print_contents> contents
%type <print_content> content

/* definir variavel de partida da gramatica                                                        */
%start tripcode

/*----------------------------------------------------------------------------------------------------
        Associatividade e Precedência dos Operadores
----------------------------------------------------------------------------------------------------*/
%left OP
%left RELOP

/*----------------------------------------------------------------------------------------------------
        Regras da Gramática
----------------------------------------------------------------------------------------------------*/

%%
tripcode:  
    main  
    { 
        programBlock = $1;
        yylineno++;
    } 
    ;

main:
    ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK stmts CLOSE_CODEBLOCK type CLOSE_CODEBLOCK
    {
        $$ = $6;
    }
    | {$$ = new NBlock();}
    ;

stmts:
    stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
    | stmts stmt { $1->statements.push_back($<stmt>2); }
    ;

stmt: 
    var_decl { $$ = $1; }
    | assign { $$ = new NExpressionStatement(*$1); }
    | var_def { $$ = $1; }
    | call_funct { $$ = new NExpressionStatement(*$1); }
    | if { $$ = $1; }
    ;

type:
    TYPE { $$ = new NId(*$1); delete $1; }
    ;

var_decl: 
    type ident DOT_COMMA { $$ = new NBagagem(*$1, *$2); }
    ;

assign:
    ident ASSIGN expr DOT_COMMA { $$ = new NAssignment(*$<ident>1, *$3); }

var_def:
    type ident initial_assign DOT_COMMA {
        if(!$3){
            $$ = new NBagagem(*$1, *$2);
        }
        else{
            $$ = new NBagagem(*$1, *$2, $3); 
        } 
    }

initial_assign:
    ASSIGN expr { $$ = $2; }
    | {$$ = NULL;}
    ;

expr: 
    expr OP expr { $$ = new NBinaryOperator(*$1, *$2, *$3); }
    | expr RELOP expr { $$ = new NBinaryOperator(*$1, *$2, *$3); }
    | term { $$ = $1; }
    ;

term: 
    INT { $$ = new NMilhas(atol($1->c_str())); delete $1; }
    | FLOAT { $$ = new NDolar(atol($1->c_str())); delete $1; }
    | L_STR {$$ = new NVoucher(removeQuotes($1->c_str())); delete $1; }
    | ident { $<ident>$ = $1; }     
    ;

ident:
    ID { $$ = new NId(*$1); delete $1; }
    ;

call_funct:
    print { $$ = $1; }
    ;

if:
    ALFANDEGA OPEN_PARENTHESES expr CLOSE_PARENTHESES block else 
    {
        $$ = new NAlfandega(*$3, *$5, $6);
    }
    ;

else:
    ISENTO block { $$ = $2; }
    | { $$ = NULL; }
    ;

block:  
    OPEN_CODEBLOCK stmts  CLOSE_CODEBLOCK { $$ = $2; }
    | CLOSE_CODEBLOCK  CLOSE_CODEBLOCK { $$ = new NBlock(); }
    ;

print:
    CHECKOUT OPEN_PARENTHESES contents CLOSE_PARENTHESES DOT_COMMA 
    {
        $$ = new NCheckout(*$3.exprvec, *$3.formatString + "\n");
    }
    ;

contents:
    content
    {
        $$.exprvec = new ExpressionList(); 
        $$.exprvec->push_back($<print_content>1.expr); 
        $<print_contents>$.formatString = $<print_content>1.formatString;
    }
    ;

content:
    L_STR  
    {
        $$.formatString = $1;
        delete $1;
    }
    | reading 
    {
        $$.expr = $1.expr; 
        $$.formatString = get_formated_type(*$1.type);
    }
    ;

reading: 
    TYPE COMMA expr 
    { 
        $$.type = $1; 
        $$.expr = $3;
    }
    ;

%%

/*----------------------------------------------------------------------------------------------------
        Funcoes em C
----------------------------------------------------------------------------------------------------*/

void yyerror() {
     printf("\n\nPrograma sintaticamente incorreto.\n\n");
     exit(0);
}

char* removeQuotes(const char* str) {
    size_t len = strlen(str);
    char* result = (char*) malloc(len - 1);
    int j = 0;

    for (size_t i = 1; i < len - 1; i++) { 
        if (str[i] != '"') {
            result[j++] = str[i]; 
        }
    }

    result[j] = '\0'; 
    return result;
}

std::string* get_formated_type(std::string type){
    std::string* format = new std::string();

    if(type == "MILHAS"){
        *format = "%d";
    }
    else if(type == "DOLAR"){
        *format = "%f";
    }
    else if(type == "VOUCHER"){
        *format = "%s";
    }
    else{
        *format = "%s";
    }
    return format;
}