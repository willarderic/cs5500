/* A Bison parser, made by GNU Bison 3.2.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "willardorth.y" /* yacc.c:338  */


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

#line 172 "willardorth.tab.c" /* yacc.c:338  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_LPAREN = 258,
    T_RPAREN = 259,
    T_MULT = 260,
    T_PLUS = 261,
    T_COMMA = 262,
    T_MINUS = 263,
    T_DOT = 264,
    T_DOTDOT = 265,
    T_COLON = 266,
    T_ASSIGN = 267,
    T_SCOLON = 268,
    T_LT = 269,
    T_LE = 270,
    T_NE = 271,
    T_EQ = 272,
    T_GT = 273,
    T_GE = 274,
    T_LBRACK = 275,
    T_RBRACK = 276,
    T_DO = 277,
    T_AND = 278,
    T_ARRAY = 279,
    T_BEGIN = 280,
    T_BOOL = 281,
    T_CHAR = 282,
    T_DIV = 283,
    T_CHARCONST = 284,
    T_INTCONST = 285,
    T_END = 286,
    T_FALSE = 287,
    T_IF = 288,
    T_INT = 289,
    T_NOT = 290,
    T_OF = 291,
    T_OR = 292,
    T_PROC = 293,
    T_PROG = 294,
    T_READ = 295,
    T_TRUE = 296,
    T_IDENT = 297,
    T_VAR = 298,
    T_WHILE = 299,
    T_WRITE = 300,
    T_UNKNOWN = 301,
    ST_EOF = 302,
    T_THEN = 303,
    T_ELSE = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 113 "willardorth.y" /* yacc.c:353  */

    int num;
    char* text;
    TypeInfo typeInfo;

#line 268 "willardorth.tab.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   170,   175,   180,   185,   191,   197,   200,
     216,   225,   231,   246,   259,   277,   246,   292,   297,   304,
     303,   320,   325,   319,   333,   341,   340,   354,   367,   381,
     395,   401,   407,   406,   485,   493,   499,   504,   514,   521,
     524,   530,   536,   548,   584,   587,   592,   599,   609,   614,
     620,   625,   631,   637,   640,   656,   666,   669,   675,   674,
     687,   703,   706,   711,   720,   733,   732,   747,   753,   760,
     765,   770,   775,   780,   785,   792,   796,   801,   807,   820,
     833,   847,   922,   926,   930,   934,   938,   942,   946,   952,
     955,   960,   965,  1026,  1031,  1037,  1051,  1054,  1060,  1063,
    1068,  1085,  1091,  1101,  1107,  1100,  1120
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_LPAREN", "T_RPAREN", "T_MULT",
  "T_PLUS", "T_COMMA", "T_MINUS", "T_DOT", "T_DOTDOT", "T_COLON",
  "T_ASSIGN", "T_SCOLON", "T_LT", "T_LE", "T_NE", "T_EQ", "T_GT", "T_GE",
  "T_LBRACK", "T_RBRACK", "T_DO", "T_AND", "T_ARRAY", "T_BEGIN", "T_BOOL",
  "T_CHAR", "T_DIV", "T_CHARCONST", "T_INTCONST", "T_END", "T_FALSE",
  "T_IF", "T_INT", "T_NOT", "T_OF", "T_OR", "T_PROC", "T_PROG", "T_READ",
  "T_TRUE", "T_IDENT", "T_VAR", "T_WHILE", "T_WRITE", "T_UNKNOWN",
  "ST_EOF", "T_THEN", "T_ELSE", "$accept", "N_START", "N_ADDOP",
  "N_ADDOP_ARITH", "N_ADDOP_LOGIC", "N_ADDOPLST", "N_ARRAY", "N_ARRAYVAR",
  "N_ASSIGN", "N_BLOCK", "$@1", "$@2", "$@3", "N_BOOLCONST", "N_COMPOUND",
  "$@4", "N_CONDITION", "$@5", "$@6", "N_THEN_PART", "$@7", "N_CONST",
  "N_ENTIREVAR", "N_EXPR", "$@8", "N_FACTOR", "N_IDENT", "N_IDENTLST",
  "N_IDX", "N_IDXRANGE", "N_IDXVAR", "N_INPUTLST", "N_INPUTVAR",
  "N_INTCONST", "N_MULTOP", "N_MULTOP_ARITH", "N_MULTOP_LOGIC",
  "N_MULTOPLST", "N_OUTPUT", "N_OUTPUTLST", "N_PROCDEC", "$@9",
  "N_PROCHDR", "N_PROCDECPART", "N_PROCIDENT", "N_PROCSTMT", "N_PROG",
  "$@10", "N_PROGLBL", "N_READ", "N_RELOP", "N_SIGN", "N_SIMPLE",
  "N_SIMPLEEXPR", "N_STMT", "N_STMTLST", "N_STMTPART", "N_TERM", "N_TYPE",
  "N_VARDEC", "N_VARDECLST", "N_VARDECPART", "N_VARIABLE", "N_VARIDENT",
  "N_WHILE", "$@11", "$@12", "N_WRITE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -103

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -26,   -90,    23,   -90,   -16,   -90,    19,   -90,   -90,    30,
       0,   -90,     4,   -90,   -90,    40,    35,    12,     4,    42,
       4,     9,    41,   -90,   -90,    40,    18,    44,   -90,    57,
      12,   -90,    46,   -90,    52,   -90,   -90,   -90,   -90,   -90,
     -90,     4,   -90,   -90,   -90,   -90,   -90,   -90,    21,   -90,
      16,   -90,   -90,    45,    53,   -90,    43,   -90,    72,     5,
     -90,    73,    58,   -90,   -90,   -90,    59,   -90,   -90,   -90,
     -90,    64,    69,   -90,   -90,   -90,    21,    47,   -90,    -1,
      48,    -1,    -1,    -1,    16,    51,    -1,   -90,   -15,    -1,
     -90,   -90,    -1,   -90,   -90,   -90,   -90,    10,   -90,   -20,
      49,    -2,   -90,    77,   -90,   -90,   -90,    78,    65,    64,
     -90,   -90,   -90,    83,   -90,    50,   -90,   -90,   -90,    -1,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,    -1,   -90,   -90,   -90,    48,    84,
      67,    -1,    87,   -90,   -90,   -90,    16,   -90,    10,    -1,
      -2,    77,   -90,    16,    78,   -90,    54,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,    16,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    67,     0,     2,     0,     1,     0,    65,    13,     0,
      98,    66,     0,    14,    38,    39,     0,    61,     0,     0,
      96,     0,     0,    58,    15,    39,     0,     0,    99,     0,
      61,    13,     0,    40,     0,    80,    79,    78,    94,    93,
      95,    96,    60,    62,    59,    19,    91,    16,    75,    97,
       0,    76,    77,     0,     0,    41,     0,    21,     0,    63,
     103,     0,     0,    82,    88,    86,   100,   101,    64,    83,
      84,    89,     0,    30,    87,    85,    75,     0,    47,    75,
       0,    75,    75,    75,     0,     0,    75,    42,     0,    75,
      28,    18,    75,    17,    29,    35,    22,    53,    27,     0,
      31,     8,   102,    44,    46,   104,    55,    56,     0,    89,
      20,    12,    10,     0,    37,     0,    50,    52,    51,    75,
      48,    49,    92,    34,    69,    71,    74,    73,    70,    72,
      32,     5,     6,     7,    75,     3,     4,    81,     0,     0,
       0,    75,     0,    43,    90,    36,     0,    23,    53,    75,
       8,    44,    68,     0,    56,   106,    24,    54,    33,     9,
      45,   105,    57,    25,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   -90,   -90,   -58,   -90,   -90,   -90,    62,
     -90,   -90,   -90,   -90,    63,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -65,   -90,   -89,    76,    71,    24,   -90,
     -90,   -54,   -37,   -40,   -90,   -90,   -90,   -49,   -36,   -52,
     -90,   -90,   -90,    74,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -39,    20,   -43,   -84,     1,   -90,   -27,   -90,    97,
      70,   -90,   -79,   -90,   -90,   -90,   -90,   -90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   134,   135,   136,   137,    38,    62,    63,     9,
      10,    17,    32,    94,    64,    50,    65,    79,   115,   147,
     164,    95,    66,   106,   149,    97,    15,    19,    53,    54,
      67,   139,   103,    98,   119,   120,   121,   122,   107,   142,
      22,    31,    23,    24,    68,    69,     3,     8,     4,    70,
     130,    99,    39,   100,    71,    85,    47,   101,    40,    27,
      28,    13,    72,    73,    74,    81,   140,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   104,    89,   114,   131,    51,   132,    52,    55,    56,
      78,    35,    36,     1,    96,   116,   105,  -102,   108,    37,
     123,   111,   102,     5,   113,  -102,     6,    51,    90,    52,
     148,    91,     7,   117,    92,   133,    55,    56,   118,    11,
      93,    45,    34,    12,    35,    36,    14,    18,    20,    57,
      21,    29,    37,    26,    30,    76,    58,    41,    59,   104,
      60,    61,   156,   124,   125,   126,   127,   128,   129,   161,
      42,    45,    48,    78,    77,    80,    82,    84,    83,   -11,
     165,    86,   110,    88,   138,   141,   143,   145,   152,   153,
     102,   155,   159,    44,    25,    46,    33,   160,   146,   157,
      87,   151,   162,   163,    43,   154,   158,   150,   112,    16,
     144,    49
};

static const yytype_uint8 yycheck[] =
{
      84,    80,     3,    92,     6,     6,     8,     8,    48,    48,
      30,    26,    27,    39,    79,     5,    81,    12,    83,    34,
      99,    86,    42,     0,    89,    20,    42,     6,    29,     8,
     119,    32,    13,    23,    35,    37,    76,    76,    28,     9,
      41,    25,    24,    43,    26,    27,    42,     7,    13,    33,
      38,    42,    34,    11,    13,    10,    40,    13,    42,   138,
      44,    45,   146,    14,    15,    16,    17,    18,    19,   153,
      13,    25,    20,    30,    21,     3,     3,    13,    20,    20,
     164,    12,    31,    36,     7,     7,    21,     4,     4,    22,
      42,     4,   150,    31,    18,    32,    25,   151,    48,   148,
      76,   138,   154,    49,    30,   141,   149,   134,    88,    12,
     109,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    51,    96,    98,     0,    42,    13,    97,    59,
      60,     9,    43,   111,    42,    76,   109,    61,     7,    77,
      13,    38,    90,    92,    93,    76,    11,   109,   110,    42,
      13,    91,    62,    77,    24,    26,    27,    34,    56,   102,
     108,    13,    13,    93,    59,    25,    64,   106,    20,   110,
      65,     6,     8,    78,    79,    83,   101,    33,    40,    42,
      44,    45,    57,    58,    64,    66,    72,    80,    94,    95,
      99,   104,   112,   113,   114,   117,    10,    21,    30,    67,
       3,   115,     3,    20,    13,   105,    12,    78,    36,     3,
      29,    32,    35,    41,    63,    71,    73,    75,    83,   101,
     103,   107,    42,    82,   112,    73,    73,    88,    73,   104,
      31,    73,   102,    73,    75,    68,     5,    23,    28,    84,
      85,    86,    87,   112,    14,    15,    16,    17,    18,    19,
     100,     6,     8,    37,    52,    53,    54,    55,     7,    81,
     116,     7,    89,    21,   105,     4,    48,    69,    75,    74,
     107,    82,     4,    22,    88,     4,   104,    87,   103,    55,
      81,   104,    89,    49,    70,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    55,    55,
      56,    57,    58,    60,    61,    62,    59,    63,    63,    65,
      64,    67,    68,    66,    69,    70,    69,    71,    71,    71,
      72,    73,    74,    73,    75,    75,    75,    75,    76,    77,
      77,    78,    79,    80,    81,    81,    82,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    89,    89,    91,    90,
      92,    93,    93,    94,    95,    97,    96,    98,    99,   100,
     100,   100,   100,   100,   100,   101,   101,   101,   102,   102,
     102,   103,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   106,   107,   108,   108,   109,   110,   110,   111,   111,
     112,   112,   113,   115,   116,   114,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     0,     3,
       6,     1,     3,     0,     0,     0,     6,     1,     1,     0,
       5,     0,     0,     5,     2,     0,     5,     1,     1,     1,
       1,     1,     0,     4,     2,     1,     3,     2,     1,     0,
       3,     1,     3,     4,     0,     3,     1,     2,     1,     1,
       1,     1,     1,     0,     3,     1,     0,     3,     0,     3,
       3,     0,     3,     1,     1,     0,     6,     1,     5,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     1,     1,     4,     0,     3,     0,     4,
       1,     1,     1,     0,     0,     6,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 159 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_START", "N_PROG");
                    //printf("\n---- Completed parsing ----\n\n");
                    
                    // Assembly code to gracefully shutdown the program
                    emitImmediate(MOVQ, 60, RAX);
                    emitRegister(XOR, RDI, RDI);
                    printf("\tsyscall\n");
                    return 0;
                }
#line 1487 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 3:
#line 171 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ADDOP", "N_ADDOP_ARITH");
                    (yyval.num) = (yyvsp[0].num);
                }
#line 1496 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 4:
#line 176 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ADDOP", "N_ADDOP_LOGIC");
                    (yyval.num) = LOGICAL_OP;
                }
#line 1505 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 5:
#line 181 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ADDOP_ARITH", "T_PLUS");
                    (yyval.num) = PLUS_OP;
                }
#line 1514 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 6:
#line 186 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ADDOP_ARITH", "T_MINUS");
                    (yyval.num) = MINUS_OP;
                }
#line 1523 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 7:
#line 192 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ADDOP_LOGIC", "T_OR");
                }
#line 1531 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 8:
#line 197 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ADDOPLST", "epsilon");
                }
#line 1539 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 9:
#line 201 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");   
                    if ((yyvsp[-2].num) == PLUS_OP || (yyvsp[-2].num) == MINUS_OP) {
                        if ((yyvsp[-1].typeInfo).type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ((yyvsp[-2].num) == LOGICAL_OP) {
                        if ((yyvsp[-1].typeInfo).type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                    addList.push_front((yyvsp[-1].typeInfo));
                    addOpList.push_front((yyvsp[-2].num));
                }
#line 1558 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 10:
#line 217 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ARRAY","T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
                    (yyval.typeInfo).type = ARRAY;
                    (yyval.typeInfo).startIndex = (yyvsp[-3].typeInfo).startIndex;
                    (yyval.typeInfo).endIndex = (yyvsp[-3].typeInfo).endIndex;
                    (yyval.typeInfo).baseType = (yyvsp[0].typeInfo).type;
                }
#line 1570 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 11:
#line 226 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ARRAYVAR", "N_ENTIREVAR");
                    (yyval.text) = (yyvsp[0].text);   
                }
#line 1579 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 12:
#line 232 "willardorth.y" /* yacc.c:1660  */
    {
                    if ((yyvsp[-2].typeInfo).type == ARRAY)
                        yyerror("Cannot make assignment to an array");
                    if ((yyvsp[-2].typeInfo).type != (yyvsp[0].typeInfo).type)
                    {
                      if ((yyvsp[-2].typeInfo).type == PROCEDURE || (yyvsp[0].typeInfo).type == PROCEDURE)
                          yyerror("Procedure/variable mismatch");
                      yyerror("Expression must be of same type as variable");
                    }
                    prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");  
                    emitBaseRelativeReverse(MOVQ, RAX, (yyvsp[-2].typeInfo).offset, RBP);
                }
#line 1596 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 13:
#line 246 "willardorth.y" /* yacc.c:1660  */
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
                    }
                }
#line 1613 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 14:
#line 259 "willardorth.y" /* yacc.c:1660  */
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
#line 1635 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 15:
#line 277 "willardorth.y" /* yacc.c:1660  */
    {
                    // label for start of execution
                    if (procStack.empty()) {
                        printLabel(codeLabelNum);
                    } else {
                        printLabel(procedureCodeLabelNums.top());
                        procedureCodeLabelNums.pop();
                    }
                }
#line 1649 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 16:
#line 287 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
                    endScope();
                }
#line 1658 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 17:
#line 293 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_BOOLCONST", "T_TRUE");
                    (yyval.num) = 1;
                }
#line 1667 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 18:
#line 298 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_BOOLCONST", "T_FALSE");
                    (yyval.num) = 0;
                }
#line 1676 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 19:
#line 304 "willardorth.y" /* yacc.c:1660  */
    {
                    if (!procStack.empty() && blockLevel == 0) {
                        
                    }
                    blockLevel++;
                }
#line 1687 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 20:
#line 311 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
                    blockLevel--;
                    if (!procStack.empty() && blockLevel == 0) {
                        procStack.pop();
                    }
                }
#line 1699 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 21:
#line 320 "willardorth.y" /* yacc.c:1660  */
    {
                    inIf = true;
                    elseLabelNum.push(genLabelNum());
                }
#line 1708 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 22:
#line 325 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_CONDITION", "T_IF N_EXPR");
                }
#line 1716 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 23:
#line 329 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_CONDITION", "N_THEN_PART");
                }
#line 1724 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 24:
#line 334 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_CONDITION", "T_THEN N_STMT");
                    prRule("N_THEN_PART", "T_THEN N_STMT");
                    printLabel(elseLabelNum.top());
                    elseLabelNum.pop();
                }
#line 1735 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 25:
#line 341 "willardorth.y" /* yacc.c:1660  */
    {
                    postConditionalLabelNum.push(genLabelNum());
                    emitJump(JMP, postConditionalLabelNum.top());
                    printLabel(elseLabelNum.top());
                    elseLabelNum.pop();
                }
#line 1746 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 26:
#line 348 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_THEN_PART", "T_THEN N_STMT T_ELSE N_STMT");
                    printLabel(postConditionalLabelNum.top());
                    postConditionalLabelNum.pop();
                }
#line 1756 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 27:
#line 355 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_CONST", "N_INTCONST");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).label = NULL;
                    (yyval.typeInfo).nestingLevel = NOT_APPLICABLE;
                    (yyval.typeInfo).frameSize = NOT_APPLICABLE;
                    (yyval.typeInfo).offset = NOT_APPLICABLE;
                    (yyval.typeInfo).value = (yyvsp[0].num);
                }
#line 1773 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 28:
#line 368 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_CONST", "T_CHARCONST");
                    (yyval.typeInfo).type = CHAR;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).label = NULL;
                    (yyval.typeInfo).nestingLevel = NOT_APPLICABLE;
                    (yyval.typeInfo).frameSize = NOT_APPLICABLE;
                    (yyval.typeInfo).offset = NOT_APPLICABLE;
                    (yyval.typeInfo).value = int((yyvsp[0].text)[1]);
                    
                }
#line 1791 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 29:
#line 382 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_CONST", "N_BOOLCONST");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).label = NULL;
                    (yyval.typeInfo).nestingLevel = NOT_APPLICABLE;
                    (yyval.typeInfo).frameSize = NOT_APPLICABLE;
                    (yyval.typeInfo).offset = NOT_APPLICABLE;
                    (yyval.typeInfo).value = (yyvsp[0].num);
                }
#line 1808 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 30:
#line 396 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_ENTIREVAR", "N_VARIDENT");
                    (yyval.text) = (yyvsp[0].text);
                }
#line 1817 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 31:
#line 402 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_EXPR", "N_SIMPLEEXPR");
                    (yyval.typeInfo) = (yyvsp[0].typeInfo);
                }
#line 1826 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 32:
#line 407 "willardorth.y" /* yacc.c:1660  */
    {
                    // move what is in rax to rcx/rdx so that rax can be used for the next expression calculation
                    if (inWhile) {
                        emitRegister(MOVQ, RAX, RCX);
                    } else if (inIf) {
                        emitRegister(MOVQ, RAX, RDX);
                    }
                }
#line 1839 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 33:
#line 416 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
                    if ((yyvsp[-3].typeInfo).type != (yyvsp[0].typeInfo).type) {
                        yyerror("Expressions must both be int, or both char, or both boolean");
                    }
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).nestingLevel = NOT_APPLICABLE;
                    (yyval.typeInfo).frameSize = NOT_APPLICABLE;
                    (yyval.typeInfo).offset = NOT_APPLICABLE;
                    (yyval.typeInfo).value = NOT_APPLICABLE;
                    
                    
                    if (inWhile && !whileLabelPairs.empty()) {
                        emitRegister(CMPQ, RAX, RCX);
                        switch ((yyvsp[-2].num)) {
                            case LE:
                                emitJump(JLE, whileLabelPairs.top().second);
                                break;
                            case GE:
                                emitJump(JGE, whileLabelPairs.top().second);
                                break;
                            case EQ:
                                emitJump(JE, whileLabelPairs.top().second);
                                break;
                            case NE:
                                emitJump(JNE, whileLabelPairs.top().second);
                                break;
                            case LT:
                                emitJump(JL, whileLabelPairs.top().second);
                                break;
                            case GT:
                                emitJump(JG, whileLabelPairs.top().second);
                                break;
                        }
                        inWhile = false;
                    }
                    if (inIf) {
                        emitRegister(CMPQ, RAX, RDX);
                        // reverse the comparison conditions so that we can jump to the else code if it is false
                        switch ((yyvsp[-2].num)) {
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
#line 1912 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 34:
#line 486 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_FACTOR", "N_SIGN N_VARIABLE");
                    if (strcmp((yyvsp[-1].text), "-") == 0 && (yyvsp[0].typeInfo).type != INT) {
                        yyerror("Expression must be of type integer");
                    }
                    assignTypeInfo((yyval.typeInfo), (yyvsp[0].typeInfo));
                }
#line 1924 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 35:
#line 494 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_FACTOR", "N_CONST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[0].typeInfo));
                    
                }
#line 1934 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 36:
#line 500 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[-1].typeInfo));
                }
#line 1943 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 37:
#line 505 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_FACTOR", "T_NOT N_FACTOR");
                    if ((yyvsp[0].typeInfo).type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                    assignTypeInfo((yyval.typeInfo), (yyvsp[0].typeInfo));
                    
                }
#line 1956 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 38:
#line 515 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_IDENT", "T_IDENT");
                    (yyval.text) = (yyvsp[0].text);
                }
#line 1965 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 39:
#line 521 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_IDENTLST", "epsilon");
                }
#line 1973 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 40:
#line 525 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
                    identList.push_front(string((yyvsp[-1].text)));
                }
#line 1982 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 41:
#line 531 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_IDX", "N_INTCONST");
                    (yyval.num) = (yyvsp[0].num);
                }
#line 1991 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 42:
#line 537 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
                    if ((yyvsp[-2].num) > (yyvsp[0].num)) {
                        yyerror("Start index must be less than or equal to end index of array");
                    }
                    (yyval.typeInfo).type = NOT_APPLICABLE;
                    (yyval.typeInfo).startIndex = (yyvsp[-2].num);
                    (yyval.typeInfo).endIndex = (yyvsp[0].num);
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                }
#line 2006 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 43:
#line 549 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
                    //Have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an array was not able to be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NULL,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string((yyvsp[-3].text)));
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
                    (yyval.typeInfo).type = info.baseType; // need to pass this to N_VARIABLE
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    if ((yyvsp[-1].typeInfo).type != INT) {
                        if ((yyvsp[-1].typeInfo).type == PROCEDURE)
                            yyerror("Procedure/variable mismatch");
                        yyerror("Index expression must be of type integer");
                    }
                    // int size = abs(info.startIndex - info.endIndex) + 1;
                    // int arrayOffset = info.startIndex;
                    // emitImmediate(SUBQ, arrayOffset, RAX);
                    // emitImmediate(IMULQ, VAR_SIZE, RAX);
                    // emitRegister(MOVQ, RAX, RBX);
                }
#line 2044 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 44:
#line 584 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_INPUTLST", "epsilon");
                }
#line 2052 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 45:
#line 588 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
                }
#line 2060 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 46:
#line 593 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_INPUTVAR", "N_VARIABLE");
                    (yyval.typeInfo) = (yyvsp[0].typeInfo);

                }
#line 2070 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 47:
#line 600 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_INTCONST", "N_SIGN T_INTCONST");
                    if (strcmp((yyvsp[-1].text), "+") == 0) {
                        (yyval.num) = (yyvsp[0].num);
                    } else if (strcmp((yyvsp[-1].text), "-") == 0) {
                        (yyval.num) = -(yyvsp[0].num);
                    }
                }
#line 2083 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 48:
#line 610 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_MULTOP", "N_MULTOP_ARITH");
                    (yyval.num) = (yyvsp[0].num);
                }
#line 2092 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 49:
#line 615 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_MULTOP", "N_MULTOP_LOGIC");
                    (yyval.num) = LOGICAL_OP;
                }
#line 2101 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 50:
#line 621 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_MULTOP_ARITH", "T_MULT");
                    (yyval.num) = MULT_OP;
                }
#line 2110 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 51:
#line 626 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_MULTOP_ARITH", "T_DIV");
                    (yyval.num) = DIV_OP;
                }
#line 2119 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 52:
#line 632 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_MULTOP_LOGIC", "T_AND");
                }
#line 2127 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 53:
#line 637 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_MULTOPLST", "epsilon");
                }
#line 2135 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 54:
#line 641 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
                    if ((yyvsp[-2].num) == DIV_OP || (yyvsp[-2].num) == MULT_OP) {
                        if ((yyvsp[-1].typeInfo).type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ((yyvsp[-2].num)  == LOGICAL_OP) {
                        if ((yyvsp[-1].typeInfo).type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                    multList.push_front((yyvsp[-1].typeInfo));
                    multOpList.push_front((yyvsp[-2].num));
                }
#line 2154 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 55:
#line 657 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_OUTPUT", "N_EXPR");
                    (yyval.typeInfo) = (yyvsp[0].typeInfo);
                    if ((yyvsp[0].typeInfo).type == INT) {
                    } else if ((yyvsp[0].typeInfo).type == CHAR) {
                    }
                }
#line 2166 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 56:
#line 666 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_OUTPUTLST", "epsilon");
                }
#line 2174 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 57:
#line 670 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
                }
#line 2182 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 58:
#line 675 "willardorth.y" /* yacc.c:1660  */
    {
                    // when inside the procedures block, the static nesting level is increased
                    staticNestingLevel++;
                    blockLevel = 0;
                }
#line 2192 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 59:
#line 681 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
                    staticNestingLevel--;
                    emitRet();
                }
#line 2202 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 60:
#line 688 "willardorth.y" /* yacc.c:1660  */
    {
                        prRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
                        TypeInfo info;
                        info.type = PROCEDURE;
                        info.startIndex = NOT_APPLICABLE;
                        info.endIndex = NOT_APPLICABLE;
                        info.baseType = NOT_APPLICABLE;
                        info.nestingLevel = staticNestingLevel;
                        info.label = strdup((yyvsp[-1].text));
                        procStack.push(make_pair(string((yyvsp[-1].text)), info));
                        printf("%s:\n", info.label);
                        beginScope();
                    }
#line 2220 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 61:
#line 703 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_PROCDECPART", "epsilon");
                }
#line 2228 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 62:
#line 707 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_PROCDECPART", "N_PROCDEC T_SCOLON N_PROCDECPART");
                }
#line 2236 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 63:
#line 712 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_PROCIDENT", "T_IDENT");
                    if (!checkSymbolTables((yyvsp[0].text))) {
                        yyerror("Undefined identifier");
                    }
                    (yyval.text) = strdup((yyvsp[0].text));
                }
#line 2248 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 64:
#line 721 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_PROCSTMT", "N_PROCIDENT");
                    TypeInfo info = getFromSymbolTables(string((yyvsp[0].text)));
                    int callerNestingLevel = staticNestingLevel - 1;
                    if (info.type != NOT_FOUND && info.type == PROCEDURE) {
                        emitCall(info.label);
                    } else {
                        yyerror("Procedure not found");
                    }
                }
#line 2263 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 65:
#line 733 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_PROG","N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
                    TypeInfo info;
                    info.type = PROGRAM;
                    info.startIndex = NOT_APPLICABLE;
                    info.endIndex = NOT_APPLICABLE;
                    info.baseType = NOT_APPLICABLE;
                    addToSymbolTable((yyvsp[-1].text), info);

                    // global declaration for what part of the assembly to start execution
                    printf("\t.global _start\n");
                }
#line 2280 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 67:
#line 748 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_PROGLBL", "T_PROG");
                    beginScope();
                }
#line 2289 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 68:
#line 754 "willardorth.y" /* yacc.c:1660  */
    {
                    if ((yyvsp[-2].typeInfo).type != INT && (yyvsp[-2].typeInfo).type != CHAR)
                      yyerror("Input variable must be of type integer or char");
                    prRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
                }
#line 2299 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 69:
#line 761 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_RELOP", "T_LT");
                    (yyval.num) = LT;
                }
#line 2308 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 70:
#line 766 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_RELOP", "T_GT");
                    (yyval.num) = GT;
                }
#line 2317 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 71:
#line 771 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_RELOP", "T_LE");
                    (yyval.num) = LE;
                }
#line 2326 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 72:
#line 776 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_RELOP", "T_GE");
                    (yyval.num) = GE;
                }
#line 2335 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 73:
#line 781 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_RELOP", "T_EQ");
                    (yyval.num) = EQ;
                }
#line 2344 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 74:
#line 786 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_RELOP", "T_NE");
                    (yyval.num) = NE;
                }
#line 2353 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 75:
#line 792 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_SIGN", "epsilon");
                    (yyval.text) = strdup("+");
                }
#line 2362 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 76:
#line 797 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_SIGN", "T_PLUS");
                    (yyval.text) = (yyvsp[0].text);
                }
#line 2371 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 77:
#line 802 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_SIGN", "T_MINUS");
                    (yyval.text) = (yyvsp[0].text);
                }
#line 2380 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 78:
#line 808 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_SIMPLE", "T_INT");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).label = NULL;
                    (yyval.typeInfo).nestingLevel = NOT_APPLICABLE;
                    (yyval.typeInfo).frameSize = NOT_APPLICABLE;
                    (yyval.typeInfo).offset = NOT_APPLICABLE;
                    (yyval.typeInfo).value = NOT_APPLICABLE;
                }
#line 2397 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 79:
#line 821 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_SIMPLE", "T_CHAR");
                    (yyval.typeInfo).type = CHAR;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).label = NULL;
                    (yyval.typeInfo).nestingLevel = NOT_APPLICABLE;
                    (yyval.typeInfo).frameSize = NOT_APPLICABLE;
                    (yyval.typeInfo).offset = NOT_APPLICABLE;
                    (yyval.typeInfo).value = NOT_APPLICABLE;
                }
#line 2414 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 80:
#line 834 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_SIMPLE", "T_BOOL");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    (yyval.typeInfo).label = NULL;
                    (yyval.typeInfo).nestingLevel = NOT_APPLICABLE;
                    (yyval.typeInfo).frameSize = NOT_APPLICABLE;
                    (yyval.typeInfo).offset = NOT_APPLICABLE;
                    (yyval.typeInfo).value = NOT_APPLICABLE;
                }
#line 2431 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 81:
#line 848 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[-1].typeInfo));
                    addList.push_front((yyvsp[-1].typeInfo));
                    list<TypeInfo>::iterator it;
                    list<int>::iterator opIt;
                    // for (it = addList.begin(); it != addList.end(); ++it) {
                    //     if (it->value == NOT_APPLICABLE) {
                    //         printf("offset: %d\n", it->offset);
                    //     } else {
                    //         printf("value: %d\n", it->value);
                    //     }
                    // }
                    // for (opIt = addOpList.begin(); opIt != addOpList.end(); ++opIt) {
                    //     printf("Op: %d\n", *opIt);
                    // }
                    bool emitting = true;
                    if (!addList.empty() && !addOpList.empty()) {
                        TypeInfo info = addList.front();
                        addList.pop_front();
                        if (info.offset == NOT_APPLICABLE) {
                            emitImmediate(MOVQ, info.value, RAX);
                        } else {
                            emitBaseRelative(MOVQ, info.offset, RBP, RAX);
                        }
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
                            if ((yyvsp[-1].typeInfo).offset == NOT_APPLICABLE) {
                                emitImmediate(MOVQ, (yyvsp[-1].typeInfo).value, RAX);
                            } else {
                                emitBaseRelative(MOVQ, (yyvsp[-1].typeInfo).offset, RBP, RAX);
                            }
                        }
                    }
                    addList.clear();
                    addOpList.clear();
                    multList.clear();
                    multOpList.clear();
                }
#line 2509 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 82:
#line 923 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMT", "N_ASSIGN");
                }
#line 2517 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 83:
#line 927 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMT", "N_PROCSTMT");
                }
#line 2525 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 84:
#line 931 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMT", "N_READ");
                }
#line 2533 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 85:
#line 935 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMT", "N_WRITE");
                }
#line 2541 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 86:
#line 939 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMT", "N_CONDITION");
                }
#line 2549 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 87:
#line 943 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMT", "N_WHILE");
                }
#line 2557 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 88:
#line 947 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMT", "N_COMPOUND");
                }
#line 2565 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 89:
#line 952 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMTLST", "epsilon");
                }
#line 2573 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 90:
#line 956 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
                }
#line 2581 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 91:
#line 961 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_STMTPART", "N_COMPOUND");
                }
#line 2589 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 92:
#line 966 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_TERM", "N_FACTOR N_MULTOPLST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[-1].typeInfo));
                    multList.push_front((yyvsp[-1].typeInfo));
                    list<TypeInfo>::iterator it;
                    list<int>::iterator opIt;
                    // for (it = multList.begin(); it != multList.end(); ++it) {
                    //     if (it->value == NOT_APPLICABLE) {
                    //         printf("offset: %d\n", it->offset);
                    //     } else {
                    //         printf("value: %d\n", it->value);
                    //     }
                    // }
                    // for (opIt = multOpList.begin(); opIt != multOpList.end(); ++opIt) {
                    //     printf("Op: %d\n", *opIt);
                    // }
                    bool emitting = true;
                    if (!multList.empty() && !multOpList.empty()) {
                        TypeInfo info = multList.front();
                        multList.pop_front();
                        if (info.offset == NOT_APPLICABLE) {
                            emitImmediate(MOVQ, info.value, RAX);
                        } else {
                            emitBaseRelative(MOVQ, info.offset, RBP, RAX);
                        }
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
#line 2653 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 93:
#line 1027 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_TYPE", "N_SIMPLE");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[0].typeInfo));
                }
#line 2662 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 94:
#line 1032 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_TYPE", "N_ARRAY");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[0].typeInfo));
                }
#line 2671 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 95:
#line 1038 "willardorth.y" /* yacc.c:1660  */
    {   
                    prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
                    identList.push_front(string((yyvsp[-3].text)));
                    for (list<string>::iterator it = identList.begin(); it != identList.end(); ++it) {
                        (yyvsp[0].typeInfo).nestingLevel = staticNestingLevel;
                        // printf("%s:\n", (*it).c_str());
                        allocateVariable((yyvsp[0].typeInfo));
                        addToSymbolTable(*it, (yyvsp[0].typeInfo));
                    }
                    identList.clear();
                }
#line 2687 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 96:
#line 1051 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_VARDECLST", "epsilon");
                }
#line 2695 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 97:
#line 1055 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
                }
#line 2703 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 98:
#line 1060 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_VARDECPART", "epsilon");
                }
#line 2711 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 99:
#line 1064 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_VARDECPART", "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
                }
#line 2719 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 100:
#line 1069 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_VARIABLE", "N_ENTIREVAR");
                    //Again, have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an integer couldn't be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NULL,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string((yyvsp[0].text)));
                        it ++;
                    }
                    if (info.type == NOT_FOUND) {
                        yyerror("? shouldn't get here 2");
                    }
                    (yyval.typeInfo) = info;

                }
#line 2740 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 101:
#line 1086 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_VARIABLE", "N_IDXVAR");
                    (yyval.typeInfo) = (yyvsp[0].typeInfo);
                }
#line 2749 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 102:
#line 1092 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_VARIDENT", "T_IDENT");
                    if (!checkSymbolTables((yyvsp[0].text))) {
                        yyerror("Undefined identifier");
                    }
                    (yyval.text) = (yyvsp[0].text);
                }
#line 2761 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 103:
#line 1101 "willardorth.y" /* yacc.c:1660  */
    {
                    whileLabelPairs.push(make_pair(genLabelNum(), genLabelNum()));
                    printLabel(whileLabelPairs.top().first);
                    inWhile = true;
                }
#line 2771 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 104:
#line 1107 "willardorth.y" /* yacc.c:1660  */
    {
                    if ((yyvsp[0].typeInfo).type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                }
#line 2781 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 105:
#line 1113 "willardorth.y" /* yacc.c:1660  */
    {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                    emitJump(JMP, whileLabelPairs.top().first);
                    printLabel(whileLabelPairs.top().second);
                    whileLabelPairs.pop();
                }
#line 2792 "willardorth.tab.c" /* yacc.c:1660  */
    break;

  case 106:
#line 1121 "willardorth.y" /* yacc.c:1660  */
    {
                    if ((yyvsp[-2].typeInfo).type != INT && (yyvsp[-2].typeInfo).type != CHAR)
                        yyerror("Output expression must be of type integer or char");
                    prRule("N_WRITE", "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
                }
#line 2802 "willardorth.tab.c" /* yacc.c:1660  */
    break;


#line 2806 "willardorth.tab.c" /* yacc.c:1660  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1127 "willardorth.y" /* yacc.c:1903  */


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
        case CALL:       printf("call\t"); break;
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
