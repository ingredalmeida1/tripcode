/*====================================================================================================
        Analisador Léxico para a Linguagem TripCode
====================================================================================================*/
%{ 
/*----------------------------------------------------------------------------------------------------
        Bibliotecas C, codigos C e Definicoes de Tokens 
----------------------------------------------------------------------------------------------------*/                                              
#include <string> 
#include "node.h"
#include "parser.hpp"          

void yyerror(char *);         
extern int yylineno; 

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t)    (yylval.token = t)

%}

%option noyywrap        

/*----------------------------------------------------------------------------------------------------
        Definicoes Regulares  
----------------------------------------------------------------------------------------------------*/
delim             [ \t] 
ws                {delim}+
line              \n
comment           ->[^<]*<-
trip              TRIP
roteiro           ROTEIRO
checkout          CHECKOUT
alfandega         ALFANDEGA
isento            ISENTO 
som               \+
sub               \-
mult              \*
div               \/
mod               \%
op                {som}|{sub}|{mult}|{div}|{mod}
eq                \=
gt                \>
ge                \>\=
lt                \<
le                \<\=
diff              \#
relop             {eq}|{gt}|{ge}|{lt}|{le}|{diff}
atribuicao        \<\-\>
digit             [0-9]
lower_letter      [a-z]
upper_letter      [A-Z]
letter            {lower_letter}|{upper_letter}
inteiro_pos       \+?{digit}+
inteiro_neg       \-{digit}+
inteiro           {inteiro_pos}|{inteiro_neg}
float             {inteiro}+\.{digit}+
string            \"([^\\\"]|\\.)*\"|\'([^\\']|\\.)*\'
id                ({lower_letter})(_|{letter}|{digit})*
dot_comma         \;
comma             \,
open_parentheses  \(
close_parentheses \)
open_codeblock    \>\>\>
close_codeblock   \<\<\<
status            STATUS
dolar             DOLAR
milhas            MILHAS
voucher           VOUCHER
type              {status}|{dolar}|{milhas}|{voucher}
quot              \"
l_str             {quot}.*{quot}

/*----------------------------------------------------------------------------------------------------
        Expressoes Regulares definindo os Tokens 
----------------------------------------------------------------------------------------------------*/
%%
{comment}                { }
{line}                   { }
{ws}                     { }
{trip}                   { return TOKEN(TRIP); }
{roteiro}                { return TOKEN(ROTEIRO); }
{checkout}               { return TOKEN(CHECKOUT); }
{alfandega}              { return TOKEN(ALFANDEGA); }
{isento}                 { return TOKEN(ISENTO); }
{dot_comma}              { return TOKEN(DOT_COMMA); }
{comma}                  { return TOKEN(COMMA); }
{open_parentheses}       { return TOKEN(OPEN_PARENTHESES); }
{close_parentheses}      { return TOKEN(CLOSE_PARENTHESES); }
{open_codeblock}         { return TOKEN(OPEN_CODEBLOCK); }
{close_codeblock}        { return TOKEN(CLOSE_CODEBLOCK); }
{atribuicao}             { return TOKEN(ASSIGN); }
{op}                     { SAVE_TOKEN; return OP; }
{relop}                  { SAVE_TOKEN; return RELOP; }
{inteiro}                { SAVE_TOKEN; return INT; }
{float}                  { SAVE_TOKEN; return FLOAT; }
{id}                     { SAVE_TOKEN; return ID; }
{type}                   { SAVE_TOKEN; return TYPE; }
{l_str}                  { SAVE_TOKEN; return L_STR; }


<<EOF>>                 { // se chegou no fim do arquivo:
                          printf("\n\n\033[1;32mPrograma sintaticamente correto.\033[0m\n\n");
                          return 0;
                        }                      
%%