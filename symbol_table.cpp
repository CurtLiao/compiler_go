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
    for(size_t table_idx = tableEntrys.size() -1; (int) table_idx  >= 0; --table_idx){
        for(size_t idx = tableEntrys.at(table_idx).ids.size() - 1; (int) idx >= 0; --idx)
            if(tableEntrys.at(table_idx).ids.at(idx).name == key)
                return tableEntrys.at(table_idx).ids.at(idx);
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
        std::cout << "assign keys : " << key << std::endl;
        //avoid empty string
        if(strcmp(key.c_str(), "")== 0)
            break;
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
        tableEntrys.push_back(symbol_table_entry());
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
    for(auto table = tableEntrys.rbegin(); table!= tableEntrys.rend(); ++table){
        for(auto it = (*table).ids.rbegin(); it!= (*table).ids.rend(); ++it){
        //check name and type and const;
           std::cout << "variable => " << (*it).name << "\t\t type = " << type_name((*it).type)  << "\t special_type = " << s_type_name((*it).s_type) << std::endl;
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