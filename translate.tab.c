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

TabelaSimbolos** tabelas_simbolos = NULL; //armazenar todas as tabelas de simbolos pra poder imprimir
int numero_de_tabelas = 0;

TabelaSimbolos* escopo_atual = NULL; //variavel para armazenar ponteiro para a tabela de simbolos do bloco atual

Funcao** funcoes = NULL; //armazenar todas as funcoes 
int numero_de_funcoes = 0;

Funcao* funcao_atual = NULL; //variavel para armazenar ponteiro para a funcao que esta sendo avaliada no momento
int prototipo = 0;   //flag para saber se os parametros formais sao relacionados ao prototipo de uma funcao

int yylex();

char* strdup(const char*);
double atof(const char*);
int atoi(const char*);

extern int yylineno;          // contar as linhas

char msg_erro[200];           //construir mensagem de erro

void yyerror();               // reportar erros léxicos e sintaticos

void semantic_error();        // reportar erros semâticos

//funcoes auxiliares para analise semantica
int identificador_disponivel(char *identificador);


#line 111 "translate.tab.c"

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
  YYSYMBOL_tripcode = 44,                  /* tripcode  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_consts = 46,                    /* consts  */
  YYSYMBOL_const = 47,                     /* const  */
  YYSYMBOL_variaveis = 48,                 /* variaveis  */
  YYSYMBOL_def_variavel = 49,              /* def_variavel  */
  YYSYMBOL_dec_variavel = 50,              /* dec_variavel  */
  YYSYMBOL_functions_header = 51,          /* functions_header  */
  YYSYMBOL_function_header = 52,           /* function_header  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_function_header_end = 54,       /* function_header_end  */
  YYSYMBOL_params_form = 55,               /* params_form  */
  YYSYMBOL_list_params_form = 56,          /* list_params_form  */
  YYSYMBOL_param_form = 57,                /* param_form  */
  YYSYMBOL_main = 58,                      /* main  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_functions = 60,                 /* functions  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_expr = 63,                      /* expr  */
  YYSYMBOL_operador = 64,                  /* operador  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_stmts = 66,                     /* stmts  */
  YYSYMBOL_stmt = 67,                      /* stmt  */
  YYSYMBOL_for = 68,                       /* for  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_while = 70,                     /* while  */
  YYSYMBOL_71_6 = 71,                      /* $@6  */
  YYSYMBOL_if = 72,                        /* if  */
  YYSYMBOL_73_7 = 73,                      /* $@7  */
  YYSYMBOL_74_8 = 74,                      /* $@8  */
  YYSYMBOL_else = 75,                      /* else  */
  YYSYMBOL_76_9 = 76,                      /* $@9  */
  YYSYMBOL_command = 77,                   /* command  */
  YYSYMBOL_call_function = 78,             /* call_function  */
  YYSYMBOL_79_10 = 79,                     /* $@10  */
  YYSYMBOL_params_real = 80,               /* params_real  */
  YYSYMBOL_list_params_real = 81,          /* list_params_real  */
  YYSYMBOL_param_real = 82,                /* param_real  */
  YYSYMBOL_return = 83,                    /* return  */
  YYSYMBOL_atribuicao = 84,                /* atribuicao  */
  YYSYMBOL_ids = 85,                       /* ids  */
  YYSYMBOL_id_list = 86,                   /* id_list  */
  YYSYMBOL_id = 87,                        /* id  */
  YYSYMBOL_types = 88,                     /* types  */
  YYSYMBOL_type_list = 89,                 /* type_list  */
  YYSYMBOL_result_form = 90,               /* result_form  */
  YYSYMBOL_results = 91,                   /* results  */
  YYSYMBOL_result = 92                     /* result  */
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
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

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
       0,   110,   110,   110,   129,   130,   134,   151,   152,   153,
     157,   171,   186,   187,   192,   191,   215,   226,   227,   231,
     232,   236,   249,   248,   265,   266,   271,   270,   308,   309,
     310,   311,   315,   316,   317,   321,   322,   323,   324,   325,
     326,   330,   331,   335,   336,   337,   338,   343,   342,   361,
     360,   377,   386,   376,   395,   394,   408,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   425,   424,   442,   443,
     447,   448,   452,   456,   460,   464,   468,   469,   472,   476,
     480,   481,   485,   488,   489,   493,   494
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
  "LOGICOP_UNARY", "$accept", "tripcode", "$@1", "consts", "const",
  "variaveis", "def_variavel", "dec_variavel", "functions_header",
  "function_header", "$@2", "function_header_end", "params_form",
  "list_params_form", "param_form", "main", "$@3", "functions", "function",
  "$@4", "expr", "operador", "term", "stmts", "stmt", "for", "$@5",
  "while", "$@6", "if", "$@7", "$@8", "else", "$@9", "command",
  "call_function", "$@10", "params_real", "list_params_real", "param_real",
  "return", "atribuicao", "ids", "id_list", "id", "types", "type_list",
  "result_form", "results", "result", YY_NULLPTR
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
    -128,     5,  -128,  -128,     6,   -32,  -128,    14,   195,   -23,
    -128,  -128,    12,   -15,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,     4,     1,  -128,  -128,    18,     0,    19,    23,    33,
    -128,  -128,   190,     7,  -128,    22,  -128,   190,   190,    -5,
    -128,    41,    40,    27,    81,    50,  -128,    15,  -128,  -128,
    -128,  -128,  -128,   195,  -128,    42,    52,  -128,    40,  -128,
      58,  -128,  -128,   200,  -128,    57,  -128,    63,    62,   190,
      66,    67,    69,    74,    76,    78,    79,   190,    75,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,    89,  -128,  -128,    82,
      40,    85,  -128,    98,    -4,   190,  -128,  -128,   115,   190,
      60,   190,     8,  -128,   100,  -128,  -128,   101,  -128,  -128,
     109,  -128,   208,   195,   213,  -128,    68,   105,  -128,  -128,
     200,  -128,   113,   121,   110,   116,   128,   125,  -128,   131,
    -128,   134,   141,  -128,    -4,  -128,   148,  -128,  -128,    55,
     132,   136,  -128,   200,   195,   200,   142,  -128,  -128,   143,
    -128,  -128,   155,  -128,   151,   161,   164,   120,   166,   140,
    -128,  -128,   136,  -128,   195,  -128,  -128,   185,   163,   167,
    -128,   172,  -128,  -128,   200,   200,  -128,  -128,   160,   180,
    -128,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,     9,     0,     4,    13,     0,     0,
       7,     8,     0,     0,    35,    36,    37,    38,    39,     6,
      40,     0,     0,    12,    25,     0,     0,     0,     0,     3,
      66,    11,     0,     0,    14,     0,    24,    69,     0,     0,
      30,     0,    18,     0,    72,     0,    71,     0,    10,    32,
      33,    34,    31,     0,    22,     0,     0,    20,    18,    67,
      68,    29,    28,     0,    21,     0,    15,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    42,    43,    44,    45,    46,     0,    61,    59,     0,
       0,     0,    70,     0,     0,     0,    64,    65,     0,     0,
       0,     0,     0,    60,     0,    19,    26,     0,    85,    86,
       0,    84,     0,     0,     0,    73,     0,     0,    41,    16,
       0,    81,     0,     0,    82,     0,     0,     0,    74,     0,
      42,    79,     0,    63,     0,    51,     0,    49,    23,     0,
       0,     0,    83,     0,     0,     0,     0,    80,    78,     0,
      77,    42,     0,    42,     0,     0,    75,     0,     0,     0,
      27,    62,     0,    52,     0,    50,    76,    56,     0,     0,
      53,     0,    54,    47,     0,     0,    42,    42,     0,     0,
      55,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,  -128,  -128,   188,   196,  -128,  -128,
    -128,  -128,   144,  -128,   -81,  -128,  -128,  -128,  -128,  -128,
     -30,  -128,    -8,  -127,   -56,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,   -62,  -128,  -128,  -128,   147,
    -128,  -128,  -128,  -128,    43,  -128,  -128,  -128,  -128,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     6,     7,    79,    80,    12,    23,
      42,    66,    56,    67,    57,    24,    63,    29,    36,   120,
      44,    53,    40,   102,   118,    82,   175,    83,   145,    84,
     143,   167,   170,   174,    85,    20,    37,    45,    60,    46,
      87,    88,   149,   156,   150,   122,   131,   110,   124,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    86,    39,   139,    27,     3,     8,    81,    47,   105,
      21,     5,     9,   109,    70,    71,    72,    48,     9,    73,
      74,    75,    31,    25,   157,    76,   159,    13,    77,    55,
      22,    32,   108,    41,    49,    50,    51,    52,   117,    28,
      86,    61,    26,    30,    33,    62,    78,   100,    34,   178,
     179,    35,    58,   109,    49,    50,    51,    52,    86,     9,
      43,    70,    71,    72,   130,   112,    73,    74,    75,   114,
      54,   116,    76,    55,    13,    77,    59,    86,    65,    69,
      64,    86,   115,    86,    90,   146,    89,   151,    91,   153,
     128,    93,    94,    78,    95,    86,    96,    86,    97,    49,
      50,    51,    52,    98,    99,   126,   101,    49,    50,    51,
      52,   103,    86,    86,   106,   104,    86,    86,   176,   177,
      49,    50,    51,    52,     9,   107,    70,    71,    72,   113,
     119,    73,    74,    75,   121,   123,   152,    76,   129,    13,
      77,   132,   134,   133,     9,   135,    70,    71,    72,   136,
     163,    73,    74,    75,   137,   140,   168,    76,    78,    13,
      77,   138,   141,   144,     9,   147,    70,    71,    72,   155,
     165,    73,    74,    75,   148,   154,   158,    76,    78,    13,
      77,   160,   164,   161,     9,   162,    70,    71,    72,   171,
     180,    73,    74,    75,   169,    10,   172,    76,    78,    13,
      77,   173,    68,    11,     9,   166,    70,    71,    72,    13,
     181,    73,    74,    75,    13,    38,    92,    76,    78,    13,
      77,   142,     0,     0,    14,    15,    16,    17,    18,    14,
      15,    16,    17,    18,   125,     0,     0,     0,    78,   127,
       0,     0,     0,     0,     0,     0,     0,    49,    50,    51,
      52,     0,    49,    50,    51,    52
};

static const yytype_int16 yycheck[] =
{
       8,    63,    32,   130,     3,     0,    38,    63,    38,    90,
      33,     5,     4,    94,     6,     7,     8,    22,     4,    11,
      12,    13,    22,    38,   151,    17,   153,    19,    20,    33,
      18,    31,    36,    26,    39,    40,    41,    42,    30,    38,
     102,    26,    38,    25,    25,    53,    38,    77,    25,   176,
     177,    18,    25,   134,    39,    40,    41,    42,   120,     4,
      38,     6,     7,     8,   120,    95,    11,    12,    13,    99,
      29,   101,    17,    33,    19,    20,    26,   139,    26,    21,
      38,   143,    22,   145,    21,    30,    29,   143,    26,   145,
      22,    25,    25,    38,    25,   157,    22,   159,    22,    39,
      40,    41,    42,    25,    25,   113,    31,    39,    40,    41,
      42,    22,   174,   175,    29,    33,   178,   179,   174,   175,
      39,    40,    41,    42,     4,    27,     6,     7,     8,    14,
      30,    11,    12,    13,    33,    26,   144,    17,    33,    19,
      20,    28,    32,    22,     4,    29,     6,     7,     8,    21,
      30,    11,    12,    13,    29,    21,   164,    17,    38,    19,
      20,    30,    21,    15,     4,    33,     6,     7,     8,    26,
      30,    11,    12,    13,    38,    33,    21,    17,    38,    19,
      20,    30,    16,    22,     4,    21,     6,     7,     8,    26,
      30,    11,    12,    13,     9,     7,    29,    17,    38,    19,
      20,    29,    58,     7,     4,   162,     6,     7,     8,    19,
      30,    11,    12,    13,    19,    25,    69,    17,    38,    19,
      20,   134,    -1,    -1,    34,    35,    36,    37,    38,    34,
      35,    36,    37,    38,    26,    -1,    -1,    -1,    38,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,    46,     5,    47,    48,    38,     4,
      49,    50,    51,    19,    34,    35,    36,    37,    38,    65,
      78,    33,    18,    52,    58,    38,    38,     3,    38,    60,
      25,    22,    31,    25,    25,    18,    61,    79,    25,    63,
      65,    26,    53,    38,    63,    80,    82,    63,    22,    39,
      40,    41,    42,    64,    29,    33,    55,    57,    25,    26,
      81,    26,    65,    59,    38,    26,    54,    56,    55,    21,
       6,     7,     8,    11,    12,    13,    17,    20,    38,    49,
      50,    67,    68,    70,    72,    77,    78,    83,    84,    29,
      21,    26,    82,    25,    25,    25,    22,    22,    25,    25,
      63,    31,    66,    22,    33,    57,    29,    27,    36,    57,
      90,    92,    63,    14,    63,    22,    63,    30,    67,    30,
      62,    33,    88,    26,    91,    26,    65,    26,    22,    33,
      67,    89,    28,    22,    32,    29,    21,    29,    30,    66,
      21,    21,    92,    73,    15,    71,    30,    33,    38,    85,
      87,    67,    65,    67,    33,    26,    86,    66,    21,    66,
      30,    22,    21,    30,    16,    30,    87,    74,    65,     9,
      75,    26,    29,    29,    76,    69,    67,    67,    66,    66,
      30,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    48,    48,    48,
      49,    50,    51,    51,    53,    52,    54,    55,    55,    56,
      56,    57,    59,    58,    60,    60,    62,    61,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    66,    67,    67,    67,    67,    69,    68,    71,
      70,    73,    74,    72,    76,    75,    75,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    79,    78,    80,    80,
      81,    81,    82,    83,    84,    85,    86,    86,    87,    88,
      89,    89,    90,    91,    91,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     3,     2,     2,     0,
       6,     4,     2,     0,     0,     6,     4,     2,     0,     3,
       0,     2,     0,    11,     2,     0,     0,    12,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     1,     1,     1,     1,     0,    16,     0,
       9,     0,     0,    11,     0,     6,     0,     1,     1,     1,
       2,     1,     9,     5,     2,     2,     0,     6,     2,     0,
       3,     0,     1,     3,     4,     2,     3,     0,     1,     2,
       3,     0,     2,     3,     0,     1,     1
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
#line 110 "translate.y"
    { //inicializar tabela de simbolos global 
      inicializar_tabela(&escopo_atual, NULL, "GLOBAL");  

      //inicializar lista para armazenar todas as tabelas de simbolos     
      tabelas_simbolos = (TabelaSimbolos**) malloc(100 * sizeof(TabelaSimbolos*));
     
      //adicionar nova tabela na lista de tabelas
      adicionar_nova_tabela(&tabelas_simbolos, escopo_atual, &numero_de_tabelas);

      //já inicializar lista para armazenar funcoes
      funcoes = (Funcao**) malloc(10 * sizeof(Funcao*));   

      printf("%d\t", yylineno++); //inicializar contagem linhas do arquivo
    }
#line 1343 "translate.tab.c"
    break;

  case 6: /* const: EXTERIOR ID term  */
#line 135 "translate.y"
     {
        strcpy(msg_erro,""); //esvazia mensagem de erro
        strcat(msg_erro, "Definição de Constante: ");

        //conferir se já tem algo na tabela global com mesmo nome
        int resultado = identificador_disponivel((yyvsp[-1].string));
        if (resultado){
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro

        adicionar_simbolo(&escopo_atual, "CONSTANTE", (yyvsp[-1].string), "-");
     }
#line 1361 "translate.tab.c"
    break;

  case 10: /* def_variavel: BAGAGEM TYPE ID ASSIGN expr DOT_COMMA  */
#line 157 "translate.y"
                                          {
                                                strcpy(msg_erro,""); //esvazia mensagem de erro
                                                strcat(msg_erro, "Definição de Variável: ");
                                                int resultado = identificador_disponivel((yyvsp[-3].string));
                                                if (resultado){
                                                    semantic_error();
                                                }
                                                strcpy(msg_erro,""); //reseta msg de erro
                                               
                                                adicionar_simbolo(&escopo_atual, (yyvsp[-4].string), (yyvsp[-3].string), "-");
                                            }
#line 1377 "translate.tab.c"
    break;

  case 11: /* dec_variavel: BAGAGEM TYPE ID DOT_COMMA  */
#line 171 "translate.y"
                              {
                                                strcpy(msg_erro,""); //esvazia mensagem de erro
                                                strcat(msg_erro, "Declaração de Variável: ");
                                                int resultado = identificador_disponivel((yyvsp[-1].string));
                                                if (resultado){
                                                    semantic_error();
                                                }
                                                strcpy(msg_erro,""); //reseta msg de erro

                                                adicionar_simbolo(&escopo_atual, (yyvsp[-2].string), (yyvsp[-1].string), "-");
                                            }
#line 1393 "translate.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 192 "translate.y"
    {
        strcpy(msg_erro,""); //esvazia mensagem de erro
        strcat(msg_erro, "Protótipo de Funcao: ");

        int resultado = identificador_disponivel((yyvsp[-1].string));
        if (resultado){
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro

        //inicializar estrutura para armazenar informacoes da funcao
        Funcao *nova_funcao = NULL;
        inicializar_funcao(&nova_funcao, (yyvsp[-1].string));
        adicionar_nova_funcao(&funcoes, nova_funcao, &numero_de_funcoes);
        funcao_atual = nova_funcao;

        prototipo = 1; //mudar a flag para verdadeiro para que os parametros sejam adicionados na funcao atual

    }
#line 1417 "translate.tab.c"
    break;

  case 16: /* function_header_end: CLOSE_PARENTHESES OPEN_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 216 "translate.y"
    {
        set_tipo(&funcao_atual, (yyvsp[-1].string));
        adicionar_simbolo(&escopo_atual, "FUNCAO", funcao_atual->identificador, (yyvsp[-1].string));

        prototipo = 0; //voltar a flag para falso
    }
#line 1428 "translate.tab.c"
    break;

  case 21: /* param_form: TYPE ID  */
#line 237 "translate.y"
    {
        if (prototipo){
            adicionar_parametro(&funcao_atual, (yyvsp[0].string), (yyvsp[-1].string));
        }
        //else{
            //se nao for o prototipo tem que conferir se declarou igual está no prototipo = semantica
        // }
    }
#line 1441 "translate.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 249 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "MAIN");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1454 "translate.tab.c"
    break;

  case 23: /* main: ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK $@3 stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 258 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1463 "translate.tab.c"
    break;

  case 26: /* $@4: %empty  */
#line 271 "translate.y"
    {
        Funcao **funcao = buscar_funcao(funcoes, (yyvsp[-4].string), numero_de_funcoes); 

        if (funcao == NULL){
            prototipo = 0;

            strcpy(msg_erro,"");
            strcat(msg_erro, "Definição de Função: Protótipo da função '"); 
            strcat(msg_erro, (yyvsp[-4].string)); 
            strcat(msg_erro, "' não foi declarado\n"); 
            semantic_error();
        }

        strcpy(msg_erro,""); //reseta msg de erro
        
        prototipo = 1; //aproveitar a flag para indicar que vai mudar o escopo atual e assim que fechar o bloco da funcao tem que restaurar para o escopo anterior
    
        inicializar_tabela_simbolos_funcao(&funcao, escopo_atual);
            
        adicionar_nova_tabela(&tabelas_simbolos, (*funcao)->escopo, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = (*funcao)->escopo;
        

    }
#line 1494 "translate.tab.c"
    break;

  case 27: /* function: ROTEIRO ID OPEN_PARENTHESES params_form CLOSE_PARENTHESES OPEN_CODEBLOCK $@4 stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 298 "translate.y"
    {
        if (prototipo){
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
        prototipo = 0;   
    }
#line 1506 "translate.tab.c"
    break;

  case 47: /* $@5: %empty  */
#line 343 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "DECOLAR");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1519 "translate.tab.c"
    break;

  case 48: /* for: DECOLAR OPEN_PARENTHESES ORIGEM term COMMA DESTINO term COMMA ESCALA term CLOSE_PARENTHESES OPEN_CODEBLOCK $@5 stmt stmts CLOSE_CODEBLOCK  */
#line 353 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1528 "translate.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 361 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "TURISTANDO");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1541 "translate.tab.c"
    break;

  case 50: /* while: TURISTANDO OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK $@6 stmt stmts CLOSE_CODEBLOCK  */
#line 370 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1550 "translate.tab.c"
    break;

  case 51: /* $@7: %empty  */
#line 377 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "ALFANDEGA");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1563 "translate.tab.c"
    break;

  case 52: /* $@8: %empty  */
#line 386 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1572 "translate.tab.c"
    break;

  case 54: /* $@9: %empty  */
#line 395 "translate.y"
    {
        TabelaSimbolos *nova_tabela = NULL;
        inicializar_tabela(&nova_tabela, escopo_atual, "ISENTO");
        adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

        // atualiza o escopo atual para a nova tabela
        escopo_atual = nova_tabela;
    }
#line 1585 "translate.tab.c"
    break;

  case 55: /* else: ISENTO OPEN_CODEBLOCK $@9 stmt stmts CLOSE_CODEBLOCK  */
#line 404 "translate.y"
    {
        // restaura o escopo anterior como o escopo atual
        escopo_atual = escopo_atual->anterior;
    }
#line 1594 "translate.tab.c"
    break;

  case 66: /* $@10: %empty  */
#line 425 "translate.y"
    {
        Funcao **funcao = buscar_funcao(funcoes, (yyvsp[-1].string), numero_de_funcoes); 

        if (funcao == NULL){
            prototipo = 0;

            strcpy(msg_erro,"");
            strcat(msg_erro, "Chamada de Função: Protótipo da função '"); 
            strcat(msg_erro, (yyvsp[-1].string)); 
            strcat(msg_erro, "' não foi declarado\n"); 
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro
    }
#line 1613 "translate.tab.c"
    break;


#line 1617 "translate.tab.c"

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

#line 497 "translate.y"

/*----------------------------------------------------------------------------------------------------
        Funcoes em C
----------------------------------------------------------------------------------------------------*/
void yyerror() {
    // imprimir mensagem de erro na cor vermelha
    fprintf(stderr, "\n\033[1;31mErro de sintaxe próximo à linha %d: %s\033[0m\n\n", yylineno-1, msg_erro);
     
    // printf("\n\n\033[1;31mPrograma sintaticamente incorreto.\033[0m\n\n");
    printf("\n\n");
    
    //imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas); // até o momento do erro

    // encerrar a análise prematuramente (assim que encontra um erro):
    exit(0);
}

void semantic_error() {
     // imprimir mensagem de erro na cor vermelha
     fprintf(stderr, "\n\033[1;31mErro semântico próximo à linha %d:\033[0m\n\033[31m---> %s\033[0m\n", yylineno-1, msg_erro);
     
     // printf("\n\n\033[1;31mPrograma semanticamente incorreto.\033[0m\n\n");
     printf("\n\n");

     exit(0);
}

int identificador_disponivel(char *identificador){
    //define a mensagem de erro:
    strcat(msg_erro, "O identificador '"); 
    strcat(msg_erro, identificador); 
    
    //percorrer funcoes para vê se identificador já foi usado:
    if (buscar_funcao(funcoes, identificador, numero_de_funcoes) != NULL){
        strcat(msg_erro, "' já está sendo usado para uma função!\n");
        return 1;
    }

    //percorreter tabela de simbolos do bloco local para vê se identificador já foi usado no escopo local:
    //se escopo local nao for o global tem que conferir se já existe constante com mesmo identificador?
    if (verificar_simbolo_escopo_local(escopo_atual, identificador)) {
        strcat(msg_erro, "' já está sendo usado!\n");
        return 1;
    }
    return 0;
}

int main(void) {
    yyparse();     
    
    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas);

    return 0;
}
