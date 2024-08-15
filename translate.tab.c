/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "translate.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD/tabela-simbolos/tabelaSimbolos.h"

char* strdup(const char*);
double atof(const char*);
int atoi(const char*);

int yylex();

extern char *yytext; // para acessar o texto reconhecido pelo scanner/lex */
extern int yylineno; // contar as linhas

char error_message[200];   //construir mensagem de erro
void yyerror();            //imprimir erro


#line 91 "translate.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "translate.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TRIP = 3,                       /* TRIP  */
  YYSYMBOL_BAGAGEM = 4,                    /* BAGAGEM  */
  YYSYMBOL_EXTERIOR = 5,                   /* EXTERIOR  */
  YYSYMBOL_CHECKIN = 6,                    /* CHECKIN  */
  YYSYMBOL_CHECKOUT = 7,                   /* CHECKOUT  */
  YYSYMBOL_ALFANDEGA = 8,                  /* ALFANDEGA  */
  YYSYMBOL_ISENTO = 9,                     /* ISENTO  */
  YYSYMBOL_TRIBUTADO = 10,                 /* TRIBUTADO  */
  YYSYMBOL_ITINERARIO = 11,                /* ITINERARIO  */
  YYSYMBOL_ROTA = 12,                      /* ROTA  */
  YYSYMBOL_IMPREVISTO = 13,                /* IMPREVISTO  */
  YYSYMBOL_POUSAR = 14,                    /* POUSAR  */
  YYSYMBOL_FERIADO = 15,                   /* FERIADO  */
  YYSYMBOL_DECOLAR = 16,                   /* DECOLAR  */
  YYSYMBOL_ORIGEM = 17,                    /* ORIGEM  */
  YYSYMBOL_DESTINO = 18,                   /* DESTINO  */
  YYSYMBOL_ESCALA = 19,                    /* ESCALA  */
  YYSYMBOL_TURISTANDO = 20,                /* TURISTANDO  */
  YYSYMBOL_TURISTAR = 21,                  /* TURISTAR  */
  YYSYMBOL_DURANTE = 22,                   /* DURANTE  */
  YYSYMBOL_ROTEIRO = 23,                   /* ROTEIRO  */
  YYSYMBOL_EMBARCAR = 24,                  /* EMBARCAR  */
  YYSYMBOL_DESPACHAR = 25,                 /* DESPACHAR  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_DOT_COMMA = 27,                 /* DOT_COMMA  */
  YYSYMBOL_DOT = 28,                       /* DOT  */
  YYSYMBOL_COLON = 29,                     /* COLON  */
  YYSYMBOL_OPEN_PARENTHESES = 30,          /* OPEN_PARENTHESES  */
  YYSYMBOL_CLOSE_PARENTHESES = 31,         /* CLOSE_PARENTHESES  */
  YYSYMBOL_OPEN_BRACKET = 32,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 33,             /* CLOSE_BRACKET  */
  YYSYMBOL_OPEN_CODEBLOCK = 34,            /* OPEN_CODEBLOCK  */
  YYSYMBOL_CLOSE_CODEBLOCK = 35,           /* CLOSE_CODEBLOCK  */
  YYSYMBOL_ASSIGN = 36,                    /* ASSIGN  */
  YYSYMBOL_CONCAT = 37,                    /* CONCAT  */
  YYSYMBOL_TYPE = 38,                      /* TYPE  */
  YYSYMBOL_OP = 39,                        /* OP  */
  YYSYMBOL_RELOP = 40,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 41,                   /* LOGICOP  */
  YYSYMBOL_LOGICOP_UNARY = 42,             /* LOGICOP_UNARY  */
  YYSYMBOL_INT = 43,                       /* INT  */
  YYSYMBOL_FLOAT = 44,                     /* FLOAT  */
  YYSYMBOL_STRING = 45,                    /* STRING  */
  YYSYMBOL_BOOL = 46,                      /* BOOL  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_p = 49,                         /* p  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_consts = 51,                    /* consts  */
  YYSYMBOL_const = 52,                     /* const  */
  YYSYMBOL_variaveis = 53,                 /* variaveis  */
  YYSYMBOL_def_variavel = 54,              /* def_variavel  */
  YYSYMBOL_dec_variavel = 55,              /* dec_variavel  */
  YYSYMBOL_functions_header = 56,          /* functions_header  */
  YYSYMBOL_function_header = 57,           /* function_header  */
  YYSYMBOL_params_form = 58,               /* params_form  */
  YYSYMBOL_list_params_form = 59,          /* list_params_form  */
  YYSYMBOL_param_form = 60,                /* param_form  */
  YYSYMBOL_main = 61,                      /* main  */
  YYSYMBOL_functions = 62,                 /* functions  */
  YYSYMBOL_function = 63,                  /* function  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_operador = 65,                  /* operador  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_stmts = 67,                     /* stmts  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_for = 69,                       /* for  */
  YYSYMBOL_while = 70,                     /* while  */
  YYSYMBOL_if = 71,                        /* if  */
  YYSYMBOL_else = 72,                      /* else  */
  YYSYMBOL_command = 73,                   /* command  */
  YYSYMBOL_call_function = 74,             /* call_function  */
  YYSYMBOL_params_real = 75,               /* params_real  */
  YYSYMBOL_list_params_real = 76,          /* list_params_real  */
  YYSYMBOL_param_real = 77,                /* param_real  */
  YYSYMBOL_return = 78,                    /* return  */
  YYSYMBOL_atribuicao = 79,                /* atribuicao  */
  YYSYMBOL_ids = 80,                       /* ids  */
  YYSYMBOL_id_list = 81,                   /* id_list  */
  YYSYMBOL_id = 82,                        /* id  */
  YYSYMBOL_types = 83,                     /* types  */
  YYSYMBOL_type_list = 84,                 /* type_list  */
  YYSYMBOL_result_form = 85,               /* result_form  */
  YYSYMBOL_results = 86,                   /* results  */
  YYSYMBOL_result = 87                     /* result  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    69,    77,    78,    82,    86,    87,    88,
      92,    96,    99,   100,   104,   107,   108,   112,   113,   117,
     121,   125,   126,   130,   133,   134,   135,   136,   140,   141,
     142,   146,   147,   148,   149,   150,   151,   155,   156,   160,
     161,   162,   163,   167,   171,   174,   178,   179,   180,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   196,   199,
     200,   204,   205,   209,   213,   217,   221,   225,   226,   229,
     238,   242,   243,   247,   250,   251,   255,   256
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TRIP", "BAGAGEM",
  "EXTERIOR", "CHECKIN", "CHECKOUT", "ALFANDEGA", "ISENTO", "TRIBUTADO",
  "ITINERARIO", "ROTA", "IMPREVISTO", "POUSAR", "FERIADO", "DECOLAR",
  "ORIGEM", "DESTINO", "ESCALA", "TURISTANDO", "TURISTAR", "DURANTE",
  "ROTEIRO", "EMBARCAR", "DESPACHAR", "COMMA", "DOT_COMMA", "DOT", "COLON",
  "OPEN_PARENTHESES", "CLOSE_PARENTHESES", "OPEN_BRACKET", "CLOSE_BRACKET",
  "OPEN_CODEBLOCK", "CLOSE_CODEBLOCK", "ASSIGN", "CONCAT", "TYPE", "OP",
  "RELOP", "LOGICOP", "LOGICOP_UNARY", "INT", "FLOAT", "STRING", "BOOL",
  "ID", "$accept", "p", "$@1", "consts", "const", "variaveis",
  "def_variavel", "dec_variavel", "functions_header", "function_header",
  "params_form", "list_params_form", "param_form", "main", "functions",
  "function", "expr", "operador", "term", "stmts", "stmt", "for", "while",
  "if", "else", "command", "call_function", "params_real",
  "list_params_real", "param_real", "return", "atribuicao", "ids",
  "id_list", "id", "types", "type_list", "result_form", "results",
  "result", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -128,     9,  -128,  -128,    18,   -17,  -128,    27,   223,    -5,
    -128,  -128,    11,    -9,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,    -4,     4,  -128,  -128,    12,  -128,   -23,  -128,    14,
      23,    31,    56,  -128,    56,    29,    26,    20,    13,  -128,
      56,   -20,  -128,    28,  -128,   232,    -4,    33,    15,    32,
    -128,    35,    92,  -128,  -128,  -128,  -128,   223,  -128,    45,
    -128,  -128,   238,  -128,    38,    52,    20,  -128,  -128,    56,
      58,    60,    62,    55,    70,    66,    68,    56,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,    83,  -128,  -128,    78,    79,
      20,    87,  -128,    94,   -28,    56,  -128,  -128,   107,    56,
     237,    21,  -128,    56,    93,  -128,   101,    89,  -128,  -128,
     108,  -128,   252,   223,   264,  -128,   100,  -128,   248,  -128,
     238,  -128,   109,   114,   106,   110,   119,   113,   116,  -128,
    -128,   127,   133,  -128,   -28,   238,   143,   238,  -128,    69,
     122,    -4,  -128,  -128,   223,  -128,   125,  -128,   134,   105,
     138,   142,   136,   141,     5,   150,  -128,  -128,  -128,   144,
     145,  -128,   223,   238,   238,   152,  -128,  -128,   151,   166,
     190,   238,  -128,     5,  -128,  -128,   214,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,     9,     0,     4,    13,     0,     0,
       7,     8,     0,     0,    31,    32,    33,    34,    35,     6,
      36,     0,     0,    12,    22,     0,    69,     0,    68,     0,
       0,     3,    60,    11,     0,    66,     0,    16,     0,    21,
       0,    63,    26,     0,    62,     0,     0,     0,     0,     0,
      18,     0,     0,    28,    29,    30,    27,     0,    58,    59,
      10,    67,     0,    19,     0,    15,    16,    25,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      38,    39,    40,    41,    42,     0,    53,    51,     0,     0,
       0,     0,    61,     0,     0,     0,    56,    57,     0,     0,
       0,     0,    52,     0,     0,    17,     0,     0,    76,    77,
       0,    75,     0,     0,     0,    64,     0,    37,     0,    14,
       0,    72,     0,     0,    73,     0,     0,     0,     0,    65,
      38,    70,     0,    55,     0,     0,     0,     0,    20,     0,
       0,     0,    74,    38,     0,    38,     0,    71,     0,     0,
       0,     0,     0,     0,    48,     0,    44,    23,    54,     0,
       0,    45,     0,     0,     0,     0,    38,    38,     0,     0,
       0,     0,    46,    48,    38,    47,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,  -128,  -128,   168,   169,  -128,  -128,
     118,  -128,   -82,  -128,  -128,  -128,   -29,  -128,    -7,  -127,
     -56,  -128,  -128,  -128,    19,  -128,    -8,  -128,  -128,   124,
    -128,  -128,   -19,  -128,   149,  -128,  -128,  -128,  -128,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     6,     7,    78,    79,    12,    23,
      49,    65,    50,    24,    31,    39,    41,    57,    42,   101,
     117,    81,    82,    83,   161,    84,    85,    43,    59,    44,
      86,    87,    88,    35,    28,   122,   131,   110,   124,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    19,    27,   139,    33,    45,    80,    29,   105,     3,
      48,    52,   109,    34,   159,   160,   149,   108,   151,    53,
      54,    55,    56,     5,    20,     9,    20,    70,    71,    72,
       8,     9,    20,    21,    22,    73,    74,    75,    25,   169,
     170,    76,    32,    26,    36,    13,    77,   176,   100,    20,
      68,    30,   109,    37,    38,    46,   116,    47,    48,    58,
      51,    20,    63,    64,   130,    66,   112,    62,    26,    20,
     114,    69,    89,     9,   118,    70,    71,    72,    90,   143,
      13,   145,    96,    73,    74,    75,    40,    20,    93,    76,
      94,    20,    95,    13,    77,    20,    98,    97,    99,    14,
      15,    16,    17,    18,   146,    20,   126,   166,   167,     9,
     102,    70,    71,    72,   103,   174,    26,   104,   106,    73,
      74,    75,   148,    67,   113,    76,   107,   121,   119,    13,
      77,    53,    54,    55,    56,   120,    20,   150,   128,   123,
     154,   133,   132,   134,   135,   136,     9,   137,    70,    71,
      72,   138,    26,   140,    20,   165,    73,    74,    75,   141,
     147,   144,    76,   152,   155,   153,    13,    77,   158,   162,
       9,   157,    70,    71,    72,    10,    11,   156,   163,   164,
      73,    74,    75,   168,    91,   171,    76,   142,     0,    26,
      13,    77,   175,    92,     9,    61,    70,    71,    72,     0,
       0,   172,     0,     0,    73,    74,    75,     0,     0,     0,
      76,     0,     0,    26,    13,    77,     0,     0,     9,     0,
      70,    71,    72,     0,     0,   173,     0,     0,    73,    74,
      75,     0,     0,     0,    76,     0,     0,    26,    13,    77,
       0,     0,     9,     0,    70,    71,    72,    13,     0,   177,
       0,     0,    73,    74,    75,     0,     0,     0,    76,    60,
       0,    26,    13,    77,   115,     0,    14,    15,    16,    17,
      18,    53,    54,    55,    56,   129,    53,    54,    55,    56,
       0,     0,     0,   125,     0,    26,     0,    53,    54,    55,
      56,    53,    54,    55,    56,   127,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
       8,     8,    21,   130,    27,    34,    62,     3,    90,     0,
      38,    40,    94,    36,     9,    10,   143,    45,   145,    39,
      40,    41,    42,     5,    32,     4,    34,     6,     7,     8,
      47,     4,    40,    38,    23,    14,    15,    16,    47,   166,
     167,    20,    30,    47,    30,    24,    25,   174,    77,    57,
      57,    47,   134,    30,    23,    26,    35,    31,    38,    31,
      47,    69,    47,    31,   120,    30,    95,    34,    47,    77,
      99,    26,    34,     4,   103,     6,     7,     8,    26,   135,
      24,   137,    27,    14,    15,    16,    30,    95,    30,    20,
      30,    99,    30,    24,    25,   103,    30,    27,    30,    43,
      44,    45,    46,    47,    35,   113,   113,   163,   164,     4,
      27,     6,     7,     8,    36,   171,    47,    38,    31,    14,
      15,    16,   141,    31,    17,    20,    32,    38,    35,    24,
      25,    39,    40,    41,    42,    34,   144,   144,    38,    31,
      35,    27,    33,    37,    34,    26,     4,    34,     6,     7,
       8,    35,    47,    26,   162,   162,    14,    15,    16,    26,
      38,    18,    20,    38,    26,    31,    24,    25,    27,    19,
       4,    35,     6,     7,     8,     7,     7,    35,    34,    34,
      14,    15,    16,    31,    66,    34,    20,   134,    -1,    47,
      24,    25,   173,    69,     4,    46,     6,     7,     8,    -1,
      -1,    35,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,
      20,    -1,    -1,    47,    24,    25,    -1,    -1,     4,    -1,
       6,     7,     8,    -1,    -1,    35,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    20,    -1,    -1,    47,    24,    25,
      -1,    -1,     4,    -1,     6,     7,     8,    24,    -1,    35,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,    27,
      -1,    47,    24,    25,    27,    -1,    43,    44,    45,    46,
      47,    39,    40,    41,    42,    27,    39,    40,    41,    42,
      -1,    -1,    -1,    31,    -1,    47,    -1,    39,    40,    41,
      42,    39,    40,    41,    42,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,    51,     5,    52,    53,    47,     4,
      54,    55,    56,    24,    43,    44,    45,    46,    47,    66,
      74,    38,    23,    57,    61,    47,    47,    80,    82,     3,
      47,    62,    30,    27,    36,    81,    30,    30,    23,    63,
      30,    64,    66,    75,    77,    64,    26,    31,    38,    58,
      60,    47,    64,    39,    40,    41,    42,    65,    31,    76,
      27,    82,    34,    47,    31,    59,    30,    31,    66,    26,
       6,     7,     8,    14,    15,    16,    20,    25,    54,    55,
      68,    69,    70,    71,    73,    74,    78,    79,    80,    34,
      26,    58,    77,    30,    30,    30,    27,    27,    30,    30,
      64,    67,    27,    36,    38,    60,    31,    32,    45,    60,
      85,    87,    64,    17,    64,    27,    35,    68,    64,    35,
      34,    38,    83,    31,    86,    31,    66,    31,    38,    27,
      68,    84,    33,    27,    37,    34,    26,    34,    35,    67,
      26,    26,    87,    68,    18,    68,    35,    38,    80,    67,
      66,    67,    38,    31,    35,    26,    35,    35,    27,     9,
      10,    72,    19,    34,    34,    66,    68,    68,    31,    67,
      67,    34,    35,    35,    68,    72,    67,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    49,    51,    51,    52,    53,    53,    53,
      54,    55,    56,    56,    57,    58,    58,    59,    59,    60,
      61,    62,    62,    63,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    68,    68,    69,    70,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    76,    76,    77,    78,    79,    80,    81,    81,    82,
      83,    84,    84,    85,    86,    86,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     3,     2,     2,     0,
       6,     4,     2,     0,     8,     2,     0,     3,     0,     2,
      10,     2,     0,    11,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     1,     1,    15,     8,     9,     5,     6,     0,     1,
       1,     1,     2,     1,     9,     5,     2,     2,     5,     2,
       0,     3,     0,     1,     3,     4,     2,     3,     0,     1,
       2,     3,     0,     2,     3,     0,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 69 "translate.y"
    { inicializar_tabela(50);    //inicializar tabela de simbolos global 

      printf("%d\t", yylineno++); //inicializa contagem linhas do arquivo
    }
#line 1311 "translate.tab.c"
    break;

  case 31: /* term: INT  */
#line 146 "translate.y"
        {printf("int %d", (yyvsp[0].iValue)); }
#line 1317 "translate.tab.c"
    break;

  case 33: /* term: STRING  */
#line 148 "translate.y"
             {printf("string %s", (yyvsp[0].str)); }
#line 1323 "translate.tab.c"
    break;

  case 69: /* id: ID  */
#line 229 "translate.y"
        { Simbolo identificador;
          printf("identificador %s", (yyvsp[0].str));
          identificador.nome = strdup((yyvsp[0].str));  
          printf("identificador %s", identificador.nome);
          adicionar_simbolo(identificador);
         }
#line 1334 "translate.tab.c"
    break;


#line 1338 "translate.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 259 "translate.y"


void yyerror() {
    // printar mensagem de erro na cor vermelha
    fprintf(stderr, "\n\033[1;31mErro de sintaxe próximo à linha %d: %s\033[0m\n\n", yylineno-1, error_message);
     
    printf("\n\n\033[1;31mPrograma sintaticamente incorreto.\033[0m\n\n");

    // encerrar analise prematuramente:
    exit(0);
}

int main(void) {
    yyparse();     
    imprimir_tabela_simbolos();
    return 0;
}
