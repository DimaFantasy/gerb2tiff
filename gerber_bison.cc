

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 4 "src/gerber_bison.yy"

#include "gerber.h"

/* Line 189 of yacc.c  */
#line 79 "src/gerber_bison.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
#define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
#undef YYERROR_VERBOSE
#define YYERROR_VERBOSE 1
#else
#define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
#define YYTOKEN_TABLE 1
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
/* Put the tokens into the symbol table, so that GDB and other debuggers
   know about them.  */
enum yytokentype
{
  PARAMETER_ADD = 258,
  PARAMETER_AM = 259,
  PARAMETER = 260,
  NUMBER = 261,
  VARIABLE = 262,
  CODE = 263,
  SYMBOL_X = 264,
  MACRONAME = 265,
  UNARY = 266
};
#endif
/* Tokens.  */
#define PARAMETER_ADD 258
#define PARAMETER_AM 259
#define PARAMETER 260
#define NUMBER 261
#define VARIABLE 262
#define CODE 263
#define SYMBOL_X 264
#define MACRONAME 265
#define UNARY 266

#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 11 "src/gerber_bison.yy"

  char *YS_string;
  double YS_float;
  int YS_int;
  NodeT *YS_NodeT;

/* Line 214 of yacc.c  */
#line 146 "src/gerber_bison.cc"
} YYSTYPE;
#define YYSTYPE_IS_TRIVIAL 1
#define yystype YYSTYPE /* obsolescent; will be withdrawn */
#define YYSTYPE_IS_DECLARED 1
#endif

/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 158 "src/gerber_bison.cc"

#ifdef short
#undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
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
#ifdef __SIZE_TYPE__
#define YYSIZE_T __SIZE_TYPE__
#elif defined size_t
#define YYSIZE_T size_t
#elif !defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
#include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#define YYSIZE_T size_t
#else
#define YYSIZE_T unsigned int
#endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) - 1)

#ifndef YY_
#if defined YYENABLE_NLS && YYENABLE_NLS
#if ENABLE_NLS
#include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#define YY_(msgid) dgettext("bison-runtime", msgid)
#endif
#endif
#ifndef YY_
#define YY_(msgid) msgid
#endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
#define YYUSE(e) ((void)(e))
#else
#define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
#define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static int
YYID(int yyi)
#else
static int
YYID(yyi)
int yyi;
#endif
{
  return yyi;
}
#endif

#if !defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

#ifdef YYSTACK_USE_ALLOCA
#if YYSTACK_USE_ALLOCA
#ifdef __GNUC__
#define YYSTACK_ALLOC __builtin_alloca
#elif defined __BUILTIN_VA_ARG_INCR
#include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#elif defined _AIX
#define YYSTACK_ALLOC __alloca
#elif defined _MSC_VER
#include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#define alloca _alloca
#else
#define YYSTACK_ALLOC alloca
#if !defined _ALLOCA_H && !defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef _STDLIB_H
#define _STDLIB_H 1
#endif
#endif
#endif
#endif
#endif

#ifdef YYSTACK_ALLOC
/* Pacify GCC's `empty if-body' warning.  */
#define YYSTACK_FREE(Ptr) \
  do                      \
  { /* empty */           \
    ;                     \
  } while (YYID(0))
#ifndef YYSTACK_ALLOC_MAXIMUM
/* The OS might guarantee only one guard page at the bottom of the stack,
   and a page size can be as small as 4096 bytes.  So we cannot safely
   invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
   to allow for a few compiler-allocated temporary stack slots.  */
#define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#endif
#else
#define YYSTACK_ALLOC YYMALLOC
#define YYSTACK_FREE YYFREE
#ifndef YYSTACK_ALLOC_MAXIMUM
#define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#endif
#if (defined __cplusplus && !defined _STDLIB_H && !((defined YYMALLOC || defined malloc) && (defined YYFREE || defined free)))
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef _STDLIB_H
#define _STDLIB_H 1
#endif
#endif
#ifndef YYMALLOC
#define YYMALLOC malloc
#if !defined malloc && !defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#ifndef YYFREE
#define YYFREE free
#if !defined free && !defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
void free(void *); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

#if (!defined yyoverflow && (!defined __cplusplus || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
#define YYSTACK_GAP_MAXIMUM (sizeof(union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
#define YYSTACK_BYTES(N) \
  ((N) * (sizeof(yytype_int16) + sizeof(YYSTYPE)) + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
#ifndef YYCOPY
#if defined __GNUC__ && 1 < __GNUC__
#define YYCOPY(To, From, Count) \
  __builtin_memcpy(To, From, (Count) * sizeof(*(From)))
#else
#define YYCOPY(To, From, Count)         \
  do                                    \
  {                                     \
    YYSIZE_T yyi;                       \
    for (yyi = 0; yyi < (Count); yyi++) \
      (To)[yyi] = (From)[yyi];          \
  } while (YYID(0))
#endif
#endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
#define YYSTACK_RELOCATE(Stack_alloc, Stack)                         \
  do                                                                 \
  {                                                                  \
    YYSIZE_T yynewbytes;                                             \
    YYCOPY(&yyptr->Stack_alloc, Stack, yysize);                      \
    Stack = &yyptr->Stack_alloc;                                     \
    yynewbytes = yystacksize * sizeof(*Stack) + YYSTACK_GAP_MAXIMUM; \
    yyptr += yynewbytes / sizeof(*yyptr);                            \
  } while (YYID(0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL 19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 76

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 14
/* YYNRULES -- Number of rules.  */
#define YYNRULES 41
/* YYNRULES -- Number of states.  */
#define YYNSTATES 70

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK 2
#define YYMAXUTOK 266

#define YYTRANSLATE(YYX) \
  ((unsigned int)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
    {
        0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 16, 2, 2,
        19, 20, 17, 11, 18, 12, 2, 14, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 21, 2,
        2, 22, 2, 2, 2, 2, 2, 23, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 13, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 1, 2, 3, 4,
        5, 6, 7, 8, 9, 10, 15};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
    {
        0, 0, 3, 5, 8, 12, 19, 22, 24, 26,
        29, 33, 35, 40, 43, 45, 49, 52, 55, 58,
        60, 63, 67, 71, 73, 77, 79, 81, 85, 89,
        93, 97, 100, 103, 107, 109, 112, 115, 118, 121,
        123, 125};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
    {
        25, 0, -1, 26, -1, 25, 26, -1, 16, 27,
        16, -1, 16, 4, 10, 31, 37, 16, -1, 35,
        17, -1, 17, -1, 16, -1, 28, 37, -1, 27,
        28, 37, -1, 5, -1, 3, 10, 18, 29, -1,
        3, 10, -1, 30, -1, 29, 13, 30, -1, 29,
        13, -1, 12, 6, -1, 11, 6, -1, 6, -1,
        37, 32, -1, 31, 37, 32, -1, 6, 18, 33,
        -1, 34, -1, 33, 18, 34, -1, 7, -1, 6,
        -1, 34, 11, 34, -1, 34, 12, 34, -1, 34,
        13, 34, -1, 34, 14, 34, -1, 12, 34, -1,
        11, 34, -1, 19, 34, 20, -1, 36, -1, 35,
        36, -1, 21, 6, -1, 22, 6, -1, 23, 6,
        -1, 8, -1, 17, -1, 37, 17, -1};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
    {
        0, 43, 43, 44, 46, 47, 48, 49, 50, 55,
        56, 58, 59, 60, 62, 63, 64, 66, 67, 68,
        70, 71, 73, 83, 84, 86, 87, 88, 89, 90,
        91, 92, 93, 94, 96, 97, 99, 100, 101, 102,
        104, 105};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
    {
        "$end", "error", "$undefined", "PARAMETER_ADD", "PARAMETER_AM",
        "PARAMETER", "NUMBER", "VARIABLE", "CODE", "SYMBOL_X", "MACRONAME",
        "'+'", "'-'", "'X'", "'/'", "UNARY", "'%'", "'*'", "','", "'('", "')'",
        "'D'", "'G'", "'M'", "$accept", "gerber", "data_block",
        "paramRS274_list", "paramRS274", "ad_modifier_list", "ad_number",
        "am_primitive_list", "am_primitve", "expr_list", "expr", "command_list",
        "command", "asterisk", 0};
#endif

#ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
    {
        0, 256, 257, 258, 259, 260, 261, 262, 263, 264,
        265, 43, 45, 88, 47, 266, 37, 42, 44, 40,
        41, 68, 71, 77};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
    {
        0, 24, 25, 25, 26, 26, 26, 26, 26, 27,
        27, 28, 28, 28, 29, 29, 29, 30, 30, 30,
        31, 31, 32, 33, 33, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 35, 35, 36, 36, 36, 36,
        37, 37};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
    {
        0, 2, 1, 2, 3, 6, 2, 1, 1, 2,
        3, 1, 4, 2, 1, 3, 2, 2, 2, 1,
        2, 3, 3, 1, 3, 1, 1, 3, 3, 3,
        3, 2, 2, 3, 1, 2, 2, 2, 2, 1,
        1, 2};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
    {
        0, 39, 8, 7, 0, 0, 0, 0, 2, 0,
        34, 0, 0, 11, 0, 0, 36, 37, 38, 1,
        3, 6, 35, 13, 0, 4, 0, 40, 9, 0,
        0, 0, 10, 41, 19, 0, 0, 12, 14, 0,
        0, 20, 18, 17, 16, 5, 21, 0, 15, 26,
        25, 0, 0, 0, 22, 23, 32, 31, 0, 0,
        0, 0, 0, 0, 33, 24, 27, 28, 29, 30};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
    {
        -1, 7, 8, 14, 15, 37, 38, 30, 41, 54,
        55, 9, 10, 28};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -15
static const yytype_int8 yypact[] =
    {
        -3, -15, 40, -15, -4, 28, 31, 0, -15, 7,
        -15, 37, 48, -15, 30, -14, -15, -15, -15, -15,
        -15, -15, -15, 43, -14, -15, -14, -15, 21, -2,
        -14, 19, 21, -15, -15, 54, 62, 56, -15, -5,
        52, -15, -15, -15, -2, -15, -15, 20, -15, -15,
        -15, 20, 20, 20, 55, 53, -15, -15, 42, 20,
        20, 20, 20, 20, -15, 53, -7, -7, -15, -15};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
    {
        -15, -15, 64, -15, 58, -15, 32, -15, 35, -15,
        -11, -15, 66, 33};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
    {
        19, 40, 16, 27, 34, 1, 62, 63, 1, 35,
        36, 45, 33, 2, 3, 1, 2, 3, 4, 5,
        6, 4, 5, 6, 21, 40, 49, 50, 4, 5,
        6, 51, 52, 11, 17, 13, 33, 18, 33, 53,
        56, 57, 58, 11, 12, 13, 25, 23, 65, 66,
        67, 68, 69, 60, 61, 62, 63, 31, 24, 32,
        42, 29, 64, 39, 60, 61, 62, 63, 43, 44,
        47, 20, 26, 59, 46, 22, 48};

static const yytype_uint8 yycheck[] =
    {
        0, 6, 6, 17, 6, 8, 13, 14, 8, 11,
        12, 16, 17, 16, 17, 8, 16, 17, 21, 22,
        23, 21, 22, 23, 17, 6, 6, 7, 21, 22,
        23, 11, 12, 3, 6, 5, 17, 6, 17, 19,
        51, 52, 53, 3, 4, 5, 16, 10, 59, 60,
        61, 62, 63, 11, 12, 13, 14, 24, 10, 26,
        6, 18, 20, 30, 11, 12, 13, 14, 6, 13,
        18, 7, 14, 18, 39, 9, 44};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
    {
        0, 8, 16, 17, 21, 22, 23, 25, 26, 35,
        36, 3, 4, 5, 27, 28, 6, 6, 6, 0,
        26, 17, 36, 10, 10, 16, 28, 17, 37, 18,
        31, 37, 37, 17, 6, 11, 12, 29, 30, 37,
        6, 32, 6, 6, 13, 16, 32, 18, 30, 6,
        7, 11, 12, 19, 33, 34, 34, 34, 34, 18,
        11, 12, 13, 14, 20, 34, 34, 34, 34, 34};

#define yyerrok (yyerrstatus = 0)
#define yyclearin (yychar = YYEMPTY)
#define YYEMPTY (-2)
#define YYEOF 0

#define YYACCEPT goto yyacceptlab
#define YYABORT goto yyabortlab
#define YYERROR goto yyerrorlab

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL goto yyerrlab
#if defined YYFAIL
/* This is here to suppress warnings from the GCC cpp's
   -Wunused-macros.  Normally we don't worry about that warning, but
   some users do, and we want to make it easy for users to remove
   YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING() (!!yyerrstatus)

#define YYBACKUP(Token, Value)                         \
  do                                                   \
    if (yychar == YYEMPTY && yylen == 1)               \
    {                                                  \
      yychar = (Token);                                \
      yylval = (Value);                                \
      yytoken = YYTRANSLATE(yychar);                   \
      YYPOPSTACK(1);                                   \
      goto yybackup;                                   \
    }                                                  \
    else                                               \
    {                                                  \
      yyerror(g, YY_("syntax error: cannot back up")); \
      YYERROR;                                         \
    }                                                  \
  while (YYID(0))

#define YYTERROR 1
#define YYERRCODE 256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(Current, Rhs, N)                       \
  do                                                          \
    if (YYID(N))                                              \
    {                                                         \
      (Current).first_line = YYRHSLOC(Rhs, 1).first_line;     \
      (Current).first_column = YYRHSLOC(Rhs, 1).first_column; \
      (Current).last_line = YYRHSLOC(Rhs, N).last_line;       \
      (Current).last_column = YYRHSLOC(Rhs, N).last_column;   \
    }                                                         \
    else                                                      \
    {                                                         \
      (Current).first_line = (Current).last_line =            \
          YYRHSLOC(Rhs, 0).last_line;                         \
      (Current).first_column = (Current).last_column =        \
          YYRHSLOC(Rhs, 0).last_column;                       \
    }                                                         \
  while (YYID(0))
#endif

/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#define YY_LOCATION_PRINT(File, Loc)            \
  fprintf(File, "%d.%d-%d.%d",                  \
          (Loc).first_line, (Loc).first_column, \
          (Loc).last_line, (Loc).last_column)
#else
#define YY_LOCATION_PRINT(File, Loc) ((void)0)
#endif
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
#define YYLEX yylex(YYLEX_PARAM)
#else
#define YYLEX yylex(g)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

#ifndef YYFPRINTF
#include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#define YYFPRINTF fprintf
#endif

#define YYDPRINTF(Args) \
  do                    \
  {                     \
    if (yydebug)        \
      YYFPRINTF Args;   \
  } while (YYID(0))

#define YY_SYMBOL_PRINT(Title, Type, Value, Location) \
  do                                                  \
  {                                                   \
    if (yydebug)                                      \
    {                                                 \
      YYFPRINTF(stderr, "%s ", Title);                \
      yy_symbol_print(stderr,                         \
                      Type, Value, g);                \
      YYFPRINTF(stderr, "\n");                        \
    }                                                 \
  } while (YYID(0))

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print(FILE *yyoutput, int yytype, YYSTYPE const *const yyvaluep, Gerber *g)
#else
static void
    yy_symbol_value_print(yyoutput, yytype, yyvaluep, g)
        FILE *yyoutput;
int yytype;
YYSTYPE const *const yyvaluep;
Gerber *g;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE(g);
#ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
#else
  YYUSE(yyoutput);
#endif
  switch (yytype)
  {
  default:
    break;
  }
}

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print(FILE *yyoutput, int yytype, YYSTYPE const *const yyvaluep, Gerber *g)
#else
static void
    yy_symbol_print(yyoutput, yytype, yyvaluep, g)
        FILE *yyoutput;
int yytype;
YYSTYPE const *const yyvaluep;
Gerber *g;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print(yyoutput, yytype, yyvaluep, g);
  YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print(yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
    yy_stack_print(yybottom, yytop)
        yytype_int16 *yybottom;
yytype_int16 *yytop;
#endif
{
  YYFPRINTF(stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
  {
    int yybot = *yybottom;
    YYFPRINTF(stderr, " %d", yybot);
  }
  YYFPRINTF(stderr, "\n");
}

#define YY_STACK_PRINT(Bottom, Top)    \
  do                                   \
  {                                    \
    if (yydebug)                       \
      yy_stack_print((Bottom), (Top)); \
  } while (YYID(0))

/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print(YYSTYPE *yyvsp, int yyrule, Gerber *g)
#else
static void
    yy_reduce_print(yyvsp, yyrule, g)
        YYSTYPE *yyvsp;
int yyrule;
Gerber *g;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n",
            yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
  {
    YYFPRINTF(stderr, "   $%d = ", yyi + 1);
    yy_symbol_print(stderr, yyrhs[yyprhs[yyrule] + yyi],
                    &(yyvsp[(yyi + 1) - (yynrhs)]), g);
    YYFPRINTF(stderr, "\n");
  }
}

#define YY_REDUCE_PRINT(Rule)          \
  do                                   \
  {                                    \
    if (yydebug)                       \
      yy_reduce_print(yyvsp, Rule, g); \
  } while (YYID(0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
#define YYDPRINTF(Args)
#define YY_SYMBOL_PRINT(Title, Type, Value, Location)
#define YY_STACK_PRINT(Bottom, Top)
#define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if YYERROR_VERBOSE

#ifndef yystrlen
#if defined __GLIBC__ && defined _STRING_H
#define yystrlen strlen
#else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen(const char *yystr)
#else
static YYSIZE_T
    yystrlen(yystr)
        const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#endif
#endif

#ifndef yystpcpy
#if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#define yystpcpy stpcpy
#else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy(char *yydest, const char *yysrc)
#else
static char *
yystpcpy(yydest, yysrc)
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
#endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr(char *yyres, const char *yystr)
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
  do_not_strip_quotes:;
  }

  if (!yyres)
    return yystrlen(yystr);

  return yystpcpy(yyres, yystr) - yyres;
}
#endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error(char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (!(YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
  {
    int yytype = YYTRANSLATE(yychar);
    YYSIZE_T yysize0 = yytnamerr(0, yytname[yytype]);
    YYSIZE_T yysize = yysize0;
    YYSIZE_T yysize1;
    int yysize_overflow = 0;
    enum
    {
      YYERROR_VERBOSE_ARGS_MAXIMUM = 5
    };
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
    int yyx;

#if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
    char *yyfmt;
    char const *yyf;
    static char const yyunexpected[] = "syntax error, unexpected %s";
    static char const yyexpecting[] = ", expecting %s";
    static char const yyor[] = " or %s";
    char yyformat[sizeof yyunexpected + sizeof yyexpecting - 1 + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2) * (sizeof yyor - 1))];
    char const *yyprefix = yyexpecting;

    /* Start YYX at -YYN if negative to avoid negative indexes in
 YYCHECK.  */
    int yyxbegin = yyn < 0 ? -yyn : 0;

    /* Stay within bounds of both yycheck and yytname.  */
    int yychecklim = YYLAST - yyn + 1;
    int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
    int yycount = 1;

    yyarg[0] = yytname[yytype];
    yyfmt = yystpcpy(yyformat, yyunexpected);

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
        yysize1 = yysize + yytnamerr(0, yytname[yyx]);
        yysize_overflow |= (yysize1 < yysize);
        yysize = yysize1;
        yyfmt = yystpcpy(yyfmt, yyprefix);
        yyprefix = yyor;
      }

    yyf = YY_(yyformat);
    yysize1 = yysize + yystrlen(yyf);
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
          yyp += yytnamerr(yyp, yyarg[yyi++]);
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
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep, Gerber *g)
#else
static void
    yydestruct(yymsg, yytype, yyvaluep, g)
        const char *yymsg;
int yytype;
YYSTYPE *yyvaluep;
Gerber *g;
#endif
{
  YYUSE(yyvaluep);
  YYUSE(g);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
  {

  default:
    break;
  }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse(void *YYPARSE_PARAM);
#else
int yyparse();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse(Gerber *g);
#else
int yyparse();
#endif
#endif /* ! YYPARSE_PARAM */

/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
int yyparse(void *YYPARSE_PARAM)
#else
int
    yyparse(YYPARSE_PARAM) void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
int yyparse(Gerber *g)
#else
int yyparse(g)
Gerber *g;
#endif
#endif
{

  int yystate;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;

  /* The stacks and their tools:
     `yyss': related to states.
     `yyvs': related to semantic values.

     Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N) (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
      yyoverflow(YY_("memory exhausted"),
                 &yyss1, yysize * sizeof(*yyssp),
                 &yyvs1, yysize * sizeof(*yyvsp),
                 &yystacksize);

      yyss = yyss1;
      yyvs = yyvs1;
    }
#else /* no yyoverflow */
#ifndef YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    /* Extend the stack our own way.  */
    if (YYMAXDEPTH <= yystacksize)
      goto yyexhaustedlab;
    yystacksize *= 2;
    if (YYMAXDEPTH < yystacksize)
      yystacksize = YYMAXDEPTH;

    {
      yytype_int16 *yyss1 = yyss;
      union yyalloc *yyptr =
          (union yyalloc *)YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
      if (!yyptr)
        goto yyexhaustedlab;
      YYSTACK_RELOCATE(yyss_alloc, yyss);
      YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#undef YYSTACK_RELOCATE
      if (yyss1 != yyssa)
        YYSTACK_FREE(yyss1);
    }
#endif
#endif /* no yyoverflow */

    yyssp = yyss + yysize - 1;
    yyvsp = yyvs + yysize - 1;

    YYDPRINTF((stderr, "Stack size increased to %lu\n",
               (unsigned long int)yystacksize));

    if (yyss + yystacksize - 1 <= yyssp)
      YYABORT;
  }

  YYDPRINTF((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
  {
    YYDPRINTF((stderr, "Reading a token: "));
    yychar = YYLEX;
  }

  if (yychar <= YYEOF)
  {
    yychar = yytoken = YYEOF;
    YYDPRINTF((stderr, "Now at end of input.\n"));
  }
  else
  {
    yytoken = YYTRANSLATE(yychar);
    YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
  yyval = yyvsp[1 - yylen];

  YY_REDUCE_PRINT(yyn);
  switch (yyn)
  {
  case 6:

/* Line 1464 of yacc.c  */
#line 48 "src/gerber_bison.yy"
  {
    g->processDataBlock();
  }
  break;

  case 12:

/* Line 1464 of yacc.c  */
#line 59 "src/gerber_bison.yy"
  {
    g->process_AD_block((yyvsp[(1) - (4)].YS_int));
  }
  break;

  case 13:

/* Line 1464 of yacc.c  */
#line 60 "src/gerber_bison.yy"
  {
    g->process_AD_block((yyvsp[(1) - (2)].YS_int));
  }
  break;

  case 14:

/* Line 1464 of yacc.c  */
#line 62 "src/gerber_bison.yy"
  {
    g->variables.push_back((yyvsp[(1) - (1)].YS_float));
  }
  break;

  case 15:

/* Line 1464 of yacc.c  */
#line 63 "src/gerber_bison.yy"
  {
    g->variables.push_back((yyvsp[(3) - (3)].YS_float));
  }
  break;

  case 16:

/* Line 1464 of yacc.c  */
#line 64 "src/gerber_bison.yy"
  {
    g->warning("modified expected after X");
  }
  break;

  case 17:

/* Line 1464 of yacc.c  */
#line 66 "src/gerber_bison.yy"
  {
    (yyval.YS_float) = -(yyvsp[(2) - (2)].YS_float);
  }
  break;

  case 18:

/* Line 1464 of yacc.c  */
#line 67 "src/gerber_bison.yy"
  {
    (yyval.YS_float) = (yyvsp[(2) - (2)].YS_float);
  }
  break;

  case 22:

/* Line 1464 of yacc.c  */
#line 74 "src/gerber_bison.yy"
  {
    g->macro_apertures.push_back(Aperture());
    g->macro_apertures.back().primitive = Aperture::PRIMITIVE(int((yyvsp[(1) - (3)].YS_float)));
    g->macro_apertures.back().parameter = g->temporaryParameters;
    g->macro_apertures.back().nameMacro = g->temporaryNameMacro;
    g->macro_apertures.back().linenum_at_definition = g->currentLine;
    g->temporaryParameters.clear();
  }
  break;

  case 23:

/* Line 1464 of yacc.c  */
#line 83 "src/gerber_bison.yy"
  {
    g->temporaryParameters.push_back((yyvsp[(1) - (1)].YS_NodeT));
  }
  break;

  case 24:

/* Line 1464 of yacc.c  */
#line 84 "src/gerber_bison.yy"
  {
    g->temporaryParameters.push_back((yyvsp[(3) - (3)].YS_NodeT));
  }
  break;

  case 25:

/* Line 1464 of yacc.c  */
#line 86 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = new NodeT(NodeT::VAR, &(yyvsp[(1) - (1)].YS_int), &g->variables);
  }
  break;

  case 26:

/* Line 1464 of yacc.c  */
#line 87 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = new NodeT(NodeT::CONSTANT, &(yyvsp[(1) - (1)].YS_float));
  }
  break;

  case 27:

/* Line 1464 of yacc.c  */
#line 88 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = new NodeT(NodeT::OPADD, (yyvsp[(1) - (3)].YS_NodeT), (yyvsp[(3) - (3)].YS_NodeT));
  }
  break;

  case 28:

/* Line 1464 of yacc.c  */
#line 89 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = new NodeT(NodeT::OPSUB, (yyvsp[(1) - (3)].YS_NodeT), (yyvsp[(3) - (3)].YS_NodeT));
  }
  break;

  case 29:

/* Line 1464 of yacc.c  */
#line 90 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = new NodeT(NodeT::OPMUL, (yyvsp[(1) - (3)].YS_NodeT), (yyvsp[(3) - (3)].YS_NodeT));
  }
  break;

  case 30:

/* Line 1464 of yacc.c  */
#line 91 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = new NodeT(NodeT::OPDIV, (yyvsp[(1) - (3)].YS_NodeT), (yyvsp[(3) - (3)].YS_NodeT));
  }
  break;

  case 31:

/* Line 1464 of yacc.c  */
#line 92 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = new NodeT(NodeT::OPNEG, (yyvsp[(2) - (2)].YS_NodeT));
  }
  break;

  case 32:

/* Line 1464 of yacc.c  */
#line 93 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = (yyvsp[(2) - (2)].YS_NodeT);
  }
  break;

  case 33:

/* Line 1464 of yacc.c  */
#line 94 "src/gerber_bison.yy"
  {
    (yyval.YS_NodeT) = (yyvsp[(2) - (3)].YS_NodeT);
  }
  break;

  case 36:

/* Line 1464 of yacc.c  */
#line 99 "src/gerber_bison.yy"
  {
    g->process_D_command(int((yyvsp[(2) - (2)].YS_float)));
  }
  break;

  case 37:

/* Line 1464 of yacc.c  */
#line 100 "src/gerber_bison.yy"
  {
    g->process_G_command(int((yyvsp[(2) - (2)].YS_float)));
  }
  break;

  case 38:

/* Line 1464 of yacc.c  */
#line 101 "src/gerber_bison.yy"
  {
  }
  break;

/* Line 1464 of yacc.c  */
#line 1588 "src/gerber_bison.cc"
  default:
    break;
  }
  YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK(yylen);
  yylen = 0;
  YY_STACK_PRINT(yyss, yyssp);

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
#if !YYERROR_VERBOSE
    yyerror(g, YY_("syntax error"));
#else
    {
      YYSIZE_T yysize = yysyntax_error(0, yystate, yychar);
      if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
      {
        YYSIZE_T yyalloc = 2 * yysize;
        if (!(yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
          yyalloc = YYSTACK_ALLOC_MAXIMUM;
        if (yymsg != yymsgbuf)
          YYSTACK_FREE(yymsg);
        yymsg = (char *)YYSTACK_ALLOC(yyalloc);
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
        (void)yysyntax_error(yymsg, yystate, yychar);
        yyerror(g, yymsg);
      }
      else
      {
        yyerror(g, YY_("syntax error"));
        if (yysize != 0)
          goto yyexhaustedlab;
      }
    }
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
      yydestruct("Error: discarding",
                 yytoken, &yylval, g);
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

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK(yylen);
  yylen = 0;
  YY_STACK_PRINT(yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;

/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3; /* Each real token shifted decrements this.  */

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

    yydestruct("Error: popping",
               yystos[yystate], yyvsp, g);
    YYPOPSTACK(1);
    yystate = *yyssp;
    YY_STACK_PRINT(yyss, yyssp);
  }

  *++yyvsp = yylval;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror(g, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    yydestruct("Cleanup: discarding lookahead",
               yytoken, &yylval, g);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK(yylen);
  YY_STACK_PRINT(yyss, yyssp);
  while (yyssp != yyss)
  {
    yydestruct("Cleanup: popping",
               yystos[*yyssp], yyvsp, g);
    YYPOPSTACK(1);
  }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE(yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID(yyresult);
}

/* Line 1684 of yacc.c  */
#line 107 "src/gerber_bison.yy"
