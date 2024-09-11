#include <iostream>
#include <vector>
/* lib da llvm para gerar representações intermediárias, precisa adicionar o path dela em C/C++: Edit Configurations (UI) */
#include <llvm/IR/Value.h>

class CodeGenContext;
class NStatement;
class NExpression;
class NBagagem;

typedef std::vector<NStatement *> StatementList;
typedef std::vector<NExpression *> ExpressionList;
typedef std::vector<NBagagem *> VariableList;

/* classe base para todos os tipos de nós da AST */
class Node
{
public:
    virtual ~Node() {}
    virtual llvm::Value *codeGen(CodeGenContext &context) { return NULL; } // depois eu faço o corpo da codeGen para cada caso
};


class NExpression : public Node
{
};

class NStatement : public Node
{
};

/* 
    abaixo estão as classes que representam tipos específicos de expressões na AST
    são usadas para representar diferentes tipos de valores que podem ser encontrados
*/

class NMilhas : public NExpression
{
public:
    long long value;
    NMilhas(long long value) : value(value) {} // inicializa o valor do int no llvm com o valor declarado no código
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NDolar : public NExpression
{
public:
    double value;
    NDolar(double value) : value(value) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NVoucher : public NExpression
{
public:
    std::string value;
    NVoucher(std::string value) : value(value) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NId : public NExpression
{
public:
    std::string name;
    NId(const std::string &name) : name(name) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

/* classe usada para expressar operações binárias, como adição, etc. */
class NBinaryOperator : public NExpression
{
public:
    std::string op; // o opperador
    NExpression &lhs; // operando da esquerda
    NExpression &rhs; // operador da direita
    NBinaryOperator(NExpression &lhs, std::string op, NExpression &rhs) : lhs(lhs), rhs(rhs), op(op) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

/* representa uma atribuição em uma expressão */
class NAssignment : public NExpression
{
public:
    NId &lhs; // id a esquerda
    NExpression &rhs; // expr a direita
    NAssignment(NId &lhs, NExpression &rhs) : lhs(lhs), rhs(rhs) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

/* representa um bloco de codigo que pode ter expr ou stmts agrupadas */
class NBlock : public NExpression
{
public:
    StatementList statements;
    NBlock() {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

/* representa uma expressão */
class NExpressionStatement : public NStatement
{
public:
    NExpression &expression;
    NExpressionStatement(NExpression &expression) : expression(expression) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

/* representa a declaração de uma var */
class NBagagem : public NStatement
{
public:
    const NId &type; // tipo da var
    NId &id; // nome da var
    NExpression *assignmentExpr; // expr que ta sendo atribuida

    // variavel sem valor inicial
    NBagagem(NId &type, NId &id) : type(type), id(id) { assignmentExpr = NULL; }

    // variavel com expr atribuida
    NBagagem(const NId &type, NId &id, NExpression *assignmentExpr) : type(type), id(id), assignmentExpr(assignmentExpr) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NCheckout : public NExpression
{
public:
    ExpressionList arguments;
    std::string format;
    NCheckout(ExpressionList &arguments, std::string format) : arguments(arguments), format(format) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

std::string nodeTypeToString(Node *node);

class NAlfandega : public NStatement
{
public:
    NExpression &condition;
    NBlock &ifBlock;
    NBlock *elseBlock;

    NAlfandega(NExpression &condition, NBlock &ifBlock, NBlock *elseBlock = nullptr)
        : condition(condition), ifBlock(ifBlock), elseBlock(elseBlock) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};