%{
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
        int arr_idx;
        int token_type;
        int state; //0 => id || 1 => primitive type
    }Token;
}

%type<Token> ID
%type<Token> STR
%type<Token> identifier_list
%type<Token> REAL_NUMBER
%type<Token> NUMBER
%type<Token> bool_type
%type<Token> primitive_type
%type<Token> primitive
%type<Token> expression
%type<Token> bool_exp
%type<Token> array_element
%type<Token> object

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
    primitive_type: INT{ $$.token_type =  T_INT; }  | BOOL{$$.token_type =  T_BOOL;} | STRING{$$.token_type =  T_STR;} | REAL{$$.token_type =  T_REAL;};
    primitive: NUMBER{ $$.token_type = T_INT; $$.state = S_PRIMITIVE; $$.val = $1.val; }| bool_type{ $$.token_type = T_BOOL; $$.state = S_PRIMITIVE; $$.flag = $1.flag; } | STR{ $$.token_type = T_STR; $$.state = S_PRIMITIVE; $$.name = $1.name; } | REAL_NUMBER{ $$.token_type = T_REAL; $$.state = S_PRIMITIVE; $$.name = $1.name; };
    bool_type: TRUE{$$.token_type = T_BOOL; $$.state = S_PRIMITIVE; $$.flag = true;}| FALSE{$$.token_type = T_BOOL; $$.state = S_PRIMITIVE; $$.flag = false;};
    array_element:
        ID '[' expression ']' {
            //if its expression isn't int then it will abort
            //if it is ID or array elemeny check type
            if($3.state == S_ID){
                if (global_st.lookup_variable($3.name).type != T_INT){
                    yyerror(arr_id_err);
                }
            }
            else if($3.state == S_ARRAY){
                if(global_st.lookup_array($3.name, $3.arr_idx).type != T_INT)
                    yyerror(declared_err);
            }
            //if it is primitive
            else {
                if($3.token_type != T_INT){
                    yyerror(arr_id_err);
                }
            }
            $$.name = $1.name;
            //Todo::set 0 because expression can not calculate
            $$.arr_idx = 0;
            $$.state = S_ARRAY; 
            $$.token_type = global_st.lookup_array($$.name, $$.arr_idx).type;  
        };
    object: ID{
                $$ = $1;
                // $$.name = $1.name; 
                $$.state = S_ID; 
                $$.token_type = global_st.lookup_variable($1.name).type; 
            }| 
            array_element{$$ = $1;};
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
        FUNC VOID ID '(' formal_args ')' compound|
        FUNC ID '(' ')' compound|
        FUNC ID '(' formal_args ')' compound;        
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
                yyerror(declared_err);
        }|
        VAR identifier_list INT '=' NUMBER {
            variable v(T_INT, 0, $5.val); 
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
        }|
        VAR identifier_list BOOL '=' bool_type {
            printf("T_BOOL = %d\n", T_BOOL);
            variable v(T_BOOL, 0, $5.flag); 
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
        }|
        VAR identifier_list STRING '=' STR { 
            variable v(T_STR, 0, $5.name); 
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
        }|
        VAR identifier_list REAL '=' REAL_NUMBER {
            variable v(T_REAL, 0, $5.name); 
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
        }|
        //array declaration
        //iterator assign => id[0] id[1] ... id[n]
        VAR identifier_list '[' expression ']' primitive_type {
            if($4.state == S_ID){
                if (global_st.lookup_variable($4.name).type != T_INT){
                    yyerror(arr_id_err);
                }
            }
            else if ($4.state == S_ARRAY){
                if(global_st.lookup_array($4.name, $4.arr_idx).type != T_INT)
                    yyerror(declared_err);
            }
            //if it is primitive
            else{ 
                if ($4.token_type != T_INT)
                yyerror(arr_id_err);
            }
            //store in symbol table
            //consider 2 situation 1: it is int-expression 2: it is primitive
            variable v($6.token_type, 0); 
            if($4.state == S_ID){
                if(!global_st.declared_array($2.name, v, global_st.lookup_variable($4.name).data.value))
                    yyerror(declared_err);
            }
            else if($4.state == S_ARRAY){
                if(!global_st.declared_array($2.name, v, global_st.lookup_array($4.name, $4.arr_idx).data.value))
                    yyerror(declared_err);
            }
            //if it is primitive
            else {
                if(!global_st.declared_array($2.name, v, $4.val))
                    yyerror(declared_err);
            }
            
        }|
        CONST identifier_list '=' primitive {
            variable v($4.token_type, 1); 
            if($4.token_type == T_INT)
                v.data.value = $4.val;
            else if($4.token_type == T_BOOL)
                v.data.flag = $4.flag;
            else
                v.data.str = $4.name;
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
        };
    simple_statement: //include varialbe or array assign and function call
        object '=' expression { 
            // printf("$1 name = %s  $3 name = %s\n", $1.name, $3.name);
            // printf("$1 state = %d\n", $1.state);
            printf("$1 use look id type = %d, $3 token_type = %d, $3 state = %d\n", global_st.lookup_variable($1.name).type, $3.token_type, $3.state);
            printf("$1 use look arr type = %d, $3 token_type = %d, $3 state = %d\n", global_st.lookup_array($1.name, $1.arr_idx).type, $3.token_type, $3.state);
            // printf("$1 type = %d, $3 in varialbe type = %d\n", global_st.lookup_variable($1.name).type, global_st.lookup_variable($3.name).type);
            // global_st.dump();
            //type check
            if($1.state == S_ARRAY){
                if(global_st.lookup_array($1.name, $1.arr_idx).type != $3.token_type)
                    yyerror(type_match_err);
            }
            else if($1.state == S_ID){
                if(global_st.lookup_variable($1.name).type != $3.token_type)
                    yyerror(type_match_err);
            }


            //get value
            // variable v;
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
            // if($3.state == S_ARRAY){

            //     if(!global_st.assign_array_by_id($1.name, $1.arr_idx, v))
            //         yyerror(declared_err);
            // }
            // else if($3.state == S_ID){
            //     if(!global_st.assign($1.name, v, )
            //         yyerror(declared_err);
            // }
            // //if it is primitive
            // else {
            //     if(!global_st.declared_array($2.name, v, $4.val))
            //         yyerror(declared_err);
            // }
        }|
        PRINT expression |
        PRINTLN expression |
        READ ID |
        RETURN expression|
        RETURN ;

    expression: // math experssion and boolean expression
        object {$$ = $1;}|
        primitive {$$ = $1;}|
        expression op_order4 expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
        }| 
        expression op_order3 expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
        }| 
        expression op_order2 expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
        }| 
        '-' expression %prec UMINUS  {
            $$ = $2;
        }|
        '(' expression ')'{
            $$ = $2;
        };
    bool_exp:
        expression {$$.token_type = T_BOOL;}|
        '(' bool_exp ')'{$$ = $2;}|
        '!' bool_exp {$$.token_type = T_BOOL;}|
        bool_exp op_order8 bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
        }| 
        bool_exp op_order7 bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
        }| 
        bool_exp op_order6 bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
        }| 
        bool_exp op_order5 bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
        };
        


    compound:
        '{' '}'|
        '{'{ global_st.push_table(); printf("push table\n");} statements '}'{ global_st.pop_table(); printf("pop table\n");};
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
