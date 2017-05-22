#!/usr/bin/python
import sys
import os

# lex source.l
# cc -o scanner -O lex.yy.c -ll
# ./scanner <  hello_world.txt
 
if __name__ == '__main__':
	op = "scp -r "
	path = "B10315007@140.118.155.208:./"
	filename = "./README.md "
	print(op + filename + path)
	# os.system(op + filename + path)
	# os.system("XIAOSEAN")
	
	# sys.exit()


