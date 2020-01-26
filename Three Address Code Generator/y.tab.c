/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct exprType{

	char *addr;
	char *code;
	
};
int n=1;int nl = 1;
char *var;char num_to_concatinate[10];char num_to_concatinate_l[10];char *ret;char *temp;
char *label;char *label2;char *check;char *begin;
char *b1;char *b2;char *s1;char *s2;
struct exprType *to_return_expr;
void yyerror(char* s);
int yylex(void);
char * newTemp(){
	char *newTemp = (char *)malloc(20);
	strcpy(newTemp,"t");
	num_to_concatinate[0]=0;
	snprintf(num_to_concatinate, 10,"%d",n);
	strcat(newTemp,num_to_concatinate);
	n++;
	return newTemp;
}
char * newLabel(){
	char *newLabel = (char *)malloc(20);
	strcpy(newLabel,"L");
	snprintf(num_to_concatinate_l, 10,"%d",nl);
	strcat(newLabel,num_to_concatinate_l);
	nl++;
	return newLabel;
}
void replace(char* s1,char* str, char* label)
{
	char* check = strstr (s1,str);
			while(check!=NULL){
			strncpy (check,label,strlen(label));strncpy (check+strlen(label),"    ",(4-strlen(label)));
			check = strstr (s1,str);}
}



# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    DIGIT = 258,
    FLOAT = 259,
    ID = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    TYPES = 264,
    REL_OPT = 265,
    OR = 266,
    AND = 267,
    CASE = 268,
    SWITCH = 269,
    NOT = 270,
    PE = 271,
    ME = 272,
    INCR = 273,
    DEFAULT = 274,
    DECR = 275,
    TRUE = 276,
    FALSE = 277,
    BREAK = 278
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define FLOAT 259
#define ID 260
#define IF 261
#define ELSE 262
#define WHILE 263
#define TYPES 264
#define REL_OPT 265
#define OR 266
#define AND 267
#define CASE 268
#define SWITCH 269
#define NOT 270
#define PE 271
#define ME 272
#define INCR 273
#define DEFAULT 274
#define DECR 275
#define TRUE 276
#define FALSE 277
#define BREAK 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


	int ival;
	float fval;
	char *sval;
	struct exprType *EXPRTYPE;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */



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
# elif ! defined YYSIZE_T
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    29,    35,     2,
      37,    38,    26,    24,     2,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    32,
       2,    31,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    36,    40,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    81,    93,    99,   104,   122,   136,   150,
     166,   177,   188,   196,   202,   207,   215,   220,   228,   235,
     245,   257,   273,   288,   306,   325,   344,   368,   390,   412,
     418,   436,   449,   461,   472,   477,   486,   495,   500,   530,
     555,   579,   605,   630,   664,   700,   723,   745,   757,   769,
     782,   788,   795
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "FLOAT", "ID", "IF", "ELSE",
  "WHILE", "TYPES", "REL_OPT", "OR", "AND", "CASE", "SWITCH", "NOT", "PE",
  "ME", "INCR", "DEFAULT", "DECR", "TRUE", "FALSE", "BREAK", "'+'", "'-'",
  "'*'", "'/'", "'^'", "'%'", "'\\n'", "'='", "';'", "'@'", "':'", "'&'",
  "'|'", "'('", "')'", "'{'", "'}'", "$accept", "startSym", "program",
  "construct", "caseblock", "block", "list", "stat", "dec", "bool", "expr",
  "text", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,    94,    37,
      10,    61,    59,    64,    58,    38,   124,    40,    41,   123,
     125
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -16

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,   -47,   -34,   -32,    12,   -15,    12,    12,   -47,   123,
      27,   123,   -47,   -47,    79,   -47,   -12,    86,   145,   145,
     -47,    30,   -47,   -47,    51,   107,   -47,   -47,     7,   -47,
      37,   -47,    37,    37,   -47,   -47,    37,   -47,   -47,     2,
     -47,   -47,    28,   145,   -10,   171,   -47,   -47,    32,    34,
     -47,   -47,   -47,    37,   199,   212,   225,   238,   145,   -47,
      56,   151,   145,   145,   133,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,   133,    -1,   184,   -47,   -47,
     -47,   -47,    84,   -47,   -47,    54,   -47,    69,   264,    97,
      97,    48,    48,   277,    48,    48,   277,   277,   -47,    17,
     -47,   133,    37,    55,    60,   -47,   251,   133,   -47,   133,
     -47,    17,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    50,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     2,     4,     5,     0,    16,     0,     0,     0,     0,
      29,     0,    23,    24,     0,     0,     1,     3,     0,    17,
       0,    20,     0,     0,    21,    22,     0,    51,    52,     0,
      35,    36,     0,     0,     0,     0,    47,    48,     0,     0,
      14,    13,    18,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    26,
      27,    25,     0,    34,    37,    31,    32,     7,    30,    42,
      43,    39,    40,    46,    41,    38,    45,    44,     6,     0,
      33,     0,     0,     0,     0,     8,     0,     0,     9,     0,
      12,    11,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,    96,    -3,     3,   -46,   101,     1,   -47,    15,
     -20,     0,    78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,   104,    13,    14,    15,    16,    44,
      45,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    62,    63,    18,    20,    19,    22,    23,    27,    17,
      54,    17,    55,    56,    17,    29,    57,     1,    87,    30,
      31,    27,    21,    61,    17,    17,    29,    26,    64,    98,
     102,    37,    38,    77,    48,    49,   103,    52,    99,    58,
      37,    38,     1,    62,    63,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   105,     1,     2,    60,     3,
       4,   110,    42,   111,    17,     5,    63,    62,    63,     6,
      75,     7,    76,    82,    53,    17,   101,    85,    86,   -15,
      28,    72,   106,     8,     1,   -15,   -15,   -15,     4,   107,
       9,    50,   -15,   -15,    83,    62,    63,     6,   -15,     7,
     108,    17,    32,    33,    34,    24,    35,    17,    28,    17,
      25,     8,     1,   -15,   112,   -15,     4,    36,   -15,   -15,
      59,   -15,   100,    68,    69,     6,    71,     7,     1,     2,
      72,     3,     4,     0,     0,     0,     0,     5,     1,     8,
       0,     6,     4,     7,     0,     0,   -15,    51,    37,    38,
       1,     6,     0,     7,     0,     8,     0,     0,     0,     0,
      39,    65,     9,     0,     0,     8,    40,    41,     0,     0,
      42,     0,     9,     0,     0,    66,    67,    68,    69,    70,
      71,    65,    43,     0,    72,     0,    73,    74,     0,    84,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,     0,     0,     0,    72,     0,    73,    74,    66,    67,
      68,    69,    70,    71,     0,     0,     0,    72,     0,    73,
      74,     0,    84,    66,    67,    68,    69,    70,    71,     0,
       0,    78,    72,     0,    73,    74,    66,    67,    68,    69,
      70,    71,     0,     0,    79,    72,     0,    73,    74,    66,
      67,    68,    69,    70,    71,     0,     0,    80,    72,     0,
      73,    74,    66,    67,    68,    69,    70,    71,     0,     0,
      81,    72,     0,    73,    74,    66,    67,    68,    69,    70,
      71,     0,     0,     0,    72,   109,    73,    74,    66,    67,
      68,    69,    70,    71,     0,     0,     0,    72,     0,    73,
      74,    66,    67,    68,    69,     0,    71,     0,     0,     0,
      72
};

static const yytype_int8 yycheck[] =
{
       0,    11,    12,    37,     4,    37,     6,     7,    11,     9,
      30,    11,    32,    33,    14,    14,    36,     5,    64,    31,
      32,    24,    37,    43,    24,    25,    25,     0,    38,    75,
      13,     3,     4,    53,    19,     5,    19,    30,    39,    37,
       3,     4,     5,    11,    12,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   101,     5,     6,    43,     8,
       9,   107,    25,   109,    64,    14,    12,    11,    12,    18,
      38,    20,    38,    58,    37,    75,     7,    62,    63,     0,
       1,    33,   102,    32,     5,     6,     7,     8,     9,    34,
      39,    40,    13,    14,    38,    11,    12,    18,    19,    20,
      40,   101,    16,    17,    18,     9,    20,   107,     1,   109,
       9,    32,     5,     6,   111,     8,     9,    31,    39,    40,
      42,    14,    38,    26,    27,    18,    29,    20,     5,     6,
      33,     8,     9,    -1,    -1,    -1,    -1,    14,     5,    32,
      -1,    18,     9,    20,    -1,    -1,    39,    40,     3,     4,
       5,    18,    -1,    20,    -1,    32,    -1,    -1,    -1,    -1,
      15,    10,    39,    -1,    -1,    32,    21,    22,    -1,    -1,
      25,    -1,    39,    -1,    -1,    24,    25,    26,    27,    28,
      29,    10,    37,    -1,    33,    -1,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    -1,    35,    36,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    33,    -1,    35,
      36,    -1,    38,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    35,    36,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    34,    35,    36,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    33,    -1,    35,
      36,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     8,     9,    14,    18,    20,    32,    39,
      42,    43,    44,    46,    47,    48,    49,    52,    37,    37,
      52,    37,    52,    52,    43,    47,     0,    44,     1,    48,
      31,    32,    16,    17,    18,    20,    31,     3,     4,    15,
      21,    22,    25,    37,    50,    51,    52,    53,    50,     5,
      40,    40,    30,    37,    51,    51,    51,    51,    37,    53,
      50,    51,    11,    12,    38,    10,    24,    25,    26,    27,
      28,    29,    33,    35,    36,    38,    38,    51,    32,    32,
      32,    32,    50,    38,    38,    50,    50,    46,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    46,    39,
      38,     7,    13,    19,    45,    46,    51,    34,    40,    34,
      46,    46,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    45,    46,    46,    46,    47,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     5,     7,     7,
       5,     4,     3,     3,     3,     1,     1,     2,     3,     1,
       2,     2,     2,     2,     2,     4,     4,     4,     4,     2,
       3,     3,     3,     4,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     1
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  (unsigned long int) yystacksize));

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

    {
			s1 = (yyvsp[0].sval);
			label = newLabel();
			replace(s1,"NEXT",label);
			ret = (char *)malloc(strlen(s1)+50);ret[0] = 0;
			strcat(ret,s1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : END OF THREE ADDRESS CODE !!!!!\n");
			printf("\n----------  FINAL THREE ADDRESS CODE ----------\n");
			puts(ret);
			(yyval.sval) = ret;
		}

    break;

  case 3:

    {
			s1 = (yyvsp[-1].sval);
			s2 = (yyvsp[0].sval);
			label = newLabel();
			replace(s1,"NEXT",label);
			ret = (char *)malloc(strlen((yyvsp[-1].sval))+strlen((yyvsp[0].sval))+4);
			ret[0] = 0;
			strcat(ret,(yyvsp[-1].sval));strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,(yyvsp[0].sval));
			(yyval.sval) = ret;
		}

    break;

  case 4:

    {
			(yyval.sval) = (yyvsp[0].sval);
		}

    break;

  case 5:

    {
			(yyval.sval) = (yyvsp[0].sval);
		}

    break;

  case 6:

    {
			
			b1 = (yyvsp[-2].sval);
			s1 = (yyvsp[0].sval);
			label = newLabel();
			replace(b1,"TRUE",label);
			replace(b1,"FAIL","NEXT");
			begin = newLabel();
			replace(s1,"NEXT",begin);
			ret = (char *)malloc(strlen(b1)+strlen(s1)+200);
			ret[0] = 0;
			strcat(ret,begin);strcat(ret," : ");strcat(ret,b1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,s1);
			strcat(ret,"\n");strcat(ret,"jump ");strcat(ret,begin);
			(yyval.sval) = ret;
	
		}

    break;

  case 7:

    {
			label = newLabel();
			b1 = (yyvsp[-2].sval);
			replace(b1,"TRUE",label);
			replace(b1,"FAIL","NEXT");
			check = strstr (b1,"FAIL");
			ret = (char *)malloc(strlen(b1)+strlen((yyvsp[0].sval))+4);
			ret[0] = 0;
			strcat(ret,b1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,(yyvsp[0].sval));printf("Printing ret \n");
			(yyval.sval) = ret;
		}

    break;

  case 8:

    {
			b1 = (yyvsp[-4].sval);
			label = newLabel();
			replace(b1,"TRUE",label);
			label2 = newLabel();
			replace(b1,"FAIL",label2);
			ret = (char *)malloc(strlen(b1)+strlen((yyvsp[-2].sval))+strlen((yyvsp[0].sval))+20);
			ret[0] = 0;
			strcat(ret,b1);strcat(ret,"\n");strcat(ret,label);strcat(ret," : ");strcat(ret,(yyvsp[-2].sval));strcat(ret,"\n");strcat(ret,"jump NEXT");strcat(ret,"\n");
			strcat(ret,label2);strcat(ret," : ");strcat(ret,(yyvsp[0].sval));
			(yyval.sval) = ret;
		}

    break;

  case 9:

    {
			char *var = (yyvsp[-4].sval);
			b1 = (yyvsp[-1].sval);
			replace(b1,"VARI",var);
			s1 = (yyvsp[-1].sval);
			label = "NEXT";	
			replace(s1,"LAST","NEXT");
			ret = (char*)malloc(strlen((yyvsp[-1].sval))+100);
			ret[0]=0;
			strcat(ret,(yyvsp[-1].sval));
				
			(yyval.sval) = ret;
		}

    break;

  case 10:

    {
				label=newLabel(); label2 = newLabel();
				ret = (char*)malloc(strlen((yyvsp[0].sval))+100); 
				memset(ret,0,sizeof ret); 
				strcat(ret,(yyvsp[-3].EXPRTYPE)->code);strcat(ret,"\nif(VARI=");
				strcat(ret,(yyvsp[-3].EXPRTYPE)->addr); strcat(ret,") "); strcat(ret,"jump ");strcat(ret,label); strcat(ret,"\n"); strcat(ret,"jump "); strcat(ret,label2);
				strcat(ret,"\n"); strcat(ret,label); strcat(ret," : "); strcat(ret,(yyvsp[-1].sval)); strcat(ret,"\n"); strcat(ret,"jump NEXT"); strcat(ret,"\n");strcat(ret,label2); strcat(ret," : "); strcat(ret,(yyvsp[0].sval)); 
				(yyval.sval)=ret;
			}

    break;

  case 11:

    {
				
				label=newLabel(); label2 = newLabel();
				ret = (char*)malloc(500*sizeof(char)); 
				memset(ret,0,sizeof ret); 
				strcat(ret,(yyvsp[-2].EXPRTYPE)->code);strcat(ret,"\nif(VARI=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr); strcat(ret,") "); strcat(ret,"jump ");strcat(ret,label); strcat(ret,"\n"); strcat(ret,"jump LAST"); 
				strcat(ret,"\n"); strcat(ret,label); strcat(ret," : "); strcat(ret,(yyvsp[0].sval)); 
				(yyval.sval)=ret;
			}

    break;

  case 12:

    {
				ret = (char*)malloc(500*sizeof(char));  memset(ret,0,sizeof(ret)); ret[0]=0;
				strcat(ret,(yyvsp[0].sval));
				(yyval.sval)=ret;
			}

    break;

  case 13:

    {
			(yyval.sval) = (yyvsp[-1].sval);
		}

    break;

  case 14:

    {
			(yyval.sval) = (yyvsp[-1].sval);
		}

    break;

  case 15:

    {
			(yyval.sval) = (yyvsp[0].sval);
		}

    break;

  case 16:

    {
			(yyval.sval) = (yyvsp[0].EXPRTYPE)->code;
		}

    break;

  case 17:

    {
			ret = (char *)malloc(strlen((yyvsp[-1].sval))+strlen((yyvsp[0].EXPRTYPE)->code)+4);
			ret[0] = 0;
			strcat(ret,(yyvsp[-1].sval));strcat(ret,"\n");strcat(ret,(yyvsp[0].EXPRTYPE)->code);
			(yyval.sval) = ret;
		}

    break;

  case 18:

    {
           yyerrok;
         }

    break;

  case 19:

    {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = (yyvsp[0].sval);
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		(yyval.EXPRTYPE) = to_return_expr;
	 }

    break;

  case 20:

    {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = (yyvsp[-1].sval);
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		(yyval.EXPRTYPE) = to_return_expr;
         }

    break;

  case 21:

    {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,to_return_expr->addr);
			strcat(ret,"=");strcat(ret,(yyvsp[-1].sval));strcat(ret,"\n"); strcat(ret,(yyvsp[-1].sval)); strcat(ret,"=");strcat(ret,(yyvsp[-1].sval));strcat(ret,"+1");
			temp = (char *)malloc(strlen(ret)+20);temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			(yyval.EXPRTYPE) = to_return_expr;

		}

    break;

  case 22:

    {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,(yyvsp[-1].sval));strcat(ret,"\n"); strcat(ret,(yyvsp[-1].sval)); strcat(ret,"=");strcat(ret,(yyvsp[-1].sval));strcat(ret,"-1");
			temp = (char *)malloc(strlen(ret)+20);temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			(yyval.EXPRTYPE) = to_return_expr;

		}

    break;

  case 23:

    {
			
	        to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,(yyvsp[0].sval));strcat(ret,"=");strcat(ret,(yyvsp[0].sval));strcat(ret,"+1");strcat(ret,"\n");strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,(yyvsp[0].sval));
			temp = (char *)malloc(strlen(ret)+20);
			temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			(yyval.EXPRTYPE) = to_return_expr;

		}

    break;

  case 24:

    {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,(yyvsp[0].sval));
			strcat(ret,"=");
			strcat(ret,(yyvsp[0].sval));strcat(ret,"-1");strcat(ret,"\n");
			strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,(yyvsp[0].sval));
			temp = (char *)malloc(strlen(ret)+20);temp[0] = 0;
			strcat(temp,ret);
			to_return_expr->code = temp;
			(yyval.EXPRTYPE) = to_return_expr;

		}

    break;

  case 25:

    {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		ret = (char *)malloc(20);
		ret[0] = 0;
		strcat(ret,(yyvsp[-3].sval));strcat(ret,"=");strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+60);
		temp[0] = 0;
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		(yyval.EXPRTYPE) = to_return_expr;
           }

    break;

  case 26:

    {
	        to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(200);
			ret[0] = 0;
			strcat(ret,(yyvsp[-3].sval));
			strcat(ret,"="); strcat(ret,(yyvsp[-3].sval));strcat(ret,"+"); strcat(ret,(yyvsp[-1].EXPRTYPE)->addr); strcat(ret,"\n");
			strcat(ret,to_return_expr->addr); strcat(ret,"=");strcat(ret,(yyvsp[-3].sval));
			temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+60);

			temp[0] = 0;
			
			if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
				strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
				strcat(temp,"\n");
				}
			strcat(temp,ret);
			to_return_expr->code = temp;
			(yyval.EXPRTYPE) = to_return_expr;

         }

    break;

  case 27:

    {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = newTemp();
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,(yyvsp[-3].sval));strcat(ret,"="); strcat(ret,(yyvsp[-3].sval));strcat(ret,"-"); strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);strcat(ret,"\n");strcat(ret,to_return_expr->addr); strcat(ret,"=");strcat(ret,(yyvsp[-3].sval));
			temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

			temp[0] = 0;
			
			if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
				strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
				strcat(temp,"\n");
				}
			strcat(temp,ret);
			to_return_expr->code = temp;
			(yyval.EXPRTYPE) = to_return_expr;

         }

    break;

  case 28:

    {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		ret = (char *)malloc(200);
		ret[0] = 0;
		strcat(ret,(yyvsp[-3].sval));strcat(ret,"=");strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-3].sval))+strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		(yyval.EXPRTYPE) = to_return_expr;
        }

    break;

  case 29:

    {	
			(yyval.sval) = (yyvsp[0].sval);
		}

    break;

  case 30:

    {
			temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+50);
			temp[0] = 0;
			if((yyvsp[-2].EXPRTYPE)->code[0]!=0){
				strcat(temp,(yyvsp[-2].EXPRTYPE)->code);strcat(temp,"\n");
				}
			if((yyvsp[0].EXPRTYPE)->code[0]!=0){
				strcat(temp,(yyvsp[0].EXPRTYPE)->code);
				strcat(temp,"\n");
				}
			ret = (char *)malloc(50);
			ret[0] = 0;
			strcat(ret,"if(");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,(yyvsp[-1].sval));strcat(ret,(yyvsp[0].EXPRTYPE)->addr);strcat(ret,") jump TRUE \n jump FAIL");
			strcat(temp,ret);
			(yyval.sval) = temp;
		}

    break;

  case 31:

    {
			b1 = (yyvsp[-2].sval);
			b2 = (yyvsp[0].sval);
			label = newLabel();
			replace(b1,"FAIL",label);
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;
			strcat(temp,b1);strcat(temp,"\n");strcat(temp,label);strcat(temp," : ");strcat(temp,b2);

			(yyval.sval) = temp;
		}

    break;

  case 32:

    {
			b1 = (yyvsp[-2].sval);
			b2 = (yyvsp[0].sval);
			label = newLabel();
			replace(b1,"TRUE",label);
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;
			strcat(temp,b1);strcat(temp,"\n");strcat(temp,label);strcat(temp," : ");strcat(temp,b2);
			(yyval.sval) = temp;
		}

    break;

  case 33:

    {	b1 = (yyvsp[-1].sval);
			label = "TEFS";
			replace(b1,"TRUE","TEFS");
			label = "TRUE";
			replace(b1,"FAIL",label);
			label = "FAIL";
			replace(b1,"TEFS","FAIL");
			(yyval.sval) = b1;
		}

    break;

  case 34:

    {
			(yyval.sval) = (yyvsp[-1].sval);
		}

    break;

  case 35:

    {
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\njump TRUE");
			
			(yyval.sval) = ret;
		}

    break;

  case 36:

    {
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\njump FAIL");
			(yyval.sval) = ret;
		}

    break;

  case 37:

    {
           (yyval.EXPRTYPE) = (yyvsp[-1].EXPRTYPE);
         }

    break;

  case 38:

    {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"@");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+60);
		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
	
         }

    break;

  case 39:

    {
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"*");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+60);
		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		(yyval.EXPRTYPE) = to_return_expr;
        }

    break;

  case 40:

    {
         to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"/");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+60);
		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		 	(yyval.EXPRTYPE) = to_return_expr;
	   }

    break;

  case 41:

    {
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"%");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);
		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		(yyval.EXPRTYPE) = to_return_expr;
         }

    break;

  case 42:

    {
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"+");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+60);temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		(yyval.EXPRTYPE) = to_return_expr;
         }

    break;

  case 43:

    {
	   
        to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(200);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(200);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"-");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+60);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		
		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		
         }

    break;

  case 44:

    {
         	printf("BITWISE OR : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"|");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
         }

    break;

  case 45:

    {
         to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;
		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"&");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);
		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		(yyval.EXPRTYPE) = to_return_expr;
         }

    break;

  case 46:

    {
         to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;
		strcat(ret,to_return_expr->addr);strcat(ret,"=");strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);strcat(ret,"^");strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);
		temp[0] = 0;
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);strcat(temp,"\n");
			}
		strcat(temp,ret);
		to_return_expr->code = temp;
		(yyval.EXPRTYPE) = to_return_expr;
         }

    break;

  case 47:

    {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = (yyvsp[0].sval);

		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;

		(yyval.EXPRTYPE) = to_return_expr;}

    break;

  case 48:

    {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			to_return_expr->addr = (yyvsp[0].sval);
			
			to_return_expr->code = (char *)malloc(2);
			to_return_expr->code[0] = 0;
			
			(yyval.EXPRTYPE) = to_return_expr;
		}

    break;

  case 49:

    {
			to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
			to_return_expr->addr = (char *)malloc(20);
			label = newTemp();
			to_return_expr->addr = label;
			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,label);strcat(ret,"=-");strcat(ret,(yyvsp[0].sval));
			to_return_expr->code=ret;
			(yyval.EXPRTYPE) = to_return_expr;
		}

    break;

  case 50:

    {
			(yyval.sval) = (yyvsp[0].sval);
         }

    break;

  case 51:

    {
			var = (char *)malloc(20);
	        snprintf(var, 10,"%d",(yyvsp[0].ival));
			(yyval.sval) = var;
         }

    break;

  case 52:

    {
		
			var = (char *)malloc(20);
	        snprintf(var, 10,"%f",(yyvsp[0].fval));
			(yyval.sval) = var;
           
         }

    break;



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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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




extern int yyparse();
extern FILE *yyin;

int main() {
	// open a file handle to a particular file:
	FILE *myfile = fopen("input.txt", "r");
	// make sure it is valid:
	if (!myfile) {
		printf("I can't open a.snazzle.file!");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}
void yyerror(char *s) {
	printf("Parsing error.  Message: %s ",s);
	exit(-1);
}
