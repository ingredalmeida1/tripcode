%{ 
/* cabecalho C */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

%} 
%option noyywrap

/* definicoes regulares */
delim		[ \t\n] 
ws		    {delim}+
comment     ->[^<]*<-
atribuicao  <->
eq          =
gt          >
ge          >=
lt          <
le          <=
diff        #
relop       [{eq}0{gt}|{ge}|{lt}|{le}|{diff}]


%% 
{comment}        {}
{ws}		     {}
{atribuicao}     { printf("Foi encontrado um TOKEN atribuição. LEXEMA: %s\n", yytext); }
{relop}          { printf("Foi encontrado um TOKEN operador relacional: %s\n", yytext); }


%% 
int main(void) 
{ 
    yylex(); 
    return 0; 
}