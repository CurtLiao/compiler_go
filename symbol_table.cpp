#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
symbol_table::symbol_table(){
    tableEntrys.push_back(symbol_table_entry());
}
symbol_table::~symbol_table(){
    
}
variable symbol_table::lookup_variable(std::string key){
    for(auto table = tableEntrys.rbegin(); table!= tableEntrys.rend(); ++table){
        for(auto it = (*table).ids.rbegin(); it!= (*table).ids.rend(); ++it){
        //check name and type and const;
            if((*it).name == key){
                return (*it);
            }
        }
    }
    variable TYPE_NIL_variable(TYPE_NIL);
    return TYPE_NIL_variable;
}
variable symbol_table::lookup_array(std::string key, int index){
    std::stringstream ss;
    std::string i_str; // for str to int
    ss << index;
    ss >>  i_str;  //透過串流運算子寫到string類別即可
    std::string key_array = key + "[" + i_str + "]";
    for(auto table = tableEntrys.rbegin(); table!= tableEntrys.rend(); ++table){
        for(auto it = (*table).ids.rbegin(); it!= (*table).ids.rend(); ++it){
        //check name and type and const;
            if((*it).name == key_array){
                return (*it);
            }
        }
    }
    variable TYPE_NIL_variable(TYPE_NIL);
    return TYPE_NIL_variable;
}
bool symbol_table::declared(std::string keys,int type, int type2){
    variable v(type, type2);
    return declared(keys, v);
}
bool symbol_table::declared(std::string keys,variable v){
    std::istringstream iss(keys);
    do
    {
        std::string key;
        iss >> key;
        //avoid empty string
        if(strcmp(key.c_str(), "")== 0)
            break;
        std::cout << "declared keys : " << key << std::endl;
        if(lookup_variable(key).type != TYPE_NIL){
            std::cout << "key : " << key << "\t" <<redeclared_error_msg << std::endl;
            return false;
        }
        variable dec_v;
        dec_v.copy(key.c_str(), v);
        dec_v.virtual_index = stack_index++;
        if(tableEntrys.size() == 1){
            dec_v.is_global = true;
        }
        tableEntrys.back().ids.push_back(dec_v);

    } while (iss);
    return true;
}
void symbol_table::declared_noncheck(std::string key,variable v){
    
    std::cout << "declared keys : " << key << " stack_index = " << stack_index << std::endl;
    variable dec_v;
    dec_v.copy(key.c_str(), v);
    // it is argv
    dec_v.is_global = false;
    // dec_v.virtual_index = stack_index++;

    tableEntrys.back().ids.push_back(dec_v);

}
bool symbol_table::declared_array(std::string keys,variable v, int array_size){
    std::istringstream iss(keys);
    do
    {
        std::string key;
        iss >> key;
        //avoid empty string
        if(strcmp(key.c_str(), "")== 0)
            break;
        std::cout << "declared keys : " << key << std::endl;
        for(int i = 0; i < array_size; ++i){
            std::string i_str;
            std::stringstream ss;
            ss << i;
            ss >>  i_str;  //透過串流運算子寫到string類別即可
            std::string key_array = key + "[" + i_str + "]";
            if(lookup_variable(key_array).type != TYPE_NIL){
                std::cout << "key : " << key_array << "\t" <<redeclared_error_msg << std::endl;
                return false;
            }
            variable dec_v;
            dec_v.copy(key_array.c_str(), v);
            tableEntrys.back().ids.push_back(dec_v);    
        }
        

    } while (iss);
    return true;
}

bool symbol_table::assign(std::string keys,int type, int type2){
    variable v(type, type2);
    return assign(keys, v);
}
bool symbol_table::each_assign(std::string key,variable v){
    for(auto table = tableEntrys.rbegin(); table!= tableEntrys.rend(); ++table){
        for(auto it = (*table).ids.rbegin(); it!= (*table).ids.rend(); ++it){
        //check name and type and const;
            if((*it).name == key){
                if((*it).type  == v.type){
                    if((*it).s_type  == STYPE_NORMAL){
                        (*it).data = v.data;
                        return true;     
                    }
                    else if ((*it).s_type  == STYPE_CONST){
                        std::cout << "key : " << key << "\t" << const_error_msg << std::endl;
                        return false;
                    }
                    else if ((*it).s_type  == STYPE_FUNC){
                        std::cout << "key : " << key << "\t" << func_redeclared_error_msg << std::endl;
                        return false;
                    }
                }
            }
        }
    }

    std::cout << nondeclared_error_msg << std::endl;
    return false;
}
bool symbol_table::assign_array_by_id(std::string key, int index,variable v){
    std::stringstream ss;
    std::string i_str; // for str to int
    ss << index;
    ss >>  i_str;  //透過串流運算子寫到string類別即可
    std::string key_array = key + "[" + i_str + "]";
    std::cout << "in assign array " << key_array << std::endl;
    for(auto table = tableEntrys.rbegin(); table!= tableEntrys.rend(); ++table){
        for(auto it = (*table).ids.rbegin(); it!= (*table).ids.rend(); ++it){
        //check name and type and const;
            if((*it).name == key_array){
                if((*it).type  == v.type){
                    if((*it).s_type  == STYPE_NORMAL){
                        (*it).data = v.data;
                        return true;     
                    }
                    else if ((*it).s_type  == STYPE_CONST){
                        std::cout << "key : " << key << "\t" << const_error_msg << std::endl;
                        return false;
                    }
                    else if ((*it).s_type  == STYPE_FUNC){
                        std::cout << "key : " << key << "\t" << func_redeclared_error_msg << std::endl;
                        return false;
                    }
                }
            }
        }
    }

    std::cout << nondeclared_error_msg << std::endl;
    return false;
}
bool symbol_table::assign(std::string keys,variable v){
    std::istringstream iss(keys);
    do
    {
        std::string key;
        iss >> key;
        std::cout << "assign keys : " << key << std::endl;
        //avoid empty string
        if(strcmp(key.c_str(), "")== 0)
            break;
        if(each_assign(key, v) == false)
            return false;
    } while (iss);
    return true;
}
bool symbol_table::assign_for_func(std::string key,variable v){
    for(auto table = tableEntrys.rbegin(); table!= tableEntrys.rend(); ++table){
        for(auto it = (*table).ids.rbegin(); it!= (*table).ids.rend(); ++it){
        //check name and type and const;
            if((*it).name == key){
                if ((*it).s_type  == STYPE_FUNC){
                    (*it).func_size = v.func_size;
                    for(int i = 0; i < v.func_size; ++i)
                        (*it).func_type[i] = v.func_type[i];
                    return true;
                }
            }
        }
    }
    return true;
}
void symbol_table::push_table(){
    // std::cout << "push table========================= cur size = " << (int)tableEntrys.size()<< std::endl;

    // reset local variable
    if((int)tableEntrys.size() == 1){
        stack_index = 1;
    }
    tableEntrys.push_back(symbol_table_entry());
}
void symbol_table::pop_table(){
    if((int)tableEntrys.size() >= 0)
        tableEntrys.pop_back();
}

void symbol_table::dump(){
    std::cout << "dump symbol_table" << std::endl;
    std::cout << "=========================" << std::endl;
    for(auto table = tableEntrys.begin(); table!= tableEntrys.end(); ++table){
        for(auto it = (*table).ids.begin(); it!= (*table).ids.end(); ++it){
        //check name and type and const;
           std::cout << "variable => \n\t key = " << (*it).name << "\n\t type = " << type_name((*it).type)  << "\n\t special_type = " << s_type_name((*it).s_type)  << std::endl;
                if((*it).type == 0)
                    std::cout << "\t value = " << (*it).data.value  << std::endl;
                else if((*it).type == 1){
                    if((*it).data.flag == 0){
                       std::cout << "\t value = false"  << std::endl;
                    }
                    else{
                        std::cout << "\t value = true"  << std::endl;   
                    }
                }
                else
                    std::cout << "\t value = " << (*it).data.str  << std::endl;

             // std::cout << "variable => " << (*it).name << "\t\t type = " << type_name((*it).type)  << "\t special_type = " << s_type_name((*it).s_type) << std::endl;
        }
        std::cout << "====next scope===="<< std::endl;
    }
    
    std::cout << "=========================" << std::endl;
}
std::string symbol_table::type_name(int value){
    if(value == 0)
        return "INT";
    if(value == 1)
        return "BOOL";
    if(value == 2)
        return "STRING";
    if(value == 3)
        return "REAL";
    return "unknow type";
}
std::string symbol_table::s_type_name(int value){
    if(value == STYPE_NORMAL)
        return "variable";
    if(value == STYPE_CONST)
        return "CONST";
    if(value == STYPE_FUNC)
        return "FUNC";
    return "unknow type";

}
bool symbol_table::check_global(){
    if(tableEntrys.size() == 1)
        return true;
    return false;
}

void symbol_table::function_concat(int type, char *name){
    // store function args type
    variable v = lookup_variable(func_name);
    v.func_type[v.func_size++] = type;
    assign_for_func(func_name, v);
    // store each arugment
    declared_noncheck(name, variable(type));

}
void symbol_table::function_declared(int type, char *name){
    variable v(type, STYPE_FUNC);
    v.name = name;
    // v.virtual_index = stack_index++;
    stack_index = 0;
    tableEntrys.front().ids.push_back(v);
    func_name = name;

}
void symbol_table::args_encode_index(){

    for(int i = tableEntrys.back().ids.size() - 1; i >= 0 ; --i){
        tableEntrys.back().ids.at(i).virtual_index = tableEntrys.back().ids.size() - 1 - i;
    }

}
bool symbol_table::function_type_check(char *func_name, char* args){
    variable v = lookup_variable(func_name);
    std::string func_type_str = "";
    std::string i_str;

    for(int i = 0; i < v.func_size; ++i){
        
        //check name and type and const;
        std::stringstream ss;
        std::string i_str; // for int to str
        ss <<  v.func_type[i] ;
        ss >> i_str;  
        func_type_str = i_str + func_type_str;
        if(i != v.func_size - 1)
            func_type_str = " " + func_type_str ;
    }
    std::string args_str = std::string(args);


    if(args_str == func_type_str){
        return true;
    }
    return(false);
}
std::string symbol_table::function_args_type(char *func_name){
    variable v = lookup_variable(func_name);
    std::string func_type_str = "";
    for(int i = 0; i < v.func_size; ++i){
        
        //check name and type and const;
        if(v.func_type[i] == 0)
            func_type_str = "int" + func_type_str;
        else if(v.func_type[i] == 1)
            func_type_str = "boolean" + func_type_str;
        else if(v.func_type[i] == 2)
            func_type_str = "string" + func_type_str;
        
        if(i != v.func_size - 1)
            func_type_str = "," + func_type_str ;
    }
    return(func_type_str);
}
std::string symbol_table::variable_type_str(char *func_name){
    variable v = lookup_variable(func_name);
    std::string func_type_str = "";
    if(v.type == 0)
        return("int");
    if(v.type == 1)
        return("boolean");
    if(v.type == 2)
        return("string");
    return("int");
}