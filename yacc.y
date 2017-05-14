%{
#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
int yylex();
int yyerror(char *s);
%}

/* tokens */
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

%token LESS_EQUAL
%token GREAT_EQUAL
%token EQUAL
%token NOT_EQUAL
%token AND
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
        ID ',' identifier_list  {Trace("identifier_list\n");}|
        ID '=' ID ',' identifier_list    {   Trace("id = id ,list\n");}|
        ID '=' ID    {   Trace("id = id \n");}|
        ID '=' NUMBER    {   Trace("id = id \n");}|
        ID     {   Trace("ID\n");};

    identifier_declared:  //declare the type of id
        VAR identifier_list primitive_type '=' NUMBER {Trace("identifier_declared '=' \n");}|
        VAR identifier_list primitive_type {Trace("identifier_declared non '='\n");};
    primitive_type: STRING | INT | BOOL | REAL;

%%

int yyerror(char *s)
{
    
    // printf("%d:  %s:  \n", linenum, s);
    printf("666:  %s:  \n", s);

    return 0;
    // char *msg;
    // {
    //     fprintf(stderr, "%s\n", msg);
    // }
}

