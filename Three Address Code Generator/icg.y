%{
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct exprType{

	char *addr;
	char *code;
	
};
int n=1;	//Stores the number of the last temporary variable used
int nl = 1; //Stores the number of the last label used
char *var;char num_to_concatinate[10];char num_to_concatinate_l[10];char *ret;char *temp;
char *label;char *label2;char *check;char *begin;
char * b1;char *b2;char *s1;char *s2;
struct exprType *to_return_expr;	//To store the code and address corresponding to generation of expression and statements.
void yyerror(char* s);
int yylex(void);

//Function to generate new temporary variables
char * newTemp(){
	char *newTemp = (char *)malloc(20);
	strcpy(newTemp,"t");
	num_to_concatinate[0]=0;
	snprintf(num_to_concatinate, 10,"%d",n);
	strcat(newTemp,num_to_concatinate);
	n++;
	return newTemp;
}

//Function to generate new labels
char * newLabel(){
	char *newLabel = (char *)malloc(20);
	strcpy(newLabel,"L");
	snprintf(num_to_concatinate_l, 10,"%d",nl);
	strcat(newLabel,num_to_concatinate_l);
	nl++;
	return newLabel;
}

//Function to replace a substring str with another substring label in the original string s1
void replace(char* s1,char* str, char* label)
{
	char* check = strstr (s1,str);
			while(check!=NULL){
			strncpy (check,label,strlen(label));strncpy (check+strlen(label),"    ",(4-strlen(label)));
			check = strstr (s1,str);}
}
%}
%start startSym
%union {
	int ival;
	float fval;
	char *sval;
	struct exprType *EXPRTYPE;
}
%token<ival> DIGIT
%token<fval> FLOAT
%token<sval> ID IF ELSE WHILE TYPES  REL_OPT OR AND CASE SWITCH NOT PE ME INCR DEFAULT DECR TRUE FALSE BREAK FOR
%token<sval> '+' '-' '*' '/' '^' '%' '\n' '=' ';' '@' ':' '&' '|' 
%type<sval> list text number construct  block dec bool program startSym caseblock 
%type<EXPRTYPE> expr stat 
%left OR
%left AND
%left NOT
%left REL_OPT
%left '|' '&' '^'
%right '='
%left '+' '-'
%left '*' '/' '%'
%right '@'
%%
startSym:	program
		{
			s1 = $1;
			label = newLabel();
			replace(s1,"NEXT",label);
			ret = (char *)malloc(strlen(s1)+50);ret[0] = 0;
			strcat(ret,s1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : END OF THREE ADDRESS CODE !!!!!\n");
			printf("\n----------  FINAL THREE ADDRESS CODE ----------\n");
			puts(ret);
			$$ = ret;
		}
		;

program : 	program construct
		{
			s1 = $1;
			s2 = $2;
			label = newLabel();
			replace(s1,"NEXT",label);
			ret = (char *)malloc(strlen($1)+strlen($2)+4);
			ret[0] = 0;
			strcat(ret,$1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,$2);
			$$ = ret;
		}
		|
		construct
		{
			$$ = $1;
		}
		;

construct :     block
		{
			$$ = $1;
		}
		|
		WHILE '(' bool ')' block 
		{
			
			b1 = $3;
			s1 = $5;
			label = newLabel();
			replace(b1,"TRUE",label);
			replace(b1,"FAIL","NEXT");
			begin = newLabel();
			replace(s1,"NEXT",begin);
			ret = (char *)malloc(strlen(b1)+strlen(s1)+200);
			ret[0] = 0;
			strcat(ret,begin);strcat(ret," : ");strcat(ret,b1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,s1);
			strcat(ret,"\n");strcat(ret,"jump ");strcat(ret,begin);
			$$ = ret;
	
		}
		|
		IF '(' bool ')' block
		{
			label = newLabel();
			b1 = $3;
			replace(b1,"TRUE",label);
			replace(b1,"FAIL","NEXT");
			check = strstr (b1,"FAIL");
			ret = (char *)malloc(strlen(b1)+strlen($5)+4);
			ret[0] = 0;
			strcat(ret,b1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,$5);printf("Printing ret \n");
			$$ = ret;
		}
		
		|
		IF '(' bool ')' block ELSE block
		{
			b1 = $3;
			label = newLabel();
			replace(b1,"TRUE",label);
			label2 = newLabel();
			replace(b1,"FAIL",label2);
			ret = (char *)malloc(strlen(b1)+strlen($5)+strlen($7)+20);
			ret[0] = 0;
			strcat(ret,b1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,$5);strcat(ret,"\n");strcat(ret,"jump NEXT");strcat(ret,"\n");
			strcat(ret,label2);strcat(ret," : ");strcat(ret,$7);
			$$ = ret;
		}
		|
		SWITCH '(' ID ')' '{' caseblock '}'
		{
			char *var = $3;
			b1 = $6;
			replace(b1,"VARI",var);
			s1 = $6;
			label = "NEXT";	
			replace(s1,"LAST","NEXT");
			ret = (char*)malloc(strlen($6)+100);
			ret[0]=0;
			strcat(ret,$6);
				
			$$ = ret;
		}
		;

caseblock	:  CASE expr ':' block caseblock
			{
				label=newLabel(); label2 = newLabel();
				ret = (char*)malloc(strlen($5)+100); 
				memset(ret,0,sizeof ret); 
				strcat(ret,$2->code);strcat(ret,"\nif(VARI=");
				strcat(ret,$2->addr); strcat(ret,") "); strcat(ret,"jump ");strcat(ret,label); strcat(ret,"\n"); strcat(ret,"jump "); strcat(ret,label2);
				strcat(ret,"\n"); strcat(ret,label); strcat(ret," : "); strcat(ret,$4); strcat(ret,"\n"); strcat(ret,"jump NEXT"); strcat(ret,"\n");strcat(ret,label2); strcat(ret," : "); strcat(ret,$5); 
				$$=ret;
			}
			|
			CASE expr  ':' block
			{
				
				label=newLabel(); label2 = newLabel();
				ret = (char*)malloc(500*sizeof(char)); 
				memset(ret,0,sizeof ret); 
				strcat(ret,$2->code);strcat(ret,"\nif(VARI=");strcat(ret,$2->addr); strcat(ret,") "); strcat(ret,"jump ");strcat(ret,label); strcat(ret,"\n"); strcat(ret,"jump LAST"); 
				strcat(ret,"\n"); strcat(ret,label); strcat(ret," : "); strcat(ret,$4); 
				$$=ret;
			}
			|
			DEFAULT ':' block
			{
				ret = (char*)malloc(500*sizeof(char));  memset(ret,0,sizeof(ret)); ret[0]=0;
				strcat(ret,$3);
				$$=ret;
			}
			;

block:		'{' list '}'
		{
			$$ = $2;
		}
		
		|
		'{' program '}'
		{
			$$ = $2;
		}
		|
		 list 
		{
			$$ = $1;
		}
		
		;
	 

list:    stat               /* Base Condition */
		{
			$$ = $1->code;
		}
         |
        list stat
		{
			ret = (char *)malloc(strlen($1)+strlen($2->code)+4);
			ret[0] = 0;
			strcat(ret,$1);strcat(ret,"\n");strcat(ret,$2->code);
			$$ = ret;
		}
	 |
        list error '\n'
         {
           yyerrok;
         }
         ;


stat:    ';'
	 {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = $1;
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		$$ = to_return_expr;
	 }
	 |
	 dec ';'
         {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = $1;
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		$$ = to_return_expr;
         }
         |

		text INCR
		{
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,to_return_expr->addr);
			strcat(ret,"=");strcat(ret,$1);strcat(ret,"\n"); strcat(ret,$1); strcat(ret,"=");strcat(ret,$1);strcat(ret,"+1");
			temp = (char *)malloc(strlen(ret)+20);temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			$$ = to_return_expr;

		}
		|
		text DECR
		{
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,$1);strcat(ret,"\n"); strcat(ret,$1); strcat(ret,"=");strcat(ret,$1);strcat(ret,"-1");
			temp = (char *)malloc(strlen(ret)+20);temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			$$ = to_return_expr;

		}
		|
		INCR text

		{
			
	        to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,$2);strcat(ret,"=");strcat(ret,$2);strcat(ret,"+1");strcat(ret,"\n");strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,$2);
			temp = (char *)malloc(strlen(ret)+20);
			temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			$$ = to_return_expr;

		}
		|
		DECR text

		{
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,$2);
			strcat(ret,"=");
			strcat(ret,$2);strcat(ret,"-1");strcat(ret,"\n");
			strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,$2);
			temp = (char *)malloc(strlen(ret)+20);temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			$$ = to_return_expr;

		}
		|
         text '=' expr ';'
         {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		ret = (char *)malloc(20);
		ret[0] = 0;
		strcat(ret,$1);strcat(ret,"=");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($3->code)+strlen(ret)+60);
		temp[0] = 0;
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		$$ = to_return_expr;
           }
         |
         text PE expr ';'
         {
	        to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(200);
			ret[0] = 0;
			strcat(ret,$1);
			strcat(ret,"="); strcat(ret,$1);strcat(ret,"+"); strcat(ret,$3->addr); strcat(ret,"\n");
			strcat(ret,to_return_expr->addr); strcat(ret,"=");strcat(ret,$1);
			temp = (char *)malloc(strlen($3->code)+strlen(ret)+60);

			temp[0] = 0;
			
			if ($3->code[0]!=0){
				strcat(temp,$3->code);
				strcat(temp,"\n");
				}
			strcat(temp,ret);
			to_return_expr->code = temp;
			$$ = to_return_expr;

         }
         |
         text ME expr ';'
         {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,$1);strcat(ret,"="); strcat(ret,$1);strcat(ret,"-"); strcat(ret,$3->addr);strcat(ret,"\n");strcat(ret,to_return_expr->addr); strcat(ret,"=");strcat(ret,$1);
			temp = (char *)malloc(strlen($3->code)+strlen(ret)+6);

			temp[0] = 0;
			
			if ($3->code[0]!=0){
				strcat(temp,$3->code);
				strcat(temp,"\n");
				}
			strcat(temp,ret);
			to_return_expr->code = temp;
			$$ = to_return_expr;

         }
	 |
	 dec '=' expr ';'
         {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		ret = (char *)malloc(200);
		ret[0] = 0;
		strcat(ret,$1);strcat(ret,"=");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		$$ = to_return_expr;
        }
        ;

dec : 		TYPES text 
		{	
			$$ = $2;
		}
		;

bool : 	 	expr REL_OPT expr
		{
			temp = (char *)malloc(strlen($1->code)+strlen($3->code)+50);
			temp[0] = 0;
			if($1->code[0]!=0){
				strcat(temp,$1->code);strcat(temp,"\n");
				}
			if($3->code[0]!=0){
				strcat(temp,$3->code);
				strcat(temp,"\n");
				}
			ret = (char *)malloc(50);
			ret[0] = 0;
			strcat(ret,"if(");strcat(ret,$1->addr);strcat(ret,$2);strcat(ret,$3->addr);strcat(ret,") jump TRUE \n jump FAIL");
			strcat(temp,ret);
			$$ = temp;
		}
		|
		bool OR bool
		{
			b1 = $1;
			b2 = $3;
			label = newLabel();
			replace(b1,"FAIL",label);
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;
			strcat(temp,b1);strcat(temp,"\n");strcat(temp,label);strcat(temp," : ");strcat(temp,b2);

			$$ = temp;
		}
		|
		bool AND bool
		{
			b1 = $1;
			b2 = $3;
			label = newLabel();
			replace(b1,"TRUE",label);
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;
			strcat(temp,b1);strcat(temp,"\n");strcat(temp,label);strcat(temp," : ");strcat(temp,b2);
			$$ = temp;
		}
		|
		NOT '(' bool ')'
		{	b1 = $3;
			label = "TEFS";
			replace(b1,"TRUE","TEFS");
			label = "TRUE";
			replace(b1,"FAIL",label);
			label = "FAIL";
			replace(b1,"TEFS","FAIL");
			$$ = b1;
		}
		|
		'(' bool ')'
		{
			$$ = $2;
		}
		|
		TRUE
		{
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\njump TRUE");
			
			$$ = ret;
		}
		|
		FALSE
		{
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\njump FAIL");
			$$ = ret;
		}
		;

expr:    '(' expr ')'
         {
           $$ = $2;
         }
         |
	 expr '@' expr
         {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"@");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+60);
		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;

           	$$ = to_return_expr;
	
         }
	 |
         expr '*' expr
         {
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"*");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+60);
		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		$$ = to_return_expr;
        }
         |
         expr '/' expr
         {
         to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"/");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+60);
		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		 	$$ = to_return_expr;
	   }
         |
         expr '%' expr
         {
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"%");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);
		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		$$ = to_return_expr;
         }
         |
         expr '+' expr
         {
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"+");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+60);temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		$$ = to_return_expr;
         }
         |
         expr '-' expr
         {
	   
        to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"-");strcat(ret,$3->addr);
		
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+60);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		
		to_return_expr->code = temp;

           	$$ = to_return_expr;
		
         }
         |
         expr '|' expr 
         {
         	printf("BITWISE OR : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"|");strcat(ret,$3->addr);
		
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	$$ = to_return_expr;
         }
         |
         expr '&' expr
         {
         to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;
		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"&");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);
		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		$$ = to_return_expr;
         }
         |
         expr '^' expr 
         {
         to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;
		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,$1->addr);strcat(ret,"^");strcat(ret,$3->addr);
		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);
		temp[0] = 0;
		if ($1->code[0]!=0){
			strcat(temp,$1->code);strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		$$ = to_return_expr;
         }
         |
	 text {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = $1;

		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;

		$$ = to_return_expr;}
         |


         number 
         {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = $1;
			
			to_return_expr->code = (char *)malloc(2);
			to_return_expr->code[0] = 0;
			
			$$ = to_return_expr;
		}
		|
		'-' number
		{
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			label = newTemp();
			to_return_expr->addr = label;
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,label);strcat(ret,"=-");strcat(ret,$2);
			to_return_expr->code=ret;
			$$ = to_return_expr;
		}
		;
text: 	ID
         {
			$$ = $1;
         }
	  ;

number:  DIGIT
         {
			var = (char *)malloc(20);
	        snprintf(var, 10,"%d",$1);
			$$ = var;
         } 
	 |
         FLOAT
         {
		
			var = (char *)malloc(20);
	        snprintf(var, 10,"%f",$1);
			$$ = var;
           
         } 
	;
	
%%


extern int yyparse();
extern FILE *yyin;

int main() {
	// open a file handle to a particular file:
	FILE *myfile = fopen("input.txt", "r");
	// make sure it is valid:
	if (!myfile) {
		printf("I can't open a.snazzle.file!");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}
void yyerror(char *s) {
	printf("Parsing error.  Message: %s ",s);
	exit(-1);
}