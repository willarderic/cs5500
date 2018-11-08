/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define T_LPAREN 258
#define T_RPAREN 259
#define T_MULT 260
#define T_PLUS 261
#define T_COMMA 262
#define T_MINUS 263
#define T_DOT 264
#define T_DOTDOT 265
#define T_COLON 266
#define T_ASSIGN 267
#define T_SCOLON 268
#define T_LT 269
#define T_LE 270
#define T_NE 271
#define T_EQ 272
#define T_GT 273
#define T_GE 274
#define T_LBRACK 275
#define T_RBRACK 276
#define T_DO 277
#define T_AND 278
#define T_ARRAY 279
#define T_BEGIN 280
#define T_BOOL 281
#define T_CHAR 282
#define T_DIV 283
#define T_CHARCONST 284
#define T_INTCONST 285
#define T_END 286
#define T_FALSE 287
#define T_IF 288
#define T_INT 289
#define T_NOT 290
#define T_OF 291
#define T_OR 292
#define T_PROC 293
#define T_PROG 294
#define T_READ 295
#define T_TRUE 296
#define T_IDENT 297
#define T_VAR 298
#define T_WHILE 299
#define T_WRITE 300
#define T_UNKNOWN 301
#define ST_EOF 302
#define T_THEN 303
#define T_ELSE 304




/* Copy the first part of user declarations.  */
#line 9 "willardorth.y"


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
#define ARITHMETIC_OP 101

int lineNum = 1; // source line number
int staticNestingLevel = 1;

list<SymbolTable> scopeStack;
list<string> identList;

stack<pair<string, TypeInfo> > procStack;
int globalsLabelNum, stackLabelNum, codeLabelNum, entryPointLabelNum;
int blockLevel = 0;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 72 "willardorth.y"
{
    int num;
    char* text;
    TypeInfo typeInfo;
}
/* Line 193 of yacc.c.  */
#line 263 "willardorth.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 276 "willardorth.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    16,
      20,    27,    29,    33,    34,    39,    41,    43,    44,    50,
      54,    57,    62,    64,    66,    68,    70,    72,    76,    79,
      81,    85,    88,    90,    91,    95,    97,   101,   106,   107,
     111,   113,   116,   118,   120,   122,   124,   126,   127,   131,
     133,   134,   138,   139,   143,   147,   148,   152,   154,   156,
     157,   164,   166,   172,   174,   176,   178,   180,   182,   184,
     185,   187,   189,   191,   193,   195,   198,   200,   202,   204,
     206,   208,   210,   212,   213,   217,   219,   222,   224,   226,
     231,   232,   236,   237,   242,   244,   246,   248,   249,   255
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    90,    -1,    53,    -1,    54,    -1,     6,
      -1,     8,    -1,    37,    -1,    -1,    52,   101,    55,    -1,
      24,    20,    73,    21,    36,    96,    -1,    67,    -1,   106,
      12,    68,    -1,    -1,   105,    60,    87,   100,    -1,    41,
      -1,    32,    -1,    -1,    25,    63,    98,    99,    31,    -1,
      33,    68,    65,    -1,    48,    98,    -1,    48,    98,    49,
      98,    -1,    77,    -1,    29,    -1,    61,    -1,   107,    -1,
      97,    -1,    97,    94,    97,    -1,    95,   106,    -1,    66,
      -1,     3,    68,     4,    -1,    35,    69,    -1,    42,    -1,
      -1,     7,    70,    71,    -1,    77,    -1,    72,    10,    72,
      -1,    57,    20,    68,    21,    -1,    -1,     7,    76,    75,
      -1,   106,    -1,    95,    30,    -1,    79,    -1,    80,    -1,
       5,    -1,    28,    -1,    23,    -1,    -1,    78,    69,    81,
      -1,    68,    -1,    -1,     7,    82,    83,    -1,    -1,    86,
      85,    59,    -1,    38,    42,    13,    -1,    -1,    84,    13,
      87,    -1,    42,    -1,    88,    -1,    -1,    92,    42,    13,
      91,    59,     9,    -1,    39,    -1,    40,     3,    76,    75,
       4,    -1,    14,    -1,    18,    -1,    15,    -1,    19,    -1,
      17,    -1,    16,    -1,    -1,     6,    -1,     8,    -1,    34,
      -1,    27,    -1,    26,    -1,   101,    55,    -1,    58,    -1,
      89,    -1,    93,    -1,   110,    -1,    64,    -1,   108,    -1,
      62,    -1,    -1,    13,    98,    99,    -1,    62,    -1,    69,
      81,    -1,    96,    -1,    56,    -1,    70,    71,    11,   102,
      -1,    -1,   103,    13,   104,    -1,    -1,    43,   103,    13,
     104,    -1,    67,    -1,    74,    -1,    42,    -1,    -1,    44,
      68,   109,    22,    98,    -1,    45,     3,    82,    83,     4,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   128,   133,   138,   142,   147,   153,   156,
     170,   179,   185,   199,   198,   223,   227,   233,   232,   257,
     262,   266,   271,   279,   287,   296,   302,   307,   319,   327,
     332,   337,   346,   353,   356,   362,   368,   380,   411,   414,
     419,   425,   435,   440,   446,   450,   455,   461,   464,   478,
     485,   488,   494,   493,   505,   520,   523,   528,   536,   561,
     560,   582,   588,   595,   599,   603,   607,   611,   615,   621,
     625,   630,   636,   644,   652,   661,   667,   671,   675,   679,
     683,   687,   691,   697,   700,   705,   710,   716,   721,   727,
     738,   741,   747,   750,   755,   771,   777,   787,   786,   797
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "N_ASSIGN", "N_BLOCK", "@1", "N_BOOLCONST", "N_COMPOUND", "@2",
  "N_CONDITION", "N_THEN_PART", "N_CONST", "N_ENTIREVAR", "N_EXPR",
  "N_FACTOR", "N_IDENT", "N_IDENTLST", "N_IDX", "N_IDXRANGE", "N_IDXVAR",
  "N_INPUTLST", "N_INPUTVAR", "N_INTCONST", "N_MULTOP", "N_MULTOP_ARITH",
  "N_MULTOP_LOGIC", "N_MULTOPLST", "N_OUTPUT", "N_OUTPUTLST", "N_PROCDEC",
  "@3", "N_PROCHDR", "N_PROCDECPART", "N_PROCIDENT", "N_PROCSTMT",
  "N_PROG", "@4", "N_PROGLBL", "N_READ", "N_RELOP", "N_SIGN", "N_SIMPLE",
  "N_SIMPLEEXPR", "N_STMT", "N_STMTLST", "N_STMTPART", "N_TERM", "N_TYPE",
  "N_VARDEC", "N_VARDECLST", "N_VARDECPART", "N_VARIABLE", "N_VARIDENT",
  "N_WHILE", "@5", "N_WRITE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    55,    55,
      56,    57,    58,    60,    59,    61,    61,    63,    62,    64,
      65,    65,    66,    66,    66,    67,    68,    68,    69,    69,
      69,    69,    70,    71,    71,    72,    73,    74,    75,    75,
      76,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      83,    83,    85,    84,    86,    87,    87,    88,    89,    91,
      90,    92,    93,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    97,    98,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   101,   102,   102,   103,
     104,   104,   105,   105,   106,   106,   107,   109,   108,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     0,     3,
       6,     1,     3,     0,     4,     1,     1,     0,     5,     3,
       2,     4,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     2,     1,     0,     3,     1,     3,     4,     0,     3,
       1,     2,     1,     1,     1,     1,     1,     0,     3,     1,
       0,     3,     0,     3,     3,     0,     3,     1,     1,     0,
       6,     1,     5,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     2,     1,     1,     4,
       0,     3,     0,     4,     1,     1,     1,     0,     5,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    61,     0,     2,     0,     1,     0,    59,    92,     0,
       0,    13,    32,    33,     0,    60,    55,     0,     0,    90,
       0,     0,    52,     0,    33,     0,     0,    93,     0,    55,
      92,    17,    85,    14,    34,     0,    74,    73,    72,    88,
      87,    89,    90,    54,    56,    53,     0,    69,    91,    69,
       0,    57,    69,     0,     0,    76,    82,    80,    94,    95,
      58,    77,    78,    83,     0,    25,    81,    79,    70,    71,
       0,     0,    35,     0,    69,    23,    16,    69,    15,    24,
      29,     0,    47,    22,     0,    26,     8,     0,    97,    69,
      69,     0,     0,    69,    69,     0,    41,     0,    31,     0,
      19,    44,    46,    45,    69,    42,    43,    86,    96,    28,
      63,    65,    68,    67,    64,    66,    69,     5,     6,     7,
      69,     3,     4,    75,    38,    40,     0,    49,    50,     0,
      83,    18,    12,    36,     0,    30,    20,    47,    27,     8,
       0,     0,     0,    69,     0,    37,    84,    10,     0,    48,
       9,    38,    62,    98,    50,    99,    21,    39,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   120,   121,   122,   123,    39,    54,    55,    10,
      16,    79,    56,    46,    57,   100,    80,    58,   127,    82,
      13,    18,    70,    71,    59,   141,   124,    83,   104,   105,
     106,   107,   128,   144,    21,    30,    22,    23,    60,    61,
       3,     8,     4,    62,   116,    84,    40,    85,    63,    92,
      33,    86,    41,    26,    27,    11,    64,    65,    66,   126,
      67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int8 yypact[] =
{
     -27,   -92,    13,   -92,   -26,   -92,    15,   -92,   -13,    -4,
      30,   -92,   -92,    33,    29,   -92,     5,    -4,    34,    -4,
       7,    43,   -92,    35,    33,    -3,    46,   -92,    49,     5,
     -13,   -92,   -92,   -92,   -92,    44,   -92,   -92,   -92,   -92,
     -92,   -92,    -4,   -92,   -92,   -92,    21,    11,   -92,    12,
      70,    17,    12,    71,    55,   -92,   -92,   -92,    56,   -92,
     -92,   -92,   -92,    64,    66,   -92,   -92,   -92,   -92,   -92,
      69,    59,   -92,    51,    12,   -92,   -92,    12,   -92,   -92,
     -92,    36,     4,   -92,   -20,    53,    -2,    40,   -92,    12,
      12,    21,    52,    12,    11,    50,   -92,    81,   -92,    21,
     -92,   -92,   -92,   -92,    12,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,    12,   -92,   -92,   -92,
      12,   -92,   -92,   -92,    80,   -92,    67,   -92,    83,    72,
      64,   -92,   -92,   -92,    -1,   -92,    39,     4,   -92,    -2,
      40,    87,    21,    12,    88,   -92,   -92,   -92,    21,   -92,
     -92,    80,   -92,   -92,    83,   -92,   -92,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,   -45,   -92,   -92,   -92,    65,
     -92,   -92,    73,   -92,   -92,   -92,   -92,   -92,   -38,   -70,
      82,    74,     3,   -92,   -92,   -51,   -39,   -46,   -92,   -92,
     -92,   -35,   -40,   -50,   -92,   -92,   -92,    76,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -44,   -28,    -9,   -91,   -22,
     -92,   -11,   -92,   101,    75,   -92,   -82,   -92,   -92,   -92,
     -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -97
static const yytype_int16 yytable[] =
{
     130,    72,   109,    73,   117,   125,   118,    98,   136,   101,
      96,    81,     1,     5,    88,    74,     6,    68,    68,    69,
      69,    35,   108,    36,    37,    36,    37,   102,     7,   -96,
       9,    38,   103,    38,   137,   119,    97,   -96,    12,    15,
      17,    75,    19,    20,    76,    25,    31,    77,    72,    28,
      73,   153,   129,    78,    49,   132,    29,   156,   125,    42,
      31,    50,    43,    51,    47,    52,    53,   110,   111,   112,
     113,   114,   115,    87,    89,    90,   -11,    91,    93,    94,
      95,    96,   108,   131,    99,   135,   134,   140,   148,   142,
     143,   152,   155,   145,   150,    45,    32,   133,    34,    24,
     157,   151,   149,   154,   158,    44,   147,   138,   146,   139,
      14,     0,     0,     0,     0,     0,     0,    48
};

static const yytype_int16 yycheck[] =
{
      91,    47,    84,    47,     6,    87,     8,    77,    99,     5,
      30,    49,    39,     0,    52,     3,    42,     6,     6,     8,
       8,    24,    42,    26,    27,    26,    27,    23,    13,    12,
      43,    34,    28,    34,   104,    37,    74,    20,    42,     9,
       7,    29,    13,    38,    32,    11,    25,    35,    94,    42,
      94,   142,    90,    41,    33,    93,    13,   148,   140,    13,
      25,    40,    13,    42,    20,    44,    45,    14,    15,    16,
      17,    18,    19,     3,     3,    20,    20,    13,    12,    10,
      21,    30,    42,    31,    48,     4,    36,     7,    49,    22,
       7,     4,     4,    21,   139,    30,    23,    94,    24,    17,
     151,   140,   137,   143,   154,    29,   134,   116,   130,   120,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    51,    90,    92,     0,    42,    13,    91,    43,
      59,   105,    42,    70,   103,     9,    60,     7,    71,    13,
      38,    84,    86,    87,    70,    11,   103,   104,    42,    13,
      85,    25,    62,   100,    71,    24,    26,    27,    34,    56,
      96,   102,    13,    13,    87,    59,    63,    20,   104,    33,
      40,    42,    44,    45,    57,    58,    62,    64,    67,    74,
      88,    89,    93,    98,   106,   107,   108,   110,     6,     8,
      72,    73,    77,    95,     3,    29,    32,    35,    41,    61,
      66,    68,    69,    77,    95,    97,   101,     3,    68,     3,
      20,    13,    99,    12,    10,    21,    30,    68,    69,    48,
      65,     5,    23,    28,    78,    79,    80,    81,    42,   106,
      14,    15,    16,    17,    18,    19,    94,     6,     8,    37,
      52,    53,    54,    55,    76,   106,   109,    68,    82,    68,
      98,    31,    68,    72,    36,     4,    98,    69,    97,   101,
       7,    75,    22,     7,    83,    21,    99,    96,    49,    81,
      55,    76,     4,    98,    82,     4,    98,    75,    83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 118 "willardorth.y"
    {
                    prRule("N_START", "N_PROG");
                    //printf("\n---- Completed parsing ----\n\n");
                    printOpCode("halt");
                    printLabel(stackLabelNum);
                    printOpCodeSingleAddr("bss", "500");
                    printOpCode("end");
                    return 0;
                ;}
    break;

  case 3:
#line 129 "willardorth.y"
    {
                    prRule("N_ADDOP", "N_ADDOP_ARITH");
                    (yyval.num) = ARITHMETIC_OP;
                ;}
    break;

  case 4:
#line 134 "willardorth.y"
    {
                    prRule("N_ADDOP", "N_ADDOP_LOGIC");
                    (yyval.num) = LOGICAL_OP;
                ;}
    break;

  case 5:
#line 139 "willardorth.y"
    {
                    prRule("N_ADDOP_ARITH", "T_PLUS");
                ;}
    break;

  case 6:
#line 143 "willardorth.y"
    {
                    prRule("N_ADDOP_ARITH", "T_MINUS");
                ;}
    break;

  case 7:
#line 148 "willardorth.y"
    {
                    prRule("N_ADDOP_LOGIC", "T_OR");
                ;}
    break;

  case 8:
#line 153 "willardorth.y"
    {
                    prRule("N_ADDOPLST", "epsilon");
                ;}
    break;

  case 9:
#line 157 "willardorth.y"
    {
                    prRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
                    if ((yyvsp[(1) - (3)].num) == ARITHMETIC_OP) {
                        if ((yyvsp[(2) - (3)].typeInfo).type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ((yyvsp[(1) - (3)].num) == LOGICAL_OP) {
                        if ((yyvsp[(2) - (3)].typeInfo).type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                ;}
    break;

  case 10:
#line 171 "willardorth.y"
    {
                    prRule("N_ARRAY","T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
                    (yyval.typeInfo).type = ARRAY;
                    (yyval.typeInfo).startIndex = (yyvsp[(3) - (6)].typeInfo).startIndex;
                    (yyval.typeInfo).endIndex = (yyvsp[(3) - (6)].typeInfo).endIndex;
                    (yyval.typeInfo).baseType = (yyvsp[(6) - (6)].typeInfo).type;
                ;}
    break;

  case 11:
#line 180 "willardorth.y"
    {
                    prRule("N_ARRAYVAR", "N_ENTIREVAR");
                    (yyval.text) = (yyvsp[(1) - (1)].text);   
                ;}
    break;

  case 12:
#line 186 "willardorth.y"
    {
                    if ((yyvsp[(1) - (3)].typeInfo).type == ARRAY)
                        yyerror("Cannot make assignment to an array");
                    if ((yyvsp[(1) - (3)].typeInfo).type != (yyvsp[(3) - (3)].typeInfo).type)
                    {
                      if ((yyvsp[(1) - (3)].typeInfo).type == PROCEDURE || (yyvsp[(3) - (3)].typeInfo).type == PROCEDURE)
                          yyerror("Procedure/variable mismatch");
                      yyerror("Expression must be of same type as variable");
                    }
                    prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
                ;}
    break;

  case 13:
#line 199 "willardorth.y"
    {
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
                ;}
    break;

  case 14:
#line 214 "willardorth.y"
    {
                    if (scopeStack.size() == 1) {
                        printLabel(entryPointLabelNum);
                    }
                    prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
                    endScope();

                ;}
    break;

  case 15:
#line 224 "willardorth.y"
    {
                    prRule("N_BOOLCONST", "T_TRUE");
                ;}
    break;

  case 16:
#line 228 "willardorth.y"
    {
                    prRule("N_BOOLCONST", "T_FALSE");
                ;}
    break;

  case 17:
#line 233 "willardorth.y"
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
                ;}
    break;

  case 18:
#line 245 "willardorth.y"
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
                ;}
    break;

  case 19:
#line 258 "willardorth.y"
    {
                    prRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT N_ELSE_PART");
                ;}
    break;

  case 20:
#line 263 "willardorth.y"
    {
                    prRule("N_THEN_PART", "T_THEN N_STMT");
                ;}
    break;

  case 21:
#line 267 "willardorth.y"
    {
                    prRule("N_THEN_PART", "T_THEN N_STMT T_ELSE N_STMT");
                ;}
    break;

  case 22:
#line 272 "willardorth.y"
    {
                    prRule("N_CONST", "N_INTCONST");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 23:
#line 280 "willardorth.y"
    {
                    prRule("N_CONST", "T_CHARCONST");
                    (yyval.typeInfo).type = CHAR;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 24:
#line 288 "willardorth.y"
    {
                    prRule("N_CONST", "N_BOOLCONST");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 25:
#line 297 "willardorth.y"
    {
                    prRule("N_ENTIREVAR", "N_VARIDENT");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 26:
#line 303 "willardorth.y"
    {
                    prRule("N_EXPR", "N_SIMPLEEXPR");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                ;}
    break;

  case 27:
#line 308 "willardorth.y"
    {
                    prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
                    if ((yyvsp[(1) - (3)].typeInfo).type != (yyvsp[(3) - (3)].typeInfo).type) {
                        yyerror("Expressions must both be int, or both char, or both boolean");
                    }
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 28:
#line 320 "willardorth.y"
    {
                    prRule("N_FACTOR", "N_SIGN N_VARIABLE");
                    if (strcmp((yyvsp[(1) - (2)].text), "-") == 0 && (yyvsp[(2) - (2)].typeInfo).type != INT) {
                        yyerror("Expression must be of type integer");
                    }
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(2) - (2)].typeInfo));
                ;}
    break;

  case 29:
#line 328 "willardorth.y"
    {
                    prRule("N_FACTOR", "N_CONST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (1)].typeInfo));
                ;}
    break;

  case 30:
#line 333 "willardorth.y"
    {
                    prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(2) - (3)].typeInfo));
                ;}
    break;

  case 31:
#line 338 "willardorth.y"
    {
                    prRule("N_FACTOR", "T_NOT N_FACTOR");
                    if ((yyvsp[(2) - (2)].typeInfo).type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(2) - (2)].typeInfo));
                ;}
    break;

  case 32:
#line 347 "willardorth.y"
    {
                    prRule("N_IDENT", "T_IDENT");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 33:
#line 353 "willardorth.y"
    {
                    prRule("N_IDENTLST", "epsilon");
                ;}
    break;

  case 34:
#line 357 "willardorth.y"
    {
                    prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
                    identList.push_front(string((yyvsp[(2) - (3)].text)));
                ;}
    break;

  case 35:
#line 363 "willardorth.y"
    {
                    prRule("N_IDX", "N_INTCONST");
                    (yyval.num) = (yyvsp[(1) - (1)].num);
                ;}
    break;

  case 36:
#line 369 "willardorth.y"
    {
                    prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
                    if ((yyvsp[(1) - (3)].num) > (yyvsp[(3) - (3)].num)) {
                        yyerror("Start index must be less than or equal to end index of array");
                    }
                    (yyval.typeInfo).type = NOT_APPLICABLE;
                    (yyval.typeInfo).startIndex = (yyvsp[(1) - (3)].num);
                    (yyval.typeInfo).endIndex = (yyvsp[(3) - (3)].num);
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 37:
#line 381 "willardorth.y"
    {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
                    //Have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an array was not able to be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string((yyvsp[(1) - (4)].text)));
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
                    if ((yyvsp[(3) - (4)].typeInfo).type != INT) {
                        if ((yyvsp[(3) - (4)].typeInfo).type == PROCEDURE)
                            yyerror("Procedure/variable mismatch");
                        yyerror("Index expression must be of type integer");
                    }
                    (yyval.typeInfo).type = info.baseType; // need to pass this to N_VARIABLE
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 38:
#line 411 "willardorth.y"
    {
                    prRule("N_INPUTLST", "epsilon");
                ;}
    break;

  case 39:
#line 415 "willardorth.y"
    {
                    prRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
                ;}
    break;

  case 40:
#line 420 "willardorth.y"
    {
                    prRule("N_INPUTVAR", "N_VARIABLE");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                ;}
    break;

  case 41:
#line 426 "willardorth.y"
    {
                    prRule("N_INTCONST", "N_SIGN T_INTCONST");
                    if (strcmp((yyvsp[(1) - (2)].text), "+") == 0) {
                        (yyval.num) = (yyvsp[(2) - (2)].num);
                    } else if (strcmp((yyvsp[(1) - (2)].text), "-") == 0) {
                        (yyval.num) = -(yyvsp[(2) - (2)].num);
                    }
                ;}
    break;

  case 42:
#line 436 "willardorth.y"
    {
                    prRule("N_MULTOP", "N_MULTOP_ARITH");
                    (yyval.num) = ARITHMETIC_OP;
                ;}
    break;

  case 43:
#line 441 "willardorth.y"
    {
                    prRule("N_MULTOP", "N_MULTOP_LOGIC");
                    (yyval.num) = LOGICAL_OP;
                ;}
    break;

  case 44:
#line 447 "willardorth.y"
    {
                    prRule("N_MULTOP_ARITH", "T_MULT");
                ;}
    break;

  case 45:
#line 451 "willardorth.y"
    {
                    prRule("N_MULTOP_ARITH", "T_DIV");
                ;}
    break;

  case 46:
#line 456 "willardorth.y"
    {
                    prRule("N_MULTOP_LOGIC", "T_AND");
                ;}
    break;

  case 47:
#line 461 "willardorth.y"
    {
                    prRule("N_MULTOPLST", "epsilon");
                ;}
    break;

  case 48:
#line 465 "willardorth.y"
    {
                    prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
                    if ((yyvsp[(1) - (3)].num) == ARITHMETIC_OP) {
                        if ((yyvsp[(2) - (3)].typeInfo).type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ((yyvsp[(1) - (3)].num)  == LOGICAL_OP) {
                        if ((yyvsp[(2) - (3)].typeInfo).type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                ;}
    break;

  case 49:
#line 479 "willardorth.y"
    {
                    prRule("N_OUTPUT", "N_EXPR");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                ;}
    break;

  case 50:
#line 485 "willardorth.y"
    {
                    prRule("N_OUTPUTLST", "epsilon");
                ;}
    break;

  case 51:
#line 489 "willardorth.y"
    {
                    prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
                ;}
    break;

  case 52:
#line 494 "willardorth.y"
    {
                    // when inside the procedures block, the static nesting level is increased
                    staticNestingLevel++;
                    blockLevel = 0;
                ;}
    break;

  case 53:
#line 500 "willardorth.y"
    {
                    prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
                    staticNestingLevel--;
                ;}
    break;

  case 54:
#line 506 "willardorth.y"
    {
                        prRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
                        TypeInfo info;
                        info.type = PROCEDURE;
                        info.startIndex = NOT_APPLICABLE;
                        info.endIndex = NOT_APPLICABLE;
                        info.baseType = NOT_APPLICABLE;
                        info.nestingLevel = staticNestingLevel;
                        info.labelNum = genLabelNum();
                        procStack.push(make_pair(string((yyvsp[(2) - (3)].text)), info));
                        beginScope();
                    ;}
    break;

  case 55:
#line 520 "willardorth.y"
    {
                    prRule("N_PROCDECPART", "epsilon");
                ;}
    break;

  case 56:
#line 524 "willardorth.y"
    {
                    prRule("N_PROCDECPART", "N_PROCDEC T_SCOLON N_PROCDECPART");
                ;}
    break;

  case 57:
#line 529 "willardorth.y"
    {
                    prRule("N_PROCIDENT", "T_IDENT");
                    if (!checkSymbolTables((yyvsp[(1) - (1)].text))) {
                        yyerror("Undefined identifier");
                    }
                ;}
    break;

  case 58:
#line 537 "willardorth.y"
    {
                    prRule("N_PROCSTMT", "N_PROCIDENT");
                    TypeInfo info = getFromSymbolTables(string((yyvsp[(1) - (1)].text)));
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
                        }
                    } else {
                        yyerror("Procedure not found");
                    }
                ;}
    break;

  case 59:
#line 561 "willardorth.y"
    {
                    // Print out init line
                    cout << "init " 
                         << (globalsLabelNum = genLabelNum()) << ", 20, " 
                         << (stackLabelNum = genLabelNum()) << ", " 
                         << (codeLabelNum = genLabelNum()) << ", " 
                         << (entryPointLabelNum = genLabelNum()) << endl;

                    // Label for globals allocation
                    printLabel(globalsLabelNum);

                    prRule("N_PROG","N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
                    TypeInfo info;
                    info.type = PROGRAM;
                    info.startIndex = NOT_APPLICABLE;
                    info.endIndex = NOT_APPLICABLE;
                    info.baseType = NOT_APPLICABLE;
                    addToSymbolTable((yyvsp[(2) - (3)].text), info);
                ;}
    break;

  case 61:
#line 583 "willardorth.y"
    {
                    prRule("N_PROGLBL", "T_PROG");
                    beginScope();
                ;}
    break;

  case 62:
#line 589 "willardorth.y"
    {
                    if ((yyvsp[(3) - (5)].typeInfo).type != INT && (yyvsp[(3) - (5)].typeInfo).type != CHAR)
                      yyerror("Input variable must be of type integer or char");
                    prRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
                ;}
    break;

  case 63:
#line 596 "willardorth.y"
    {
                    prRule("N_RELOP", "T_LT");
                ;}
    break;

  case 64:
#line 600 "willardorth.y"
    {
                    prRule("N_RELOP", "T_GT");
                ;}
    break;

  case 65:
#line 604 "willardorth.y"
    {
                    prRule("N_RELOP", "T_LE");
                ;}
    break;

  case 66:
#line 608 "willardorth.y"
    {
                    prRule("N_RELOP", "T_GE");
                ;}
    break;

  case 67:
#line 612 "willardorth.y"
    {
                    prRule("N_RELOP", "T_EQ");
                ;}
    break;

  case 68:
#line 616 "willardorth.y"
    {
                    prRule("N_RELOP", "T_NE");
                ;}
    break;

  case 69:
#line 621 "willardorth.y"
    {
                    prRule("N_SIGN", "epsilon");
                    (yyval.text) = strdup("+");
                ;}
    break;

  case 70:
#line 626 "willardorth.y"
    {
                    prRule("N_SIGN", "T_PLUS");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 71:
#line 631 "willardorth.y"
    {
                    prRule("N_SIGN", "T_MINUS");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 72:
#line 637 "willardorth.y"
    {
                    prRule("N_SIMPLE", "T_INT");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 73:
#line 645 "willardorth.y"
    {
                    prRule("N_SIMPLE", "T_CHAR");
                    (yyval.typeInfo).type = CHAR;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 74:
#line 653 "willardorth.y"
    {
                    prRule("N_SIMPLE", "T_BOOL");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 75:
#line 662 "willardorth.y"
    {
                    prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (2)].typeInfo));
                ;}
    break;

  case 76:
#line 668 "willardorth.y"
    {
                    prRule("N_STMT", "N_ASSIGN");
                ;}
    break;

  case 77:
#line 672 "willardorth.y"
    {
                    prRule("N_STMT", "N_PROCSTMT");
                ;}
    break;

  case 78:
#line 676 "willardorth.y"
    {
                    prRule("N_STMT", "N_READ");
                ;}
    break;

  case 79:
#line 680 "willardorth.y"
    {
                    prRule("N_STMT", "N_WRITE");
                ;}
    break;

  case 80:
#line 684 "willardorth.y"
    {
                    prRule("N_STMT", "N_CONDITION");
                ;}
    break;

  case 81:
#line 688 "willardorth.y"
    {
                    prRule("N_STMT", "N_WHILE");
                ;}
    break;

  case 82:
#line 692 "willardorth.y"
    {
                    prRule("N_STMT", "N_COMPOUND");
                ;}
    break;

  case 83:
#line 697 "willardorth.y"
    {
                    prRule("N_STMTLST", "epsilon");
                ;}
    break;

  case 84:
#line 701 "willardorth.y"
    {
                    prRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
                ;}
    break;

  case 85:
#line 706 "willardorth.y"
    {
                    prRule("N_STMTPART", "N_COMPOUND");
                ;}
    break;

  case 86:
#line 711 "willardorth.y"
    {
                    prRule("N_TERM", "N_FACTOR N_MULTOPLST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (2)].typeInfo));
                ;}
    break;

  case 87:
#line 717 "willardorth.y"
    {
                    prRule("N_TYPE", "N_SIMPLE");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (1)].typeInfo));
                ;}
    break;

  case 88:
#line 722 "willardorth.y"
    {
                    prRule("N_TYPE", "N_ARRAY");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (1)].typeInfo));
                ;}
    break;

  case 89:
#line 728 "willardorth.y"
    {   
                    prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
                    identList.push_front(string((yyvsp[(1) - (4)].text)));
                    for (list<string>::iterator it = identList.begin(); it != identList.end(); ++it) {
                        addToSymbolTable(*it, (yyvsp[(4) - (4)].typeInfo));
                    }
                    identList.clear();
                ;}
    break;

  case 90:
#line 738 "willardorth.y"
    {
                    prRule("N_VARDECLST", "epsilon");
                ;}
    break;

  case 91:
#line 742 "willardorth.y"
    {
                    prRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
                ;}
    break;

  case 92:
#line 747 "willardorth.y"
    {
                    prRule("N_VARDECPART", "epsilon");
                ;}
    break;

  case 93:
#line 751 "willardorth.y"
    {
                    prRule("N_VARDECPART", "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
                ;}
    break;

  case 94:
#line 756 "willardorth.y"
    {
                    prRule("N_VARIABLE", "N_ENTIREVAR");
                    //Again, have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an integer couldn't be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
                    list<SymbolTable>::iterator it = scopeStack.begin();
                    while (it != scopeStack.end() && info.type == NOT_FOUND) {
                        info = it->findAndGetEntry(string((yyvsp[(1) - (1)].text)));
                        it ++;
                    }
                    if (info.type == NOT_FOUND) {
                        yyerror("? shouldn't get here 2");
                    }
                    (yyval.typeInfo) = info;
                ;}
    break;

  case 95:
#line 772 "willardorth.y"
    {
                    prRule("N_VARIABLE", "N_IDXVAR");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                ;}
    break;

  case 96:
#line 778 "willardorth.y"
    {
                    prRule("N_VARIDENT", "T_IDENT");
                    if (!checkSymbolTables((yyvsp[(1) - (1)].text))) {
                        yyerror("Undefined identifier");
                    }
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 97:
#line 787 "willardorth.y"
    {
                    if ((yyvsp[(2) - (2)].typeInfo).type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                ;}
    break;

  case 98:
#line 793 "willardorth.y"
    {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                ;}
    break;

  case 99:
#line 798 "willardorth.y"
    {
                    if ((yyvsp[(3) - (5)].typeInfo).type != INT && (yyvsp[(3) - (5)].typeInfo).type != CHAR)
                        yyerror("Output expression must be of type integer or char");
                    prRule("N_WRITE", "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2545 "willardorth.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 804 "willardorth.y"


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



