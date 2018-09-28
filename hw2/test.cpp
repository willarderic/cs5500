#include <iostream>
#include "SymbolTable.h"

int main() {
	TypeInfo info;
	info.type = 1;
	info.startIndex = 1;
	info.endIndex = 2;
	info.baseType = 2;
	SymbolTable table = SymbolTable();
	bool first = table.add("first", info);
	bool second = table.add("first",info);
	bool third = table.find("first");
	std::cout << first << " " << second << " " << third << std::endl;
}
