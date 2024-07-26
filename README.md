# Analisador Léxico da Linguagem Tripcode

Este projeto contém um analisador léxico para a linguagem Tripcode, desenvolvido com Flex e C.

## Pré-requisitos

- **Flex**: Um gerador de analisadores léxicos.
- **GCC**: Um compilador para a linguagem C.

## Estrutura do Projeto

- `tripcode-lex.l`: Arquivo de definições do analisador léxico.
- `entrada.txt`: Arquivos de entradas com os dados a serem analisados (*entrada.txt é apenas um exemplo*).

## Como Executar o Analisador Léxico

Siga as etapas abaixo para compilar e executar o analisador léxico:

1. **Abra um terminal.**
2. **Navegue até o diretório do projeto:**
   ```bash
   cd /caminho/para/o/seu/projeto
3. **Execute os seguintes comandos:**
   ```bash
   flex tripcode-lex.l
   gcc lex.yy.c
4. **Por fim, teste o analisador léxico com a entrada escrita em TripCode:**
   ```bash
   ./a.out < entrada.txt