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
            // std::cout << "lookup key => " << (*it).name << std::endl;
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
    // for(size_t table_idx = tableEntrys.size() -1; (int) table_idx  >= 0; --table_idx){
    //     for(size_t idx = tableEntrys.at(table_idx).ids.size() - 1; (int) idx >= 0; --idx)
    //         if(tableEntrys.at(table_idx).ids.at(idx).name == key)
    //             return tableEntrys.at(table_idx).ids.at(idx);
    // }
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
        tableEntrys.back().ids.push_back(dec_v);

    } while (iss);
    return true;
}
void symbol_table::declared_noncheck(std::string key,variable v){
    
    std::cout << "declared keys : " << key << std::endl;
    variable dec_v;
    dec_v.copy(key.c_str(), v);
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
// int symbol_table::checkDeclared(std::string key){
//     int variable_type = lookup_variable(key).type;
//     int special_type = lookup_variable(key).s_type;
//     if(variable_type == TYPE_NIL){
//         return TYPE_NIL;
//     }
//     else if(special_type == STYPE_CONST){
//         return TYPE_CONST;
//     }
//     else {
//         return TYPE_PRIMITVE;
//     }
// }
void symbol_table::push_table(){
    tableEntrys.push_back(symbol_table_entry());
}
void symbol_table::pop_table(){
    if((int)tableEntrys.size() >= 0)
        tableEntrys.pop_back();
}
// void symbol_table::dump(symbol_table_entry* st){
//     std::cout << "dump symbol_table" << std::endl;
//     std::cout << "=========================" << std::endl;
//     for(std::vector<std::string>::iterator iter = st->ids.begin(); iter != st->ids.end(); ++iter) {
//         std::cout << *iter << std::endl;
//     }
//     std::cout << "=========================" << std::endl;
// }
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
    // for(std::vector<std::string>::iterator iter = st->ids.begin(); iter != st->ids.end(); ++iter) {
    //     std::cout << *iter << std::endl;
    // }
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
// char* symbol_table::concat_array_element(std::string key, int index){
//     std::stringstream ss;
//     std::string i_str; // for str to int
//     ss << index;
//     ss >>  i_str;  //透過串流運算子寫到string類別即可
//     std::string key_array = key + "[" + i_str + "]";
//     return &key_array[0u];;
// }
void symbol_table::function_concat(int type, char *name){
    // store function args type
    lookup_variable(func_name).func_type.push_back(type);
    // store each arugment
    declared_noncheck(name, variable(type));

}
void symbol_table::function_declared(int type, char *name){
    declared(name, variable(type, STYPE_FUNC));
}
bool symbol_table::function_type_Type_check(int type){
    func_check_count++;
    variable v = lookup_variable(func_name);
    int vec_size = v.func_type.size();
    if(func_check_count >= vec_size)
        return false;
    if(type == v.func_type.at())
}
bool symbol_table::function_type_ID_check(char *name){
    retrun (function_type_Type_check(lookup_variable(name).type))
}
bool symbol_table::function_check_init(char *name){
    retrun (function_type_Type_check(lookup_variable(name).type))
}
func_check_count