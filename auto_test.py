#!/usr/bin/python
import sys
import os

# lex source.l
# cc -o scanner -O lex.yy.c -ll
# ./scanner <  hello_world.txt
 
if __name__ == '__main__':
	filename = "hello_world.txt"
	os.system("lex source.l")
	# os.system("cc -o scanner -O lex.yy.c -ll")
	# os.system("g++ -o scanner -O lex.yy.c -ll")
	os.rename("lex.yy.c", "lex.yy.cpp")
	# os.system("g++ -o scanner -O lex.yy.cpp -ll")
	os.system("g++ -o scanner -O *.cpp -ll")

	# os.system("cc -o scanner -O lex.yy.c -lfl")

	if(len(sys.argv) == 2):
		filename = sys.argv[1]
	print("test filename => ", filename)
	os.system("./scanner < " + filename)
	sys.exit()