// symbol Table
//
// store the scanner pass token.
//

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#define TYPE_NIL -1
#define TYPE_CONST -2
#define TYPE_PRIMITVE 0

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
	bool constFlag;
	
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
	bool assign(std::string key,int type);
	bool assign(std::string key,int type, bool cFlag);
	bool assign(std::string key,int type, variable_data value, bool constFlag = false);
	bool assign(std::string keys,variable v);
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
	std::string type_name(int value);
	variable_data initialize_variable(int type);

};
