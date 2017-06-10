#!/usr/bin/python
import sys
import os

# lex source.l
# cc -o scanner -O lex.yy.c -ll
# ./scanner <  hello_world.txt
 
if __name__ == '__main__':
	filename = "test.go"		
	os.system("bison -y -d yacc.y")
	os.system("flex source.l")
	# os.rename("lex.yy.c", "lex.yy.cpp")
	os.system("mv lex.yy.c lex.yy.cpp")

	# os.mv("lex.yy.c", "lex.yy.cpp")

	# os.rename("y.tab.c", "y.tab.cpp")

	# os.system("g++ -o scanner -O lex.yy.cpp y.tab.c symbol_table.cpp -ll")
	# os.system("g++ -o scanner -O lex.yy.cc y.tab.c symbol_table.cpp -ll")
	# os.system("g++ -o scanner -O lex.yy.cc y.tab.c symbol_table.cpp -ll")
	os.system("g++ -std=c++11 lex.yy.cpp y.tab.c symbol_table.cpp -ll -ly")
	# os.system("gcc lex.yy.c y.tab.c -lfl -ly")
	# javaa < HelloWorldApp.jasm

	# if(len(sys.argv) == 2):
	# 	filename = sys.argv[1]
	# # print("test filename => ", filename)
	os.system("./a.out < " + filename)
	sys.exit()