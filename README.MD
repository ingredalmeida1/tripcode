# Compilador da Linguagem Tripcode

![Logo da Linguagem Tripcode](images/logo-tripcode.png) 

Este projeto contém um compilador para a linguagem Tripcode, desenvolvido com Flex, Bison e C. O compilador é projetado para analisar toda a gramática proposta e executar um subconjunto da linguagem Tripcode, focando em condicionais, expressões aritméticas, e manipulação de variáveis. 

## Sobre a origem do nome
O nome TripCode reflete tanto o propósito quanto o contexto temático da linguagem. Ele é uma combinação dos termos distintos:

- Trip: faz referência ao contexto temático da linguagem, que é o setor de viagens.
- Code: sublinha a função principal da linguagem de programação, que é permitir a
criação de códigos.

Além disso, a letra C faz uma referência implícita à linguagem C, linguagem na qual TripCode foi inspirada.

## Fases de Implementação

O desenvolvimento do compilador foi dividido em quatro fases principais:

1. **Definição da Linguagem**
   - Descrição e especificação da sintaxe e semântica da linguagem Tripcode.

2. **Análise Léxica**
   - Implementação do analisador léxico utilizando Flex para identificar tokens da linguagem.

3. **Análise Sintática**
   - Implementação do analisador sintático utilizando Bison para verificar a estrutura gramatical do código Tripcode.

4. **Análise Semântica**
   - Verificação de consistência semântica e análise de tipos.

5. **Geração de Código Intermediário e Executável**
   - Transformação do código Tripcode em código intermediário e, posteriormente, em código executável utilizando LLVM.

### Observações

Nem todas as estruturas da linguagem Tripcode estão sendo consideradas para o executável com LLVM. O compilador atualmente suporta apenas:

- Condicionais
- Expressões aritméticas e condicionais
- Declaração e manipulação de variáveis

Outras construções da linguagem não estão implementadas na versão atual do compilador e estão propostas como trabalhos futuros.

## Como Executar

Para facilitar o processo de compilação e execução da linguagem, foram criados arquivos Makefile. O projeto é dividido em duas partes e, por isso, foi organizado em duas pastas:

- A pasta `/front-end-compiler` é responsável pela análise semântica e geração de código de três endereços.
- A pasta `/llvm` se encarrega da geração da árvore sintática abstrata, da representação intermediária da LLVM a partir dessa árvore, e da geração de código objeto.

Devido a essa divisão, dois Makefiles foram criados, um para cada parte do projeto, e estão localizados nas respectivas pastas.

## Documentações
Os documentos da documentação de cada fase de implementação do compilador estão disponíveis na pasta `docs`.  

## Colaboradoras
Este trabalho foi desenvolvido e implementado por:

- [Aymê Faustino](https://github.com/aymesantos)
- [Emily Lopes](https://github.com/Emily-Lopes)
- [Ingred Almeida](https://github.com/ingredalmeida1)
- [Letícia Silva](https://github.com/lleticiasilvaa)