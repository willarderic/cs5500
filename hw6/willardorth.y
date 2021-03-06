/*
 *  bison specifications for the MIPL language.
 *  Written to meet requirements for CS 5500, Fall 2018.
 */

/*
 *  Declaration section.
 */
%{

#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <list>
#include "SymbolTable.h"
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void ignoreComment();
int ckInt();
void prRule(const char*, const char*);
string typeInfoOutput(TypeInfo typeInfo);
bool checkSymbolTables(string ident);
void printTokenInfo(const char* tokenType, const char* lexeme);
void addToSymbolTable(string name, TypeInfo typeInfo);
void assignTypeInfo(TypeInfo& t1, TypeInfo& t2);
void beginScope();
void endScope();
int genLabelNum();
void printLabel(int labelNum);
void printOpCode(string opCode);
void printOpCodeSingleAddr(string opCode, string addr);
void printOpCodeDoubleAddr(string opCode, string addr1, string addr2);
string getStr(stringstream& ss);
TypeInfo getFromSymbolTables(string name);
void nextOffset(const TypeInfo& info, int& offset);
int yyerror(const char*);

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}

#define MAX_INT	"2147483647"

// controls for various types of output
#define OUTPUT_TOKENS 0
#define OUTPUT_PRODUCTIONS 0
#define OUTPUT_SCOPES 0
#define OUTPUT_ADDSYMBOLS 0
#define OUTPUT_ERRORS 1

// constants for logical or arithmetic operators for type checking
#define LOGICAL_OP 100
#define MINUS_OP 101
#define PLUS_OP 102
#define MULT_OP 103
#define DIV_OP 104
#define EQ 105
#define NE 106
#define LT 107
#define LE 108
#define GT 109
#define GE 110

int lineNum = 1; // source line number
int staticNestingLevel = 1;

list<SymbolTable> scopeStack;
list<string> identList;

stack<pair<string, TypeInfo> > procStack;
int globalsLabelNum, stackLabelNum, codeLabelNum, entryPointLabelNum;
int blockLevel = 0;
int offset = 0;

// If statement
stack<int> elseLabelNum, postConditionalLabelNum;
// while statement label stacks
stack<pair<int, int> > whileLabelPairs;
%}

%union {
    int num;
    char* text;
    TypeInfo typeInfo;
};

/*
 *  Token declaration. 'N_...' for rules, 'T_...' for tokens.
 *  Note: tokens are also used in the flex specification file.
 */
%token      T_LPAREN    T_RPAREN    T_MULT	    T_PLUS
%token      T_COMMA     T_MINUS     T_DOT       T_DOTDOT
%token      T_COLON     T_ASSIGN    T_SCOLON    T_LT
%token      T_LE        T_NE        T_EQ        T_GT
%token      T_GE        T_LBRACK    T_RBRACK    T_DO
%token      T_AND       T_ARRAY     T_BEGIN     T_BOOL
%token      T_CHAR      T_DIV       T_CHARCONST T_INTCONST
%token      T_END       T_FALSE     T_IF        T_INT
%token      T_NOT       T_OF        T_OR        T_PROC
%token      T_PROG      T_READ      T_TRUE      T_IDENT
%token      T_VAR       T_WHILE     T_WRITE     T_UNKNOWN

%token      ST_EOF

%type<num> N_IDX N_INTCONST T_INTCONST T_INT N_ADDOP N_MULTOP N_ADDOP_ARITH N_MULTOP_ARITH N_RELOP
%type<text> T_IDENT N_IDENT N_PROCIDENT N_SIGN T_PLUS T_MINUS
%type<text> N_ENTIREVAR N_VARIDENT N_ARRAYVAR T_CHARCONST
%type<typeInfo> N_SIMPLE N_TYPE N_ARRAY N_IDXRANGE N_IDXVAR
%type<typeInfo> N_VARIABLE N_TERM N_FACTOR N_CONST N_EXPR N_SIMPLEEXPR N_OUTPUT N_INPUTVAR

/*
 *  To eliminate ambiguities.
 */
%nonassoc   T_THEN
%nonassoc   T_ELSE

/*
 *  Starting point.
 */
%start      N_START

/*
 *  Translation rules.
 */
%%
N_START         : N_PROG
                {
                    prRule("N_START", "N_PROG");
                    //printf("\n---- Completed parsing ----\n\n");
                    printOpCode("halt");
                    printLabel(stackLabelNum);
                    printOpCodeSingleAddr("bss", "500");
                    printOpCode("end");
                    return 0;
                }
                ;
N_ADDOP         : N_ADDOP_ARITH
                {
                    prRule("N_ADDOP", "N_ADDOP_ARITH");
                    $$ = $1;
                }
                | N_ADDOP_LOGIC
                {
                    prRule("N_ADDOP", "N_ADDOP_LOGIC");
                    $$ = LOGICAL_OP;
                }
N_ADDOP_ARITH   : T_PLUS
                {
                    prRule("N_ADDOP_ARITH", "T_PLUS");
                    $$ = PLUS_OP;
                }
                | T_MINUS
                {
                    prRule("N_ADDOP_ARITH", "T_MINUS");
                    $$ = MINUS_OP;
                }
                ;
N_ADDOP_LOGIC   : T_OR
                {
                    prRule("N_ADDOP_LOGIC", "T_OR");
                }
                ;
N_ADDOPLST      : /* epsilon */
                {
                    prRule("N_ADDOPLST", "epsilon");
                }
                | N_ADDOP N_TERM 
                {
                    if ($1 == PLUS_OP) {
                        printOpCode("add");
                    } else if ($1 == MINUS_OP) {
                        printOpCode("sub");
                    } else if ($1 == LOGICAL_OP) {
                        printOpCode("or");
                    }
                }
                N_ADDOPLST
                {
                    prRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
                    if ($1 == PLUS_OP || $1 == MINUS_OP) {
                        if ($2.type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ($1 == LOGICAL_OP) {
                        if ($2.type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                }
                ;
N_ARRAY         : T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE
                {
                    prRule("N_ARRAY","T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
                    $$.type = ARRAY;
                    $$.startIndex = $3.startIndex;
                    $$.endIndex = $3.endIndex;
                    $$.baseType = $6.type;
                }
                ;
N_ARRAYVAR      : N_ENTIREVAR
                {
                    prRule("N_ARRAYVAR", "N_ENTIREVAR");
                    $$ = $1;   
                }
                ;
N_ASSIGN        : N_VARIABLE T_ASSIGN N_EXPR
                {
                    if ($1.type == ARRAY)
                        yyerror("Cannot make assignment to an array");
                    if ($1.type != $3.type)
                    {
                      if ($1.type == PROCEDURE || $3.type == PROCEDURE)
                          yyerror("Procedure/variable mismatch");
                      yyerror("Expression must be of same type as variable");
                    }
                    prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");   
                    printOpCode("st");
                }
                ;
N_BLOCK         : N_VARDECPART
                {
                    offset = 0;
                    if (procStack.empty()) {
                        stringstream ss;
                        ss << (20 + scopeStack.front().frameSize());
                        printOpCodeSingleAddr("bss", getStr(ss));
                        printLabel(codeLabelNum);
                    } else {
                        procStack.top().second.frameSize = scopeStack.front().frameSize();
                        SymbolTable front = scopeStack.front();
                        scopeStack.pop_front();
                        addToSymbolTable(procStack.top().first, procStack.top().second);
                        scopeStack.push_front(front);
                    }
                }
                N_PROCDECPART
                {
                    if (procStack.empty()) {
                        printLabel(entryPointLabelNum);
                    }
                }
                N_STMTPART
                {
                    prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
                    endScope();

                }
                ;
N_BOOLCONST     : T_TRUE
                {
                    prRule("N_BOOLCONST", "T_TRUE");
                    printOpCodeSingleAddr("lc", "1");
                }
                | T_FALSE
                {
                    prRule("N_BOOLCONST", "T_FALSE");
                    printOpCodeSingleAddr("lc", "0");
                }
                ;
N_COMPOUND      : T_BEGIN 
                {
                    if (!procStack.empty() && blockLevel == 0) {
                        stringstream ss;
                        printLabel(procStack.top().second.labelNum);
                        ss << procStack.top().second.nestingLevel;
                        printOpCodeDoubleAddr("save", getStr(ss), "0");
                        ss << procStack.top().second.frameSize;
                        printOpCodeSingleAddr("asp", getStr(ss));
                    }
                    blockLevel++;
                }
                N_STMT N_STMTLST T_END
                {
                    prRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
                    blockLevel--;
                    if (!procStack.empty() && blockLevel == 0) {
                        stringstream ss;
                        ss << "-" << procStack.top().second.frameSize;
                        printOpCodeSingleAddr("asp", getStr(ss));
                        printOpCode("ji");
                        procStack.pop();
                    }
                }
                ;
N_CONDITION     : T_IF N_EXPR 
                {
                    prRule("N_CONDITION", "T_IF N_EXPR");
                    elseLabelNum.push(genLabelNum());
                    stringstream ss;
                    ss << "L." << elseLabelNum.top();
                    printOpCodeSingleAddr("jf", getStr(ss));
                }
                N_THEN_PART
                {
                    prRule("N_CONDITION", "N_THEN_PART");
                }
                ;
N_THEN_PART     : T_THEN N_STMT 
                {
                    prRule("N_CONDITION", "T_THEN N_STMT");
                    prRule("N_THEN_PART", "T_THEN N_STMT");
                    postConditionalLabelNum.push(genLabelNum());
                    stringstream ss;
                    ss << "L." << postConditionalLabelNum.top();
                    printOpCodeSingleAddr("jp", getStr(ss));
                    printLabel(elseLabelNum.top());
                    elseLabelNum.pop();
                    printLabel(postConditionalLabelNum.top());
                    postConditionalLabelNum.pop();
                }
                | T_THEN N_STMT T_ELSE
                {
                    postConditionalLabelNum.push(genLabelNum());
                    stringstream ss;
                    ss << "L." << postConditionalLabelNum.top();
                    printOpCodeSingleAddr("jp", getStr(ss));
                    printLabel(elseLabelNum.top());
                    elseLabelNum.pop();
                }
                N_STMT
                {
                    prRule("N_THEN_PART", "T_THEN N_STMT T_ELSE N_STMT");
                    printLabel(postConditionalLabelNum.top());
                    postConditionalLabelNum.pop();
                }
                ;
N_CONST         : N_INTCONST
                {
                    prRule("N_CONST", "N_INTCONST");
                    $$.type = INT;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    stringstream ss;
                    ss << $1;
                    printOpCodeSingleAddr("lc", getStr(ss));
                }
                | T_CHARCONST
                {
                    prRule("N_CONST", "T_CHARCONST");
                    $$.type = CHAR;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    int val = int($1[1]);
                    stringstream ss;
                    ss << val;
                    printOpCodeSingleAddr("lc", getStr(ss));
                }
                | N_BOOLCONST
                {
                    prRule("N_CONST", "N_BOOLCONST");
                    $$.type = BOOL;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                }
                ;
N_ENTIREVAR     : N_VARIDENT
                {
                    prRule("N_ENTIREVAR", "N_VARIDENT");
                    $$ = $1;
                }
                ;
N_EXPR          : N_SIMPLEEXPR
                {
                    prRule("N_EXPR", "N_SIMPLEEXPR");
                    $$ = $1;
                }
                | N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR
                {

                    prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
                    if ($1.type != $3.type) {
                        yyerror("Expressions must both be int, or both char, or both boolean");
                    }
                    $$.type = BOOL;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;

                    switch ($2) {
                        case LE:
                            printOpCode(".le.");
                            break;
                        case GE:
                            printOpCode(".ge.");
                            break;
                        case EQ:
                            printOpCode(".eq.");
                            break;
                        case NE:
                            printOpCode(".ne.");
                            break;
                        case LT:
                            printOpCode(".lt.");
                            break;
                        case GT:
                            printOpCode(".gt.");
                            break;
                    }
                }
                ;
N_FACTOR        : N_SIGN N_VARIABLE
                {
                    prRule("N_FACTOR", "N_SIGN N_VARIABLE");
                    if (strcmp($1, "-") == 0 && $2.type != INT) {
                        yyerror("Expression must be of type integer");
                    }
                    assignTypeInfo($$, $2);
                    printOpCode("deref");
                    if (strcmp($1, "-") == 0) {
                        printOpCode("neg");
                    }
                }
                | N_CONST
                {
                    prRule("N_FACTOR", "N_CONST");
                    assignTypeInfo($$, $1);
                }
                | T_LPAREN N_EXPR T_RPAREN
                {
                    prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
                    assignTypeInfo($$, $2);
                }
                | T_NOT N_FACTOR
                {
                    prRule("N_FACTOR", "T_NOT N_FACTOR");
                    if ($2.type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                    assignTypeInfo($$, $2);
                    
                    stringstream ss;
                    printOpCode("not");
                }
                ;
N_IDENT         : T_IDENT
                {
                    prRule("N_IDENT", "T_IDENT");
                    $$ = $1;
                }
                ;
N_IDENTLST      : /* epsilon */
                {
                    prRule("N_IDENTLST", "epsilon");
                }
                | T_COMMA N_IDENT N_IDENTLST
                {
                    prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
                    identList.push_front(string($2));
                }
                ;
N_IDX           : N_INTCONST
                {
                    prRule("N_IDX", "N_INTCONST");
                    $$ = $1;
                }
                ;
N_IDXRANGE      : N_IDX T_DOTDOT N_IDX
                {
                    prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
                    if ($1 > $3) {
                        yyerror("Start index must be less than or equal to end index of array");
                    }
                    $$.type = NOT_APPLICABLE;
                    $$.startIndex = $1;
                    $$.endIndex = $3;
                    $$.baseType = NOT_APPLICABLE;
                }
                ;
N_IDXVAR        : N_ARRAYVAR T_LBRACK
                {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK");
                   
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string($1));
                        it ++;
                    }
                    int c = info.offset - info.startIndex;
                    stringstream ss;
                    ss << c;
                    printOpCodeDoubleAddr("la", getStr(ss), "0");
                }
                N_EXPR T_RBRACK
                {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
                    //Have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an array was not able to be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string($1));
                        it ++;
                    }
                    if (info.type == NOT_FOUND) {
                        yyerror("? shouldn't get here");
                    }
                    if (info.type != ARRAY) {
                        if (info.type == PROCEDURE)
                            yyerror("Procedure/variable mismatch");
                        yyerror("Indexed variable must be of array type");
                    }
                    $$.type = info.baseType; // need to pass this to N_VARIABLE
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    if ($4.type != INT) {
                        if ($4.type == PROCEDURE)
                            yyerror("Procedure/variable mismatch");
                        yyerror("Index expression must be of type integer");
                    }
                    printOpCode("add");
                }
                ;
N_INPUTLST      : /* epsilon */
                {
                    prRule("N_INPUTLST", "epsilon");
                }
                | T_COMMA N_INPUTVAR N_INPUTLST
                {
                    prRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
                }
                ;
N_INPUTVAR      : N_VARIABLE
                {
                    prRule("N_INPUTVAR", "N_VARIABLE");
                    $$ = $1;
                    if ($1.type == INT) {
                        printOpCode("iread");
                    } else if ($1.type == CHAR) {
                        printOpCode("cread");
                    }
                    printOpCode("st");
                }
                ;
N_INTCONST      : N_SIGN T_INTCONST
                {
                    prRule("N_INTCONST", "N_SIGN T_INTCONST");
                    if (strcmp($1, "+") == 0) {
                        $$ = $2;
                    } else if (strcmp($1, "-") == 0) {
                        $$ = -$2;
                    }
                }
                ;
N_MULTOP        : N_MULTOP_ARITH 
                {
                    prRule("N_MULTOP", "N_MULTOP_ARITH");
                    $$ = $1;
                }
                | N_MULTOP_LOGIC
                {
                    prRule("N_MULTOP", "N_MULTOP_LOGIC");
                    $$ = LOGICAL_OP;
                }
                ;
N_MULTOP_ARITH  : T_MULT
                {
                    prRule("N_MULTOP_ARITH", "T_MULT");
                    $$ = MULT_OP;
                }
                | T_DIV
                {
                    prRule("N_MULTOP_ARITH", "T_DIV");
                    $$ = DIV_OP;
                }
                ;
N_MULTOP_LOGIC  : T_AND
                {
                    prRule("N_MULTOP_LOGIC", "T_AND");
                }
                ;
N_MULTOPLST     : /* epsilon */
                {
                    prRule("N_MULTOPLST", "epsilon");
                }
                | N_MULTOP N_FACTOR 
                {
                    if ($1 == MULT_OP) {
                        printOpCode("mult");
                    } else if ($1 == DIV_OP) {
                        printOpCode("div");
                    } else if ($1 == LOGICAL_OP) {
                        printOpCode("and");
                    }
                } 
                N_MULTOPLST
                {
                    prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
                    if ($1 == DIV_OP || $1 == MULT_OP) {
                        if ($2.type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ($1  == LOGICAL_OP) {
                        if ($2.type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                }
                ;
N_OUTPUT        : N_EXPR
                {
                    prRule("N_OUTPUT", "N_EXPR");
                    $$ = $1;
                    if ($1.type == INT) {
                        printOpCode("iwrite");
                    } else if ($1.type == CHAR) {
                        printOpCode("cwrite");
                    }
                }
                ;
N_OUTPUTLST     : /* epsilon */
                {
                    prRule("N_OUTPUTLST", "epsilon");
                }
                | T_COMMA N_OUTPUT N_OUTPUTLST
                {
                    prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
                }
                ;
N_PROCDEC       : N_PROCHDR 
                {
                    // when inside the procedures block, the static nesting level is increased
                    staticNestingLevel++;
                    blockLevel = 0;
                }
                N_BLOCK
                {
                    prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
                    staticNestingLevel--;
                }
                ;
N_PROCHDR       : T_PROC T_IDENT T_SCOLON
                    {
                        prRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
                        TypeInfo info;
                        info.type = PROCEDURE;
                        info.startIndex = NOT_APPLICABLE;
                        info.endIndex = NOT_APPLICABLE;
                        info.baseType = NOT_APPLICABLE;
                        info.nestingLevel = staticNestingLevel;
                        info.labelNum = genLabelNum();
                        procStack.push(make_pair(string($2), info));
                        beginScope();
                    }
                ;
N_PROCDECPART   : /* epsilon */
                {
                    prRule("N_PROCDECPART", "epsilon");
                }
                | N_PROCDEC T_SCOLON N_PROCDECPART
                {
                    prRule("N_PROCDECPART", "N_PROCDEC T_SCOLON N_PROCDECPART");
                }
                ;
N_PROCIDENT     : T_IDENT
                {
                    prRule("N_PROCIDENT", "T_IDENT");
                    if (!checkSymbolTables($1)) {
                        yyerror("Undefined identifier");
                    }
                }
                ;
N_PROCSTMT      : N_PROCIDENT
                {
                    prRule("N_PROCSTMT", "N_PROCIDENT");
                    TypeInfo info = getFromSymbolTables(string($1));
                    int callerNestingLevel = staticNestingLevel - 1;
                    if (info.type != NOT_FOUND && info.type == PROCEDURE) {
                        if (callerNestingLevel >= info.nestingLevel) {
                            stringstream ss;
                            for (int i = callerNestingLevel; i >= info.nestingLevel; --i) {
                                ss << i;
                                printOpCodeDoubleAddr("push", getStr(ss), "0");
                            }
                            ss << "L." << info.labelNum;
                            printOpCodeSingleAddr("js", getStr(ss));
                            for (int i = info.nestingLevel; i <= callerNestingLevel; ++i) {
                                ss << i;
                                printOpCodeDoubleAddr("pop", getStr(ss), "0");
                            }
                        } else {
                            stringstream ss;
                            ss << "L." << info.labelNum;
                            printOpCodeSingleAddr("js", getStr(ss));
                        }
                    } else {
                        yyerror("Procedure not found");
                    }
                }
                ;
N_PROG          : N_PROGLBL T_IDENT T_SCOLON
                {
                    // Print out init line
                    cout << "\tinit " 
                         << "L." << (globalsLabelNum = genLabelNum()) << ", 20, " 
                         << "L." << (stackLabelNum = genLabelNum()) << ", " 
                         << "L." << (codeLabelNum = genLabelNum()) << ", " 
                         << "L." << (entryPointLabelNum = genLabelNum()) << endl;

                    // Label for globals allocation
                    printLabel(globalsLabelNum);

                    prRule("N_PROG","N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
                    TypeInfo info;
                    info.type = PROGRAM;
                    info.startIndex = NOT_APPLICABLE;
                    info.endIndex = NOT_APPLICABLE;
                    info.baseType = NOT_APPLICABLE;
                    addToSymbolTable($2, info);
                }
                N_BLOCK T_DOT
                ;
N_PROGLBL       : T_PROG
                {
                    prRule("N_PROGLBL", "T_PROG");
                    beginScope();
                }
                ;
N_READ          : T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN
                {
                    if ($3.type != INT && $3.type != CHAR)
                      yyerror("Input variable must be of type integer or char");
                    prRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
                }
                ;
N_RELOP         : T_LT
                {
                    prRule("N_RELOP", "T_LT");
                    $$ = LT;
                }
                | T_GT
                {
                    prRule("N_RELOP", "T_GT");
                    $$ = GT;
                }
                | T_LE
                {
                    prRule("N_RELOP", "T_LE");
                    $$ = LE;
                }
                | T_GE
                {
                    prRule("N_RELOP", "T_GE");
                    $$ = GE;
                }   
                | T_EQ
                {
                    prRule("N_RELOP", "T_EQ");
                    $$ = EQ;
                }
                | T_NE
                {
                    prRule("N_RELOP", "T_NE");
                    $$ = NE;
                }
                ;
N_SIGN          : /* epsilon */
                {
                    prRule("N_SIGN", "epsilon");
                    $$ = strdup("+");
                }
                | T_PLUS
                {
                    prRule("N_SIGN", "T_PLUS");
                    $$ = $1;
                }
                | T_MINUS
                {
                    prRule("N_SIGN", "T_MINUS");
                    $$ = $1;
                }
                ;
N_SIMPLE        : T_INT
                {
                    prRule("N_SIMPLE", "T_INT");
                    $$.type = INT;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                }
                | T_CHAR
                {
                    prRule("N_SIMPLE", "T_CHAR");
                    $$.type = CHAR;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                }
                | T_BOOL
                {
                    prRule("N_SIMPLE", "T_BOOL");
                    $$.type = BOOL;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                }
                ;
N_SIMPLEEXPR    : N_TERM N_ADDOPLST
                {
                    prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
                    assignTypeInfo($$, $1);
                }
                ;
N_STMT          : N_ASSIGN
                {
                    prRule("N_STMT", "N_ASSIGN");
                }
                | N_PROCSTMT
                {
                    prRule("N_STMT", "N_PROCSTMT");
                }
                | N_READ
                {
                    prRule("N_STMT", "N_READ");
                }
                | N_WRITE
                {
                    prRule("N_STMT", "N_WRITE");
                }
                | N_CONDITION
                {
                    prRule("N_STMT", "N_CONDITION");
                }
                | N_WHILE
                {
                    prRule("N_STMT", "N_WHILE");
                }
                | N_COMPOUND
                {
                    prRule("N_STMT", "N_COMPOUND");
                }
                ;
N_STMTLST       : /* epsilon */
                {
                    prRule("N_STMTLST", "epsilon");
                }
                | T_SCOLON N_STMT N_STMTLST
                {
                    prRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
                }
                ;
N_STMTPART      : N_COMPOUND
                {
                    prRule("N_STMTPART", "N_COMPOUND");
                }   
                ;
N_TERM          : N_FACTOR N_MULTOPLST
                {
                    prRule("N_TERM", "N_FACTOR N_MULTOPLST");
                    assignTypeInfo($$, $1);
                }
                ;
N_TYPE          : N_SIMPLE
                {
                    prRule("N_TYPE", "N_SIMPLE");
                    assignTypeInfo($$, $1);
                }
                | N_ARRAY
                {
                    prRule("N_TYPE", "N_ARRAY");
                    assignTypeInfo($$, $1);
                }
                ;
N_VARDEC        : N_IDENT N_IDENTLST T_COLON N_TYPE
                {   
                    prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
                    identList.push_front(string($1));
                    for (list<string>::iterator it = identList.begin(); it != identList.end(); ++it) {
                        $4.nestingLevel = staticNestingLevel;
                        if (procStack.empty()) {
                            $4.offset = 20 + offset;
                        } else {
                            $4.offset = offset;
                        }
                        nextOffset($4, offset);
                        addToSymbolTable(*it, $4);
                    }
                    identList.clear();
                }
                ;
N_VARDECLST     : /* epsilon */
                {
                    prRule("N_VARDECLST", "epsilon");
                }
                | N_VARDEC T_SCOLON N_VARDECLST
                {
                    prRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
                }
                ;
N_VARDECPART    : /* epsilon */
                {
                    prRule("N_VARDECPART", "epsilon");
                }
                | T_VAR N_VARDEC T_SCOLON N_VARDECLST
                {
                    prRule("N_VARDECPART", "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
                }
                ;
N_VARIABLE      : N_ENTIREVAR
                {
                    prRule("N_VARIABLE", "N_ENTIREVAR");
                    //Again, have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an integer couldn't be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string($1));
                        it ++;
                    }
                    if (info.type == NOT_FOUND) {
                        yyerror("? shouldn't get here 2");
                    }
                    $$ = info;

                    stringstream ss;
                    ss << info.offset << ", " << info.nestingLevel - 1;
                    printOpCodeSingleAddr("la", getStr(ss));
                }
                | N_IDXVAR
                {
                    prRule("N_VARIABLE", "N_IDXVAR");
                    $$ = $1;
                }
                ;
N_VARIDENT      : T_IDENT
                {
                    prRule("N_VARIDENT", "T_IDENT");
                    if (!checkSymbolTables($1)) {
                        yyerror("Undefined identifier");
                    }
                    $$ = $1;
                }
                ;
N_WHILE         : T_WHILE 
                {
                    whileLabelPairs.push(make_pair(genLabelNum(), genLabelNum()));
                    printLabel(whileLabelPairs.top().first);
                }
                N_EXPR
                {
                    if ($3.type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                    stringstream ss;
                    ss << "L." <<whileLabelPairs.top().second;
                    printOpCodeSingleAddr("jf", getStr(ss));
                }
                T_DO N_STMT
                {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                    stringstream ss;
                    ss << "L." << whileLabelPairs.top().first;
                    printOpCodeSingleAddr("jp", getStr(ss));
                    printLabel(whileLabelPairs.top().second);
                    whileLabelPairs.pop();
                }
                ;
N_WRITE         : T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN
                {
                    if ($3.type != INT && $3.type != CHAR)
                        yyerror("Output expression must be of type integer or char");
                    prRule("N_WRITE", "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
                }
                ;
%%

#include "lex.yy.c"
extern FILE *yyin;


void prRule(const char *lhs, const char *rhs) {
  if (OUTPUT_PRODUCTIONS)
    printf("%s -> %s\n", lhs, rhs);
  return;
}

void printLabel(int labelNum) {
    cout << "L." << labelNum << ":" << endl;
}

void printOpCode(string opCode) {
    cout << "\t" << opCode << endl;
}

void printOpCodeSingleAddr(string opCode, string addr) {
    cout << "\t" << opCode << " " << addr << endl;
}

void printOpCodeDoubleAddr(string opCode, string addr1, string addr2) {
    cout << "\t" << opCode << " " << addr1 << ", " << addr2 << endl;
}

int yyerror(const char *s) {
  if (OUTPUT_ERRORS)
    printf("Line %d: %s\n", lineNum, s);
  exit(1);
}

int ckInt() {
  char *ptr;
  int	rc = 0;
  ptr = yytext;

  /* ignore sign and leading zeroes */
  if (*ptr == '-' || *ptr == '+')
    ++ptr;
  while (*ptr == '0')
    ++ptr;

  switch (*ptr) {
  case '1':	/* ALL are valid */
			break;

  case '2':	/* it depends */
			if (strcmp(MAX_INT, ptr) < 0)
				rc = 1;
			break;

  default:	     /* ALL are invalid */
			rc = 1;
			break;
		}
  return rc;
}

void ignoreComment() {
  char c, pc = 0;

  /* read and ignore the input until you get an ending token */
  while (((c = yyinput()) != ')' || pc != '*') && c != 0) {
    pc = c;
    if (c == '\n') lineNum++;
  }

  return;
}

string typeInfoOutput(TypeInfo typeInfo) {
    string ret;
    switch (typeInfo.type) {
        case INT:
            ret = "INTEGER";
            break;
        case CHAR:
            ret = "CHAR";
            break;
        case BOOL:
            ret = "BOOLEAN";
            break;
        case PROGRAM:
            ret = "PROGRAM";
            break;
        case PROCEDURE:
            ret = "PROCEDURE";
            break;
        case ARRAY:
            string baseType;
            switch (typeInfo.baseType) {
                case INT:
                    baseType = "INTEGER";
                    break;
                case CHAR:
                    baseType = "CHAR";
                    break;
                case BOOL:
                    baseType = "BOOLEAN";
                    break;
            }
            ret =  "ARRAY " + to_string(typeInfo.startIndex) + " .. " + to_string(typeInfo.endIndex) + " OF " + baseType;
            break;
    }
    return ret;
}

void beginScope() {
    if (OUTPUT_SCOPES)
      printf("\n___Entering new scope...\n\n");
    scopeStack.push_front(SymbolTable());
}

void endScope() {
    if (OUTPUT_SCOPES)
      printf("\n___Exiting scope...\n\n");
    scopeStack.pop_front();
}

bool checkSymbolTables(string ident) {
    list<SymbolTable>::iterator it;
    for (it = scopeStack.begin(); it != scopeStack.end(); ++it) {
        if (it->find(string(ident))) {
            return true;
        }
    }
    return false;
}

TypeInfo getFromSymbolTables(string name) {
    list<SymbolTable>::iterator it;
    TypeInfo info;
    for (it = scopeStack.begin(); it != scopeStack.end(); ++it) {
        info = it->findAndGetEntry(name);
        if (info.type != NOT_FOUND) {
            return info;
        }
    }
    return info;
}

void addToSymbolTable(string name, TypeInfo typeInfo) {
    if (OUTPUT_ADDSYMBOLS)
        printf("___Adding %s to symbol table with type %s\n", name.c_str(), typeInfoOutput(typeInfo).c_str());
    if (!scopeStack.front().add(name, typeInfo)) {
        yyerror("Multiply defined identifier");
    }
}

void printTokenInfo(const char* tokenType, const char* lexeme) {
  if (OUTPUT_TOKENS)
    printf("TOKEN: %-15s  LEXEME: %s\n", tokenType, lexeme);
}

void assignTypeInfo(TypeInfo& t1, TypeInfo& t2) {
    t1.type = t2.type;
    t1.startIndex = t2.startIndex;
    t1.endIndex = t2.endIndex;
    t1.baseType = t2.baseType;
}

int genLabelNum() {
    static int labelNum = 0;
    return labelNum++;
}

string getStr(stringstream& ss) {
    string s = ss.str();
    ss.str(string());
    return s;
}

void nextOffset(const TypeInfo& info, int& offset) {
    switch (info.type) {
        case INT:
        case BOOL:
        case CHAR:
            offset++;
            break;
        case ARRAY:
            // distance between indices and then +1 because indices are inclusive
            offset += abs(info.startIndex - info.endIndex) + 1; 
            break;
        default:
            break;
    }
}


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("You must specify a file in the command line!\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");
    do {
        yyparse();
    } while (!feof(yyin));
    return 0;
}


