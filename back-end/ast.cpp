#include "ast.h"

void open_file(const char *filename)
{
    freopen(filename, "r", stdin);
}

void addLabel(std::ofstream &file, const std::string &label, void *node)
{
    file << "node" << node << " [label=\"" << label << "\"];" << std::endl;
}

void addEdge(std::ofstream &file, void *node1, void *node2)
{
    file << "node" << node1 << " -> "
         << "node" << node2 << ";" << std::endl;
}

void *nExpressionAST(std::ofstream &file, const NExpression &expression)
{
    int *i = new int;

    NMilhas *integer = dynamic_cast<NMilhas *>(const_cast<NExpression *>(&expression));
    if (integer)
    {
        addLabel(file, std::to_string(integer->value), (void *)&expression);
        return (void *)&expression;
    }

    NDolar *doubl = dynamic_cast<NDolar *>(const_cast<NExpression *>(&expression));
    if (doubl)
    {
        addLabel(file, std::to_string(doubl->value), (void *)&expression);
        return (void *)&expression;
    }

    NVoucher *string = dynamic_cast<NVoucher *>(const_cast<NExpression *>(&expression));
    if (string)
    {
        addLabel(file, string->value, (void *)&expression);
        return (void *)&expression;
    }

    NId *identifier = dynamic_cast<NId *>(const_cast<NExpression *>(&expression));
    if (identifier)
    {
        addLabel(file, identifier->name, (void *)&expression);
        return (void *)&expression;
    }

    NCheckout *print = dynamic_cast<NCheckout *>(const_cast<NExpression *>(&expression));
    if (print)
    {
        addLabel(file, "CHECKOUT", (void *)&expression);
        for (auto &argument : print->arguments)
        {
            void *expr = nExpressionAST(file, *argument);
            addLabel(file, nodeTypeToString(argument), expr);
            addEdge(file, (void *)&expression, expr);
        }
        return (void *)&expression;
    }

    NBinaryOperator *binaryOperator = dynamic_cast<NBinaryOperator *>(const_cast<NExpression *>(&expression));
    if (binaryOperator)
    {
        addLabel(file, binaryOperator->op, (void *)&expression);
        addEdge(file, (void *)&expression, (void *)&binaryOperator->lhs);
        addEdge(file, (void *)&expression, (void *)&binaryOperator->rhs);
        nExpressionAST(file, binaryOperator->lhs);
        nExpressionAST(file, binaryOperator->rhs);
        return (void *)&expression;
    }

    NAssignment *assignment = dynamic_cast<NAssignment *>(const_cast<NExpression *>(&expression));
    if (assignment)
    {
        addLabel(file, "ATRIBUIÇÃO", (void *)&expression);
        void *lhs = nExpressionAST(file, assignment->lhs);
        void *rhs = nExpressionAST(file, assignment->rhs);
        addEdge(file, (void *)&expression, lhs);
        addEdge(file, (void *)&expression, rhs);
        return (void *)&expression;
    }

    return (void *)&expression;
}

void NBagagemAST(std::ofstream &file, const NBagagem &var)
{
    addLabel(file, "BAGAGEM", (void *)&var);
    addLabel(file, var.type.name, (void *)&var.type);
    addLabel(file, var.id.name, (void *)&var.id);

    addEdge(file, (void *)&var, (void *)&var.type);
    addEdge(file, (void *)&var, (void *)&var.id);

    if (var.assignmentExpr)
    {
        void *expr = nExpressionAST(file, *var.assignmentExpr);
        addLabel(file, nodeTypeToString(var.assignmentExpr), expr);
        addEdge(file, (void *)&var, expr);
    }
}

void *nStatementAST(std::ofstream &file, const NStatement &statement)
{
    int *i = new int;

    NExpressionStatement *expr = dynamic_cast<NExpressionStatement *>(const_cast<NStatement *>(&statement));
    if (expr)
    {
        return nExpressionAST(file, expr->expression);
    }

    NBagagem *var = dynamic_cast<NBagagem *>(const_cast<NStatement *>(&statement));
    if (var)
    {
        NBagagemAST(file, *var);
    }

    NAlfandega *ifStatement = dynamic_cast<NAlfandega *>(const_cast<NStatement *>(&statement));
    if (ifStatement)
    {
        addLabel(file, "ALFÂNDEGA", (void *)&statement);
        void *expr = nExpressionAST(file, ifStatement->condition);
        void *then = nBlockAST(file, ifStatement->ifBlock, "ANALISANDO");
        addEdge(file, (void *)&statement, expr);
        addEdge(file, (void *)&statement, then);

        if (ifStatement->elseBlock != nullptr)
        {
            void *elseBlock = nBlockAST(file, *ifStatement->elseBlock, "ISENTO");
            addEdge(file, (void *)&statement, elseBlock);
        }
    }

    return (void *)&statement;
}

void *nBlockAST(std::ofstream &file, const NBlock &block, const std::string &nodeName)
{
    addLabel(file, nodeName, (void *)&block);
    for (const auto &statement : block.statements)
    {
        if (statement == nullptr)
            continue;
        void *child = nStatementAST(file, *statement);
        addEdge(file, (void *)&block, child);
    }
    return (void *)&block;
}

void generateGraph(const NBlock &block, const std::string &nodeName)
{
    std::ofstream file(nodeName + ".dot");
    file << "digraph {" << std::endl;

    nBlockAST(file, block, "your-trip");

    file << "}" << std::endl;
    file.close();

    std::cout << "Arquivo '" << nodeName << ".dot' gerado com sucesso!" << std::endl;
}
