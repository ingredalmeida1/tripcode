%{ /* Codigo C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translate.tab.h"  /* Incluir o cabeçalho gerado pelo Bison */

void yyerror(char *);

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

/* mapa              MAPA */
/* passaporte        PASSAPORTE */

type              {status}|{dolar}|{milhas}|{voucher}

/* --- operadores relacionados aos tipos */
/* cambio            CAMBIO */
/* cotacao           COTACAO */
/* classe            CLASSE */

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
/* descansar         DESCANSAR */
/* trabalhar         TRABALHAR */

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

op                {som}|{sub}|{mult}|{div}|{mod}
relop             {eq}|{gt}|{ge}|{lt}|{le}|{diff}
logicop           {and}|{or}
logicop_unary     {not}

/* --- valores */
digit             [0-9]
lower_letter      [a-z]
upper_letter      [A-Z]
letter            {lower_letter}|{upper_letter}
inteiro_pos       \+?{digit}+
inteiro_neg       \-{digit}+

inteiro           {inteiro_pos}|{inteiro_neg}
float             {inteiro}+\.{digit}+
string            \"([^\\\"]|\\.)*\"|\'([^\\']|\\.)*\'
boolean           {ferias}|{diautil}

id                ({lower_letter})(_|{letter}|{digit})*

/* --- estrutura do codigo */
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

/* --- erros lexicos */
all_characters     [a-zA-Z1-9]
lexema_error      {all_characters}+|.

%%

{comment}                { printf("%s", yytext); }
{line}                   { printf("\n%d\t", yylineno++); }
{ws}                     { printf("%s", yytext); }

{trip}                   { return TRIP; }

{bagagem}                { return BAGAGEM; }
{exterior}               { return EXTERIOR; }

{checkin}                { return CHECKIN; }
{checkout}               { return CHECKOUT; }

{alfandega}              { return ALFANDEGA; }
{isento}                 { return ISENTO; }
{tributado}              { return TRIBUTADO; }

{itinerario}             { return ITINERARIO; }
{rota}                   { return ROTA; }
{imprevisto}             { return IMPREVISTO; }

{pousar}                 { return POUSAR; }
{feriado}                { return FERIADO; }

{decolar}                { return DECOLAR; }
{origem}                 { return ORIGEM; }
{destino}                { return DESTINO; }
{escala}                 { return ESCALA; }

{turistando}             { return TURISTANDO; }
{turistar}               { return TURISTAR; }
{durante}                { return DURANTE; }

{roteiro}                { return ROTEIRO; }
{embarcar}               { return EMBARCAR; }
{despachar}              { return DESPACHAR; }

{comma}                  { return COMMA; }
{dot_comma}              { return DOT_COMMA; }
{dot}                    { return DOT; }
{colon}                  { return COLON; }
{open_parentheses}       { return OPEN_PARENTHESES; }
{close_parentheses}      { return CLOSE_PARENTHESES; }
{open_bracket}           { return OPEN_BRACKET; }
{close_bracket}          { return CLOSE_BRACKET; }
{open_codeblock}         { return OPEN_CODEBLOCK; }
{close_codeblock}        { return CLOSE_CODEBLOCK; }

{atribuicao}             { return ASSIGN;}

{op}                     { yylval.str = strdup(yytext); return OP;}
{relop}                  { yylval.str = strdup(yytext); return RELOP;}
{logicop}                { yylval.str = strdup(yytext); return LOGICOP;}
{logicop_unary}          { yylval.str = strdup(yytext); return LOGICOP_UNARY;}

{type}                   { yylval.str = strdup(yytext); return TYPE;}

{inteiro}                { yylval.iValue = atoi(yytext); return INT;}
{float}                  { yylval.real = atof(yytext); return FLOAT;}
{string}                 { yylval.str = strdup(yytext); return STRING;}
{boolean}                { yylval.str = strdup(yytext); return BOOL;}

{id}                     { yylval.str = strdup(yytext); return ID; }

{lexema_error}           {                           
                            char erro_msg[100]; // Buffer para armazenar a mensagem de erro
                            sprintf(erro_msg, "SintaxError: invalid character '%s'", yytext);
                            yyerror(erro_msg); // Passa a mensagem formatada para a função yyerror
                        }                        
%%