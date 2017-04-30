# compiler_go
b10315007
林詠翔
hw1


how to compile
	two way
	1.use commend
		lex source.l"
		rename lex.yy.c lex.yy.cpp
		g++ -o scanner -O *.cpp -ll
	2.use python script
		./auto_test.py

how to use 
	./scanner < filename