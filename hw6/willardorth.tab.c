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
#line 83 "willardorth.y"
{
    int num;
    char* text;
    TypeInfo typeInfo;
}
/* Line 193 of yacc.c.  */
#line 274 "willardorth.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 287 "willardorth.tab.c"

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
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    16,
      17,    22,    29,    31,    32,    37,    38,    39,    45,    47,
      49,    50,    56,    60,    63,    68,    70,    72,    74,    76,
      78,    82,    85,    87,    91,    94,    96,    97,   101,   103,
     107,   112,   113,   117,   119,   122,   124,   126,   128,   130,
     132,   133,   134,   139,   141,   142,   146,   147,   151,   155,
     156,   160,   162,   164,   165,   172,   174,   180,   182,   184,
     186,   188,   190,   192,   193,   195,   197,   199,   201,   203,
     206,   208,   210,   212,   214,   216,   218,   220,   221,   225,
     227,   230,   232,   234,   239,   240,   244,   245,   250,   252,
     254,   256,   257,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    94,    -1,    53,    -1,    54,    -1,     6,
      -1,     8,    -1,    37,    -1,    -1,    -1,    52,   105,    56,
      55,    -1,    24,    20,    76,    21,    36,   100,    -1,    70,
      -1,    -1,   110,    60,    12,    71,    -1,    -1,    -1,   109,
      62,    91,    63,   104,    -1,    41,    -1,    32,    -1,    -1,
      25,    66,   102,   103,    31,    -1,    33,    71,    68,    -1,
      48,   102,    -1,    48,   102,    49,   102,    -1,    80,    -1,
      29,    -1,    64,    -1,   111,    -1,   101,    -1,   101,    98,
     101,    -1,    99,   110,    -1,    69,    -1,     3,    71,     4,
      -1,    35,    72,    -1,    42,    -1,    -1,     7,    73,    74,
      -1,    80,    -1,    75,    10,    75,    -1,    58,    20,    71,
      21,    -1,    -1,     7,    79,    78,    -1,   110,    -1,    99,
      30,    -1,    82,    -1,    83,    -1,     5,    -1,    28,    -1,
      23,    -1,    -1,    -1,    81,    72,    85,    84,    -1,    71,
      -1,    -1,     7,    86,    87,    -1,    -1,    90,    89,    61,
      -1,    38,    42,    13,    -1,    -1,    88,    13,    91,    -1,
      42,    -1,    92,    -1,    -1,    96,    42,    13,    95,    61,
       9,    -1,    39,    -1,    40,     3,    79,    78,     4,    -1,
      14,    -1,    18,    -1,    15,    -1,    19,    -1,    17,    -1,
      16,    -1,    -1,     6,    -1,     8,    -1,    34,    -1,    27,
      -1,    26,    -1,   105,    55,    -1,    59,    -1,    93,    -1,
      97,    -1,   114,    -1,    67,    -1,   112,    -1,    65,    -1,
      -1,    13,   102,   103,    -1,    65,    -1,    72,    84,    -1,
     100,    -1,    57,    -1,    73,    74,    11,   106,    -1,    -1,
     107,    13,   108,    -1,    -1,    43,   107,    13,   108,    -1,
      70,    -1,    77,    -1,    42,    -1,    -1,    44,    71,   113,
      22,   102,    -1,    45,     3,    86,    87,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   139,   144,   149,   154,   160,   166,   170,
     169,   193,   202,   209,   208,   229,   245,   228,   257,   262,
     269,   268,   293,   298,   302,   307,   318,   330,   339,   345,
     350,   384,   399,   404,   409,   421,   428,   431,   437,   443,
     455,   486,   489,   494,   500,   510,   515,   521,   526,   532,
     538,   542,   541,   565,   577,   580,   586,   585,   597,   612,
     615,   620,   628,   653,   652,   674,   680,   687,   692,   697,
     702,   707,   712,   719,   723,   728,   734,   742,   750,   759,
     765,   769,   773,   777,   781,   785,   789,   795,   798,   803,
     808,   814,   819,   825,   843,   846,   852,   855,   860,   876,
     882,   892,   891,   902
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
  "N_ADDOP_ARITH", "N_ADDOP_LOGIC", "N_ADDOPLST", "@1", "N_ARRAY",
  "N_ARRAYVAR", "N_ASSIGN", "@2", "N_BLOCK", "@3", "@4", "N_BOOLCONST",
  "N_COMPOUND", "@5", "N_CONDITION", "N_THEN_PART", "N_CONST",
  "N_ENTIREVAR", "N_EXPR", "N_FACTOR", "N_IDENT", "N_IDENTLST", "N_IDX",
  "N_IDXRANGE", "N_IDXVAR", "N_INPUTLST", "N_INPUTVAR", "N_INTCONST",
  "N_MULTOP", "N_MULTOP_ARITH", "N_MULTOP_LOGIC", "N_MULTOPLST", "@6",
  "N_OUTPUT", "N_OUTPUTLST", "N_PROCDEC", "@7", "N_PROCHDR",
  "N_PROCDECPART", "N_PROCIDENT", "N_PROCSTMT", "N_PROG", "@8",
  "N_PROGLBL", "N_READ", "N_RELOP", "N_SIGN", "N_SIMPLE", "N_SIMPLEEXPR",
  "N_STMT", "N_STMTLST", "N_STMTPART", "N_TERM", "N_TYPE", "N_VARDEC",
  "N_VARDECLST", "N_VARDECPART", "N_VARIABLE", "N_VARIDENT", "N_WHILE",
  "@9", "N_WRITE", 0
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
       0,    50,    51,    52,    52,    53,    53,    54,    55,    56,
      55,    57,    58,    60,    59,    62,    63,    61,    64,    64,
      66,    65,    67,    68,    68,    69,    69,    69,    70,    71,
      71,    72,    72,    72,    72,    73,    74,    74,    75,    76,
      77,    78,    78,    79,    80,    81,    81,    82,    82,    83,
      84,    85,    84,    86,    87,    87,    89,    88,    90,    91,
      91,    92,    93,    95,    94,    96,    97,    98,    98,    98,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   101,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   104,
     105,   106,   106,   107,   108,   108,   109,   109,   110,   110,
     111,   113,   112,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     0,     0,
       4,     6,     1,     0,     4,     0,     0,     5,     1,     1,
       0,     5,     3,     2,     4,     1,     1,     1,     1,     1,
       3,     2,     1,     3,     2,     1,     0,     3,     1,     3,
       4,     0,     3,     1,     2,     1,     1,     1,     1,     1,
       0,     0,     4,     1,     0,     3,     0,     3,     3,     0,
       3,     1,     1,     0,     6,     1,     5,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     1,     1,     4,     0,     3,     0,     4,     1,     1,
       1,     0,     5,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    65,     0,     2,     0,     1,     0,    63,    96,     0,
       0,    15,    35,    36,     0,    64,    59,     0,     0,    94,
       0,     0,    56,    16,    36,     0,     0,    97,     0,    59,
      96,     0,    37,     0,    78,    77,    76,    92,    91,    93,
      94,    58,    60,    57,    20,    89,    17,    73,    95,     0,
      74,    75,     0,     0,    38,     0,    73,     0,    61,    73,
       0,     0,    80,    86,    84,    98,    99,    62,    81,    82,
      87,    13,    28,    85,    83,    73,     0,    44,    73,    26,
      19,    73,    18,    27,    32,     0,    50,    25,     0,    29,
       8,     0,   101,    73,    73,     0,     0,     0,    39,     0,
       0,    34,     0,    22,    47,    49,    48,    73,    45,    46,
      90,   100,    31,    67,    69,    72,    71,    68,    70,    73,
       5,     6,     7,    73,     3,     4,    79,    41,    43,     0,
      53,    54,     0,    87,    21,    73,    11,    33,    23,    51,
      30,     9,     0,     0,     0,    73,     0,    40,    88,    14,
       0,    50,     8,    41,    66,   102,    54,   103,    24,    52,
      10,    42,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   123,   124,   125,   126,   152,    37,    61,    62,
      97,    10,    16,    31,    83,    63,    49,    64,   103,    84,
      65,   130,    86,    13,    18,    52,    53,    66,   143,   127,
      87,   107,   108,   109,   110,   151,   131,   146,    21,    30,
      22,    23,    67,    68,     3,     8,     4,    69,   119,    88,
      38,    89,    70,    96,    46,    90,    39,    26,    27,    11,
      71,    72,    73,   129,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int8 yypact[] =
{
     -25,   -95,    31,   -95,    -7,   -95,    24,   -95,    -9,     1,
      36,   -95,   -95,    40,    38,   -95,    11,     1,    42,     1,
      12,    44,   -95,   -95,    40,    -8,    47,   -95,    49,    11,
      -9,    30,   -95,    52,   -95,   -95,   -95,   -95,   -95,   -95,
       1,   -95,   -95,   -95,   -95,   -95,   -95,    21,   -95,    19,
     -95,   -95,    61,    53,   -95,    43,     7,    72,     5,     7,
      73,    57,   -95,   -95,   -95,    58,   -95,   -95,   -95,   -95,
      67,   -95,   -95,   -95,   -95,    21,    45,   -95,     7,   -95,
     -95,     7,   -95,   -95,   -95,    34,    18,   -95,   -18,    51,
       3,    41,   -95,     7,     7,    19,    54,    74,   -95,    -6,
      80,   -95,    19,   -95,   -95,   -95,   -95,     7,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,     7,
     -95,   -95,   -95,     7,   -95,   -95,   -95,    81,   -95,    65,
     -95,    82,    69,    67,   -95,     7,   -95,   -95,    46,   -95,
     -95,   -95,    41,    87,    19,     7,    88,   -95,   -95,   -95,
      19,    18,     3,    81,   -95,   -95,    82,   -95,   -95,   -95,
     -95,   -95,   -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -95,   -95,   -95,   -59,   -95,   -95,   -95,   -95,
     -95,    64,   -95,   -95,   -95,    66,   -95,   -95,   -95,   -95,
     -95,   -56,   -75,    79,    75,    23,   -95,   -95,   -53,   -41,
     -45,   -95,   -95,   -95,   -49,   -95,   -40,   -52,   -95,   -95,
     -95,    77,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -42,
       4,   -12,   -94,   -24,   -95,   -15,   -95,   101,    71,   -95,
     -84,   -95,   -95,   -95,   -95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -101
static const yytype_int16 yytable[] =
{
      85,   133,    54,    92,   112,    55,   101,   128,   138,   120,
      78,   121,    77,    50,     1,    51,    33,  -100,    34,    35,
      34,    35,   100,   104,   111,  -100,    36,    50,    36,    51,
      54,     5,   139,    55,     9,     6,    79,     7,   132,    80,
     122,   105,    81,    12,    44,    15,   106,    17,    82,    20,
     155,    19,    56,    25,    28,    44,   158,    29,   128,    57,
      40,    58,    41,    59,    60,   113,   114,   115,   116,   117,
     118,    75,    47,    77,    76,    91,    93,    94,   -12,   149,
      95,    99,   102,   111,   137,   134,   135,   144,   142,   145,
     147,   154,   157,   160,    43,   150,    24,    45,    98,    32,
     161,   153,   159,   136,   162,   156,    42,   140,   141,   148,
      14,    48
};

static const yytype_uint8 yycheck[] =
{
      56,    95,    47,    59,    88,    47,    81,    91,   102,     6,
       3,     8,    30,     6,    39,     8,    24,    12,    26,    27,
      26,    27,    78,     5,    42,    20,    34,     6,    34,     8,
      75,     0,   107,    75,    43,    42,    29,    13,    94,    32,
      37,    23,    35,    42,    25,     9,    28,     7,    41,    38,
     144,    13,    33,    11,    42,    25,   150,    13,   142,    40,
      13,    42,    13,    44,    45,    14,    15,    16,    17,    18,
      19,    10,    20,    30,    21,     3,     3,    20,    20,   135,
      13,    36,    48,    42,     4,    31,    12,    22,     7,     7,
      21,     4,     4,   152,    30,    49,    17,    31,    75,    24,
     153,   142,   151,    99,   156,   145,    29,   119,   123,   133,
       9,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    51,    94,    96,     0,    42,    13,    95,    43,
      61,   109,    42,    73,   107,     9,    62,     7,    74,    13,
      38,    88,    90,    91,    73,    11,   107,   108,    42,    13,
      89,    63,    74,    24,    26,    27,    34,    57,   100,   106,
      13,    13,    91,    61,    25,    65,   104,    20,   108,    66,
       6,     8,    75,    76,    80,    99,    33,    40,    42,    44,
      45,    58,    59,    65,    67,    70,    77,    92,    93,    97,
     102,   110,   111,   112,   114,    10,    21,    30,     3,    29,
      32,    35,    41,    64,    69,    71,    72,    80,    99,   101,
     105,     3,    71,     3,    20,    13,   103,    60,    75,    36,
      71,    72,    48,    68,     5,    23,    28,    81,    82,    83,
      84,    42,   110,    14,    15,    16,    17,    18,    19,    98,
       6,     8,    37,    52,    53,    54,    55,    79,   110,   113,
      71,    86,    71,   102,    31,    12,   100,     4,   102,    72,
     101,   105,     7,    78,    22,     7,    87,    21,   103,    71,
      49,    85,    56,    79,     4,   102,    86,     4,   102,    84,
      55,    78,    87
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
#line 129 "willardorth.y"
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
#line 140 "willardorth.y"
    {
                    prRule("N_ADDOP", "N_ADDOP_ARITH");
                    (yyval.num) = (yyvsp[(1) - (1)].num);
                ;}
    break;

  case 4:
#line 145 "willardorth.y"
    {
                    prRule("N_ADDOP", "N_ADDOP_LOGIC");
                    (yyval.num) = LOGICAL_OP;
                ;}
    break;

  case 5:
#line 150 "willardorth.y"
    {
                    prRule("N_ADDOP_ARITH", "T_PLUS");
                    (yyval.num) = PLUS_OP;
                ;}
    break;

  case 6:
#line 155 "willardorth.y"
    {
                    prRule("N_ADDOP_ARITH", "T_MINUS");
                    (yyval.num) = MINUS_OP;
                ;}
    break;

  case 7:
#line 161 "willardorth.y"
    {
                    prRule("N_ADDOP_LOGIC", "T_OR");
                ;}
    break;

  case 8:
#line 166 "willardorth.y"
    {
                    prRule("N_ADDOPLST", "epsilon");
                ;}
    break;

  case 9:
#line 170 "willardorth.y"
    {
                    if ((yyvsp[(1) - (2)].num) == PLUS_OP) {
                        printOpCode("add");
                    } else if ((yyvsp[(1) - (2)].num) == MINUS_OP) {
                        printOpCode("sub");
                    } else if ((yyvsp[(1) - (2)].num) == LOGICAL_OP) {
                        printOpCode("or");
                    }
                ;}
    break;

  case 10:
#line 180 "willardorth.y"
    {
                    prRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
                    if ((yyvsp[(1) - (4)].num) == PLUS_OP || (yyvsp[(1) - (4)].num) == MINUS_OP) {
                        if ((yyvsp[(2) - (4)].typeInfo).type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ((yyvsp[(1) - (4)].num) == LOGICAL_OP) {
                        if ((yyvsp[(2) - (4)].typeInfo).type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                ;}
    break;

  case 11:
#line 194 "willardorth.y"
    {
                    prRule("N_ARRAY","T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
                    (yyval.typeInfo).type = ARRAY;
                    (yyval.typeInfo).startIndex = (yyvsp[(3) - (6)].typeInfo).startIndex;
                    (yyval.typeInfo).endIndex = (yyvsp[(3) - (6)].typeInfo).endIndex;
                    (yyval.typeInfo).baseType = (yyvsp[(6) - (6)].typeInfo).type;
                ;}
    break;

  case 12:
#line 203 "willardorth.y"
    {
                    prRule("N_ARRAYVAR", "N_ENTIREVAR");
                    (yyval.text) = (yyvsp[(1) - (1)].text);   
                ;}
    break;

  case 13:
#line 209 "willardorth.y"
    {
                    stringstream ss;
                    ss << (yyvsp[(1) - (1)].typeInfo).offset << ", " << "0";
                    printOpCodeSingleAddr("la", getStr(ss));
                ;}
    break;

  case 14:
#line 215 "willardorth.y"
    {
                    if ((yyvsp[(1) - (4)].typeInfo).type == ARRAY)
                        yyerror("Cannot make assignment to an array");
                    if ((yyvsp[(1) - (4)].typeInfo).type != (yyvsp[(4) - (4)].typeInfo).type)
                    {
                      if ((yyvsp[(1) - (4)].typeInfo).type == PROCEDURE || (yyvsp[(4) - (4)].typeInfo).type == PROCEDURE)
                          yyerror("Procedure/variable mismatch");
                      yyerror("Expression must be of same type as variable");
                    }
                    prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");   
                    printOpCode("st");
                ;}
    break;

  case 15:
#line 229 "willardorth.y"
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
                ;}
    break;

  case 16:
#line 245 "willardorth.y"
    {
                    if (procStack.empty()) {
                        printLabel(entryPointLabelNum);
                    }
                ;}
    break;

  case 17:
#line 251 "willardorth.y"
    {
                    prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
                    endScope();

                ;}
    break;

  case 18:
#line 258 "willardorth.y"
    {
                    prRule("N_BOOLCONST", "T_TRUE");
                    printOpCodeSingleAddr("lc", "1");
                ;}
    break;

  case 19:
#line 263 "willardorth.y"
    {
                    prRule("N_BOOLCONST", "T_FALSE");
                    printOpCodeSingleAddr("lc", "0");
                ;}
    break;

  case 20:
#line 269 "willardorth.y"
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

  case 21:
#line 281 "willardorth.y"
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

  case 22:
#line 294 "willardorth.y"
    {
                    prRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT N_ELSE_PART");
                ;}
    break;

  case 23:
#line 299 "willardorth.y"
    {
                    prRule("N_THEN_PART", "T_THEN N_STMT");
                ;}
    break;

  case 24:
#line 303 "willardorth.y"
    {
                    prRule("N_THEN_PART", "T_THEN N_STMT T_ELSE N_STMT");
                ;}
    break;

  case 25:
#line 308 "willardorth.y"
    {
                    prRule("N_CONST", "N_INTCONST");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    stringstream ss;
                    ss << (yyvsp[(1) - (1)].num);
                    printOpCodeSingleAddr("lc", getStr(ss));
                ;}
    break;

  case 26:
#line 319 "willardorth.y"
    {
                    prRule("N_CONST", "T_CHARCONST");
                    (yyval.typeInfo).type = CHAR;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                    int val = int((yyvsp[(1) - (1)].text)[1]);
                    stringstream ss;
                    ss << val;
                    printOpCodeSingleAddr("lc", getStr(ss));
                ;}
    break;

  case 27:
#line 331 "willardorth.y"
    {
                    prRule("N_CONST", "N_BOOLCONST");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 28:
#line 340 "willardorth.y"
    {
                    prRule("N_ENTIREVAR", "N_VARIDENT");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 29:
#line 346 "willardorth.y"
    {
                    prRule("N_EXPR", "N_SIMPLEEXPR");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                ;}
    break;

  case 30:
#line 351 "willardorth.y"
    {

                    prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
                    if ((yyvsp[(1) - (3)].typeInfo).type != (yyvsp[(3) - (3)].typeInfo).type) {
                        yyerror("Expressions must both be int, or both char, or both boolean");
                    }
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;

                    switch ((yyvsp[(2) - (3)].num)) {
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
                ;}
    break;

  case 31:
#line 385 "willardorth.y"
    {
                    prRule("N_FACTOR", "N_SIGN N_VARIABLE");
                    if (strcmp((yyvsp[(1) - (2)].text), "-") == 0 && (yyvsp[(2) - (2)].typeInfo).type != INT) {
                        yyerror("Expression must be of type integer");
                    }
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(2) - (2)].typeInfo));
                    stringstream ss;
                    ss << (yyvsp[(2) - (2)].typeInfo).offset;
                    printOpCodeDoubleAddr("la", getStr(ss), "0");
                    printOpCode("deref");
                    if (strcmp((yyvsp[(1) - (2)].text), "-") == 0) {
                        printOpCode("neg");
                    }
                ;}
    break;

  case 32:
#line 400 "willardorth.y"
    {
                    prRule("N_FACTOR", "N_CONST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (1)].typeInfo));
                ;}
    break;

  case 33:
#line 405 "willardorth.y"
    {
                    prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(2) - (3)].typeInfo));
                ;}
    break;

  case 34:
#line 410 "willardorth.y"
    {
                    prRule("N_FACTOR", "T_NOT N_FACTOR");
                    if ((yyvsp[(2) - (2)].typeInfo).type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(2) - (2)].typeInfo));
                    
                    stringstream ss;
                    printOpCode("not");
                ;}
    break;

  case 35:
#line 422 "willardorth.y"
    {
                    prRule("N_IDENT", "T_IDENT");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 36:
#line 428 "willardorth.y"
    {
                    prRule("N_IDENTLST", "epsilon");
                ;}
    break;

  case 37:
#line 432 "willardorth.y"
    {
                    prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
                    identList.push_front(string((yyvsp[(2) - (3)].text)));
                ;}
    break;

  case 38:
#line 438 "willardorth.y"
    {
                    prRule("N_IDX", "N_INTCONST");
                    (yyval.num) = (yyvsp[(1) - (1)].num);
                ;}
    break;

  case 39:
#line 444 "willardorth.y"
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

  case 40:
#line 456 "willardorth.y"
    {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
                    //Have to check the entire stack, not just the front (was leading to a bug in comboNoErrors where an array was not able to be found)
                    //TypeInfo info = scopeStack.front().findAndGetEntry(string($1));
                    TypeInfo info = {NOT_FOUND,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE,NOT_APPLICABLE};
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

  case 41:
#line 486 "willardorth.y"
    {
                    prRule("N_INPUTLST", "epsilon");
                ;}
    break;

  case 42:
#line 490 "willardorth.y"
    {
                    prRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
                ;}
    break;

  case 43:
#line 495 "willardorth.y"
    {
                    prRule("N_INPUTVAR", "N_VARIABLE");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                ;}
    break;

  case 44:
#line 501 "willardorth.y"
    {
                    prRule("N_INTCONST", "N_SIGN T_INTCONST");
                    if (strcmp((yyvsp[(1) - (2)].text), "+") == 0) {
                        (yyval.num) = (yyvsp[(2) - (2)].num);
                    } else if (strcmp((yyvsp[(1) - (2)].text), "-") == 0) {
                        (yyval.num) = -(yyvsp[(2) - (2)].num);
                    }
                ;}
    break;

  case 45:
#line 511 "willardorth.y"
    {
                    prRule("N_MULTOP", "N_MULTOP_ARITH");
                    (yyval.num) = (yyvsp[(1) - (1)].num);
                ;}
    break;

  case 46:
#line 516 "willardorth.y"
    {
                    prRule("N_MULTOP", "N_MULTOP_LOGIC");
                    (yyval.num) = LOGICAL_OP;
                ;}
    break;

  case 47:
#line 522 "willardorth.y"
    {
                    prRule("N_MULTOP_ARITH", "T_MULT");
                    (yyval.num) = MULT_OP;
                ;}
    break;

  case 48:
#line 527 "willardorth.y"
    {
                    prRule("N_MULTOP_ARITH", "T_DIV");
                    (yyval.num) = DIV_OP;
                ;}
    break;

  case 49:
#line 533 "willardorth.y"
    {
                    prRule("N_MULTOP_LOGIC", "T_AND");
                ;}
    break;

  case 50:
#line 538 "willardorth.y"
    {
                    prRule("N_MULTOPLST", "epsilon");
                ;}
    break;

  case 51:
#line 542 "willardorth.y"
    {
                    if ((yyvsp[(1) - (2)].num) == MULT_OP) {
                        printOpCode("mult");
                    } else if ((yyvsp[(1) - (2)].num) == DIV_OP) {
                        printOpCode("div");
                    } else if ((yyvsp[(1) - (2)].num) == LOGICAL_OP) {
                        printOpCode("and");
                    }
                ;}
    break;

  case 52:
#line 552 "willardorth.y"
    {
                    prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
                    if ((yyvsp[(1) - (4)].num) == DIV_OP || (yyvsp[(1) - (4)].num) == MULT_OP) {
                        if ((yyvsp[(2) - (4)].typeInfo).type != INT) {
                            yyerror("Expression must be of type integer");
                        }
                    } else if ((yyvsp[(1) - (4)].num)  == LOGICAL_OP) {
                        if ((yyvsp[(2) - (4)].typeInfo).type != BOOL) {
                            yyerror("Expression must be of type boolean");
                        }
                    }
                ;}
    break;

  case 53:
#line 566 "willardorth.y"
    {
                    prRule("N_OUTPUT", "N_EXPR");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                    if ((yyvsp[(1) - (1)].typeInfo).type == INT) {
                        printOpCode("iwrite");
                    } else if ((yyvsp[(1) - (1)].typeInfo).type == CHAR) {
                        printOpCode("cwrite");
                    }
                ;}
    break;

  case 54:
#line 577 "willardorth.y"
    {
                    prRule("N_OUTPUTLST", "epsilon");
                ;}
    break;

  case 55:
#line 581 "willardorth.y"
    {
                    prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
                ;}
    break;

  case 56:
#line 586 "willardorth.y"
    {
                    // when inside the procedures block, the static nesting level is increased
                    staticNestingLevel++;
                    blockLevel = 0;
                ;}
    break;

  case 57:
#line 592 "willardorth.y"
    {
                    prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
                    staticNestingLevel--;
                ;}
    break;

  case 58:
#line 598 "willardorth.y"
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

  case 59:
#line 612 "willardorth.y"
    {
                    prRule("N_PROCDECPART", "epsilon");
                ;}
    break;

  case 60:
#line 616 "willardorth.y"
    {
                    prRule("N_PROCDECPART", "N_PROCDEC T_SCOLON N_PROCDECPART");
                ;}
    break;

  case 61:
#line 621 "willardorth.y"
    {
                    prRule("N_PROCIDENT", "T_IDENT");
                    if (!checkSymbolTables((yyvsp[(1) - (1)].text))) {
                        yyerror("Undefined identifier");
                    }
                ;}
    break;

  case 62:
#line 629 "willardorth.y"
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

  case 63:
#line 653 "willardorth.y"
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
                    addToSymbolTable((yyvsp[(2) - (3)].text), info);
                ;}
    break;

  case 65:
#line 675 "willardorth.y"
    {
                    prRule("N_PROGLBL", "T_PROG");
                    beginScope();
                ;}
    break;

  case 66:
#line 681 "willardorth.y"
    {
                    if ((yyvsp[(3) - (5)].typeInfo).type != INT && (yyvsp[(3) - (5)].typeInfo).type != CHAR)
                      yyerror("Input variable must be of type integer or char");
                    prRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
                ;}
    break;

  case 67:
#line 688 "willardorth.y"
    {
                    prRule("N_RELOP", "T_LT");
                    (yyval.num) = LT;
                ;}
    break;

  case 68:
#line 693 "willardorth.y"
    {
                    prRule("N_RELOP", "T_GT");
                    (yyval.num) = GT;
                ;}
    break;

  case 69:
#line 698 "willardorth.y"
    {
                    prRule("N_RELOP", "T_LE");
                    (yyval.num) = LE;
                ;}
    break;

  case 70:
#line 703 "willardorth.y"
    {
                    prRule("N_RELOP", "T_GE");
                    (yyval.num) = GE;
                ;}
    break;

  case 71:
#line 708 "willardorth.y"
    {
                    prRule("N_RELOP", "T_EQ");
                    (yyval.num) = EQ;
                ;}
    break;

  case 72:
#line 713 "willardorth.y"
    {
                    prRule("N_RELOP", "T_NE");
                    (yyval.num) = NE;
                ;}
    break;

  case 73:
#line 719 "willardorth.y"
    {
                    prRule("N_SIGN", "epsilon");
                    (yyval.text) = strdup("+");
                ;}
    break;

  case 74:
#line 724 "willardorth.y"
    {
                    prRule("N_SIGN", "T_PLUS");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 75:
#line 729 "willardorth.y"
    {
                    prRule("N_SIGN", "T_MINUS");
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 76:
#line 735 "willardorth.y"
    {
                    prRule("N_SIMPLE", "T_INT");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 77:
#line 743 "willardorth.y"
    {
                    prRule("N_SIMPLE", "T_CHAR");
                    (yyval.typeInfo).type = CHAR;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 78:
#line 751 "willardorth.y"
    {
                    prRule("N_SIMPLE", "T_BOOL");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).startIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).endIndex = NOT_APPLICABLE;
                    (yyval.typeInfo).baseType = NOT_APPLICABLE;
                ;}
    break;

  case 79:
#line 760 "willardorth.y"
    {
                    prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (2)].typeInfo));
                ;}
    break;

  case 80:
#line 766 "willardorth.y"
    {
                    prRule("N_STMT", "N_ASSIGN");
                ;}
    break;

  case 81:
#line 770 "willardorth.y"
    {
                    prRule("N_STMT", "N_PROCSTMT");
                ;}
    break;

  case 82:
#line 774 "willardorth.y"
    {
                    prRule("N_STMT", "N_READ");
                ;}
    break;

  case 83:
#line 778 "willardorth.y"
    {
                    prRule("N_STMT", "N_WRITE");
                ;}
    break;

  case 84:
#line 782 "willardorth.y"
    {
                    prRule("N_STMT", "N_CONDITION");
                ;}
    break;

  case 85:
#line 786 "willardorth.y"
    {
                    prRule("N_STMT", "N_WHILE");
                ;}
    break;

  case 86:
#line 790 "willardorth.y"
    {
                    prRule("N_STMT", "N_COMPOUND");
                ;}
    break;

  case 87:
#line 795 "willardorth.y"
    {
                    prRule("N_STMTLST", "epsilon");
                ;}
    break;

  case 88:
#line 799 "willardorth.y"
    {
                    prRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
                ;}
    break;

  case 89:
#line 804 "willardorth.y"
    {
                    prRule("N_STMTPART", "N_COMPOUND");
                ;}
    break;

  case 90:
#line 809 "willardorth.y"
    {
                    prRule("N_TERM", "N_FACTOR N_MULTOPLST");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (2)].typeInfo));
                ;}
    break;

  case 91:
#line 815 "willardorth.y"
    {
                    prRule("N_TYPE", "N_SIMPLE");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (1)].typeInfo));
                ;}
    break;

  case 92:
#line 820 "willardorth.y"
    {
                    prRule("N_TYPE", "N_ARRAY");
                    assignTypeInfo((yyval.typeInfo), (yyvsp[(1) - (1)].typeInfo));
                ;}
    break;

  case 93:
#line 826 "willardorth.y"
    {   
                    prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
                    identList.push_front(string((yyvsp[(1) - (4)].text)));
                    for (list<string>::iterator it = identList.begin(); it != identList.end(); ++it) {
                        (yyvsp[(4) - (4)].typeInfo).nestingLevel = staticNestingLevel;
                        if (procStack.empty()) {
                            (yyvsp[(4) - (4)].typeInfo).offset = 20 + offset;
                        } else {
                            (yyvsp[(4) - (4)].typeInfo).offset = offset;
                        }
                        nextOffset((yyvsp[(4) - (4)].typeInfo), offset);
                        addToSymbolTable(*it, (yyvsp[(4) - (4)].typeInfo));
                    }
                    identList.clear();
                ;}
    break;

  case 94:
#line 843 "willardorth.y"
    {
                    prRule("N_VARDECLST", "epsilon");
                ;}
    break;

  case 95:
#line 847 "willardorth.y"
    {
                    prRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
                ;}
    break;

  case 96:
#line 852 "willardorth.y"
    {
                    prRule("N_VARDECPART", "epsilon");
                ;}
    break;

  case 97:
#line 856 "willardorth.y"
    {
                    prRule("N_VARDECPART", "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
                ;}
    break;

  case 98:
#line 861 "willardorth.y"
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

  case 99:
#line 877 "willardorth.y"
    {
                    prRule("N_VARIABLE", "N_IDXVAR");
                    (yyval.typeInfo) = (yyvsp[(1) - (1)].typeInfo);
                ;}
    break;

  case 100:
#line 883 "willardorth.y"
    {
                    prRule("N_VARIDENT", "T_IDENT");
                    if (!checkSymbolTables((yyvsp[(1) - (1)].text))) {
                        yyerror("Undefined identifier");
                    }
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                ;}
    break;

  case 101:
#line 892 "willardorth.y"
    {
                    if ((yyvsp[(2) - (2)].typeInfo).type != BOOL) {
                        yyerror("Expression must be of type boolean");
                    }
                ;}
    break;

  case 102:
#line 898 "willardorth.y"
    {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                ;}
    break;

  case 103:
#line 903 "willardorth.y"
    {
                    if ((yyvsp[(3) - (5)].typeInfo).type != INT && (yyvsp[(3) - (5)].typeInfo).type != CHAR)
                        yyerror("Output expression must be of type integer or char");
                    prRule("N_WRITE", "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2670 "willardorth.tab.c"
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


#line 909 "willardorth.y"


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



