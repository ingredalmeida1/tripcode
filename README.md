# Analisador Léxico da Linguagem Tripcode

Este projeto contém um compilador para a linguagem Tripcode, desenvolvido com Flex, Bison e C. Até o momento temos o analisador léxico e o analisador sintático desenvolvidos, o restante do compilador ainda está em produção.

## Pré-requisitos

- **Flex**: Um gerador de analisadores léxicos.
- **Bison**: Um gerador de analisadores sintáticos.
- **GCC**: Um compilador para a linguagem C.

## Estrutura do Projeto

- `lex.l`: Arquivo de definições do analisador léxico.
- `translate.y`: Arquivode regras e ações do analisador sintático.
- `TAD`: Diretório com os Tipos de Dados Abstratos utilizados no compilador.
- `testes-flex e testes-yacc`: Diretório com os códigos de teste para avaliar o compilador.

## Como Executar o Analisador Léxico

Siga as etapas abaixo para compilar e executar o compilador:

1. **Abra um terminal.**

2. **Navegue até o diretório do projeto:**
   ```bash
   cd /caminho/para/o/seu/projeto

4. **Instale o Bison, caso ainda não tenha:**
   ```bash
   sudo apt install bison

5. **Execute os seguintes comandos:**
   ```bash
   yacc -d translate.y
   flex lex.l
   gcc y.tab.c lex.yy.c -lfl
   
6. **Por fim, teste o analisador léxico com a entrada escrita em TripCode:**
   ```bash
   ./a.out < <seu_arquivo_de_teste>.tc