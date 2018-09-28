/*
 *  bison specifications for the MIPL language.
 *  Written to meet requirements for CS 5500, Fall 2018.
 */

/*
 *  Declaration section.
 */
%{

#   include <stdio.h>
#   include <ctype.h>

void	ignoreComment();
int ckInt();
void  prRule(const char*, const char*);
void printTokenInfo(const char* tokenType, 
                    const char* lexeme);

int yyerror(const char*);

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}

#define MAX_INT	"2147483647"

#define OUTPUT_TOKENS	     1
#define OUTPUT_PRODUCTIONS 1

int lineNum = 1;                   // source line number

%}

/*
 *  Token declaration. 'N_...' for rules, 'T_...' for tokens.
 *  Note: tokens are also used in the flex specification file.
 */
%token      T_LPAREN    T_RPAREN    T_MULT	     T_PLUS
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
N_ADDOP         : T_PLUS
                    {
                    prRule("N_ADDOP", "T_PLUS");
                    }
                | T_MINUS
                    {
                    prRule("N_ADDOP", "T_MINUS");
                    }
                | T_OR
                    {
                    prRule("N_ADDOP", "T_OR");
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
                    prRule("N_ARRAY",
                        "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
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
                    prRule("N_CONDITION",
                        "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
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
                    }
                ;
N_IDENTLST      : /* epsilon */
                    {
                    prRule("N_IDENTLST", "epsilon");
                    }
                | T_COMMA N_IDENT N_IDENTLST
                    {
                    prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
                    }
                ;
N_IDX           : N_INTCONST
                    {
                    prRule("N_IDX", "N_INTCONST");
                    }
                ;
N_IDXRANGE      : N_IDX T_DOTDOT N_IDX
                    {
                    prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
                    }
                ;
N_IDXVAR        : N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK
                    {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
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
                    }
                ;
N_MULTOP        : T_MULT
                    {
                    prRule("N_MULTOP", "T_MULT");
                    }
                | T_DIV
                    {
                    prRule("N_MULTOP", "T_DIV");
                    }
                | T_AND
                    {
                    prRule("N_MULTOP", "T_AND");
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
                    }
                ;
N_PROCDECPART   : /* epsilon */
                    {
                    prRule("N_PROCDECPART", "epsilon");
                    }
                | N_PROCDEC T_SCOLON N_PROCDECPART
                    {
                    prRule("N_PROCDECPART",
                        "N_PROCDEC T_SCOLON N_PROCDECPART");
                    }
                ;
N_PROCIDENT     : T_IDENT
                    {
                    prRule("N_PROCIDENT", "T_IDENT");
                    }
                ;
N_PROCSTMT      : N_PROCIDENT
                    {
                    prRule("N_PROCSTMT", "N_PROCIDENT");
                    }
                ;
N_PROG          : N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT
                    {
                    prRule("N_PROG",
                        "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
                    }
                ;
N_PROGLBL       : T_PROG
                    {
                    prRule("N_PROGLBL", "T_PROG");
                    }
                ;
N_READ          : T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN
                    {
                    prRule("N_READ",
                        "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
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
                    }
                | T_PLUS
                    {
                    prRule("N_SIGN", "T_PLUS");
                    }
                | T_MINUS
                    {
                    prRule("N_SIGN", "T_MINUS");
                    }
                ;
N_SIMPLE        : T_INT
                    {
                    prRule("N_SIMPLE", "T_INT");
                    }
                | T_CHAR
                    {
                    prRule("N_SIMPLE", "T_CHAR");
                    }
                | T_BOOL
                    {
                    prRule("N_SIMPLE", "T_BOOL");
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
                    }
                | N_ARRAY
                    {
                    prRule("N_TYPE", "N_ARRAY");
                    }
                ;
N_VARDEC        : N_IDENT N_IDENTLST T_COLON N_TYPE
                    {
                    prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
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
                    prRule("N_VARDECPART",
                        "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
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
                    }
                ;
N_WHILE         : T_WHILE N_EXPR T_DO N_STMT
                    {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                    }
                ;
N_WRITE         : T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN
                    {
                    prRule("N_WRITE",
                        "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
                    }
                ;
%%

#include "lex.yy.c"
extern FILE *yyin;


void prRule(const char *lhs, const char *rhs) 
{
  if (OUTPUT_PRODUCTIONS)
    printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s) 
{
  printf("Line %d: %s\n", lineNum, s);
  exit(1);
}

int ckInt() 
{
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

void ignoreComment() 
{
  char c, pc = 0;

  /* read and ignore the input until you get an ending token */
  while (((c = yyinput()) != ')' || pc != '*') && c != 0) {
    pc = c;
    if (c == '\n') lineNum++;
  }

  return;
}

void printTokenInfo(const char* tokenType, const char* lexeme) 
{
  if (OUTPUT_TOKENS)
    printf("TOKEN: %-15s  LEXEME: %s\n", tokenType, lexeme);
}

int main()
{
  // loop as long as there is anything to parse
  do {
    yyparse();
  } while (!feof(yyin));

  return 0;
}


