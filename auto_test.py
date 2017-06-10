#!/usr/bin/python
import sys
import os

# lex source.l
# cc -o scanner -O lex.yy.c -ll
# ./scanner <  hello_world.txt
 
if __name__ == '__main__':
	filename = "example.go"		
	os.system("bison -y -d yacc.y")
	os.system("flex source.l")
	# os.rename("lex.yy.c", "lex.yy.cpp")
	os.system("mv lex.yy.c lex.yy.cpp")
	os.system("g++ -std=c++11 lex.yy.cpp y.tab.c symbol_table.cpp -ll -ly")
	

	# if(len(sys.argv) == 2):
	# 	filename = sys.argv[1]
	# # print("test filename => ", filename)
	os.system("./a.out < " + filename) 
	jasm_filename = "b10315007"
	os.system("../javaaPortable/javaa ./%s.jasm" % jasm_filename)
	os.system("java %s.class" % jasm_filename)

	sys.exit()