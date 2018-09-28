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
#line 9 "mipl.y"


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 232 "mipl.tab.c"

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
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

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
       0,     0,     3,     5,     7,     9,    11,    12,    16,    23,
      25,    29,    33,    35,    37,    42,    47,    54,    56,    58,
      60,    62,    64,    68,    71,    73,    77,    80,    82,    83,
      87,    89,    93,    98,    99,   103,   105,   108,   110,   112,
     114,   115,   119,   121,   122,   126,   129,   133,   134,   138,
     140,   142,   148,   150,   156,   158,   160,   162,   164,   166,
     168,   169,   171,   173,   175,   177,   179,   182,   184,   186,
     188,   190,   192,   194,   196,   197,   201,   203,   206,   208,
     210,   215,   216,   220,   221,   226,   228,   230,   232,   237
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    82,    -1,     6,    -1,     8,    -1,    37,
      -1,    -1,    52,    92,    53,    -1,    24,    20,    68,    21,
      36,    87,    -1,    62,    -1,    97,    12,    63,    -1,    96,
      79,    91,    -1,    41,    -1,    32,    -1,    25,    89,    90,
      31,    -1,    33,    63,    48,    89,    -1,    33,    63,    48,
      89,    49,    89,    -1,    72,    -1,    29,    -1,    58,    -1,
      98,    -1,    88,    -1,    88,    85,    88,    -1,    86,    97,
      -1,    61,    -1,     3,    63,     4,    -1,    35,    64,    -1,
      42,    -1,    -1,     7,    65,    66,    -1,    72,    -1,    67,
      10,    67,    -1,    55,    20,    63,    21,    -1,    -1,     7,
      71,    70,    -1,    97,    -1,    86,    30,    -1,     5,    -1,
      28,    -1,    23,    -1,    -1,    73,    64,    74,    -1,    63,
      -1,    -1,     7,    75,    76,    -1,    78,    57,    -1,    38,
      42,    13,    -1,    -1,    77,    13,    79,    -1,    42,    -1,
      80,    -1,    83,    42,    13,    57,     9,    -1,    39,    -1,
      40,     3,    71,    70,     4,    -1,    14,    -1,    18,    -1,
      15,    -1,    19,    -1,    17,    -1,    16,    -1,    -1,     6,
      -1,     8,    -1,    34,    -1,    27,    -1,    26,    -1,    92,
      53,    -1,    56,    -1,    81,    -1,    84,    -1,   100,    -1,
      60,    -1,    99,    -1,    59,    -1,    -1,    13,    89,    90,
      -1,    59,    -1,    64,    74,    -1,    87,    -1,    54,    -1,
      65,    66,    11,    93,    -1,    -1,    94,    13,    95,    -1,
      -1,    43,    94,    13,    95,    -1,    62,    -1,    69,    -1,
      42,    -1,    44,    63,    22,    89,    -1,    45,     3,    75,
      76,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    77,    81,    85,    91,    94,    99,   105,
     110,   115,   120,   124,   129,   134,   138,   144,   148,   152,
     157,   162,   166,   171,   175,   179,   183,   188,   194,   197,
     202,   207,   212,   218,   221,   226,   231,   236,   240,   244,
     250,   253,   258,   264,   267,   272,   277,   283,   286,   292,
     297,   302,   308,   313,   319,   323,   327,   331,   335,   339,
     345,   348,   352,   357,   361,   365,   370,   375,   379,   383,
     387,   391,   395,   399,   405,   408,   413,   418,   423,   427,
     432,   438,   441,   447,   450,   456,   460,   465,   470,   475
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
  "N_ADDOPLST", "N_ARRAY", "N_ARRAYVAR", "N_ASSIGN", "N_BLOCK",
  "N_BOOLCONST", "N_COMPOUND", "N_CONDITION", "N_CONST", "N_ENTIREVAR",
  "N_EXPR", "N_FACTOR", "N_IDENT", "N_IDENTLST", "N_IDX", "N_IDXRANGE",
  "N_IDXVAR", "N_INPUTLST", "N_INPUTVAR", "N_INTCONST", "N_MULTOP",
  "N_MULTOPLST", "N_OUTPUT", "N_OUTPUTLST", "N_PROCDEC", "N_PROCHDR",
  "N_PROCDECPART", "N_PROCIDENT", "N_PROCSTMT", "N_PROG", "N_PROGLBL",
  "N_READ", "N_RELOP", "N_SIGN", "N_SIMPLE", "N_SIMPLEEXPR", "N_STMT",
  "N_STMTLST", "N_STMTPART", "N_TERM", "N_TYPE", "N_VARDEC", "N_VARDECLST",
  "N_VARDECPART", "N_VARIABLE", "N_VARIDENT", "N_WHILE", "N_WRITE", 0
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
       0,    50,    51,    52,    52,    52,    53,    53,    54,    55,
      56,    57,    58,    58,    59,    60,    60,    61,    61,    61,
      62,    63,    63,    64,    64,    64,    64,    65,    66,    66,
      67,    68,    69,    70,    70,    71,    72,    73,    73,    73,
      74,    74,    75,    76,    76,    77,    78,    79,    79,    80,
      81,    82,    83,    84,    85,    85,    85,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    88,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    92,    93,    93,
      94,    95,    95,    96,    96,    97,    97,    98,    99,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     0,     3,     6,     1,
       3,     3,     1,     1,     4,     4,     6,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     2,     1,     0,     3,
       1,     3,     4,     0,     3,     1,     2,     1,     1,     1,
       0,     3,     1,     0,     3,     2,     3,     0,     3,     1,
       1,     5,     1,     5,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1,     2,     1,     1,
       4,     0,     3,     0,     4,     1,     1,     1,     4,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    52,     0,     2,     0,     1,     0,    83,     0,     0,
      47,    27,    28,     0,    51,     0,     0,    83,     0,     0,
       0,    81,     0,    47,    45,     0,    76,    11,    28,     0,
       0,    84,    46,    48,    60,     0,    49,    60,     0,     0,
      67,    73,    71,    85,    86,    50,    68,    69,    74,     0,
      20,    72,    70,    29,     0,    65,    64,    63,    79,    78,
      80,    81,    60,    61,    62,    18,    13,    60,    12,    19,
      24,     0,    40,    17,     0,    21,     6,     0,     0,    60,
      60,     0,     0,    60,    60,    82,     0,    26,     0,    37,
      39,    38,    60,    77,    36,    87,    23,    54,    56,    59,
      58,    55,    57,    60,     3,     4,     5,    60,    66,    33,
      35,     0,    42,    43,     0,    74,    14,    10,     0,     0,
      30,     0,    25,    15,    40,    22,     6,     0,     0,    88,
      60,     0,    32,    75,    60,     0,     0,    41,     7,    33,
      53,    43,    89,    31,     0,    16,    34,    44,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   107,   108,    58,    39,    40,     9,    69,    41,
      42,    70,    43,   112,    72,    12,    20,   118,   119,    44,
     128,   109,    73,    92,    93,   113,   131,    16,    17,    18,
      45,    46,     3,     4,    47,   103,    74,    59,    75,    48,
      82,    27,    76,    60,    30,    31,    10,    49,    50,    51,
      52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -83
static const yytype_int8 yypact[] =
{
     -16,   -83,    33,   -83,    -7,   -83,    29,     6,     8,    38,
      10,   -83,    44,    45,   -83,    17,    54,     6,    43,     8,
      58,     8,    57,    10,   -83,    -4,   -83,   -83,    44,    -8,
      59,   -83,   -83,   -83,     2,    68,     5,     2,    70,    55,
     -83,   -83,   -83,    56,   -83,   -83,   -83,   -83,    61,    65,
     -83,   -83,   -83,   -83,    60,   -83,   -83,   -83,   -83,   -83,
     -83,     8,     2,   -83,   -83,   -83,   -83,     2,   -83,   -83,
     -83,    30,     4,   -83,   -18,    47,     7,    37,    62,     2,
       2,    -4,    50,     2,    14,   -83,    78,   -83,    -4,   -83,
     -83,   -83,     2,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,     2,   -83,   -83,   -83,     2,   -83,    76,
     -83,    -4,   -83,    79,    64,    61,   -83,   -83,    77,    67,
     -83,    63,   -83,    40,     4,   -83,     7,    37,    86,   -83,
       2,    87,   -83,   -83,    14,    66,    -4,   -83,   -83,    76,
     -83,    79,   -83,   -83,    19,   -83,   -83,   -83,   -83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,   -83,   -34,   -83,   -83,   -83,    80,   -83,    81,
     -83,   -83,   -83,   -23,   -64,    75,    72,   -39,   -83,   -83,
     -43,   -29,   -82,   -83,   -21,   -26,   -40,   -83,   -83,    82,
     -83,   -83,   -83,   -83,   -83,   -83,   -78,   -38,     9,   -81,
      -6,   -83,     0,   -83,   100,    49,   -83,   -73,   -83,   -83,
     -83
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
     115,    96,   120,    87,   110,    62,   121,   123,    63,    89,
      64,    71,    94,   104,    78,   105,    54,   -87,    55,    56,
      63,    25,    64,     1,    95,   -87,    57,    90,   124,    34,
     129,    65,    91,     5,    66,     6,    35,    67,    36,    86,
      37,    38,     7,    68,   106,    55,    56,    14,    15,     8,
      11,    19,   120,    57,   110,   145,   121,   114,    21,    22,
     117,    97,    98,    99,   100,   101,   102,    23,    25,    29,
      32,    77,    61,    79,    81,    80,    -9,    83,    88,    95,
      84,   116,   122,   127,   111,   132,   130,   134,   135,   136,
     140,   142,   138,    94,    28,   143,   146,    24,   139,    26,
      53,   147,   144,   137,   141,    33,   148,   126,    13,   133,
      85,     0,   125
};

static const yytype_int16 yycheck[] =
{
      81,    74,    84,    67,    77,     3,    84,    88,     6,     5,
       8,    34,    30,     6,    37,     8,    24,    12,    26,    27,
       6,    25,     8,    39,    42,    20,    34,    23,    92,    33,
     111,    29,    28,     0,    32,    42,    40,    35,    42,    62,
      44,    45,    13,    41,    37,    26,    27,     9,    38,    43,
      42,     7,   134,    34,   127,   136,   134,    80,    13,    42,
      83,    14,    15,    16,    17,    18,    19,    13,    25,    11,
      13,     3,    13,     3,    13,    20,    20,    12,    48,    42,
      20,    31,     4,     7,    22,    21,     7,    10,    21,    49,
       4,     4,   126,    30,    19,   134,   139,    17,   127,    18,
      28,   141,    36,   124,   130,    23,   144,   107,     8,   115,
      61,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    51,    82,    83,     0,    42,    13,    43,    57,
      96,    42,    65,    94,     9,    38,    77,    78,    79,     7,
      66,    13,    42,    13,    57,    25,    59,    91,    65,    11,
      94,    95,    13,    79,    33,    40,    42,    44,    45,    55,
      56,    59,    60,    62,    69,    80,    81,    84,    89,    97,
      98,    99,   100,    66,    24,    26,    27,    34,    54,    87,
      93,    13,     3,     6,     8,    29,    32,    35,    41,    58,
      61,    63,    64,    72,    86,    88,    92,     3,    63,     3,
      20,    13,    90,    12,    20,    95,    63,    64,    48,     5,
      23,    28,    73,    74,    30,    42,    97,    14,    15,    16,
      17,    18,    19,    85,     6,     8,    37,    52,    53,    71,
      97,    22,    63,    75,    63,    89,    31,    63,    67,    68,
      72,    86,     4,    89,    64,    88,    92,     7,    70,    89,
       7,    76,    21,    90,    10,    21,    49,    74,    53,    71,
       4,    75,     4,    67,    36,    89,    70,    76,    87
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
#line 71 "mipl.y"
    {
                    prRule("N_START", "N_PROG");
			    printf("\n---- Completed parsing ----\n\n");
			    return 0;
                    ;}
    break;

  case 3:
#line 78 "mipl.y"
    {
                    prRule("N_ADDOP", "T_PLUS");
                    ;}
    break;

  case 4:
#line 82 "mipl.y"
    {
                    prRule("N_ADDOP", "T_MINUS");
                    ;}
    break;

  case 5:
#line 86 "mipl.y"
    {
                    prRule("N_ADDOP", "T_OR");
                    ;}
    break;

  case 6:
#line 91 "mipl.y"
    {
                    prRule("N_ADDOPLST", "epsilon");
                    ;}
    break;

  case 7:
#line 95 "mipl.y"
    {
                    prRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
                    ;}
    break;

  case 8:
#line 100 "mipl.y"
    {
                    prRule("N_ARRAY",
                        "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
                    ;}
    break;

  case 9:
#line 106 "mipl.y"
    {
                    prRule("N_ARRAYVAR", "N_ENTIREVAR");
                    ;}
    break;

  case 10:
#line 111 "mipl.y"
    {
                    prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
                    ;}
    break;

  case 11:
#line 116 "mipl.y"
    {
                    prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
                    ;}
    break;

  case 12:
#line 121 "mipl.y"
    {
                    prRule("N_BOOLCONST", "T_TRUE");
                    ;}
    break;

  case 13:
#line 125 "mipl.y"
    {
                    prRule("N_BOOLCONST", "T_FALSE");
                    ;}
    break;

  case 14:
#line 130 "mipl.y"
    {
                    prRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
                    ;}
    break;

  case 15:
#line 135 "mipl.y"
    {
                    prRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
                    ;}
    break;

  case 16:
#line 139 "mipl.y"
    {
                    prRule("N_CONDITION",
                        "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
                    ;}
    break;

  case 17:
#line 145 "mipl.y"
    {
                    prRule("N_CONST", "N_INTCONST");
                    ;}
    break;

  case 18:
#line 149 "mipl.y"
    {
                    prRule("N_CONST", "T_CHARCONST");
                    ;}
    break;

  case 19:
#line 153 "mipl.y"
    {
                    prRule("N_CONST", "N_BOOLCONST");
                    ;}
    break;

  case 20:
#line 158 "mipl.y"
    {
                    prRule("N_ENTIREVAR", "N_VARIDENT");
                    ;}
    break;

  case 21:
#line 163 "mipl.y"
    {
                    prRule("N_EXPR", "N_SIMPLEEXPR");
                    ;}
    break;

  case 22:
#line 167 "mipl.y"
    {
                    prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
                    ;}
    break;

  case 23:
#line 172 "mipl.y"
    {
                    prRule("N_FACTOR", "N_SIGN N_VARIABLE");
                    ;}
    break;

  case 24:
#line 176 "mipl.y"
    {
                    prRule("N_FACTOR", "N_CONST");
                    ;}
    break;

  case 25:
#line 180 "mipl.y"
    {
                    prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
                    ;}
    break;

  case 26:
#line 184 "mipl.y"
    {
                    prRule("N_FACTOR", "T_NOT N_FACTOR");
                    ;}
    break;

  case 27:
#line 189 "mipl.y"
    {
                    prRule("N_IDENT", "T_IDENT");
                    ;}
    break;

  case 28:
#line 194 "mipl.y"
    {
                    prRule("N_IDENTLST", "epsilon");
                    ;}
    break;

  case 29:
#line 198 "mipl.y"
    {
                    prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
                    ;}
    break;

  case 30:
#line 203 "mipl.y"
    {
                    prRule("N_IDX", "N_INTCONST");
                    ;}
    break;

  case 31:
#line 208 "mipl.y"
    {
                    prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
                    ;}
    break;

  case 32:
#line 213 "mipl.y"
    {
                    prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
                    ;}
    break;

  case 33:
#line 218 "mipl.y"
    {
                    prRule("N_INPUTLST", "epsilon");
                    ;}
    break;

  case 34:
#line 222 "mipl.y"
    {
                    prRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
                    ;}
    break;

  case 35:
#line 227 "mipl.y"
    {
                    prRule("N_INPUTVAR", "N_VARIABLE");
                    ;}
    break;

  case 36:
#line 232 "mipl.y"
    {
                    prRule("N_INTCONST", "N_SIGN T_INTCONST");
                    ;}
    break;

  case 37:
#line 237 "mipl.y"
    {
                    prRule("N_MULTOP", "T_MULT");
                    ;}
    break;

  case 38:
#line 241 "mipl.y"
    {
                    prRule("N_MULTOP", "T_DIV");
                    ;}
    break;

  case 39:
#line 245 "mipl.y"
    {
                    prRule("N_MULTOP", "T_AND");
                    ;}
    break;

  case 40:
#line 250 "mipl.y"
    {
                    prRule("N_MULTOPLST", "epsilon");
                    ;}
    break;

  case 41:
#line 254 "mipl.y"
    {
                    prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
                    ;}
    break;

  case 42:
#line 259 "mipl.y"
    {
                    prRule("N_OUTPUT", "N_EXPR");
                    ;}
    break;

  case 43:
#line 264 "mipl.y"
    {
                    prRule("N_OUTPUTLST", "epsilon");
                    ;}
    break;

  case 44:
#line 268 "mipl.y"
    {
                    prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
                    ;}
    break;

  case 45:
#line 273 "mipl.y"
    {
                    prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
                    ;}
    break;

  case 46:
#line 278 "mipl.y"
    {
                    prRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
                    ;}
    break;

  case 47:
#line 283 "mipl.y"
    {
                    prRule("N_PROCDECPART", "epsilon");
                    ;}
    break;

  case 48:
#line 287 "mipl.y"
    {
                    prRule("N_PROCDECPART",
                        "N_PROCDEC T_SCOLON N_PROCDECPART");
                    ;}
    break;

  case 49:
#line 293 "mipl.y"
    {
                    prRule("N_PROCIDENT", "T_IDENT");
                    ;}
    break;

  case 50:
#line 298 "mipl.y"
    {
                    prRule("N_PROCSTMT", "N_PROCIDENT");
                    ;}
    break;

  case 51:
#line 303 "mipl.y"
    {
                    prRule("N_PROG",
                        "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
                    ;}
    break;

  case 52:
#line 309 "mipl.y"
    {
                    prRule("N_PROGLBL", "T_PROG");
                    ;}
    break;

  case 53:
#line 314 "mipl.y"
    {
                    prRule("N_READ",
                        "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
                    ;}
    break;

  case 54:
#line 320 "mipl.y"
    {
                    prRule("N_RELOP", "T_LT");
                    ;}
    break;

  case 55:
#line 324 "mipl.y"
    {
                    prRule("N_RELOP", "T_GT");
                    ;}
    break;

  case 56:
#line 328 "mipl.y"
    {
                    prRule("N_RELOP", "T_LE");
                    ;}
    break;

  case 57:
#line 332 "mipl.y"
    {
                    prRule("N_RELOP", "T_GE");
                    ;}
    break;

  case 58:
#line 336 "mipl.y"
    {
                    prRule("N_RELOP", "T_EQ");
                    ;}
    break;

  case 59:
#line 340 "mipl.y"
    {
                    prRule("N_RELOP", "T_NE");
                    ;}
    break;

  case 60:
#line 345 "mipl.y"
    {
                    prRule("N_SIGN", "epsilon");
                    ;}
    break;

  case 61:
#line 349 "mipl.y"
    {
                    prRule("N_SIGN", "T_PLUS");
                    ;}
    break;

  case 62:
#line 353 "mipl.y"
    {
                    prRule("N_SIGN", "T_MINUS");
                    ;}
    break;

  case 63:
#line 358 "mipl.y"
    {
                    prRule("N_SIMPLE", "T_INT");
                    ;}
    break;

  case 64:
#line 362 "mipl.y"
    {
                    prRule("N_SIMPLE", "T_CHAR");
                    ;}
    break;

  case 65:
#line 366 "mipl.y"
    {
                    prRule("N_SIMPLE", "T_BOOL");
                    ;}
    break;

  case 66:
#line 371 "mipl.y"
    {
                    prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
                    ;}
    break;

  case 67:
#line 376 "mipl.y"
    {
                    prRule("N_STMT", "N_ASSIGN");
                    ;}
    break;

  case 68:
#line 380 "mipl.y"
    {
                    prRule("N_STMT", "N_PROCSTMT");
                    ;}
    break;

  case 69:
#line 384 "mipl.y"
    {
                    prRule("N_STMT", "N_READ");
                    ;}
    break;

  case 70:
#line 388 "mipl.y"
    {
                    prRule("N_STMT", "N_WRITE");
                    ;}
    break;

  case 71:
#line 392 "mipl.y"
    {
                    prRule("N_STMT", "N_CONDITION");
                    ;}
    break;

  case 72:
#line 396 "mipl.y"
    {
                    prRule("N_STMT", "N_WHILE");
                    ;}
    break;

  case 73:
#line 400 "mipl.y"
    {
                    prRule("N_STMT", "N_COMPOUND");
                    ;}
    break;

  case 74:
#line 405 "mipl.y"
    {
                    prRule("N_STMTLST", "epsilon");
                    ;}
    break;

  case 75:
#line 409 "mipl.y"
    {
                    prRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
                    ;}
    break;

  case 76:
#line 414 "mipl.y"
    {
                    prRule("N_STMTPART", "N_COMPOUND");
                    ;}
    break;

  case 77:
#line 419 "mipl.y"
    {
                    prRule("N_TERM", "N_FACTOR N_MULTOPLST");
                    ;}
    break;

  case 78:
#line 424 "mipl.y"
    {
                    prRule("N_TYPE", "N_SIMPLE");
                    ;}
    break;

  case 79:
#line 428 "mipl.y"
    {
                    prRule("N_TYPE", "N_ARRAY");
                    ;}
    break;

  case 80:
#line 433 "mipl.y"
    {
                    prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
                    ;}
    break;

  case 81:
#line 438 "mipl.y"
    {
                    prRule("N_VARDECLST", "epsilon");
                    ;}
    break;

  case 82:
#line 442 "mipl.y"
    {
                    prRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
                    ;}
    break;

  case 83:
#line 447 "mipl.y"
    {
                    prRule("N_VARDECPART", "epsilon");
                    ;}
    break;

  case 84:
#line 451 "mipl.y"
    {
                    prRule("N_VARDECPART",
                        "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
                    ;}
    break;

  case 85:
#line 457 "mipl.y"
    {
                    prRule("N_VARIABLE", "N_ENTIREVAR");
                    ;}
    break;

  case 86:
#line 461 "mipl.y"
    {
                    prRule("N_VARIABLE", "N_IDXVAR");
                    ;}
    break;

  case 87:
#line 466 "mipl.y"
    {
                    prRule("N_VARIDENT", "T_IDENT");
                    ;}
    break;

  case 88:
#line 471 "mipl.y"
    {
                    prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
                    ;}
    break;

  case 89:
#line 476 "mipl.y"
    {
                    prRule("N_WRITE",
                        "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
                    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2190 "mipl.tab.c"
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


#line 481 "mipl.y"


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



