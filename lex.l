%{
/* Cabeçalho C */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "translate.tab.h"  /* Inclua o cabeçalho gerado pelo Bison */

%} 

%option noyywrap

/* definicoes regulares */
delim		               [ \t] 
ws		                   {delim}+
linha                      \n
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
open_bracket               \[
close_bracket              \]
close_parentheses          \)
open_parentheses           \(
open_codeblock             \>\>\>
close_codeblock            \<\<\<
colon                      \:
alfandega                  ALFANDEGA
isento                     ISENTO
tributado                  TRIBUTADO
checkout                   CHECKOUT
checkin                    CHECKIN
itinerario                 ITINERARIO
rota                       ROTA
pousar                     POUSAR
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
feriado                    FERIADO
bool                       ({ferias})|({diautil})
type                       ({milhas})|({dolar})|({voucher})|({bool})

%% 
{linha}                  { printf("\n%d\t", yylineno); yylineno++; }
{ws}		             {}
{comment}                { /* Ignora comentários */ }

{roteiro}                { return ROTEIRO; }
{trip}                   { return TRIP; }
{open_parentheses}       { return OPEN_PARENTHESES; }
{close_parentheses}      { return CLOSE_PARENTHESES; }


%% 
