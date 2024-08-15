%{ /* Codigo C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translate.tab.h"       // Incluir o cabeçalho gerado pelo Bison 

void yyerror(char *);

extern char error_message[200];  //construir mensagem de erro

extern int yylineno;             //Variável para contar linhas */

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

concat            \<\>
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

{trip}                   { printf("%s", yytext); return TRIP; }

{bagagem}                { printf("%s", yytext); return BAGAGEM; }
{exterior}               { printf("%s", yytext); return EXTERIOR; }

{checkin}                { printf("%s", yytext); return CHECKIN; }
{checkout}               { printf("%s", yytext); return CHECKOUT; }

{alfandega}              { printf("%s", yytext); return ALFANDEGA; }
{isento}                 { printf("%s", yytext); return ISENTO; }
{tributado}              { printf("%s", yytext); return TRIBUTADO; }

{itinerario}             { printf("%s", yytext); return ITINERARIO; }
{rota}                   { printf("%s", yytext); return ROTA; }
{imprevisto}             { printf("%s", yytext); return IMPREVISTO; }

{pousar}                 { printf("%s", yytext); return POUSAR; }
{feriado}                { printf("%s", yytext); return FERIADO; }

{decolar}                { printf("%s", yytext); return DECOLAR; }
{origem}                 { printf("%s", yytext); return ORIGEM; }
{destino}                { printf("%s", yytext); return DESTINO; }
{escala}                 { printf("%s", yytext); return ESCALA; }

{turistando}             { printf("%s", yytext); return TURISTANDO; }
{turistar}               { printf("%s", yytext); return TURISTAR; }
{durante}                { printf("%s", yytext); return DURANTE; }

{roteiro}                { printf("%s", yytext); return ROTEIRO; }
{embarcar}               { printf("%s", yytext); return EMBARCAR; }
{despachar}              { printf("%s", yytext); return DESPACHAR; }

{comma}                  { printf("%s", yytext); return COMMA; }
{dot_comma}              { printf("%s", yytext); return DOT_COMMA; }
{dot}                    { printf("%s", yytext); return DOT; }
{colon}                  { printf("%s", yytext); return COLON; }
{open_parentheses}       { printf("%s", yytext); return OPEN_PARENTHESES; }
{close_parentheses}      { printf("%s", yytext); return CLOSE_PARENTHESES; }
{open_bracket}           { printf("%s", yytext); return OPEN_BRACKET; }
{close_bracket}          { printf("%s", yytext); return CLOSE_BRACKET; }
{open_codeblock}         { printf("%s", yytext); return OPEN_CODEBLOCK; }
{close_codeblock}        { printf("%s", yytext); return CLOSE_CODEBLOCK; }

{atribuicao}             { printf("%s", yytext); return ASSIGN;}
{concat}                 { printf("%s", yytext); return CONCAT;}

{op}                     { printf("%s", yytext); yylval.str = strdup(yytext); return OP;}
{relop}                  { printf("%s", yytext); yylval.str = strdup(yytext); return RELOP;}
{logicop}                { printf("%s", yytext); yylval.str = strdup(yytext); return LOGICOP;}
{logicop_unary}          { printf("%s", yytext); yylval.str = strdup(yytext); return LOGICOP_UNARY;}

{type}                   { printf("%s", yytext); yylval.str = strdup(yytext); return TYPE;}

{inteiro}                { printf("%s", yytext); yylval.iValue = atoi(yytext); return INT;}
{float}                  { printf("%s", yytext); yylval.real = atof(yytext); return FLOAT;}
{string}                 { printf("%s", yytext); yylval.str = strdup(yytext); return STRING;}
{boolean}                { printf("%s", yytext); yylval.str = strdup(yytext); return BOOL;}

{id}                     { printf("%s", yytext); yylval.str = strdup(yytext); return ID; }

{lexema_error}          {  printf("%s", yytext); 
                           // formatar mensagem de erro                      
                           char message[200] = "lexema '"; 
                           strcat(message, yytext); 
                           strcat(message, "' inválido!"); 
                           // armazenar na variavel de mensagem de erro
                           strcpy(error_message, message); 
                           // chamar funcao erro  
                           yyerror(message);
                        }  

<<EOF>>                 {
                            // se chegou no fim do arquivo:
                            printf("\n\n\033[1;32mPrograma sintaticamente correto.\033[0m\n\n");
                            return 0;
                        }                      
%%