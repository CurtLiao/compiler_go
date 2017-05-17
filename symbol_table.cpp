#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
symbol_table::symbol_table(){

}
symbol_table::~symbol_table(){
    
}
// symbol_table_entry symbol_table::create(){
//     return symbol_table_entry();
// }
variable symbol_table::lookup_variable(std::string key){
    for(size_t table_idx = tableEntrys.size() -1; (int) table_idx  >= 0; --table_idx){
        for(size_t idx = tableEntrys.at(table_idx).ids.size() - 1; (int) idx >= 0; --idx)
            if(tableEntrys.at(table_idx).ids.at(idx).name == key)
                return tableEntrys.at(table_idx).ids.at(idx);
    }
    variable TYPE_NIL_variable;
    TYPE_NIL_variable.type = TYPE_NIL;
    return TYPE_NIL_variable;
}
// unsigned long symbol_table::lookup(symbol_table_entry* st, std::string key){

//     for(size_t idx = 0; idx < st->ids.size(); ++idx){
//         if(st->ids.at(idx).name == key)
//             return idx;
//     }
//     return TYPE_NIL;
// }
// unsigned long symbol_table::insert(symbol_table_entry* st, std::string key){
//     st->ids.push_back(key);
//     return(st->ids.size()-1);
// }
bool symbol_table::insert(std::string key,int type, variable_data value){
    if(lookup_variable(key).type == TYPE_NIL){
        variable v;
        v.data = value;
        return true;
    }
    return false;
}
bool symbol_table::assign(std::string key,int type, variable_data value, bool cFlag){
    variable v;
    v.type = type;
    v.data = value;
    v.constFlag = cFlag;
    return assign(key, v);
}
bool symbol_table::assign(std::string key,variable v){
    for(auto table = tableEntrys.rbegin(); table!= tableEntrys.rend(); ++table){
        for(auto it = (*table).ids.rbegin(); it!= (*table).ids.rend(); ++it){
        //check name and type and const;
            if((*it).name == key){
                if((*it).type  == v.type){
                    if((*it).constFlag  == true){
                        (*it).data = v.data;
                        return true;     
                    }
                    else{
                        std::cout << const_error_msg << std::endl;
                        return false;
                    }
                }
            }
        }
    }

    std::cout << nondeclared_error_msg << std::endl;
    return false;

    // for(size_t table_idx = tableEntrys.size() -1; (int) table_idx  >= 0; --table_idx)
    //     for(size_t idx = tableEntrys.at(table_idx).ids.size() - 1; (int) idx >= 0; --idx){
    //         //check name and type and const;
    //         if(tableEntrys.at(table_idx).ids.at(idx).name == key){
    //             if(tableEntrys.at(table_idx).ids.at(idx).type  == v.type){
    //                 if(tableEntrys.at(table_idx).ids.at(idx).constFlag  == true){
    //                     tableEntrys.at(table_idx).ids.at(idx).data = v.data;
    //                     return true;     
    //                 }
    //                 else{
    //                     std::cout << const_error_msg << std::endl;
    //                     return false;
    //                 }
    //             }
    //         }
    //     }
    // std::cout << nondeclared_error_msg << std::endl;
    // return false;
}
int symbol_table::checkDeclared(std::string key){
    int variable_type = lookup_variable(key).type;
    bool constFlag = lookup_variable(key).constFlag;
    if(variable_type == TYPE_NIL){
        return TYPE_NIL;
    }
    else if(constFlag == true){
        return TYPE_CONST;
    }
    else {
        return TYPE_PRIMITVE;
    }
}
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
           std::cout << "variable => " << (*it).name << " type = " << type_name((*it).type) << std::endl;
        }
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