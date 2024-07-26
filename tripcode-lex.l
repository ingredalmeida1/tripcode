%{ 
/* cabecalho C */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

%} 
%option noyywrap

/* definicoes regulares */
delim		         [ \t\n] 
ws		             {delim}+
digit                [0-9]
letter               [A-za-z]
comment              ->[^<]*<-
atribuicao           \<\-\>
eq                   \=
gt                   \>
ge                   \>\=
lt                   \<
le                   \<\=
diff                 \#
relop                {eq}|{gt}|{ge}|{lt}|{le}|{diff}
and                  \&
or                   \|
xor                  \^
bitop                {and}|{or}|{xor}
id                   (_|{letter})(_|{letter}|{digit})*
milhas               {digit}+
dolar                {digit}+\.{digit}+
documento            \"([^\\\"]|\\.)*\"|\'([^\\']|\\.)*\'
som                  \+
sub                  \-
mult                 \*
div                  \/
mod                  \%
op                   {som}|{sub}|{mult}|{div}|{mod}
comma                \;
colon                \:
close_paren          \)
open_paren           \(
close_colch          \]
open_colch           \[
open_block           \>\>\>
close_block          \<\<\<
alfandega            ALFANDEGA
isento               ISENTO
tributado            TRIBUTADO
checkout             CHECKOUT
itinerario           ITINERARIO
rota                 ROTA
pousar               POUSAR
imprevisto           IMPREVISTO
descansar            DESCANSAR
trabalhar            TRABALHAR


%% 
{ws}		         {}
{comment}            { printf("Foi encontrado um comentario: %s\n", yytext); }
{atribuicao}         { printf("Foi encontrada a operação de atribuição. LEXEMA: %s\n", yytext); }
{relop}              { printf("Foi encontrado um operdador relacional. LEXEMA:  %s\n", yytext); }
{bitop}              { printf("Foi encontrado um operador lógico. LEXEMA:  %s\n", yytext); }
{op}                 { printf("Foi encontrado um operador aritmético. LEXEMA:  %s\n", yytext); }
{alfandega}          { printf("Foi encontrado o comando alfandega. LEXEMA: %s\n", yytext); }
{isento}             { printf("Foi encontrado o comando isento. LEXEMA: %s\n", yytext); }
{tributado}          { printf("Foi encontrado o comando tributado. LEXEMA: %s\n", yytext); }
{checkout}           { printf("Foi encontrada a função checkout. LEXEMA: %s\n", yytext); }
{itinerario}         { printf("Foi encontrada o comando itinerario. LEXEMA: %s\n", yytext); }
{rota}               { printf("Foi encontrada o comando rota. LEXEMA: %s\n", yytext); }
{pousar}             { printf("Foi encontrada o comando pousar. LEXEMA: %s\n", yytext); }
{imprevisto}         { printf("Foi encontrada o comando imprevisto. LEXEMA: %s\n", yytext); }
{descansar}          { printf("Foi encontrada o comando descansar. LEXEMA: %s\n", yytext); }
{trabalhar}          { printf("Foi encontrada o comando trabalhar. LEXEMA: %s\n", yytext); }
{id}                 { printf("Foi encontrado um identificador. LEXEMA: %s\n", yytext); }
{milhas}             { printf("Foi encontrado um tipo de dados milhas. LEXEMA:  %s\n", yytext); }
{dolar}              { printf("Foi encontrado um tipo de dados dolar. LEXEMA:  %s\n", yytext); }
{documento}          { printf("Foi encontrado tipo de dados documento. LEXEMA:  %s\n", yytext); }
{comma}              { printf("Foi encontrado um ponto e vírgula. LEXEMA:  %s\n", yytext); }
{colon}              { printf("Foi encontrado dois pontos. LEXEMA:  %s\n", yytext); }
{open_paren}         { printf("Foi encontrada uma abertura de parênteses. LEXEMA:  %s\n", yytext); }
{close_paren}        { printf("Foi encontrado um fechamento de parênteses. LEXEMA:  %s\n", yytext); }
{open_block}         { printf("Foi encontrado uma abertura de bloco de código. LEXEMA:  %s\n", yytext); }
{close_block}        { printf("Foi encontrado um fechamento de bloco de código. LEXEMA:  %s\n", yytext); }
{open_colch}         { printf("Foi encontrado uma abertura de colchete. LEXEMA:  %s\n", yytext); }
{close_colch}        { printf("Foi encontrado um fechamento de colchete. LEXEMA:  %s\n", yytext); }


%% 
int main(void) 
{ 
    yylex(); 
    return 0; 
}