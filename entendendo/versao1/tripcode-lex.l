%{ 
/* cabecalho C */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

%} 
%option noyywrap

/* definicoes regulares */
delim		               [ \t\n] 
ws		                   {delim}+
digit                      [0-9]
lower_letter               [a-z]
upper_letter               [A-Z]
letter                     {lower_letter}|{upper_letter}
comment                    ->[^<]*<-
atribuicao                 \<\-\>
eq                         \= 
gt                         \>
ge                         \>\=
lt                         \<
le                         \<\=
diff                       \#
relop                      {eq}|{gt}|{ge}|{lt}|{le}|{diff}
and                        AND
or                         OR
not                        NOT
logicop                    {and}|{or}|{not}
id                         ({lower_letter})(_|{letter}|{digit})*
inteiro_pos                \+?{digit}+
inteiro_neg                \-{digit}+
inteiro                    {inteiro_pos}|{inteiro_neg}
float                      {inteiro}+\.{digit}+
string                     \"([^\\\"]|\\.)*\"|\'([^\\']|\\.)*\'
som                        \+
sub                        \-
mult                       \*
div                        \/
mod                        \%
op                         {som}|{sub}|{mult}|{div}|{mod}
dot_comma                  \;
dot                        \.
comma                      \,
colon                      \:
open_bracket               \[
close_bracket              \]
close_parentheses          \)
open_parentheses           \(
open_codeblock             \>\>\>
close_codeblock            \<\<\<
alfandega                  ALFANDEGA
isento                     ISENTO
tributado                  TRIBUTADO
checkout                   CHECKOUT
checkin                    CHECKIN
itinerario                 ITINERARIO
rota                       ROTA
pousar                     POUSAR
feriado                    FERIADO
imprevisto                 IMPREVISTO
descansar                  DESCANSAR
trabalhar                  TRABALHAR
mapa                       MAPA
passaporte                 PASSAPORTE
bagagem                    BAGAGEM
roteiro                    ROTEIRO
despachar                  DESPACHAR
embarcar                   EMBARCAR
decolar                    DECOLAR
origem                     ORIGEM
destino                    DESTINO
escala                     ESCALA 
turistando                 TURISTANDO
turistar                   TURISTAR
durante                    DURANTE
cambio                     CAMBIO
cotacao                    COTACAO 
classe                     CLASSE
dolar                      DOLAR
milhas                     MILHAS
voucher                    VOUCHER
trip                       trip
status                     STATUS
exterior                   EXTERIOR
ferias                     FERIAS
diautil                    DIAUTIL


%% 
{ws}		         {}
{comment}            { printf("Foi encontrado um comentario: %s\n", yytext); }

{cambio}             { printf("Foi encontrado um operador cambio. LEXEMA:  %s\n", yytext); }
{cotacao}            { printf("Foi encontrado um operador cotacao. LEXEMA:  %s\n", yytext); }
{classe}             { printf("Foi encontrado um operador classe. LEXEMA:  %s\n", yytext); }
{alfandega}          { printf("Foi encontrado o comando alfandega. LEXEMA: %s\n", yytext); }
{isento}             { printf("Foi encontrado o comando isento. LEXEMA: %s\n", yytext); }
{tributado}          { printf("Foi encontrado o comando tributado. LEXEMA: %s\n", yytext); }
{checkout}           { printf("Foi encontrada a função checkout. LEXEMA: %s\n", yytext); }
{checkin}            { printf("Foi encontrada a função checkin. LEXEMA: %s\n", yytext); }
{itinerario}         { printf("Foi encontrada o comando itinerario. LEXEMA: %s\n", yytext); }
{rota}               { printf("Foi encontrada o comando rota. LEXEMA: %s\n", yytext); }
{pousar}             { printf("Foi encontrada o comando pousar. LEXEMA: %s\n", yytext); }
{feriado}            { printf("Foi encontrado o comando feriado. LEXEMA:  %s\n", yytext); }
{imprevisto}         { printf("Foi encontrada o comando imprevisto. LEXEMA: %s\n", yytext); }
{descansar}          { printf("Foi encontrada o comando descansar. LEXEMA: %s\n", yytext); }
{trabalhar}          { printf("Foi encontrada o comando trabalhar. LEXEMA: %s\n", yytext); }
{roteiro}            { printf("Foi encontrada o comando roteiro. LEXEMA: %s\n", yytext); }
{embarcar}           { printf("Foi encontrada o comando embarcar. LEXEMA: %s\n", yytext); }
{despachar}          { printf("Foi encontrada o comando despachar. LEXEMA: %s\n", yytext); }
{decolar}            { printf("Foi encontrada o comando decolar. LEXEMA: %s\n", yytext); }
{origem}             { printf("Foi encontrada o comando origem. LEXEMA: %s\n", yytext); }
{destino}            { printf("Foi encontrada o comando destino. LEXEMA: %s\n", yytext); }
{escala}             { printf("Foi encontrada o comando escala. LEXEMA: %s\n", yytext); }
{turistando}         { printf("Foi encontrada o comando turistando. LEXEMA: %s\n", yytext); }
{turistar}           { printf("Foi encontrada o comando turistar. LEXEMA: %s\n", yytext); }
{durante}            { printf("Foi encontrada o comando durante. LEXEMA: %s\n", yytext); }
{mapa}               { printf("Foi encontrada a estrutura de dados mapa. LEXEMA: %s\n", yytext); }
{passaporte}         { printf("Foi encontrada a estrutura de dados passaporte. LEXEMA: %s\n", yytext); }
{bagagem}            { printf("Foi encontrada a estrutura de dados babagem. LEXEMA: %s\n", yytext); }
{milhas}             { printf("Foi encontrado um tipo de dados milhas. LEXEMA:  %s\n", yytext); }
{dolar}              { printf("Foi encontrado um tipo de dados dolar. LEXEMA:  %s\n", yytext); }
{voucher}            { printf("Foi encontrado tipo de dados voucher. LEXEMA:  %s\n", yytext); }
{trip}               { printf("Foi encontrado a função principal trip. LEXEMA:  %s\n", yytext); }
{status}             { printf("Foi encontrado tipo de dados status. LEXEMA:  %s\n", yytext); }
{exterior}           { printf("Foi encontrada uma declaração de constante exterior. LEXEMA:  %s\n", yytext); }
{ferias}             { printf("Foi encontrado um valor booleano ferias. LEXEMA:  %s\n", yytext); }
{diautil}            { printf("Foi encontrado um valor booleano diautil. LEXEMA:  %s\n", yytext); }


{comma}              { printf("Foi encontrado uma vírgula. LEXEMA:  %s\n", yytext); }
{dot_comma}          { printf("Foi encontrado um ponto e vírgula. LEXEMA:  %s\n", yytext); }
{dot}                { printf("Foi encontrado um ponto. LEXEMA:  %s\n", yytext); }
{colon}              { printf("Foi encontrado dois pontos. LEXEMA:  %s\n", yytext); }
{open_parentheses}   { printf("Foi encontrada uma abertura de parênteses. LEXEMA:  %s\n", yytext); }
{close_parentheses}  { printf("Foi encontrado um fechamento de parênteses. LEXEMA:  %s\n", yytext); }
{open_bracket}       { printf("Foi encontrada uma abertura de colchetes. LEXEMA:  %s\n", yytext); }
{close_bracket}      { printf("Foi encontrado um fechamento de colchetes. LEXEMA:  %s\n", yytext); }
{open_codeblock}     { printf("Foi encontrado uma abertura de bloco de código. LEXEMA:  %s\n", yytext); }
{close_codeblock}    { printf("Foi encontrado um fechamento de bloco de código. LEXEMA:  %s\n", yytext); }
{atribuicao}         { printf("Foi encontrada a operação de atribuição. LEXEMA: %s\n", yytext); }
{relop}              { printf("Foi encontrado um operdador relacional. LEXEMA:  %s\n", yytext); }
{logicop}            { printf("Foi encontrado um operador lógico. LEXEMA:  %s\n", yytext); }
{op}                 { printf("Foi encontrado um operador aritmético. LEXEMA:  %s\n", yytext); }
{inteiro}            { printf("Foi encontrado um inteiro. LEXEMA:  %s\n", yytext); }
{float}              { printf("Foi encontrado um float. LEXEMA:  %s\n", yytext); }
{string}             { printf("Foi encontrado uma string. LEXEMA:  %s\n", yytext); }

{id}                 { printf("Foi encontrado um identificador. LEXEMA: %s\n", yytext); }


%% 
int main(void) 
{ 
    yylex(); 
    return 0; 
}