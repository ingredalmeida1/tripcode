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
#line 4 "translate.y"

/*----------------------------------------------------------------------------------------------------
        Bibliotecas C, codigos C e Definicoes de Tokens 
----------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "TAD/TabelaSimbolos.h"

TabelaSimbolos** tabelas_simbolos = NULL; //armazenar todas as tabelas de simbolos pra poder printar
int numero_de_tabelas = 0;

TabelaSimbolos* escopo_atual = NULL;

//variavel para armazenar ponteiro para a tabela de simbolos do bloco atual

int yylex();

char* strdup(const char*);
double atof(const char*);
int atoi(const char*);

extern int yylineno;          // contar as linhas

char msg_erro[200];           //construir mensagem de erro

void yyerror();               // reportar erros


#line 102 "translate.tab.c"

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
  YYSYMBOL_POUSAR = 11,                    /* POUSAR  */
  YYSYMBOL_FERIADO = 12,                   /* FERIADO  */
  YYSYMBOL_DECOLAR = 13,                   /* DECOLAR  */
  YYSYMBOL_ORIGEM = 14,                    /* ORIGEM  */
  YYSYMBOL_DESTINO = 15,                   /* DESTINO  */
  YYSYMBOL_ESCALA = 16,                    /* ESCALA  */
  YYSYMBOL_TURISTANDO = 17,                /* TURISTANDO  */
  YYSYMBOL_ROTEIRO = 18,                   /* ROTEIRO  */
  YYSYMBOL_EMBARCAR = 19,                  /* EMBARCAR  */
  YYSYMBOL_DESPACHAR = 20,                 /* DESPACHAR  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_DOT_COMMA = 22,                 /* DOT_COMMA  */
  YYSYMBOL_DOT = 23,                       /* DOT  */
  YYSYMBOL_COLON = 24,                     /* COLON  */
  YYSYMBOL_OPEN_PARENTHESES = 25,          /* OPEN_PARENTHESES  */
  YYSYMBOL_CLOSE_PARENTHESES = 26,         /* CLOSE_PARENTHESES  */
  YYSYMBOL_OPEN_BRACKET = 27,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 28,             /* CLOSE_BRACKET  */
  YYSYMBOL_OPEN_CODEBLOCK = 29,            /* OPEN_CODEBLOCK  */
  YYSYMBOL_CLOSE_CODEBLOCK = 30,           /* CLOSE_CODEBLOCK  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_CONCAT = 32,                    /* CONCAT  */
  YYSYMBOL_TYPE = 33,                      /* TYPE  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_STRING = 36,                    /* STRING  */
  YYSYMBOL_BOOL = 37,                      /* BOOL  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_OP = 39,                        /* OP  */
  YYSYMBOL_RELOP = 40,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 41,                   /* LOGICOP  */
  YYSYMBOL_LOGICOP_UNARY = 42,             /* LOGICOP_UNARY  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_p = 44,                         /* p  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_consts = 46,                    /* consts  */
  YYSYMBOL_const = 47,                     /* const  */
  YYSYMBOL_variaveis = 48,                 /* variaveis  */
  YYSYMBOL_def_variavel = 49,              /* def_variavel  */
  YYSYMBOL_dec_variavel = 50,              /* dec_variavel  */
  YYSYMBOL_functions_header = 51,          /* functions_header  */
  YYSYMBOL_function_header = 52,           /* function_header  */
  YYSYMBOL_params_form = 53,               /* params_form  */
  YYSYMBOL_list_params_form = 54,          /* list_params_form  */
  YYSYMBOL_param_form = 55,                /* param_form  */
  YYSYMBOL_main = 56,                      /* main  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_functions = 58,                 /* functions  */
  YYSYMBOL_function = 59,                  /* function  */
  YYSYMBOL_expr = 60,                      /* expr  */
  YYSYMBOL_operador = 61,                  /* operador  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_stmts = 63,                     /* stmts  */
  YYSYMBOL_stmt = 64,                      /* stmt  */
  YYSYMBOL_for = 65,                       /* for  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_while = 67,                     /* while  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_if = 69,                        /* if  */
  YYSYMBOL_70_5 = 70,                      /* $@5  */
  YYSYMBOL_71_6 = 71,                      /* $@6  */
  YYSYMBOL_else = 72,                      /* else  */
  YYSYMBOL_73_7 = 73,                      /* $@7  */
  YYSYMBOL_74_8 = 74,                      /* $@8  */
  YYSYMBOL_75_9 = 75,                      /* $@9  */
  YYSYMBOL_command = 76,                   /* command  */
  YYSYMBOL_call_function = 77,             /* call_function  */
  YYSYMBOL_params_real = 78,               /* params_real  */
  YYSYMBOL_list_params_real = 79,          /* list_params_real  */
  YYSYMBOL_param_real = 80,                /* param_real  */
  YYSYMBOL_return = 81,                    /* return  */
  YYSYMBOL_atribuicao = 82,                /* atribuicao  */
  YYSYMBOL_ids = 83,                       /* ids  */
  YYSYMBOL_id_list = 84,                   /* id_list  */
  YYSYMBOL_id = 85,                        /* id  */
  YYSYMBOL_types = 86,                     /* types  */
  YYSYMBOL_type_list = 87,                 /* type_list  */
  YYSYMBOL_result_form = 88,               /* result_form  */
  YYSYMBOL_results = 89,                   /* results  */
  YYSYMBOL_result = 90                     /* result  */
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
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   122,   122,   122,   138,   139,   143,   150,   151,   152,
     156,   163,   170,   171,   175,   182,   183,   187,   188,   192,
     197,   196,   213,   214,   218,   221,   222,   223,   224,   228,
     229,   230,   234,   235,   236,   237,   238,   239,   243,   244,
     248,   249,   250,   251,   256,   255,   274,   273,   290,   299,
     289,   308,   307,   323,   332,   322,   337,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   353,   356,   357,   361,
     362,   366,   370,   374,   378,   382,   383,   386,   392,   396,
     397,   401,   404,   405,   409,   410
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
  "POUSAR", "FERIADO", "DECOLAR", "ORIGEM", "DESTINO", "ESCALA",
  "TURISTANDO", "ROTEIRO", "EMBARCAR", "DESPACHAR", "COMMA", "DOT_COMMA",
  "DOT", "COLON", "OPEN_PARENTHESES", "CLOSE_PARENTHESES", "OPEN_BRACKET",
  "CLOSE_BRACKET", "OPEN_CODEBLOCK", "CLOSE_CODEBLOCK", "ASSIGN", "CONCAT",
  "TYPE", "INT", "FLOAT", "STRING", "BOOL", "ID", "OP", "RELOP", "LOGICOP",
  "LOGICOP_UNARY", "$accept", "p", "$@1", "consts", "const", "variaveis",
  "def_variavel", "dec_variavel", "functions_header", "function_header",
  "params_form", "list_params_form", "param_form", "main", "$@2",
  "functions", "function", "expr", "operador", "term", "stmts", "stmt",
  "for", "$@3", "while", "$@4", "if", "$@5", "$@6", "else", "$@7", "$@8",
  "$@9", "command", "call_function", "params_real", "list_params_real",
  "param_real", "return", "atribuicao", "ids", "id_list", "id", "types",
  "type_list", "result_form", "results", "result", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -115,    16,  -115,  -115,    22,   -10,  -115,    26,   214,    -2,
    -115,  -115,    14,    -1,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,     0,     2,  -115,  -115,    17,   -16,    18,    23,    21,
     207,  -115,   207,    24,    25,     9,  -115,   207,   231,  -115,
      31,  -115,    13,    30,    27,    38,  -115,    42,    34,  -115,
    -115,  -115,  -115,   214,  -115,    47,  -115,  -115,  -115,    49,
      64,    25,  -115,  -115,   207,     6,    58,    25,    68,  -115,
      72,    77,    80,    29,    85,    83,    87,   207,    88,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,   101,  -115,  -115,    94,
    -115,    98,   103,   -25,   207,  -115,  -115,   111,   207,    59,
     207,    76,  -115,  -115,     6,    99,  -115,  -115,   105,  -115,
     220,   214,   227,  -115,    96,   107,  -115,  -115,  -115,   114,
     124,   119,   126,   138,   129,  -115,   130,   109,   141,   145,
    -115,   -25,  -115,   156,  -115,  -115,   139,   140,   142,  -115,
       6,   214,     6,   148,  -115,  -115,   153,  -115,  -115,   161,
    -115,  -115,   164,   170,   137,   176,   157,  -115,   142,  -115,
     214,  -115,  -115,    11,   167,   169,   171,  -115,   173,  -115,
    -115,  -115,     6,     6,     6,  -115,  -115,  -115,   177,   197,
     217,  -115,  -115,  -115,    11,  -115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,     9,     0,     4,    13,     0,     0,
       7,     8,     0,     0,    32,    33,    34,    35,    36,     6,
      37,     0,     0,    12,    23,     0,     0,     0,     0,     3,
      68,    11,     0,     0,    16,     0,    22,     0,    71,    27,
       0,    70,     0,     0,     0,     0,    18,     0,     0,    29,
      30,    31,    28,     0,    66,    67,    10,    20,    19,     0,
      15,    16,    26,    25,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    39,    40,    41,    42,    43,     0,    61,    59,     0,
      17,     0,     0,     0,     0,    64,    65,     0,     0,     0,
       0,     0,    60,    14,     0,     0,    84,    85,     0,    83,
       0,     0,     0,    72,     0,     0,    38,    39,    80,     0,
       0,    81,     0,     0,     0,    73,     0,     0,    78,     0,
      63,     0,    48,     0,    46,    21,     0,     0,     0,    82,
       0,     0,     0,     0,    79,    77,     0,    76,    39,     0,
      39,    24,     0,    74,     0,     0,     0,    62,     0,    49,
       0,    47,    75,    56,     0,     0,     0,    50,     0,    51,
      53,    44,     0,     0,     0,    39,    39,    39,     0,     0,
       0,    52,    54,    45,    56,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,  -115,  -115,   192,   199,  -115,  -115,
     150,  -115,   -60,  -115,  -115,  -115,  -115,   -28,  -115,    -7,
    -114,   -63,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    28,
    -115,  -115,  -115,  -115,    -8,  -115,  -115,   149,  -115,  -115,
    -115,  -115,    60,  -115,  -115,  -115,  -115,    89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     6,     7,    79,    80,    12,    23,
      45,    60,    46,    24,    65,    29,    36,    38,    53,    39,
     101,   116,    82,   174,    83,   142,    84,   140,   163,   167,
     172,   173,   184,    85,    86,    40,    55,    41,    87,    88,
     146,   153,   147,   119,   128,   108,   121,   109
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    19,    81,   127,    42,    27,    31,    90,    44,    48,
       9,   106,    70,    71,    72,    32,     3,    73,    74,    75,
     165,   166,    20,    76,    20,    13,    77,     5,     8,    20,
       9,    21,    22,   107,   154,    56,   156,    25,    26,    35,
      28,   117,    30,    33,    78,    20,    63,    47,    34,    99,
      43,    95,    49,    50,    51,    52,    20,    54,    44,    57,
      62,   178,   179,   180,    59,    58,   110,    61,    64,    20,
     112,   107,   114,    49,    50,    51,    52,   148,    66,   150,
       9,   113,    70,    71,    72,    67,    20,    73,    74,    75,
      20,    89,    20,    76,    91,    13,    77,    92,    49,    50,
      51,    52,    93,    20,   123,    94,   115,    96,    97,   175,
     176,   177,    98,     9,    78,    70,    71,    72,   125,   100,
      73,    74,    75,   102,   103,   111,    76,   104,    13,    77,
     105,   120,   118,    20,   149,    49,    50,    51,    52,   136,
     126,     9,   129,    70,    71,    72,   130,    78,    73,    74,
      75,   131,    20,   164,    76,   132,    13,    77,   134,   133,
     135,     9,   137,    70,    71,    72,   138,   159,    73,    74,
      75,   141,   143,   144,    76,    78,    13,    77,   151,   152,
     145,     9,   155,    70,    71,    72,   157,   161,    73,    74,
      75,   158,   160,   168,    76,    78,    13,    77,   169,    10,
     170,     9,   171,    70,    71,    72,    11,   181,    73,    74,
      75,    68,   185,    69,    76,    78,    13,    77,   162,     0,
     139,     9,     0,    70,    71,    72,    13,   182,    73,    74,
      75,     0,    37,    13,    76,    78,    13,    77,     0,     0,
       0,    14,    15,    16,    17,    18,   122,   183,    14,    15,
      16,    17,    18,   124,     0,    78,     0,     0,     0,    49,
      50,    51,    52,     0,     0,     0,    49,    50,    51,    52,
      49,    50,    51,    52
};

static const yytype_int16 yycheck[] =
{
       8,     8,    65,   117,    32,     3,    22,    67,    33,    37,
       4,    36,     6,     7,     8,    31,     0,    11,    12,    13,
       9,    10,    30,    17,    32,    19,    20,     5,    38,    37,
       4,    33,    18,    93,   148,    22,   150,    38,    38,    18,
      38,   104,    25,    25,    38,    53,    53,    38,    25,    77,
      26,    22,    39,    40,    41,    42,    64,    26,    33,    29,
      26,   175,   176,   177,    26,    38,    94,    25,    21,    77,
      98,   131,   100,    39,    40,    41,    42,   140,    29,   142,
       4,    22,     6,     7,     8,    21,    94,    11,    12,    13,
      98,    33,   100,    17,    26,    19,    20,    25,    39,    40,
      41,    42,    25,   111,   111,    25,    30,    22,    25,   172,
     173,   174,    25,     4,    38,     6,     7,     8,    22,    31,
      11,    12,    13,    22,    30,    14,    17,    29,    19,    20,
      27,    26,    33,   141,   141,    39,    40,    41,    42,    30,
      33,     4,    28,     6,     7,     8,    22,    38,    11,    12,
      13,    32,   160,   160,    17,    29,    19,    20,    29,    21,
      30,     4,    21,     6,     7,     8,    21,    30,    11,    12,
      13,    15,    33,    33,    17,    38,    19,    20,    30,    26,
      38,     4,    21,     6,     7,     8,    22,    30,    11,    12,
      13,    21,    16,    26,    17,    38,    19,    20,    29,     7,
      29,     4,    29,     6,     7,     8,     7,    30,    11,    12,
      13,    61,   184,    64,    17,    38,    19,    20,   158,    -1,
     131,     4,    -1,     6,     7,     8,    19,    30,    11,    12,
      13,    -1,    25,    19,    17,    38,    19,    20,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    26,    30,    34,    35,
      36,    37,    38,    26,    -1,    38,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    39,    40,    41,    42,
      39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,    46,     5,    47,    48,    38,     4,
      49,    50,    51,    19,    34,    35,    36,    37,    38,    62,
      77,    33,    18,    52,    56,    38,    38,     3,    38,    58,
      25,    22,    31,    25,    25,    18,    59,    25,    60,    62,
      78,    80,    60,    26,    33,    53,    55,    38,    60,    39,
      40,    41,    42,    61,    26,    79,    22,    29,    38,    26,
      54,    25,    26,    62,    21,    57,    29,    21,    53,    80,
       6,     7,     8,    11,    12,    13,    17,    20,    38,    49,
      50,    64,    65,    67,    69,    76,    77,    81,    82,    33,
      55,    26,    25,    25,    25,    22,    22,    25,    25,    60,
      31,    63,    22,    30,    29,    27,    36,    55,    88,    90,
      60,    14,    60,    22,    60,    30,    64,    64,    33,    86,
      26,    89,    26,    62,    26,    22,    33,    63,    87,    28,
      22,    32,    29,    21,    29,    30,    30,    21,    21,    90,
      70,    15,    68,    33,    33,    38,    83,    85,    64,    62,
      64,    30,    26,    84,    63,    21,    63,    22,    21,    30,
      16,    30,    85,    71,    62,     9,    10,    72,    26,    29,
      29,    29,    73,    74,    66,    64,    64,    64,    63,    63,
      63,    30,    30,    30,    75,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    48,    48,    48,
      49,    50,    51,    51,    52,    53,    53,    54,    54,    55,
      57,    56,    58,    58,    59,    60,    60,    60,    60,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    66,    65,    68,    67,    70,    71,
      69,    73,    72,    74,    75,    72,    72,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    79,
      79,    80,    81,    82,    83,    84,    84,    85,    86,    87,
      87,    88,    89,    89,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     3,     2,     2,     0,
       6,     4,     2,     0,     8,     2,     0,     3,     0,     2,
       0,    11,     2,     0,    11,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       1,     1,     1,     1,     0,    16,     0,     9,     0,     0,
      11,     0,     6,     0,     0,     8,     0,     1,     1,     1,
       2,     1,     9,     5,     2,     2,     5,     2,     0,     3,
       0,     1,     3,     4,     2,     3,     0,     1,     2,     3,
       0,     2,     3,     0,     1,     1
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
#line 122 "translate.y"
    { //inicializar tabela de simbolos global 
      inicializar_tabela(&escopo_atual, NULL, "GLOBAL");  

      //inicializar lista para armazenar todas as tabelas de simbolos     
      tabelas_simbolos = (TabelaSimbolos**) malloc(100 * sizeof(TabelaSimbolos*));
     
      //adicionar nova tabela na lista de tabelas
      adicionar_nova_tabela(&tabelas_simbolos, escopo_atual, &numero_de_tabelas);

      printf("%d\t", yylineno++); //inicializa contagem linhas do arquivo
    }
#line 1332 "translate.tab.c"
    break;

  case 6: /* const: EXTERIOR ID term  */
#line 144 "translate.y"
     {
        adicionar_simbolo(&escopo_atual, "CONSTANTE", (yyvsp[-1].string), "-");
     }
#line 1340 "translate.tab.c"
    break;

  case 10: /* def_variavel: BAGAGEM TYPE ID ASSIGN expr DOT_COMMA  */
#line 156 "translate.y"
                                          {
                                               // inserir na tabela de simbolos do escopo atual o valor do identificador($3) e seu tipo($2)  [o valor só vai ser armazenado proxima etapa do trabalho]
                                               adicionar_simbolo(&escopo_atual, (yyvsp[-4].string), (yyvsp[-3].string), "-");
                                           }
#line 1349 "translate.tab.c"
    break;

  case 11: /* dec_variavel: BAGAGEM TYPE ID DOT_COMMA  */
#line 163 "translate.y"
                              {
                                               // inserir na tabela de simbolos do escopo atual o valor do identificador($3) e seu tipo($2)  [o valor só vai ser armazenado proxima etapa do trabalho]
                                               adicionar_simbolo(&escopo_atual, (yyvsp[-2].string), (yyvsp[-1].string), "-");
                                           }
#line 1358 "translate.tab.c"
    break;

  case 14: /* function_header: ROTEIRO ID OPEN_PARENTHESES params_form CLOSE_PARENTHESES OPEN_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 176 "translate.y"
    {
        adicionar_simbolo(&escopo_atual, "FUNCAO", (yyvsp[-6].string), (yyvsp[-1].string));
    }
#line 1366 "translate.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 197 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "MAIN");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1379 "translate.tab.c"
    break;

  case 21: /* main: ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK $@2 stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 206 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1388 "translate.tab.c"
    break;

  case 44: /* $@3: %empty  */
#line 256 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "DECOLAR");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1401 "translate.tab.c"
    break;

  case 45: /* for: DECOLAR OPEN_PARENTHESES ORIGEM term COMMA DESTINO term COMMA ESCALA term CLOSE_PARENTHESES OPEN_CODEBLOCK $@3 stmt stmts CLOSE_CODEBLOCK  */
#line 266 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1410 "translate.tab.c"
    break;

  case 46: /* $@4: %empty  */
#line 274 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "WHILE");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1423 "translate.tab.c"
    break;

  case 47: /* while: TURISTANDO OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK $@4 stmt stmts CLOSE_CODEBLOCK  */
#line 283 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1432 "translate.tab.c"
    break;

  case 48: /* $@5: %empty  */
#line 290 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "ALFANDEGA");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1445 "translate.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 299 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1454 "translate.tab.c"
    break;

  case 51: /* $@7: %empty  */
#line 308 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "ISENTO");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1467 "translate.tab.c"
    break;

  case 52: /* else: ISENTO OPEN_CODEBLOCK $@7 stmt stmts CLOSE_CODEBLOCK  */
#line 317 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1476 "translate.tab.c"
    break;

  case 53: /* $@8: %empty  */
#line 323 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "TRIBUTADO");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1489 "translate.tab.c"
    break;

  case 54: /* $@9: %empty  */
#line 332 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1498 "translate.tab.c"
    break;

  case 77: /* id: ID  */
#line 386 "translate.y"
        { 
            //conferir se já foi definido ou declarado (sintatico ou semantico ?)
        }
#line 1506 "translate.tab.c"
    break;


#line 1510 "translate.tab.c"

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

#line 413 "translate.y"

/*----------------------------------------------------------------------------------------------------
        Funcoes em C
----------------------------------------------------------------------------------------------------*/
void yyerror() {
    // imprimir mensagem de erro na cor vermelha
    fprintf(stderr, "\n\033[1;31mErro de sintaxe próximo à linha %d: %s\033[0m\n\n", yylineno-1, msg_erro);
     
    printf("\n\n\033[1;31mPrograma sintaticamente incorreto.\033[0m\n\n");

        imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas); // até o momento do erro

    // encerrar a análise prematuramente (assim que encontra um erro):
    exit(0);
}

int main(void) {
    yyparse();     
    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas);
    return 0;
}
