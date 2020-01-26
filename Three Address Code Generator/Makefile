all :
	flex icg.l
	yacc -d icg.y -ll
	gcc lex.yy.c y.tab.c -o icg -ll