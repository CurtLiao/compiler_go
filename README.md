# compiler_go
b10315007
林詠翔
hw2


how to compile
	1.use command
		make
	2.use python script
		./auto_test.py
	it will output a file=>a.out

how to use 
	a.out < ###(filename)

lex: 
	revise between hw1 and hw2
		token:
			add return function for passing to yacc
		real:
			let it can pass float type 
				e.g.
					1.2423423532
					-32342.325252

yacc:
	almost be invoke by symbol_table.cpp

symbol table:
	look up/ assign / declare variable
	variable can recognize type , const, function