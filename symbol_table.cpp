#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
symbol_table::symbol_table(){

}
symbol_table::~symbol_table(){
    
}
symbol_table_entry symbol_table::create(){
    return symbol_table_entry();
}
unsigned long symbol_table::lookup(symbol_table_entry* st, std::string key){

    for(size_t idx = 0; idx < st->ids.size(); ++idx){
        if(st->ids.at(idx) == key)
            return idx;
    }
    return nil;
}
unsigned long symbol_table::insert(symbol_table_entry* st, std::string key){
    st->ids.push_back(key);
    return(st->ids.size()-1);
}
void symbol_table::dump(symbol_table_entry* st){
    std::cout << "dump symbol_table" << std::endl;
    std::cout << "=========================" << std::endl;
    for(std::vector<std::string>::const_iterator iter = st->ids.begin(); iter != st->ids.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
    std::cout << "=========================" << std::endl;
}