#include <stack>
#include <typeinfo>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include "llvm/Pass.h"
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Bitstream/BitstreamReader.h>
#include <llvm/Bitstream/BitstreamWriter.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

class NBlock;

/*  */
static LLVMContext MyContext;
static IRBuilder<> Builder(MyContext);

class CodeGenBlock {
public:
    BasicBlock *block; // bloco atual
    Value *returnValue; 
    std::map<std::string, Value*> locals; // variaveis locais desse bloco
};

class CodeGenContext {
    Function *mainFunction; // função principal, no nosso caso 'trip'
    std::stack<Function *> functions; // funções da main (ainda nao estamos usando)

public:

    std::stack<CodeGenBlock *> blocks; // blocos da main
    Module *module;

    CodeGenContext() { module = new Module("main", MyContext); } 
    
    void generateCode(NBlock& root); // gera os nós a partir da main

    GenericValue BuildCode(); // constroi e retorna o code

    // retorna as vars locais do bloco
    std::map<std::string, Value*>& locals() { return blocks.top()->locals; }

    // retorna o bloco basico atual
    BasicBlock *currentBlock() { return blocks.top()->block; }

    // adicionar um novo bloco basico
    void pushBlock(BasicBlock *block) { blocks.push(new CodeGenBlock()); blocks.top()->returnValue = NULL; blocks.top()->block = block; }
    
    // remove um bloco basico
    void popBlock() { CodeGenBlock *top = blocks.top(); blocks.pop(); delete top; }
    
    // define o valor de retorno do bloco
    void setCurrentReturnValue(Value *value) { blocks.top()->returnValue = value; }
   
    // adiciona uma funcao (ainda nao usamos)
    void pushFunction(Function *function) { functions.push(function); }
    
    // otimizacao: remover blocos inatingiveis
    void RemoveUnreachableBlocks(){ while(functions.size() > 0){ Function *function = functions.top(); functions.pop(); EliminateUnreachableBlocks(*function); } }
    
    // get do valor que o bloco retorna
    Value* getCurrentReturnValue() { return blocks.top()->returnValue; }
};