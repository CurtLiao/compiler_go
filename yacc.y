%{
#define Trace(t)        printf(t)
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
%token REAL_NUMBER
%token ID


%%
program:        ID semi
                {
                Trace("Reducing to program\n");
                }
                ;

semi:           "<="
                {
                Trace("Reducing to semi\n");
                }
                ;
%%
#include "lex.yy.c"

yyerror(msg)
char *msg;
{
    fprintf(stderr, "%s\n", msg);
}

main()
{
    /* open the source program file */
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
}


