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


%% 
{ws}		         {}
{comment}            { /* Ignora comentários */ }

{cambio}                 { return CAMBIO; }
{cotacao}                { return COTACAO; }
{classe}                 { return CLASSE; }
{alfandega}              { return ALFANDEGA; }
{isento}                 { return ISENTO; }
{tributado}              { return TRIBUTADO; }
{checkout}               { return CHECKOUT; }
{checkin}                { return CHECKIN; }
{itinerario}             { return ITINERARIO; }
{rota}                   { return ROTA; }
{pousar}                 { return POUSAR; }
{imprevisto}             { return IMPREVISTO; }
{descansar}              { return DESCANSAR; }
{trabalhar}              { return TRABALHAR; }
{roteiro}                { return ROTEIRO; }
{embarcar}               { return EMBARCAR; }
{despachar}              { return DESPACHAR; }
{decolar}                { return DECOLAR; }
{origem}                 { return ORIGEM; }
{destino}                { return DESTINO; }
{escala}                 { return ESCALA; }
{turistando}             { return TURISTANDO; }
{turistar}               { return TURISTAR; }
{durante}                { return DURANTE; }
{mapa}                   { return MAPA; }
{passaporte}             { return PASSAPORTE; }
{bagagem}                { return BAGAGEM; }
{milhas}                 { return MILHAS; }
{dolar}                  { return DOLAR; }
{voucher}                { return VOUCHER; }
{trip}                   { return TRIP; }
{status}                 { return STATUS; }
{exterior}               { return EXTERIOR; }
{ferias}                 { return FERIAS; }
{diautil}                { return DIAUTIL; }
{feriado}                { return FERIADO; }


{comma}              { return COMMA; }
{dot_comma}          { return DOT_COMMA; }
{dot}                { return DOT; }
{open_parentheses}   { return OPEN_PARENTHESES; }
{close_parentheses}  { return CLOSE_PARENTHESES; }
{open_bracket}       { return OPEN_BRACKET; }
{close_bracket}      { return CLOSE_BRACKET; }
{open_codeblock}     { return OPEN_CODEBLOCK; }
{close_codeblock}    { return CLOSE_CODEBLOCK; }

{atribuicao}         { return ATRIBUICAO; }

{relop}              { yylval.str = strdup(yytext); return RELOP; }
{logicop}            { yylval.str = strdup(yytext); return LOGICOP; }
{op}                 { yylval.str = strdup(yytext); return OP; }

{inteiro}            { yylval.iValue = atoi(yytext); return INTEIRO; }
{float}              { yylval.real = atof(yytext); return DECIMAL; }
{string}             { yylval.str = strdup(yytext); return STRING; }

{id}                 { yylval.str = strdup(yytext); return ID; }

{lexema_error}        {char message[200] = "Lexema inválido: '"; strcat(message, yytext); strcat(message, "'"); strcpy(error_message, message); yyerror(message);}

%% 
int main(void) 
{ 
    yylex(); 
    return 0; 
}