TARGET = compiler
LEX = flex
YACC = bison
CXX = g++ -std=c++11 
.PHONY: all clean

all: $(TARGET)

$(TARGET): y.tab.c lex.yy.cpp symbol_table.cpp symbol_table.h
	$(CXX) $^ -ll -ly

y.tab.c: yacc.y
	$(YACC) -y -d $^ 
	

lex.yy.cpp: source.l
	$(LEX) -o $@ $^

clean:
	rm y.tab.* lex.yy.cpp

