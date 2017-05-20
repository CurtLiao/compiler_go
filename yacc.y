%{
#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"
symbol_table global_st;
int variable_type; // 0=> int 1=> bool 2=> string 3=>real
bool const_flag = false;
enum Type_enum{T_INT = 0, T_BOOL = 1, T_STR, T_REAL};
int yylex();
int yyerror(char *s);
%}
//add my type to pass the value from lex
%union 
{
    struct
    {
        union{
            char *name;
            int  val;
            bool flag;
        };
        int token_type;
    }Token;
}

// %union 
// {
//     char    *name;
//     int     val;
// }
%type<Token> ID
%type<Token> STR
%type<Token> identifier_list
%type<Token> REAL_NUMBER
%type<Token> NUMBER
%type<Token> bool_type
%type<Token> primitive_type


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
%token READ

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
%left '+' '-' '*' '/' '%' '^'
%left '<' '>' LESS_EQUAL GREAT_EQUAL EQUAL NOT_EQUAL
%left '!' '&' '|'
%nonassoc UMINUS


%%
    primitive_type: INT{ $$.token_type = T_INT; }  | BOOL{$$.token_type =  T_BOOL;} | STRING{$$.token_type =  T_STR;} | REAL{$$.token_type =  T_REAL;};
    primitive: NUMBER| bool_type | STR | REAL_NUMBER;
    bool_type: TRUE{$$.token_type = T_BOOL; $$.flag = true;}| FALSE{$$.token_type = T_BOOL; $$.flag = false;};
    op_order2: '^' ;
    op_order3: '*' | '/' | '%' ;
    op_order4: '+' | '-' ;
    op_order5: '<' | '>' | LESS_EQUAL | GREAT_EQUAL | EQUAL | NOT_EQUAL;
    op_order6: '!' ;
    op_order7: '&' ;
    op_order8: '|' ;

    
    program: //start program
        statements{Trace("Reducing to program\n");};
    statements: //statements can be a one statement or statements
        statement | statement statements;
    statement: 
        declared { Trace("declare id \n");}|
        simple_statement { Trace("simple statement\n");}|
        compound |
        func_invoke |   
        condition |   
        for_loop |
        go;      

    func_declared: // can provide function declared, support void type
        FUNC primitive_type ID '(' ')' compound|
        FUNC primitive_type ID '(' formal_args ')' compound|
        FUNC VOID ID '(' ')' compound|
        FUNC VOID ID '(' formal_args ')' compound;
    formal_args: // like  int a, int b, .... 
        primitive_type ID|
        primitive_type ID ',' formal_args;
    declared: // variable or function declartd
        func_declared | 
        identifier_declared ;
    identifier_list:          // identifier list can pass one or more id
        ID ',' identifier_list {  printf("\t id , identifier_list || id = %s\n", $1.name); strcat($$.name, " "); strcat($$.name, $3.name);}|
        ID     {printf("\t id in identifier_list || id = %s\n", $1.name); $$.name = $1.name; };
    identifier_declared:  //declare the type of id and type check
        VAR identifier_list primitive_type { 
            if(!global_st.declared($2.name, $3.token_type))
                yyerror("declared error");
            Trace("identifier_declared non \n");
        }|
        VAR identifier_list INT '=' NUMBER {
            variable v(T_INT, 0, $5.val); 
            if(!global_st.declared($2.name, v))
                yyerror("declared error");
            Trace("identifier_declared INT \n");
        }|
        VAR identifier_list BOOL '=' bool_type {
            printf("T_BOOL = %d\n", T_BOOL);
            variable v(T_BOOL, 0, $5.flag); 
            if(!global_st.declared($2.name, v))
                yyerror("declared error");
            Trace("identifier_declared BOOL \n");
        }|
        VAR identifier_list STRING '=' STR { 
            variable v(T_STR, 0, $5.name); 
            if(!global_st.declared($2.name, v))
                yyerror("declared error");
        }|
        VAR identifier_list REAL '=' REAL_NUMBER {
            variable v(T_REAL, 0, $5.name); 
            if(!global_st.declared($2.name, v))
                yyerror("declared error");
            Trace("identifier_declared REAL \n");}|
        VAR identifier_list '[' NUMBER ']' primitive_type {
            //array declaration
            //iterator assign => id[0] id[1] ... id[n]
            variable v($6.token_type, 0); 
            printf("pre array func = %d\n", $4.val);
            if(!global_st.declared_array($2.name, v, $4.val))
                yyerror("declared error");

            Trace("identifier_declared array \n");
        }|
        CONST identifier_list '=' primitive {Trace("CONST \n");};
    simple_statement: //include varialbe or array assign and function call
        ID '=' expression { printf("\t id = expression || id = %s\n", $1.name);}|
        ID '[' NUMBER ']''=' expression {

        }|
        PRINT expression |
        PRINTLN expression |
        READ ID   {  printf("\t Read id || id = %s\n", $2.name);}|
        RETURN expression|
        RETURN ;
    expression: // math experssion and boolean expression
        ID |
        primitive |
        expression op_order4 expression | 
        expression op_order3 expression | 
        expression op_order2 expression | 
        '-' expression %prec UMINUS  |
        '(' expression ')';
    bool_exp:
        expression {Trace("exp \n");}|
        '(' bool_exp ')'|
        '!' bool_exp {Trace("!bool_exp \n");}|
        bool_exp op_order8 bool_exp | 
        bool_exp op_order7 bool_exp | 
        bool_exp op_order6 bool_exp | 
        bool_exp op_order5 bool_exp ;
        


    compound:
        '{' '}'|
        '{' statements '}'{    global_st.push_table();};
    func_invoke:
        ID '(' identifier_list ')';
    condition:
        IF '(' bool_exp ')' statement|
        IF '(' bool_exp ')' statement ELSE statement;
    for_loop:
        FOR '(' bool_exp ')' simple_statement|
        FOR '(' bool_exp ')' compound|
        FOR '(' statement ';' bool_exp ')' simple_statement|
        FOR '(' statement ';' bool_exp ')' compound|
        FOR '(' bool_exp ';' statement ')' simple_statement|
        FOR '(' bool_exp ';' statement ')' compound|
        FOR '(' statement ';' bool_exp ';' statement ')' simple_statement|
        FOR '(' statement ';' bool_exp ';' statement ')' compound;
    go:
        GO ID '(' identifier_list ')';

        
%%

int yyerror(char *s)
{
    
    // printf("%d:  %s:  \n", linenum, s);
    printf("compiler error:  %s  \n", s);
    abort();

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
    global_st.dump();
}