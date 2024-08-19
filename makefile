compile:
	clear
	bison -d translate.y
	flex lex.l
	gcc translate.tab.c TAD/TabelaSimbolos.c lex.yy.c -lfl

run:
	./a.out < exemplos/testes-yacc/corretos/basico.tc
	./a.out < exemplos/testes-yacc/corretos/condicional.tc
	./a.out < exemplos/testes-yacc/corretos/escopos.tc
	./a.out < exemplos/testes-yacc/corretos/funcao.tc
	./a.out < exemplos/testes-yacc/corretos/repeticao.tc

run2:
	./a.out < exemplos/testes-yacc/incorretos/basico.tc
	./a.out < exemplos/testes-yacc/incorretos/condicional.tc
	./a.out < exemplos/testes-yacc/incorretos/declaracao.tc
	./a.out < exemplos/testes-yacc/incorretos/fechamento.tc
	./a.out < exemplos/testes-yacc/incorretos/repeticao.tc