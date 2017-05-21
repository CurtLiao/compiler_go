/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
symbol_table global_st;
int variable_type; // 0=> int 1=> bool 2=> string 3=>real
bool const_flag = false;
enum Type_enum{T_INT = 0, T_BOOL = 1, T_STR, T_REAL};
enum State_enum{S_PRIMITIVE = 0, S_ID = 1, S_ARRAY = 2};

int yylex();
int yyerror(char *s);
char* declared_err = "declared error";
char* type_match_err= "type match error";
char* arr_id_err= "array index should be integer";


#line 86 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    BREAK = 259,
    CASE = 260,
    CONST = 261,
    CONTINUE = 262,
    DEFAULT = 263,
    ELSE = 264,
    FALSE = 265,
    FOR = 266,
    FUNC = 267,
    GO = 268,
    IF = 269,
    IMPORT = 270,
    INT = 271,
    NIL = 272,
    PRINT = 273,
    PRINTLN = 274,
    REAL = 275,
    RETURN = 276,
    STRING = 277,
    STRUCT = 278,
    SWITCH = 279,
    TRUE = 280,
    TYPE = 281,
    VAR = 282,
    VOID = 283,
    WHILE = 284,
    READ = 285,
    LESS_EQUAL = 286,
    GREAT_EQUAL = 287,
    EQUAL = 288,
    NOT_EQUAL = 289,
    AND = 290,
    ADD_ASSIGNMENT = 291,
    SUB_ASSIGNMENT = 292,
    MUL_ASSIGNMENT = 293,
    DIV_ASSIGNMENT = 294,
    NUMBER = 295,
    STR = 296,
    ID = 297,
    REAL_NUMBER = 298,
    UMINUS = 299
  };
#endif
/* Tokens.  */
#define BOOL 258
#define BREAK 259
#define CASE 260
#define CONST 261
#define CONTINUE 262
#define DEFAULT 263
#define ELSE 264
#define FALSE 265
#define FOR 266
#define FUNC 267
#define GO 268
#define IF 269
#define IMPORT 270
#define INT 271
#define NIL 272
#define PRINT 273
#define PRINTLN 274
#define REAL 275
#define RETURN 276
#define STRING 277
#define STRUCT 278
#define SWITCH 279
#define TRUE 280
#define TYPE 281
#define VAR 282
#define VOID 283
#define WHILE 284
#define READ 285
#define LESS_EQUAL 286
#define GREAT_EQUAL 287
#define EQUAL 288
#define NOT_EQUAL 289
#define AND 290
#define ADD_ASSIGNMENT 291
#define SUB_ASSIGNMENT 292
#define MUL_ASSIGNMENT 293
#define DIV_ASSIGNMENT 294
#define NUMBER 295
#define STR 296
#define ID 297
#define REAL_NUMBER 298
#define UMINUS 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "yacc.y" /* yacc.c:355  */

    struct
    {
        union{
            char *name;
            int  val;
            bool flag;
        };
        int arr_idx;
        int token_type;
        int state; //0 => id || 1 => primitive type
    }Token;

#line 228 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    48,    53,     2,
      58,    59,    46,    44,    60,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
      50,    61,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,    54,    63,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   106,   130,   136,   137,   138,   138,   138,   139,
     139,   140,   140,   140,   140,   140,   140,   141,   142,   143,
     147,   149,   149,   151,   152,   153,   154,   155,   156,   157,
     160,   161,   162,   163,   164,   165,   167,   168,   170,   171,
     173,   178,   183,   187,   192,   198,   203,   210,   243,   255,
     304,   305,   306,   307,   308,   311,   312,   313,   318,   323,
     328,   331,   335,   336,   337,   338,   344,   350,   356,   363,
     364,   368,   369,   369,   371,   373,   374,   376,   377,   378,
     379,   380,   381,   382,   383,   385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "BREAK", "CASE", "CONST",
  "CONTINUE", "DEFAULT", "ELSE", "FALSE", "FOR", "FUNC", "GO", "IF",
  "IMPORT", "INT", "NIL", "PRINT", "PRINTLN", "REAL", "RETURN", "STRING",
  "STRUCT", "SWITCH", "TRUE", "TYPE", "VAR", "VOID", "WHILE", "READ",
  "LESS_EQUAL", "GREAT_EQUAL", "EQUAL", "NOT_EQUAL", "AND",
  "ADD_ASSIGNMENT", "SUB_ASSIGNMENT", "MUL_ASSIGNMENT", "DIV_ASSIGNMENT",
  "NUMBER", "STR", "ID", "REAL_NUMBER", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'^'", "'<'", "'>'", "'!'", "'&'", "'|'", "UMINUS", "'['", "']'", "'('",
  "')'", "','", "'='", "'{'", "'}'", "';'", "$accept", "primitive_type",
  "primitive", "bool_type", "array_element", "object", "op_order2",
  "op_order3", "op_order4", "op_order5", "op_order6", "op_order7",
  "op_order8", "program", "statements", "statement", "func_declared",
  "formal_args", "declared", "identifier_list", "identifier_declared",
  "simple_statement", "expression", "bool_exp", "mix_exp", "compound",
  "$@1", "func_invoke", "condition", "for_loop", "go", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    43,    45,    42,    47,    37,    94,
      60,    62,    33,    38,   124,   299,    91,    93,    40,    41,
      44,    61,   123,   125,    59
};
# endif

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     161,   -39,   -48,   198,   -29,   -36,   167,   167,   167,   -39,
     -16,    41,   -31,  -110,   -13,    45,  -110,   161,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,   -11,     7,    97,
    -110,  -110,  -110,  -110,    17,     6,    27,    23,   144,  -110,
    -110,  -110,  -110,    19,  -110,   167,   167,  -110,  -110,  -110,
     187,   187,   187,    18,  -110,   167,   -39,  -110,   161,   144,
    -110,  -110,   -39,   107,   144,   144,   -13,    26,   187,   196,
      31,     3,    38,   -39,   235,  -110,   270,  -110,  -110,  -110,
    -110,  -110,  -110,   167,   167,   167,    22,    40,    43,    44,
     167,  -110,   276,    47,    39,   187,   259,  -110,  -110,  -110,
    -110,   270,   245,   144,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,    58,   161,   144,   144,   144,   144,     8,
      50,    77,    62,    11,    64,   161,  -110,   187,   187,   187,
      25,    86,    85,    88,   290,  -110,  -110,  -110,  -110,   211,
    -110,  -110,    71,   259,   259,   259,   259,    50,    72,  -110,
      73,    50,    50,    75,  -110,   127,  -110,  -110,  -110,  -110,
     195,    58,   161,    58,  -110,    50,   195,  -110,  -110,    50,
     161,  -110,  -110,  -110,    82,  -110,  -110,  -110,  -110,  -110,
    -110,    58,  -110,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,    13,    82,    14,     0,     0,    30,    31,    48,    33,
      49,    34,    35,    36,    37,    38,    39,    51,     0,     0,
       3,     2,     5,     4,     0,     0,     0,     0,     0,    11,
      10,     6,     8,    13,     9,     0,     0,    66,     7,    65,
      60,    61,    63,     0,    62,     0,     0,    81,     0,     0,
       1,    32,     0,     0,     0,     0,    65,     0,    72,     0,
       0,     0,     0,     0,     0,    70,     0,    19,    20,    16,
      17,    18,    15,     0,     0,     0,     3,     2,     5,     4,
       0,    52,     0,     0,     0,    72,    79,    59,    50,    58,
      74,    72,     0,     0,    23,    24,    25,    26,    21,    22,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    69,    68,    67,
       0,     0,     0,     0,     0,    12,    84,    83,    73,     0,
      87,    88,     0,    78,    77,    76,    75,     0,     0,    44,
      46,     0,     0,     0,    95,    85,    54,    53,    56,    55,
       0,     0,     0,     0,    42,     0,     0,    45,    40,     0,
       0,    57,    89,    90,     0,    91,    92,    43,    47,    41,
      86,     0,    93,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,    -2,    81,    15,  -110,     0,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,    20,   -27,  -110,  -103,  -110,     9,
    -110,  -109,     1,   -23,  -110,  -108,  -110,  -110,  -110,  -110,
    -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,   121,    47,    48,    13,    49,    83,    84,    85,   115,
     116,   117,   118,    15,    16,    17,    18,   122,    19,    28,
      20,    21,    68,    69,    97,    22,    58,    23,    24,    25,
      26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,    36,    67,    27,   140,   141,    30,    50,    51,    52,
      29,    30,   149,    37,    30,    74,   148,    14,    53,    31,
     153,    86,    38,    32,    31,    33,    54,    31,    32,    66,
      33,    32,    57,    33,    87,    39,    96,    61,    88,   164,
      89,   100,   102,   167,   168,    60,    75,    76,    59,    62,
      40,    91,   172,   173,   175,   176,    92,   177,    14,    70,
      95,   179,   120,   178,    71,    93,   101,   147,    63,    72,
     152,    98,   182,   183,    90,    55,     6,     7,    94,     8,
     139,    73,   124,   130,   127,   128,   129,   142,    10,   119,
     103,   134,   143,   144,   145,   146,   123,    55,   155,    56,
      43,   131,   137,     1,   132,   133,   136,    39,     2,     3,
       4,     5,    12,    14,    14,     6,     7,    39,     8,   150,
      12,   151,    40,   154,     9,    14,   157,    10,   158,   159,
     163,   165,    40,   166,   169,   174,   170,    41,    42,    11,
      44,   181,    45,   180,    99,   156,     0,    41,    42,    64,
      44,     0,     0,     0,    39,    65,     0,     0,   171,    12,
       0,    14,    14,    14,     0,     0,     0,     1,     0,    40,
      14,     0,     2,     3,     4,     5,     0,    39,     0,     6,
       7,    14,     8,     0,    41,    42,    43,    44,     9,    45,
       0,    10,    40,     0,     0,     0,    64,     0,    30,     0,
       0,    30,    65,    11,     0,     0,     0,    41,    42,    43,
      44,    31,    45,     0,    31,    32,     0,    33,    32,     0,
      33,     0,     0,    12,     0,    46,    34,   104,   105,   106,
     107,    77,    78,    79,    80,    81,    82,     0,     0,     0,
      35,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     114,   108,   109,   110,   111,   112,   104,   105,   106,   107,
     161,     0,     0,     0,     0,   162,   104,   105,   106,   107,
       0,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     104,   105,   106,   107,   125,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   138,     0,     0,     0,     0,   108,
     109,   110,   111,   112,    77,    78,    79,    80,    81,    82,
      77,    78,    79,    80,    81,    82,     0,     0,     0,   126,
       0,     0,     0,   135,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,     0,     0,     0,   160
};

static const yytype_int16 yycheck[] =
{
       0,     3,    29,    42,   113,   113,     3,     6,     7,     8,
      58,     3,   120,    42,     3,    38,   119,    17,     9,    16,
     123,     3,    58,    20,    16,    22,    42,    16,    20,    29,
      22,    20,    63,    22,    16,    10,    59,    17,    20,   147,
      22,    64,    65,   151,   152,     0,    45,    46,    61,    60,
      25,    53,   161,   161,   163,   163,    55,   165,    58,    42,
      59,   169,    59,   166,    58,    56,    65,    59,    61,    42,
      59,    62,   181,   181,    56,    56,    18,    19,    58,    21,
     103,    58,    73,    61,    83,    84,    85,   114,    30,    58,
      64,    90,   115,   116,   117,   118,    58,    56,   125,    58,
      42,    61,    63,     6,    61,    61,    59,    10,    11,    12,
      13,    14,    62,   113,   114,    18,    19,    10,    21,    42,
      62,    59,    25,    59,    27,   125,    40,    30,    43,    41,
      59,    59,    25,    60,    59,   162,     9,    40,    41,    42,
      43,    59,    45,   170,    63,   130,    -1,    40,    41,    52,
      43,    -1,    -1,    -1,    10,    58,    -1,    -1,   160,    62,
      -1,   161,   162,   163,    -1,    -1,    -1,     6,    -1,    25,
     170,    -1,    11,    12,    13,    14,    -1,    10,    -1,    18,
      19,   181,    21,    -1,    40,    41,    42,    43,    27,    45,
      -1,    30,    25,    -1,    -1,    -1,    52,    -1,     3,    -1,
      -1,     3,    58,    42,    -1,    -1,    -1,    40,    41,    42,
      43,    16,    45,    -1,    16,    20,    -1,    22,    20,    -1,
      22,    -1,    -1,    62,    -1,    58,    28,    31,    32,    33,
      34,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      42,    -1,    31,    32,    33,    34,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      64,    50,    51,    52,    53,    54,    31,    32,    33,    34,
      59,    -1,    -1,    -1,    -1,    64,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      31,    32,    33,    34,    59,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    44,    45,    46,    47,    48,    49,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    57,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    12,    13,    14,    18,    19,    21,    27,
      30,    42,    62,    69,    70,    78,    79,    80,    81,    83,
      85,    86,    90,    92,    93,    94,    95,    42,    84,    58,
       3,    16,    20,    22,    28,    42,    66,    42,    58,    10,
      25,    40,    41,    42,    43,    45,    58,    67,    68,    70,
      87,    87,    87,    84,    42,    56,    58,    63,    91,    61,
       0,    79,    60,    61,    52,    58,    70,    80,    87,    88,
      42,    58,    42,    58,    88,    87,    87,    44,    45,    46,
      47,    48,    49,    71,    72,    73,     3,    16,    20,    22,
      56,    66,    87,    84,    79,    87,    88,    89,    84,    67,
      88,    87,    88,    64,    31,    32,    33,    34,    50,    51,
      52,    53,    54,    59,    64,    74,    75,    76,    77,    58,
      59,    66,    82,    58,    84,    59,    59,    87,    87,    87,
      61,    61,    61,    61,    87,    57,    59,    63,    59,    88,
      86,    90,    80,    88,    88,    88,    88,    59,    82,    90,
      42,    59,    59,    82,    59,    80,    68,    40,    43,    41,
      57,    59,    64,    59,    90,    59,    60,    90,    90,    59,
       9,    66,    86,    90,    80,    86,    90,    90,    82,    90,
      80,    59,    86,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      68,    68,    69,    70,    70,    71,    72,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    76,    77,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    91,    90,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       6,     7,     6,     7,     5,     6,     2,     4,     1,     1,
       3,     1,     3,     5,     5,     5,     5,     6,     4,     3,
       2,     2,     2,     2,     1,     1,     1,     3,     3,     3,
       2,     3,     1,     3,     2,     3,     3,     3,     3,     1,
       1,     2,     0,     4,     4,     5,     7,     5,     5,     7,
       7,     7,     7,     9,     9,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 102 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type =  T_INT; }
#line 1488 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 102 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_BOOL;}
#line 1494 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 102 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_STR;}
#line 1500 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 102 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_REAL;}
#line 1506 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 103 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_INT; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).val = (yyvsp[0].Token).val; }
#line 1512 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 103 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = (yyvsp[0].Token).flag; }
#line 1518 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 103 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_STR; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).name = (yyvsp[0].Token).name; }
#line 1524 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 103 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_REAL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).name = (yyvsp[0].Token).name; }
#line 1530 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 104 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = true;}
#line 1536 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 104 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = false;}
#line 1542 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 106 "yacc.y" /* yacc.c:1661  */
    {
            //if its expression isn't int then it will abort
            //if it is ID or array elemeny check type
            if((yyvsp[-1].Token).state == S_ID){
                if (global_st.lookup_variable((yyvsp[-1].Token).name).type != T_INT){
                    yyerror(arr_id_err);
                }
            }
            else if((yyvsp[-1].Token).state == S_ARRAY){
                if(global_st.lookup_array((yyvsp[-1].Token).name, (yyvsp[-1].Token).arr_idx).type != T_INT)
                    yyerror(declared_err);
            }
            //if it is primitive
            else {
                if((yyvsp[-1].Token).token_type != T_INT){
                    yyerror(arr_id_err);
                }
            }
            (yyval.Token).name = (yyvsp[-3].Token).name;
            //Todo::set 0 because expression can not calculate
            (yyval.Token).arr_idx = 0;
            (yyval.Token).state = S_ARRAY; 
            (yyval.Token).token_type = global_st.lookup_array((yyval.Token).name, (yyval.Token).arr_idx).type;  
        }
#line 1571 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 130 "yacc.y" /* yacc.c:1661  */
    {
                (yyval.Token) = (yyvsp[0].Token);
                // $$.name = $1.name; 
                (yyval.Token).state = S_ID; 
                (yyval.Token).token_type = global_st.lookup_variable((yyvsp[0].Token).name).type; 
            }
#line 1582 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 136 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1588 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 147 "yacc.y" /* yacc.c:1661  */
    {Trace("Reducing to program\n");}
#line 1594 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 151 "yacc.y" /* yacc.c:1661  */
    { Trace("declare id \n");}
#line 1600 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 152 "yacc.y" /* yacc.c:1661  */
    { Trace("simple statement\n");}
#line 1606 "y.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 173 "yacc.y" /* yacc.c:1661  */
    {  
            printf("\t id , identifier_list || id = %s\n", (yyvsp[-2].Token).name); 
            strcat((yyval.Token).name, " "); 
            strcat((yyval.Token).name, (yyvsp[0].Token).name);
        }
#line 1616 "y.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 178 "yacc.y" /* yacc.c:1661  */
    {
            // printf("\t id in identifier_list || id = %s\n", $1.name); 
            (yyval.Token).name = (yyvsp[0].Token).name; 
        }
#line 1625 "y.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 183 "yacc.y" /* yacc.c:1661  */
    { 
            if(!global_st.declared((yyvsp[-1].Token).name, (yyvsp[0].Token).token_type))
                yyerror(declared_err);
        }
#line 1634 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 187 "yacc.y" /* yacc.c:1661  */
    {
            variable v(T_INT, 0, (yyvsp[0].Token).val); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1644 "y.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 192 "yacc.y" /* yacc.c:1661  */
    {
            printf("T_BOOL = %d\n", T_BOOL);
            variable v(T_BOOL, 0, (yyvsp[0].Token).flag); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1655 "y.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 198 "yacc.y" /* yacc.c:1661  */
    { 
            variable v(T_STR, 0, (yyvsp[0].Token).name); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1665 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 203 "yacc.y" /* yacc.c:1661  */
    {
            variable v(T_REAL, 0, (yyvsp[0].Token).name); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1675 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 210 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).state == S_ID){
                if (global_st.lookup_variable((yyvsp[-2].Token).name).type != T_INT){
                    yyerror(arr_id_err);
                }
            }
            else if ((yyvsp[-2].Token).state == S_ARRAY){
                if(global_st.lookup_array((yyvsp[-2].Token).name, (yyvsp[-2].Token).arr_idx).type != T_INT)
                    yyerror(declared_err);
            }
            //if it is primitive
            else{ 
                if ((yyvsp[-2].Token).token_type != T_INT)
                yyerror(arr_id_err);
            }
            //store in symbol table
            //consider 2 situation 1: it is int-expression 2: it is primitive
            variable v((yyvsp[0].Token).token_type, 0); 
            if((yyvsp[-2].Token).state == S_ID){
                if(!global_st.declared_array((yyvsp[-4].Token).name, v, global_st.lookup_variable((yyvsp[-2].Token).name).data.value))
                    yyerror(declared_err);
            }
            else if((yyvsp[-2].Token).state == S_ARRAY){
                if(!global_st.declared_array((yyvsp[-4].Token).name, v, global_st.lookup_array((yyvsp[-2].Token).name, (yyvsp[-2].Token).arr_idx).data.value))
                    yyerror(declared_err);
            }
            //if it is primitive
            else {
                if(!global_st.declared_array((yyvsp[-4].Token).name, v, (yyvsp[-2].Token).val))
                    yyerror(declared_err);
            }
            
        }
#line 1713 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 243 "yacc.y" /* yacc.c:1661  */
    {
            variable v((yyvsp[0].Token).token_type, 1); 
            if((yyvsp[0].Token).token_type == T_INT)
                v.data.value = (yyvsp[0].Token).val;
            else if((yyvsp[0].Token).token_type == T_BOOL)
                v.data.flag = (yyvsp[0].Token).flag;
            else
                v.data.str = (yyvsp[0].Token).name;
            if(!global_st.declared((yyvsp[-2].Token).name, v))
                yyerror(declared_err);
        }
#line 1729 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 255 "yacc.y" /* yacc.c:1661  */
    { 
            // printf("$1 name = %s  $3 name = %s\n", $1.name, $3.name);
            // printf("$1 state = %d\n", $1.state);
            printf("$1 use look id type = %d, $3 token_type = %d, $3 state = %d\n", global_st.lookup_variable((yyvsp[-2].Token).name).type, (yyvsp[0].Token).token_type, (yyvsp[0].Token).state);
            printf("$1 use look arr type = %d, $3 token_type = %d, $3 state = %d\n", global_st.lookup_array((yyvsp[-2].Token).name, (yyvsp[-2].Token).arr_idx).type, (yyvsp[0].Token).token_type, (yyvsp[0].Token).state);
            // printf("$1 type = %d, $3 in varialbe type = %d\n", global_st.lookup_variable($1.name).type, global_st.lookup_variable($3.name).type);
            // global_st.dump();
            //type check
            if((yyvsp[-2].Token).state == S_ARRAY){
                if(global_st.lookup_array((yyvsp[-2].Token).name, (yyvsp[-2].Token).arr_idx).type != (yyvsp[0].Token).token_type)
                    yyerror(type_match_err);
            }
            else if((yyvsp[-2].Token).state == S_ID){
                if(global_st.lookup_variable((yyvsp[-2].Token).name).type != (yyvsp[0].Token).token_type)
                    yyerror(type_match_err);
            }


            //get value
            variable v((yyvsp[0].Token).token_type);
            // if($3.state == S_ID){
            //     v = global_st.lookup_variable($3.name);
            // }
            // else if($3.state == S_ARRAY){
            //     v = global_st.lookup_array($3.name, $3.arr_idx);
            // }
            // else{
            //     //todo:: it just assign type bcz can not calculate
            //     v.type = $1.token_type;
            // }
            // v.s_type = 0;//set to variable

            
            //assign
            //todo: this just push type bcz it can not calcualate
            if((yyvsp[0].Token).state == S_ARRAY){
                if(!global_st.assign_array_by_id((yyvsp[-2].Token).name, (yyvsp[-2].Token).arr_idx, v))
                    yyerror(type_match_err);
            }
            else if((yyvsp[0].Token).state == S_ID){
                if(!global_st.assign((yyvsp[-2].Token).name, v))
                    yyerror(type_match_err);
            }
            //if it is primitive
            else {
                if(!global_st.assign((yyvsp[-2].Token).name, v))
                    yyerror(type_match_err);
            }
        }
#line 1783 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 311 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1789 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 312 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1795 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 313 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
        }
#line 1805 "y.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 318 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
        }
#line 1815 "y.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 323 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
        }
#line 1825 "y.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 328 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token) = (yyvsp[0].Token);
        }
#line 1833 "y.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 331 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token) = (yyvsp[-1].Token);
        }
#line 1841 "y.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 335 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1847 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 336 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[-1].Token);}
#line 1853 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 337 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL;}
#line 1859 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 338 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 1870 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 344 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 1881 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 350 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 1892 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 356 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 1903 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 363 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1909 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 364 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1915 "y.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 369 "yacc.y" /* yacc.c:1661  */
    { global_st.push_table(); printf("push table\n");}
#line 1921 "y.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 369 "yacc.y" /* yacc.c:1661  */
    { global_st.pop_table(); printf("pop table\n");}
#line 1927 "y.tab.c" /* yacc.c:1661  */
    break;


#line 1931 "y.tab.c" /* yacc.c:1661  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 388 "yacc.y" /* yacc.c:1906  */


int yyerror(char *s)
{
    
    // printf("%d:  %s:  \n", linenum, s);
    printf("compiler error:  %s  \n", s);
    // compier error exit()
    abort();
    return 0;
}

int main(int argc, char const *argv[])
{
    // currentSTE = st.create();
    // yylex(); 
    /* code */
    // show symbol table
    // st.dump(&currentSTE);
    // return 0;
    yyparse();
    global_st.dump();
}
