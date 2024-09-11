compile:
	clear
	bison -d translate.y
	flex lex.l
	gcc translate.tab.c TAD/TabelaSimbolos.c TAD/InstrucaoTAC.c lex.yy.c -lfl

run_corretos:
	./a.out < exemplos/testes-semantica/corretos/exemplo1.tc
	./a.out < exemplos/testes-semantica/corretos/exemplo2.tc

run_incorretos:
	./a.out < exemplos/testes-semantica/incorretos/lexico.tc
	./a.out < exemplos/testes-semantica/incorretos/sintatico.tc
	./a.out < exemplos/testes-semantica/incorretos/semantico-identificadorIndisponivel.tc
	./a.out < exemplos/testes-semantica/incorretos/semantico-atribuicaoConstante.tc
	./a.out < exemplos/testes-semantica/incorretos/semantico-inicializada.tc
	./a.out < exemplos/testes-semantica/incorretos/semantico-operandos.tc
	./a.out < exemplos/testes-semantica/incorretos/semantico-qtdParametros.tc
	./a.out < exemplos/testes-semantica/incorretos/semantico-tiposParametros.tc

run_tac:
	./a.out < exemplos/testes-tac/basico.tc
