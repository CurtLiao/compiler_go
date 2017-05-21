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
struct variable{
	std::vector<int> func_type;
	std::string name;
	union{
		variable_data data;	
	};
	
	int type;// 0 = int 1 = bool 2 = str 3 = real_numver
	int s_type;// 0 = normal 1 = const 2 = function declare
	variable():type(0), s_type(0){
		data.value = 0;
	}
	variable(int type1): type(type1), s_type(0){	}
	variable(int type1, int type2): type(type1), s_type(type2){
		init_data(type1);
	}
	variable(int type1, int type2, char* value): type(type1), s_type(type2){
		data.str = value;
	}
	variable(int type1, int type2, bool value): type(type1), s_type(type2){
		data.flag = value;
	}
	variable(int type1, int type2, int value): type(type1), s_type(type2){
		data.value = value;
	}

	void copy(const char* key, variable v){
		name = key;
		type = v.type;
		s_type = v.s_type;
		data = v.data;
	}
	void copy(variable v){
		type = v.type;
		s_type = v.s_type;
		data = v.data;
	}
	void init_data(int type){
		char* c = new char[1];
		c[0] = '\0';
		if(type == 0){
	        data.value = 0;
		}
	    else if(type == 1){
	        data.flag = false;
	    }
	    else{
	    	data.str = c;
	    }
	}
};
typedef struct {
	std::vector<variable> ids;
}symbol_table_entry;
class symbol_table
{
public:
    symbol_table();
    ~symbol_table();
	bool each_assign(std::string key,variable v);
	bool assign(std::string keys, int type = 0, int type2 = 0);
	bool assign(std::string keys, variable v);
	bool assign_array_by_id(std::string key, int index,variable v);
	bool declared(std::string keys, int type = 0, int type2 = 0);
	bool declared(std::string keys, variable v);
    bool declared_array(std::string keys,variable v, int array_size);
	void declared_noncheck(std::string key,variable v);
    void function_concat(int type, char *name);
	void function_declared(int type, char *name);
    void dump();
    void push_table();
	void pop_table();
	char* concat_array_element(std::string key, int index);
    variable lookup_variable(std::string key);
	variable lookup_array(std::string key, int index);

private:
	std::vector<symbol_table_entry> tableEntrys;
	std::string const_error_msg = "The variable is a constant, can not reassign!";
	std::string nondeclared_error_msg = "The variable is not a variable, can not assign!";
	std::string redeclared_error_msg = "The variable already be declared => use for variable!";
	std::string func_redeclared_error_msg = "The variable already be declared! => use for funcion";

	std::string type_name(int value);
	std::string s_type_name(int value);
	variable func_v;
	std::string func_name;
	std::string func_check_count;

};
