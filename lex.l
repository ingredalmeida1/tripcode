%{ /* Codigo C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translate.tab.h"  /* Incluir o cabeçalho gerado pelo Bison */

extern int yylineno; /* Variável para contar linhas */
%}

/* This tells flex to read only one input file */
%option noyywrap 

/* Definições regulares */
delim             [ \t] 
ws                {delim}+
line              \n
comment           ->[^<]*<-

trip              trip

/* --- valores booleanos: */
ferias            FERIAS
diautil           DIAUTIL

/* --- tipos de dados: */
status            STATUS
dolar             DOLAR
milhas            MILHAS
voucher           VOUCHER

mapa              MAPA
passaporte        PASSAPORTE

/* --- operadores relacionados aos tipos */
cambio            CAMBIO
cotacao           COTACAO 
classe            CLASSE

/* --- declarar variavel */
bagagem           BAGAGEM
exterior          EXTERIOR

/* --- comandos de entrada/saida */
checkin           CHECKIN
checkout          CHECKOUT

/* --- comando condicional */
alfandega         ALFANDEGA
isento            ISENTO
tributado         TRIBUTADO

/* --- comando switch */
itinerario        ITINERARIO
rota              ROTA
imprevisto        IMPREVISTO

pousar            POUSAR
feriado           FERIADO

/* --- comando repeticao */
decolar           DECOLAR
origem            ORIGEM
destino           DESTINO
escala            ESCALA 

turistando        TURISTANDO
turistar          TURISTAR
durante           DURANTE

/* --- definicao de funcao */
roteiro           ROTEIRO
despachar         DESPACHAR
embarcar          EMBARCAR

/* --- operadores */
and               AND
or                OR

not               NOT
descansar         DESCANSAR
trabalhar         TRABALHAR

som               \+
sub               \-
mult              \*
div               \/
mod               \%

eq                \=
gt                \>
ge                \>\=
lt                \<
le                \<\=
diff              \#

atribuicao        \<\-\>

/* --- */

digit             [0-9]
lower_letter      [a-z]
upper_letter      [A-Z]
letter            {lower_letter}|{upper_letter}
inteiro_pos       \+?{digit}+
inteiro_neg       \-{digit}+

op                {som}|{sub}|{mult}|{div}|{mod}
relop             {eq}|{gt}|{ge}|{lt}|{le}|{diff}
logicop           {and}|{or}|{not}

inteiro           {inteiro_pos}|{inteiro_neg}
float             {inteiro}+\.{digit}+
string            \"([^\\\"]|\\.)*\"|\'([^\\']|\\.)*\'

type              ({milhas})|({dolar})|({voucher})|({bool})|({mapa})|({passaporte})

id                ({lower_letter})(_|{letter}|{digit})*

dot_comma         \;
dot               \.
comma             \,
open_bracket      \[
close_bracket     \]
open_parentheses  \(
close_parentheses \)
open_codeblock    \>\>\>
close_codeblock   \<\<\<
colon             \:

%%

{comment}                { printf("%s", yytext); }
{line}                   { printf("\n%d\t", yylineno++); }
{ws}                     { }

{roteiro}                { return ROTEIRO; }
{trip}                   { return TRIP; }
{milhas}                 { return MILHAS; }
{open_codeblock}         { return OPEN_CODEBLOCK; }
{close_codeblock}        { return CLOSE_CODEBLOCK; }
{open_parentheses}       { return OPEN_PARENTHESES; }
{close_parentheses}      { return CLOSE_PARENTHESES; }

{id}                     { return ID; }

%%