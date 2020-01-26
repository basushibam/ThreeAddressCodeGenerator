# ThreeAddressCodeGenerator
A 3-Address Code Generator for a subset of C language


INTRODUCTION-
	Compiler is a program that reads a program written in one language, called source language, and translated it in to an equivalent program in another language, called target language. It reports errors detected during the translation of source code to target code. Source program can be of any programming language. Here our input is a sub-C program and output in Intermediate Code. The first phase of the compiler, Lexical Analyzer, is being implemented by using LEX tool provided with Linux. The second phase, Syntax Analyzer, is being implemented by using YACC tool provided by Linux. The third phase, Semantic Analyzer, and the fourth phase, Intermediate Code Generation, are carried out as the part of action corresponding to the production rules in the parser.

PROBLEM DESCRIPTION-
	A source code can directly be translated into its target machine code, then why at all we need to translate the source code into an intermediate code which is then translated to its target code? The benefits of using machine independent intermediate code are:
	If a compiler translates the source language to its target machine language without having the option for generating intermediate code, then for each new machine, a full native compiler is required.
	Intermediate code eliminates the need of a new full compiler for every unique machine by keeping the analysis portion same for all the compilers.
	The second part of compiler, synthesis, is changed according to the target machine.
	It becomes easier to apply the source code modifications to improve code performance by applying code optimization techniques on the intermediate code.
	Because of the machine independent intermediate code, portability will be enhanced.
While generating machine code directly from source code is possible, it entails two problems. With m languages and n target machines, we need to write m front ends, m × n optimizers, and m × n code generators. The code optimizer which is one of the largest and very-difficult-to-write components of a compiler, cannot be reused. By converting source code to an intermediate code, a machine-independent code optimizer may be written. This means just m front ends, n code generators and 1 optimizer.
 Intermediate code can be either language specific (e.g., Bytecode for Java) or language. independent (three-address code). Intermediate Code representation can be Postfix notation, Three-Address Code or the Syntax Tree. In this project the sub-C program is converted to the Three-Address Code form of Intermediate Code.
 
 
DECOMPOSITION-
	The task of 3-Address Code generation, which consists of both lexical analysis and syntax analysis, was broken down as follows-
1)	Decide how the input is given to the program and how the output will be displayed.
2)	Decide the format of the input.
3)	Decide what are the keywords that will be supported for the sub-C input program and what kind of data types of operands and operations can be used.
4)	Prepare a lexical specification that breaks down the input into tokens.
5)	After deciding the constructs that will be supported by the sub-C input program prepare the grammar rules.
6)	Write the semantic actions corresponding to each grammar rule, which generates the final 3-Address Code.
7)	Prepare documentation of the project.


APPROACH-
1)	The input is decided to be taken from file “input.txt” and the output is shown on the console.
2)	The sub-C language was defined with the following data-types, operators and constructs-
  a.	Data types: int, unsigned int, Boolean
  b.	Assignment operators:  =, +=, -=, *=, /=
  c.	Binary operators:  +, -, *, /, @(exponentiation)
  d.	Bitwise operators: |, &, ^
  e.	Logical operators: ||,&&
  f.	Relational operators: ==, !=, <, <=, >, >=
  g.	Conditional: if, if-else, switch
  h.	Repetitive:  while
  i.	Identifiers: simple identifiers with no special characters
3)	Lexical specification is prepared which includes the “y.tab.h” file.
4)	The data-structure for type of non-terminals like “expr”, “stat” is decided to be a structre containing two fields- 1) char* addr – for storing the name corresponding to that expression and 2) char* code- for storing the code corresponding to evaluation of that expression.   
5)	The precedence of different types of operators and also among operators of same type is noted along with its associativity. The exponentiation operator is denoted be “@” and bitwise XOR operation by “^”.
6)	The Yacc specification file is prepared and all the semantic actions are written. Some sequence of actions that are repeated in many semantic actions have been modularised into a function like the “replace()” and “newLabel()” in file “icg.y”. 


DESCRIPTION OF FUNCTIONAL UNITS-
1)	newTemp()-
Input-void
Output-a pointer to a new temporary variable never used before
Description- A global variable “n” is kept for storing the number to be given to the latest temporary variable like t1 or t4. So, whenever this function is called first the integer value of n is converted to a string in variable “num_to_concatenate”. This string is concatenated to “t” and returned.
Dependencies- The semantic actions for generating code for expressions calls this function whenever a sub-expression needs to be evaluated and value is to be stored in a temporary variable.

2)	newLabel()-
Input-void
Output-a pointer to a new label never used before
Description- A global variable “nl” is kept for storing the number to be given to the latest label like L1 or L15. So, whenever this function is called first the integer value of “nl” is converted to a string in variable “num_to_concatenate”. This string is concatenated to “L” and returned.
Dependencies- The semantic actions for if-else, switch and while construct use this function for generating labels to jump to on different conditions.

3)	replace()-
Input-char* s1, char* str, char* label
Output-void
Description-This function basically does backpatching. It replaces a substring str with another substring label in the original string s1. Whenever a code has a set of statements which jump to a particular statement when a condition is satisfied then this function is called for labelling. Suppose a block of statements have a some set of statements labelled as “jump TRUE” which jump to a particular statement when some condition is satisfied(also called “true-list”) and that target statement to be jumped to is written as “TRUE: a=a+b” then the replace function replaces “TRUE” with label “L1” so the block becomes “jump L1” and “L1: a=a+b”. 
Dependencies- The semantic actions for if-else, switch and while construct use this function when a label is required to jump to a statement immediately following the block. In such a case the substring “NEXT” is replaced with a string “L1”. 


SAMPLE INPUT AND OUTPUT-

Input 1:

int e=5;
int low=0;int high=n-1;
while(low<=high)
{
	int mid=(low+high)/2;
	if(a_mid==e) {p=q+r;}
	else
	{
		if(a_mid>e)
		{
			low = mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
}

Output 1:

----------  FINAL THREE ADDRESS CODE ----------
e=5
low=0
t3=n-1
high=t3
L8 : L7 : if(low<=high) jump L6   
 jump L9  
L6 : t5=low+high
t6=t5/2
mid=t6
L5 : if(a_mid==e) jump L3   
jump L4  
L3 : t8=q+r
p=t8
jump L7  
L4 : if(a_mid>e) jump L1   
jump L2  
L1 : t10=mid+1
low=t10
jump L7  
L2 : t12=mid-1
high=t12
jump L7
L9 : END OF THREE ADDRESS CODE !!!!!

##################################################################################

Input 2:

switch(a)
{
	case 0: {a=b+c;}
	case 1: {p=q+r;}
	default:
	{
		i=0;
		while(i<10){b=c+d*ul;}
	}
}

Output 2:

----------  FINAL THREE ADDRESS CODE ----------

if(a   =0) jump L6
jump L7
L6 : t1=b+c
a=t1
jump L8  
L7 : 
if(a   =1) jump L4
jump L5
L4 : t3=q+r
p=t3
jump L8  
L5 : i=0
L3 : L2 : if(i<10) jump L1   
jump L8  
L1 : t6=d*ul
t7=c+t6
b=t7
jump L2
L8 : END OF THREE ADDRESS CODE !!!!!
##################################################################################


MAJOR LIMITATIONS AND ASSUMPTIONS-
	The sub-C program only supports constructs like if-else, while and switch case. 
	It does not support functions or function calls.
	No symbol table has been prepared and all the variables are assumed to be declared by the user in its proper block.
	It is assumed that the user will operate on proper operands like only integer variables for bitwise operation, not character or float.
	Labels can be generated from L1 to L999 and it is assumed that this range will be enough to hold all the labels required for final output. 
	This project is only meant for Three-Address Code generation and not on the evaluation/execution of the input code snippet.
