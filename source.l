%{
#include <ctype.h>
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; 	printf("<'%s'>\n", yytext); }
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n","integer",i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n","string",s);}
#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];
%}

digit [0-9]+
letter [A-Za-z]
id {letter}({letter}|{digit})*

%%


","    {token(',');}
":"    {token(':');}
";"    {token(';');}
"("    {token('(');}
")"    {token(')');}
"["    {token('[');}
"]"    {token(']');}
"{"    {token('{');}
"}"    {token('}');}

"+"    {token('+');}
"-"    {token('-');}
"*"    {token('*');}
"/"    {token('/');}
"^"    {token('^');}
"%"    {token('%');}
"<"    {token('<');}
"<="   {token("<=");}
">="   {token(">=");}
">"    {token('>');}
"=="   {token("==");}
"!="   {token("!=");}
"&"    {token('&');}
"|"    {token('|');}
"!"    {token('!');}
"="    {token('=');}
"+="   {token("+=");}
"-="   {token("-=");}
"*="   {token("*=");}
"/="   {token("/=");}

bool	{token("BOOL")}
break	{token("BREAK")}
case	{token("CASE")}
const	{token("CONST")}
continue	{token("CONTINUE")}
default	{token("DEFAULT")}
else	{token("ELSE")}
false	{token("FALSE")}
for	{token("FOR")}
func	{token("FUNC")}
go	{token("GO")}
if	{token("IF")}
import	{token("IMPORT")}
int	{token("INT")}
nil	{token("NIL")}
print	{token("PRINT")}
println	{token("PRINTLN")}
real	{token("REAL")}
return	{token("RETURN")}
string	{token("STRING")}
struct	{token("STRUCT")}
switch	{token("SWITCH")}
true	{token("TRUE")}
type	{token("TYPE")}
var	{token("VAR")}
void	{token("VOID")}
while	{token("WHILE")}

{id}		{tokenString("id", yytext);}
{digit}    	{tokenInteger("integer",atoi(yytext));}



\n     {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%
