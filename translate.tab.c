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
Funcao* funcao_temp = NULL; //variavel para armazenar ponteiro para a funcao temporaria para comparar com o prototipo

int prototipo = 0;   //flag para saber se os parametros formais sao relacionados ao prototipo de uma funcao
int definicao = 0;

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
int comparar_definicao_com_prototipo();
void verificar_definicao_funcoes_chamadas();


#line 116 "translate.tab.c"

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
  YYSYMBOL_POUSAR = 10,                    /* POUSAR  */
  YYSYMBOL_FERIADO = 11,                   /* FERIADO  */
  YYSYMBOL_DECOLAR = 12,                   /* DECOLAR  */
  YYSYMBOL_ORIGEM = 13,                    /* ORIGEM  */
  YYSYMBOL_DESTINO = 14,                   /* DESTINO  */
  YYSYMBOL_ESCALA = 15,                    /* ESCALA  */
  YYSYMBOL_TURISTANDO = 16,                /* TURISTANDO  */
  YYSYMBOL_ROTEIRO = 17,                   /* ROTEIRO  */
  YYSYMBOL_EMBARCAR = 18,                  /* EMBARCAR  */
  YYSYMBOL_DESPACHAR = 19,                 /* DESPACHAR  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_DOT_COMMA = 21,                 /* DOT_COMMA  */
  YYSYMBOL_DOT = 22,                       /* DOT  */
  YYSYMBOL_COLON = 23,                     /* COLON  */
  YYSYMBOL_OPEN_PARENTHESES = 24,          /* OPEN_PARENTHESES  */
  YYSYMBOL_CLOSE_PARENTHESES = 25,         /* CLOSE_PARENTHESES  */
  YYSYMBOL_OPEN_BRACKET = 26,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 27,             /* CLOSE_BRACKET  */
  YYSYMBOL_OPEN_CODEBLOCK = 28,            /* OPEN_CODEBLOCK  */
  YYSYMBOL_CLOSE_CODEBLOCK = 29,           /* CLOSE_CODEBLOCK  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_CONCAT = 31,                    /* CONCAT  */
  YYSYMBOL_TYPE = 32,                      /* TYPE  */
  YYSYMBOL_INT = 33,                       /* INT  */
  YYSYMBOL_FLOAT = 34,                     /* FLOAT  */
  YYSYMBOL_STRING = 35,                    /* STRING  */
  YYSYMBOL_BOOL = 36,                      /* BOOL  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_ID_CONST = 38,                  /* ID_CONST  */
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
  YYSYMBOL_dec_variavel = 49,              /* dec_variavel  */
  YYSYMBOL_def_variavel = 50,              /* def_variavel  */
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
  YYSYMBOL_function_end = 63,              /* function_end  */
  YYSYMBOL_stmts = 64,                     /* stmts  */
  YYSYMBOL_stmt = 65,                      /* stmt  */
  YYSYMBOL_for = 66,                       /* for  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_while = 68,                     /* while  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_if = 70,                        /* if  */
  YYSYMBOL_71_7 = 71,                      /* $@7  */
  YYSYMBOL_72_8 = 72,                      /* $@8  */
  YYSYMBOL_else = 73,                      /* else  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_command = 75,                   /* command  */
  YYSYMBOL_call_function = 76,             /* call_function  */
  YYSYMBOL_params_real = 77,               /* params_real  */
  YYSYMBOL_list_params_real = 78,          /* list_params_real  */
  YYSYMBOL_param_real = 79,                /* param_real  */
  YYSYMBOL_return = 80,                    /* return  */
  YYSYMBOL_atribuicao = 81,                /* atribuicao  */
  YYSYMBOL_expr = 82,                      /* expr  */
  YYSYMBOL_term = 83,                      /* term  */
  YYSYMBOL_ids = 84,                       /* ids  */
  YYSYMBOL_id_list = 85,                   /* id_list  */
  YYSYMBOL_id = 86,                        /* id  */
  YYSYMBOL_types = 87,                     /* types  */
  YYSYMBOL_type_list = 88,                 /* type_list  */
  YYSYMBOL_result_form = 89,               /* result_form  */
  YYSYMBOL_results = 90,                   /* results  */
  YYSYMBOL_result = 91                     /* result  */
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
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

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
       0,   124,   124,   124,   145,   146,   150,   167,   168,   169,
     173,   188,   216,   217,   222,   221,   245,   256,   257,   261,
     262,   266,   281,   280,   297,   298,   303,   302,   337,   360,
     361,   365,   366,   367,   368,   373,   372,   390,   389,   406,
     415,   405,   424,   423,   437,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   453,   475,   476,   480,   481,   485,
     489,   493,   509,   535,   537,   548,   561,   562,   566,   567,
     568,   569,   570,   571,   575,   579,   580,   584,   600,   604,
     605,   609,   612,   613,   617,   618
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
  "EXTERIOR", "CHECKIN", "CHECKOUT", "ALFANDEGA", "ISENTO", "POUSAR",
  "FERIADO", "DECOLAR", "ORIGEM", "DESTINO", "ESCALA", "TURISTANDO",
  "ROTEIRO", "EMBARCAR", "DESPACHAR", "COMMA", "DOT_COMMA", "DOT", "COLON",
  "OPEN_PARENTHESES", "CLOSE_PARENTHESES", "OPEN_BRACKET", "CLOSE_BRACKET",
  "OPEN_CODEBLOCK", "CLOSE_CODEBLOCK", "ASSIGN", "CONCAT", "TYPE", "INT",
  "FLOAT", "STRING", "BOOL", "ID", "ID_CONST", "OP", "RELOP", "LOGICOP",
  "LOGICOP_UNARY", "$accept", "tripcode", "$@1", "consts", "const",
  "variaveis", "dec_variavel", "def_variavel", "functions_header",
  "function_header", "$@2", "function_header_end", "params_form",
  "list_params_form", "param_form", "main", "$@3", "functions", "function",
  "$@4", "function_end", "stmts", "stmt", "for", "$@5", "while", "$@6",
  "if", "$@7", "$@8", "else", "$@9", "command", "call_function",
  "params_real", "list_params_real", "param_real", "return", "atribuicao",
  "expr", "term", "ids", "id_list", "id", "types", "type_list",
  "result_form", "results", "result", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -129,     6,  -129,  -129,     5,   -27,  -129,     8,   211,   -10,
    -129,  -129,    14,   -14,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,     4,     2,  -129,  -129,    31,   -12,    32,    38,
      46,   197,  -129,   197,    41,  -129,    30,  -129,   211,    43,
    -129,    -5,  -129,    12,    44,    39,    50,    52,  -129,    55,
     211,   211,   211,  -129,  -129,  -129,    42,    56,  -129,  -129,
    -129,   197,  -129,  -129,  -129,     9,  -129,    57,  -129,    64,
      39,  -129,    62,    66,    67,    71,    76,    74,    78,   197,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,    79,  -129,  -129,
      58,    72,    39,    80,    81,    -3,   197,  -129,  -129,    95,
     197,    19,   122,  -129,   197,    84,  -129,    82,    77,  -129,
    -129,    89,  -129,   212,   211,   217,  -129,    85,  -129,   199,
    -129,     9,  -129,    93,   100,    96,   103,   115,   108,   110,
    -129,  -129,   123,   124,  -129,    -3,  -129,   128,  -129,  -129,
     142,   113,   118,  -129,     9,   211,     9,   131,  -129,  -129,
     147,  -129,  -129,   127,  -129,   138,   135,   153,   158,   160,
     174,  -129,  -129,   118,  -129,   211,  -129,  -129,   179,   164,
     155,  -129,   163,  -129,  -129,     9,     9,  -129,  -129,   190,
     206,  -129,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,     9,     0,     4,    13,     0,     0,
       7,     8,     0,     0,    68,    69,    70,    71,    77,    72,
       6,    73,     0,     0,    12,    25,     0,     0,     0,     0,
       3,    56,    10,     0,     0,    14,     0,    24,     0,     0,
      58,    59,    66,     0,     0,    18,     0,     0,    54,    55,
       0,     0,     0,    65,    11,    22,     0,     0,    20,    26,
      67,     0,    62,    63,    64,     0,    21,     0,    15,    17,
      18,    57,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    45,    30,    31,    32,    33,    34,     0,    49,    47,
       0,     0,     0,     0,     0,     0,     0,    52,    53,     0,
       0,     0,     0,    48,     0,     0,    19,     0,     0,    84,
      85,     0,    83,     0,     0,     0,    60,     0,    29,     0,
      16,     0,    80,     0,     0,    81,     0,     0,     0,     0,
      61,    30,    78,     0,    51,     0,    39,     0,    37,    23,
       0,     0,     0,    82,     0,     0,     0,     0,    27,    79,
       0,    76,    30,     0,    30,     0,     0,    74,     0,     0,
       0,    28,    50,     0,    40,     0,    38,    75,    44,     0,
       0,    41,     0,    42,    35,     0,     0,    30,    30,     0,
       0,    43,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,  -129,  -129,   192,   198,  -129,  -129,
    -129,  -129,   134,  -129,   -88,  -129,  -129,  -129,  -129,  -129,
    -129,  -128,   -51,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   -57,  -129,  -129,   146,  -129,  -129,   -31,
      -8,  -129,  -129,   -64,  -129,  -129,  -129,  -129,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     6,     7,    80,    81,    12,    24,
      45,    68,    57,    69,    58,    25,    65,    30,    37,    70,
     148,   102,   118,    83,   176,    84,   146,    85,   144,   168,
     171,   175,    86,    19,    39,    49,    40,    88,    89,    41,
      42,   150,   157,    21,   123,   132,   111,   125,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    90,    43,   140,   106,    28,     3,   110,    87,    32,
       5,     8,     9,     9,    82,    72,    73,    74,    33,    75,
      76,    77,    22,    26,   158,    78,   160,    13,    79,    56,
      47,    23,   109,    54,    50,    51,    52,    53,    90,    29,
     116,    27,    62,    63,    64,    87,    18,   110,   101,   179,
     180,    50,    51,    52,    53,    31,    34,    90,    50,    51,
      52,    53,    35,    36,    87,   113,    44,    46,    48,   115,
     131,    56,    55,   119,    59,    61,    90,    60,   151,    66,
      90,    67,    90,    87,    92,    91,    94,    87,   104,    87,
      95,    96,    97,   152,    90,   154,    90,    98,    99,   167,
     103,    87,   100,    87,   105,   107,   127,   108,   114,   122,
     121,    90,    90,   120,   124,    90,    90,   129,    87,    87,
     133,   134,    87,    87,   177,   178,     9,   135,    72,    73,
      74,   136,    75,    76,    77,   137,   138,   153,    78,   139,
      13,    79,   145,   141,   142,   149,     9,   159,    72,    73,
      74,   117,    75,    76,    77,    18,   162,   169,    78,    18,
      13,    79,     9,   155,    72,    73,    74,   161,    75,    76,
      77,   147,   156,   163,    78,   165,    13,    79,     9,    18,
      72,    73,    74,   173,    75,    76,    77,   164,   170,   172,
      78,   174,    13,    79,     9,    18,    72,    73,    74,    10,
      75,    76,    77,   166,    93,    11,    78,    71,    13,    79,
       9,    18,    72,    73,    74,    13,    75,    76,    77,   181,
     130,    38,    78,   143,    13,    79,     0,    18,     0,    13,
      14,    15,    16,    17,    18,   182,     0,   126,    50,    51,
      52,    53,   128,    18,    14,    15,    16,    17,    18,     0,
       0,    50,    51,    52,    53,     0,    50,    51,    52,    53
};

static const yytype_int16 yycheck[] =
{
       8,    65,    33,   131,    92,     3,     0,    95,    65,    21,
       5,    38,     4,     4,    65,     6,     7,     8,    30,    10,
      11,    12,    32,    37,   152,    16,   154,    18,    19,    32,
      38,    17,    35,    21,    39,    40,    41,    42,   102,    37,
      21,    37,    50,    51,    52,   102,    37,   135,    79,   177,
     178,    39,    40,    41,    42,    24,    24,   121,    39,    40,
      41,    42,    24,    17,   121,    96,    25,    37,    25,   100,
     121,    32,    28,   104,    24,    20,   140,    25,   142,    37,
     144,    25,   146,   140,    20,    28,    24,   144,    30,   146,
      24,    24,    21,   144,   158,   146,   160,    21,    24,   163,
      21,   158,    24,   160,    32,    25,   114,    26,    13,    32,
      28,   175,   176,    29,    25,   179,   180,    32,   175,   176,
      27,    21,   179,   180,   175,   176,     4,    31,     6,     7,
       8,    28,    10,    11,    12,    20,    28,   145,    16,    29,
      18,    19,    14,    20,    20,    32,     4,    20,     6,     7,
       8,    29,    10,    11,    12,    37,    21,   165,    16,    37,
      18,    19,     4,    32,     6,     7,     8,    29,    10,    11,
      12,    29,    25,    20,    16,    15,    18,    19,     4,    37,
       6,     7,     8,    28,    10,    11,    12,    29,     9,    25,
      16,    28,    18,    19,     4,    37,     6,     7,     8,     7,
      10,    11,    12,    29,    70,     7,    16,    61,    18,    19,
       4,    37,     6,     7,     8,    18,    10,    11,    12,    29,
      21,    24,    16,   135,    18,    19,    -1,    37,    -1,    18,
      33,    34,    35,    36,    37,    29,    -1,    25,    39,    40,
      41,    42,    25,    37,    33,    34,    35,    36,    37,    -1,
      -1,    39,    40,    41,    42,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,    46,     5,    47,    48,    38,     4,
      49,    50,    51,    18,    33,    34,    35,    36,    37,    76,
      83,    86,    32,    17,    52,    58,    37,    37,     3,    37,
      60,    24,    21,    30,    24,    24,    17,    61,    24,    77,
      79,    82,    83,    82,    25,    53,    37,    83,    25,    78,
      39,    40,    41,    42,    21,    28,    32,    55,    57,    24,
      25,    20,    83,    83,    83,    59,    37,    25,    54,    56,
      62,    79,     6,     7,     8,    10,    11,    12,    16,    19,
      49,    50,    65,    66,    68,    70,    75,    76,    80,    81,
      86,    28,    20,    55,    24,    24,    24,    21,    21,    24,
      24,    82,    64,    21,    30,    32,    57,    25,    26,    35,
      57,    89,    91,    82,    13,    82,    21,    29,    65,    82,
      29,    28,    32,    87,    25,    90,    25,    83,    25,    32,
      21,    65,    88,    27,    21,    31,    28,    20,    28,    29,
      64,    20,    20,    91,    71,    14,    69,    29,    63,    32,
      84,    86,    65,    83,    65,    32,    25,    85,    64,    20,
      64,    29,    21,    20,    29,    15,    29,    86,    72,    83,
       9,    73,    25,    28,    28,    74,    67,    65,    65,    64,
      64,    29,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    48,    48,    48,
      49,    50,    51,    51,    53,    52,    54,    55,    55,    56,
      56,    57,    59,    58,    60,    60,    62,    61,    63,    64,
      64,    65,    65,    65,    65,    67,    66,    69,    68,    71,
      72,    70,    74,    73,    73,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    77,    77,    78,    78,    79,
      80,    81,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    83,    84,    85,    85,    86,    87,    88,
      88,    89,    90,    90,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     3,     2,     2,     0,
       4,     6,     2,     0,     0,     6,     4,     2,     0,     3,
       0,     2,     0,    11,     2,     0,     0,    10,     3,     2,
       0,     1,     1,     1,     1,     0,    16,     0,     9,     0,
       0,    11,     0,     6,     0,     1,     1,     1,     2,     1,
       9,     5,     2,     2,     5,     2,     0,     3,     0,     1,
       3,     4,     3,     3,     3,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     3,     0,     1,     2,     3,
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
#line 124 "translate.y"
    {   //inicializar tabela de simbolos global 
        inicializar_tabela(&escopo_atual, NULL, "GLOBAL");  

        //inicializar lista para armazenar todas as tabelas de simbolos     
        tabelas_simbolos = (TabelaSimbolos**) malloc(100 * sizeof(TabelaSimbolos*));
        
        //adicionar nova tabela na lista de tabelas
        adicionar_nova_tabela(&tabelas_simbolos, escopo_atual, &numero_de_tabelas);

        //já inicializar lista para armazenar funcoes
        funcoes = (Funcao**) malloc(10 * sizeof(Funcao*));   

        printf("%d\t", yylineno++); //inicializar contagem linhas do arquivo
    }
#line 1347 "translate.tab.c"
    break;

  case 3: /* tripcode: $@1 consts variaveis functions_header main functions  */
#line 139 "translate.y"
    {
        verificar_definicao_funcoes_chamadas();
    }
#line 1355 "translate.tab.c"
    break;

  case 6: /* const: EXTERIOR ID_CONST term  */
#line 151 "translate.y"
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Definição de Constante: ");

            //conferir se já tem algo na tabela global com mesmo nome
            int resultado = identificador_disponivel((yyvsp[-1].string));
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            adicionar_simbolo(&escopo_atual, (yyvsp[0].string), (yyvsp[-1].string), "CONSTANTE");
        }
#line 1373 "translate.tab.c"
    break;

  case 10: /* dec_variavel: BAGAGEM TYPE ID DOT_COMMA  */
#line 174 "translate.y"
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
#line 1389 "translate.tab.c"
    break;

  case 11: /* def_variavel: BAGAGEM TYPE ID ASSIGN expr DOT_COMMA  */
#line 189 "translate.y"
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Definição de Variável: ");
            int resultado = identificador_disponivel((yyvsp[-3].string));
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            if ((strcmp((yyvsp[-4].string), (yyvsp[-1].string)) != 0)){
                strcat(msg_erro, "Definição de Variável: ");
                strcat(msg_erro, "O tipo do valor atribuido à variável '");
                strcat(msg_erro, (yyvsp[-3].string));
                strcat(msg_erro, "' é incompatível com tipo esperado! ('");
                strcat(msg_erro, (yyvsp[-4].string));
                strcat(msg_erro, "' <-> '");
                strcat(msg_erro, (yyvsp[-1].string));
                strcat(msg_erro, "' => X)\n");
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro
            
            adicionar_simbolo(&escopo_atual, (yyvsp[-4].string), (yyvsp[-3].string), "-");
        }
#line 1418 "translate.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 222 "translate.y"
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
#line 1442 "translate.tab.c"
    break;

  case 16: /* function_header_end: CLOSE_PARENTHESES OPEN_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 246 "translate.y"
    {
        set_tipo(&funcao_atual, (yyvsp[-1].string));
        adicionar_simbolo(&escopo_atual, "FUNCAO", funcao_atual->identificador, (yyvsp[-1].string));

        prototipo = 0; //voltar a flag para falso
    }
#line 1453 "translate.tab.c"
    break;

  case 21: /* param_form: TYPE ID  */
#line 267 "translate.y"
        {
            if (prototipo){
                adicionar_parametro(&funcao_atual, (yyvsp[0].string), (yyvsp[-1].string));
            }
            if (definicao){
                //se nao for o prototipo tem que conferir se declarou igual está no prototipo = semantica
                adicionar_parametro(&funcao_temp, (yyvsp[0].string), (yyvsp[-1].string));
            }
            //conferir quando for checkout
        }
#line 1468 "translate.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 281 "translate.y"
        {
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "MAIN");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1481 "translate.tab.c"
    break;

  case 23: /* main: ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK $@3 stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 290 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1490 "translate.tab.c"
    break;

  case 26: /* $@4: %empty  */
#line 303 "translate.y"
        {
            Funcao **funcao = buscar_funcao(funcoes, (yyvsp[-1].string), numero_de_funcoes); 
            if (funcao == NULL){

                strcpy(msg_erro,"");
                strcat(msg_erro, "Definição de Função: Protótipo da função '"); 
                strcat(msg_erro, (yyvsp[-1].string)); 
                strcat(msg_erro, "' não foi declarado\n"); 
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro
            
            definicao = 1; //aproveitar a flag para indicar que vai mudar o escopo atual e assim que fechar o bloco da funcao tem que restaurar para o escopo anterior

            inicializar_tabela_simbolos_funcao(&funcao, escopo_atual);
            adicionar_nova_tabela(&tabelas_simbolos, (*funcao)->escopo, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = (*funcao)->escopo;

            funcao_atual = *funcao;

            //mudar flag que indica que funcao foi definida
            set_definida(&funcao_atual);

            //inicializar estrutura temporar para armazenar informacoes da definicao da funcao
            Funcao *aux = NULL;
            inicializar_funcao(&aux, (yyvsp[-1].string));
            funcao_temp = aux;  
        }
#line 1525 "translate.tab.c"
    break;

  case 28: /* function_end: CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 338 "translate.y"
        {
            if (definicao){

                strcpy(msg_erro,""); //esvazia mensagem de erro
                strcat(msg_erro, "Definicao de Funcao: ");

                set_tipo(&funcao_temp, (yyvsp[-1].string));

                int resultado = comparar_definicao_com_prototipo();
                if (resultado){
                    semantic_error();
                }
                strcpy(msg_erro,""); //reseta msg de erro

                // restaura o escopo anterior como o escopo atual
                escopo_atual = escopo_atual->anterior;
            }
            definicao = 0; 
        }
#line 1549 "translate.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 373 "translate.y"
        {
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "DECOLAR");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1562 "translate.tab.c"
    break;

  case 36: /* for: DECOLAR OPEN_PARENTHESES ORIGEM term COMMA DESTINO term COMMA ESCALA term CLOSE_PARENTHESES OPEN_CODEBLOCK $@5 stmt stmts CLOSE_CODEBLOCK  */
#line 382 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1571 "translate.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 390 "translate.y"
        {
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "TURISTANDO");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1584 "translate.tab.c"
    break;

  case 38: /* while: TURISTANDO OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK $@6 stmt stmts CLOSE_CODEBLOCK  */
#line 399 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1593 "translate.tab.c"
    break;

  case 39: /* $@7: %empty  */
#line 406 "translate.y"
        {
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "ALFANDEGA");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1606 "translate.tab.c"
    break;

  case 40: /* $@8: %empty  */
#line 415 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1615 "translate.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 424 "translate.y"
        {
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "ISENTO");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1628 "translate.tab.c"
    break;

  case 43: /* else: ISENTO OPEN_CODEBLOCK $@9 stmt stmts CLOSE_CODEBLOCK  */
#line 433 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1637 "translate.tab.c"
    break;

  case 54: /* call_function: EMBARCAR ID OPEN_PARENTHESES params_real CLOSE_PARENTHESES  */
#line 454 "translate.y"
        {
            Funcao **funcao = buscar_funcao(funcoes, (yyvsp[-3].string), numero_de_funcoes); 

            if (funcao == NULL){
                prototipo = 0;

                strcpy(msg_erro,"");
                strcat(msg_erro, "Chamada de Função: Protótipo da função '"); 
                strcat(msg_erro, (yyvsp[-3].string)); 
                strcat(msg_erro, "' não foi declarado\n"); 
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            (*funcao)->chamada = 1;

            (yyval.string) = (*funcao)->tipo_retorno;
        }
#line 1660 "translate.tab.c"
    break;

  case 60: /* return: DESPACHAR expr DOT_COMMA  */
#line 489 "translate.y"
                             {(yyval.string) = (yyvsp[-1].string);}
#line 1666 "translate.tab.c"
    break;

  case 61: /* atribuicao: id ASSIGN expr DOT_COMMA  */
#line 494 "translate.y"
        { 
            if (strcmp((yyvsp[-3].string), (yyvsp[-1].string)) != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Atribuição: Não é possível atribuir tipo '");
                strcat(msg_erro, (yyvsp[-1].string));  
                strcat(msg_erro, "' a uma variavel do tipo '"); 
                strcat(msg_erro, (yyvsp[-3].string)); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
        }
#line 1683 "translate.tab.c"
    break;

  case 62: /* expr: expr OP term  */
#line 510 "translate.y"
        { 
            if ( (strcmp((yyvsp[-2].string), (yyvsp[0].string)) != 0) ){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação '");
                strcat(msg_erro, (yyvsp[-1].string));  
                strcat(msg_erro, "': Tanto o lado esquerdo quanto o lado direito devem ser do mesmo tipo e '"); 
                strcat(msg_erro, (yyvsp[-2].string)); 
                strcat(msg_erro, "' != '"); 
                strcat(msg_erro, (yyvsp[0].string)); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
                    
            if (strcmp((yyvsp[-2].string), "STRING") == 0){
                strcat(msg_erro, "Operação '");
                strcat(msg_erro, (yyvsp[-1].string));  
                strcat(msg_erro, "': Não é possível aplicar essa operação em strings!'"); 
                strcat(msg_erro, (yyvsp[-2].string)); 
            }
            strcpy(msg_erro,"");

            (yyval.string) = (yyvsp[-2].string);
        }
#line 1712 "translate.tab.c"
    break;

  case 63: /* expr: expr RELOP term  */
#line 535 "translate.y"
                        { (yyval.string) = "BOLL"; }
#line 1718 "translate.tab.c"
    break;

  case 64: /* expr: expr LOGICOP term  */
#line 538 "translate.y"
        { 
            if ((strcmp((yyvsp[-2].string), "BOOL") != 0) || (strcmp((yyvsp[0].string), "BOOL") != 0)){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Lógica: Operadores lógicos só podem ser aplicados ao tipo BOOL\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
            (yyval.string) = (yyvsp[-2].string);
        }
#line 1732 "translate.tab.c"
    break;

  case 65: /* expr: expr LOGICOP_UNARY  */
#line 549 "translate.y"
            {
                if (strcmp((yyvsp[-1].string), "BOOL") != 0) {
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Operação Lógica Unária: O operador NOT não pode ser aplicado ao tipo'"); 
                    strcat(msg_erro, (yyvsp[-1].string)); 
                    strcat(msg_erro, "' apenas ao tipo BOOL\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");
                
                (yyval.string) = (yyvsp[-1].string);
            }
#line 1749 "translate.tab.c"
    break;

  case 66: /* expr: term  */
#line 561 "translate.y"
           {(yyval.string) = (yyvsp[0].string);}
#line 1755 "translate.tab.c"
    break;

  case 67: /* expr: OPEN_PARENTHESES term CLOSE_PARENTHESES  */
#line 562 "translate.y"
                                              {(yyval.string) = (yyvsp[-1].string);}
#line 1761 "translate.tab.c"
    break;

  case 68: /* term: INT  */
#line 566 "translate.y"
                     {(yyval.string) = "MILHAS";}
#line 1767 "translate.tab.c"
    break;

  case 69: /* term: FLOAT  */
#line 567 "translate.y"
                     {(yyval.string) = "DOLAR";}
#line 1773 "translate.tab.c"
    break;

  case 70: /* term: STRING  */
#line 568 "translate.y"
                     {(yyval.string) = "VOUCHER";}
#line 1779 "translate.tab.c"
    break;

  case 71: /* term: BOOL  */
#line 569 "translate.y"
                     {(yyval.string) = "BOOL";}
#line 1785 "translate.tab.c"
    break;

  case 72: /* term: call_function  */
#line 570 "translate.y"
                     {(yyval.string) = (yyvsp[0].string);}
#line 1791 "translate.tab.c"
    break;

  case 73: /* term: id  */
#line 571 "translate.y"
                     {(yyval.string) = (yyvsp[0].string);}
#line 1797 "translate.tab.c"
    break;

  case 77: /* id: ID  */
#line 585 "translate.y"
        { Simbolo *simbolo = buscar_simbolo(escopo_atual,  (yyvsp[0].string));
            if (simbolo == NULL){
                strcpy(msg_erro,"");
                strcat(msg_erro, "'Usar' Variável: Não existe variável com o identificador '"); 
                strcat(msg_erro, (yyvsp[0].string)); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            (yyval.string) = simbolo->tipo;
        }
#line 1814 "translate.tab.c"
    break;


#line 1818 "translate.tab.c"

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

#line 621 "translate.y"

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

int identificador_disponivel(char *identificador) {
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

int comparar_definicao_com_prototipo() {
    if (funcao_atual->qtd_parametros != funcao_temp->qtd_parametros) {
        strcat(msg_erro, "Quantidade de Parâmetros Diferente!\n");
        return 1; 
    }

    for (int i = 0; i < funcao_atual->qtd_parametros; i++) {
        if (strcmp(funcao_atual->parametros[i]->tipo, funcao_temp->parametros[i]->tipo) != 0) {
            char buffer[100]; 
            snprintf(buffer, sizeof(buffer), "Erro no %dº parâmetro: esperado '%s'!\n", 
                     i + 1, 
                     funcao_atual->parametros[i]->tipo);
            strcat(msg_erro, buffer);
            return 1;
        }
    }

    if (strcmp(funcao_atual->tipo_retorno, funcao_temp->tipo_retorno) != 0) {
        strcat(msg_erro, "Tipo de Retorno diferente: esperado ");
        strcat(msg_erro, funcao_atual->tipo_retorno);
        strcat(msg_erro, "!");
        return 1;
    }

    return 0;
}


void verificar_definicao_funcoes_chamadas() {
    for (int i = 0; i < numero_de_funcoes; i++) {
        if (funcoes[i]->chamada){
            if (funcoes[i]->definida == 0){
                strcat(msg_erro, "A função '");
                strcat(msg_erro, funcoes[i]->identificador);
                strcat(msg_erro, "' não foi definida, existe apenas seu protótipo!");
                semantic_error();
            }
        } 
    }
}

int main(void) {
    yyparse();     
    
    printf("\n\n\033[1;32mPrograma sintaticamente correto.\033[0m\n\n");
    
    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas);

    return 0;
}
