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

void ignoreComment();
int ckInt();
void prRule(const char*, const char*);
std::string typeInfoOutput(TypeInfo typeInfo);
bool checkSymbolTables(std::string ident);
void printTokenInfo(const char* tokenType, const char* lexeme);
void addToSymbolTable(std::string name, TypeInfo typeInfo);
void beginScope();
void endScope();

int yyerror(const char*);

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}

#define MAX_INT	"2147483647"

#define OUTPUT_TOKENS 0
#define OUTPUT_PRODUCTIONS 0

// constants for logical or arithmetic operators for type checking
#define LOGICAL_OP 100
#define ARITHMETIC_OP 101

int lineNum = 1; // source line number

std::list<SymbolTable> scopeStack;
std::list<std::string> identList;
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

%type<num> N_IDX N_INTCONST T_INTCONST T_INT N_ADDOP N_MULTOP
%type<text> T_IDENT N_IDENT N_PROCIDENT N_SIGN T_PLUS T_MINUS
%type<typeInfo> N_SIMPLE N_TYPE N_ARRAY N_IDXRANGE 

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
                    printf("\n---- Completed parsing ----\n\n");
                    return 0;
                }
                ;
N_ADDOP         : N_ADDOP_ARITH
                {
                    prRule("N_ADDOP", "N_ADDOP_ARITH";)
                    $$ = ARITHMETIC_OP;
                }
                | N_ADDOP_LOGIC
                {
                    prRule("N_ADDOP", "N_ADDOP_LOGIC");
                    $$ = LOGICAL_OP;
                }
N_ADDOP_ARITH   : T_PLUS
                {
                    prRule("N_ADDOP_ARITH", "T_PLUS");
                }
                | T_MINUS
                {
                    prRule("N_ADDOP_ARITH", "T_MINUS");
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
                }
                ;
N_ASSIGN        : N_VARIABLE T_ASSIGN N_EXPR
                {
                    prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
                }
                ;
N_BLOCK         : N_VARDECPART N_PROCDECPART N_STMTPART
                {
                    prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
                    endScope();
                }
                ;
N_BOOLCONST     : T_TRUE
                {
                    prRule("N_BOOLCONST", "T_TRUE");
                }
                | T_FALSE
                {
                    prRule("N_BOOLCONST", "T_FALSE");
                }
                ;
N_COMPOUND      : T_BEGIN N_STMT N_STMTLST T_END
                {
                    prRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
                }
                ;
N_CONDITION     : T_IF N_EXPR T_THEN N_STMT
                {
                    prRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
                }
                | T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT
                {
                    prRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
                }
                ;
N_CONST         : N_INTCONST
                {
                    prRule("N_CONST", "N_INTCONST");
                }
                | T_CHARCONST
                {
                    prRule("N_CONST", "T_CHARCONST");
                }
                | N_BOOLCONST
                {
                    prRule("N_CONST", "N_BOOLCONST");
                }
                ;
N_ENTIREVAR     : N_VARIDENT
                {
                    prRule("N_ENTIREVAR", "N_VARIDENT");
                }
                ;
N_EXPR          : N_SIMPLEEXPR
                {
                    prRule("N_EXPR", "N_SIMPLEEXPR");
                }
                | N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR
                {
                    prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
                }
                ;
N_FACTOR        : N_SIGN N_VARIABLE
                {
                    prRule("N_FACTOR", "N_SIGN N_VARIABLE");
                }
                | N_CONST
                {
                    prRule("N_FACTOR", "N_CONST");
                }
                | T_LPAREN N_EXPR T_RPAREN
                {
                    prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
                }
                | T_NOT N_FACTOR
                {
                    prRule("N_FACTOR", "T_NOT N_FACTOR");
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
                    identList.push_front(std::string($2));
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
                    $$.type = NOT_APPLICABLE;
                    $$.startIndex = $1;
                    $$.endIndex = $3;
                    $$.baseType = NOT_APPLICABLE;
                }
                ;
N_IDXVAR        : N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK
                {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
                    if ($1.type != ARRAY) {
                        yyerror()
                    }
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
                    $$ = ARITHMETIC_OP;
                }
                | N_MULTOP_LOGIC
                {
                    prRule("N_MULTOP", "N_MULTOP_LOGIC")
                    $$ = LOGICAL_OP;
                }
                ;
N_MULTOP_ARITH  : T_MULT
                {
                    prRule("N_MULTOP_ARITH", "T_MULT");
                }
                | T_DIV
                {
                    prRule("N_MULTOP_ARITH", "T_DIV");
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
                }
                ;
N_OUTPUT        : N_EXPR
                {
                    prRule("N_OUTPUT", "N_EXPR");
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
N_PROCDEC       : N_PROCHDR N_BLOCK
                {
                    prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
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
                        addToSymbolTable($2, info);
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
                    prRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
                }
                ;
N_RELOP         : T_LT
                {
                    prRule("N_RELOP", "T_LT");
                }
                | T_GT
                {
                    prRule("N_RELOP", "T_GT");
                }
                | T_LE
                {
                    prRule("N_RELOP", "T_LE");
                }
                | T_GE
                {
                    prRule("N_RELOP", "T_GE");
                }   
                | T_EQ
                {
                    prRule("N_RELOP", "T_EQ");
                }
                | T_NE
                {
                    prRule("N_RELOP", "T_NE");
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
                }
                ;
N_TYPE          : N_SIMPLE
                {
                    prRule("N_TYPE", "N_SIMPLE");
                    $$ = $1;
                }
                | N_ARRAY
                {
                    prRule("N_TYPE", "N_ARRAY");
                    $$ = $1;
                }
                ;
N_VARDEC        : N_IDENT N_IDENTLST T_COLON N_TYPE
                {   
                    prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
                    identList.push_front(std::string($1));
                    for (std::list<std::string>::iterator it = identList.begin(); it != identList.end(); ++it) {
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
                }
                | N_IDXVAR
                {
                    prRule("N_VARIABLE", "N_IDXVAR");
                }
                ;
N_VARIDENT      : T_IDENT
                {
                    prRule("N_VARIDENT", "T_IDENT");
                    if (!checkSymbolTables($1)) {
                        yyerror("Undefined identifier");
                    }
                }
                ;
N_WHILE         : T_WHILE N_EXPR T_DO N_STMT
                {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                }
                ;
N_WRITE         : T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN
                {
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

int yyerror(const char *s) {
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

std::string typeInfoOutput(TypeInfo typeInfo) {
    std::string ret;
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
            std::string baseType;
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
            ret =  "ARRAY " + std::to_string(typeInfo.startIndex) + " .. " + std::to_string(typeInfo.endIndex) + " OF " + baseType;
            break;
    }
    return ret;
}

void beginScope() {
    printf("\n___Entering new scope...\n\n");
    scopeStack.push_front(SymbolTable());
}

void endScope() {
    printf("\n___Exiting scope...\n\n");
    scopeStack.pop_front();
}

bool checkSymbolTables(std::string ident) {
    std::list<SymbolTable>::iterator it;
    for (it = scopeStack.begin(); it != scopeStack.end(); ++it) {
        if (it->find(std::string(ident))) {
            return true;
        }
    }
    return false;
}

void addToSymbolTable(std::string name, TypeInfo typeInfo) {
    printf("___Adding %s to symbol table with type %s\n", name.c_str(), typeInfoOutput(typeInfo).c_str());
    if (!scopeStack.front().add(name, typeInfo)) {
        yyerror("Multiply defined identifier");
    }
}

void printTokenInfo(const char* tokenType, const char* lexeme) {
  if (OUTPUT_TOKENS)
    printf("TOKEN: %-15s  LEXEME: %s\n", tokenType, lexeme);
}

int main() {
  // loop as long as there is anything to parse
  do {
    yyparse();
  } while (!feof(yyin));

  return 0;
}


