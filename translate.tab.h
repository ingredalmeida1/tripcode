/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TRANSLATE_TAB_H_INCLUDED
# define YY_YY_TRANSLATE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 13 "translate.y"

     #include "TADs/SymbolTable.h" 

#line 53 "translate.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CAMBIO = 258,                  /* CAMBIO  */
    COTACAO = 259,                 /* COTACAO  */
    CLASSE = 260,                  /* CLASSE  */
    ALFANDEGA = 261,               /* ALFANDEGA  */
    ISENTO = 262,                  /* ISENTO  */
    TRIBUTADO = 263,               /* TRIBUTADO  */
    CHECKOUT = 264,                /* CHECKOUT  */
    CHECKIN = 265,                 /* CHECKIN  */
    ITINERARIO = 266,              /* ITINERARIO  */
    ROTA = 267,                    /* ROTA  */
    POUSAR = 268,                  /* POUSAR  */
    IMPREVISTO = 269,              /* IMPREVISTO  */
    DESCANSAR = 270,               /* DESCANSAR  */
    TRABALHAR = 271,               /* TRABALHAR  */
    ROTEIRO = 272,                 /* ROTEIRO  */
    EMBARCAR = 273,                /* EMBARCAR  */
    DESPACHAR = 274,               /* DESPACHAR  */
    DECOLAR = 275,                 /* DECOLAR  */
    ORIGEM = 276,                  /* ORIGEM  */
    DESTINO = 277,                 /* DESTINO  */
    ESCALA = 278,                  /* ESCALA  */
    TURISTANDO = 279,              /* TURISTANDO  */
    TURISTAR = 280,                /* TURISTAR  */
    DURANTE = 281,                 /* DURANTE  */
    MAPA = 282,                    /* MAPA  */
    PASSAPORTE = 283,              /* PASSAPORTE  */
    BAGAGEM = 284,                 /* BAGAGEM  */
    MILHAS = 285,                  /* MILHAS  */
    DOLAR = 286,                   /* DOLAR  */
    VOUCHER = 287,                 /* VOUCHER  */
    TRIP = 288,                    /* TRIP  */
    STATUS = 289,                  /* STATUS  */
    EXTERIOR = 290,                /* EXTERIOR  */
    FERIAS = 291,                  /* FERIAS  */
    DIAUTIL = 292,                 /* DIAUTIL  */
    FERIADO = 293,                 /* FERIADO  */
    COMMA = 294,                   /* COMMA  */
    DOT_COMMA = 295,               /* DOT_COMMA  */
    DOT = 296,                     /* DOT  */
    OPEN_PARENTHESES = 297,        /* OPEN_PARENTHESES  */
    CLOSE_PARENTHESES = 298,       /* CLOSE_PARENTHESES  */
    OPEN_BRACKET = 299,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 300,           /* CLOSE_BRACKET  */
    OPEN_CODEBLOCK = 301,          /* OPEN_CODEBLOCK  */
    CLOSE_CODEBLOCK = 302,         /* CLOSE_CODEBLOCK  */
    ATRIBUICAO = 303,              /* ATRIBUICAO  */
    OP = 304,                      /* OP  */
    RELOP = 305,                   /* RELOP  */
    LOGICOP = 306,                 /* LOGICOP  */
    FLOAT = 307,                   /* FLOAT  */
    STRING = 308,                  /* STRING  */
    INTEIRO = 309,                 /* INTEIRO  */
    ID = 310                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "translate.y"

    char *str;
    int iValue;
    float real;

#line 131 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
