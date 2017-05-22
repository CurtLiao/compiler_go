/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 23 "yacc.y" /* yacc.c:1915  */

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

#line 162 "y.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
