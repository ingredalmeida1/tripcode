
OBJS = parser.o  \
       codegen.o \
       main.o    \
       tokens.o  \
       corefn.o  \
       native.o \
	   ast.o \

LLVMCONFIG = llvm-config-14
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++14
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --libs`
archive ?= main.cll

clean:
	$(RM) -rf parser.cpp parser.hpp parser tokens.cpp $(OBJS) output.ll output.s output.o output.bc parser *.dot *.exe *.png

parser.cpp: parser.y
	bison -d  -Wno-other -o $@ $^ 
	
parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp
	flex -o $@ $^ 

%.o: %.cpp
	clang++-14 -gfull -c $(CPPFLAGS) -o $@ $< -w


parser: $(OBJS)	
	clang++-14 -gfull -o $@ $(OBJS) $(LIBS) $(LDFLAGS) -w


trip: parser 
	$(RM) -rf output.ll output.s output.o output.bc 
	./parser $(archive)
	llvm-as output.ll -o output.bc
	llc output.bc -filetype=obj -o output.o
	clang output.o -o $(archive).exe -no-pie

ast:
	dot -Tpng codigos/condicional.dot -o codigos/condicional.png
	dot -Tpng codigos/bubble.dot -o codigos/bubble.png

certos: parser
	make trip archive=codigos/condicional.tc
	make trip archive=codigos/bubble.tc

certos-ast: certos
	dot -Tpng codigos/condicional.dot -o codigos/condicional.png
	dot -Tpng codigos/bubble.dot -o codigos/bubble.png