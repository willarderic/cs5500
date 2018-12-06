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
#include <iostream>
#include <sstream>
#include <stack>

#include "SymbolTable.h"
#include "instructions.h"
#include "registers.h"

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
string getStr(stringstream& ss);
TypeInfo getFromSymbolTables(string name);
void allocateVariable(TypeInfo& info);
void deallocateVariables(std::unordered_map<std::string, TypeInfo> symbolTable);
int yyerror(const char*);

// Printing functions
void globalVarDec(string ident, TypeInfo info);
void printInstruction(Instruction instrx);
void printRegister(Register reg);

// Functions for emitting instructions based on addressing mode
void emitGlobalSym(Instruction instrx, string ident, Register reg);
void emitImmediate(Instruction instrx, int value, Register reg);
void emitRegister(Instruction instrx, Register reg1, Register reg2);
void emitIndirect(Instruction instrx, Register reg1, Register reg2);
void emitBaseRelative(Instruction instrx, int constant, Register reg1, Register reg2);
void emitOffsetBaseRelative(Instruction instrx, int constant, int offset, Register reg1, Register reg2, Register reg3);
void emitBaseRelativeReverse(Instruction instrx, Register reg1, int constant, Register reg2);
void emitJump(Instruction instrx, int labelNum);
void emitCall(const char* func);
void emitRet();

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

// All variables get 8 bytes allocated for them
#define VAR_SIZE 8

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
list<TypeInfo> addList, multList;
list<int> addOpList, multOpList;

stack<pair<string, TypeInfo> > procStack;
stack<int> procedureCodeLabelNums;
int globalsLabelNum, stackLabelNum, codeLabelNum, entryPointLabelNum;
int blockLevel = 0;
bool inIf, inWhile;
int stackOffset = 1;

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

%type<num> N_IDX N_INTCONST T_INTCONST T_INT N_ADDOP N_MULTOP N_ADDOP_ARITH N_MULTOP_ARITH N_RELOP N_BOOLCONST
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
                    
                    // Claim the memory for the character buffer back from the stack
                    emitImmediate(ADDQ, 8, RSP);
                    // Assembly code to gracefully shutdown the program
                    emitImmediate(MOVQ, 60, RAX);
                    emitRegister(XOR, RDI, RDI);
                    printf("\tsyscall\n");
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
                | N_ADDOP N_TERM N_ADDOPLST
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
                    addList.push_front($2);
                    addOpList.push_front($1);
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
                    if ($1.type == ARRAY) {
                        yyerror("Cannot make assignment to an array");
                    }
                    if ($1.type != $3.type)
                    {
                      if ($1.type == PROCEDURE || $3.type == PROCEDURE) {
                          yyerror("Procedure/variable mismatch");
                      }
                      yyerror("Expression must be of same type as variable");
                    }
                    prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");  
                    emitBaseRelativeReverse(MOVQ, RAX, $1.offset, RBP);
                }
                ;
N_BLOCK         :
                {
                    // Start the data section of the assembly code
                    if (procStack.empty()) {
                        // directive to let the assembler know everything below this is executable code
                        printf("\t.text\n");
                        // program start point
                        printf("_start:\n");
                        // Initialize base pointer so that we can store variables in it
                        printf("\tpushq\t%%rbp\n");
                        emitRegister(MOVQ, RSP, RBP);
                        emitImmediate(SUBQ, 8, RSP);
                        stackOffset++;
                    }
                }
                N_VARDECPART
                {
                    if (procStack.empty()) {
                        codeLabelNum = genLabelNum();
                        emitJump(JMP, codeLabelNum);
                    } else {
                        procStack.top().second.frameSize = scopeStack.front().frameSize();
                        SymbolTable front = scopeStack.front();
                        scopeStack.pop_front();
                        addToSymbolTable(procStack.top().first, procStack.top().second);
                        scopeStack.push_front(front);

                        // Put jump here to the stmtpart of the procedure because the procedures who are inside
                        // this procedure will have their code between here and that part
                        procedureCodeLabelNums.push(genLabelNum());
                        emitJump(JMP, procedureCodeLabelNums.top());
                    }
                }
                N_PROCDECPART
                {
                    // label for start of execution
                    if (procStack.empty()) {
                        printLabel(codeLabelNum);
                    } else {
                        printLabel(procedureCodeLabelNums.top());
                        procedureCodeLabelNums.pop();
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
                    $$ = 1;
                }
                | T_FALSE
                {
                    prRule("N_BOOLCONST", "T_FALSE");
                    $$ = 0;
                }
                ;
N_COMPOUND      : T_BEGIN 
                {
                    blockLevel++;
                }
                N_STMT N_STMTLST T_END
                {
                    prRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
                    blockLevel--;
                    if (!procStack.empty() && blockLevel == 0) {
                        procStack.pop();
                    }
                }
                ;
N_CONDITION     : T_IF
                {
                    inIf = true;
                    elseLabelNum.push(genLabelNum());
                }
                N_EXPR 
                {
                    prRule("N_CONDITION", "T_IF N_EXPR");
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
                    printLabel(elseLabelNum.top());
                    elseLabelNum.pop();
                }
                | T_THEN N_STMT T_ELSE
                {
                    postConditionalLabelNum.push(genLabelNum());
                    emitJump(JMP, postConditionalLabelNum.top());
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
                    $$.label = NULL;
                    $$.nestingLevel = NOT_APPLICABLE;
                    $$.frameSize = NOT_APPLICABLE;
                    $$.offset = NOT_APPLICABLE;
                    $$.value = $1;
                }
                | T_CHARCONST
                {
                    prRule("N_CONST", "T_CHARCONST");
                    $$.type = CHAR;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    $$.label = NULL;
                    $$.nestingLevel = NOT_APPLICABLE;
                    $$.frameSize = NOT_APPLICABLE;
                    $$.offset = NOT_APPLICABLE;
                    $$.value = int($1[1]);
                    
                }
                | N_BOOLCONST
                {
                    prRule("N_CONST", "N_BOOLCONST");
                    $$.type = BOOL;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    $$.label = NULL;
                    $$.nestingLevel = NOT_APPLICABLE;
                    $$.frameSize = NOT_APPLICABLE;
                    $$.offset = NOT_APPLICABLE;
                    $$.value = $1;
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
                | N_SIMPLEEXPR N_RELOP
                {
                    // move what is in rax to rcx/rdx so that rax can be used for the next expression calculation
                    if (inWhile) {
                        emitRegister(MOVQ, RAX, RCX);
                    } else if (inIf) {
                        emitRegister(MOVQ, RAX, RDX);
                    }
                }
                N_SIMPLEEXPR
                {
                    prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
                    if ($1.type != $4.type) {
                        yyerror("Expressions must both be int, or both char, or both boolean");
                    }
                    $$.type = BOOL;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    $$.nestingLevel = NOT_APPLICABLE;
                    $$.frameSize = NOT_APPLICABLE;
                    $$.offset = NOT_APPLICABLE;
                    $$.value = NOT_APPLICABLE;
                    
                    
                    if (inWhile && !whileLabelPairs.empty()) {
                        emitRegister(CMPQ, RAX, RCX);
                        // reverse the jump from the operator because we only jump if its false
                        switch ($2) {
                            case LE:
                                emitJump(JG, whileLabelPairs.top().second);
                                break;
                            case GE:
                                emitJump(JL, whileLabelPairs.top().second);
                                break;
                            case EQ:
                                emitJump(JNE, whileLabelPairs.top().second);
                                break;
                            case NE:
                                emitJump(JE, whileLabelPairs.top().second);
                                break;
                            case LT:
                                emitJump(JGE, whileLabelPairs.top().second);
                                break;
                            case GT:
                                emitJump(JLE, whileLabelPairs.top().second);
                                break;
                        }
                        inWhile = false;
                    }
                    if (inIf) {
                        emitRegister(CMPQ, RAX, RDX);
                        // reverse the comparison conditions so that we can jump to the else code if it is false
                        switch ($2) {
                            case LE:
                                emitJump(JG, elseLabelNum.top());
                                break;
                            case GE:
                                emitJump(JL, elseLabelNum.top());
                                break;
                            case EQ:
                                emitJump(JNE, elseLabelNum.top());
                                break;
                            case NE:
                                emitJump(JE, elseLabelNum.top());
                                break;
                            case LT:
                                emitJump(JGE, elseLabelNum.top());
                                break;
                            case GT:
                                emitJump(JLE, elseLabelNum.top());
                                break;
                        }
                        inIf = false;
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
N_IDXVAR        : N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK
                {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
                    //Have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an array was not able to be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NULL,NOT_APPLICABLE,NOT_APPLICABLE};
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
                    if ($3.type != INT) {
                        if ($3.type == PROCEDURE)
                            yyerror("Procedure/variable mismatch");
                        yyerror("Index expression must be of type integer");
                    }
                    // int size = abs(info.startIndex - info.endIndex) + 1;
                    // int arrayOffset = info.startIndex;
                    // emitImmediate(SUBQ, arrayOffset, RAX);
                    // emitImmediate(IMULQ, VAR_SIZE, RAX);
                    // emitRegister(MOVQ, RAX, RBX);
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
                | N_MULTOP N_FACTOR N_MULTOPLST
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
                    multList.push_front($2);
                    multOpList.push_front($1);
                }
                ;
N_OUTPUT        : N_EXPR
                {
                    prRule("N_OUTPUT", "N_EXPR");
                    $$ = $1;
                    if ($1.type == INT) {
                        int loopLabel = genLabelNum();
                        emitImmediate(CMPQ, 0, RAX);
                        emitJump(JGE, loopLabel);

                        // Print out a negative sign if the integer is less than 0
                        emitRegister(MOVQ, RAX, R9);
                        printf("\tmovq\t$\'-\', -8(%%rbp)\n");
                        emitBaseRelative(LEA, -8, RBP, RSI);
                        emitImmediate(MOVQ, 1, RAX);
                        emitImmediate(MOVQ, 1, RDX);
                        printf("\tsyscall\n");
                        emitRegister(MOVQ, R9, RAX);
                        // negate the number 
                        printf("\tneg\t %%rax\n");

                        // print an integer in rax digit by digit
                        emitImmediate(MOVQ, 10, RCX);
                        printLabel(loopLabel);
                        emitRegister(XOR, RDX, RDX);
                        printf("\tidivq\t%%rcx\n");
                        printf("\taddq\t$\'0\', %%rdx\n");
                        emitBaseRelativeReverse(MOVQ, RDX, -8, RBP);
                        emitBaseRelative(LEA, -8, RBP, RSI);
                        emitRegister(MOVQ, RAX, R9);
                        emitImmediate(MOVQ, 1, RAX);
                        emitImmediate(MOVQ, 1, RDX);
                        printf("\tsyscall\n");
                        emitRegister(MOVQ, R9, RAX);
                        emitImmediate(CMPQ, 0, RAX);
                        emitJump(JNZ, loopLabel);
                    } else if ($1.type == CHAR) {
                        emitBaseRelativeReverse(MOVQ, RAX, -8, RBP);
                        emitBaseRelative(LEA, -8, RBP, RSI);
                        emitImmediate(MOVQ, 1, RAX);
                        emitImmediate(MOVQ, 1, RDX);
                        printf("\tsyscall\n");
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
                    emitRet();
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
                    info.label = strdup($2);
                    procStack.push(make_pair(string($2), info));
                    printf("%s:\n", info.label);
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
                    $$ = strdup($1);
                }
                ;
N_PROCSTMT      : N_PROCIDENT
                {
                    prRule("N_PROCSTMT", "N_PROCIDENT");
                    TypeInfo info = getFromSymbolTables(string($1));
                    int callerNestingLevel = staticNestingLevel - 1;
                    if (info.type == PROCEDURE) {
                        emitCall(info.label);
                    } else if (info.type == NOT_FOUND) {
                        yyerror("Procedure not found");
                    } else {
                        yyerror("Cannot call non-procedure");
                    }
                }
                ;
N_PROG          : N_PROGLBL T_IDENT T_SCOLON
                {
                    prRule("N_PROG","N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
                    TypeInfo info;
                    info.type = PROGRAM;
                    info.startIndex = NOT_APPLICABLE;
                    info.endIndex = NOT_APPLICABLE;
                    info.baseType = NOT_APPLICABLE;
                    addToSymbolTable($2, info);

                    // global declaration for what part of the assembly to start execution
                    printf("\t.global _start\n");
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
                    $$.label = NULL;
                    $$.nestingLevel = NOT_APPLICABLE;
                    $$.frameSize = NOT_APPLICABLE;
                    $$.offset = NOT_APPLICABLE;
                    $$.value = NOT_APPLICABLE;
                }
                | T_CHAR
                {
                    prRule("N_SIMPLE", "T_CHAR");
                    $$.type = CHAR;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    $$.label = NULL;
                    $$.nestingLevel = NOT_APPLICABLE;
                    $$.frameSize = NOT_APPLICABLE;
                    $$.offset = NOT_APPLICABLE;
                    $$.value = NOT_APPLICABLE;
                }
                | T_BOOL
                {
                    prRule("N_SIMPLE", "T_BOOL");
                    $$.type = BOOL;
                    $$.startIndex = NOT_APPLICABLE;
                    $$.endIndex = NOT_APPLICABLE;
                    $$.baseType = NOT_APPLICABLE;
                    $$.label = NULL;
                    $$.nestingLevel = NOT_APPLICABLE;
                    $$.frameSize = NOT_APPLICABLE;
                    $$.offset = NOT_APPLICABLE;
                    $$.value = NOT_APPLICABLE;
                }
                ;
N_SIMPLEEXPR    : N_TERM N_ADDOPLST
                {
                    prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
                    assignTypeInfo($$, $1);
                    addList.push_front($1);
                    list<TypeInfo>::iterator it;
                    list<int>::iterator opIt;
                    
                    bool emitting = true;

                    // If one of these is empty than it means that we are not doing any add operations
                    if (!addList.empty() && !addOpList.empty()) {
                        TypeInfo info = addList.front();
                        addList.pop_front();
                        if (info.offset == NOT_APPLICABLE) {
                            emitImmediate(MOVQ, info.value, RAX);
                        } else {
                            emitBaseRelative(MOVQ, info.offset, RBP, RAX);
                        }

                        // Store all the add operators and offsets in the addlist and addoplist
                        // Then emit them all here to make sure it follows Order of operations

                        while (emitting) {
                            info = addList.front();
                            addList.pop_front();
                            int op = addOpList.front();
                            addOpList.pop_front();
                            switch (op) {
                                case PLUS_OP:
                                    if (info.offset == NOT_APPLICABLE) {
                                        emitImmediate(ADDQ, info.value, RAX);
                                    } else {
                                        emitBaseRelative(ADDQ, info.offset, RBP, RAX);
                                    }
                                    break;
                                case MINUS_OP:
                                    if (info.offset == NOT_APPLICABLE) {
                                        emitImmediate(SUBQ, info.value, RAX);
                                    } else {
                                        emitBaseRelative(SUBQ, info.offset, RBP, RAX);
                                    }
                                    break;
                                case LOGICAL_OP:
                                    if (info.offset == NOT_APPLICABLE) {
                                        emitImmediate(OR, info.value, RAX);
                                    } else {
                                        emitBaseRelative(OR, info.offset, RBP, RAX);
                                    }
                                    break;
                            }
                            if (addList.empty() || addOpList.empty()) {
                                emitting = false;
                            }
                        }
                    } else  {
                        // If the addlist/multList have something in them but no operators are present,
                        // then this must be some other operation involving expr (i.e. assign, etc)
                        if ((addOpList.empty() && !addList.empty()) && (multOpList.empty() && !multList.empty())) {
                            if ($1.offset == NOT_APPLICABLE) {
                                emitImmediate(MOVQ, $1.value, RAX);
                            } else {
                                emitBaseRelative(MOVQ, $1.offset, RBP, RAX);
                            }
                        }
                    }
                    addList.clear();
                    addOpList.clear();
                    multList.clear();
                    multOpList.clear();
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
                    multList.push_front($1);
                    list<TypeInfo>::iterator it;
                    list<int>::iterator opIt;
                    bool emitting = true;

                    // If one of these is empty than it means that we are not doing any add operations
                    if (!multList.empty() && !multOpList.empty()) {
                        TypeInfo info = multList.front();
                        multList.pop_front();
                        if (info.offset == NOT_APPLICABLE) {
                            emitImmediate(MOVQ, info.value, RAX);
                        } else {
                            emitBaseRelative(MOVQ, info.offset, RBP, RAX);
                        }

                        // Store all the add operators and offsets in the multList and multoplist
                        // Then emit them all here to make sure it follows Order of operations

                        while (emitting) {
                            info = multList.front();
                            multList.pop_front();
                            int op = multOpList.front();
                            multOpList.pop_front();
                            switch (op) {
                                case MULT_OP:
                                    if (info.offset == NOT_APPLICABLE) {
                                        emitImmediate(IMULQ, info.value, RAX);
                                    } else {
                                        emitBaseRelative(IMULQ, info.offset, RBP, RAX);
                                    }
                                    break;
                                case DIV_OP:
                                    if (info.offset == NOT_APPLICABLE) {
                                        emitImmediate(IDIVQ, info.value, RAX);
                                    } else {
                                        emitBaseRelative(IDIVQ, info.offset, RBP, RAX);
                                    }
                                    break;
                                case LOGICAL_OP:
                                    if (info.offset == NOT_APPLICABLE) {
                                        emitImmediate(AND, info.value, RAX);
                                    } else {
                                        emitBaseRelative(AND, info.offset, RBP, RAX);
                                    }
                                    break;
                            }
                            if (multList.empty() || multOpList.empty()) {
                                emitting = false;
                            }
                        }
                    }
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
                        allocateVariable($4);
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
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NULL,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string($1));
                        it ++;
                    }
                    if (info.type == NOT_FOUND) {
                        yyerror("? shouldn't get here 2");
                    }
                    $$ = info;
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
                    inWhile = true;
                }
                N_EXPR
                {
                    if ($3.type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                }
                T_DO N_STMT
                {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                    emitJump(JMP, whileLabelPairs.top().first);
                    printLabel(whileLabelPairs.top().second);
                    whileLabelPairs.pop();
                }
                ;
N_WRITE         : T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN
                {
                    if ($3.type != INT && $3.type != CHAR) {
                        yyerror("Output expression must be of type integer or char");
                    }
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
    cout << "L" << labelNum << ":" << endl;
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
    deallocateVariables(scopeStack.front().getAllEntries());
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
    t1.nestingLevel = t2.nestingLevel;
    if (t2.label == NULL) {
        t1.label = NULL;
    } else {
        t1.label = strdup(t2.label);
    }
    t1.frameSize = t2.frameSize;
    t1.offset = t2.offset;
    t1.value = t2.value;
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

/********* FUNCTIONS ADDED FOR PROJECT ***********/

void allocateVariable(TypeInfo& info) {
    int arraySize = 0;
    switch (info.type) {
        case INT:
        case BOOL:
        case CHAR:
            // store where the allocated memory for this variable is on the stack
            // Store as a negative number because the stack grows downward
            // Access by -offset(%rbp)
            info.offset = -(stackOffset * VAR_SIZE);
            emitImmediate(SUBQ, VAR_SIZE, RSP);
            stackOffset++;
            break;
        case ARRAY:
            // Store where the start of the memory for the array starts
            arraySize = abs(info.startIndex - info.endIndex) + 1;
            info.offset = -(stackOffset * VAR_SIZE);
            emitImmediate(SUBQ, (arraySize * VAR_SIZE), RSP);
            // distance between indices and then +1 because indices are inclusive
            stackOffset += arraySize;
            break;
        default:
            break;
    }
}

void deallocateVariables(std::unordered_map<std::string, TypeInfo> symbolTable) {
    int arraySize = 0;
    int memorySize = 0;
    std::unordered_map<std::string, TypeInfo>::iterator it;
    for (it = symbolTable.begin(); it != symbolTable.end(); ++it) {
        
        switch (it->second.type) {
            case INT:
            case BOOL:
            case CHAR:
                // printf("%s:\n", it->first.c_str());
                memorySize++;
                stackOffset--;
                break;
            case ARRAY:
                // printf("%s:\n", it->first.c_str());
                arraySize = abs(it->second.startIndex - it->second.endIndex) + 1;
                memorySize += arraySize;
                stackOffset -= arraySize;
                break;
            default:
                break;
        }
    }
    emitImmediate(ADDQ, (memorySize * VAR_SIZE), RSP);
} 

void printInstruction(Instruction instrx) {
    printf("\t");
    switch (instrx) {
        case MOVQ:      printf("movq\t"); break;
        case ADDQ:      printf("addq\t"); break;
        case SUBQ:      printf("subq\t"); break;
        case IMULQ:     printf("imulq\t"); break;
        case IDIVQ:     printf("idivq\t"); break;
        case INCQ:      printf("incq\t"); break;
        case DECQ:      printf("decq\t"); break;
        case AND:       printf("and\t"); break;
        case OR:        printf("or\t"); break;
        case XOR:       printf("xor\t"); break;
        case CMPQ:      printf("cmpq\t"); break;
        case JE:        printf("je\t"); break;
        case JNE:       printf("jne\t"); break;
        case JL:        printf("jl\t"); break;
        case JLE:       printf("jle\t"); break;
        case JG:        printf("jg\t"); break;
        case JGE:       printf("jge\t"); break;
        case JMP:       printf("jmp\t"); break;
        case RET:       printf("ret\t"); break;
        case CALL:      printf("call\t"); break;
        case LEA:       printf("lea\t"); break;
        case JNZ:       printf("jnz\t"); break;
    }
}

void printRegister(Register reg) {
    switch (reg) {
        case RAX:  printf("%%rax"); break;
        case RBX:  printf("%%rbx"); break;
        case RCX:  printf("%%rcx"); break;
        case RDX:  printf("%%rdx"); break;
        case RSI:  printf("%%rsi"); break;
        case RDI:  printf("%%rdi"); break;
        case RBP:  printf("%%rbp"); break;
        case RSP:  printf("%%rsp"); break;
        case R8:   printf("%%r8"); break;
        case R9:   printf("%%r9"); break;
        case R10:  printf("%%r10"); break;
        case R11:  printf("%%r11"); break;
        case R12:  printf("%%r12"); break;
        case R13:  printf("%%r13"); break;
        case R14:  printf("%%r14"); break;
        case R15:  printf("%%r15"); break;
    }
}

void emitGlobalSym(Instruction instrx, string ident, Register reg){}

void emitImmediate(Instruction instrx, int value, Register reg) {
    printInstruction(instrx);
    printf("$%d, ", value);
    printRegister(reg);
    printf("\n");
}

void emitRegister(Instruction instrx, Register reg1, Register reg2){
    printInstruction(instrx);
    printRegister(reg1);
    printf(", ");
    printRegister(reg2);
    printf("\n");
}

void emitIndirect(Instruction instrx, Register reg1, Register reg2){}

void emitBaseRelative(Instruction instrx, int constant, Register reg1, Register reg2) {
    printInstruction(instrx);
    printf("%d(", constant);
    printRegister(reg1);
    printf("), ");
    printRegister(reg2);
    printf("\n");
}
void emitOffsetBaseRelative(Instruction instrx, int constant, int offset, Register reg1, Register reg2, Register reg3){} 

void emitBaseRelativeReverse(Instruction instrx, Register reg1, int constant, Register reg2) {
    printInstruction(instrx);
    printRegister(reg1);
    printf(", ");
    printf("%d(", constant);
    printRegister(reg2);
    printf(")\n");
}

void emitJump(Instruction instrx, int labelNum) {
    printInstruction(instrx);
    printf("L%d\n", labelNum);
}

void emitCall(const char* label) {
    printInstruction(CALL);
    printf("%s\n", label);
}
void emitRet() {
    printInstruction(RET);
    printf("\n\n");
}
/********* END FUNCTIONS ADDED FOR PROJECT ***********/


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