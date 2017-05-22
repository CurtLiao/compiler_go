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
char args_buffer[256];


#line 87 "y.tab.c" /* yacc.c:339  */

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
#line 23 "yacc.y" /* yacc.c:355  */

    struct
    {
        // this union means value
        union{
            char *name;
            int  val;
            bool flag;
        };
        // for function type concat
        char* concat_name;
        // if it is an array element it should be store the index
        int arr_idx;
        // int => 0 = T_INT bool => 1 = T_BOOL string => 3 = T_STR real => 3 = T_REAL
        int token_type;
        //0 => id || 1 => primitive type for passing data by $$ to recognize
        int state; 
    }Token;

#line 235 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       0,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   117,   143,   149,   151,   152,   152,   152,   153,
     153,   154,   154,   154,   154,   154,   154,   155,   156,   157,
     161,   163,   163,   165,   166,   167,   168,   169,   170,   171,
     176,   176,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   181,   185,   188,   192,   193,   197,   203,   210,   217,
     224,   228,   233,   239,   244,   251,   285,   297,   340,   341,
     342,   343,   344,   347,   348,   349,   350,   355,   360,   365,
     368,   372,   373,   374,   375,   381,   387,   393,   400,   401,
     405,   406,   406,   409,   409,   417,   424,   425,   427,   427,
     428,   428,   429,   429,   430,   430,   431,   431,   432,   432,
     433,   433,   434,   434,   436,   440,   440
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
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "formal_args", "declared",
  "identifier_list", "argument_list", "identifier_declared",
  "simple_statement", "expression", "bool_exp", "mix_exp", "compound",
  "$@7", "func_invoke", "$@8", "condition", "for_loop", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "go", "$@17", YY_NULLPTR
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

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -113

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     112,   -19,   -33,    72,    -7,   -21,   180,   180,   180,   -19,
      -6,   -45,   -25,  -137,   -17,    39,  -137,   112,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,   -15,   -14,   152,
    -137,  -137,  -137,  -137,     4,   -10,    21,     8,   166,  -137,
    -137,  -137,  -137,  -137,   180,   180,  -137,  -137,  -137,   186,
    -137,   186,   186,     6,  -137,   180,    12,  -137,   112,   166,
    -137,  -137,   -19,   109,   166,   166,   -17,    10,   186,   195,
      13,    14,    17,    20,    26,   234,  -137,   269,  -137,  -137,
    -137,  -137,  -137,  -137,   180,   180,   180,     7,    18,    25,
      28,   180,  -137,   275,  -137,   166,    27,   186,   258,  -137,
    -137,  -137,  -137,   269,   244,   166,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,    37,   112,   166,   166,   166,
     166,    42,  -137,    60,    44,  -137,   166,   112,  -137,   186,
     186,   186,     9,    66,    64,    69,   289,  -137,    53,    61,
    -137,  -137,   210,    90,    51,    70,   258,   258,   258,   258,
    -137,    60,    51,    11,    76,  -137,    60,    77,   128,  -137,
    -137,  -137,  -137,    11,  -137,   166,    78,   112,    82,  -137,
    -137,    79,    51,    86,  -137,    87,    51,    51,    89,  -137,
     112,  -137,  -137,    90,    51,    92,    90,    51,  -137,    51,
      60,  -137,  -137,    51,  -137,  -137,  -137,    84,  -137,  -137,
    -137,  -137,  -137,    90,    51,  -137,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,    13,    91,    14,     0,     0,    30,    31,    54,    33,
      55,    34,    35,    36,    37,    38,    39,    57,     0,     0,
       3,     2,     5,     4,     0,     0,     0,     0,     0,    11,
      10,     6,     8,     9,     0,     0,    75,     7,    74,    68,
      73,    69,    71,     0,    70,     0,    93,    90,     0,     0,
       1,    32,     0,     0,     0,     0,    74,     0,    81,     0,
      73,     0,    50,     0,   115,     0,    79,     0,    19,    20,
      16,    17,    18,    15,     0,     0,     0,     3,     2,     5,
       4,     0,    60,     0,    95,     0,     0,    81,    88,    67,
      56,    66,    83,    81,     0,     0,    23,    24,    25,    26,
      21,    22,    27,    28,    29,    98,     0,     0,     0,     0,
       0,    46,    48,     0,    42,   114,     0,     0,    80,    78,
      77,    76,     0,     0,     0,     0,     0,    12,     0,    59,
      92,    82,     0,     0,     0,     0,    87,    86,    85,    84,
      44,     0,     0,     0,     0,    40,     0,     0,    96,    62,
      61,    64,    63,     0,    94,     0,   102,     0,    13,    99,
     101,   106,     0,     0,    49,    52,     0,     0,     0,   116,
       0,    65,    58,     0,     0,     0,     0,     0,    45,     0,
       0,    51,    41,     0,    97,   103,   105,   110,   107,   109,
      47,    53,    43,     0,     0,   111,   113
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,   -48,    93,    23,  -137,     0,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,    -9,   -23,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -136,  -137,     3,  -105,  -137,  -133,    -4,
     -22,    94,  -120,  -137,     1,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    36,    46,    47,    13,    48,    84,    85,    86,   117,
     118,   119,   120,    15,    16,    17,    18,   177,   156,   172,
     151,   152,   123,   154,    19,    28,   138,    20,    21,    68,
      98,   139,    22,    58,    50,    95,    24,    25,   143,   144,
     183,   184,   186,   187,   203,   204,    26,   126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    23,    49,    51,    52,    92,    67,    69,    61,    87,
     169,    55,    53,    56,    30,   173,    75,    14,    23,    39,
     178,   157,    88,    27,   170,    29,    89,    31,    90,    66,
      70,    32,   174,    33,    40,    37,    54,    38,    57,    60,
      76,    77,   102,   104,    59,    62,    71,    63,    72,    96,
     195,    93,   188,   198,   201,    97,   191,   192,    14,    23,
     182,   103,    91,    73,   196,   100,    74,   199,   132,   200,
     205,    94,   121,   202,   105,    30,   122,   -36,   124,   133,
     129,   130,   131,   142,   206,   125,   134,   136,    31,   135,
     140,    97,    32,   145,    33,   146,   147,   148,   149,  -100,
      34,   150,   153,   155,   158,   175,   160,   161,     6,     7,
     162,     8,   164,    12,    35,   181,    14,    23,     1,    39,
      10,   165,    97,     2,     3,     4,     5,    14,    23,   171,
       6,     7,   168,     8,    40,   176,   179,   180,    55,     9,
    -104,  -108,    10,    14,   185,   189,  -112,   190,   193,    41,
      42,   197,    43,    99,    11,   159,   101,   194,     1,     0,
       0,    97,    39,     2,     3,     4,     5,    14,    23,     0,
       6,     7,     0,     8,    12,     0,    39,    40,     0,     9,
      14,    23,    10,    14,     0,     0,    14,     0,     0,     0,
      39,    40,    41,    42,    11,    43,     0,    44,     0,     0,
       0,     0,     0,    14,    64,    40,    41,    42,    11,    43,
      65,    44,     0,     0,    12,     0,     0,     0,    64,     0,
      41,    42,    11,    43,    65,    44,   106,   107,   108,   109,
      78,    79,    80,    81,    82,    83,     0,     0,    45,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,     0,     0,     0,     0,   116,
     110,   111,   112,   113,   114,   106,   107,   108,   109,   166,
       0,     0,     0,     0,   167,   106,   107,   108,   109,     0,
       0,     0,     0,     0,   110,   111,   112,   113,   114,   106,
     107,   108,   109,   127,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   141,     0,     0,     0,     0,   110,   111,
     112,   113,   114,    78,    79,    80,    81,    82,    83,    78,
      79,    80,    81,    82,    83,     0,     0,     0,   128,     0,
       0,     0,   137,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,   163
};

static const yytype_int16 yycheck[] =
{
       0,     0,     6,     7,     8,    53,    29,    29,    17,     3,
     143,    56,     9,    58,     3,   151,    38,    17,    17,    10,
     156,   126,    16,    42,   144,    58,    20,    16,    22,    29,
      29,    20,   152,    22,    25,    42,    42,    58,    63,     0,
      44,    45,    64,    65,    61,    60,    42,    61,    58,    58,
     183,    55,   172,   186,   190,    59,   176,   177,    58,    58,
     165,    65,    56,    42,   184,    62,    58,   187,    61,   189,
     203,    59,    58,   193,    64,     3,    59,    64,    58,    61,
      84,    85,    86,   105,   204,    59,    61,    91,    16,    61,
      63,    95,    20,   116,    22,   117,   118,   119,   120,    62,
      28,    59,    42,    59,   127,   153,    40,    43,    18,    19,
      41,    21,    59,    62,    42,   163,   116,   116,     6,    10,
      30,    60,   126,    11,    12,    13,    14,   127,   127,    59,
      18,    19,    42,    21,    25,    59,    59,     9,    56,    27,
      62,    62,    30,   143,   167,    59,    62,    60,    59,    40,
      41,    59,    43,    59,    42,   132,    63,   180,     6,    -1,
      -1,   165,    10,    11,    12,    13,    14,   167,   167,    -1,
      18,    19,    -1,    21,    62,    -1,    10,    25,    -1,    27,
     180,   180,    30,   183,    -1,    -1,   186,    -1,    -1,    -1,
      10,    25,    40,    41,    42,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,   203,    52,    25,    40,    41,    42,    43,
      58,    45,    -1,    -1,    62,    -1,    -1,    -1,    52,    -1,
      40,    41,    42,    43,    58,    45,    31,    32,    33,    34,
      44,    45,    46,    47,    48,    49,    -1,    -1,    58,    -1,
      -1,    31,    32,    33,    34,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    64,
      50,    51,    52,    53,    54,    31,    32,    33,    34,    59,
      -1,    -1,    -1,    -1,    64,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    31,
      32,    33,    34,    59,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    44,    45,    46,    47,    48,    49,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    57,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    12,    13,    14,    18,    19,    21,    27,
      30,    42,    62,    69,    70,    78,    79,    80,    81,    89,
      92,    93,    97,    99,   101,   102,   111,    42,    90,    58,
       3,    16,    20,    22,    28,    42,    66,    42,    58,    10,
      25,    40,    41,    43,    45,    58,    67,    68,    70,    94,
      99,    94,    94,    90,    42,    56,    58,    63,    98,    61,
       0,    79,    60,    61,    52,    58,    70,    80,    94,    95,
      99,    42,    58,    42,    58,    95,    94,    94,    44,    45,
      46,    47,    48,    49,    71,    72,    73,     3,    16,    20,
      22,    56,    66,    94,    59,   100,    79,    94,    95,    96,
      90,    67,    95,    94,    95,    64,    31,    32,    33,    34,
      50,    51,    52,    53,    54,    59,    64,    74,    75,    76,
      77,    58,    59,    87,    58,    59,   112,    59,    59,    94,
      94,    94,    61,    61,    61,    61,    94,    57,    91,    96,
      63,    59,    95,   103,   104,    80,    95,    95,    95,    95,
      59,    85,    86,    42,    88,    59,    83,    91,    80,    68,
      40,    43,    41,    57,    59,    60,    59,    64,    42,    93,
      97,    59,    84,    88,    97,    66,    59,    82,    88,    59,
       9,    66,    91,   105,   106,    80,   107,   108,    97,    59,
      60,    97,    97,    59,    80,    93,    97,    59,    93,    97,
      97,    88,    97,   109,   110,    93,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      68,    68,    69,    70,    70,    71,    72,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    76,    77,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      82,    81,    83,    81,    84,    81,    85,    81,    86,    81,
      87,    81,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    98,    97,   100,    99,    99,   101,   101,   103,   102,
     104,   102,   105,   102,   106,   102,   107,   102,   108,   102,
     109,   102,   110,   102,   111,   112,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     7,     0,     8,     0,     7,     0,     8,     0,     6,
       0,     7,     2,     4,     1,     1,     3,     1,     3,     1,
       3,     5,     5,     5,     5,     6,     4,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     2,
       3,     1,     3,     2,     3,     3,     3,     3,     1,     1,
       2,     0,     4,     0,     5,     3,     5,     7,     0,     6,
       0,     6,     0,     8,     0,     8,     0,     8,     0,     8,
       0,    10,     0,    10,     4,     0,     6
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
#line 112 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type =  T_INT; }
#line 1511 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 112 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_BOOL;}
#line 1517 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 112 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_STR;}
#line 1523 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 112 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_REAL;}
#line 1529 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 113 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_INT; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).val = (yyvsp[0].Token).val; }
#line 1535 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 113 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = (yyvsp[0].Token).flag; }
#line 1541 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 113 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_STR; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).name = (yyvsp[0].Token).name; }
#line 1547 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 113 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_REAL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).name = (yyvsp[0].Token).name; }
#line 1553 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 114 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = true;}
#line 1559 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 114 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = false;}
#line 1565 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 117 "yacc.y" /* yacc.c:1661  */
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
            //passing to $$ to distinguish which expression be returned;
            (yyval.Token).state = S_ARRAY; 
            //return the type of element
            (yyval.Token).token_type = global_st.lookup_array((yyval.Token).name, (yyval.Token).arr_idx).type;  
        }
#line 1596 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 143 "yacc.y" /* yacc.c:1661  */
    {
                (yyval.Token) = (yyvsp[0].Token);
                (yyval.Token).state = S_ID; 
                //return the type of element
                (yyval.Token).token_type = global_st.lookup_variable((yyvsp[0].Token).name).type; 
            }
#line 1607 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 149 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1613 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 161 "yacc.y" /* yacc.c:1661  */
    {Trace("Reducing to program\n");}
#line 1619 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 165 "yacc.y" /* yacc.c:1661  */
    { Trace("declare id \n");}
#line 1625 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 166 "yacc.y" /* yacc.c:1661  */
    { Trace("simple statement\n");}
#line 1631 "y.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 176 "yacc.y" /* yacc.c:1661  */
    {global_st.function_declared((yyvsp[-3].Token).token_type, (yyvsp[-2].Token).name);}
#line 1637 "y.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 177 "yacc.y" /* yacc.c:1661  */
    { global_st.push_table(); global_st.function_declared((yyvsp[-2].Token).token_type, (yyvsp[-1].Token).name); }
#line 1643 "y.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 177 "yacc.y" /* yacc.c:1661  */
    {global_st.pop_table();}
#line 1649 "y.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 178 "yacc.y" /* yacc.c:1661  */
    {global_st.function_declared(-1, (yyvsp[-2].Token).name);}
#line 1655 "y.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 179 "yacc.y" /* yacc.c:1661  */
    { global_st.push_table(); global_st.function_declared(-1, (yyvsp[-1].Token).name);}
#line 1661 "y.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 179 "yacc.y" /* yacc.c:1661  */
    {global_st.pop_table();}
#line 1667 "y.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 180 "yacc.y" /* yacc.c:1661  */
    {global_st.function_declared(-1, (yyvsp[-2].Token).name);}
#line 1673 "y.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 181 "yacc.y" /* yacc.c:1661  */
    { global_st.push_table(); global_st.function_declared(-1, (yyvsp[-1].Token).name);}
#line 1679 "y.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 181 "yacc.y" /* yacc.c:1661  */
    {global_st.pop_table();}
#line 1685 "y.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 185 "yacc.y" /* yacc.c:1661  */
    {
            global_st.function_concat((yyvsp[0].Token).token_type, (yyvsp[-1].Token).name);
        }
#line 1693 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 188 "yacc.y" /* yacc.c:1661  */
    {
            global_st.function_concat((yyvsp[-2].Token).token_type, (yyvsp[-3].Token).name);
        }
#line 1701 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 197 "yacc.y" /* yacc.c:1661  */
    {  
            // for variable declared like
            printf("\t id , identifier_list || id = %s\n", (yyvsp[-2].Token).name); 
            strcat((yyval.Token).name, " "); 
            strcat((yyval.Token).name, (yyvsp[0].Token).name);
        }
#line 1712 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 203 "yacc.y" /* yacc.c:1661  */
    {
            // printf("\t id in identifier_list || id = %s\n", $1.name); 
            (yyval.Token).name = (yyvsp[0].Token).name; 
        }
#line 1721 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 210 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token).concat_name = (char*)malloc(2*sizeof(char)); 
            sprintf((yyval.Token).concat_name, "%d", (yyvsp[-2].Token).token_type);
            strcat((yyval.Token).concat_name, " ");
            strcat((yyval.Token).concat_name, (yyvsp[0].Token).concat_name);
            printf("\t args in mix_exp, arg_list of argument_list|| id = %s\n", (yyval.Token).concat_name); 
        }
#line 1733 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 217 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token).concat_name = (char*)malloc(2*sizeof(char)); 
            sprintf((yyval.Token).concat_name, "%d", (yyvsp[0].Token).token_type);
            printf("\t args in mix_exp of argument_list|| id = %s\n", (yyval.Token).concat_name); 
        }
#line 1743 "y.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 224 "yacc.y" /* yacc.c:1661  */
    { 
            if(!global_st.declared((yyvsp[-1].Token).name, (yyvsp[0].Token).token_type))
                yyerror(declared_err);
        }
#line 1752 "y.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 228 "yacc.y" /* yacc.c:1661  */
    {
            variable v(T_INT, 0, (yyvsp[0].Token).val); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1762 "y.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 233 "yacc.y" /* yacc.c:1661  */
    {
            printf("T_BOOL = %d\n", T_BOOL);
            variable v(T_BOOL, 0, (yyvsp[0].Token).flag); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1773 "y.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 239 "yacc.y" /* yacc.c:1661  */
    { 
            variable v(T_STR, 0, (yyvsp[0].Token).name); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1783 "y.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 244 "yacc.y" /* yacc.c:1661  */
    {
            variable v(T_REAL, 0, (yyvsp[0].Token).name); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1793 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 251 "yacc.y" /* yacc.c:1661  */
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
#line 1831 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 285 "yacc.y" /* yacc.c:1661  */
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
#line 1847 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 297 "yacc.y" /* yacc.c:1661  */
    { 
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
            if((yyvsp[-2].Token).state == S_ARRAY){
                if(!global_st.assign_array_by_id((yyvsp[-2].Token).name, (yyvsp[-2].Token).arr_idx, v))
                    yyerror(type_match_err);
            }
            else if((yyvsp[-2].Token).state == S_ID){
                if(!global_st.assign((yyvsp[-2].Token).name, v))
                    yyerror(type_match_err);
            }
            //if it is primitive
            else {
                if(!global_st.assign((yyvsp[-2].Token).name, v))
                    yyerror(type_match_err);
            }
        }
#line 1895 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 347 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1901 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 348 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1907 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 349 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1913 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 350 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
        }
#line 1923 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 355 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
        }
#line 1933 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 360 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
        }
#line 1943 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 365 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token) = (yyvsp[0].Token);
        }
#line 1951 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 368 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token) = (yyvsp[-1].Token);
        }
#line 1959 "y.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 372 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1965 "y.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 373 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[-1].Token);}
#line 1971 "y.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 374 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL;}
#line 1977 "y.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 375 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 1988 "y.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 381 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 1999 "y.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 387 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 2010 "y.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 393 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
        }
#line 2021 "y.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 400 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 2027 "y.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 401 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 2033 "y.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 406 "yacc.y" /* yacc.c:1661  */
    { global_st.push_table(); printf("push table\n");}
#line 2039 "y.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 406 "yacc.y" /* yacc.c:1661  */
    { global_st.pop_table(); printf("pop table\n");}
#line 2045 "y.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 409 "yacc.y" /* yacc.c:1661  */
    {args_buffer[0] = '\0';}
#line 2051 "y.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 409 "yacc.y" /* yacc.c:1661  */
    {
            // printf("id name = %s\n", $1.name);
            if(!global_st.function_type_check((yyvsp[-4].Token).name, (yyvsp[-1].Token).concat_name))
                yyerror(type_match_err);

            (yyval.Token).token_type = global_st.lookup_variable((yyvsp[-4].Token).name).type;
            // printf("id type = %d\n", $$.token_type);
        }
#line 2064 "y.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 417 "yacc.y" /* yacc.c:1661  */
    {
            if(!global_st.function_type_check((yyvsp[-2].Token).name, ""))
                yyerror(type_match_err);
            (yyval.Token).token_type = global_st.lookup_variable((yyvsp[-2].Token).name).type;
            // printf("id type = %d\n", $$.token_type);
        }
#line 2075 "y.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 427 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-1].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2081 "y.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 428 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-1].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2087 "y.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 429 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-1].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2093 "y.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 430 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-1].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2099 "y.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 431 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-3].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2105 "y.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 432 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-3].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2111 "y.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 433 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-3].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2117 "y.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 434 "yacc.y" /* yacc.c:1661  */
    {if((yyvsp[-3].Token).token_type != T_BOOL){yyerror(type_match_err);}}
#line 2123 "y.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 436 "yacc.y" /* yacc.c:1661  */
    {
            if(!global_st.function_type_check((yyvsp[-2].Token).name, ""))
                yyerror(type_match_err);
        }
#line 2132 "y.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 440 "yacc.y" /* yacc.c:1661  */
    {args_buffer[0] = '\0';}
#line 2138 "y.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 440 "yacc.y" /* yacc.c:1661  */
    {
            if(!global_st.function_type_check((yyvsp[-4].Token).name, (yyvsp[-1].Token).concat_name))
                yyerror(type_match_err);
        }
#line 2147 "y.tab.c" /* yacc.c:1661  */
    break;


#line 2151 "y.tab.c" /* yacc.c:1661  */
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
#line 446 "yacc.y" /* yacc.c:1906  */


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
    // yylex(); 
    /* code */

    yyparse();
    // global_st.dump();
    // return 0;
}
