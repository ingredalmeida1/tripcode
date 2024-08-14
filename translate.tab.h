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
    ITINERARIO = 266,              /* ITINERARIO  */
    ROTA = 267,                    /* ROTA  */
    IMPREVISTO = 268,              /* IMPREVISTO  */
    POUSAR = 269,                  /* POUSAR  */
    FERIADO = 270,                 /* FERIADO  */
    DECOLAR = 271,                 /* DECOLAR  */
    ORIGEM = 272,                  /* ORIGEM  */
    DESTINO = 273,                 /* DESTINO  */
    ESCALA = 274,                  /* ESCALA  */
    TURISTANDO = 275,              /* TURISTANDO  */
    TURISTAR = 276,                /* TURISTAR  */
    DURANTE = 277,                 /* DURANTE  */
    ROTEIRO = 278,                 /* ROTEIRO  */
    EMBARCAR = 279,                /* EMBARCAR  */
    DESPACHAR = 280,               /* DESPACHAR  */
    COMMA = 281,                   /* COMMA  */
    DOT_COMMA = 282,               /* DOT_COMMA  */
    DOT = 283,                     /* DOT  */
    COLON = 284,                   /* COLON  */
    OPEN_PARENTHESES = 285,        /* OPEN_PARENTHESES  */
    CLOSE_PARENTHESES = 286,       /* CLOSE_PARENTHESES  */
    OPEN_BRACKET = 287,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 288,           /* CLOSE_BRACKET  */
    OPEN_CODEBLOCK = 289,          /* OPEN_CODEBLOCK  */
    CLOSE_CODEBLOCK = 290,         /* CLOSE_CODEBLOCK  */
    ASSIGN = 291,                  /* ASSIGN  */
    TYPE = 292,                    /* TYPE  */
    OP = 293,                      /* OP  */
    RELOP = 294,                   /* RELOP  */
    LOGICOP = 295,                 /* LOGICOP  */
    LOGICOP_UNARY = 296,           /* LOGICOP_UNARY  */
    INT = 297,                     /* INT  */
    FLOAT = 298,                   /* FLOAT  */
    STRING = 299,                  /* STRING  */
    BOOL = 300,                    /* BOOL  */
    ID = 301                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "translate.y"

    char *str;
    int iValue;
    float real;

#line 116 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
