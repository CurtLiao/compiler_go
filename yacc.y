%{
#include "lex.yy.c"
#include <stdlib.h>
#include <stdio.h>
#define Trace(t)        printf(t)
 // void yyerror (char const *s);
int yyerror(char *s);

%}

/* tokens */
%token BOOL
%token BREAK
%token CASE
%token CONST
%token CONTINUE
%token DEFAULT
%token ELSE
%token FALSE
%token FOR
%token FUNC
%token GO
%token IF
%token IMPORT
%token INT
%token NIL
%token PRINT
%token PRINTLN
%token REAL
%token RETURN
%token STRING
%token STRUCT
%token SWITCH
%token TRUE
%token TYPE
%token VAR
%token VOID
%token WHILE
%token COMMA
%token COLON
%token SEMICOLON
%token LEFT_PARENTHESES
%token RIGHT_PARENTHESES
%token LEFT_SQUARE_BRACKET
%token RIGHT_SQUARE_BRACKET
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token ADD
%token SUB
%token MUL
%token DIV
%token POWER
%token MOD
%token LESS
%token LESS_EQUAL
%token GREAT
%token GREAT_EQUAL
%token EQUAL
%token NOT_EQUAL
%token AND
%token OR
%token NOT
%token ASSIGNMENT
%token ADD_ASSIGNMENT
%token SUB_ASSIGNMENT
%token MUL_ASSIGNMENT
%token DIV_ASSIGNMENT
%token NUMBER
%token STR
%token ID
%token REAL_NUMBER
%start program


%%

    program:
        statement{Trace("Reducing to program\n");};

    statement: 
        identifier_declared |
        identifier_declared statement;
    identifier_list:          //變數宣告的LIST
        ID ',' identifier_list  {Trace("identifier_list");}|
        ID '=' ID ',' identifier_list    {   Trace("id = id ,list");}|
        ID '=' ID    {   Trace("id = id ");}|
        ID '=' NUMBER    {   Trace("id = id ");}|
        ID     {   Trace("identifier_list ',' identifier_decl");};

    identifier_declared:  //declare the type of id
        VAR identifier_list primitive_type '=' NUMBER {Trace("identifier_declared '=' ");}|
        VAR identifier_list primitive_type {Trace("identifier_declared non '='");};
    primitive_type: STRING | INT | BOOL | REAL;

%%

// yyerror(msg)
int yyerror(char *s)
{
    
    printf("%d:  %s:  \n", ++linenum, s);
    return 0;
    // char *msg;
    // {
    //     fprintf(stderr, "%s\n", msg);
    // }
}
 // void yyerror (char const *s) {
 //   fprintf (stderr, "%s\n", s);
 // }

// main()
// {
//     printf ("yacc main\n");

//     /* open the source program file */
//     if (argc != 2) {
//         printf ("Usage: sc filename\n");
//         exit(1);
//     }
//     yyin = fopen(argv[1], "r");         /* open input file */

//     /* perform parsing */
//     if (yyparse() == 1)                 /* parsing */
//         yyerror("Parsing error !");     /* syntax error */
// }


