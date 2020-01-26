%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

char c;

%}

DIGIT  [0-9]+
ID [a-zA-Z_][0-9a-zA-Z_]*
FLOAT [0-9]+[.][0-9]*

ARITHMETIC_OPERATORS ['+' '\-' '*' '/' '^' '%' '@']
OTHER_CHARACTERS ['=' ':' ';' '(' ')' '{' '}' ]
BITWISE_OPERATORS ['|' '&' '^' ]
TYPES ["int" "unsigned_int" "double"]

%%
[ \t] ;
[\n] ;


"if" 								{ return (IF); }
"else" 								{ return (ELSE); }
"case"								{ return (CASE);}
"for"								{return (FOR);}
"break"								{return (BREAK);}
"default"							{return (DEFAULT);}
"switch"							{return (SWITCH);}
"while"								{ return (WHILE); }
"unsigned_int" 						{return (TYPES);}
"boolean" 							{return (TYPES);}
"int"								{ return (TYPES); }
"float"								{ return (TYPES); }
"long"								{ return (TYPES); }
"char"								{ return (TYPES); }
"double"							{ return (TYPES); }
"++"								{yylval.sval = strdup(yytext); return INCR;}
"--" 								{yylval.sval=strdup(yytext); return DECR;}
"+="								{yylval.sval=strdup(yytext); return PE;}
"-="								{yylval.sval=strdup(yytext); return ME;}
">"									{yylval.sval = strdup(yytext);
									return (REL_OPT);}
"<"									{yylval.sval = strdup(yytext);
									return (REL_OPT);}
">="								{yylval.sval = strdup(yytext);
									return (REL_OPT);}
"<="								{yylval.sval = strdup(yytext);
									return (REL_OPT);}
"!="								{yylval.sval = strdup(yytext);
									return (REL_OPT);}
"=="								{yylval.sval = strdup(yytext);
									return (REL_OPT);}
	
"||"								{yylval.sval = strdup(yytext);
									return (OR);}
"&&"								{yylval.sval = strdup(yytext);
									return (AND);}
"!"									{yylval.sval = strdup(yytext);
									return (NOT);}
"true"								{yylval.sval = strdup(yytext);
									return (TRUE);}
"false"								{yylval.sval = strdup(yytext);
									return (FALSE);}

{DIGIT}  							{ yylval.ival = atoi(yytext);
	   								return DIGIT; }

{FLOAT}  							{ yylval.fval = atof(yytext);
	   								return FLOAT; }

{ID} 								{yylval.sval = strdup(yytext);return ID; }
{ARITHMETIC_OPERATORS}   			{c = yytext[0];return(c);}
{BITWISE_OPERATORS}					{c=yytext[0]; return (c);}
{OTHER_CHARACTERS}   				{c = yytext[0];return(c);}

%%