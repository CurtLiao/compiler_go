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
FILE *java_code;

symbol_table global_st;
int variable_type; // 0=> int 1=> bool 2=> string 3=>real
int label_index = 0; // for goto label
int label_stack[10];
int label_stack_top = 0;
bool const_flag = false;
enum Type_enum{T_INT = 0, T_BOOL = 1, T_STR, T_REAL};
enum State_enum{S_PRIMITIVE = 0, S_ID = 1, S_ARRAY = 2};

int yylex();
int yyerror(char *s);
char* declared_err = "declared error";
char* type_match_err= "type match error";
char* arr_id_err= "array index should be integer";
char args_buffer[256];


#line 92 "y.tab.c" /* yacc.c:339  */

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
#line 28 "yacc.y" /* yacc.c:355  */

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

#line 240 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

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
       2,     2,     2,    46,     2,     2,     2,    51,    45,     2,
      56,    57,    49,    47,    58,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
      60,    59,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,    44,    63,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   122,   122,   122,   123,   129,   139,   148,
     149,   149,   152,   178,   189,   191,   201,   203,   203,   205,
     206,   207,   208,   209,   210,   211,   212,   217,   217,   239,
     249,   239,   267,   267,   277,   282,   277,   298,   298,   306,
     311,   306,   331,   334,   338,   339,   343,   349,   356,   363,
     370,   386,   394,   408,   416,   423,   457,   457,   487,   536,
     536,   544,   544,   552,   553,   554,   557,   558,   559,   565,
     571,   577,   583,   589,   601,   606,   611,   615,   616,   617,
     625,   633,   640,   653,   666,   679,   692,   705,   718,   725,
     726,   726,   729,   729,   740,   750,   756,   750,   778,   778,
     803,   823,   829,   847,   829,   863,   875,   887,   863,   905,
     905,   916,   920,   920
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
  "NUMBER", "STR", "ID", "REAL_NUMBER", "'|'", "'&'", "'!'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'", "','",
  "'='", "'<'", "'>'", "'{'", "'}'", "';'", "$accept", "primitive_type",
  "primitive", "bool_type", "array_element", "object", "op_order2",
  "program", "statements", "statement", "func_declared", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "formal_args",
  "declared", "identifier_list", "argument_list", "identifier_declared",
  "$@10", "simple_statement", "$@11", "$@12", "expression", "bool_exp",
  "compound", "$@13", "func_invoke", "$@14", "condition", "$@15", "$@16",
  "prefix_for_statement", "$@17", "postfix_for_statement", "forloop_args",
  "$@18", "$@19", "$@20", "$@21", "$@22", "for_loop", "$@23", "go", "$@24", YY_NULLPTR
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
     295,   296,   297,   298,   124,    38,    33,    43,    45,    42,
      47,    37,    94,   299,    91,    93,    40,    41,    44,    61,
      60,    62,   123,   125,    59
};
# endif

#define YYPACT_NINF -155

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-155)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      77,  -155,  -155,   -48,     6,   -23,   -32,  -155,  -155,   152,
    -155,   -22,   -11,  -155,  -155,    -2,  -155,   124,   152,   124,
     -38,  -155,  -155,  -155,  -155,    32,  -155,    77,  -155,  -155,
    -155,  -155,   155,   227,  -155,   165,  -155,  -155,  -155,   -22,
    -155,  -155,  -155,  -155,  -155,    -6,   -16,    -1,    -3,   124,
     152,   152,   -17,   152,   155,  -155,     3,     1,  -155,   152,
      -7,   124,    81,  -155,   228,   187,  -155,    77,  -155,  -155,
     152,   152,   152,   152,   152,  -155,   152,   124,   124,   124,
     124,   124,   124,   124,   124,   124,    10,   133,     2,    14,
      25,    27,   196,   155,   155,   228,   -22,    11,    26,    42,
      44,   152,  -155,   243,  -155,   124,   227,  -155,  -155,    -4,
     259,   259,    34,    34,    34,   155,   227,   227,   227,   227,
     227,   236,    81,   227,   227,   128,    38,   227,  -155,  -155,
      48,  -155,    64,    53,  -155,   124,  -155,  -155,     5,    71,
      73,    80,   252,  -155,    65,   205,  -155,  -155,   152,    60,
     124,  -155,    64,    66,    13,    72,  -155,    64,    75,    77,
    -155,  -155,  -155,  -155,    13,  -155,   124,   155,    93,  -155,
     227,    66,    79,  -155,    88,  -155,    66,    90,  -155,   139,
    -155,  -155,    87,    78,    97,    60,  -155,  -155,    64,    66,
    -155,  -155,  -155,  -155,   152,    66,  -155,    66,  -155,  -155,
      66,    77,   155,  -155,    99,  -155,  -155,  -155,    66,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    56,    11,     0,     0,     0,     0,    59,    61,    65,
      10,     0,     0,     6,     8,    13,     9,     0,     0,     0,
      90,    68,     7,    14,    67,     0,    16,    17,    44,    19,
      45,    20,    88,    26,    21,    22,    23,    24,    25,     0,
     109,     3,     2,     5,     4,     0,     0,     0,     0,     0,
       0,     0,    13,     0,    64,    66,    47,     0,    63,     0,
      92,     0,    78,    75,    88,     0,    89,     0,     1,    18,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,   112,     0,    60,    62,     0,     0,     3,     2,     5,
       4,     0,    50,     0,    94,     0,    58,    76,    77,     0,
      69,    70,    71,    72,    73,    74,    85,    86,    84,    87,
      79,    80,    81,    82,    83,     0,    13,   102,   105,   110,
      34,    37,     0,    29,   111,     0,    95,    46,     0,     0,
       0,     0,     0,    12,     0,    49,    91,    57,     0,   101,
       0,    32,     0,     0,     0,     0,    27,     0,     0,     0,
      52,    51,    54,    53,     0,    93,     0,    98,     0,   103,
     106,     0,     0,    38,    42,    40,     0,     0,   113,     0,
      55,    48,     0,     0,     0,   101,    33,    35,     0,     0,
      28,    30,    96,    99,     0,     0,   107,     0,    43,    41,
       0,     0,   100,   104,     0,    36,    31,    97,     0,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,   -55,    35,    19,  -155,  -155,  -155,  -155,   -21,  -154,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -139,  -155,   -36,  -128,  -155,  -155,  -155,  -155,  -155,    -8,
      -5,   -45,  -155,     0,  -155,  -155,  -155,  -155,  -155,  -155,
      28,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    47,    21,    22,    23,    24,    76,    25,    26,    27,
      28,   176,   157,   200,   171,   152,   197,   153,   132,   189,
     155,    29,    57,   144,    30,    39,    31,    50,    51,    32,
      33,    34,    67,    55,   105,    36,   159,   201,   128,   182,
     169,   129,   149,   184,   150,   185,   204,    37,    87,    38,
     135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    54,   102,    86,    97,   179,    69,   158,    40,    41,
      63,    64,    62,   172,    65,     2,    41,    98,   177,    48,
      56,    99,    42,   100,    49,    66,    43,    35,    44,    42,
      10,    58,    68,    43,    45,    44,    88,    59,   181,    60,
      89,    90,    93,    94,    92,    95,   109,   207,    46,   198,
     104,   103,    59,    91,    60,   101,   106,    61,   130,   146,
     137,    96,   110,   111,   112,   113,   114,    35,   115,   125,
     138,   131,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   133,   127,     1,   134,   139,    75,     2,     3,     4,
       5,     6,    59,   142,    60,     7,     8,   148,     9,   174,
     145,   140,    10,   141,    11,   151,   154,    12,   173,   180,
     156,   161,    77,    78,    79,    80,   162,    13,    14,    15,
      16,   163,   165,    17,   168,    18,   186,    83,    20,   175,
     145,   190,   178,    19,     2,   183,   187,   194,     2,    20,
     167,    84,    85,     2,   199,   170,   188,   191,   192,    10,
     203,   193,   205,    10,   195,   206,   208,   160,    10,    35,
     147,   145,     2,   209,    13,    14,    52,    16,    13,    14,
      17,    16,    18,    13,    14,   126,    16,    10,     0,    17,
      19,    18,     0,     0,     0,     0,   202,     0,     0,    19,
       0,     0,    13,    14,    52,    16,   -66,   -66,   -66,   -66,
      18,    35,    70,    71,    72,    73,    74,    75,    53,   -66,
     -66,     0,   -66,   196,   -66,   -66,   -66,   -66,    77,    78,
      79,    80,     0,     0,     0,   -66,   -66,    77,    78,    79,
      80,    81,    82,    83,     0,     0,    77,    78,    79,    80,
      81,    82,    83,     0,   108,     0,     0,    84,    85,    81,
      82,    83,     0,   136,     0,     0,    84,    85,    77,    78,
      79,    80,     0,   166,     0,    84,    85,    77,    78,    79,
      80,    81,    82,    83,     0,    70,    71,    72,    73,    74,
      75,    82,    83,     0,     0,   107,     0,    84,    85,     0,
      70,    71,    72,    73,    74,    75,    84,    85,   143,    70,
      71,    72,    73,    74,    75,     0,     0,   164,    72,    73,
      74,    75
};

static const yytype_int16 yycheck[] =
{
       0,     9,    57,    39,     3,   159,    27,   135,    56,     3,
      18,    19,    17,   152,    19,    10,     3,    16,   157,    42,
      42,    20,    16,    22,    56,    63,    20,    27,    22,    16,
      25,    42,     0,    20,    28,    22,    42,    54,   166,    56,
      56,    42,    50,    51,    49,    53,    67,   201,    42,   188,
      57,    59,    54,    56,    56,    54,    61,    59,    56,    63,
      96,    58,    70,    71,    72,    73,    74,    67,    76,    59,
      59,    57,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    56,    87,     6,    57,    59,    52,    10,    11,    12,
      13,    14,    54,   101,    56,    18,    19,    59,    21,   154,
     105,    59,    25,    59,    27,    57,    42,    30,   153,   164,
      57,    40,    31,    32,    33,    34,    43,    40,    41,    42,
      43,    41,    57,    46,    64,    48,   171,    46,    62,    57,
     135,   176,    57,    56,    10,    42,    57,    59,    10,    62,
     148,    60,    61,    10,   189,   150,    58,    57,     9,    25,
     195,    64,   197,    25,    57,   200,    57,   138,    25,   159,
     125,   166,    10,   208,    40,    41,    42,    43,    40,    41,
      46,    43,    48,    40,    41,    42,    43,    25,    -1,    46,
      56,    48,    -1,    -1,    -1,    -1,   194,    -1,    -1,    56,
      -1,    -1,    40,    41,    42,    43,    31,    32,    33,    34,
      48,   201,    47,    48,    49,    50,    51,    52,    56,    44,
      45,    -1,    47,   185,    49,    50,    51,    52,    31,    32,
      33,    34,    -1,    -1,    -1,    60,    61,    31,    32,    33,
      34,    44,    45,    46,    -1,    -1,    31,    32,    33,    34,
      44,    45,    46,    -1,    57,    -1,    -1,    60,    61,    44,
      45,    46,    -1,    57,    -1,    -1,    60,    61,    31,    32,
      33,    34,    -1,    58,    -1,    60,    61,    31,    32,    33,
      34,    44,    45,    46,    -1,    47,    48,    49,    50,    51,
      52,    45,    46,    -1,    -1,    57,    -1,    60,    61,    -1,
      47,    48,    49,    50,    51,    52,    60,    61,    55,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    49,    50,
      51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    10,    11,    12,    13,    14,    18,    19,    21,
      25,    27,    30,    40,    41,    42,    43,    46,    48,    56,
      62,    67,    68,    69,    70,    72,    73,    74,    75,    86,
      89,    91,    94,    95,    96,    98,   100,   112,   114,    90,
      56,     3,    16,    20,    22,    28,    42,    66,    42,    56,
      92,    93,    42,    56,    94,    98,    42,    87,    42,    54,
      56,    59,    95,    94,    94,    95,    63,    97,     0,    73,
      47,    48,    49,    50,    51,    52,    71,    31,    32,    33,
      34,    44,    45,    46,    60,    61,    87,   113,    42,    56,
      42,    56,    95,    94,    94,    94,    58,     3,    16,    20,
      22,    54,    66,    94,    57,    99,    95,    57,    57,    73,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    59,    42,    95,   103,   106,
      56,    57,    83,    56,    57,   115,    57,    87,    59,    59,
      59,    59,    94,    55,    88,    95,    63,    67,    59,   107,
     109,    57,    80,    82,    42,    85,    57,    77,    88,   101,
      68,    40,    43,    41,    55,    57,    58,    94,    64,   105,
      95,    79,    85,    96,    66,    57,    76,    85,    57,    74,
      66,    88,   104,    42,   108,   110,    96,    57,    58,    84,
      96,    57,     9,    64,    59,    57,   105,    81,    85,    96,
      78,   102,    94,    96,   111,    96,    96,    74,    57,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      68,    68,    69,    70,    70,    71,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    76,    75,    77,
      78,    75,    79,    75,    80,    81,    75,    82,    75,    83,
      84,    75,    85,    85,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    90,    89,    91,    92,
      91,    93,    91,    91,    91,    91,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      97,    96,    99,    98,    98,   101,   102,   100,   104,   103,
     105,   105,   107,   108,   106,   109,   110,   111,   106,   113,
     112,   114,   115,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     7,     0,
       0,     9,     0,     7,     0,     0,     9,     0,     6,     0,
       0,     8,     2,     4,     1,     1,     3,     1,     3,     1,
       3,     5,     5,     5,     5,     6,     0,     5,     3,     0,
       3,     0,     3,     2,     2,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       0,     4,     0,     5,     3,     0,     0,     9,     0,     5,
       4,     0,     0,     0,     6,     0,     0,     0,     8,     0,
       4,     4,     0,     6
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
#line 122 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type =  T_INT; }
#line 1512 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 122 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_BOOL;}
#line 1518 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 122 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_STR;}
#line 1524 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 122 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type =  T_REAL;}
#line 1530 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 123 "yacc.y" /* yacc.c:1661  */
    { 
        (yyval.Token).token_type = T_INT; 
        (yyval.Token).state = S_PRIMITIVE; 
        (yyval.Token).val = (yyvsp[0].Token).val;  
        if(const_flag != true)
            fprintf(java_code, "\t\tsipush %d\n", (yyvsp[0].Token).val);
    }
#line 1542 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 129 "yacc.y" /* yacc.c:1661  */
    { 
        (yyval.Token).token_type = T_BOOL; 
        (yyval.Token).state = S_PRIMITIVE; 
        (yyval.Token).flag = (yyvsp[0].Token).flag; 
        if(const_flag != true){
            if((yyval.Token).flag)    
                fprintf(java_code, "\t\tsipush %d\n", 1);
            else        
                fprintf(java_code, "\t\tsipush %d\n", 0);
        }
    }
#line 1558 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 139 "yacc.y" /* yacc.c:1661  */
    { 
        (yyval.Token).token_type = T_STR; 
        (yyval.Token).state = S_PRIMITIVE; 
        (yyval.Token).name = (yyvsp[0].Token).name; 
        if(const_flag != true)
            fprintf(java_code, "\t\tldc \"%s\" \n", (yyvsp[0].Token).name);

            

    }
#line 1573 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 148 "yacc.y" /* yacc.c:1661  */
    { (yyval.Token).token_type = T_REAL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).name = (yyvsp[0].Token).name; }
#line 1579 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 149 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = true; }
#line 1585 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 149 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL; (yyval.Token).state = S_PRIMITIVE; (yyval.Token).flag = false;}
#line 1591 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 152 "yacc.y" /* yacc.c:1661  */
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
#line 1622 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 178 "yacc.y" /* yacc.c:1661  */
    {
                (yyval.Token) = (yyvsp[0].Token);
                (yyval.Token).state = S_ID; 
                //return the type of element
                variable left_v = global_st.lookup_variable((yyvsp[0].Token).name);
                (yyval.Token).token_type = left_v.type; 
                if(left_v.is_global)
                    fprintf(java_code, "\t\tgetstatic int proj3.%s\n", (yyvsp[0].Token).name);
                else                    
                    fprintf(java_code, "\t\tiload %d\n", left_v.virtual_index);
            }
#line 1638 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 189 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 1644 "y.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 201 "yacc.y" /* yacc.c:1661  */
    { Trace("Reducing to program\n");}
#line 1650 "y.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 205 "yacc.y" /* yacc.c:1661  */
    { Trace("declare id \n");}
#line 1656 "y.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 206 "yacc.y" /* yacc.c:1661  */
    { Trace("simple statement\n");}
#line 1662 "y.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 217 "yacc.y" /* yacc.c:1661  */
    {
            global_st.function_declared((yyvsp[-3].Token).token_type, (yyvsp[-2].Token).name);
            if (strcmp((yyvsp[-2].Token).name, "main") == 0){
                if((yyvsp[-3].Token).token_type == T_INT)
                    fprintf(java_code,"\tmethod public static int main(java.lang.String[])\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
                else if((yyvsp[-3].Token).token_type == T_BOOL)
                    fprintf(java_code,"\tmethod public static boolean main(java.lang.String[])\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
                else if((yyvsp[-3].Token).token_type == T_STR)
                    fprintf(java_code,"\tmethod public static string main(java.lang.String[])\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
            }
            else{
                if((yyvsp[-3].Token).token_type == T_INT)
                    fprintf(java_code,"\tmethod public static int %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-2].Token).name);
                else if((yyvsp[-3].Token).token_type == T_BOOL)
                    fprintf(java_code,"\tmethod public static boolean %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-2].Token).name);
                else if((yyvsp[-3].Token).token_type == T_STR)
                    fprintf(java_code,"\tmethod public static string %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-2].Token).name);
            }
            // fprintf(java_code,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
            
            
        }
#line 1689 "y.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 238 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t}\n");}
#line 1695 "y.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 239 "yacc.y" /* yacc.c:1661  */
    { 
            global_st.push_table(); 
            global_st.function_declared((yyvsp[-2].Token).token_type, (yyvsp[-1].Token).name); 
            if((yyvsp[-2].Token).token_type == T_INT)
                fprintf(java_code,"\tmethod public static int %s", (yyvsp[-1].Token).name);
            else if((yyvsp[-2].Token).token_type == T_BOOL)
                fprintf(java_code,"\tmethod public static boolean %s", (yyvsp[-1].Token).name);
            else if((yyvsp[-2].Token).token_type == T_STR)
                fprintf(java_code,"\tmethod public static string %s", (yyvsp[-1].Token).name);

        }
#line 1711 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 249 "yacc.y" /* yacc.c:1661  */
    {
            global_st.args_encode_index();
            variable v = global_st.lookup_variable((yyvsp[-4].Token).name);
            fprintf(java_code,"(");
            for(int i = v.func_size - 1; i >= 0 ; --i){
                printf("position = %d  type = %d\n", i , v.func_type[i]);
                if(v.func_type[i] == T_INT)
                    fprintf(java_code, "int");
                else if(v.func_type[i] == T_BOOL)
                    fprintf(java_code, "boolean");
                else if(v.func_type[i] == T_STR)
                    fprintf(java_code, "string");   
                if(i != 0)
                     fprintf(java_code, ", ");   
            }
            fprintf(java_code,")\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
            
        }
#line 1734 "y.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 266 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t}\n");global_st.pop_table();}
#line 1740 "y.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 267 "yacc.y" /* yacc.c:1661  */
    {
            global_st.function_declared(-1, (yyvsp[-2].Token).name);
            if (strcmp((yyvsp[-2].Token).name, "main") == 0){
                fprintf(java_code,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
            }
            else{
                fprintf(java_code,"\tmethod public static void %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-2].Token).name);
            }

        }
#line 1755 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 276 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t\treturn\n\t}\n");}
#line 1761 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 277 "yacc.y" /* yacc.c:1661  */
    { 
            global_st.push_table(); 
            global_st.function_declared(-1, (yyvsp[-1].Token).name);
            fprintf(java_code,"\tmethod public static void %s", (yyvsp[-1].Token).name);

        }
#line 1772 "y.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 282 "yacc.y" /* yacc.c:1661  */
    {
            global_st.args_encode_index();
            variable v = global_st.lookup_variable((yyvsp[-4].Token).name);
            fprintf(java_code,"(");
            for(int i = v.func_size - 1; i >= 0 ; --i){
                if(v.func_type[i] == T_INT)
                    fprintf(java_code, "int");
                else if(v.func_type[i] == T_BOOL)
                    fprintf(java_code, "boolean");
                else if(v.func_type[i] == T_STR)
                    fprintf(java_code, "string");   
                if(i != 0)
                     fprintf(java_code, ", ");   
            }
            fprintf(java_code,")\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
        }
#line 1793 "y.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 297 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t\treturn\n\t}\n");global_st.pop_table();}
#line 1799 "y.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 298 "yacc.y" /* yacc.c:1661  */
    {
            global_st.function_declared(-1, (yyvsp[-2].Token).name);
            if (strcmp((yyvsp[-2].Token).name, "main") == 0){
                fprintf(java_code,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
            }
            else{
                fprintf(java_code,"\tmethod public static void %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-2].Token).name);
            }        }
#line 1812 "y.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 305 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t\treturn\n\t}\n");}
#line 1818 "y.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 306 "yacc.y" /* yacc.c:1661  */
    { 
            global_st.push_table(); 
            global_st.function_declared(-1, (yyvsp[-1].Token).name);
            fprintf(java_code,"\tmethod public static void %s(", (yyvsp[-1].Token).name);

        }
#line 1829 "y.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 311 "yacc.y" /* yacc.c:1661  */
    {
            global_st.args_encode_index();
            variable v = global_st.lookup_variable((yyvsp[-4].Token).name);
            fprintf(java_code,"(");
            for(int i = v.func_size - 1; i >= 0 ; --i){
                printf("position = %d  type = %d\n", i , v.func_type[i]);
                if(v.func_type[i] == T_INT)
                    fprintf(java_code, "int");
                else if(v.func_type[i] == T_BOOL)
                    fprintf(java_code, "boolean");
                else if(v.func_type[i] == T_STR)
                    fprintf(java_code, "string");   
                if(i != 0)
                     fprintf(java_code, ", ");   
            }
            fprintf(java_code,")\n\tmax_stack 30\n\tmax_locals 30\n\t{\n");
        }
#line 1851 "y.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 327 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t\treturn\n\t}\n");global_st.pop_table();}
#line 1857 "y.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 331 "yacc.y" /* yacc.c:1661  */
    {
            global_st.function_concat((yyvsp[0].Token).token_type, (yyvsp[-1].Token).name);
        }
#line 1865 "y.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 334 "yacc.y" /* yacc.c:1661  */
    {
            global_st.function_concat((yyvsp[-2].Token).token_type, (yyvsp[-3].Token).name);
        }
#line 1873 "y.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 343 "yacc.y" /* yacc.c:1661  */
    {  
            // for variable declared like
            printf("\t id , identifier_list || id = %s\n", (yyvsp[-2].Token).name); 
            strcat((yyval.Token).name, " "); 
            strcat((yyval.Token).name, (yyvsp[0].Token).name);
        }
#line 1884 "y.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 349 "yacc.y" /* yacc.c:1661  */
    {
            // printf("\t id in identifier_list || id = %s\n", $1.name); 
            (yyval.Token).name = (yyvsp[0].Token).name; 
        }
#line 1893 "y.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 356 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token).concat_name = (char*)malloc(2*sizeof(char)); 
            sprintf((yyval.Token).concat_name, "%d", (yyvsp[-2].Token).token_type);
            strcat((yyval.Token).concat_name, " ");
            strcat((yyval.Token).concat_name, (yyvsp[0].Token).concat_name);
            printf("\t args in mix_exp, arg_list of argument_list|| id = %s\n", (yyval.Token).concat_name); 
        }
#line 1905 "y.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 363 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token).concat_name = (char*)malloc(2*sizeof(char)); 
            sprintf((yyval.Token).concat_name, "%d", (yyvsp[0].Token).token_type);
            printf("\t args in mix_exp of argument_list|| id = %s\n", (yyval.Token).concat_name); 
        }
#line 1915 "y.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 370 "yacc.y" /* yacc.c:1661  */
    { 
            if(!global_st.declared((yyvsp[-1].Token).name, (yyvsp[0].Token).token_type))
                yyerror(declared_err);
            // global variable
            if(global_st.check_global()){
                fprintf(java_code, "\tfield static ");
                if((yyvsp[0].Token).token_type == T_INT)
                    fprintf(java_code, "int");
                else if((yyvsp[0].Token).token_type == T_BOOL)
                    fprintf(java_code, "boolean");
                else if((yyvsp[0].Token).token_type == T_STR)
                    fprintf(java_code, "string");   
                fprintf(java_code, " %s\n", (yyvsp[-1].Token).name);
            }

        }
#line 1936 "y.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 386 "yacc.y" /* yacc.c:1661  */
    {
            variable v(T_INT, 0, (yyvsp[0].Token).val); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
            // global variable
            if(global_st.check_global())
                fprintf(java_code, "\tfield static int %s = %d\n", (yyvsp[-3].Token).name, (yyvsp[0].Token).val);
        }
#line 1949 "y.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 394 "yacc.y" /* yacc.c:1661  */
    {
            printf("T_BOOL = %d\n", T_BOOL);
            variable v(T_BOOL, 0, (yyvsp[0].Token).flag); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
            // global variable
            if(global_st.check_global()){
                if((yyvsp[0].Token).flag == false)
                    fprintf(java_code, "\tfield static int %s = %d\n", (yyvsp[-3].Token).name, 0);
                else
                    fprintf(java_code, "\tfield static int %s = %d\n", (yyvsp[-3].Token).name, 1);
            }

        }
#line 1968 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 408 "yacc.y" /* yacc.c:1661  */
    { 
            variable v(T_STR, 0, (yyvsp[0].Token).name); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
            if(global_st.check_global())
                fprintf(java_code, "\tfield static string %s = %s\n", (yyvsp[-3].Token).name, (yyvsp[0].Token).name);
            
        }
#line 1981 "y.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 416 "yacc.y" /* yacc.c:1661  */
    {
            variable v(T_REAL, 0, (yyvsp[0].Token).name); 
            if(!global_st.declared((yyvsp[-3].Token).name, v))
                yyerror(declared_err);
        }
#line 1991 "y.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 423 "yacc.y" /* yacc.c:1661  */
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
#line 2029 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 457 "yacc.y" /* yacc.c:1661  */
    {
            const_flag = true;
        }
#line 2037 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 459 "yacc.y" /* yacc.c:1661  */
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
            
            if(global_st.check_global()){
                if((yyvsp[0].Token).token_type == T_INT)
                    fprintf(java_code, "\tfield static int %s = %d\n", (yyvsp[-2].Token).name, (yyvsp[0].Token).val);
                else if((yyvsp[0].Token).token_type == T_BOOL)
                    fprintf(java_code, "\tfield static string %s = %s\n", (yyvsp[-2].Token).name, (yyvsp[0].Token).name);
                else{
                    if((yyvsp[0].Token).flag == false)
                        fprintf(java_code, "\tfield static int %s = %d\n", (yyvsp[-2].Token).name, 0);
                    else
                        fprintf(java_code, "\tfield static int %s = %d\n", (yyvsp[-2].Token).name, 1);    
                }
                
            }
            const_flag = false;

        }
#line 2069 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 487 "yacc.y" /* yacc.c:1661  */
    { 
            //type check
            // if($1.state == S_ARRAY){
            //     if(global_st.lookup_array($1.name, $1.arr_idx).type != $3.token_type)
            //         yyerror(type_match_err);
            // }
            // else if($1.state == S_ID){
                variable left_v = global_st.lookup_variable((yyvsp[-2].Token).name);
                if(left_v.type != (yyvsp[0].Token).token_type)
                    yyerror(type_match_err);
                //check global or local and assign
                if(left_v.is_global)
                    fprintf(java_code, "\t\tputstatic int proj3.%s\n", (yyvsp[-2].Token).name);
                else                    
                    fprintf(java_code, "\t\tistore %d\n", left_v.virtual_index);
            // }


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
            // if($1.state == S_ARRAY){
            //     if(!global_st.assign_array_by_id($1.name, $1.arr_idx, v))
            //         yyerror(type_match_err);
            // }
            // else if($1.state == S_ID){
            if(!global_st.assign((yyvsp[-2].Token).name, v))
                yyerror(type_match_err);
            // }
            //if it is primitive
            else {
                if(!global_st.assign((yyvsp[-2].Token).name, v))
                    yyerror(type_match_err);
            }
        }
#line 2123 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 536 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");}
#line 2129 "y.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 537 "yacc.y" /* yacc.c:1661  */
    {
            printf("test type %d\n", (yyvsp[0].Token).token_type);
            if((yyvsp[0].Token).token_type == T_STR)
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
            else
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n"); 
        }
#line 2141 "y.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 544 "yacc.y" /* yacc.c:1661  */
    {fprintf(java_code,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");}
#line 2147 "y.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 545 "yacc.y" /* yacc.c:1661  */
    {
            printf("test type %d\n", (yyvsp[0].Token).token_type);
            if((yyvsp[0].Token).token_type == T_STR)
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
            else
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n"); 
        }
#line 2159 "y.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 553 "yacc.y" /* yacc.c:1661  */
    {    fprintf(java_code,"\t\tireturn\n");}
#line 2165 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 554 "yacc.y" /* yacc.c:1661  */
    {    fprintf(java_code,"\t\tireturn\n");}
#line 2171 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 557 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 2177 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 558 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 2183 "y.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 559 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 2189 "y.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 565 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            fprintf(java_code, "\t\tiadd\n");
        }
#line 2200 "y.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 571 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            fprintf(java_code, "\t\tisub\n");
        }
#line 2211 "y.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 577 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            fprintf(java_code, "\t\timul\n");
        }
#line 2222 "y.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 583 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            fprintf(java_code, "\t\tidiv\n");
        }
#line 2233 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 589 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            fprintf(java_code, "\t\tirem\n");
        }
#line 2244 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 601 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
        }
#line 2254 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 606 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token) = (yyvsp[0].Token);
            fprintf(java_code, "\t\tineg\n");

        }
#line 2264 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 611 "yacc.y" /* yacc.c:1661  */
    {
            (yyval.Token) = (yyvsp[-1].Token);
        }
#line 2272 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 615 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[-1].Token);}
#line 2278 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 616 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token).token_type = T_BOOL;}
#line 2284 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 617 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tior\n");

        }
#line 2297 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 625 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tiand\n");

        }
#line 2310 "y.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 633 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tixor\n");
        }
#line 2322 "y.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 640 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tiflt L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }
#line 2340 "y.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 653 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifgt L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }
#line 2358 "y.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 666 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifeq L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }
#line 2376 "y.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 679 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifle L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }
#line 2394 "y.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 692 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifge L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }
#line 2412 "y.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 705 "yacc.y" /* yacc.c:1661  */
    {
            if((yyvsp[-2].Token).token_type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            (yyval.Token) = (yyvsp[-2].Token);
            (yyval.Token).token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifne L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }
#line 2430 "y.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 718 "yacc.y" /* yacc.c:1661  */
    {(yyval.Token) = (yyvsp[0].Token);}
#line 2436 "y.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 726 "yacc.y" /* yacc.c:1661  */
    { global_st.push_table();}
#line 2442 "y.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 726 "yacc.y" /* yacc.c:1661  */
    { global_st.pop_table(); }
#line 2448 "y.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 729 "yacc.y" /* yacc.c:1661  */
    {args_buffer[0] = '\0';}
#line 2454 "y.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 729 "yacc.y" /* yacc.c:1661  */
    {
            // printf("id name = %s\n", $1.name);
            if(!global_st.function_type_check((yyvsp[-4].Token).name, (yyvsp[-1].Token).concat_name))
                yyerror(type_match_err);
            variable v = global_st.lookup_variable((yyvsp[-4].Token).name);
            (yyval.Token).token_type = v.type;
            // printf("id type = %d\n", $$.token_type);
            fprintf(java_code,"\t\tinvokestatic %s proj3.%s(%s)\n", global_st.variable_type_str((yyvsp[-4].Token).name).c_str(), (yyvsp[-4].Token).name, global_st.function_args_type((yyvsp[-4].Token).name).c_str());
            

        }
#line 2470 "y.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 740 "yacc.y" /* yacc.c:1661  */
    {
            if(!global_st.function_type_check((yyvsp[-2].Token).name, ""))
                yyerror(type_match_err);
            variable v = global_st.lookup_variable((yyvsp[-2].Token).name);
            (yyval.Token).token_type = v.type;
            // printf("id type = %d\n", $$.token_type);
            fprintf(java_code,"\t\tinvokestatic %s proj3.%s()\n", global_st.variable_type_str((yyvsp[-2].Token).name).c_str(), (yyvsp[-2].Token).name);

        }
#line 2484 "y.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 750 "yacc.y" /* yacc.c:1661  */
    {
            //save index for else
            label_stack[label_stack_top++] = label_index;
            // fprintf(java_code,"\t\ticonst_0\n");
            fprintf(java_code,"\t\tifeq L%d\n", label_index);
            label_index += 2;
        }
#line 2496 "y.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 756 "yacc.y" /* yacc.c:1661  */
    {
            //go exit
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 1);
            //else lable
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1]);
        }
#line 2507 "y.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 761 "yacc.y" /* yacc.c:1661  */
    {
            fprintf(java_code,"\tL%d:\n", label_stack[--label_stack_top] + 1);
        }
#line 2515 "y.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 778 "yacc.y" /* yacc.c:1661  */
    { 
            //type check
           
            variable left_v = global_st.lookup_variable((yyvsp[-2].Token).name);
            if(left_v.type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            //check global or local and assign
            if(left_v.is_global)
                fprintf(java_code, "\t\tputstatic int proj3.%s\n", (yyvsp[-2].Token).name);
            else                    
                fprintf(java_code, "\t\tistore %d\n", left_v.virtual_index);
            //get value
            variable v((yyvsp[0].Token).token_type);
            if(!global_st.assign((yyvsp[-2].Token).name, v))
                yyerror(type_match_err);
            //if it is primitive
            else {
                if(!global_st.assign((yyvsp[-2].Token).name, v))
                    yyerror(type_match_err);
            }
        }
#line 2541 "y.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 798 "yacc.y" /* yacc.c:1661  */
    {printf("in pre simple_statement\n");}
#line 2547 "y.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 803 "yacc.y" /* yacc.c:1661  */
    { 
            //type check
           
            variable left_v = global_st.lookup_variable((yyvsp[-2].Token).name);
            if(left_v.type != (yyvsp[0].Token).token_type)
                yyerror(type_match_err);
            //check global or local and assign
            if(left_v.is_global)
                fprintf(java_code, "\t\tputstatic int proj3.%s\n", (yyvsp[-2].Token).name);
            else                    
                fprintf(java_code, "\t\tistore %d\n", left_v.virtual_index);
            //get value
            variable v((yyvsp[0].Token).token_type);
            if(!global_st.assign((yyvsp[-2].Token).name, v))
                yyerror(type_match_err);
            //if it is primitive
            else {
                if(!global_st.assign((yyvsp[-2].Token).name, v))
                    yyerror(type_match_err);
            }
        }
#line 2573 "y.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 823 "yacc.y" /* yacc.c:1661  */
    {
            printf("in post simple_statement\n");
            fprintf(java_code,"\ticonst_0\n");
            fprintf(java_code,"\t\tpop\n");
        }
#line 2583 "y.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 829 "yacc.y" /* yacc.c:1661  */
    {
            printf("in bool for\nin bool for\nin bool for\n");
            // label_index -= 1;
            // label_stack[label_stack_top++] = label_index;
            //Ltest
            // label_index += 4;

            printf("in bool_exp\nin bool_exp\nin bool_exp\nin for\nin for\nin for\n");

            // if($5.token_type != T_BOOL){
            //     yyerror(type_match_err);
            // }
            //go exit
            fprintf(java_code,"\t\tifeq L%d\n", label_stack[label_stack_top-1] + 3);
            //go to Lbody
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 2);
            //Lpost
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 1);
        }
#line 2607 "y.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 847 "yacc.y" /* yacc.c:1661  */
    {
            
            //go to Ltest
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1]);
        //     //Lbody
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 2);
            
        }
#line 2620 "y.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 854 "yacc.y" /* yacc.c:1661  */
    {
             //     //go to Lpost
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 1);
            fprintf(java_code,"\tL%d:\n", label_stack[--label_stack_top] + 3);
            fprintf(java_code,"\ticonst_0\n");
            fprintf(java_code,"\t\tpop\n");

        }
#line 2633 "y.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 863 "yacc.y" /* yacc.c:1661  */
    {
            //bcz it don't need preprocess
            --label_stack_top;
            label_index -= 3;
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top] + 1);

            label_stack[label_stack_top++] = label_index;
            //Ltest
            fprintf(java_code,"\tL%d:\n", label_index);
            label_index += 4;

            
        }
#line 2651 "y.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 875 "yacc.y" /* yacc.c:1661  */
    {
            printf("in bool_exp\nin bool_exp\nin bool_exp\nin for\nin for\nin for\n");

            // if($5.token_type != T_BOOL){
            //     yyerror(type_match_err);
            // }
            //go exit
            fprintf(java_code,"\t\tifeq L%d\n", label_stack[label_stack_top-1] + 3);
            //go to Lbody
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 2);
            //Lpost
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 1);
        }
#line 2669 "y.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 887 "yacc.y" /* yacc.c:1661  */
    {
            
            //go to Ltest
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1]);
        //     //Lbody
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 2);
            
        }
#line 2682 "y.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 894 "yacc.y" /* yacc.c:1661  */
    {
             //     //go to Lpost
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 1);
            fprintf(java_code,"\tL%d:iconst_0\n", label_stack[--label_stack_top] + 3);
            fprintf(java_code,"\t\tpop\n");

        }
#line 2694 "y.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 905 "yacc.y" /* yacc.c:1661  */
    {
            label_stack[label_stack_top++] = label_index;
            //Ltest
            fprintf(java_code,"\tL%d: iconst_0\n", label_index);
            fprintf(java_code,"\t\tpop\n");

            label_index += 4;

        }
#line 2708 "y.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 916 "yacc.y" /* yacc.c:1661  */
    {
            if(!global_st.function_type_check((yyvsp[-2].Token).name, ""))
                yyerror(type_match_err);
        }
#line 2717 "y.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 920 "yacc.y" /* yacc.c:1661  */
    {args_buffer[0] = '\0';}
#line 2723 "y.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 920 "yacc.y" /* yacc.c:1661  */
    {
            if(!global_st.function_type_check((yyvsp[-4].Token).name, (yyvsp[-1].Token).concat_name))
                yyerror(type_match_err);
        }
#line 2732 "y.tab.c" /* yacc.c:1661  */
    break;


#line 2736 "y.tab.c" /* yacc.c:1661  */
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
#line 926 "yacc.y" /* yacc.c:1906  */


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
    /* code */
    java_code = fopen("b10315007.jasm","w");
    fprintf(java_code,"class proj3\n{\n");
    yyparse();
    fprintf(java_code,"}");
    fclose(java_code);
    return 0;

    // global_st.dump();
    // return 0;
}
