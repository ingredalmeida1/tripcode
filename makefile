compile:
	clear
	bison -d translate.y
	flex lex.l
	gcc translate.tab.c TAD/TabelaSimbolos.c lex.yy.c -lfl