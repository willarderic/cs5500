#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <unordered_map>
#include <string>
#include <stdlib.h>

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
    int nestingLevel;
    char* label;
    int frameSize;
    int offset;
    int value;
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
        TypeInfo ret = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NULL,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
        found = hashTable.find(name);
        if (found != hashTable.end()) {
            ret = found->second;
        }
        return ret;
    }

    std::unordered_map<std::string, TypeInfo> getAllEntries(){
        return hashTable;
    }

    int frameSize() {
        int size = 0;
        std::unordered_map<std::string, TypeInfo>::iterator it;
        for (it = hashTable.begin(); it != hashTable.end(); ++it) {
            switch (it->second.type) {
                case INT:
                case BOOL:
                case CHAR:
                    size++;
                    break;
                case ARRAY:
                    // distance between indices and then +1 because indices are inclusive
                    size += abs(it->second.startIndex - it->second.endIndex) + 1; 
                    break;
                default:
                    break;
            }
        }
        return size;
    }
};

#endif