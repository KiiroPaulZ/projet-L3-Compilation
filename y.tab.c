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

        /* Variables globales */
        int pos; // Pointeur sur une case disponible en mémoire
        param_list_t * param_list_stack; 
        field_list_t * field_list_stack; 
        table_t *pile; // TS
        
        #define RED "\033[0;31m"
        #define WHITE "\033[0;37m"
        #define PURPLE "\033[0;35m"
        #define ERROR RED"ERROR: "WHITE
        #define WARNING PURPLE"WARNING: "WHITE

        extern int yylex();
        extern int yylineno;
        int yyerror(char *);

        char * marker = "prog"; // Marque par défaut, pour verifier si une variable globale est redefinie

        char * type_check(nodes_list_t * a); // Partie finale de l'analyse sémantique, on vérifie le typage et si les opérations sont correctes sur la représentation intermédiaire
        int verifyParamIntegrity(param_list_t * pls); // Vérifie si chaque déclaration est bien formée (présence des paramètres dans ts)
        code_info * generation (node_t * a); // après l'analyse sémantique, génération du code en partant de la racine


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
#line 28 "structfe.y"
{
        char *nom; // represente nom des variables, fonctions, structures
        char* val;

        /*type_t type; // int ou void (variable ou fonction)
        param_t param; 
        param_list_t * param_list;*/

        node_t * node;
        nodes_list_t * node_list;
        symbole_t * symb;
}
/* Line 193 of yacc.c.  */
#line 180 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 193 "y.tab.c"

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

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
     251,   259,   262,   266,   268,   270,   273,   275,   277,   280
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
      68,    -1,    69,    -1,    70,    -1,    36,    37,    -1,    63,
      66,    64,    -1,    63,    65,    64,    -1,    63,    65,    66,
      64,    -1,    36,    -1,    37,    -1,    51,    -1,    65,    51,
      -1,    61,    -1,    66,    61,    -1,    35,    -1,    50,    35,
      -1,    17,    27,    50,    28,    61,    -1,    17,    27,    50,
      28,    61,    18,    61,    -1,    19,    27,    50,    28,    61,
      -1,    20,    27,    67,    67,    50,    28,    61,    -1,    21,
      35,    -1,    21,    50,    35,    -1,    72,    -1,    73,    -1,
      72,    73,    -1,    75,    -1,    51,    -1,    52,    57,    -1,
      74,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    75,    76,    80,    81,    90,   132,   137,
     145,   154,   166,   167,   172,   176,   177,   178,   182,   183,
     184,   188,   189,   190,   194,   195,   196,   197,   198,   202,
     203,   204,   208,   209,   213,   214,   218,   219,   223,   316,
     348,   373,   377,   378,   379,   383,   391,   392,   396,   397,
     401,   418,   424,   428,   429,   430,   431,   435,   436,   440,
     457,   458,   459,   460,   461,   465,   466,   467,   468,   471,
     472,   488,   489,   493,   494,   498,   499,   503,   504,   508,
     509,   513,   514,   517,   527,   581,   636,   637,   641,   710
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
  "program_start", "program", "external_declaration", "function_init",
  "function_definition", 0
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
      69,    70,    70,    71,    72,    72,    73,    73,    74,    75
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
       7,     2,     3,     1,     1,     2,     1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    43,    42,     0,    87,     0,    41,    44,     0,
      83,    84,     0,    86,    40,    44,    47,     0,    53,     0,
       0,    88,    52,    39,     1,    85,    69,    89,     0,     0,
       0,     0,    48,    51,     0,    38,     0,    65,     2,     3,
       0,     0,     0,     0,     0,    17,    16,     0,    15,    75,
       5,    12,    18,     0,    21,    24,    29,    32,    34,    36,
       0,    71,     0,    73,    60,     0,     0,    61,    62,    63,
      64,     0,     0,    46,    49,    54,    56,     0,     0,    57,
      14,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,    70,    72,    67,     0,
      74,    66,    45,    50,    59,    55,     0,     0,     0,     0,
      82,     4,     9,     6,     0,    10,     8,    37,    19,    20,
      18,    22,    23,    27,    28,    25,    26,    30,    31,    33,
      35,    68,    58,     0,     0,     0,     7,     0,    77,    79,
       0,    11,     0,     0,    78,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    50,    51,   124,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     5,     6,     7,    15,    31,    32,    21,
      22,    78,    79,    63,    64,    28,   108,    65,    66,    67,
      68,    69,    70,     9,    10,    11,    12,    13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int16 yypact[] =
{
      10,    71,   -66,   -66,    17,   -66,     9,   -66,   -19,    30,
      10,   -66,    -2,   -66,   -66,   -66,     7,    71,   -66,     8,
       9,    15,    28,   -66,   -66,   -66,    22,   -66,   163,    71,
       9,    84,   -66,    28,    39,   -66,   221,   -66,   -66,   -66,
      37,    48,    66,    75,   188,   -66,   -66,    37,   -66,   -66,
     -66,   125,    44,    37,    -3,     5,    87,   129,   114,   123,
     111,   -66,     9,   -66,   -66,   113,   138,   -66,   -66,   -66,
     -66,   108,   112,   -66,   -66,   -66,   -66,     9,   -15,   -66,
     -66,    37,    37,   197,   -66,   116,   128,   150,   202,   157,
      37,   -66,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,   -66,    15,   -66,   -66,   -66,   138,
     -66,   -66,   -66,   -66,   -66,   -66,    10,   135,   136,   197,
     -66,   -66,   -66,   -66,    51,   -66,   -66,   -66,   -66,   -66,
     -66,    -3,    -3,     5,     5,     5,     5,    87,    87,   129,
     114,   -66,   -66,    53,    53,    37,   -66,    37,   152,   -66,
     143,   -66,    53,    53,   -66,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,    12,   -66,   -32,   142,    -4,    70,
      78,   -66,   -44,   -20,   -26,     0,     4,   156,   -24,   -11,
     169,   -66,    73,   -61,   183,   -66,   -60,   -66,   131,   -65,
     -66,   -66,   -66,   -66,   -66,   187,   -66,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      85,    14,    62,    86,     8,   110,   111,    74,    61,    34,
      77,    18,    18,   115,     8,   116,    23,    30,   119,    72,
      16,    92,    93,     1,     2,     3,     4,    94,    95,    30,
      24,    30,     8,    19,    26,    20,    20,   117,   118,    62,
      38,    39,    40,    29,   125,   107,   127,    74,   110,   141,
      35,   105,    80,    17,   145,    36,    38,    39,    40,    37,
      45,    46,   131,   132,    47,    91,   114,    75,    48,     8,
      41,    30,    42,    43,    44,    81,    45,    46,    90,   146,
      47,   147,   148,   149,    48,     2,     3,     4,    49,    26,
      77,   154,   155,    82,    96,    97,   137,   138,     2,     3,
       4,   150,    83,   151,   128,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,    38,    39,    40,    98,
      99,    73,     2,     3,     4,   102,     1,     2,     3,     4,
      41,    87,    42,    43,    44,   103,    45,    46,   100,   101,
      47,    38,    39,    40,    48,   112,   104,   113,    49,    26,
     106,   120,    88,   122,    89,    41,   121,    42,    43,    44,
     126,    45,    46,   143,   144,    47,    38,    39,    40,    48,
     152,   153,   139,    49,    26,   106,     1,     2,     3,     4,
      41,   140,    42,    43,    44,    71,    45,    46,    33,   142,
      47,    38,    39,    40,    48,    27,   109,    25,    49,    26,
      38,    39,    40,     0,     0,    38,    39,    40,     0,     0,
       0,    45,    46,     0,     0,    47,     0,     0,     0,    48,
      45,    46,     0,    84,    47,    45,    46,     0,    48,    47,
     123,     0,    49,    48,     1,     2,     3,     4,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,    76
};

static const yytype_int16 yycheck[] =
{
      44,     1,    28,    47,     0,    66,    66,    31,    28,    20,
      36,     3,     3,    28,    10,    30,    35,    17,    83,    30,
       3,    24,    25,    13,    14,    15,    16,    22,    23,    29,
       0,    31,    28,    24,    36,    27,    27,    81,    82,    65,
       3,     4,     5,    36,    88,    65,    90,    71,   109,   109,
      35,    62,    40,    36,   119,    27,     3,     4,     5,    37,
      23,    24,    94,    95,    27,    53,    77,    28,    31,    65,
      17,    71,    19,    20,    21,    27,    23,    24,    34,    28,
      27,    30,   143,   144,    31,    14,    15,    16,    35,    36,
     116,   152,   153,    27,     7,     8,   100,   101,    14,    15,
      16,   145,    27,   147,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     3,     4,     5,    32,
      33,    37,    14,    15,    16,    11,    13,    14,    15,    16,
      17,     6,    19,    20,    21,    12,    23,    24,     9,    10,
      27,     3,     4,     5,    31,    37,    35,    35,    35,    36,
      37,    35,    27,     3,    29,    17,    28,    19,    20,    21,
       3,    23,    24,    28,    28,    27,     3,     4,     5,    31,
      18,    28,   102,    35,    36,    37,    13,    14,    15,    16,
      17,   103,    19,    20,    21,    29,    23,    24,    19,   116,
      27,     3,     4,     5,    31,    12,    65,    10,    35,    36,
       3,     4,     5,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      23,    24,    -1,    35,    27,    23,    24,    -1,    31,    27,
      28,    -1,    35,    31,    13,    14,    15,    16,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    15,    16,    51,    52,    53,    54,    71,
      72,    73,    74,    75,    53,    54,     3,    36,     3,    24,
      27,    57,    58,    35,     0,    73,    36,    62,    63,    36,
      53,    55,    56,    58,    57,    35,    27,    37,     3,     4,
       5,    17,    19,    20,    21,    23,    24,    27,    31,    35,
      39,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    61,    62,    65,    66,    67,    68,    69,
      70,    55,    57,    37,    56,    28,    28,    52,    59,    60,
      42,    27,    27,    27,    35,    50,    50,     6,    27,    29,
      34,    42,    24,    25,    22,    23,     7,     8,    32,    33,
       9,    10,    11,    12,    35,    57,    37,    51,    64,    66,
      61,    64,    37,    35,    57,    28,    30,    50,    50,    67,
      35,    28,     3,    28,    41,    50,     3,    50,    42,    42,
      42,    44,    44,    45,    45,    45,    45,    46,    46,    47,
      48,    64,    60,    28,    28,    67,    28,    30,    61,    61,
      50,    50,    18,    28,    61,    61
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
#line 66 "structfe.y"
    { 
                        symbole_t * s = NULL;
                        node_t * n = NULL;
                        table_t * stack_head = pile;
                        s = rechercher_global(stack_head, (yyvsp[(1) - (1)].nom),0, ""); // Recherche de s dans dans la table
                        n = create_node(strdup((yyvsp[(1) - (1)].nom)), NULL); // On crée un noeud auquel on associe le symbole
                        n->symb = s;
                        (yyval.node) = n;
                      }
    break;

  case 3:
#line 75 "structfe.y"
    { node_t * n = NULL; n = create_node(strdup((yyvsp[(1) - (1)].val)), NULL); n->isConst = true; (yyval.node) = n; }
    break;

  case 4:
#line 76 "structfe.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 5:
#line 80 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
#line 81 "structfe.y"
    { // appel de fonction anonyme
                if((yyvsp[(1) - (3)].node)->symb != NULL && (yyvsp[(1) - (3)].node)->symb->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength((yyvsp[(1) - (3)].node)->symb->param_list))){ // Verification s'il s'agit bien d'un appel de fonction et si son nombre de paramètre correspond
                        (yyval.node) = (yyvsp[(1) - (3)].node);
                } else {
                        clean_param_list_stack();
                        printf("%sLigne %d, ceci n'est pas une fonction anonyme!\n",ERROR, yylineno);
                        exit(1);
                }
        }
    break;

  case 7:
#line 90 "structfe.y"
    { // appel de fonction
                // S'il s'agit d'une fonction, qu'il a un symbole associé et que la liste des parametres correspond à la liste de parametres définie initialement
                if((yyvsp[(1) - (4)].node)->symb != NULL && (yyvsp[(1) - (4)].node)->symb->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength((yyvsp[(1) - (4)].node)->symb->param_list)) && verifyParamIntegrity(param_list_stack) == 1){
                        if((yyvsp[(1) - (4)].node)->symb->is_function_def){
                                clean_param_list_stack(); // Après chaque utilisation il faut penser à clean la pile de parametre globale
                                (yyval.node) = (yyvsp[(1) - (4)].node);
                        } else {
                                printf("%sLigne %d, La fonction '%s' existe, mais il n'y a aucune reference.\n", ERROR, yylineno, (yyvsp[(1) - (4)].node)->name);
                                exit(1);
                        }
                } else if((yyvsp[(1) - (4)].node)->symb != NULL && (yyvsp[(1) - (4)].node)->symb->ts == FONCTION_) { // peut-etre existe-il une "surcharge" de cette fonction
                        int n = 1;
                        symbole_t * sy = NULL;
                        while(sy == NULL){ // Tant qu'il y a des occurences de la fonction, on regarde "ses surcharges"
                                sy = rechercher_global(pile, (yyvsp[(1) - (4)].node)->symb->nom, n, "");
                                if(sy == NULL)
                                        break;
                                if(sy->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength(sy->param_list)) && verifyParamIntegrity(param_list_stack) == 1){
                                        if(sy->is_function_def) {
                                                clean_param_list_stack(); // Après chaque utilisation il faut penser à clean la pile de parametre globale
                                                (yyval.node) = (yyvsp[(1) - (4)].node);
                                        } else {
                                                printf("%sLigne %d, La fonction '%s' existe, mais il n'y a aucune reference.\n", ERROR, yylineno, (yyvsp[(1) - (4)].node)->name);
                                                exit(1);
                                        }
                                } else { // Une occurence a été trouvé mais pas le bon nb de params
                                        
                                }

                                n++;
                        }
                        if(sy == NULL){
                                clean_param_list_stack();
                                printf("%sLigne %d, la fonction n'est pas déclaré et/ou le nombre de paramètres n'est pas valide!\n",ERROR, yylineno);
                                exit(1);
                        }
                } else  {
                                clean_param_list_stack();
                                printf("%sLigne %d, la fonction n'est pas déclaré et/ou le nombre de paramètres n'est pas valide!\n",ERROR, yylineno);
                                exit(1);
                        }
        }
    break;

  case 8:
#line 132 "structfe.y"
    {
                                                node_t * n = NULL; 
                                                n = create_node(".", mergeNodes(2, (yyvsp[(1) - (3)].node), create_node(strdup((yyvsp[(3) - (3)].nom)), NULL))); 
                                                (yyval.node) = n;
                                            }
    break;

  case 9:
#line 137 "structfe.y"
    { 
                                                        node_t * n = NULL; 
                                                        n = create_node("->", mergeNodes(2, (yyvsp[(1) - (3)].node), create_node(strdup((yyvsp[(3) - (3)].nom)), NULL))); 
                                                        (yyval.node) = n; 
                                                }
    break;

  case 10:
#line 145 "structfe.y"
    {
                                // On sauvegarde des informations pour le paramètre dans la TS et on l'ajoute à la pile des paramètres courants
                                if((yyvsp[(1) - (1)].node)->symb == NULL){
                                        symbole_t * s = malloc(sizeof(symbole_t));
                                        s->nom = (yyvsp[(1) - (1)].node)->name;
                                        (yyvsp[(1) - (1)].node)->symb = s;
                                }
                                addParam(&param_list_stack, (yyvsp[(1) - (1)].node)->symb);
                        }
    break;

  case 11:
#line 154 "structfe.y"
    {

                                                                if((yyvsp[(3) - (3)].node)->symb == NULL){ // Si le noeud n'a pas de symbole c'est qu'il s'agit d'une opération, donc on lui creer un symbole "vide"
                                                                        symbole_t * s = malloc(sizeof(symbole_t));
                                                                        s->nom = (yyvsp[(3) - (3)].node)->name;
                                                                        (yyvsp[(3) - (3)].node)->symb = s;
                                                                }
                                                                addParam(&param_list_stack, (yyvsp[(3) - (3)].node)->symb);
                                                        }
    break;

  case 12:
#line 166 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:
#line 167 "structfe.y"
    {
                                                node_t * n = NULL;
                                                n = create_node(strdup((yyvsp[(1) - (2)].nom)), mergeNodes(1,(yyvsp[(2) - (2)].node)));
                                                (yyval.node) = n;
                                          }
    break;

  case 14:
#line 172 "structfe.y"
    { (yyval.node) = create_node("SIZEOF", mergeNodes(1,(yyvsp[(2) - (2)].node))); }
    break;

  case 15:
#line 176 "structfe.y"
    { (yyval.nom)="&"; }
    break;

  case 16:
#line 177 "structfe.y"
    { (yyval.nom)="*"; }
    break;

  case 17:
#line 178 "structfe.y"
    { (yyval.nom)="-"; }
    break;

  case 18:
#line 182 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 19:
#line 183 "structfe.y"
    { (yyval.node) = create_node("*", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 20:
#line 184 "structfe.y"
    { (yyval.node) = create_node("/", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 21:
#line 188 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 22:
#line 189 "structfe.y"
    { (yyval.node) = create_node("+", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 23:
#line 190 "structfe.y"
    { (yyval.node) = create_node("-", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 24:
#line 194 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 25:
#line 195 "structfe.y"
    { (yyval.node) = create_node("<", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 26:
#line 196 "structfe.y"
    { (yyval.node) = create_node(">", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 27:
#line 197 "structfe.y"
    { (yyval.node) = create_node("<=", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 28:
#line 198 "structfe.y"
    { (yyval.node) = create_node(">=", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 29:
#line 202 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 30:
#line 203 "structfe.y"
    { (yyval.node) = create_node("==", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 31:
#line 204 "structfe.y"
    { (yyval.node) = create_node("!=", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 32:
#line 208 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 33:
#line 209 "structfe.y"
    { (yyval.node) = create_node("&&", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 34:
#line 213 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 35:
#line 214 "structfe.y"
    { (yyval.node) = create_node("||", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 36:
#line 218 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:
#line 219 "structfe.y"
    { (yyval.node) = create_node("=", mergeNodes(2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); }
    break;

  case 38:
#line 223 "structfe.y"
    {       
                                                        if((yyvsp[(1) - (3)].node)->type == VOID_){
                                                                printf("%sLigne %d, vous ne pouvez pas déclarer une variable de type void.\n", ERROR, yylineno);
                                                                exit(1);
                                                        }
                                                        
                                                        symbole_t *s = NULL;
                                                        table_t * stack_head = pile;
                                                        
                                                        if(stack_head == NULL){
                                                                table_t *table = nouvelle_table(); // Si la pile est vide on l'initialise
                                                                push(table); 
                                                        }
                                                        
                                                        table_t * current = stack_head;

                                                        if((yyvsp[(1) - (3)].node)->type == STRUCT_){
                                                                symbole_t * s = rechercher_global(current->preced, (yyvsp[(1) - (3)].node)->children->first->name, 0, ""); 

                                                                if(s == NULL){
                                                                        printf("%sLigne %d, cette structure n'est pas définie.\n",ERROR, yylineno);
                                                                        exit(1);
                                                                }
                                                        }
                                                        
                                                        if(current != NULL)
                                                                s = rechercher(current->symbole, (yyvsp[(2) - (3)].node)->name);
                                                        
                                                        symbole_t * s2 = NULL;

                                                        if(stack_head != NULL && stack_head->preced != NULL && stack_head->preced->symbole != NULL)
                                                                s2 = rechercherStack((getSymbole(stack_head->preced->symbole,-1))->param_list, (yyvsp[(2) - (3)].node)->name); // Je vérifie aussi si ce que je déclare n'a pas le meme nom qu'un parametre dans la définition de fonction courante
                                                       
                                                        if(s != NULL && s->ts != FONCTION_ && strcmp(s->marker, marker) == 0 || ((rechercher_global(pile, (yyvsp[(2) - (3)].node)->name, 0, "prog")) != NULL && strcmp((rechercher_global(pile, (yyvsp[(2) - (3)].node)->name, 0, "prog"))->marker, marker) == 0) && (rechercher_global(pile, (yyvsp[(2) - (3)].node)->name, 0, "prog"))->ts != FONCTION_ ){
                                                                printf("%sLigne %d, la variable '%s' a déjà été déclarée.\n", ERROR, yylineno, (yyvsp[(2) - (3)].node)->name);
                                                                exit(1);
                                                        } else if (s2 != NULL) {
                                                                printf("%sLigne %d, vous ne pouvez pas déclarer %s car elle est défini en parametre de fonction.\n", ERROR, yylineno, (yyvsp[(2) - (3)].node)->name);
                                                                exit(1);
                                                         }else if (s != NULL && s->ts == FONCTION_){ 
                                                                s->param_list = copyParamList(param_list_stack);
                                                                clean_param_list_stack();
                                                         }else {
                                                                while(current != NULL){ // je vérifie si la variable a deja été declaré
                                                                        if(current ->symbole != NULL){
                                                                                s = rechercher(current->symbole, (yyvsp[(2) - (3)].node)->name);
                                                                                if(s != NULL)
                                                                                        break;
                                                                        }
                                                                        current  = current ->preced;
                                                                }

                                                                if(((rechercher_global(pile, (yyvsp[(2) - (3)].node)->name, 0, "prog")) != NULL && strcmp((rechercher_global(pile, (yyvsp[(2) - (3)].node)->name, 0, "prog"))->marker, "prog") == 0) && (rechercher_global(pile, (yyvsp[(2) - (3)].node)->name, 0, "prog"))->ts != FONCTION_ ) // le -1 pour regarde les déclarations globales
                                                                        printf("%sLigne %d, la variable '%s' en masque une autre.\n", WARNING, yylineno, (yyvsp[(2) - (3)].node)->name);
                                                                table_t * t = *top(); // Le symbole n'existe pas, il faut le définir
                                                                s = ajouter(&(t->symbole), (yyvsp[(2) - (3)].node)->name);
                                                                if((yyvsp[(1) - (3)].node)->type == EXTERN_INT_ || (yyvsp[(1) - (3)].node)->type == EXTERN_VOID_ || (yyvsp[(1) - (3)].node)->type == EXTERN_STRUCT_){ // Ici on gere les extern
                                                                        s->ts = FONCTION_; //EXTERN_FONCTION_;
                                                                        s->is_function_def = true;
                                                                        switch((yyvsp[(1) - (3)].node)->type){
                                                                                case EXTERN_INT_: s->type = INT_; break;
                                                                                case EXTERN_VOID_ : s->type = VOID_; break;
                                                                                default : s->type = STRUCT_;
                                                                        }
                                                                } 
                                                                s->ts = (yyvsp[(2) - (3)].node)->ts_t;
                                                                if(param_list_stack != NULL){ // S'il a des paramètres, on les sauvegardes
                                                                        s->param_list = copyParamList(param_list_stack);
                                                                        clean_param_list_stack();
                                                                }
                                                                s->marker = marker;

                                                                if((yyvsp[(1) - (3)].node)->type == INT_){
                                                                        if(s->isPtr == true){
                                                                                s->taille = sizeof(8);
                                                                        } else {
                                                                                s->taille = sizeof(4);
                                                                        }
                                                                } else if ((yyvsp[(1) - (3)].node)->type == VOID_){
                                                                        if(s->isPtr == true){
                                                                             s->taille = sizeof(8);
                                                                        } else {
                                                                                s->taille = 0;
                                                                        }
                                                                } else { // Cas si c'est de type STRUCT_
                                                                        s->taille = sizeof(4);
                                                                }

                                                                s->position = pos;
                                                                s->suivant = NULL;
                                                                pos += s->taille;
                                                        }
                                                }
    break;

  case 39:
#line 316 "structfe.y"
    {
                symbole_t *s = NULL;
                table_t * stack_head = pile;
                table_t * current = stack_head;
                
                if(stack_head == NULL){
                        table_t *table = nouvelle_table(); push(table); // Si la pile est vide on l'initialise
                }

                if(current != NULL)
                        s = rechercher(current->symbole, (yyvsp[(1) - (2)].node)->name);

                if(s != NULL && s->field_list != NULL){
                        printf("%sLigne %d, la structure '%s' a déjà été déclarée.\n", ERROR, yylineno, (yyvsp[(1) - (2)].node)->name);
                        exit(1);
                } else {
                        table_t * t = *top(); // Le symbole n'existe pas, il faut le définir
                        s = ajouter(&(t->symbole), (yyvsp[(1) - (2)].node)->name);
                        s->type = STRUCT_;
                        s->ts = STRUCTURE_;
                        s->taille = sizeof(STRUCT_);
                        s->position = pos;
                        s->suivant = NULL;
                        s->marker = marker;
                        pos += s->taille;
                        if ((yyval.node)->symb != NULL)
                                s->field_list = (yyval.node)->symb->field_list;
                }
        }
    break;

  case 40:
#line 348 "structfe.y"
    {
                                        switch((yyvsp[(2) - (2)].node)->type){
                                                case INT_:      { 
                                                                        node_t * n = create_node("type_EXTERN_INT", NULL);
                                                                        n->type = EXTERN_INT_;
                                                                        n->ts_t = FONCTION_;
                                                                        (yyval.node) = n;
                                                                        break;
                                                                }
                                                case VOID_:     {
                                                                        node_t * n = create_node("type_EXTERN_VOID", NULL);
                                                                        n->type = EXTERN_VOID_;
                                                                        n->ts_t = FONCTION_;
                                                                        (yyval.node) = n;
                                                                        break;
                                                                }
                                                default:        {
                                                                        node_t * n = create_node("type_EXTERN_STRUCT", NULL);
                                                                        n->type = EXTERN_STRUCT_;
                                                                        n->ts_t = FONCTION_;
                                                                        (yyval.node) = n;
                                                                        break;
                                                                }
                                        }
                                }
    break;

  case 41:
#line 373 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 42:
#line 377 "structfe.y"
    { node_t * n = create_node("type_VOID", NULL); n->type = VOID_; (yyval.node) = n; }
    break;

  case 43:
#line 378 "structfe.y"
    { node_t * n = create_node("type_INT", NULL); n->type = INT_; (yyval.node) = n; }
    break;

  case 44:
#line 379 "structfe.y"
    { node_t * n = create_node("type_STRUCT", mergeNodes(1, (yyvsp[(1) - (1)].node))); n->type = STRUCT_; n->ts_t = STRUCTURE_ ; (yyval.node) = n; }
    break;

  case 45:
#line 383 "structfe.y"
    { 
                                                                        node_t * n = create_node(strdup((yyvsp[(2) - (5)].nom)), NULL);
                                                                        symbole_t * s = malloc(sizeof(symbole_t));
                                                                        s->field_list = field_list_stack;
                                                                        clean_field_list_stack();
                                                                        n->symb = s;
                                                                        (yyval.node) = n;
                                                                }
    break;

  case 46:
#line 391 "structfe.y"
    { printf("%sLigne %d, les structures anonymes ne sont pas autorisées.\n",ERROR, yylineno); exit(1); }
    break;

  case 47:
#line 392 "structfe.y"
    { (yyval.node) = create_node(strdup((yyvsp[(2) - (2)].nom)), NULL); }
    break;

  case 48:
#line 396 "structfe.y"
    { addField(&field_list_stack, (yyvsp[(1) - (1)].symb)); (yyval.symb) = NULL; }
    break;

  case 49:
#line 397 "structfe.y"
    { addField(&field_list_stack, (yyvsp[(2) - (2)].symb)); (yyval.symb) = NULL; }
    break;

  case 50:
#line 401 "structfe.y"
    {
                                                        char * nom = (yyvsp[(2) - (3)].node)->name; // Je sauvegarde les informations
                                                        symbole_t * s;
                                                        s = malloc(sizeof(symbole_t));
                                                        s->type = (yyvsp[(1) - (3)].node)->type;
                                                        if(nom[0] == '*'){
                                                                s->isPtr = true;
                                                                nom++; // on retire le premier caractere
                                                        } else {
                                                                s->isPtr = false;
                                                        }
                                                        s->nom = nom;
                                                        (yyval.symb) = s;
                                                }
    break;

  case 51:
#line 418 "structfe.y"
    {
                                                char p[strlen((yyvsp[(2) - (2)].node)->name)+2]; 
                                                sprintf(p, "*%s", (yyvsp[(2) - (2)].node)->name);
                                                (yyvsp[(2) - (2)].node)->name = strdup(p);
                                                (yyval.node) = (yyvsp[(2) - (2)].node);
                                        }
    break;

  case 52:
#line 424 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 53:
#line 428 "structfe.y"
    { node_t * n = create_node(strdup((yyvsp[(1) - (1)].nom)), NULL); n->ts_t = VARIABLE_; (yyval.node) = n; }
    break;

  case 54:
#line 429 "structfe.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 55:
#line 430 "structfe.y"
    { node_t * n = (yyvsp[(1) - (4)].node); n->ts_t = FONCTION_; (yyval.node) = n; }
    break;

  case 56:
#line 431 "structfe.y"
    { node_t * n = (yyvsp[(1) - (3)].node); n->ts_t = FONCTION_; (yyval.node) = n; }
    break;

  case 57:
#line 435 "structfe.y"
    { addParam(&param_list_stack, (yyvsp[(1) - (1)].symb)); }
    break;

  case 58:
#line 436 "structfe.y"
    { addParam(&param_list_stack, (yyvsp[(3) - (3)].symb)); }
    break;

  case 59:
#line 440 "structfe.y"
    {
                char * nom = strdup((yyvsp[(2) - (2)].node)->name); // Je sauvegarde les informations
                symbole_t * s;
                s = malloc(sizeof(symbole_t));
                s->type = (yyvsp[(1) - (2)].node)->type;
                if(nom[0] == '*'){
                        s->isPtr = true;
                        nom++; // on retire le premier caractere
                } else {
                        s->isPtr = false;
                }
                s->nom = nom;
                (yyval.symb) = s;
        }
    break;

  case 60:
#line 457 "structfe.y"
    {(yyval.node_list) = (yyvsp[(1) - (1)].node_list);}
    break;

  case 61:
#line 458 "structfe.y"
    {(yyval.node_list) = mergeNodes(1, (yyvsp[(1) - (1)].node));}
    break;

  case 62:
#line 459 "structfe.y"
    {(yyval.node_list) = mergeNodes(1, (yyvsp[(1) - (1)].node));}
    break;

  case 63:
#line 460 "structfe.y"
    {(yyval.node_list) = mergeNodes(1, (yyvsp[(1) - (1)].node));}
    break;

  case 64:
#line 461 "structfe.y"
    {(yyval.node_list) = mergeNodes(1, (yyvsp[(1) - (1)].node));}
    break;

  case 65:
#line 465 "structfe.y"
    {(yyval.node_list) = NULL;}
    break;

  case 66:
#line 466 "structfe.y"
    {(yyval.node_list) = (yyvsp[(2) - (3)].node_list);}
    break;

  case 67:
#line 467 "structfe.y"
    {(yyval.node_list) = NULL;}
    break;

  case 68:
#line 468 "structfe.y"
    {(yyval.node_list) = (yyvsp[(3) - (4)].node_list);}
    break;

  case 69:
#line 471 "structfe.y"
    { table_t *table = nouvelle_table(); push(table);}
    break;

  case 70:
#line 472 "structfe.y"
    {   /* NE PAS TOUCHER */

                marker = "prog";
                
                /*table_t *table = pop(); 
                detruire_table(&table);
                if((*top()) != NULL){ // autrement dit si la pile est vide    
                    //print_table();
                } else {
                    printf("[]\n");
                }*/

                /* ************* */
            }
    break;

  case 71:
#line 488 "structfe.y"
    { (yyval.node_list) = NULL; }
    break;

  case 72:
#line 489 "structfe.y"
    { (yyval.node_list) = NULL; }
    break;

  case 73:
#line 493 "structfe.y"
    {(yyval.node_list) = (yyvsp[(1) - (1)].node_list);}
    break;

  case 74:
#line 494 "structfe.y"
    {(yyval.node_list) = concatNodes((yyvsp[(1) - (2)].node_list), (yyvsp[(2) - (2)].node_list)); }
    break;

  case 75:
#line 498 "structfe.y"
    { (yyval.node) = NULL; }
    break;

  case 76:
#line 499 "structfe.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 77:
#line 503 "structfe.y"
    {(yyval.node) = create_node("IF", concatNodes(mergeNodes(1, (yyvsp[(3) - (5)].node)), (yyvsp[(5) - (5)].node_list)));}
    break;

  case 78:
#line 504 "structfe.y"
    {(yyval.node) = create_node("IF-ELSE", concatNodes(mergeNodes(1, (yyvsp[(3) - (7)].node)), concatNodes((yyvsp[(5) - (7)].node_list), (yyvsp[(7) - (7)].node_list))));}
    break;

  case 79:
#line 508 "structfe.y"
    {(yyval.node) = create_node("WHILE", concatNodes(mergeNodes(1, (yyvsp[(3) - (5)].node)), (yyvsp[(5) - (5)].node_list))); }
    break;

  case 80:
#line 509 "structfe.y"
    { (yyval.node) = create_node("FOR", concatNodes( mergeNodes(3, (yyvsp[(3) - (7)].node), (yyvsp[(4) - (7)].node), (yyvsp[(5) - (7)].node)), (yyvsp[(7) - (7)].node_list))); }
    break;

  case 81:
#line 513 "structfe.y"
    { (yyval.node) = create_node("RETURN", NULL);}
    break;

  case 82:
#line 514 "structfe.y"
    {(yyval.node) = create_node("RETURN", mergeNodes(1, (yyvsp[(2) - (3)].node))); }
    break;

  case 83:
#line 517 "structfe.y"
    {       //Obliger de séparer le start du program car on affiche chaque AST des fonctions, donc on ne veux pas un arret prématuré
                                printf("FIN ANALYSE!\n");
                                print_tree(mergeNodes(1,(yyval.node)), "");
                                
                                /* Il faudrait normalement vider la table */
                                // ...
                        }
    break;

  case 84:
#line 527 "structfe.y"
    {
                                        print_complete_table();
                                        nodes_list_t * arbre = NULL;
                                        if((yyvsp[(1) - (1)].node) != NULL){
                                                arbre = mergeNodes(1, (yyvsp[(1) - (1)].node));
                                                print_tree(arbre, "");
                                                // Il faut verifier chacune de ses branches
                                                nodes_list_t * current = arbre->first->children;
                                                int i = 0;
                                                while(current->next != NULL){ // je ne gere pas le return pour le moment
                                                        type_check(current);
                                                        current = current->next;
                                                        i++;
                                                }
                                                i++;
                                                
                                                if(strcmp(current->first->name, "RETURN") != 0 && arbre->first->symb->type != VOID_){
                                                                printf("%sIl n'y a pas de fonction de retour alors que la fonction n'est pas de type void.\n", ERROR);
                                                                exit(1);
                                                        } else if (strcmp(current->first->name, "RETURN") != 0 && arbre->first->symb->type == VOID_){
                                                                /* pas implémenté */
                                                        } else {
                                                                switch(arbre->first->symb->type){
                                                                        case INT_ :{
                                                                                if(strcmp(type_check(current), "int") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "int *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "int") != 0 && strcmp(type_check(current), "int *") != 0)){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }

                                                                        case VOID_ : {
                                                                                if(strcmp(type_check(current), "void") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "void *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "void") != 0 && strcmp(type_check(current), "void *") != 0)){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }

                                                                        default : { // STRUCT_
                                                                                if(strcmp(type_check(current), "struct") != 0){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }             
                                                                }
                                                        }
                                                
                                                printf("TYPECHECK ==> OK\n");
                                                printf("%s\n", generation(arbre->first)->code);
                                        }
                                        (yyval.node) = create_node("prog", mergeNodes(1, (yyvsp[(1) - (1)].node)));
                                }
    break;

  case 85:
#line 581 "structfe.y"
    {
                                                print_complete_table();
                                                nodes_list_t * arbre = NULL;
                                                if((yyvsp[(2) - (2)].node) != NULL){
                                                        arbre = mergeNodes(1, (yyvsp[(2) - (2)].node));
                                                        print_tree(arbre, "");
                                                        nodes_list_t * current = arbre->first->children;
                                                        int i = 0;
                                                        while(current->next != NULL){ // je ne gere pas le return pour le moment
                                                                type_check(current);
                                                                current = current->next;
                                                                i++;
                                                        }
                                                        i++;

                                                        if(strcmp(current->first->name, "RETURN") != 0 && arbre->first->symb->type != VOID_){
                                                                printf("%sIl n'y a pas de fonction de retour alors que la fonction n'est pas de type void.\n", ERROR);
                                                                exit(1);
                                                        } else if (strcmp(current->first->name, "RETURN") != 0 && arbre->first->symb->type == VOID_){
                                                                /* pas implémenté */
                                                        } else {
                                                                switch(arbre->first->symb->type){
                                                                        case INT_ :{
                                                                                if(strcmp(type_check(current), "int") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "int *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "int") != 0 && strcmp(type_check(current), "int *") != 0)){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }

                                                                        case VOID_ : {
                                                                                if(strcmp(type_check(current), "void") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "void *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "void") != 0 && strcmp(type_check(current), "void *") != 0)){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }

                                                                        default : { // STRUCT_
                                                                                if(strcmp(type_check(current), "struct") != 0){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }             
                                                                }
                                                        }
                                                        printf("TYPECHECK ==> OK\n");
                                                        printf("%s\n", generation(arbre->first)->code); 
                                                }
                                                (yyval.node) = create_node("prog", mergeNodes(1, (yyvsp[(2) - (2)].node)));
                                        }
    break;

  case 86:
#line 636 "structfe.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 87:
#line 637 "structfe.y"
    { (yyval.node) = NULL;}
    break;

  case 88:
#line 641 "structfe.y"
    { /* Nouvelle regle syntaxique */
                                                        // Il fallait pouvoir agir sur la declaration des fonctions indépendamment des paramètres de celle-ci
                                                        marker = strdup((yyvsp[(2) - (2)].node)->name);
                                                        symbole_t *s = NULL;
                                                        table_t * stack_head = pile;

                                                        if(stack_head == NULL){
                                                                table_t *table = nouvelle_table(); push(table); // Si la pile est vide on l'initialise
                                                        }

                                                        while(stack_head != NULL){
                                                                if(stack_head->symbole != NULL){
                                                                        s = rechercher(stack_head->symbole, (yyvsp[(2) - (2)].node)->name);
                                                                        if(s != NULL)
                                                                                break;
                                                                }
                                                                stack_head = stack_head->preced;
                                                        }
                                                        if(s != NULL && s->is_function_def == true && paramLength(s->param_list) == paramLength(param_list_stack)){
                                                                printf("%sLigne %d, la fonction '%s' est déjà déclarée.\n", ERROR, yylineno, (yyvsp[(2) - (2)].node)->name);
                                                                exit(1);
                                                        } else {
                                                                int n = 0;
                                                                symbole_t * sy = NULL;

                                                                while(sy == NULL){ // Tant qu'il y a des occurences de la fonction, on regarde ses surcharges
                                                                        sy = rechercher_global(stack_head, (yyvsp[(2) - (2)].node)->name, n, "");
                                                                        if(sy == NULL){
                                                                                if (s != NULL && s->is_function_def != true){
                                                                                        s->param_list = copyParamList(param_list_stack);
                                                                                        s->ts = FONCTION_;
                                                                                        s->is_function_def = true;
                                                                                        clean_param_list_stack();
                                                                                        (yyval.symb) = s;
                                                                                        break;
                                                                                } else {
                                                                                        table_t * t = *top();
                                                                                        sy = ajouter(&(t->symbole), (yyvsp[(2) - (2)].node)->name);
                                                                                        sy->type = (yyvsp[(1) - (2)].node)->type;
                                                                                        sy->ts = FONCTION_;
                                                                                        sy->taille = sizeof((yyvsp[(1) - (2)].node)->type);
                                                                                        sy->position = pos;
                                                                                        sy->suivant = NULL;
                                                                                        pos += sy->taille;
                                                                                        if(((yyvsp[(2) - (2)].node)->name)[0] == '*')
                                                                                                (yyvsp[(2) - (2)].node)->name++;
                                                                                        sy->is_function_def = true; 
                                                                                        sy->param_list = copyParamList(param_list_stack);
                                                                                        clean_param_list_stack();
                                                                                        (yyval.symb) = sy;
                                                                                        break; 
                                                                                }
                                                                        }
                                                                                
                                                                        if(sy != NULL && sy->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength(sy->param_list)) && sy->is_function_def){
                                                                                printf("%sLigne %d, La fonction '%s' est déjà définie.\n", ERROR, yylineno, (yyvsp[(2) - (2)].node)->name);
                                                                                exit(1);
                                                                        } else if (sy != NULL && sy->ts == FONCTION_ && sy->is_function_def ) {
                                                                                sy = NULL;
                                                                        } else {
                                                                                sy = NULL;
                                                                        }
                                                                        
                                                                        n++;
                                                                }
                                                        }
                                                }
    break;

  case 89:
#line 710 "structfe.y"
    {
                                                        clean_param_list_stack(); // On nettoie la pile des paramètres par précaution
                                                        node_t * n  = create_node(getSymbole((yyvsp[(1) - (2)].symb),-1)->nom,(yyvsp[(2) - (2)].node_list));
                                                        n->symb = (yyvsp[(1) - (2)].symb);
                                                        (yyval.node) = n;
                                                }
    break;


/* Line 1267 of yacc.c.  */
#line 2452 "y.tab.c"
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


#line 717 "structfe.y"

        int yyerror(char *s){ // fonction pour détecter une erreur
                fprintf(stderr, "%s\n", s);
                exit(1);
        }

        int pos = 0;
        table_t * pile = NULL;

        table_t ** top(){
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

        symbole_t * rechercher_global(table_t * t, char * nom, int n, char * mark){
                if(t != NULL){
                        table_t * table = t;
                        while(table != NULL){
                                symbole_t * s = NULL;
                                symbole_t * depthS = NULL;
                                depthS = table->symbole;
                                while(1){
                                        s = rechercher(depthS, nom);
                                        
                                        if(s == NULL)
                                                break;
                                        

                                        if(s != NULL && (s->marker != NULL && strcmp(s->marker, mark) == 0 || strcmp("", mark) == 0) && n == 0) // "" pour faire une recherche classique
                                                return s;
                                        
                                        if(s != NULL && (s->marker != NULL && strcmp(s->marker, mark) == 0 || strcmp("", mark) == 0))
                                                n--;

                                        depthS = depthS->suivant;
                                }
                                table = table->preced;
                        }
                }
                return NULL;
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

        void print_complete_table(){
                table_t * stack = malloc(sizeof (table_t));
                assert(stack != NULL);

                if(*top() != NULL){
                        stack->symbole = (*top())->symbole;
                        stack->preced = (*top())->preced;
                }
                printf("================================\n");
                while(stack != NULL){
                        printf("{\n");
                        while(stack->symbole != NULL){
                                if(stack->symbole->marker != NULL){
                                        printf("        NAME: %-22s | isPTR: %d | type: %2d | TAILLE: %3d | POSITION: %3d | TS NATURE: %2d | PARAM_LENGTH: %2d | FUN def?:%d | MARKER: %s\n", stack->symbole->nom, stack->symbole->isPtr, stack->symbole->type, stack->symbole->taille, stack->symbole->position, stack->symbole->ts, paramLength(stack->symbole->param_list), stack->symbole->is_function_def, stack->symbole->marker);
                                } else {
                                        printf("        NAME: %-22s | isPTR: %d | type: %2d | TAILLE: %3d | POSITION: %3d | TS NATURE: %2d | PARAM_LENGTH: %2d | FUN def?:%d | MARKER: NONE\n", stack->symbole->nom, stack->symbole->isPtr, stack->symbole->type, stack->symbole->taille, stack->symbole->position, stack->symbole->ts, paramLength(stack->symbole->param_list), stack->symbole->is_function_def);
                                }
                                stack->symbole = stack->symbole->suivant;
                        }
                        printf("}\n");

                        if(stack->preced != NULL){
                                stack->symbole = stack->preced->symbole;
                                stack->preced = stack->preced->preced;
                        } else {
                                break;
                        }
                }
                printf("\n================================\n");
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

                if(nbPara == 1){
                        n->next = NULL;
                        return n;
                }

                n->next = malloc(sizeof(nodes_list_t));

                nodes_list_t * temp = n->next;
                
                for(int j = 1; j < nbPara; j++){
                        node_t * current = va_arg(ap, node_t *);
                        temp->first = current;
                        if(j != nbPara -1) {
                                temp->next = malloc(sizeof(nodes_list_t));
                                temp = temp->next;
                        }
                }
                temp->next = NULL;
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
                nodes_list_t * current = n->first->children;
                char * newspace = "     ";
                while(current != NULL){ // Tant que le pere a des enfants
                    printf("%s     |___> ", space);
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

        void addParam(param_list_t ** stack, symbole_t * s){
                param_list_t * p = malloc(sizeof(param_list_t));
                p->symbole = s;
                param_list_t * st = *stack;

                if(*stack == NULL){
                        *stack = p;
                } else {
                        while(st->suivant != NULL){
                                st = st->suivant;
                        }
                        st->suivant = p;
                }
        }   

        param_list_t * copyParamList(param_list_t * stack){
                if(stack == NULL)
                        return NULL;
                
                param_list_t * p = malloc(sizeof(param_list_t));
                p->symbole = malloc(sizeof(symbole_t));
                p->symbole->type = stack->symbole->type;
                p->symbole->isPtr = stack->symbole->isPtr;
                p->symbole->nom = strdup(stack->symbole->nom);
                p->suivant = copyParamList(stack->suivant);
                return p;
        }

        symbole_t * rechercherStack(param_list_t * st, char * nom){
                param_list_t * p = st;
                while(p != NULL){
                        if(strcmp(nom, p->symbole->nom) == 0)
                                return p->symbole;
                        p = p->suivant;
                }
                return NULL;
        }

        void displayParam(param_list_t * p){
                printf("Liste courante des paramètres:\n");
                while(p != NULL){
                        printf("+ %s, est de type %d et isPtr vaut %d\n",p->symbole->nom, p->symbole->type ,p->symbole->isPtr);
                        p = p->suivant;
                }
        }

        void clean_param_list_stack(){
                param_list_t ** stack = &param_list_stack;
                while (*stack != NULL){
                        *stack = (*stack)->suivant;
                }
        }

        int paramLength(param_list_t * p){
                param_list_t * current;
                int count;
                current = p;
                count = 0;
                while(current != NULL){
                        count++;
                        current = current->suivant;
                }
                return count;
        }

        symbole_t * getSymbole(symbole_t * s, int n){
                symbole_t * current = s;
                if(n < 0){
                        while(current->suivant != NULL){
                                current = current->suivant;
                        }
                        return current;
                } else{
                        int count = 0;
                        while(count < n){
                        if(current == NULL){
                                printf("getSymbole : out of range\n");
                                exit(1);
                        }
                        current = current->suivant;
                        }
                }
                if(current == NULL){
                        printf("getSymbole : out of range\n");
                        exit(1);
                }
                return current;
        }

        symbole_t * getSymboleList(table_t * t, int n){
                table_t * current = t;
                if(n < 0){
                        while(current->preced != NULL){
                                current = current->preced;
                        }
                        return current->symbole;
                } else{
                        int count = 0;
                        while(count < n){
                                if(current == NULL){
                                        printf("getSymbole : out of range\n");
                                        exit(1);
                                }
                                current = current->preced;
                        }
                }
                if(current == NULL){
                        printf("getSymbole : out of range\n");
                        exit(1);
                }
                return current->symbole;
        }

        nodes_list_t * concatNodes(nodes_list_t * n1, nodes_list_t * n2){
                nodes_list_t * copy = n1;
                nodes_list_t * current = copy;
                while(current->next != NULL){
                        current = current->next;
                }
                current->next = n2;
                return copy;
        }

        void addField(field_list_t ** stack, symbole_t * s){
                field_list_t * p = malloc(sizeof(field_list_t));
                p->symbole = s;
                field_list_t * st = *stack;

                if(*stack == NULL){
                        *stack = p;
                } else {
                        while(st->suivant != NULL){
                                st = st->suivant;
                        }
                        st->suivant = p;
                }
        }

        field_list_t * copyFieldList(field_list_t * stack){
                if(stack == NULL)
                        return NULL;

                field_list_t * p = malloc(sizeof(field_list_t));
                p->symbole = malloc(sizeof(symbole_t));
                p->symbole->type = stack->symbole->type;
                p->symbole->isPtr = stack->symbole->isPtr;
                p->symbole->nom = strdup(stack->symbole->nom);
                p->suivant = copyFieldList(stack->suivant);
                return p;
        }

        symbole_t * rechercherFieldStack(field_list_t * st, char * nom){
                field_list_t * p = st;
                while(p != NULL){
                        if(strcmp(nom, p->symbole->nom) == 0)
                                return p->symbole;
                        p = p->suivant;
                }
                return NULL;
        }

        void displayField(field_list_t * p){
                printf("Liste courante des paramètres:\n");
                while(p != NULL){
                        printf("+ %s, est de type %d et isPtr vaut %d\n",p->symbole->nom, p->symbole->type ,p->symbole->isPtr);
                        p = p->suivant;
                }
        }

        void clean_field_list_stack(){
                field_list_t ** stack = &field_list_stack;
                while (*stack != NULL){
                        *stack = (*stack)->suivant;
                }
        }

        int fieldLength(field_list_t * p){
                field_list_t * current;
                int count;
                current = p;
                count = 0;
                while(current != NULL){
                        count++;
                        current = current->suivant;
                }
                return count;
        }

        int verifyParamIntegrity(param_list_t * pls){
                param_list_t * current = pls;
                table_t * stack_head = pile;
                while(current != NULL){
                        if(rechercher_global(stack_head, current->symbole->nom,0,marker) == NULL && rechercher_global(stack_head, current->symbole->nom,0,"prog") == NULL){ // Si un parametre n'existe pas alors il y  a un probleme
                                return 0;
                        }
                        current = current->suivant;
                }
                return 1;
        }

        char * type_check(nodes_list_t * a){
                if(strcmp(a->first->name, "=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if(strcmp(fg, fd) == 0)
                                return fg; 
                        printf("%sTYPECHECK: '=' attendait un type %s mais a reçu un type %s OU il s'agit d'un probleme de pointeurs.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "+") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0)){
                                return "int"; 
                        } else if (((strcmp(fg, "int *") == 0 && strcmp(fd, "int") == 0)) || ((strcmp(fg, "int") == 0 && strcmp(fd, "int *") == 0)) || ((strcmp(fg, "int *") == 0 && strcmp(fd, "int *") == 0))){
                                return "int *";
                        }
                        printf("%sTYPECHECK: '+' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "-") == 0){ // Il faut aussi verifier s'il s'agit d'une opération unaire
                        if(a->first->children->next != NULL){ // S'il ne s'agit pas de l'operation unaire
                                char * fg = type_check(a->first->children);
                                char * fd = type_check(a->first->children->next);

                                if((strcmp(fg, "int *") == 0 && strcmp(fd, "int *") == 0) || (strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                        return "int"; 
                                
                                printf("%sTYPECHECK: '-' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                                exit(1);
                        } else {
                                char * fils = type_check(a->first->children);
                                if(strcmp(fils, "int") == 0)
                                        return "int";
                                printf("%sTYPECHECK: '-' (UNAIRE) attendait un type int mais a reçu un type %s.\n", ERROR, fils);
                                exit(1);
                        }
                } else if (strcmp(a->first->name, "*") == 0){ // Il faut aussi vérifier s'il s'agit d'un pointeur
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                              
                        printf("%sTYPECHECK: '*' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "/") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                              
                        printf("%sTYPECHECK: '/' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, ">") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                        
                        printf("%sTYPECHECK: '>' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "<") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                
                        printf("%sTYPECHECK: '<' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, ">=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                             
                        printf("%sTYPECHECK: '>=' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "<=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                                
                        printf("%sTYPECHECK: '<=' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "==") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                         
                        printf("%sTYPECHECK: '==' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "!=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                               
                        printf("%sTYPECHECK: '!=' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "&&") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                                
                        printf("%sTYPECHECK: '&&' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "||") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                               
                        printf("%sTYPECHECK: '||' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "&") == 0){
                        char * fils = type_check(a->first->children);
                        if(strcmp(fils, "int") == 0){
                                return "int *"; 
                        } else if (a->first->children->first->symb->ts == FONCTION_){
                                switch(a->first->children->first->symb->type){
                                        case INT_ : return "int *"; break;
                                        case VOID_: return "void *"; break;
                                        default : return "struct"; break;
                                }
                        }        
                        printf("%sTYPECHECK: '&' (UNAIRE) attendait un type int ou une fonction mais a reçu un type %s et/ou n'est pas une fonction.\n", ERROR, fils);
                        exit(1);
                } else if (strcmp(a->first->name, "->") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if(strcmp(fg, "struct") == 0 && a->first->children->first->symb->isPtr == true)
                                return fd; 
                              
                        printf("%sTYPECHECK: '->' attendait un type struct mais a reçu un type %s (peut-etre pas un pointeur?) .\n", ERROR, fg);
                        exit(1);
                } else if (strcmp(a->first->name, ".") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if(strcmp(fg, "struct") == 0 && a->first->children->first->symb->isPtr == false)
                                return fd; 
                                
                        printf("%sTYPECHECK: '.' attendait un type struct mais a reçu un type %s (peut-etre un pointeur?) .\n", ERROR, fg);
                        exit(1);
                } else if (strcmp(a->first->name, "RETURN") == 0){
                        if(a->first->children != NULL){
                                char * fils = type_check(a->first->children);
                                return fils;
                        } else {
                                return "void";
                        }
                        
                } else { // Si on entre ici, soit on a pas implémenté un opérateur, soit il faut faire remonter un type
                        //JE RECHERCHE DANS LA TS L'ELEMENT COURANT
                        
                        table_t * stack_head = pile;
                        symbole_t * s = NULL;

                        if(a->first->isConst == true){ // c'est qu'il s'agit d'une constante
                                return "int";
                        }
                        
                        s = rechercher_global(stack_head, a->first->name, 0, "");

                        if (s != NULL) {
                                type_t res;
                                res = s->type;
                                switch(res){
                                        case INT_ :{
                                                if(s->isPtr)
                                                        return "int *";
                                                return "int";
                                                break;}
                                        case VOID_ :{
                                                if(s->isPtr)
                                                        return "void *";
                                                return "void";
                                                break;}
                                        default :
                                                return "struct";
                                }
                        }
                        
                        printf("%sTYPECHECK: %s n'est pas géré semble-t-il OU n'existe pas.\n", ERROR, a->first->name);
                        exit(1);
                }
        }

        int lengthChildren(node_t * a) {
                nodes_list_t * children;
                children = a->children;
                int acc = 0;
                while(children != NULL){
                        acc++;
                        children = children->next;
                }
                return acc;
        }

        char * concatener(int nbPara, ...){
                char * res = strdup("");
                if(nbPara == 0)
                        return NULL;
                        
                va_list ap;    
                va_start(ap, nbPara);
                                
                for(int j = 0; j < nbPara; j++){
                        char * current = va_arg(ap, char *);
                        strcat(res, " ");
                        strcat(res, current);
                }
                                
                va_end(ap);
                return res;
        }

        code_info * generation (node_t * a){
                // Init
                nodes_list_t * arbre = a->children; // Premier fils
                int length_children = lengthChildren(a); // Nb de ses enfants
                code_info * codes[length_children];
                int i = 0;

                // Je recupere dans un premier temps le code des enfants du noeud courant
                while(arbre != NULL && length_children > 0){
                        codes[i] = generation(arbre->first);
                        i++;
                        arbre = arbre->next;
                }

                // Je peux maintenant traiter le code du noeud en parametre
                if(strcmp(a->name, "=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        if(infos->val == NULL){
                                infos->code = strdup(concatener(4, codes[0]->code, "=", codes[1]->code, ";\n"));
                        } else {
                                char * tmp = codes[1]->code;
                                infos->code = concatener(4, tmp, codes[0]->code, "=", codes[1]->val);
                        }
                        return infos;
                } else if (strcmp(a->name, "+") == 0) {
                         // ^ il faudra introduire le nombre de var temp créées
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        if(infos->val == NULL){
                                infos->code = strdup(concatener(4, codes[0]->code, "+", codes[1]->code, ";\n"));
                        }else{
                                char * tmp = codes[1]->code;
                                infos->code = concatener(4, tmp, codes[0]->code, "+", codes[1]->val);
                        }
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "-") == 0){ // Il faut aussi verifier s'il s'agit d'une opération unaire
                       code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "-", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "*") == 0){ // Il faut aussi vérifier s'il s'agit d'un pointeur
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "*", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "/") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "/", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, ">") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, ">", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "<") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "<", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, ">=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, ">=", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                        
                } else if (strcmp(a->name, "<=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "<=", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "==") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "==", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "!=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "!=", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "&&") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "&&", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "||") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "||", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } /* else if (strcmp(a->name, "&") == 0){
                        
                } else if (strcmp(a->name, "->") == 0){
                        
                } else if (strcmp(a->name, ".") == 0){

                }*/ else if (strcmp(a->name, "RETURN") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        
                        if (infos->val == NULL){
                                infos->code = strdup(concatener(3, "return", codes[0]->code, ";\n"));
                        } else {
                                char * tmp = codes[1]->code;
                                infos->code = concatener(4, tmp, codes[0]->code, "return", codes[1]->val);
                        }
                        return infos;
                } else if (strcmp (a->name, "main") == 0){ 
                        int i = 0;
                        if(length_children == 0)
                                return codes[0];

                        while(i < length_children - 1){
                                if(length_children == 1)
                                        break;
                                strcat(codes[0]->code, codes[i+1]->code);
                                i++;
                        }
                        return codes[0];
                } else { // Soit le cas n'est pas implémenté, soit il s'agit d'une variable ou une constante
                        if(a->name != NULL){
                                  code_info * infos = malloc(sizeof(code_info));
                                  assert(infos != NULL);
                                  infos->code = a->name;
                                return infos;
                        }
                                
                        printf("ERREUR: il y a un pb d'implémentation ... \n");
                        exit(1);
                }
        }

        int main(){
                while(1){
                        yyparse();
                }
        }
