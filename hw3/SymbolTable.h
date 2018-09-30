#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <unordered_map>
#include <string>

#define NOT_FOUND -2
#define NOT_APPLICABLE -1
#define INT 1
#define BOOL 2
#define CHAR 3
#define ARRAY 4
#define PROCEDURE 5
#define PROGRAM 6

struct TypeInfo {
    int type;
    int startIndex;
    int endIndex;
    int baseType;
};

class SymbolTable {

private:
    std::unordered_map<std::string, TypeInfo> hashTable;

public:
    SymbolTable() { }
    
    bool add(std::string name, TypeInfo typeInfo) {
        return hashTable.insert(std::make_pair(name, typeInfo)).second;
    }

    bool find(std::string name) {
        std::unordered_map<std::string, TypeInfo>::iterator found;
        if ((found = hashTable.find(name)) == hashTable.end()) {
            return false;
        }
        return true;
    }

    TypeInfo findAndGetEntry(std::string name) {
        std::unordered_map<std::string, TypeInfo>::iterator found;
        TypeInfo ret = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
        found = hashTable.find(name);
        if (found != hashTable.end()) {
            ret = found->second;
        }
        return ret;
    }
};

#endif