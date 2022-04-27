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
     IDENTIFIER = 258,
     CONSTANT = 259,
     SIZEOF = 260,
     PTR_OP = 261,
     LE_OP = 262,
     GE_OP = 263,
     EQ_OP = 264,
     NE_OP = 265,
     AND_OP = 266,
     OR_OP = 267,
     EXTERN = 268,
     INT = 269,
     VOID = 270,
     STRUCT = 271,
     IF = 272,
     ELSE = 273,
     WHILE = 274,
     FOR = 275,
     RETURN = 276,
     ELSE_PRIORITY = 277
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define SIZEOF 260
#define PTR_OP 261
#define LE_OP 262
#define GE_OP 263
#define EQ_OP 264
#define NE_OP 265
#define AND_OP 266
#define OR_OP 267
#define EXTERN 268
#define INT 269
#define VOID 270
#define STRUCT 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define FOR 275
#define RETURN 276
#define ELSE_PRIORITY 277




/* Copy the first part of user declarations.  */
#line 1 "structfe.y"

        #include "nodes.h"
        #include <math.h>
        #define BUFFER_SIZE 200
        #define MAX_STRING_SIZE 40
        #define RED "\033[0;31m"
        #define WHITE "\033[0;37m"
        #define PURPLE "\033[0;35m"
        #define ERROR RED"ERROR: "WHITE
        #define WARNING PURPLE"WARNING: "WHITE
        int yylex();
        int yylineno;
        int yyerror(char *);
        table_t *pile;
        int pos;
        void print_table();
        void print_node(node_t * n);
        void print_tree(nodes_list_t * n, char * space);
        void semanticAnalysis(nodes_list_t * n);
        void getLeaves(node_t * n, node_t * t);




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
#line 25 "structfe.y"
{
    char *nom; // represente nom des variables, fonctions, structures
    char* val;
    type_t type; // int ou void (variable ou fonction)
    // Une fonction prend 0 OU N parametre(s)
    param_t param; //
    //liste_t *liste; // liste de parametres
    node_t * node;
    nodes_list_t * node_list;
}
/* Line 193 of yacc.c.  */
#line 175 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 188 "y.tab.c"

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,     2,
      27,    28,    24,    22,    30,    23,    29,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      32,    34,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    17,    22,    26,
      30,    32,    36,    38,    41,    44,    46,    48,    50,    52,
      56,    60,    62,    66,    70,    72,    76,    80,    84,    88,
      90,    94,    98,   100,   104,   106,   110,   112,   116,   120,
     123,   126,   128,   130,   132,   134,   140,   145,   148,   150,
     153,   157,   160,   162,   164,   168,   173,   177,   179,   183,
     186,   188,   190,   192,   194,   196,   199,   203,   207,   212,
     214,   216,   218,   221,   223,   226,   228,   231,   237,   245,
     251,   259,   262,   266,   268,   271,   273,   275
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,     3,    -1,     4,    -1,    27,    50,    28,
      -1,    39,    -1,    40,    27,    28,    -1,    40,    27,    41,
      28,    -1,    40,    29,     3,    -1,    40,     6,     3,    -1,
      50,    -1,    41,    30,    50,    -1,    40,    -1,    43,    42,
      -1,     5,    42,    -1,    31,    -1,    24,    -1,    23,    -1,
      42,    -1,    44,    24,    42,    -1,    44,    25,    42,    -1,
      44,    -1,    45,    22,    44,    -1,    45,    23,    44,    -1,
      45,    -1,    46,    32,    45,    -1,    46,    33,    45,    -1,
      46,     7,    45,    -1,    46,     8,    45,    -1,    46,    -1,
      47,     9,    46,    -1,    47,    10,    46,    -1,    47,    -1,
      48,    11,    47,    -1,    48,    -1,    49,    12,    48,    -1,
      49,    -1,    42,    34,    50,    -1,    52,    57,    35,    -1,
      54,    35,    -1,    13,    53,    -1,    53,    -1,    15,    -1,
      14,    -1,    54,    -1,    16,     3,    36,    55,    37,    -1,
      16,    36,    55,    37,    -1,    16,     3,    -1,    56,    -1,
      55,    56,    -1,    53,    57,    35,    -1,    24,    58,    -1,
      58,    -1,     3,    -1,    27,    57,    28,    -1,    58,    27,
      59,    28,    -1,    58,    27,    28,    -1,    60,    -1,    59,
      30,    60,    -1,    52,    57,    -1,    62,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    63,    64,    -1,    63,
      66,    64,    -1,    63,    65,    64,    -1,    63,    65,    66,
      64,    -1,    36,    -1,    37,    -1,    51,    -1,    65,    51,
      -1,    61,    -1,    66,    61,    -1,    35,    -1,    50,    35,
      -1,    17,    27,    50,    28,    61,    -1,    17,    27,    50,
      28,    61,    18,    61,    -1,    19,    27,    50,    28,    61,
      -1,    20,    27,    67,    67,    50,    28,    61,    -1,    21,
      35,    -1,    21,    50,    35,    -1,    72,    -1,    71,    72,
      -1,    73,    -1,    51,    -1,    52,    57,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    71,    72,    76,    77,    78,    79,    80,
      84,    85,    89,    90,    96,   100,   101,   102,   106,   107,
     108,   112,   113,   114,   118,   119,   120,   121,   122,   126,
     127,   128,   132,   133,   137,   138,   142,   143,   163,   197,
     201,   202,   206,   207,   208,   212,   213,   214,   218,   219,
     223,   227,   230,   236,   237,   238,   239,   243,   244,   248,
     252,   253,   254,   255,   256,   260,   261,   262,   263,   266,
     267,   278,   279,   283,   284,   288,   289,   293,   294,   298,
     299,   303,   304,   308,   317,   329,   330,   334
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "SIZEOF",
  "PTR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "EXTERN", "INT", "VOID", "STRUCT", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "'+'", "'-'", "'*'", "'/'", "ELSE_PRIORITY", "'('", "')'",
  "'.'", "','", "'&'", "'<'", "'>'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression", "expression",
  "declaration", "declaration_specifiers", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "statement", "compound_statement", "ACCOO",
  "ACCOF", "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "program", "external_declaration", "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    43,    45,    42,    47,   277,    40,    41,    46,
      44,    38,    60,    62,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    42,    43,    43,    43,    44,    44,
      44,    45,    45,    45,    46,    46,    46,    46,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      56,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     4,     3,     3,
       1,     3,     1,     2,     2,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     5,     4,     2,     1,     2,
       3,     2,     1,     1,     3,     4,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     2,     3,     3,     4,     1,
       1,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       7,     2,     3,     1,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    43,    42,     0,    86,     0,    41,    44,     0,
      83,    85,    40,    44,    47,     0,    53,     0,     0,     0,
      52,    39,     1,    84,     0,     0,     0,    48,    51,     0,
      38,    69,    87,     0,     0,     0,     0,    46,    49,    54,
       2,     3,     0,     0,     0,     0,     0,    17,    16,     0,
      15,    75,    70,     5,    12,    18,     0,    21,    24,    29,
      32,    34,    36,     0,    71,     0,    73,    60,    65,     0,
       0,    61,    62,    63,    64,    56,     0,     0,    57,    45,
      50,    14,     0,     0,     0,    81,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,    72,    67,     0,
      74,    66,    59,    55,     0,     0,     0,     0,    82,     4,
       9,     6,     0,    10,     8,    37,    19,    20,    18,    22,
      23,    27,    28,    25,    26,    30,    31,    33,    35,    68,
      58,     0,     0,     0,     7,     0,    77,    79,     0,    11,
       0,     0,    78,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    53,    54,   122,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     5,     6,     7,    13,    26,    27,    19,
      20,    77,    78,    66,    67,    33,    68,    69,    70,    71,
      72,    73,    74,     9,    10,    11
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
      80,    69,   -70,   -70,    12,   -70,    27,   -70,   -18,     9,
     -70,   -70,   -70,   -70,   -24,    69,   -70,    23,    27,    52,
       0,   -70,   -70,   -70,    69,    27,    61,   -70,     0,    24,
     -70,   -70,   -70,    87,   191,   165,    -4,   -70,   -70,   -70,
     -70,   -70,   187,    43,    47,    51,   147,   -70,   -70,   187,
     -70,   -70,   -70,   -70,    99,    46,   187,    88,    97,     6,
     128,    78,   109,    74,   -70,    27,   -70,   -70,   -70,    87,
     112,   -70,   -70,   -70,   -70,   -70,    27,     4,   -70,   -70,
     -70,   -70,   187,   187,   162,   -70,    90,   102,   124,   172,
     131,   187,   -70,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   -70,   111,   -70,   -70,   112,
     -70,   -70,   -70,   -70,    80,   125,   127,   162,   -70,   -70,
     -70,   -70,    39,   -70,   -70,   -70,   -70,   -70,   -70,    88,
      88,    97,    97,    97,    97,     6,     6,   128,    78,   -70,
     -70,   137,   137,   187,   -70,   187,   141,   -70,   134,   -70,
     137,   137,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -38,   -70,    49,   123,    82,    60,
      65,   -70,   -46,   -23,   -28,    18,     2,   163,    -6,     3,
     171,   -70,    84,   -69,   175,   -70,   -62,   -70,   132,   -68,
     -70,   -70,   -70,   -70,   199,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      86,   110,     8,    87,    81,    65,    76,   108,   111,    22,
      64,     8,    24,    97,    98,    14,   117,    21,    92,    12,
      38,    29,     1,     2,     3,     4,    16,    34,    36,    38,
      16,    80,   113,    25,   114,     8,   115,   116,    99,   100,
     110,    65,    25,   123,    25,   125,   107,   139,    15,   143,
      18,    17,    39,    25,    18,   126,   127,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   144,   106,   145,
      82,     8,   146,   147,    83,     2,     3,     4,    84,   112,
      91,   152,   153,     2,     3,     4,    76,    30,    31,   103,
      40,    41,    42,     1,     2,     3,     4,   148,    37,   149,
       1,     2,     3,     4,    43,    88,    44,    45,    46,   105,
      47,    48,    93,    94,    49,    40,    41,    42,    50,    95,
      96,   104,    51,    31,    52,   118,    89,   120,    90,    43,
     119,    44,    45,    46,   124,    47,    48,   101,   102,    49,
      40,    41,    42,    50,   129,   130,    30,    51,    31,    52,
      40,    41,    42,   141,    43,   142,    44,    45,    46,   150,
      47,    48,   151,   137,    49,    40,    41,    42,    50,   138,
      47,    48,    51,    31,    49,    40,    41,    42,    50,     2,
       3,     4,    85,   135,   136,    47,    48,    35,    28,    49,
      40,    41,    42,    50,    32,    47,    48,    51,   140,    49,
     121,   109,    79,    50,     1,     2,     3,     4,    23,     0,
      47,    48,     0,     0,    49,     0,     0,     0,    50,    75,
     131,   132,   133,   134
};

static const yytype_int16 yycheck[] =
{
      46,    70,     0,    49,    42,    33,    34,    69,    70,     0,
      33,     9,    36,     7,     8,     3,    84,    35,    56,     1,
      26,    18,    13,    14,    15,    16,     3,    27,    25,    35,
       3,    35,    28,    15,    30,    33,    82,    83,    32,    33,
     109,    69,    24,    89,    26,    91,    69,   109,    36,   117,
      27,    24,    28,    35,    27,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    28,    65,    30,
      27,    69,   141,   142,    27,    14,    15,    16,    27,    76,
      34,   150,   151,    14,    15,    16,   114,    35,    36,    11,
       3,     4,     5,    13,    14,    15,    16,   143,    37,   145,
      13,    14,    15,    16,    17,     6,    19,    20,    21,    35,
      23,    24,    24,    25,    27,     3,     4,     5,    31,    22,
      23,    12,    35,    36,    37,    35,    27,     3,    29,    17,
      28,    19,    20,    21,     3,    23,    24,     9,    10,    27,
       3,     4,     5,    31,    95,    96,    35,    35,    36,    37,
       3,     4,     5,    28,    17,    28,    19,    20,    21,    18,
      23,    24,    28,   103,    27,     3,     4,     5,    31,   104,
      23,    24,    35,    36,    27,     3,     4,     5,    31,    14,
      15,    16,    35,   101,   102,    23,    24,    24,    17,    27,
       3,     4,     5,    31,    19,    23,    24,    35,   114,    27,
      28,    69,    37,    31,    13,    14,    15,    16,     9,    -1,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    28,
      97,    98,    99,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    15,    16,    51,    52,    53,    54,    71,
      72,    73,    53,    54,     3,    36,     3,    24,    27,    57,
      58,    35,     0,    72,    36,    53,    55,    56,    58,    57,
      35,    36,    62,    63,    27,    55,    57,    37,    56,    28,
       3,     4,     5,    17,    19,    20,    21,    23,    24,    27,
      31,    35,    37,    39,    40,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    61,    62,    64,    65,
      66,    67,    68,    69,    70,    28,    52,    59,    60,    37,
      35,    42,    27,    27,    27,    35,    50,    50,     6,    27,
      29,    34,    42,    24,    25,    22,    23,     7,     8,    32,
      33,     9,    10,    11,    12,    35,    57,    51,    64,    66,
      61,    64,    57,    28,    30,    50,    50,    67,    35,    28,
       3,    28,    41,    50,     3,    50,    42,    42,    42,    44,
      44,    45,    45,    45,    45,    46,    46,    47,    48,    64,
      60,    28,    28,    67,    28,    30,    61,    61,    50,    50,
      18,    28,    61,    61
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
#line 62 "structfe.y"
    {
                        symbole_t *s = NULL;
                        node_t * n = NULL;
                        table_t * stack_head = pile;
                        s = rechercher(stack_head->symbole, (yyvsp[(1) - (1)].nom));
                        n = create_node((yyvsp[(1) - (1)].nom), NULL);
                        n->symb = s;
                        (yyval.node) = n;
                      }
    break;

  case 3:
#line 71 "structfe.y"
    { node_t * n = NULL; n = create_node((yyvsp[(1) - (1)].val), NULL); /*n->type = INT_;*/ (yyval.node) = n; }
    break;

  case 4:
#line 72 "structfe.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 5:
#line 76 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); /*$$ = create_node("postfix_expression", mergeNodes(1,$1));*/}
    break;

  case 6:
#line 77 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); }
    break;

  case 8:
#line 79 "structfe.y"
    { node_t * n = NULL; n = create_node(".", mergeNodes(2, (yyvsp[(1) - (3)].node), create_node((yyvsp[(3) - (3)].nom), NULL))); /*n->type = INT_;*/ (yyval.node) = n; }
    break;

  case 9:
#line 80 "structfe.y"
    { node_t * n = NULL; n = create_node("->", mergeNodes(2, (yyvsp[(1) - (3)].node), create_node((yyvsp[(3) - (3)].nom), NULL))); /*n->type = INT_;*/ (yyval.node) = n; }
    break;

  case 12:
#line 89 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 13:
#line 90 "structfe.y"
    { 
                                                node_t * n = NULL;
                                                n = create_node((yyvsp[(1) - (2)].nom), mergeNodes(1,(yyvsp[(2) - (2)].node)));
                                                //n->type = $2->type;
                                                (yyval.node) = n;
                                          }
    break;

  case 15:
#line 100 "structfe.y"
    {(yyval.nom)="&";}
    break;

  case 16:
#line 101 "structfe.y"
    {(yyval.nom)="*";}
    break;

  case 17:
#line 102 "structfe.y"
    {(yyval.nom)="-";}
    break;

  case 18:
#line 106 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 19:
#line 107 "structfe.y"
    {(yyval.node) = create_node("*", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));}
    break;

  case 20:
#line 108 "structfe.y"
    {(yyval.node) = create_node("/", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));}
    break;

  case 21:
#line 112 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 22:
#line 113 "structfe.y"
    {(yyval.node) = create_node("+", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));}
    break;

  case 23:
#line 114 "structfe.y"
    {(yyval.node) = create_node("-", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));}
    break;

  case 24:
#line 118 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 29:
#line 126 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 32:
#line 132 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 34:
#line 137 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 36:
#line 142 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 37:
#line 143 "structfe.y"
    {     
                                                (yyval.node) = create_node("=", mergeNodes(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
                                                /*table_t * stack_head = pile;
                                                symbole_t * var = rechercher(stack_head->symbole, $1);
                                                printf("", )
                                                //printf("%s %u et %s %u\n",$1->name, $1->type, $3->name, $3->type);
                                                //printf("%s est ptr ? %d\n", $1->name, rechercher($1,table).isPtr)
                                                si expression n'a pas d'enfant
                                                        symbole_t * var2 = rechercher(stack_head->symbole, $1->name);
                                                        ....
                                                sinon
                                                        retrieveTypeOfNoeud*/
                                                /*if(var->type != $3->type || var->isPtr != ...){
                                                        printf("%sLigne %d, vous ne pouvez pas affecter un type %u à une variable de type %u.\n", ERROR, yylineno, $3->type, $1->type);
                                                } */
                                                /*$$ = create_node("expression", mergeNodes(3,$1,create_node("=", NULL),$3));*/
        }
    break;

  case 38:
#line 163 "structfe.y"
    {
                                                        if((yyvsp[(1) - (3)].type) == VOID_){
                                                                printf("%sLigne %d, vous ne pouvez pas déclarer une variable de type void.\n",ERROR, yylineno);
                                                                exit(1);
                                                        }
                                                        symbole_t *s = NULL;
                                                        table_t * stack_head = pile;
                                                        if(stack_head == NULL){
                                                                table_t *table = nouvelle_table(); push(table); // Si la pile est vide on l'initialise
                                                        }
                                                        while(stack_head != NULL){
                                                                if(stack_head->symbole != NULL){
                                                                s = rechercher(stack_head->symbole, (yyvsp[(2) - (3)].nom));
                                                                if(s != NULL)
                                                                        break;
                                                                }
                                                                stack_head = stack_head->preced;
                                                        }
                                                        if((s != NULL) && (stack_head->symbole == pile->symbole) && (stack_head->preced == pile->preced)){
                                                                printf("%sLigne %d, la variable '%s' a déjà été déclarée.\n", ERROR, yylineno, (yyvsp[(2) - (3)].nom));
                                                                exit(1);
                                                        } else {
                                                                if(s != NULL)
                                                                printf("%sLigne %d, la variable '%s' en masque une autre\n", WARNING, yylineno, (yyvsp[(2) - (3)].nom));
                                                                table_t * t = *top();
                                                                s = ajouter(&(t->symbole), (yyvsp[(2) - (3)].nom));
                                                                s->type = (yyvsp[(1) - (3)].type);
                                                                s->taille = sizeof((yyvsp[(1) - (3)].type));
                                                                s->position = pos;
                                                                s->suivant = NULL;
                                                                pos += s->taille;
                                                        }
                                                        print_table();
                                                }
    break;

  case 40:
#line 201 "structfe.y"
    {(yyval.type) = (yyvsp[(2) - (2)].type);}
    break;

  case 41:
#line 202 "structfe.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 42:
#line 206 "structfe.y"
    { (yyval.type) = VOID_ ;}
    break;

  case 43:
#line 207 "structfe.y"
    { (yyval.type) = INT_ ;}
    break;

  case 44:
#line 208 "structfe.y"
    {(yyval.type) = STRUCT_ ;}
    break;

  case 51:
#line 227 "structfe.y"
    {
                                        sprintf((yyval.nom), "%s%s", "*", (yyvsp[(2) - (2)].nom));
                                }
    break;

  case 52:
#line 230 "structfe.y"
    {
                                (yyval.nom) = (yyvsp[(1) - (1)].nom);
                            }
    break;

  case 53:
#line 236 "structfe.y"
    {(yyval.nom) = (yyvsp[(1) - (1)].nom);}
    break;

  case 54:
#line 237 "structfe.y"
    {(yyval.nom) = (yyvsp[(2) - (3)].nom);}
    break;

  case 56:
#line 239 "structfe.y"
    {(yyval.nom) = (yyvsp[(1) - (3)].nom);}
    break;

  case 60:
#line 252 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 61:
#line 253 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 62:
#line 254 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 63:
#line 255 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 64:
#line 256 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 66:
#line 261 "structfe.y"
    {(yyval.node) = create_node("main_2", (yyvsp[(2) - (3)].node_list));}
    break;

  case 68:
#line 263 "structfe.y"
    {(yyval.node) = create_node("main_3", (yyvsp[(3) - (4)].node_list));}
    break;

  case 69:
#line 266 "structfe.y"
    {table_t *table = nouvelle_table(); push(table);}
    break;

  case 70:
#line 267 "structfe.y"
    {
                table_t *table = pop(); 
                detruire_table(&table);
                if((*top()) != NULL){ // autrement dit si la pile est vide    
                    print_table();
                } else {
                    printf("[]\n");
                }
            }
    break;

  case 71:
#line 278 "structfe.y"
    {}
    break;

  case 72:
#line 279 "structfe.y"
    {}
    break;

  case 73:
#line 283 "structfe.y"
    {(yyval.node_list) = mergeNodes(1, (yyvsp[(1) - (1)].node));}
    break;

  case 74:
#line 284 "structfe.y"
    { (yyval.node_list) = pushNode((yyvsp[(1) - (2)].node_list), (yyvsp[(2) - (2)].node));}
    break;

  case 76:
#line 289 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 82:
#line 304 "structfe.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node); /*$$ = create_node("jump_statement", mergeNodes(3,create_node("return", NULL), $2, create_node(";", NULL)));*/}
    break;

  case 83:
#line 308 "structfe.y"
    {
                nodes_list_t * arbre = NULL;
                if((yyvsp[(1) - (1)].node) != NULL){
                        printf("ext 1\n");
                        (yyval.node) = create_node("prog", mergeNodes(1, (yyvsp[(1) - (1)].node))); 
                        arbre = mergeNodes(1, (yyvsp[(1) - (1)].node));
                        print_tree(arbre, "");
                }
        }
    break;

  case 84:
#line 317 "structfe.y"
    {
                nodes_list_t * arbre = NULL;
                if((yyvsp[(2) - (2)].node) != NULL){
                        printf("ext 2\n");
                        (yyval.node) = create_node("prog", mergeNodes(1, (yyvsp[(2) - (2)].node)));
                        arbre = mergeNodes(1, (yyvsp[(2) - (2)].node));
                        print_tree(arbre, "");
                }
        }
    break;

  case 85:
#line 329 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 86:
#line 330 "structfe.y"
    {(yyval.node) = NULL;}
    break;

  case 87:
#line 334 "structfe.y"
    { (yyval.node) = (yyvsp[(3) - (3)].node); }
    break;


/* Line 1267 of yacc.c.  */
#line 1905 "y.tab.c"
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


#line 337 "structfe.y"

        int yyerror(char *s){ // fonction pour détecter une erreur
                fprintf(stderr, "%s\n", s);
                exit(1);
        }

        int pos = 0;
        table_t * pile = NULL;

        table_t ** top() {
                return &pile;
        }

        table_t * nouvelle_table(){
                table_t * t = malloc(sizeof(table_t));
                assert(t != NULL);
                t->symbole = NULL;
                t->preced = NULL;
                return t;
        }

        void push(table_t * table){
                table_t ** stack = top();
                table->preced = *stack;
                *stack = table;
        }

        symbole_t * rechercher(symbole_t * list, char * nom){
                if(list != NULL){
                        symbole_t *last = list;
                        while(strcmp(last->nom, nom) != 0){
                        if (last->suivant == NULL){
                                return NULL;
                        }
                        last = last->suivant;           
                        }
                        return last;
                }else{
                        return NULL;
                }
        }

        symbole_t * ajouter(symbole_t ** list_s, char *nom){
                symbole_t *s = malloc(sizeof(symbole_t));
                assert(s != NULL);
                if(nom[0] == '*'){
                        s->isPtr = true;
                        nom++; // on retire le premier caractere
                } else {
                        s->isPtr = false;
                }
                s->nom = strdup(nom);
                if((*list_s) != NULL){
                        symbole_t *last = (*list_s);
                        while(last->suivant != NULL){
                                last = last->suivant;
                        }
                        last->suivant = s;
                }else{
                        *list_s = s;
                }
                return s;
        }

        void print_table(){
                table_t * stack = malloc(sizeof (table_t));
                assert(stack != NULL);

                if(*top() != NULL){
                        stack->symbole = (*top())->symbole;
                        stack->preced = (*top())->preced;
                }
                
                printf("[");
                while(stack != NULL){
                        printf("{ ");
                        while(stack->symbole != NULL){
                                printf("%s -> ", stack->symbole->nom);
                                stack->symbole = stack->symbole->suivant;
                        }
                        printf("NULL }");

                        if(stack->preced != NULL){
                                stack->symbole = stack->preced->symbole;
                                stack->preced = stack->preced->preced;
                        } else {
                                break;
                        }
                }
                printf("]\n");
                free(stack);
        }

        table_t * pop(){
                table_t ** stack_header = top();
                table_t * first = *top();
                *stack_header = first->preced;
                return first;
        }

        void detruire_table(table_t ** t){
                symbole_t *tmp;
                while((*t)->symbole != NULL){
                        tmp = (*t)->symbole;
                        (*t)->symbole = (*t)->symbole->suivant;
                        free(tmp->nom); // A cause du strdup
                        free(tmp);
                }
                //t = NULL;
                free(*t);
        }

        // function for nodes 
        nodes_list_t * mergeNodes(int nbPara, ...){
                if(nbPara == 0)
                        return NULL;

                va_list ap;    
                va_start(ap, nbPara);
                nodes_list_t * n = malloc(sizeof(nodes_list_t));
                n->first = va_arg(ap, node_t *);

                if(nbPara == 1)
                        return n;

                n->next = malloc(sizeof(nodes_list_t));

                nodes_list_t * temp = n->next;

                for(int j = 1; j < nbPara; j++){
                        node_t * current = va_arg(ap, node_t *);
                        temp->first = current;
                        if(j != nbPara -1){
                                temp->next = malloc(sizeof(nodes_list_t));
                                temp = temp->next;
                        }
                }
                        va_end(ap);
                        return n;
        };

        void print_node(node_t * n){
                printf("nom : %s\n", n->name);
                nodes_list_t * current = n->children; //malloc(sizeof(nodes_list_t));
                //current = n->children;
                printf("mes fils sont: ");
                while(current != NULL){
                        printf("%s -> ", current->first->name);
                        current = current->next;
                }
                printf("NULL\n");
        };

        node_t * create_node(char * name, nodes_list_t * nodesList){
                node_t * n = malloc(sizeof(node_t));
                assert(n != NULL);
                n->name = name;
                n->children = nodesList;
                //print_node(n);
                return n;
        };

        void print_tree(nodes_list_t * n, char * space){
                printf("%s\n", n->first->name);
                //current = n->children;
                nodes_list_t * current = n->first->children;
                char * newspace = "     ";
                //char ntarget[strlen(space) + strlen(newspace) + 1];
                while(current != NULL){ // Tant que le pere a des enfants
                    //strcpy(ntarget, space);
                    printf("%s     |___> ", space);
                    //strcat(ntarget, newspace);
                    printf("%s \n", current->first->name);
                    nodes_list_t * depth_current = current->first->children;
                    while(depth_current != NULL){ //tant que j'ai pas vu tout les enfants
                        char target[strlen(space) + strlen(newspace) + 1];
                        strcpy(target, space);
                        strcat(target, newspace);
                        printf("%s     |___> ", target);

                        char ntarget[strlen(target) + strlen(newspace) + 1];
                        strcpy(ntarget, target);
                        strcat(ntarget, newspace);

                        print_tree(depth_current, ntarget);
                        depth_current = depth_current->next;
                        printf("\n");
                    }
                    
                    current = current->next;
                }
        };

        nodes_list_t * pushNode(nodes_list_t * t, node_t * n){
                nodes_list_t * copy = t;
                nodes_list_t * current = copy;
                while(current->next != NULL){
                        current = current->next;
                }
                current->next = mergeNodes(1, n);
                return copy;
        };

        int main(){
                while(1){
                        yyparse();
                }
        }
