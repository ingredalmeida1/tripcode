compile:
	clear
	bison -d translate.y
	flex lex.l
	gcc translate.tab.c lex.yy.c -lfl