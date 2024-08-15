compile:
	clear
	bison -d translate.y
	flex lex.l
	gcc translate.tab.c TAD/tabela-simbolos/tabelaSimbolos.c lex.yy.c -lfl