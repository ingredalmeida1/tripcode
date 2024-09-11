#include "ast.h"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        open_file(argv[1]);
    }
    yyparse();
    cout << programBlock << endl;

    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();
    CodeGenContext context;
    createCoreFunctions(context);
    context.generateCode(*programBlock);
    context.BuildCode();

    std::string output(argv[1]);
    output = output.substr(0, output.find_last_of("."));

    generateGraph(*programBlock, output);

    std::cout << "Fim da execução." << std::endl;

    return 0;
}
