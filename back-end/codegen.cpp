#include "node.h"
#include "codegen.h"
#include "parser.hpp"
#include <fstream>
#include <fcntl.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/raw_ostream.h>

using namespace std;
extern int yylineno;

/* gera o code llvm e salva em um arquivo */
void CodeGenContext::generateCode(NBlock &root)
{
    vector<Type *> argTypes;
    FunctionType *ftype = FunctionType::get(Type::getInt64Ty(MyContext), makeArrayRef(argTypes), false);
    mainFunction = Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module);
        BasicBlock *bblock = BasicBlock::Create(MyContext, "entry", mainFunction, 0);

    // aramazena a função e o bloco no contexto atual (contexto é como se fosse o escopo, onde tem as vars, funcs daquele bloco e taks)
    pushFunction(mainFunction);
    pushBlock(bblock);

    // chama codeGen a partir da raiz
    root.codeGen(*this);
    printf("Gerando código para...\n");

    // se não tem um valor específico de retorno, deixa 0 como padrão (o nosso padrão é 0)
    if (!getCurrentReturnValue())
    {
        Builder.SetInsertPoint(currentBlock());
        Builder.CreateRet(llvm::ConstantInt::get(Builder.getInt64Ty(), 0));
    }

    std::cout << "Código gerado.\n";

    // otimizaocao: remover blocos inalcançaveis
    RemoveUnreachableBlocks();
    legacy::PassManager pm;

    // escreve a saída no arquivo
    int fd = open("output.ll", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd != -1)
    {
        llvm::raw_fd_ostream output(fd, true, false);
        module->print(output, nullptr);
        output.flush();
        output.close();
        std::cout << "\033[1;32mCódigo gerado e escrito no arquivo output.ll\033[0m\n";
    }
    else
    {
        printf("Não foi possível gerar o arquivo output.ll");
    }
}

/* prepara o code para execução */
GenericValue CodeGenContext::BuildCode()
{
    ExecutionEngine *ee = EngineBuilder(unique_ptr<Module>(module)).create();
    ee->finalizeObject();
    return GenericValue();
}

/* busca o id/var dentro do contexto */
Value *getIdentifier(CodeGenContext &context, std::string name)
{
    std::stack<CodeGenBlock *> blocks = context.blocks;

    while (blocks.size() > 0)
    {
        CodeGenBlock *block = blocks.top(); // cada bloco tem suas vars locais
        blocks.pop();
        if (block->locals.find(name) != block->locals.end())
        {
            return block->locals[name];
        }
    }
    printf("Variável '%s' não declarada!", &name);
    return NULL;
}

/* função que descreve o node como uma string (melhor pra visualizar) */
std::string nodeTypeToString(Node *node)
{   
    // por exemplo, se o node é int então retorna um str(valor_do_node_int)
    NMilhas *integer = dynamic_cast<NMilhas *>(node);
    if (integer)
    {
        return std::to_string(integer->value);
    }
    NDolar *doubl = dynamic_cast<NDolar *>(node);
    if (doubl)
    {
        return std::to_string(doubl->value);
    }
    NVoucher *string = dynamic_cast<NVoucher *>(node);
    if (string)
    {
        return string->value;
    }
    NId *identifier = dynamic_cast<NId *>(node);
    if (identifier)
    {
        return identifier->name;
    }
    NBinaryOperator *binaryOperator = dynamic_cast<NBinaryOperator *>(node);
    if (binaryOperator)
    {
        return binaryOperator->op;
    }
    NExpressionStatement *expressionStatement = dynamic_cast<NExpressionStatement *>(node);
    if (expressionStatement)
    {
        return "NExpressionStatement";
    }
    NAssignment *assignment = dynamic_cast<NAssignment *>(node);
    if (assignment)
    {
        return "NAssignment";
    }
    NBlock *block = dynamic_cast<NBlock *>(node);
    if (block)
    {
        return "NBlock";
    }
    NStatement *statement = dynamic_cast<NStatement *>(node);
    if (statement)
    {
        return "NStatement";
    }

    return "unknown";
}

/* gerando codigo para o node de tipo inteiro */
Value *NMilhas::codeGen(CodeGenContext &context)
{
    std::cout << "Criando inteiro: " << value << endl;

    // cria uma constante no llvm dentro contexto atual e com o valor do node
    return ConstantInt::get(Type::getInt64Ty(MyContext), value, true);
}

/* gerando codigo para o node de tipo float */
Value *NDolar::codeGen(CodeGenContext &context)
{
    std::cout << "Craindo float: " << value << endl;
    return ConstantFP::get(Type::getDoubleTy(MyContext), value);
}

/* gerando codigo para o node de tipo string */
Value *NVoucher::codeGen(CodeGenContext &context)
{
    // cria uma str llvm a partir do valor da str armazenada no nó
    llvm::Constant *stringConstant = llvm::ConstantDataArray::getString(MyContext, value);

    // cria uma var global pra armazenar o valor da str no modulo llvm atual
    llvm::GlobalVariable *globalString = new llvm::GlobalVariable(
        *context.module,
        stringConstant->getType(),
        true, // so acessada dentro do modulo
        llvm::GlobalValue::PrivateLinkage,
        stringConstant,
        "my_string");

    // ponteiro para essa str
    llvm::Value *stringPtr = Builder.CreateBitCast(
        globalString,
        llvm::PointerType::get(llvm::Type::getInt8Ty(MyContext), 0));

    return stringPtr;
}

/* gerando codigo para o node de id */
Value *NId::codeGen(CodeGenContext &context)
{
    std::cout << "Criando referência para o identificador: " << name << endl;
    std::stack<CodeGenBlock *> blocks = context.blocks;

    while (blocks.size() > 0)
    {
        CodeGenBlock *block = blocks.top();
        blocks.pop();
        if (block->locals.find(name) != block->locals.end())
        {
            Type *type = block->locals[name]->getType();
            if (type->getTypeID() == llvm::Type::PointerTyID)
            {
                llvm::PointerType *pointerType = llvm::cast<llvm::PointerType>(type);
                type = pointerType->getPointerElementType();
            }
            return new LoadInst(type, block->locals[name], name, false, context.currentBlock());
        }
    }

    printf("Variável usada antes de sua declaração: %s", &name);
    return NULL;
}

/* gerando codigo para o node de expr binaria */
Value *NBinaryOperator::codeGen(CodeGenContext &context)
{
    std::cout << "Criando operação binária de " << op << std::endl;

    // armazena o tipo de expr e o predicado (em caso de relop)
    Instruction::BinaryOps instr;
    CmpInst::Predicate pred;

    Value *lhsValue = lhs.codeGen(context);
    Value *rhsValue = rhs.codeGen(context);

    if (op == "+")
    {
        instr = Instruction::Add;
        goto math;
    }
    if (op == "-")
    {
        instr = Instruction::Sub;
        goto math;
    }
    if (op == "*")
    {
        instr = Instruction::Mul;
        goto math;
    }
    if (op == "/")
    {
        instr = Instruction::SDiv;
        goto math;
    }
    if (op == "/")
    {
        instr = Instruction::SDiv;
        goto math;
    }
    if (op == "=")
    {
        pred = CmpInst::ICMP_EQ;
        goto comparison;
    }
    if (op == "#")
    {
        pred = CmpInst::ICMP_NE;
        goto comparison;
    }
    if (op == ">")
    {
        pred = CmpInst::ICMP_SGT;
        goto comparison;
    }
    if (op == ">=")
    {
        pred = CmpInst::ICMP_SGE;
        goto comparison;
    }
    if (op == "<")
    {
        pred = CmpInst::ICMP_SLT;
        goto comparison;
    }
    if (op == "<=")
    {
        pred = CmpInst::ICMP_SLE;
        goto comparison;
    }

    // operador não existe na linguagem
    return nullptr;

math:
    return BinaryOperator::Create(instr, lhsValue,
                                  rhsValue, "", context.currentBlock());

comparison:
    return CmpInst::Create(Instruction::ICmp, pred, lhsValue,
                           rhsValue, "", context.currentBlock());
}

/* gerando codigo para um node de atribuicao */
Value *NAssignment::codeGen(CodeGenContext &context)
{
    // verify_semantic_assign(lhs, rhs, context);
    std::cout << "Criando atribuição para " << lhs.name << endl;
    Value *lhsValue = getIdentifier(context, lhs.name);
    if (!lhsValue)
    {
        return NULL;
    }

    // se achou faz um store para salvar o resultado na var
    return new StoreInst(rhs.codeGen(context), lhsValue, false, context.currentBlock());
}

/* gerando bloco de instruções */
Value *NBlock::codeGen(CodeGenContext &context)
{
    std::cout << "Gerando código para " << typeid(*this).name() << endl;
    StatementList::const_iterator it;
    Value *last = NULL;

    // itera sobre cada instr no bloco chamando codeGen
    // se encontrar um valor de retorno no meio ele ignora as instr após ele
    for (it = statements.begin(); it != statements.end(); it++)
    {
        std::cout << "Gerando código para " << typeid(**it).name() << endl;
        last = (**it).codeGen(context);
        if (context.getCurrentReturnValue() != NULL)
        {
            std::cout << "Valor de retorno encontrado, ignorando instruções restantes \n";
            return last;
        }
    }

    // retorna o valor gerado pela ultima instr para esse bloco
    return last;
}

/* gerando codigo para uma instr expr */
Value *NExpressionStatement::codeGen(CodeGenContext &context)
{
    std::cout << "Gerando código para " << typeid(expression).name() << endl;
    return expression.codeGen(context);
}

/* retorno do tipo do id */
static Type *typeOf(const NId &type)
{

    if (type.name.compare("MILHAS") == 0)
    {
        return Type::getInt64Ty(MyContext);
    }
    else if (type.name.compare("DOLAR") == 0)
    {
        return Type::getDoubleTy(MyContext);
    }
    else if (type.name.compare("VOUCHER") == 0)
    {
        return Type::getInt8PtrTy(MyContext);
    }
    std::cout << "nao encontrei esse tipo em typeOf" << std::endl;
    return Type::getVoidTy(MyContext);
}

/* gerando codigo para uma declaração de var */
Value *NBagagem::codeGen(CodeGenContext &context)
{
    AllocaInst *alloc;
    std::cout << "Criando declaração de variável " << type.name << " " << id.name << endl;

    // reserva espaço na memoria para essa var no bloco de codigo
    alloc = new AllocaInst(typeOf(type), 0, id.name.c_str(), context.currentBlock());

    context.locals()[id.name] = alloc;
    if (assignmentExpr != NULL)
    {
        NAssignment assn(id, *assignmentExpr);
        assn.codeGen(context);
    }
    else
    {
        if (type.name == "int")
        {
            assignmentExpr = new NMilhas(0);
            NAssignment assn(id, *assignmentExpr);
            assn.codeGen(context);
        }
        if (type.name == "float")
        {
            assignmentExpr = new NDolar(0.0);
            NAssignment assn(id, *assignmentExpr);
            assn.codeGen(context);
        }
        // if (type.name == "bool")
        // {
        //     assignmentExpr = new NBool("true");
        //     NAssignment assn(id, *assignmentExpr);
        //     assn.codeGen(context);
        // }
        if (type.name == "string")
        {
            assignmentExpr = new NVoucher("");
            NAssignment assn(id, *assignmentExpr);
            assn.codeGen(context);
        }
    }
    return alloc;
}

std::string getValueFormatString(llvm::Value *value)
{
    llvm::Type *valueType = value->getType();

    if (valueType->isIntegerTy())
    {

        return "%d";
    }
    if (valueType->isFloatingPointTy())
    {

        return "%f";
    }
    if (llvm::PointerType *pointerType = llvm::dyn_cast<llvm::PointerType>(valueType))
    {
        llvm::Type *elementType = pointerType->getElementType();

        if (elementType->isIntegerTy(8))
        {
            return "%s";
        }
    }
    if (valueType->isStructTy())
    {
        return "%s";
    }
    if (valueType->isPointerTy())
    {
        return "%p";
    }

    // Se nenhum dos tipos correspondentes for encontrado, retorne uma string vazia ou um valor padrão.
    return "%s";
}

/* verificar conteudo d euma função */
void printFunctionContent(llvm::Function *func) {
    if (!func) {
        llvm::outs() << "Function is null.\n";
        return;
    }

    llvm::outs() << "Function Content:\n";
    func->print(llvm::outs()); // imprime a função no fluxo de saída padrão
    llvm::outs() << "\n";
}

/* gerando codigo para print */
Value *NCheckout::codeGen(CodeGenContext &context)
{
    Function *printfFn = context.module->getFunction("printf");
    std::deque<Value *> args;
    ExpressionList::const_iterator it;
    std::string formatString = "";

    for (it = arguments.begin(); it != arguments.end(); it++)
    {

        Value *value = (**it).codeGen(context);
        formatString += getValueFormatString(value);
        formatString += " ";
        args.push_back(value);
    }
    formatString += "\n";


    if (formatString.empty())
    {
        std::cerr << "Erro: String de formato vazia!" << std::endl;
        return nullptr; 
    }
    const char *constValue = format.c_str();
    
    llvm::Constant *format_const = llvm::ConstantDataArray::getString(MyContext, constValue);
    llvm::GlobalVariable *var =
        new llvm::GlobalVariable(
            *context.module, llvm::ArrayType::get(llvm::IntegerType::get(MyContext, 8), strlen(constValue) + 1),
            true, llvm::GlobalValue::PrivateLinkage, format_const, ".str");
    llvm::Constant *zero =
        llvm::Constant::getNullValue(llvm::IntegerType::getInt32Ty(MyContext));

    std::vector<llvm::Constant *> indices;
    indices.push_back(zero);
    indices.push_back(zero);
    llvm::Constant *var_ref = llvm::ConstantExpr::getGetElementPtr(
        llvm::ArrayType::get(llvm::IntegerType::get(MyContext, 8), strlen(constValue) + 1),
        var, indices);

    args.push_front(var_ref);
    std::vector<Value *> argsT(args.begin(), args.end());

    CallInst *call = CallInst::Create(printfFn, makeArrayRef(argsT), "", context.currentBlock());
    return call;
}

Value *NAlfandega::codeGen(CodeGenContext &context)
{

    std::cout << "Criando comando if" << std::endl;

    Function *TheFunction = context.currentBlock()->getParent();
    context.pushFunction(TheFunction);
    BasicBlock *ThenBB = BasicBlock::Create(MyContext, "then", TheFunction);
    BasicBlock *ElseBB = BasicBlock::Create(MyContext, "else", TheFunction);
    BasicBlock *MergeBB = BasicBlock::Create(MyContext, "merge", TheFunction);

    Builder.SetInsertPoint(context.currentBlock());
    Value *CondV = condition.codeGen(context);
    if (elseBlock != NULL)
    {
        Builder.CreateCondBr(CondV, ThenBB, ElseBB);
    }
    else
    {
        ElseBB->eraseFromParent();
        Builder.CreateCondBr(CondV, ThenBB, MergeBB);
    }

    Builder.SetInsertPoint(ThenBB);
    context.pushBlock(ThenBB);

    Value *ThenV = ifBlock.codeGen(context);

    if (context.getCurrentReturnValue() == NULL)
    {
        Builder.CreateBr(MergeBB);
    }
    context.popBlock();

    if (elseBlock != NULL)
    {
        Builder.SetInsertPoint(ElseBB);
        context.pushBlock(ElseBB);
        Value *ElseV = elseBlock->codeGen(context);
        if (context.getCurrentReturnValue() == NULL)
        {
            Builder.CreateBr(MergeBB);
        }
        context.popBlock();
    }

    Builder.SetInsertPoint(MergeBB);
    context.pushBlock(MergeBB);

    std::cout << "Creating if statement done" << std::endl;

    return NULL;
}