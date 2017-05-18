%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"


#define LIST     strcat(buf,yytext)
#define token(t) {LIST; 	printf("<'%s'>\n", yytext); return(t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n", "NUMBER", i); 	yylval.Token.val = i; yylval.Token.token_type = T_INT;return(NUMBER);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n", "String", yytext); yylval.Token.name = s; yylval.Token.token_type = T_STR; return(STR);}
#define MAX_LINE_LENG 256
#define printYYText() {LIST; printf("%s\n",yytext);}
#define printLine() {LIST;printf("%d: %s", linenum++, buf);    buf[0] = '\0';}
// symbol_table st;
// symbol_table_entry currentSTE;
int linenum = 1;
char buf[MAX_LINE_LENG];
char strBuf[MAX_LINE_LENG];
enum Type_enum{T_INT = 1, T_BOOL, T_STR, T_REAL};

%}

digit [0-9]+
letter [A-Za-z]
id {letter}({letter}|{digit}|_)*
%x commentState

%%

"/*" {
	// for comment /* */
	LIST;
	BEGIN(commentState);
}
<commentState>"*/" {
	LIST;
	BEGIN(INITIAL);
}
<commentState>\n|<commentState>\r\n {printLine();}
<commentState>. {LIST;}
\/\/.* {
	// comment //
	LIST;
}
\".*\" {
	// for string
	// delete first "
	strcpy(strBuf, yytext+1);
	// delete last "
	strBuf[strlen(strBuf)-1] = '\0';
	int count = -1;
	// replace "" to "
	while(strBuf[++count] != '\0'){
		if(strBuf[count] == '\"'){
			int temp = count;
			while(strBuf[temp++] != '\0')
				strBuf[temp] = strBuf[temp+1];
		}
	}
	tokenString("string", strBuf);
	strBuf[0] = '\0';
}



","          {token(',');}
":"          {token(':');}
";"          {token(';')}
"("          {token('(')}
")"          {token(')')}
"["          {token('[')}
"]"          {token(']')}
"{"          {token('{')}
"}"          {token('}')}
"+"          {token('+')}
"-"          {token('-')}
"*"          {token('*')}
"/"          {token('/')}
"^"          {token('^')}
"%"          {token('%')}
"<"          {token('<')}
">"          {token('>')}
"&"         {token('&')}
"|"         {token('|')}
"!"         {token('!')}
"="         {token('=')}
"<="         {token(LESS_EQUAL);}
">="         {token(GREAT_EQUAL);}
"=="         {token(EQUAL);}
"!="         {token(NOT_EQUAL);}
"+="         {token(ADD_ASSIGNMENT);}
"-="         {token(SUB_ASSIGNMENT);}
"*="         {token(MUL_ASSIGNMENT);}
"/="         {token(DIV_ASSIGNMENT);}

bool		{token(BOOL);}
break		{token(BREAK);}
case		{token(CASE);}
const		{token(CONST);}
continue		{token(CONTINUE);}
default		{token(DEFAULT);}
else		{token(ELSE);}
false		{	yylval.Token.flag = false; yylval.Token.token_type = T_BOOL; token(FALSE);}
for		{token(FOR);}
func		{token(FUNC);}
go		{token(GO);}
if		{token(IF);}
import		{token(IMPORT);}
int		{token(INT);}
nil		{token(NIL);}
print		{token(PRINT);}
println		{token(PRINTLN);}
real		{token(REAL);}
return		{token(RETURN);}
string		{token(STRING);}
struct		{token(STRUCT);}
switch		{token(SWITCH);}
true		{	yylval.Token.flag = true; yylval.Token.token_type = T_BOOL; token(TRUE);}
type		{token(TYPE);}
var		{token(VAR);}
void		{token(VOID);}
while		{token(WHILE);}
read		{token(READ);}


{id}		{
	yylval.Token.name = strdup(yytext);
	yylval.Token.token_type = T_STR;
	printf("<%s:%s>\n", "ID", yytext);
	token(ID);
}
{digit}*("."{digit}*)?["e"|"E"][+-]?{digit}*|{digit}"."{digit}* {
	yylval.Token.name = strdup(yytext);
	yylval.Token.token_type = T_REAL;
	token(REAL_NUMBER);
}


[+-]?{digit}    {
	tokenInteger("integer",atoi(yytext));}

\n|\r\n {printLine();}
[ \t]*  {LIST;}
.   {
    LIST;
    printf("%d:%s\n", linenum+1, buf);
    printf("bad character:'%s'\n",yytext);
    exit(-1);
}
%%
// int main(int argc, char const *argv[])
// {
	// currentSTE = st.create();
	// yylex();	
	/* code */
	// show symbol table
	// st.dump(&currentSTE);
	// return 0;
// }
int yywrap(){
	if(buf[0] != '\0'){
		printf("%d: %s\n", linenum++, buf); 
		buf[0] = '\0';
	}
	return 1;
}

/*
","          {token(COMMA);}
":"          {token(COLON);}
";"          {token(SEMICOLON);}
"("          {token(LEFT_PARENTHESES);}
")"          {token(RIGHT_PARENTHESES);}
"["          {token(LEFT_SQUARE_BRACKET);}
"]"          {token(RIGHT_SQUARE_BRACKET);}
"{"          {token(LEFT_BRACKET);}
"}"          {token(RIGHT_BRACKET);}
"+"          {token(ADD);}
"-"          {token(SUB);}
"*"          {token(MUL);}
"/"          {token(DIV);}
"^"          {token(POWER);}
"%"          {token(MOD);}
"<"          {token(LESS);}
"<="         {token(LESS_EQUAL);}
">="         {token(GREAT_EQUAL);}
">"         {token(GREAT);}
"=="         {token(EQUAL);}
"!="         {token(NOT_EQUAL);}
"&"         {token(AND);}
"|"         {token(OR);}
"!"         {token(NOT);}
"="         {token(ASSIGNMENT);}
"+="         {token(ADD_ASSIGNMENT);}
"-="         {token(SUB_ASSIGNMENT);}
"*="         {token(MUL_ASSIGNMENT);}
"/="         {token(DIV_ASSIGNMENT);}
*/