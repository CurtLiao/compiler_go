// symbol Table
//
// store the scanner pass token.
//

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#define TYPE_NIL -1
#define TYPE_CONST -2
#define TYPE_PRIMITVE 0
#define STYPE_NORMAL 0
#define STYPE_CONST 1
#define STYPE_FUNC 2
#include <sstream>
#include <iostream>
#include <vector>
#include "string.h"
#endif

typedef union{
	int value;	
	char *str;	
	bool flag;
}variable_data;
typedef struct {
	std::string name;
	variable_data data;
	int type;
	int s_type;// 0 = normal 1 = const 2 = function declare
	
}variable;
typedef struct {
	std::vector<variable> ids;
}symbol_table_entry;
class symbol_table
{
public:
    symbol_table();
    ~symbol_table();

    // symbol_table_entry create();
    // unsigned long lookup(symbol_table_entry* st, std::string key);

	bool each_assign(std::string key,variable v);
	bool assign(std::string keys, int type = 0, int type2 = 0);
	bool assign(std::string keys, variable v);
	bool declared(std::string keys, int type = 0, int type2 = 0);
	bool declared(std::string keys, variable v);

    variable lookup_variable(std::string key);
    bool insert(std::string key,int type, variable_data value);
    int checkDeclared(std::string key);
    // void dump(symbol_table_entry* st);
    void dump();
    // void push_table();
    void push_table();
	void pop_table();
private:
	std::vector<symbol_table_entry> tableEntrys;
	std::string const_error_msg = "The variable is a constant, can not reassign!";
	std::string nondeclared_error_msg = "The variable is not a variable, can not assign!";
	std::string redeclared_error_msg = "The variable already be declared => use for variable!";
	std::string func_redeclared_error_msg = "The variable already be declared! => use for funcion";

	std::string type_name(int value);
	std::string s_type_name(int value);

	variable_data initialize_variable(int type);

};
