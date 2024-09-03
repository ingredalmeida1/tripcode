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
#include "TAD/InstrucaoTAC.h"

TabelaSimbolos** tabelas_simbolos = NULL; //armazenar todas as tabelas de simbolos pra poder imprimir
int numero_de_tabelas = 0;

TabelaSimbolos* escopo_atual = NULL; //variavel para armazenar ponteiro para a tabela de simbolos do bloco atual

Funcao** funcoes = NULL; //armazenar todas as funcoes 
int numero_de_funcoes = 0;

Funcao* funcao_atual = NULL; //variavel para armazenar ponteiro para a funcao que esta sendo avaliada no momento
Funcao* funcao_temp = NULL; //variavel para armazenar ponteiro para a funcao temporaria para comparar com o prototipo

int qtd_parametros_reais = 0;
char* tipos_parametros_reais[10]; 

int prototipo = 0;   //flag para saber se os parametros formais sao relacionados ao prototipo de uma funcao
int definicao = 0;   //flag para saber se os parametros formais sao relacionados ao prototipo de uma funcao
int checkout = 0;    //flag para saber se os parametros formais sao relacionados a chamada da funcao chekcout

int qtd_tipos_checkin = 0;
char* tipos_checkin[10]; 
int qtd_ids_checkin = 0;
char* ids_checkin[10]; 

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


#line 126 "translate.tab.c"

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
  YYSYMBOL_OP = 38,                        /* OP  */
  YYSYMBOL_RELOP = 39,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 40,                   /* LOGICOP  */
  YYSYMBOL_LOGICOP_UNARY = 41,             /* LOGICOP_UNARY  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_tripcode = 43,                  /* tripcode  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_consts = 45,                    /* consts  */
  YYSYMBOL_const = 46,                     /* const  */
  YYSYMBOL_variaveis = 47,                 /* variaveis  */
  YYSYMBOL_dec_variavel = 48,              /* dec_variavel  */
  YYSYMBOL_def_variavel = 49,              /* def_variavel  */
  YYSYMBOL_functions_header = 50,          /* functions_header  */
  YYSYMBOL_function_header = 51,           /* function_header  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_function_header_end = 53,       /* function_header_end  */
  YYSYMBOL_params_form = 54,               /* params_form  */
  YYSYMBOL_list_params_form = 55,          /* list_params_form  */
  YYSYMBOL_param_form = 56,                /* param_form  */
  YYSYMBOL_main = 57,                      /* main  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_functions = 59,                 /* functions  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_function_end = 62,              /* function_end  */
  YYSYMBOL_stmts = 63,                     /* stmts  */
  YYSYMBOL_stmt = 64,                      /* stmt  */
  YYSYMBOL_for = 65,                       /* for  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_while = 67,                     /* while  */
  YYSYMBOL_68_6 = 68,                      /* $@6  */
  YYSYMBOL_if = 69,                        /* if  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_else = 72,                      /* else  */
  YYSYMBOL_73_9 = 73,                      /* $@9  */
  YYSYMBOL_command = 74,                   /* command  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_77_12 = 77,                     /* $@12  */
  YYSYMBOL_78_13 = 78,                     /* $@13  */
  YYSYMBOL_79_14 = 79,                     /* $@14  */
  YYSYMBOL_call_function = 80,             /* call_function  */
  YYSYMBOL_81_15 = 81,                     /* $@15  */
  YYSYMBOL_params_real = 82,               /* params_real  */
  YYSYMBOL_list_params_real = 83,          /* list_params_real  */
  YYSYMBOL_param_real = 84,                /* param_real  */
  YYSYMBOL_return = 85,                    /* return  */
  YYSYMBOL_atribuicao = 86,                /* atribuicao  */
  YYSYMBOL_expr = 87,                      /* expr  */
  YYSYMBOL_term = 88,                      /* term  */
  YYSYMBOL_types = 89,                     /* types  */
  YYSYMBOL_type_list = 90,                 /* type_list  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_ids = 92,                       /* ids  */
  YYSYMBOL_id_list = 93,                   /* id_list  */
  YYSYMBOL_id = 94,                        /* id  */
  YYSYMBOL_result_form = 95,               /* result_form  */
  YYSYMBOL_results = 96,                   /* results  */
  YYSYMBOL_result = 97                     /* result  */
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
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   133,   154,   155,   159,   178,   179,   180,
     184,   199,   230,   231,   236,   235,   260,   272,   273,   277,
     278,   282,   331,   330,   358,   359,   364,   363,   398,   431,
     432,   436,   437,   438,   439,   444,   443,   467,   466,   492,
     510,   491,   519,   518,   532,   536,   537,   538,   539,   540,
     542,   544,   546,   541,   581,   581,   581,   582,   583,   588,
     587,   632,   633,   637,   638,   642,   650,   669,   709,   739,
     762,   774,   789,   790,   794,   797,   800,   803,   807,   810,
     834,   838,   839,   843,   850,   854,   855,   859,   867,   870,
     871,   875,   876
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
  "FLOAT", "STRING", "BOOL", "ID", "OP", "RELOP", "LOGICOP",
  "LOGICOP_UNARY", "$accept", "tripcode", "$@1", "consts", "const",
  "variaveis", "dec_variavel", "def_variavel", "functions_header",
  "function_header", "$@2", "function_header_end", "params_form",
  "list_params_form", "param_form", "main", "$@3", "functions", "function",
  "$@4", "function_end", "stmts", "stmt", "for", "$@5", "while", "$@6",
  "if", "$@7", "$@8", "else", "$@9", "command", "$@10", "$@11", "$@12",
  "$@13", "$@14", "call_function", "$@15", "params_real",
  "list_params_real", "param_real", "return", "atribuicao", "expr", "term",
  "types", "type_list", "type", "ids", "id_list", "id", "result_form",
  "results", "result", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -127,     8,  -127,  -127,     5,   -21,  -127,    16,    57,    -4,
    -127,  -127,    14,   -13,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,    -3,     2,  -127,  -127,     9,    -9,    13,    22,    18,
    -127,  -127,    97,    28,  -127,     1,  -127,    97,    57,    11,
    -127,    19,    25,    30,    42,  -127,   189,    43,  -127,    57,
      57,    57,  -127,  -127,    32,    46,  -127,  -127,  -127,    53,
    -127,  -127,  -127,  -127,   204,  -127,    54,  -127,    64,    25,
      97,    50,    61,    62,    67,    74,    73,    75,    97,    70,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,    80,  -127,  -127,
      79,    25,    82,  -127,    86,  -127,    97,  -127,  -127,   100,
      97,    24,    97,     7,  -127,    89,  -127,    94,  -127,   -26,
     116,    57,   193,  -127,    39,    96,  -127,  -127,   204,   113,
    -127,  -127,  -127,  -127,   101,   126,   119,  -127,   120,  -127,
    -127,   125,  -127,   128,   127,  -127,   151,  -127,  -127,    98,
     150,   153,   160,   -26,   204,    57,   204,   139,  -127,  -127,
     113,  -127,  -127,  -127,   157,  -127,   158,   149,  -127,   132,
     174,   156,  -127,  -127,  -127,  -127,  -127,    57,  -127,   177,
     183,   196,   194,   176,   149,   185,  -127,   198,  -127,  -127,
    -127,  -127,   204,   204,  -127,  -127,   172,   188,  -127,  -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,     9,     0,     4,    13,     0,     0,
       7,     8,     0,     0,    74,    75,    76,    77,    79,    78,
       6,     0,     0,    12,    25,     0,     0,     0,     0,     3,
      59,    10,     0,     0,    14,     0,    24,    62,     0,     0,
      72,     0,    18,     0,     0,    64,    65,     0,    11,     0,
       0,     0,    71,    22,     0,     0,    20,    26,    60,    61,
      73,    68,    69,    70,     0,    21,     0,    15,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    45,    30,    31,    32,    33,    34,     0,    49,    47,
       0,     0,     0,    63,     0,    54,     0,    57,    58,     0,
       0,     0,     0,     0,    48,     0,    19,     0,    50,     0,
       0,     0,     0,    66,     0,     0,    29,    16,     0,     0,
      91,    92,    55,    90,     0,     0,     0,    67,     0,    30,
      83,     0,    82,     0,    88,    39,     0,    37,    23,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    27,    51,
       0,    56,    89,    30,     0,    30,     0,     0,    81,     0,
       0,     0,    28,    87,    52,    86,    40,     0,    38,     0,
      84,    44,     0,     0,     0,     0,    41,     0,    53,    85,
      42,    35,     0,     0,    30,    30,     0,     0,    43,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,  -127,  -127,   214,   217,  -127,  -127,
    -127,  -127,   166,  -127,   -87,  -127,  -127,  -127,  -127,  -127,
    -127,  -126,   -57,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   -63,  -127,
    -127,  -127,   167,  -127,  -127,   -30,    -8,  -127,  -127,    88,
    -127,  -127,    65,  -127,  -127,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     6,     7,    80,    81,    12,    23,
      42,    67,    55,    68,    56,    24,    64,    29,    36,    69,
     148,   103,   116,    83,   183,    84,   146,    85,   144,   171,
     176,   182,    86,   119,   157,   169,   109,   133,    19,    37,
      44,    59,    45,    88,    89,    46,    40,   131,   141,   132,
     164,   170,   165,   122,   134,   123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    87,    39,   139,   106,    27,    54,    82,     3,   120,
       5,     9,    31,    71,    72,    73,     8,    74,    75,    76,
       9,    32,   121,    77,    25,    13,    78,   159,    21,   161,
      47,    22,    48,    30,    26,    35,   115,    33,    43,    28,
      87,    61,    62,    63,    79,   113,    34,    53,   101,    49,
      50,    51,    52,    41,    57,    87,   121,    54,   186,   187,
     127,   129,    49,    50,    51,    52,   110,    58,    60,    65,
     112,    66,   114,    70,    94,    13,    87,    49,    50,    51,
      52,    87,    90,    87,    91,    95,    96,   153,    97,   155,
      14,    15,    16,    17,    18,    98,    87,    99,    87,   100,
     102,   104,     9,   125,    71,    72,    73,   107,    74,    75,
      76,   105,   108,   111,    77,    13,    13,    78,   117,    87,
      87,    38,   118,    87,    87,   184,   185,   147,   128,   135,
      14,    15,    16,    17,    18,    79,     9,   154,    71,    72,
      73,   124,    74,    75,    76,   130,   136,   137,    77,   138,
      13,    78,   140,   142,    49,    50,    51,    52,   143,   172,
       9,   166,    71,    72,    73,   145,    74,    75,    76,    79,
     149,   156,    77,   150,    13,    78,     9,   160,    71,    72,
      73,   151,    74,    75,    76,   168,   163,   162,    77,   167,
      13,    78,     9,    79,    71,    72,    73,   178,    74,    75,
      76,   188,   173,   174,    77,   175,    13,    78,     9,    79,
      71,    72,    73,   180,    74,    75,    76,   189,   126,   177,
      77,    10,    13,    78,    11,    79,   181,    49,    50,    51,
      52,    49,    50,    51,    52,    92,   152,    93,   158,   179,
       0,    79
};

static const yytype_int16 yycheck[] =
{
       8,    64,    32,   129,    91,     3,    32,    64,     0,    35,
       5,     4,    21,     6,     7,     8,    37,    10,    11,    12,
       4,    30,   109,    16,    37,    18,    19,   153,    32,   155,
      38,    17,    21,    24,    37,    17,    29,    24,    37,    37,
     103,    49,    50,    51,    37,    21,    24,    28,    78,    38,
      39,    40,    41,    25,    24,   118,   143,    32,   184,   185,
      21,   118,    38,    39,    40,    41,    96,    25,    25,    37,
     100,    25,   102,    20,    24,    18,   139,    38,    39,    40,
      41,   144,    28,   146,    20,    24,    24,   144,    21,   146,
      33,    34,    35,    36,    37,    21,   159,    24,   161,    24,
      30,    21,     4,   111,     6,     7,     8,    25,    10,    11,
      12,    32,    26,    13,    16,    18,    18,    19,    29,   182,
     183,    24,    28,   186,   187,   182,   183,    29,    32,    28,
      33,    34,    35,    36,    37,    37,     4,   145,     6,     7,
       8,    25,    10,    11,    12,    32,    20,    28,    16,    29,
      18,    19,    27,    25,    38,    39,    40,    41,    31,   167,
       4,    29,     6,     7,     8,    14,    10,    11,    12,    37,
      20,    32,    16,    20,    18,    19,     4,    20,     6,     7,
       8,    21,    10,    11,    12,    29,    37,    29,    16,    15,
      18,    19,     4,    37,     6,     7,     8,    21,    10,    11,
      12,    29,    25,    20,    16,     9,    18,    19,     4,    37,
       6,     7,     8,    28,    10,    11,    12,    29,    25,    25,
      16,     7,    18,    19,     7,    37,    28,    38,    39,    40,
      41,    38,    39,    40,    41,    69,   143,    70,   150,   174,
      -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,    45,     5,    46,    47,    37,     4,
      48,    49,    50,    18,    33,    34,    35,    36,    37,    80,
      88,    32,    17,    51,    57,    37,    37,     3,    37,    59,
      24,    21,    30,    24,    24,    17,    60,    81,    24,    87,
      88,    25,    52,    37,    82,    84,    87,    88,    21,    38,
      39,    40,    41,    28,    32,    54,    56,    24,    25,    83,
      25,    88,    88,    88,    58,    37,    25,    53,    55,    61,
      20,     6,     7,     8,    10,    11,    12,    16,    19,    37,
      48,    49,    64,    65,    67,    69,    74,    80,    85,    86,
      28,    20,    54,    84,    24,    24,    24,    21,    21,    24,
      24,    87,    30,    63,    21,    32,    56,    25,    26,    78,
      87,    13,    87,    21,    87,    29,    64,    29,    28,    75,
      35,    56,    95,    97,    25,    88,    25,    21,    32,    64,
      32,    89,    91,    79,    96,    28,    20,    28,    29,    63,
      27,    90,    25,    31,    70,    14,    68,    29,    62,    20,
      20,    21,    97,    64,    88,    64,    32,    76,    91,    63,
      20,    63,    29,    37,    92,    94,    29,    15,    29,    77,
      93,    71,    88,    25,    20,     9,    72,    25,    21,    94,
      28,    28,    73,    66,    64,    64,    63,    63,    29,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    43,    45,    45,    46,    47,    47,    47,
      48,    49,    50,    50,    52,    51,    53,    54,    54,    55,
      55,    56,    58,    57,    59,    59,    61,    60,    62,    63,
      63,    64,    64,    64,    64,    66,    65,    68,    67,    70,
      71,    69,    73,    72,    72,    74,    74,    74,    74,    74,
      75,    76,    77,    74,    78,    79,    74,    74,    74,    81,
      80,    82,    82,    83,    83,    84,    85,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    90,    90,    91,    92,    93,    93,    94,    95,    96,
      96,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     3,     2,     2,     0,
       4,     6,     2,     0,     0,     6,     4,     2,     0,     3,
       0,     2,     0,    11,     2,     0,     0,    10,     3,     2,
       0,     1,     1,     1,     1,     0,    16,     0,     9,     0,
       0,    11,     0,     6,     0,     1,     1,     1,     2,     1,
       0,     0,     0,    12,     0,     0,     7,     2,     2,     0,
       6,     2,     0,     3,     0,     1,     3,     4,     3,     3,
       3,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     3,     0,     1,     2,     3,     0,     1,     2,     3,
       0,     1,     1
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
#line 133 "translate.y"
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
#line 1367 "translate.tab.c"
    break;

  case 3: /* tripcode: $@1 consts variaveis functions_header main functions  */
#line 148 "translate.y"
    {
        verificar_definicao_funcoes_chamadas();
    }
#line 1375 "translate.tab.c"
    break;

  case 6: /* const: EXTERIOR ID term  */
#line 160 "translate.y"
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Definição de Constante: ");

            //conferir se já tem algo na tabela global com mesmo nome
            int resultado = identificador_disponivel((yyvsp[-1].lexema));
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro
                        
            // printf("\nDefinicao de constante do tipo %s com valor %s", $3.tipo, $3.valor);
            
            adicionar_simbolo(&escopo_atual, "CONSTANTE", (yyvsp[0].simbolo).tipo, (yyvsp[-1].lexema), (yyvsp[0].simbolo).valor, 1);
        }
#line 1395 "translate.tab.c"
    break;

  case 10: /* dec_variavel: BAGAGEM TYPE ID DOT_COMMA  */
#line 185 "translate.y"
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Declaração de Variável: ");
            int resultado = identificador_disponivel((yyvsp[-1].lexema));
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            adicionar_simbolo(&escopo_atual, "VARIAVEL", (yyvsp[-2].lexema), (yyvsp[-1].lexema), NULL, 0);
        }
#line 1411 "translate.tab.c"
    break;

  case 11: /* def_variavel: BAGAGEM TYPE ID ASSIGN expr DOT_COMMA  */
#line 200 "translate.y"
        {
            strcpy(msg_erro,""); //esvazia mensagem de erro
            strcat(msg_erro, "Definição de Variável: ");
            int resultado = identificador_disponivel((yyvsp[-3].lexema));
            if (resultado){
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            if ((strcmp((yyvsp[-4].lexema), (yyvsp[-1].simbolo).tipo) != 0)){
                strcat(msg_erro, "Definição de Variável: ");
                strcat(msg_erro, "O tipo do valor atribuido à variável '");
                strcat(msg_erro, (yyvsp[-3].lexema));
                strcat(msg_erro, "' é incompatível com tipo esperado! ('");
                strcat(msg_erro, (yyvsp[-4].lexema));
                strcat(msg_erro, "' <-> '");
                strcat(msg_erro, (yyvsp[-1].simbolo).tipo);
                strcat(msg_erro, "' => X)\n");
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro
            
            adicionar_simbolo(&escopo_atual, "VARIAVEL", (yyvsp[-4].lexema), (yyvsp[-3].lexema), (yyvsp[-1].simbolo).valor, 1);
            
            //adicionar ao código de três endereços
            adicionar_instrucao_TAC("", atual_temp(), "", (yyvsp[-3].lexema));
        }
#line 1443 "translate.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 236 "translate.y"
    {
        strcpy(msg_erro,""); //esvazia mensagem de erro
        strcat(msg_erro, "Protótipo de Funcao: ");

        int resultado = identificador_disponivel((yyvsp[-1].lexema));
        if (resultado){
            semantic_error();
        }
        strcpy(msg_erro,""); //reseta msg de erro

        //inicializar estrutura para armazenar informacoes da funcao
        Funcao *nova_funcao = NULL;
        inicializar_funcao(&nova_funcao, (yyvsp[-1].lexema));
        adicionar_nova_funcao(&funcoes, nova_funcao, &numero_de_funcoes);
        funcao_atual = nova_funcao;

        prototipo = 1; //mudar a flag para verdadeiro para que os parametros sejam adicionados na funcao atual

    }
#line 1467 "translate.tab.c"
    break;

  case 16: /* function_header_end: CLOSE_PARENTHESES OPEN_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 261 "translate.y"
    {
        set_tipo(&funcao_atual, (yyvsp[-1].lexema));
        
        adicionar_simbolo(&escopo_atual, "FUNCAO", (yyvsp[-1].lexema), funcao_atual->identificador, NULL, 0); //inicializado 

        prototipo = 0; //voltar a flag para falso
    }
#line 1479 "translate.tab.c"
    break;

  case 21: /* param_form: TYPE ID  */
#line 283 "translate.y"
        {
            if (prototipo){
                adicionar_parametro(&funcao_atual, (yyvsp[0].lexema), (yyvsp[-1].lexema));
            }
            if (definicao){
                //se nao for o prototipo tem que conferir se declarou igual está no prototipo = semantica
                adicionar_parametro(&funcao_temp, (yyvsp[0].lexema), (yyvsp[-1].lexema));
            }
            if (checkout){
                        
                Simbolo *simbolo = buscar_simbolo(escopo_atual,  (yyvsp[0].lexema));
                if (simbolo == NULL){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Chamada comando CHECKOUT: A variável '"); 
                    strcat(msg_erro, (yyvsp[0].lexema)); 
                    strcat(msg_erro, "' não foi previamente declarada!'\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");

                if (strcmp(simbolo->tipo, (yyvsp[-1].lexema)) != 0){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Chamada comando CHECKOUT:  A variável'");
                    strcat(msg_erro, (yyvsp[0].lexema));  
                    strcat(msg_erro, "' é uma variavel do tipo '"); 
                    strcat(msg_erro, simbolo->tipo); 
                    strcat(msg_erro, "' e não do tipo '"); 
                    strcat(msg_erro, (yyvsp[-1].lexema)); 
                    strcat(msg_erro, "'\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");

                //pra poder usar uma variável ela precisar ter sido inicializada
                if (simbolo->inicializado == 0){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "A variável '"); 
                    strcat(msg_erro, (yyvsp[0].lexema)); 
                    strcat(msg_erro, "' não foi previamente definida/inicializada!'\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");
            }
        }
#line 1528 "translate.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 331 "translate.y"
        {
            Funcao *nova_funcao = NULL;
            inicializar_funcao(&nova_funcao, "TRIP"); //pra poder verificar se tem pelo menos um retorno e se o tipo é MILHAS
            funcao_atual = nova_funcao;
            set_tipo(&funcao_atual, "MILHAS");

            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "MAIN");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1546 "translate.tab.c"
    break;

  case 23: /* main: ROTEIRO TRIP OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_CODEBLOCK $@3 stmt stmts CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 345 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;

            if (funcao_atual->retorno == 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Programa Principal 'TRIP': Está faltando retorno do tipo MILHAS\n"); 
                semantic_error();
            }
        }
#line 1561 "translate.tab.c"
    break;

  case 26: /* $@4: %empty  */
#line 364 "translate.y"
        {
            Funcao **funcao = buscar_funcao(funcoes, (yyvsp[-1].lexema), numero_de_funcoes); 
            if (funcao == NULL){

                strcpy(msg_erro,"");
                strcat(msg_erro, "Definição de Função: Protótipo da função '"); 
                strcat(msg_erro, (yyvsp[-1].lexema)); 
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
            inicializar_funcao(&aux, (yyvsp[-1].lexema));
            funcao_temp = aux;  
        }
#line 1596 "translate.tab.c"
    break;

  case 28: /* function_end: CLOSE_CODEBLOCK TYPE CLOSE_CODEBLOCK  */
#line 399 "translate.y"
        {
            if (definicao){

                strcpy(msg_erro,""); //esvazia mensagem de erro
                strcat(msg_erro, "Definicao de Funcao: ");

                set_tipo(&funcao_temp, (yyvsp[-1].lexema));

                int resultado = comparar_definicao_com_prototipo();
                if (resultado){
                    semantic_error();
                }
                strcpy(msg_erro,""); //reseta msg de erro

                if (funcao_atual->retorno == 0){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Definicao de Funcao '");
                    strcat(msg_erro, funcao_atual->identificador);
                    strcat(msg_erro, "': Faltando retorno do tipo '");
                    strcat(msg_erro, funcao_atual->tipo_retorno);
                    strcat(msg_erro, "'\n");
                    semantic_error();
                }

                // restaura o escopo anterior como o escopo atual
                escopo_atual = escopo_atual->anterior;
            }
            definicao = 0; 
        }
#line 1630 "translate.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 444 "translate.y"
        { 
            if (strcmp((yyvsp[-8].simbolo).tipo, "MILHAS") != 0 || strcmp((yyvsp[-5].simbolo).tipo, "MILHAS") != 0 || strcmp((yyvsp[-2].simbolo).tipo, "MILHAS") != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Bloco de Repeticao DECOLAR: todos termos devem ser do tipo 'MILHAS'\n");
                semantic_error();
            }
            strcpy(msg_erro,"");
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "DECOLAR");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1649 "translate.tab.c"
    break;

  case 36: /* for: DECOLAR OPEN_PARENTHESES ORIGEM term COMMA DESTINO term COMMA ESCALA term CLOSE_PARENTHESES OPEN_CODEBLOCK $@5 stmt stmts CLOSE_CODEBLOCK  */
#line 459 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1658 "translate.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 467 "translate.y"
        {
            if (strcmp((yyvsp[-2].simbolo).tipo, "BOOL") != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Bloco de Repeticao TURISTANDO: a condicao deve ser do tipo 'BOOL' e nao do tipo '");
                strcat(msg_erro, (yyvsp[-2].simbolo).tipo); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "TURISTANDO");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1680 "translate.tab.c"
    break;

  case 38: /* while: TURISTANDO OPEN_PARENTHESES expr CLOSE_PARENTHESES OPEN_CODEBLOCK $@6 stmt stmts CLOSE_CODEBLOCK  */
#line 485 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1689 "translate.tab.c"
    break;

  case 39: /* $@7: %empty  */
#line 492 "translate.y"
        {
            if (strcmp((yyvsp[-2].simbolo).tipo, "BOOL") != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Bloco Condicional ALFANDEGA: a condicao deve ser do tipo 'BOOL' e nao do tipo '");
                strcat(msg_erro, (yyvsp[-2].simbolo).tipo); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "ALFANDEGA");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1711 "translate.tab.c"
    break;

  case 40: /* $@8: %empty  */
#line 510 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1720 "translate.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 519 "translate.y"
        {
            TabelaSimbolos *nova_tabela = NULL;
            inicializar_tabela(&nova_tabela, escopo_atual, "ISENTO");
            adicionar_nova_tabela(&tabelas_simbolos, nova_tabela, &numero_de_tabelas);

            // atualiza o escopo atual para a nova tabela
            escopo_atual = nova_tabela;
        }
#line 1733 "translate.tab.c"
    break;

  case 43: /* else: ISENTO OPEN_CODEBLOCK $@9 stmt stmts CLOSE_CODEBLOCK  */
#line 528 "translate.y"
        {
            // restaura o escopo anterior como o escopo atual
            escopo_atual = escopo_atual->anterior;
        }
#line 1742 "translate.tab.c"
    break;

  case 50: /* $@10: %empty  */
#line 542 "translate.y"
        {qtd_tipos_checkin = 0;}
#line 1748 "translate.tab.c"
    break;

  case 51: /* $@11: %empty  */
#line 544 "translate.y"
        { qtd_ids_checkin=0; }
#line 1754 "translate.tab.c"
    break;

  case 52: /* $@12: %empty  */
#line 546 "translate.y"
            {
                if (qtd_tipos_checkin != qtd_ids_checkin){
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Chamada comando CHECKIN: Quantidade de Tipos != Quantidade de Variáveis!\n"); 
                    semantic_error();
                }
                for (int i=0; i<qtd_ids_checkin; i++){
                    Simbolo *simbolo = buscar_simbolo(escopo_atual,  ids_checkin[i]);
                    if (simbolo == NULL){
                        strcpy(msg_erro,"");
                        strcat(msg_erro, "Chamada comando CHECKIN: A variável '"); 
                        strcat(msg_erro, ids_checkin[i]); 
                        strcat(msg_erro, "' não foi previamente declarada!'\n"); 
                        semantic_error();
                    }
                    strcpy(msg_erro,"");

                    if (strcmp(simbolo->tipo, tipos_checkin[i]) != 0){
                        strcpy(msg_erro,"");
                        strcat(msg_erro, "Chamada comando CHECKOUT:  A variável'");
                        strcat(msg_erro, ids_checkin[i]);  
                        strcat(msg_erro, "' é uma variavel do tipo '"); 
                        strcat(msg_erro, simbolo->tipo); 
                        strcat(msg_erro, "' e não do tipo '"); 
                        strcat(msg_erro, tipos_checkin[i]); 
                        strcat(msg_erro, "'\n"); 
                        semantic_error();
                    }
                    strcpy(msg_erro,"");

                    simbolo->inicializado == 1;
                    simbolo->valor = strdup("?"); //vai ser inicializada mas não sei o valor em tempo de compilação
                }
            }
#line 1793 "translate.tab.c"
    break;

  case 54: /* $@13: %empty  */
#line 581 "translate.y"
                                {checkout = 1;}
#line 1799 "translate.tab.c"
    break;

  case 55: /* $@14: %empty  */
#line 581 "translate.y"
                                                            {checkout = 0;}
#line 1805 "translate.tab.c"
    break;

  case 59: /* $@15: %empty  */
#line 588 "translate.y"
        {
            qtd_parametros_reais = 0; //sempre reiniciando o contador vai sobreescrevendo
        }
#line 1813 "translate.tab.c"
    break;

  case 60: /* call_function: EMBARCAR ID OPEN_PARENTHESES $@15 params_real CLOSE_PARENTHESES  */
#line 592 "translate.y"
        {
            Funcao **funcao = buscar_funcao(funcoes, (yyvsp[-4].lexema), numero_de_funcoes); 

            if (funcao == NULL){
                prototipo = 0;

                strcpy(msg_erro,"");
                strcat(msg_erro, "Chamada de Função: Protótipo da função '"); 
                strcat(msg_erro, (yyvsp[-4].lexema)); 
                strcat(msg_erro, "' não foi declarado\n"); 
                semantic_error();
            }
            strcpy(msg_erro,""); //reseta msg de erro

            // Verifica a quantidade de parâmetros
            if (qtd_parametros_reais != (*funcao)->qtd_parametros) {
                strcpy(msg_erro, "Chamada de Função: Número incorreto de parâmetros na função '");
                strcat(msg_erro, (yyvsp[-4].lexema)); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }

            //tipos dos parâmetros
            for (int i = 0; i < qtd_parametros_reais; i++) {
                if (strcmp(tipos_parametros_reais[i], (*funcao)->parametros[i]->tipo) != 0) {
                    strcpy(msg_erro, "Chamada de Função: Tipos de parâmetros incompatíveis na função '");
                    strcat(msg_erro, (yyvsp[-4].lexema)); 
                    strcat(msg_erro, "'\n"); 
                    semantic_error();
                }
            }

            (*funcao)->chamada = 1;

            (yyval.simbolo).tipo = (*funcao)->tipo_retorno;
            (yyval.simbolo).valor = strdup("?"); //com o retorno da funcao vai armazenar o valor mas em tempo de compilacao não da pra saber qual
        }
#line 1855 "translate.tab.c"
    break;

  case 65: /* param_real: expr  */
#line 643 "translate.y"
        {
            tipos_parametros_reais[qtd_parametros_reais] = (yyvsp[0].simbolo).tipo;
            qtd_parametros_reais += 1;
        }
#line 1864 "translate.tab.c"
    break;

  case 66: /* return: DESPACHAR expr DOT_COMMA  */
#line 651 "translate.y"
        {   
            if((strcmp((yyvsp[-1].simbolo).tipo, funcao_atual->tipo_retorno) != 0)){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Retorno função '");
                strcat(msg_erro, funcao_atual->identificador);
                strcat(msg_erro, "': Tipo Incompatível, esperado: '");
                strcat(msg_erro, funcao_atual->tipo_retorno);
                strcat(msg_erro, "'\n");
                semantic_error();
            }

            funcao_atual->retorno = 1;

            //onde armazenar o valor do retorno? 
        }
#line 1884 "translate.tab.c"
    break;

  case 67: /* atribuicao: ID ASSIGN expr DOT_COMMA  */
#line 670 "translate.y"
        { 
            Simbolo *simbolo = buscar_simbolo(escopo_atual,  (yyvsp[-3].lexema));
            if (simbolo == NULL){
                strcpy(msg_erro,"");
                strcat(msg_erro, "A variável '"); 
                strcat(msg_erro, (yyvsp[-3].lexema)); 
                strcat(msg_erro, "' não foi previamente declarada!'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            if (strcmp(simbolo->descricao, "CONSTANTE") == 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Atribuição: Não é possível fazer reatribuição de CONSTANTE\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            if (strcmp(simbolo->tipo, (yyvsp[-1].simbolo).tipo) != 0){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Atribuição: Não é possível atribuir um valor do tipo '");
                strcat(msg_erro, (yyvsp[-1].simbolo).tipo);  
                strcat(msg_erro, "' a uma variavel do tipo '"); 
                strcat(msg_erro, simbolo->tipo); 
                strcat(msg_erro, "'\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");

            //se foi possível fazer atribuição foi armazenado um valor na variável então ela foi inicializada
            simbolo->inicializado = 1;
            simbolo->valor = (yyvsp[-1].simbolo).valor; // ou só coloca strdup("?"); //saber o valor certinho em tempo de execução

            //acessar atributos da variavel expressao:
             //printf("\n Atributos da expressao: %s, %s", $3.tipo, $3.valor);
        }
#line 1925 "translate.tab.c"
    break;

  case 68: /* expr: expr OP term  */
#line 710 "translate.y"
        {
            if ( (strcmp((yyvsp[-2].simbolo).tipo, "VOUCHER") == 0) || (strcmp((yyvsp[0].simbolo).tipo, "VOUCHER") == 0) ){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Aritimética: Ainda não está disponível manipular variáveis do tipo VOUCHER com operações aritméticas =(");
                semantic_error();
            }
            strcpy(msg_erro,"");

            if ( (strcmp((yyvsp[-2].simbolo).tipo, "BOOL") == 0) || (strcmp((yyvsp[0].simbolo).tipo, "BOOL") == 0) ){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Aritimética: Operandos devem ser de tipos numéricos (MILHAS ou DOLAR)");
                semantic_error();
            }
            strcpy(msg_erro,"");
            
            //o resultado só vai ser do tipo MILHAS se os dois operandos forem do tipo MILHAS (inclusive na divisao)
            if ( (strcmp((yyvsp[-2].simbolo).tipo, "MILHAS") == 0) && (strcmp((yyvsp[0].simbolo).tipo, "MILHAS") == 0) ){
                (yyval.simbolo).tipo = "MILHAS";
            }
            else{
                (yyval.simbolo).tipo = "DOLAR";
            }
            (yyval.simbolo).valor = novo_temp(); 

            //adicionar ao código de três endereços
            adicionar_instrucao_TAC((yyvsp[-1].lexema), (yyvsp[-2].simbolo).valor, (yyvsp[0].simbolo).valor, (yyval.simbolo).valor); 

        }
#line 1958 "translate.tab.c"
    break;

  case 69: /* expr: expr RELOP term  */
#line 740 "translate.y"
        { 
            if ( (strcmp((yyvsp[-2].simbolo).tipo, "VOUCHER") == 0) || (strcmp((yyvsp[0].simbolo).tipo, "VOUCHER") == 0) ){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Relacional: Ainda não está diponível para variáveis do tipo VOUCHER =(");
                semantic_error();
            }
            strcpy(msg_erro,"");


            if ( (strcmp((yyvsp[-2].simbolo).tipo, "BOOL") == 0) || (strcmp((yyvsp[0].simbolo).tipo, "BOLL") == 0) ){
                if ( (strcmp((yyvsp[-1].lexema), "#") != 0) && (strcmp((yyvsp[-1].lexema), "=") != 0) ) //se não está vendo se igual nem se diferente
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Operação Relacionados: Para que os operandos sejam booleanos o operados tem que ser '=' ou '#'");
                    semantic_error();
            }
            strcpy(msg_erro,"");

            //para valores numéricos não tem restrição
            (yyval.simbolo).tipo = "BOOL";
            (yyval.simbolo).valor = novo_temp();
        }
#line 1984 "translate.tab.c"
    break;

  case 70: /* expr: expr LOGICOP term  */
#line 763 "translate.y"
        { 
            if ((strcmp((yyvsp[-2].simbolo).tipo, "BOOL") != 0) || (strcmp((yyvsp[0].simbolo).tipo, "BOOL") != 0)){
                strcpy(msg_erro,"");
                strcat(msg_erro, "Operação Lógica: Operadores lógicos só podem ser aplicados ao tipo BOOL\n"); 
                semantic_error();
            }
            strcpy(msg_erro,"");
            (yyval.simbolo).tipo = (yyvsp[-2].simbolo).tipo;
            (yyval.simbolo).valor = novo_temp();
        }
#line 1999 "translate.tab.c"
    break;

  case 71: /* expr: expr LOGICOP_UNARY  */
#line 775 "translate.y"
            {
                if (strcmp((yyvsp[-1].simbolo).tipo, "BOOL") != 0) {
                    strcpy(msg_erro,"");
                    strcat(msg_erro, "Operação Lógica Unária: O operador NOT não pode ser aplicado ao tipo'"); 
                    strcat(msg_erro, (yyvsp[-1].simbolo).tipo); 
                    strcat(msg_erro, "' apenas ao tipo BOOL\n"); 
                    semantic_error();
                }
                strcpy(msg_erro,"");
                
                (yyval.simbolo).tipo = (yyvsp[-1].simbolo).tipo;
                (yyval.simbolo).valor = novo_temp(); //depois olhar se teria como já criar com um contator tipo temp1
            }
#line 2017 "translate.tab.c"
    break;

  case 72: /* expr: term  */
#line 789 "translate.y"
           {(yyval.simbolo) = (yyvsp[0].simbolo);}
#line 2023 "translate.tab.c"
    break;

  case 73: /* expr: OPEN_PARENTHESES term CLOSE_PARENTHESES  */
#line 790 "translate.y"
                                              {(yyval.simbolo) = (yyvsp[-1].simbolo);}
#line 2029 "translate.tab.c"
    break;

  case 74: /* term: INT  */
#line 794 "translate.y"
        {
        (yyval.simbolo) = (Simbolo){ .tipo = "MILHAS", .valor = (yyvsp[0].lexema) };
    }
#line 2037 "translate.tab.c"
    break;

  case 75: /* term: FLOAT  */
#line 797 "translate.y"
            {
        (yyval.simbolo) = (Simbolo){ .tipo = "DOLAR", .valor = (yyvsp[0].lexema) };
    }
#line 2045 "translate.tab.c"
    break;

  case 76: /* term: STRING  */
#line 800 "translate.y"
             {
        (yyval.simbolo) = (Simbolo){ .tipo = "VOUCHER", .valor = (yyvsp[0].lexema) };
    }
#line 2053 "translate.tab.c"
    break;

  case 77: /* term: BOOL  */
#line 803 "translate.y"
           {
        (yyval.simbolo) = (Simbolo){ .tipo = "BOOL", .valor = (yyvsp[0].lexema) };
    }
#line 2061 "translate.tab.c"
    break;

  case 78: /* term: call_function  */
#line 807 "translate.y"
                    { 
        (yyval.simbolo) = (Simbolo){ .tipo = (yyvsp[0].simbolo).tipo, .valor = (yyvsp[0].simbolo).valor }; 
    }
#line 2069 "translate.tab.c"
    break;

  case 79: /* term: ID  */
#line 810 "translate.y"
         {
        Simbolo *simbolo = buscar_simbolo(escopo_atual, (yyvsp[0].lexema));
        if (simbolo == NULL) {
            strcpy(msg_erro,"");
            strcat(msg_erro, "A variável '"); 
            strcat(msg_erro, (yyvsp[0].lexema)); 
            strcat(msg_erro, "' não foi previamente declarada!\n"); 
            semantic_error();
        }

        if (simbolo->inicializado == 0) {
            strcpy(msg_erro,"");
            strcat(msg_erro, "A variável '"); 
            strcat(msg_erro, (yyvsp[0].lexema)); 
            strcat(msg_erro, "' não foi previamente definida/inicializada!\n"); 
            semantic_error();
        }

        (yyval.simbolo) = (Simbolo){ .tipo = simbolo->tipo, .valor = simbolo->identificador }; //já recebe o simbolo com todos os valores já armazenados na tabela de simbolos
    }
#line 2094 "translate.tab.c"
    break;

  case 83: /* type: TYPE  */
#line 844 "translate.y"
        {      
            tipos_checkin[qtd_tipos_checkin] = (yyvsp[0].lexema);
            qtd_tipos_checkin += 1;
        }
#line 2103 "translate.tab.c"
    break;

  case 87: /* id: ID  */
#line 860 "translate.y"
        {      
            ids_checkin[qtd_ids_checkin] = (yyvsp[0].lexema);
            qtd_ids_checkin += 1;
        }
#line 2112 "translate.tab.c"
    break;


#line 2116 "translate.tab.c"

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

#line 880 "translate.y"

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
    if (verificar_simbolo_escopo_local(escopo_atual, identificador)) {
        strcat(msg_erro, "' já está sendo usado!\n");
        return 1;
    }

    //se escopo local nao for o global tem que conferir se já existe constante com mesmo identificador no escobo global
    if (escopo_atual->anterior != NULL) {
        // Percorre a tabela de símbolos do escopo global para verificar se o identificador já foi usado para uma constante:
        TabelaSimbolos *escopo_global = tabelas_simbolos[0];
        
        if (verificar_constante(escopo_global, identificador)) {
            strcat(msg_erro, "' já está sendo usado para identificar uma constante!\n");
            return 1;
        }
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
    if(yyparse() == 0) {  
    
        printf("\n\n\033[1;32mPrograma sintaticamente correto.\033[0m\n\n");

    imprimir_todas_tabelas_simbolos(tabelas_simbolos, numero_de_tabelas);

    imprimir_TAC();
    }

    return 0;
}
