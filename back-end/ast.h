#include <iostream>
#include "codegen.h"
#include "node.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>


using namespace std;

extern int yyparse();
extern NBlock *programBlock;

void open_file(const char *filename);

void createCoreFunctions(CodeGenContext &context);

void generateGraph(const NBlock &block, const std::string &nodeName);

void *nStatementAST(std::ofstream &file, const NStatement &statement);

void* nBlockAST(std::ofstream &file, const NBlock &block, const std::string &nodeName);

void* nExpressionAST(std::ofstream &file, const NExpression &expression);

void NBagagemAST(std::ofstream &file, const NBagagem &var);

