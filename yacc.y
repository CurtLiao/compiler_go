%{
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

%}
//add my type to pass the value from lex
%union 
{
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
}

%type<Token> ID
%type<Token> STR
%type<Token> REAL_NUMBER
%type<Token> NUMBER
%type<Token> identifier_list
%type<Token> argument_list
%type<Token> bool_type
%type<Token> primitive_type
%type<Token> primitive
%type<Token> expression
%type<Token> bool_exp
// %type<Token> mix_exp
%type<Token> array_element
%type<Token> object
%type<Token> func_invoke

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
%left '|'
%left '&'
%left '!' 
%left '<' '>' LESS_EQUAL GREAT_EQUAL EQUAL NOT_EQUAL
%left '+' '-' 
%left '*'  '/' '%' 
%right '^'
%right UMINUS
// %nonassoc UMINUS
//to count linenum

%%
    
    primitive_type: INT{ $$.token_type =  T_INT; }  | BOOL{$$.token_type =  T_BOOL;} | STRING{$$.token_type =  T_STR;} | REAL{$$.token_type =  T_REAL;};
    primitive: NUMBER{ 
        $$.token_type = T_INT; 
        $$.state = S_PRIMITIVE; 
        $$.val = $1.val;  
        if(const_flag != true)
            fprintf(java_code, "\t\tsipush %d\n", $1.val);
    }| bool_type{ 
        $$.token_type = T_BOOL; 
        $$.state = S_PRIMITIVE; 
        $$.flag = $1.flag; 
        if(const_flag != true){
            if($$.flag)    
                fprintf(java_code, "\t\tsipush %d\n", 1);
            else        
                fprintf(java_code, "\t\tsipush %d\n", 0);
        }
    } | STR{ 
        $$.token_type = T_STR; 
        $$.state = S_PRIMITIVE; 
        $$.name = $1.name; 
        if(const_flag != true)
            fprintf(java_code, "\t\tldc \"%s\" \n", $1.name);

            

    } | REAL_NUMBER{ $$.token_type = T_REAL; $$.state = S_PRIMITIVE; $$.name = $1.name; };
    bool_type: TRUE{$$.token_type = T_BOOL; $$.state = S_PRIMITIVE; $$.flag = true; }| FALSE{$$.token_type = T_BOOL; $$.state = S_PRIMITIVE; $$.flag = false;};
    // for access array element
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
            //passing to $$ to distinguish which expression be returned;
            $$.state = S_ARRAY; 
            //return the type of element
            $$.token_type = global_st.lookup_array($$.name, $$.arr_idx).type;  
        };
    object: ID{
                $$ = $1;
                $$.state = S_ID; 
                //return the type of element
                variable left_v = global_st.lookup_variable($1.name);
                $$.token_type = left_v.type; 
                if(left_v.is_global)
                    fprintf(java_code, "\t\tgetstatic int proj3.%s\n", $1.name);
                else                    
                    fprintf(java_code, "\t\tiload %d\n", left_v.virtual_index);
            }| 
            array_element{$$ = $1;};
    // math operator Priority  
    op_order2: '^' ;
    // op_order3: '*' | '/' | '%' ;
    // op_order4: '+' | '-' ;
    // op_order5: '<' | '>' | LESS_EQUAL | GREAT_EQUAL | EQUAL | NOT_EQUAL;
    // op_order6: '!' ;
    // op_order7: '&' ;
    // op_order8: '|' ;

    
    program: //start program
        statements{ Trace("Reducing to program\n");};
    statements: //statements can be a one statement or statements
        statement | statement statements;
    statement: 
        declared { Trace("declare id \n");}|
        simple_statement { Trace("simple statement\n");}|
        compound |
        func_invoke |   
        condition |   
        for_loop |
        go|
        bool_exp;     

    func_declared: 
        // can provide function declared, support void type
        // push function name to global table, let it can be function call
        FUNC primitive_type ID '(' ')'{
            global_st.function_declared($2.token_type, $3.name);
            if (strcmp($3.name, "main") == 0){
                if($2.token_type == T_INT)
                    fprintf(java_code,"\tmethod public static int main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
                else if($2.token_type == T_BOOL)
                    fprintf(java_code,"\tmethod public static boolean main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
                else if($2.token_type == T_STR)
                    fprintf(java_code,"\tmethod public static string main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            }
            else{
                if($2.token_type == T_INT)
                    fprintf(java_code,"\tmethod public static int %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $3.name);
                else if($2.token_type == T_BOOL)
                    fprintf(java_code,"\tmethod public static boolean %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $3.name);
                else if($2.token_type == T_STR)
                    fprintf(java_code,"\tmethod public static string %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $3.name);
            }
            // fprintf(java_code,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            
            
        } compound {fprintf(java_code,"\t}\n");}|
        FUNC primitive_type ID '('{ 
            global_st.push_table(); 
            global_st.function_declared($2.token_type, $3.name); 
            if($2.token_type == T_INT)
                fprintf(java_code,"\tmethod public static int %s", $3.name);
            else if($2.token_type == T_BOOL)
                fprintf(java_code,"\tmethod public static boolean %s", $3.name);
            else if($2.token_type == T_STR)
                fprintf(java_code,"\tmethod public static string %s", $3.name);

        } formal_args ')'{
            global_st.args_encode_index();
            variable v = global_st.lookup_variable($3.name);
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
            fprintf(java_code,")\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            
        } compound {fprintf(java_code,"\t}\n");global_st.pop_table();}|
        FUNC VOID ID '(' ')'{
            global_st.function_declared(-1, $3.name);
            if (strcmp($3.name, "main") == 0){
                fprintf(java_code,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            }
            else{
                fprintf(java_code,"\tmethod public static void %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $3.name);
            }

        } compound {fprintf(java_code,"\t\treturn\n\t}\n");}|
        FUNC VOID ID '('{ 
            global_st.push_table(); 
            global_st.function_declared(-1, $3.name);
            fprintf(java_code,"\tmethod public static void %s", $3.name);

        } formal_args ')'{
            global_st.args_encode_index();
            variable v = global_st.lookup_variable($3.name);
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
            fprintf(java_code,")\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        } compound {fprintf(java_code,"\t\treturn\n\t}\n");global_st.pop_table();}|
        FUNC ID '(' ')'{
            global_st.function_declared(-1, $2.name);
            if (strcmp($2.name, "main") == 0){
                fprintf(java_code,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            }
            else{
                fprintf(java_code,"\tmethod public static void %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $2.name);
            }        } compound{fprintf(java_code,"\t\treturn\n\t}\n");}|
        FUNC ID '('{ 
            global_st.push_table(); 
            global_st.function_declared(-1, $2.name);
            fprintf(java_code,"\tmethod public static void %s(", $2.name);

        } formal_args ')'{
            global_st.args_encode_index();
            variable v = global_st.lookup_variable($2.name);
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
            fprintf(java_code,")\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        } compound{fprintf(java_code,"\t\treturn\n\t}\n");global_st.pop_table();};        
    formal_args: 
        // like   a int , b int , .... 
        //it will return 0 0 bcz int type i set => 0
        ID primitive_type{
            global_st.function_concat($2.token_type, $1.name);
        }|
        ID primitive_type ',' formal_args{
            global_st.function_concat($2.token_type, $1.name);
        };
    declared: // variable or function declared
        func_declared | 
        identifier_declared ;
    // identifier list can pass one or more id
    // if we have three variable use ','' to concat like "a, b, c" it will return a b c 
    identifier_list:          
        ID ',' identifier_list {  
            // for variable declared like
            printf("\t id , identifier_list || id = %s\n", $1.name); 
            strcat($$.name, " "); 
            strcat($$.name, $3.name);
        }|
        ID     {
            // printf("\t id in identifier_list || id = %s\n", $1.name); 
            $$.name = $1.name; 
        };
    // identifier list can pass one or more id
    // it can handle id and primitive
    argument_list:          
        bool_exp ',' argument_list{
            $$.concat_name = (char*)malloc(2*sizeof(char)); 
            sprintf($$.concat_name, "%d", $1.token_type);
            strcat($$.concat_name, " ");
            strcat($$.concat_name, $3.concat_name);
            printf("\t args in mix_exp, arg_list of argument_list|| id = %s\n", $$.concat_name); 
        }|
        bool_exp     {
            $$.concat_name = (char*)malloc(2*sizeof(char)); 
            sprintf($$.concat_name, "%d", $1.token_type);
            printf("\t args in mix_exp of argument_list|| id = %s\n", $$.concat_name); 
        };
    //declare the type of id and type check
    identifier_declared: 
        VAR identifier_list primitive_type { 
            if(!global_st.declared($2.name, $3.token_type))
                yyerror(declared_err);
            // global variable
            if(global_st.check_global()){
                fprintf(java_code, "\tfield static ");
                if($3.token_type == T_INT)
                    fprintf(java_code, "int");
                else if($3.token_type == T_BOOL)
                    fprintf(java_code, "boolean");
                else if($3.token_type == T_STR)
                    fprintf(java_code, "string");   
                fprintf(java_code, " %s\n", $2.name);
            }

        }|
        VAR identifier_list INT '=' NUMBER {
            variable v(T_INT, 0, $5.val); 
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
            // global variable
            if(global_st.check_global())
                fprintf(java_code, "\tfield static int %s = %d\n", $2.name, $5.val);
        }|
        VAR identifier_list BOOL '=' bool_type {
            printf("T_BOOL = %d\n", T_BOOL);
            variable v(T_BOOL, 0, $5.flag); 
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
            // global variable
            if(global_st.check_global()){
                if($5.flag == false)
                    fprintf(java_code, "\tfield static int %s = %d\n", $2.name, 0);
                else
                    fprintf(java_code, "\tfield static int %s = %d\n", $2.name, 1);
            }

        }|
        VAR identifier_list STRING '=' STR { 
            variable v(T_STR, 0, $5.name); 
            if(!global_st.declared($2.name, v))
                yyerror(declared_err);
            if(global_st.check_global())
                fprintf(java_code, "\tfield static string %s = %s\n", $2.name, $5.name);
            
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
        // const and set flag to remember it is const can not assign
        CONST{
            const_flag = true;
        } identifier_list '=' primitive {
            variable v($5.token_type, 1); 
            if($5.token_type == T_INT)
                v.data.value = $5.val;
            else if($5.token_type == T_BOOL)
                v.data.flag = $5.flag;
            else
                v.data.str = $5.name;
            if(!global_st.declared($3.name, v))
                yyerror(declared_err);
            
            if(global_st.check_global()){
                if($5.token_type == T_INT)
                    fprintf(java_code, "\tfield static int %s = %d\n", $3.name, $5.val);
                else if($5.token_type == T_BOOL)
                    fprintf(java_code, "\tfield static string %s = %s\n", $3.name, $5.name);
                else{
                    if($5.flag == false)
                        fprintf(java_code, "\tfield static int %s = %d\n", $3.name, 0);
                    else
                        fprintf(java_code, "\tfield static int %s = %d\n", $3.name, 1);    
                }
                
            }
            const_flag = false;

        };
    simple_statement: //include varialbe or array assign and function call
        ID '=' bool_exp { 
            //type check
            // if($1.state == S_ARRAY){
            //     if(global_st.lookup_array($1.name, $1.arr_idx).type != $3.token_type)
            //         yyerror(type_match_err);
            // }
            // else if($1.state == S_ID){
                variable left_v = global_st.lookup_variable($1.name);
                if(left_v.type != $3.token_type)
                    yyerror(type_match_err);
                //check global or local and assign
                if(left_v.is_global)
                    fprintf(java_code, "\t\tputstatic int proj3.%s\n", $1.name);
                else                    
                    fprintf(java_code, "\t\tistore %d\n", left_v.virtual_index);
            // }


            //get value
            variable v($3.token_type);
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
            if(!global_st.assign($1.name, v))
                yyerror(type_match_err);
            // }
            //if it is primitive
            else {
                if(!global_st.assign($1.name, v))
                    yyerror(type_match_err);
            }
        }|
        PRINT {fprintf(java_code,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");} 
        expression{
            printf("test type %d\n", $3.token_type);
            if($3.token_type == T_STR)
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
            else
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n"); 
        } |
        PRINTLN {fprintf(java_code,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");} 
        expression{
            printf("test type %d\n", $3.token_type);
            if($3.token_type == T_STR)
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
            else
                fprintf(java_code,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n"); 
        } |
        READ ID |
        RETURN expression{    fprintf(java_code,"\t\tireturn\n");}|
        RETURN {    fprintf(java_code,"\t\tireturn\n");};

    expression: // math experssion and boolean expression
        func_invoke{$$ = $1;}|
        object {$$ = $1;}|
        primitive {$$ = $1;}|
        // expression op_order4 expression {
        //     if($1.token_type != $3.token_type)
        //         yyerror(type_match_err);
        //     $$ = $1;
        // }| 
        expression '+' expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            fprintf(java_code, "\t\tiadd\n");
        }| 
        expression '-' expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            fprintf(java_code, "\t\tisub\n");
        }| 
        expression '*' expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            fprintf(java_code, "\t\timul\n");
        }| 
        expression '/' expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            fprintf(java_code, "\t\tidiv\n");
        }| 
        expression '%' expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            fprintf(java_code, "\t\tirem\n");
        }| 
        // expression op_order3 expression {
        //     if($1.token_type != $3.token_type)
        //         yyerror(type_match_err);
        //     $$ = $1;
        // }|

        expression op_order2 expression {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
        }| 
        '-' expression %prec UMINUS  {
            $$ = $2;
            fprintf(java_code, "\t\tineg\n");

        }|
        '(' expression ')'{
            $$ = $2;
        };
    bool_exp:
        expression {$$ = $1;}|
        '(' bool_exp ')'{$$ = $2;}|
        '!' bool_exp {$$.token_type = T_BOOL;}|
        bool_exp '|' bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tior\n");

        }| 
        bool_exp '&' bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tiand\n");

        }| 
        bool_exp '!' bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tixor\n");
        }| 
        bool_exp '<' bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tiflt L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }|
        bool_exp '>' bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifgt L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }|
        bool_exp EQUAL bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifeq L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }|
        bool_exp LESS_EQUAL bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifle L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }|
        bool_exp GREAT_EQUAL bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifge L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        }|
        bool_exp NOT_EQUAL bool_exp {
            if($1.token_type != $3.token_type)
                yyerror(type_match_err);
            $$ = $1;
            $$.token_type = T_BOOL;
            fprintf(java_code, "\t\tisub\n");
            fprintf(java_code, "\t\tifne L%d\n", label_index);
            fprintf(java_code, "\t\ticonst_0\n");
            fprintf(java_code, "\t\tgoto L%d\n",label_index+1);
            fprintf(java_code, "\tL%d:\ticonst_1\n",label_index);
            fprintf(java_code, "\tL%d:\n",label_index+1);
            label_index +=2;
        };
    // mix_exp:
    //     bool_exp {$$ = $1;}|
    //     expression {$$ = $1;}; //becaz mix_exp will go to exp


    compound:
        '{' '}'|
        '{'{ global_st.push_table();} statements '}'{ global_st.pop_table(); };
    // call function and return the function type
    func_invoke:
        ID '('{args_buffer[0] = '\0';} argument_list ')'{
            // printf("id name = %s\n", $1.name);
            if(!global_st.function_type_check($1.name, $4.concat_name))
                yyerror(type_match_err);
            variable v = global_st.lookup_variable($1.name);
            $$.token_type = v.type;
            // printf("id type = %d\n", $$.token_type);
            fprintf(java_code,"\t\tinvokestatic %s proj3.%s(%s)\n", global_st.variable_type_str($1.name).c_str(), $1.name, global_st.function_args_type($1.name).c_str());
            

        }|
        ID '('')'{
            if(!global_st.function_type_check($1.name, ""))
                yyerror(type_match_err);
            variable v = global_st.lookup_variable($1.name);
            $$.token_type = v.type;
            // printf("id type = %d\n", $$.token_type);
            fprintf(java_code,"\t\tinvokestatic %s proj3.%s()\n", global_st.variable_type_str($1.name).c_str(), $1.name);

        };
    condition:
        IF '(' bool_exp ')'{
            //save index for else
            label_stack[label_stack_top++] = label_index;
            // fprintf(java_code,"\t\ticonst_0\n");
            fprintf(java_code,"\t\tifeq L%d\n", label_index);
            label_index += 2;
        } statement ELSE{
            //go exit
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 1);
            //else lable
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1]);
        } statement{
            fprintf(java_code,"\tL%d:\n", label_stack[--label_stack_top] + 1);
        }
        // |
        // IF '(' bool_exp ')'{
        //     //save index for else
        //     label_stack[label_stack_top++] = label_index;
        //     // fprintf(java_code,"\t\ticonst_0\n");
        //     fprintf(java_code,"\t\tifeq L%d\n", label_index);
        //     label_index += 1;
        // }statement{
        //     fprintf(java_code,"\tL%d:\n", label_stack[--label_stack_top]);
        // }
        ;
    for_loop:
        FOR {
            label_stack[label_stack_top++] = label_index;
            //Ltest
            fprintf(java_code,"\tL%d:\n", label_index);
            label_index += 4;
        }'(' bool_exp ';' {
            //go exit
            fprintf(java_code,"\t\tifeq L%d\n", label_stack[label_stack_top-1] + 3);
            //go to Lbody
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 2);
            //Lpost
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 1);
        } statement {
            if($4.token_type != T_BOOL){
                yyerror(type_match_err);
            }
            //go to Ltest
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1]);
            //Lbody
            fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 2);
            
        } ')' compound{
            //go to Lpost
            fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 1);
            fprintf(java_code,"\tL%d:\n", label_stack[--label_stack_top-1] + 3);

        };
        //correct
        // FOR '(' statement ';' {
        //     label_stack[label_stack_top++] = label_index;
        //     //Ltest
        //     fprintf(java_code,"\tL%d:\n", label_index);
        //     label_index += 4;
            
        // } bool_exp {
        //     if($6.token_type != T_BOOL){
        //         yyerror(type_match_err);
        //     }
        //     //go exit
        //     fprintf(java_code,"\t\tifeq L%d\n", label_stack[label_stack_top-1] + 3);
        //     //go to Lbody
        //     fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 2);
            
        //     //Lbody
        //     fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 2);
            
        // } ')' compound{
        //     //no Lbody go to Ltest
        //     fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1]);
        //     fprintf(java_code,"\tL%d:\n", label_stack[--label_stack_top-1] + 3);

        // }


        //correct
        // FOR '(' statement ';'{
        //     label_stack[label_stack_top++] = label_index;
        //     fprintf(java_code,"\tL%d:\n", label_index);
        //     label_index += 4;
        // } bool_exp ';'{
        //     //go exit
        //     fprintf(java_code,"\t\tifeq L%d\n", label_stack[label_stack_top-1] + 3);
        //     //go to Lbody
        //     fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1] + 2);
        //     //Lpost
        //     fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 1);
        // } statement ')'{
        //     if($6.token_type != T_BOOL){
        //         yyerror(type_match_err);
        //     }
        //     //go to Ltest
        //     fprintf(java_code,"\t\tgoto L%d\n", label_stack[label_stack_top-1]);
        //     //Lbody
        //     fprintf(java_code,"\tL%d:\n", label_stack[label_stack_top - 1] + 2);
            
        // } compound{
        //     //go to Lpost
        //     fprintf(java_code,"\t\tgoto L%d\n", label_stack[--label_stack_top-1] + 1);
        //     fprintf(java_code,"\tL%d:\n", label_stack[--label_stack_top-1] + 3);
        // };

    go:
        GO ID '('')'{
            if(!global_st.function_type_check($2.name, ""))
                yyerror(type_match_err);
        }|
        GO ID '(' {args_buffer[0] = '\0';} argument_list ')'{
            if(!global_st.function_type_check($2.name, $5.concat_name))
                yyerror(type_match_err);
        };


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
