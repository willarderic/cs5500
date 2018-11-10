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
     T_JP = 258,
     T_JF = 259,
     T_JT = 260,
     T_JS = 261,
     T_JI = 262,
     T_BSS = 263,
     T_ASP = 264,
     T_ST = 265,
     T_PUSH = 266,
     T_POP = 267,
     T_SAVE = 268,
     T_LC = 269,
     T_LV = 270,
     T_LA = 271,
     T_DEREF = 272,
     T_ADD = 273,
     T_SUB = 274,
     T_MULT = 275,
     T_DIV = 276,
     T_MOD = 277,
     T_AND = 278,
     T_OR = 279,
     T_COMMA = 280,
     T_COLON = 281,
     T_EQ = 282,
     T_NE = 283,
     T_LT = 284,
     T_LE = 285,
     T_GT = 286,
     T_GE = 287,
     T_NEG = 288,
     T_NOT = 289,
     T_CREAD = 290,
     T_IREAD = 291,
     T_CWRITE = 292,
     T_IWRITE = 293,
     T_INIT = 294,
     T_HALT = 295,
     T_NCONST = 296,
     T_PCONST = 297,
     T_UNKNOWN = 298,
     T_LABEL = 299,
     T_ENTRY = 300,
     T_END = 301
   };
#endif
/* Tokens.  */
#define T_JP 258
#define T_JF 259
#define T_JT 260
#define T_JS 261
#define T_JI 262
#define T_BSS 263
#define T_ASP 264
#define T_ST 265
#define T_PUSH 266
#define T_POP 267
#define T_SAVE 268
#define T_LC 269
#define T_LV 270
#define T_LA 271
#define T_DEREF 272
#define T_ADD 273
#define T_SUB 274
#define T_MULT 275
#define T_DIV 276
#define T_MOD 277
#define T_AND 278
#define T_OR 279
#define T_COMMA 280
#define T_COLON 281
#define T_EQ 282
#define T_NE 283
#define T_LT 284
#define T_LE 285
#define T_GT 286
#define T_GE 287
#define T_NEG 288
#define T_NOT 289
#define T_CREAD 290
#define T_IREAD 291
#define T_CWRITE 292
#define T_IWRITE 293
#define T_INIT 294
#define T_HALT 295
#define T_NCONST 296
#define T_PCONST 297
#define T_UNKNOWN 298
#define T_LABEL 299
#define T_ENTRY 300
#define T_END 301




/* Copy the first part of user declarations.  */
#line 18 "oal.y"

#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include <list>
#include <stack>
#include <vector>
using namespace std;

#define DEBUG 0   // set to non-zero to see debugging output
#define OUTPUT_TOKENS	     0
#define OUTPUT_PRODUCTIONS 0

typedef char Cstring[80];

Cstring entryLabel = "0";

int lineNum = 1;
int instrxCount = 0;
int entryPointInstrxNum = -1, haltPointInstrxNum = -1;
int displaySize = 0;

// Arithmetic stack holds integers and memory locations 
// (offset & level)
typedef struct { int val1, val2; } arithmeticStackElt;
stack<arithmeticStackElt> arithmeticStack;   

// Execution stack holds instructions locations, display values, 
// and local var values. We're using a vector instead of a stack
// per se; assume it "grows" in index sequence 0, 1, 2, ...
// where 0 is the stack "bottom."
vector<int> executionStack; 

// Display holds execution stack indices and global var values
vector<int> display;

// Individual instructions stored; will reference "instruction  
// location" by vector index
typedef void (*ptrToFunction) (const int, const int, int&);
typedef struct { int op1, op2; ptrToFunction f; } instrx;
vector<instrx> instructions;

// Keep track of defined labels and "jump to" labels 
// for semantic analysis
std::list<string> jumpLocations;
std::list<string> definedLabels;

// Maintain index into instructions vector for each label
typedef struct { string labelName; int instrxNum; } labelInfo;
std::list<labelInfo> labelInstrxNums;

// Function prototypes
void addInstruction(ptrToFunction f, 
                    const int op1 = -1, const int op2 = -1);
void lc(const int op1, const int op2, int& instrxNum);
void la(const int op1, const int op2, int& instrxNum);
void lv(const int op1, const int op2, int& instrxNum);
void iwrite(const int op1, const int op2, int& instrxNum);
void cwrite(const int op1, const int op2, int& instrxNum);
void iread(const int op1, const int op2, int& instrxNum);
void cread(const int op1, const int op2, int& instrxNum);
void add(const int op1, const int op2, int& instrxNum);
void mult(const int op1, const int op2, int& instrxNum);
void div(const int op1, const int op2, int& instrxNum);
void sub(const int op1, const int op2, int& instrxNum);
void mod(const int op1, const int op2, int& instrxNum);
void and_op(const int op1, const int op2, int& instrxNum);
void or_op(const int op1, const int op2, int& instrxNum);
void eq_op(const int op1, const int op2, int& instrxNum);
void ne_op(const int op1, const int op2, int& instrxNum);
void lt_op(const int op1, const int op2, int& instrxNum);
void le_op(const int op1, const int op2, int& instrxNum);
void gt_op(const int op1, const int op2, int& instrxNum);
void ge_op(const int op1, const int op2, int& instrxNum);
void binaryOperation(int opCode);
void not_op(const int op1, const int op2, int& instrxNum);
void neg_op(const int op1, const int op2, int& instrxNum);
void unaryOperation(const int opCode);
void st(const int op1, const int op2, int& instrxNum);
void deref(const int op1, const int op2, int& instrxNum);
void push(const int op1, const int op2, int& instrxNum);
void pop(const int op1, const int op2, int& instrxNum);
void asp(const int op1, const int op2, int& instrxNum);
void save(const int op1, const int op2, int& instrxNum);
void jp(const int op1, const int op2, int& instrxNum);
void jt(const int op1, const int op2, int& instrxNum);
void jf(const int op1, const int op2, int& instrxNum);
void js(const int op1, const int op2, int& instrxNum);
void ji(const int op1, const int op2, int& instrxNum);
void labelInstrx(const int op1, const int op2, int& instrxNum);

// Maintain a list each label ("L.xx") and its
// index into the instructions vector 
void addLabelInstrxNum(const string labelName, 
                       const int instrxNum);
int findLabelInstrxNum(const string labelName);

// Maintain lists of labels defined and jumped to
void addLabel(const string x, std::list<string> &L);
bool findLabel(const string x, std::list<string> L);
bool checkLabels();

// Debugging, initialization, etc. functions
void dumpExecutionStack();
void bail(const char *s);
void initDisplay();
void performEvaluation();

void ignoreComment();
void prRule(const char *, const char *);
void printTokenInfo(const char* tokenType, 
                    const char* lexeme);


int yyerror(const char *s) 
{
  printf("%d: %s\n", lineNum, s);
}

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}



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
#line 146 "oal.y"
{
  int	num;
  Cstring cstring;
  struct { int offset, level; } memLoc;
}
/* Line 193 of yacc.c.  */
#line 322 "oal.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 335 "oal.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   86

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    17,    28,    31,    33,    35,    38,
      40,    43,    46,    48,    50,    52,    53,    56,    58,    60,
      62,    64,    66,    68,    70,    72,    74,    78,    81,    83,
      85,    87,    89,    91,    93,    95,    97,    99,   101,   103,
     105,   107,   109,   111,   113,   115,   117,   119,   121,   123,
     125,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   147,   150,   153,   156,   159,   162,   165
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    52,    56,    53,    59,
      54,    60,    58,    55,    57,    46,    -1,    39,    44,    25,
      42,    25,    44,    25,    44,    25,    44,    -1,    44,    26,
      -1,    51,    -1,    51,    -1,    45,    26,    -1,    51,    -1,
       8,    42,    -1,     8,    42,    -1,    40,    -1,    61,    -1,
      61,    -1,    -1,    61,    62,    -1,    65,    -1,    51,    -1,
      71,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
      41,    -1,    42,    -1,    63,    25,    42,    -1,    66,    44,
      -1,     7,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,    72,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    10,    -1,    17,    -1,     9,    63,    -1,
      11,    64,    -1,    12,    64,    -1,    13,    64,    -1,    14,
      63,    -1,    15,    64,    -1,    16,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   176,   176,   187,   195,   216,   230,   235,   241,   257,
     263,   269,   274,   281,   287,   293,   296,   302,   306,   310,
     314,   318,   322,   326,   331,   336,   342,   350,   369,   375,
     380,   385,   390,   396,   401,   406,   411,   416,   421,   426,
     431,   436,   441,   446,   451,   456,   462,   467,   473,   478,
     484,   489,   495,   500,   505,   510,   515,   520,   525,   530,
     535,   541,   548,   556,   564,   572,   579,   587
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_JP", "T_JF", "T_JT", "T_JS", "T_JI",
  "T_BSS", "T_ASP", "T_ST", "T_PUSH", "T_POP", "T_SAVE", "T_LC", "T_LV",
  "T_LA", "T_DEREF", "T_ADD", "T_SUB", "T_MULT", "T_DIV", "T_MOD", "T_AND",
  "T_OR", "T_COMMA", "T_COLON", "T_EQ", "T_NE", "T_LT", "T_LE", "T_GT",
  "T_GE", "T_NEG", "T_NOT", "T_CREAD", "T_IREAD", "T_CWRITE", "T_IWRITE",
  "T_INIT", "T_HALT", "T_NCONST", "T_PCONST", "T_UNKNOWN", "T_LABEL",
  "T_ENTRY", "T_END", "$accept", "N_START", "N_PROG", "N_INIT",
  "N_LABEL_INSTRX", "N_GLOBAL", "N_EXEC_CODE_LABEL", "N_ENTRYPOINT_LABEL",
  "N_STACK_LABEL", "N_DISPLAY_BSS", "N_STACK_BSS", "N_HALT", "N_EXEC_CODE",
  "N_MAIN_CODE", "N_INSTRX_LIST", "N_INSTRX", "N_INTCONST", "N_MEMORY_LOC",
  "N_JUMP_INSTRX", "N_JUMP_OP", "N_BINARY_OP", "N_UNARY_OP",
  "N_INPUT_INSTRX", "N_OUTPUT_INSTRX", "N_STACK_INSTRX", "N_ASP_INSTRX",
  "N_PUSH_INSTRX", "N_POP_INSTRX", "N_SAVE_INSTRX", "N_LC_INSTRX",
  "N_LV_INSTRX", "N_LA_INSTRX", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    65,    65,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    73,    74,    75,    76,    77,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,    11,    10,     2,     1,     1,     2,     1,
       2,     2,     1,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     1,     0,     6,     0,
       0,     5,     0,     0,     0,    10,     7,    15,     0,     0,
      13,     0,     0,    15,    29,    30,    31,    32,    28,     0,
      59,     0,     0,     0,     0,     0,     0,    60,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    18,    16,    17,
       0,    20,    21,    22,    23,    19,    52,    53,    54,    55,
      56,    57,    58,     0,     8,     0,    14,    24,    25,    61,
       0,    62,    63,    64,    65,    66,    67,    27,     0,    12,
       0,     0,     0,     9,     0,    26,     4,     0,     0,    11,
       3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    57,     9,    17,    23,    94,    13,
      98,    90,    19,    75,    20,    58,    80,    81,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int8 yypact[] =
{
     -36,   -18,    27,   -41,    -2,    18,   -41,    14,   -41,    36,
       7,   -41,    10,    -2,    28,   -41,   -41,   -41,    11,     9,
       1,    31,    32,   -41,   -41,   -41,   -41,   -41,   -41,   -40,
     -41,   -40,   -40,   -40,   -40,   -40,   -40,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
      13,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,    16,   -41,    19,     1,   -41,   -41,   -41,
      37,   -41,   -41,   -41,   -41,   -41,   -41,   -41,    38,   -41,
      -2,    22,    17,   -41,    57,   -41,   -41,    24,    21,   -41,
     -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,   -41,    -4,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,    45,   -41,    12,    15,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       8,    77,    78,     1,    24,    25,    26,    27,    28,    16,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     5,     6,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      11,    79,     7,    10,    12,     7,    84,    82,    83,    14,
      85,    86,    15,    18,    22,    21,    73,    87,    74,    89,
      88,    96,    91,    92,    95,    97,    99,   100,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93
};

static const yytype_int8 yycheck[] =
{
       4,    41,    42,    39,     3,     4,     5,     6,     7,    13,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    44,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      26,    29,    44,    25,     8,    44,    34,    32,    33,    42,
      35,    36,    42,    25,    45,    44,    25,    44,    26,    40,
      44,    44,    25,    25,    42,     8,    42,    46,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    48,    49,    50,    44,     0,    44,    51,    52,
      25,    26,     8,    56,    42,    42,    51,    53,    25,    59,
      61,    44,    45,    54,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    51,    62,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    25,    26,    60,    61,    41,    42,    63,
      63,    64,    64,    64,    63,    64,    64,    44,    44,    40,
      58,    25,    25,    51,    55,    42,    44,     8,    57,    42,
      46
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
#line 177 "oal.y"
    {
				prRule("N_START", "N_PROG");
				if (DEBUG)
				  {
				    printf("\n---- Completed parsing");
				    printf(" ----\n\n");
				  }
				return 0;
				;}
    break;

  case 3:
#line 190 "oal.y"
    {
				prRule("N_PROG", 
				       "N_INIT N_GLOBAL N_DISPLAY ...");
				;}
    break;

  case 4:
#line 198 "oal.y"
    {
				Cstring label;
				sprintf(label, "%s", (yyvsp[(2) - (10)].cstring));
				string labelStr = label;
                    	addLabel(labelStr, jumpLocations);
				sprintf(label, "%s", (yyvsp[(6) - (10)].cstring));
				labelStr = label;
                    	addLabel(labelStr, jumpLocations);
				sprintf(label, "%s", (yyvsp[(8) - (10)].cstring));
				labelStr = label;
                    	addLabel(labelStr, jumpLocations);
				sprintf(entryLabel, "%s", (yyvsp[(10) - (10)].cstring));
				labelStr = entryLabel;
                    	addLabel(labelStr, jumpLocations);
				prRule("N_INIT",
				       "T_INIT T_LABEL T_COMMA ...");
				;}
    break;

  case 5:
#line 217 "oal.y"
    {
				prRule("N_LABEL_INSTRX", 
				       "T_LABEL T_COLON");
				Cstring label;
				sprintf(label, "%s", (yyvsp[(1) - (2)].cstring));
				string labelStr = label;
                   	if (findLabel(labelStr, definedLabels))
                  	 bail("Duplicate label definition found!"); 
                    	addLabel(labelStr, definedLabels);
                    	addLabelInstrxNum(labelStr, instrxCount);
                   	addInstruction(labelInstrx);
				;}
    break;

  case 6:
#line 231 "oal.y"
    {
				prRule("N_GLOBAL", "N_LABEL_INSTRX");
				;}
    break;

  case 7:
#line 236 "oal.y"
    {
				prRule("N_EXEC_CODE_LABEL",
				       "N_LABEL_INSTRX");
				;}
    break;

  case 8:
#line 242 "oal.y"
    {
				prRule("N_ENTRYPOINT_LABEL",
				       "T_ENTRY T_COLON");
				Cstring label;
				sprintf(label, "%s", (yyvsp[(1) - (2)].cstring));
				strcpy((yyval.cstring), label);
				string labelStr = label;
				if (findLabel(labelStr, definedLabels))
                       bail("Duplicate label definition found!"); 
                    	addLabel(labelStr, definedLabels);
                    	entryPointInstrxNum = instrxCount;
                    	addLabelInstrxNum(labelStr, instrxCount);
				addInstruction(labelInstrx);
				;}
    break;

  case 9:
#line 258 "oal.y"
    {
				prRule("N_STACK_LABEL",
				       "N_LABEL_INSTRX");
				;}
    break;

  case 10:
#line 264 "oal.y"
    {
				prRule("N_DISPLAY_BSS", "T_PCONST");
                      displaySize = (yyvsp[(2) - (2)].num);
				;}
    break;

  case 11:
#line 270 "oal.y"
    {
				prRule("N_STACK_BSS", "T_PCONST");
				;}
    break;

  case 12:
#line 275 "oal.y"
    {
				prRule("N_HALT", "T_HALT");
                   	haltPointInstrxNum = instrxCount;
                    	addInstruction(labelInstrx);  
				;}
    break;

  case 13:
#line 282 "oal.y"
    {
				prRule("N_EXEC_CODE",
				       "N_INSTRX_LIST");
				;}
    break;

  case 14:
#line 288 "oal.y"
    {
				prRule("N_MAIN_CODE", "N_INSTRX_LIST");
				;}
    break;

  case 15:
#line 293 "oal.y"
    {
				prRule("N_INSTRX_LIST", "epsilon");
				;}
    break;

  case 16:
#line 297 "oal.y"
    {
				prRule("N_INSTRX_LIST", 
				       "N_INSTRX_LIST N_INSTRX");
				;}
    break;

  case 17:
#line 303 "oal.y"
    {
				prRule("N_INSTRX", "N_JUMP_INSTRX");
				;}
    break;

  case 18:
#line 307 "oal.y"
    {
				prRule("N_INSTRX", "N_LABEL_INSTRX");
				;}
    break;

  case 19:
#line 311 "oal.y"
    {
				prRule("N_INSTRX", "N_STACK_INSTRX");
				;}
    break;

  case 20:
#line 315 "oal.y"
    {
				prRule("N_INSTRX", "N_BINARY_OP");
				;}
    break;

  case 21:
#line 319 "oal.y"
    {
				prRule("N_INSTRX", "N_UNARY_OP");
				;}
    break;

  case 22:
#line 323 "oal.y"
    {
				prRule("N_INSTRX", "N_INPUT_INSTRX");
				;}
    break;

  case 23:
#line 327 "oal.y"
    {
				prRule("N_INSTRX", "N_OUTPUT_INSTRX");
				;}
    break;

  case 24:
#line 332 "oal.y"
    {
				prRule("N_INTCONST", "T_NCONST");
                    	(yyval.num) = (yyvsp[(1) - (1)].num);
				;}
    break;

  case 25:
#line 337 "oal.y"
    {
				prRule("N_INTCONST", "T_PCONST");
                    	(yyval.num) = (yyvsp[(1) - (1)].num);
				;}
    break;

  case 26:
#line 343 "oal.y"
    {
				prRule("N_MEMORY_LOC", 
			  	       "N_INTCONST T_COMMA T_PCONST");
                    	(yyval.memLoc).offset = (yyvsp[(1) - (3)].num);
                    	(yyval.memLoc).level = (yyvsp[(3) - (3)].num);
				;}
    break;

  case 27:
#line 351 "oal.y"
    {
                    	prRule("N_JUMP_INSTRX", 
				       "N_JUMP_OP T_LABEL");
                    	ptrToFunction f;
				Cstring label;
				sprintf(label, "%s", (yyvsp[(2) - (2)].cstring));
				string labelStr = label;
                   	addLabel(labelStr, jumpLocations);
                    	switch ((yyvsp[(1) - (2)].num)) 
				{
				case T_JP: f = jp; break;
                 	case T_JF: f = jf; break;
                    	case T_JT: f = jt; break;
                    	case T_JS: f = js; break;
                    	};
                    	addInstruction(f, 
						    strtol((yyvsp[(2) - (2)].cstring) + 2, 0, 10));
				;}
    break;

  case 28:
#line 370 "oal.y"
    {
				prRule("N_JUMP_INSTRX", "T_JI");
                    	addInstruction(ji);
				;}
    break;

  case 29:
#line 376 "oal.y"
    {
                      prRule("N_JUMP_OP", "T_JP");
                     	(yyval.num) = T_JP;
				;}
    break;

  case 30:
#line 381 "oal.y"
    {
				prRule("N_JUMP_OP", "T_JF");
                     	(yyval.num) = T_JF;
				;}
    break;

  case 31:
#line 386 "oal.y"
    {
				prRule("N_JUMP_OP", "T_JT");
                   	(yyval.num) = T_JT;
				;}
    break;

  case 32:
#line 391 "oal.y"
    {
				prRule("N_JUMP_OP", "T_JS");
                     	(yyval.num) = T_JS;
				;}
    break;

  case 33:
#line 397 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_ADD");
                      addInstruction(add);
				;}
    break;

  case 34:
#line 402 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_SUB");
                      addInstruction(sub);
				;}
    break;

  case 35:
#line 407 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_MULT");
                      addInstruction(mult);
				;}
    break;

  case 36:
#line 412 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_DIV");
                      addInstruction(div);
				;}
    break;

  case 37:
#line 417 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_MOD");
                      addInstruction(mod);
				;}
    break;

  case 38:
#line 422 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_AND");
                      addInstruction(and_op);
				;}
    break;

  case 39:
#line 427 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_OR");
                      addInstruction(or_op);
				;}
    break;

  case 40:
#line 432 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_EQ");
                      addInstruction(eq_op);
				;}
    break;

  case 41:
#line 437 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_NE");
                      addInstruction(ne_op);
				;}
    break;

  case 42:
#line 442 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_LT");
                      addInstruction(lt_op);
				;}
    break;

  case 43:
#line 447 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_LE");
                      addInstruction(le_op);
				;}
    break;

  case 44:
#line 452 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_GT");
                      addInstruction(gt_op);
				;}
    break;

  case 45:
#line 457 "oal.y"
    {
				 prRule("N_BINARY_OP", "T_GE");
                      addInstruction(ge_op);
				;}
    break;

  case 46:
#line 463 "oal.y"
    {
				 prRule("N_UNARY_OP", "T_NEG");
                      addInstruction(neg_op);
				;}
    break;

  case 47:
#line 468 "oal.y"
    {
				 prRule("N_UNARY_OP", "T_NOT");
                      addInstruction(not_op);
				;}
    break;

  case 48:
#line 474 "oal.y"
    {
				 prRule("N_INPUT_INSTRX", "T_CREAD");
                      addInstruction(cread);
				;}
    break;

  case 49:
#line 479 "oal.y"
    {
				 prRule("N_INPUT_INSTRX", "T_IREAD");
                      addInstruction(iread);
				;}
    break;

  case 50:
#line 485 "oal.y"
    {
				 prRule("N_OUTPUT_INSTRX", "T_CWRITE");
                      addInstruction(cwrite);
				;}
    break;

  case 51:
#line 490 "oal.y"
    {
				 prRule("N_OUTPUT_INSTRX", "T_IWRITE");
                      addInstruction(iwrite);
				;}
    break;

  case 52:
#line 496 "oal.y"
    {
				prRule("N_STACK_INSTRX",
				       "N_ASP_INSTRX");
				;}
    break;

  case 53:
#line 501 "oal.y"
    {
				prRule("N_STACK_INSTRX",
			            "N_PUSH_INSTRX");
				;}
    break;

  case 54:
#line 506 "oal.y"
    {
				prRule("N_STACK_INSTRX",
				       "N_POP_INSTRX");
				;}
    break;

  case 55:
#line 511 "oal.y"
    {
				prRule("N_STACK_INSTRX",
				       "N_SAVE_INSTRX");
				;}
    break;

  case 56:
#line 516 "oal.y"
    {
				prRule("N_STACK_INSTRX",
				       "N_LC_INSTRX");
				;}
    break;

  case 57:
#line 521 "oal.y"
    {
				prRule("N_STACK_INSTRX",
				       "N_LV_INSTRX");
				;}
    break;

  case 58:
#line 526 "oal.y"
    {
				prRule("N_STACK_INSTRX",
				       "N_LA_INSTRX");
				;}
    break;

  case 59:
#line 531 "oal.y"
    {
				 prRule("N_STACK_INSTRX", "T_ST");
                      addInstruction(st);
				;}
    break;

  case 60:
#line 536 "oal.y"
    {
				 prRule("N_STACK_INSTRX", "T_DEREF");
                      addInstruction(deref);
				;}
    break;

  case 61:
#line 542 "oal.y"
    {
				 prRule("N_ASP_INSTRX", 
				       "T_ASP N_INTCONST");
                      addInstruction(asp, (yyvsp[(2) - (2)].num));
				;}
    break;

  case 62:
#line 549 "oal.y"
    {
				 prRule("N_PUSH_INSTRX", 
				       "T_PUSH N_MEMORY_LOC");
                      addInstruction(push, (yyvsp[(2) - (2)].memLoc).offset,
				               (yyvsp[(2) - (2)].memLoc).level);
				;}
    break;

  case 63:
#line 557 "oal.y"
    {
				 prRule("N_POP_INSTRX", 
				       "T_POP N_MEMORY_LOC");
                      addInstruction(pop, (yyvsp[(2) - (2)].memLoc).offset,
						    (yyvsp[(2) - (2)].memLoc).level);
				;}
    break;

  case 64:
#line 565 "oal.y"
    {
				 prRule("N_SAVE_INSTRX", 
				       "T_SAVE N_MEMORY_LOC");
                      addInstruction(save, (yyvsp[(2) - (2)].memLoc).offset,
						    (yyvsp[(2) - (2)].memLoc).level);
				;}
    break;

  case 65:
#line 573 "oal.y"
    {
				 prRule("N_LC_INSTRX", 
				       "T_LC N_INTCONST");
                      addInstruction(lc, (yyvsp[(2) - (2)].num));
				;}
    break;

  case 66:
#line 580 "oal.y"
    {
				 prRule("N_LV_INSTRX", 
				       "T_LV N_MEMORY_LOC");
 				 addInstruction(lv, (yyvsp[(2) - (2)].memLoc).offset,
						    (yyvsp[(2) - (2)].memLoc).level);
				;}
    break;

  case 67:
#line 588 "oal.y"
    {
				 prRule("N_LA_INSTRX", 
				       "T_LA N_MEMORY_LOC");
                      addInstruction(la, (yyvsp[(2) - (2)].memLoc).offset,
						    (yyvsp[(2) - (2)].memLoc).level);
				;}
    break;


/* Line 1267 of yacc.c.  */
#line 2209 "oal.tab.c"
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


#line 595 "oal.y"


#include "lex.yy.c"

extern FILE *yyin;

// Add instruction (as specified by f, op1, op2) to 
// instructions vector
void addInstruction(ptrToFunction f, 
                    const int op1, const int op2) 
{
  instrx i;
  i.op1 = op1;
  i.op2 = op2;
  i.f = f;
  instructions.push_back(i);
  instrxCount++;
  return;
}

// Push value op1 onto arithmetic stack
void lc(const int op1, const int op2, int& instrxNum) 
{
  arithmeticStackElt stackElt;
  stackElt.val1 = op1;
  stackElt.val2 = op2; 
  arithmeticStack.push(stackElt);
  instrxNum++;
  return;
}

// Push address of memory location (op1, op2) 
// onto arithmetic stack
void la(const int op1, const int op2, int& instrxNum) 
{
  arithmeticStackElt stackElt;
  stackElt.val1 = op1;
  stackElt.val2 = op2; 
  arithmeticStack.push(stackElt);
  instrxNum++;
  return;
}

// Push value stored at memory location (op1, op2) 
// onto arithmetic stack
void lv(const int op1, const int op2, int& instrxnum) 
{
  la(op1, op2, instrxnum);
  instrxnum--;          // because la will increment instrxNum
  deref(-1, -1, instrxnum); // deref also increments instrxNum
  return;
}

// Pop an integer from arithmetic stack and output
void iwrite(const int op1, const int op2, int& instrxNum) 
{
  if (arithmeticStack.empty())
    bail("Arithmetic stack is empty in iwrite!"); 

  arithmeticStackElt stackElt = arithmeticStack.top();
  arithmeticStack.pop();
  printf("%d", stackElt.val1);
  instrxNum++;
  return;
}

// Pop a char from arithmetic stack and output
void cwrite(const int op1, const int op2, int& instrxNum) 
{
  if (arithmeticStack.empty())
    bail("Arithmetic stack is empty in iwrite!");
 
  arithmeticStackElt stackElt = arithmeticStack.top();
  arithmeticStack.pop();
  if (stackElt.val1 == 92)  // '\' is ASCII 47
    printf("\n");
  else printf("%c", stackElt.val1);
  instrxNum++;
  return;
}

// Read an integer from input, and push its value 
// onto arithmetic stack
void iread(const int op1, const int op2, int& instrxNum) 
{
  int x;
  scanf("%d", &x);
  arithmeticStackElt stackElt;
  stackElt.val1 = x;
  stackElt.val2 = -1;
  arithmeticStack.push(stackElt);
  instrxNum++;
  return;
}

// Read a char from input, and push its value 
// onto arithmetic stack
void cread(const int op1, const int op2, int& instrxNum) 
{
  char x;
  scanf("%c", &x);
  arithmeticStackElt stackElt;
  stackElt.val1 = static_cast<int>(x);
  stackElt.val2 = -1;
  arithmeticStack.push(stackElt);
  instrxNum++;
  return;
}

// Pop top of arithmetic stack, and push the value in 
// that address back onto the arithmetic stack
void deref(const int op1, const int op2, int& instrxNum) 
{
  if (arithmeticStack.empty())
    bail("Arithmetic stack is empty in deref!");

  arithmeticStackElt stackElt = arithmeticStack.top();
  arithmeticStack.pop();
/*
  if (stackElt.val2 == -1)
    bail("Attempting to deref a constant!");
*/
  arithmeticStackElt newStackElt;
  if (stackElt.val2 == 0)
     newStackElt.val1 = display[stackElt.val1];
  else 
  {
    int pos = 1 + display[stackElt.val2] +
              stackElt.val1;
    newStackElt.val1 = executionStack[pos];
  }
  newStackElt.val2 = -1;

  arithmeticStack.push(newStackElt);
  instrxNum++;
  return;
}

// Pop 2 elements off arithmetic stack, and store value of 1st  
// element popped in the address contained in the 2nd 
// element popped
void st(const int op1, const int op2, int& instrxNum) 
{
  if (arithmeticStack.empty())
    bail("Arithmetic stack is empty in st!");

  arithmeticStackElt stackElt1 = arithmeticStack.top();
  arithmeticStack.pop();
/*
  if (stackElt1.val2 != -1)
    bail("Invalid value in st!");
*/
  if (arithmeticStack.empty())
    bail("Arithmetic stack is empty in st!");
  
  arithmeticStackElt stackElt2 = arithmeticStack.top();
  arithmeticStack.pop();
  if (stackElt2.val2 == -1)
    bail("Invalid address in st!");

  if (stackElt2.val2 == 0)
     display[stackElt2.val1] = stackElt1.val1;
  else 
  {
    int pos = 1 + display[stackElt2.val2] +
              stackElt2.val1;
    executionStack[pos] = stackElt1.val1;
  }

  instrxNum++;
  return;
}

// Add/remove op1 elements to/from execution stack 
void asp(const int op1, const int op2, int& instrxNum) 
{
  if (DEBUG) 
  {
    printf("\nIn asp instrxNum = %d op1 = %d\n", 
           instrxNum, op1);
    dumpExecutionStack();
  }

  if (op1 < 0) 
  {
    for (int i = 0; i < abs(op1); i++)
      executionStack.pop_back();
  } 
  else 
  {
    for (int i = 0; i < op1; i++)
      executionStack.push_back(0);
  }
  instrxNum++;
  return;
}

// Push value in specified memory location (op1, op2) 
// onto execution stack
void push(const int op1, const int op2, int& instrxNum) 
{
  int x;
  if (op2 == 0)
     x = display[op1];
  else x = executionStack[1 + display[op2] + op1];
  executionStack.push_back(x);
  instrxNum++;
  return;
}

// Pop value from top of execution stack, storing it in 
// memory location (op1, op2)
void pop(const int op1, const int op2, int& instrxNum) 
{
  if (executionStack.empty())
    bail("Execution stack is empty during pop!");

  int x = executionStack.back();
  executionStack.pop_back(); 
  if (op2 == 0)
     display[op1] = x;
  else executionStack[1 + display[op2] + op1] = x;
  instrxNum++;
  return;
}

// Save current value of execution stack top in memory 
// location (op1, op2)
void save(const int op1, const int op2, int& instrxNum) 
{
  int x = executionStack.size( ) - 1;
  if (DEBUG) 
  {
    printf("In save instrxNum = %d and x = %d\n", 
           instrxNum, x);
    dumpExecutionStack();
  }

  if (x < 0)
    bail("Execution stack empty during save!");

  if (op2 == 0)
     display[op1] = x;
  else executionStack[1 + display[op2] + op1] = x;

  instrxNum++;
  return;
}

// Jump to label specified by op1; stacks remain unchanged
void jp(const int op1, const int op2, int& instrxNum) 
{
  if (DEBUG)
    printf("\nIn jp with instrxNum = %d\n", instrxNum);

  char buf[20];
  sprintf(buf, "L.%d", op1);
  instrxNum = findLabelInstrxNum(buf);
  if (DEBUG)
    printf("jp is jumping to instrxNum %d\n", instrxNum);
  if (instrxNum == -1)
    bail("Attempted jump to undefined label!");
  return;
}

// Pop top of arithmetic stack; if true, 
// jump to label location (op1)
void jt(const int op1, const int op2, int& instrxNum) 
{
  if (arithmeticStack.empty())
    bail("Arithmetic stack is empty in jt!");

  arithmeticStackElt stackElt = arithmeticStack.top();
  arithmeticStack.pop();

  if (stackElt.val2 != -1)
    bail("Can't test an address equal to 'true' in jt!");

  if (stackElt.val1 != 0)
    jp(op1, op2, instrxNum);
  else instrxNum++;
  return;
}

// Pop top of arithmetic stack; if false, jump to 
// label location (op1)
void jf(const int op1, const int op2, int& instrxNum) 
{
  if (arithmeticStack.empty())
    bail("Arithmetic stack is empty in jf!");

  arithmeticStackElt stackElt = arithmeticStack.top();
  arithmeticStack.pop();

  if (stackElt.val2 != -1)
    bail("Can't test an address equal to 'false' during jf!");

  if (stackElt.val1 == 0)
    jp(op1, op2, instrxNum);
  else instrxNum++;
  return;
}

// Jump to label (op1); push address of next instruction 
// onto execution stack
void js(const int op1, const int op2, int& instrxNum) 
{
  if (DEBUG) 
  {
    printf("\nIn js with instrxNum = %d\n", instrxNum);
    dumpExecutionStack();
  }
  executionStack.push_back(instrxNum+1);
  jp(op1, op2, instrxNum);
  return;
}

// Pop a location off execution stack, and transfer 
// control to location popped
void ji(const int op1, const int op2, int& instrxNum) 
{
  if (DEBUG)
    dumpExecutionStack();

  if (executionStack.empty())
    bail("Execution stack is empty during ji!");

  instrxNum = executionStack.back();
  executionStack.pop_back(); 

  if (DEBUG)
    printf("ji has set instrxNum to %d\n", instrxNum);

  return;
}

// All binary operations (add, mult, sub, div, mod, and, or, 
// .eq., .ne., .lt., .le., .gt., .ge.) pop 2 elements off 
// arithmetic stack, perform the operation, and 
// push result onto arithmetic stack

void add(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_ADD);
  instrxNum++;
  return;
}

void sub(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_SUB);
  instrxNum++;
  return;
}

void mult(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_MULT);
  instrxNum++;
  return;
}

void div(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_DIV);
  instrxNum++;
}

void mod(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_MOD);
  instrxNum++;
  return;
}

void and_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_AND);
  instrxNum++;
  return;
}

void or_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_OR);
  instrxNum++;
  return;
}

void eq_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_EQ);
  instrxNum++;
  return;
}

void ne_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_NE);
  instrxNum++;
  return;
}

void lt_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_LT);
  instrxNum++;
  return;
}

void le_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_LE);
  instrxNum++;
  return;
}

void gt_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_GT);
  instrxNum++;
  return;
}

void ge_op(const int op1, const int op2, int& instrxNum) 
{
  binaryOperation(T_GE);
  instrxNum++;
  return;
}

// Generalized function to perform any binary operation
// indicated by opCode (i.e., a particular operator token)
void binaryOperation(const int opCode) 
{
  if (arithmeticStack.empty())
   bail("Arithmetic stack is empty during binary operation!");

  arithmeticStackElt stackElt1 = arithmeticStack.top();
  arithmeticStack.pop();

  if (arithmeticStack.empty())
   bail("Arithmetic stack is empty during binary operation!");  
  
  arithmeticStackElt stackElt2 = arithmeticStack.top();
  arithmeticStack.pop();

  if ((stackElt1.val2 != -1) && (stackElt2.val2 != -1)) 
    bail("Cannot perform binary operation on two addresses!"); 
  else 
  {
    switch (opCode) 
    {
    case T_ADD : stackElt1.val1 = stackElt2.val1 +
                                  stackElt1.val1;
                 break;
    case T_SUB : stackElt1.val1 = stackElt2.val1 -
                                  stackElt1.val1;
                 break;
    case T_MULT: stackElt1.val1 = stackElt2.val1 *
                                  stackElt1.val1;
                 break;
    case T_DIV : if (stackElt1.val1 == 0)
                   bail("Cannot divide by zero!");
                 stackElt1.val1 = stackElt2.val1 /
                                  stackElt1.val1;
                 break;
    case T_MOD : if (stackElt1.val1 == 0)
                   bail("Cannot mod by zero!");
                 stackElt1.val1 = stackElt2.val1 %
                                  stackElt1.val1;
                 break;
    case T_AND : if (stackElt1.val1 && stackElt2.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    case T_OR  : if (stackElt1.val1 || stackElt2.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    case T_EQ  : if (stackElt1.val1 == stackElt2.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    case T_NE  : if (stackElt1.val1 != stackElt2.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    case T_LT  : if (stackElt2.val1 < stackElt1.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    case T_LE  : if (stackElt2.val1 <= stackElt1.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    case T_GT  : if (stackElt2.val1 > stackElt1.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    case T_GE  : if (stackElt2.val1 >= stackElt1.val1)
                   stackElt1.val1 = 1;
                 else stackElt1.val1 = 0;
                 break;
    default  :   bail("Invalid operator in binaryOperation!");
                 break;
    }
    if (stackElt2.val2 != -1) 
      stackElt1.val2 = stackElt2.val2; 
    arithmeticStack.push(stackElt1);
  }
  return;
}

// All unary operations (neg, not) pop one element off
// arithmetic stack, perform the operation, and push 
// result onto arithmetic stack

void neg_op(const int op1, const int op2, int& instrxNum) 
{
  unaryOperation(T_NEG);
  instrxNum++;
}

void not_op(const int op1, const int op2, int& instrxNum) 
{
  unaryOperation(T_NOT);
  instrxNum++;
  return;
}

// Generalized function to perform any unary operation
// indicated by opCode (i.e., a particular operator token)
void unaryOperation(const int opCode) 
{
  if (arithmeticStack.empty())
   bail("Arithmetic stack is empty during unary operation!");
  arithmeticStackElt stackElt = arithmeticStack.top();
  arithmeticStack.pop();

  if (stackElt.val2 != -1) 
    bail("Cannot perform unary operation on an address!"); 
  else 
  {
    switch (opCode) 
    {
    case T_NEG : stackElt.val1 = -stackElt.val1;
                 break;
    case T_NOT : if (stackElt.val1 == 0)
                   stackElt.val1 = 1;
                 else stackElt.val1 = 0;
                 break;
    default : bail("Invalid operator in unaryOperation!");
    }
    arithmeticStack.push(stackElt);
  }
  return;
}

// Label instructions (e.g., "L.xx:") just increment instrxNum
void labelInstrx(const int op1, const int op2, int& instrxNum) 
{
  instrxNum++;
  return;
}

// Output the contents of the execution stack (for debugging)
void dumpExecutionStack() 
{  
  printf("\nExecution stack contents:\n");
  for (int i = 0; i < executionStack.size(); i++)
    printf("  executionStack[%d] = %d\n", 
           i, executionStack[i]);
  return;
}

// Output the specified message and terminate program execution
void bail(const char* s) 
{
  printf("\n%s\n", s);
  exit(1);
}

// Initialize the display vector to be displaySize (which is
// 20 + space needed for global variables)
void initDisplay() 
{
  for (int i = 0; i < displaySize; i++)
    display.push_back(0);
  return;
}

// After parsing, evaluate the OAL code, starting at
// instructions[entryPointInstrxNum] and continuing until
// we reach the haltPointInstrxNum
void performEvaluation() 
{
  int instrxNum = entryPointInstrxNum;
  while (instrxNum < haltPointInstrxNum) 
  {
    int op1 = instructions[instrxNum].op1;
    int op2 = instructions[instrxNum].op2;
    instructions[instrxNum].f(op1, op2, instrxNum);
  }
  return;
}

// When comment encountered during parsing, ignore
// all chars until eoln
void ignoreComment() 
{
  char c;

  // read and ignore the input until eoln
  while (((c = yyinput()) != '\n') && c != 0) ;

  ++lineNum;

  if (DEBUG) printf("  ----> FOUND A COMMENT\n");
  return;
}

// Add labelName and its instrxNum to labelInstrxNums
void addLabelInstrxNum(const string labelName, 
                       const int instrxNum) 
{
  labelInfo info;
  info.labelName = labelName;
  info.instrxNum = instrxNum;
  labelInstrxNums.push_front(info);
}

// Find labelName in the labelInstrxNums list. If found,
// return its instrxNum; otherwise, return -1.
int findLabelInstrxNum(const string labelName) 
{
  std::list<labelInfo>::iterator itr = labelInstrxNums.begin();
  while (itr != labelInstrxNums.end()) 
  {
    labelInfo info = (labelInfo) *itr;
    if (labelName == info.labelName)
      return(info.instrxNum);
    itr++;
  }
  return(-1);  // labelNum not found (shouldn't happen!)
}

// Add label x to list L (where L is either jumpLocations
// or definedLabels)
void addLabel(const string x, std::list<string> &L) 
{
  if (!findLabel(x, L)) L.push_front(x);
  return;
}

// Determine whether label x is in label list L (where
// L is either jumpLocations or definedLabels)
bool findLabel(const string x, std::list<string> L) 
{
  std::list<string>::iterator itr = L.begin();
  while (itr != L.end()) 
  {
	if (x == (string) *itr) 
        return(true);
      
	itr++;
  }
  return(false);
}

// Make sure all jumpLocations were to definedLabels
bool checkLabels( ) 
{
  bool labelsOK = true;
  std::list<string>::iterator itr = jumpLocations.begin();
  while (itr != jumpLocations.end()) 
  {
    string x = (string) *itr;
    if (!findLabel(x, definedLabels)) 
    {
      printf("There is a jump to undefined label %s\n",
             x.c_str());
      labelsOK = false;
    }
    itr++;
  }
  return(labelsOK);
}

// Output the production being parsed (for debugging)
void prRule(const char* lhs, const char* rhs) 
{
  if (OUTPUT_PRODUCTIONS ) 
    printf("%s -> %s\n", lhs, rhs);
  return;
}

void printTokenInfo(const char* tokenType, 
                    const char* lexeme) 
{
  if (OUTPUT_TOKENS)
    printf("TOKEN: %-15s  LEXEME: %s\n", tokenType, lexeme);
  return;
}

int main(int argc, char** argv) {
  if (argc < 2)
    bail("You must specify a file in the command line!");

  // Parse the input file, and generate instructions vector
  yyin = fopen(argv[1], "r");
  do {
	yyparse();
  } while (!feof(yyin));

  // Make sure all jumps were to defined labels
  bool labelsOK = checkLabels();
  jumpLocations.clear();
  definedLabels.clear();

  if (labelsOK) 
  {
    initDisplay();
    performEvaluation();
    printf("\nProgram execution completed.\n");
  }

  return 0;
}

