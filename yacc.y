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
        identifier_declared { Trace("declare id \n");}|
        identifier_declared statement{ Trace("declare id and states\n");};
    identifier_list:          //變數宣告的LIST
        ID ',' identifier_list  {Trace("identifier_list\n");}|
        ID     {   
                    Trace("ID ="); 
                    //printf("%s\n", $1);
                };

    identifier_declared:  //declare the type of id
        VAR identifier_list primitive_type { Trace("identifier_declared non \n");}|
        VAR identifier_list INT '=' NUMBER {Trace("identifier_declared INT \n");}|
        VAR identifier_list BOOL '=' bool_type {Trace("identifier_declared BOOL \n");}|
        VAR identifier_list STRING '=' STR {Trace("identifier_declared STR \n");}|
        VAR identifier_list REAL '=' REAL_NUMBER {Trace("identifier_declared REAL \n");}|
        VAR identifier_list '[' NUMBER ']' primitive_type {Trace("identifier_declared array \n");}|//array declaration
        CONST identifier_list '=' primitive {Trace("CONST \n");};

    primitive_type: STRING | INT | BOOL | REAL;
    primitive: STR | NUMBER | REAL_NUMBER | bool_type;
    bool_type: TRUE | FALSE;


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

int main(int argc, char const *argv[])
{
    // currentSTE = st.create();
    // yylex(); 
    /* code */
    // show symbol table
    // st.dump(&currentSTE);
    // return 0;
    yyparse();
}