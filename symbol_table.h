// symbol Table
//
// store the scanner pass token.
//

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#define nil -1
#endif


#include <iostream>
#include <vector>
#include "string.h"
typedef struct {
	std::vector<std::string> ids;
    // map<string, string> id_map;
}symbol_table_entry;
class symbol_table
{
public:
    symbol_table();
    ~symbol_table();
    symbol_table_entry create();
    unsigned long lookup(symbol_table_entry* st, std::string key);
    unsigned long insert(symbol_table_entry* st, std::string key);
    void dump(symbol_table_entry* st);
};
