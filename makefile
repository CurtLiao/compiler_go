TARGET = compiler
LEX = flex
YACC = bison
CXX = g++ -std=c++11 

compiler: y.tab.c lex.yy.cpp symbol_table.cpp
	$(CXX) $^ -ll -ly

y.tab.c: yacc.y
	$(YACC) -y -d $^ 
	

lex.yy.cpp: source.l
	$(LEX) -o $@ $^

clean:
	rm -fy.tab.c lex.yy.cpp symbols.cpp

