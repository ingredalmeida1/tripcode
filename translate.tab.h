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
#line 30 "translate.y"

     #include "TAD/TabelaSimbolos.h"

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
    TRIP = 258,                    /* TRIP  */
    BAGAGEM = 259,                 /* BAGAGEM  */
    EXTERIOR = 260,                /* EXTERIOR  */
    CHECKIN = 261,                 /* CHECKIN  */
    CHECKOUT = 262,                /* CHECKOUT  */
    ALFANDEGA = 263,               /* ALFANDEGA  */
    ISENTO = 264,                  /* ISENTO  */
    TRIBUTADO = 265,               /* TRIBUTADO  */
    POUSAR = 266,                  /* POUSAR  */
    FERIADO = 267,                 /* FERIADO  */
    DECOLAR = 268,                 /* DECOLAR  */
    ORIGEM = 269,                  /* ORIGEM  */
    DESTINO = 270,                 /* DESTINO  */
    ESCALA = 271,                  /* ESCALA  */
    TURISTANDO = 272,              /* TURISTANDO  */
    ROTEIRO = 273,                 /* ROTEIRO  */
    EMBARCAR = 274,                /* EMBARCAR  */
    DESPACHAR = 275,               /* DESPACHAR  */
    COMMA = 276,                   /* COMMA  */
    DOT_COMMA = 277,               /* DOT_COMMA  */
    DOT = 278,                     /* DOT  */
    COLON = 279,                   /* COLON  */
    OPEN_PARENTHESES = 280,        /* OPEN_PARENTHESES  */
    CLOSE_PARENTHESES = 281,       /* CLOSE_PARENTHESES  */
    OPEN_BRACKET = 282,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 283,           /* CLOSE_BRACKET  */
    OPEN_CODEBLOCK = 284,          /* OPEN_CODEBLOCK  */
    CLOSE_CODEBLOCK = 285,         /* CLOSE_CODEBLOCK  */
    ASSIGN = 286,                  /* ASSIGN  */
    CONCAT = 287,                  /* CONCAT  */
    TYPE = 288,                    /* TYPE  */
    INT = 289,                     /* INT  */
    FLOAT = 290,                   /* FLOAT  */
    STRING = 291,                  /* STRING  */
    BOOL = 292,                    /* BOOL  */
    ID = 293,                      /* ID  */
    OP = 294,                      /* OP  */
    RELOP = 295,                   /* RELOP  */
    LOGICOP = 296,                 /* LOGICOP  */
    LOGICOP_UNARY = 297            /* LOGICOP_UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "translate.y"

    int inteiro;
    float real;
    char *string;

#line 118 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
