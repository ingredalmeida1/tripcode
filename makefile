compile:
	clear
	bison -d translate.y
	flex lex.l
	gcc translate.tab.c TAD/TabelaSimbolos.c TAD/InstrucaoTAC.c lex.yy.c -lfl

run_corretos:
	./a.out < exemplos/testes-yacc/corretos/basico.tc
	./a.out < exemplos/testes-yacc/corretos/condicional.tc
	./a.out < exemplos/testes-yacc/corretos/repeticao.tc
	./a.out < exemplos/testes-yacc/corretos/funcao.tc
	./a.out < exemplos/testes-yacc/corretos/escopos.tc

run_incorretos:
	./a.out < exemplos/testes-yacc/incorretos/basico.tc
	./a.out < exemplos/testes-yacc/incorretos/lexico.tc
	./a.out < exemplos/testes-yacc/incorretos/fechamento.tc
	./a.out < exemplos/testes-yacc/incorretos/declaracao.tc
	./a.out < exemplos/testes-yacc/incorretos/repeticao.tc
	./a.out < exemplos/testes-yacc/incorretos/funcao.tc

run_testes:
	./a.out < exemplos/testes-tac/basico.tc
