/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    #define BOLDRED "\033[1m\033[31m"
    #define BOLDBLUE "\033[1m\033[34m"
    #define BOLDMAGENTA "\033[1m\033[35m"
    #define BOLDGREEN "\033[1m\033[32m"
    #define RESET "\033[0m"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();

    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
    
    struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);

    struct dataType {
        char *id_name;
        char *data_type;
        char *type;
        int   line_no;
    } symbol_table[100];

    char type[100]; // Added declaration for type
	char id_name[100];
    int count = 0; // Added declaration for count
    int q; // Added declaration for q
    int sem_errors = 0;
    int label = 0;
    char buff[100];
    char errors[10][100];
    char reserved[10][20] = {"number", "import", "async", "string", "void", "if", "else", "for", "while", "return"};
    
    void insert_type();
	void store_name();
    void add(char c);
    int search(char *);


    void printBTHelper(char* prefix, struct node* ptr, int isLeft);
    void printBT(struct node* ptr);
    void printSymbolTable();
	void printSemanticErrors();

    int check_declaration(char *);
    void check_return_type(char *);
    int check_types(char *, char *);
    char *get_type(char *);
	void insert_type();
    
    extern int countn;

#line 135 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IMPORT = 258,                  /* IMPORT  */
    FROM = 259,                    /* FROM  */
    AS = 260,                      /* AS  */
    CONSOLELOG = 261,              /* CONSOLELOG  */
    SCAN = 262,                    /* SCAN  */
    IF = 263,                      /* IF  */
    WHILE = 264,                   /* WHILE  */
    ELSE = 265,                    /* ELSE  */
    RETURN = 266,                  /* RETURN  */
    ELIF = 267,                    /* ELIF  */
    LET = 268,                     /* LET  */
    VAR = 269,                     /* VAR  */
    CONST = 270,                   /* CONST  */
    ADD = 271,                     /* ADD  */
    SUB = 272,                     /* SUB  */
    MULT = 273,                    /* MULT  */
    DIV = 274,                     /* DIV  */
    LOG = 275,                     /* LOG  */
    GE = 276,                      /* GE  */
    LE = 277,                      /* LE  */
    GT = 278,                      /* GT  */
    LT = 279,                      /* LT  */
    EQ = 280,                      /* EQ  */
    NE = 281,                      /* NE  */
    TRUE = 282,                    /* TRUE  */
    FALSE = 283,                   /* FALSE  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    NUMBERTYPE = 286,              /* NUMBERTYPE  */
    STRINGTYPE = 287,              /* STRINGTYPE  */
    BOOLEANTYPE = 288,             /* BOOLEANTYPE  */
    FUNCTION = 289,                /* FUNCTION  */
    INTEGER = 290,                 /* INTEGER  */
    FLOAT = 291,                   /* FLOAT  */
    STRINGVALUE = 292,             /* STRINGVALUE  */
    POW = 293,                     /* POW  */
    IDENTIFIER = 294               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IMPORT 258
#define FROM 259
#define AS 260
#define CONSOLELOG 261
#define SCAN 262
#define IF 263
#define WHILE 264
#define ELSE 265
#define RETURN 266
#define ELIF 267
#define LET 268
#define VAR 269
#define CONST 270
#define ADD 271
#define SUB 272
#define MULT 273
#define DIV 274
#define LOG 275
#define GE 276
#define LE 277
#define GT 278
#define LT 279
#define EQ 280
#define NE 281
#define TRUE 282
#define FALSE 283
#define AND 284
#define OR 285
#define NUMBERTYPE 286
#define STRINGTYPE 287
#define BOOLEANTYPE 288
#define FUNCTION 289
#define INTEGER 290
#define FLOAT 291
#define STRINGVALUE 292
#define POW 293
#define IDENTIFIER 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "parser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} treeNode; 

    struct var_name2 {
        char name[100];
        struct node* nd;
        char type[8];
    } treeNode2;

#line 279 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IMPORT = 3,                     /* IMPORT  */
  YYSYMBOL_FROM = 4,                       /* FROM  */
  YYSYMBOL_AS = 5,                         /* AS  */
  YYSYMBOL_CONSOLELOG = 6,                 /* CONSOLELOG  */
  YYSYMBOL_SCAN = 7,                       /* SCAN  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_ELIF = 12,                      /* ELIF  */
  YYSYMBOL_LET = 13,                       /* LET  */
  YYSYMBOL_VAR = 14,                       /* VAR  */
  YYSYMBOL_CONST = 15,                     /* CONST  */
  YYSYMBOL_ADD = 16,                       /* ADD  */
  YYSYMBOL_SUB = 17,                       /* SUB  */
  YYSYMBOL_MULT = 18,                      /* MULT  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_LOG = 20,                       /* LOG  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NE = 26,                        /* NE  */
  YYSYMBOL_TRUE = 27,                      /* TRUE  */
  YYSYMBOL_FALSE = 28,                     /* FALSE  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_NUMBERTYPE = 31,                /* NUMBERTYPE  */
  YYSYMBOL_STRINGTYPE = 32,                /* STRINGTYPE  */
  YYSYMBOL_BOOLEANTYPE = 33,               /* BOOLEANTYPE  */
  YYSYMBOL_FUNCTION = 34,                  /* FUNCTION  */
  YYSYMBOL_INTEGER = 35,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 36,                     /* FLOAT  */
  YYSYMBOL_STRINGVALUE = 37,               /* STRINGVALUE  */
  YYSYMBOL_POW = 38,                       /* POW  */
  YYSYMBOL_IDENTIFIER = 39,                /* IDENTIFIER  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ':'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_main = 49,                      /* main  */
  YYSYMBOL_importList = 50,                /* importList  */
  YYSYMBOL_imports = 51,                   /* imports  */
  YYSYMBOL_moduleList = 52,                /* moduleList  */
  YYSYMBOL_modules = 53,                   /* modules  */
  YYSYMBOL_body = 54,                      /* body  */
  YYSYMBOL_block = 55,                     /* block  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_console_outputs = 59,           /* console_outputs  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_parameterList = 63,             /* parameterList  */
  YYSYMBOL_parameter = 64,                 /* parameter  */
  YYSYMBOL_65_6 = 65,                      /* $@6  */
  YYSYMBOL_66_7 = 66,                      /* $@7  */
  YYSYMBOL_datatype = 67,                  /* datatype  */
  YYSYMBOL_else = 68,                      /* else  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_condition = 70,                 /* condition  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_74_11 = 74,                     /* $@11  */
  YYSYMBOL_75_12 = 75,                     /* $@12  */
  YYSYMBOL_76_13 = 76,                     /* $@13  */
  YYSYMBOL_declaration = 77,               /* declaration  */
  YYSYMBOL_init = 78,                      /* init  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_term = 80,                      /* term  */
  YYSYMBOL_factor = 81,                    /* factor  */
  YYSYMBOL_base = 82,                      /* base  */
  YYSYMBOL_and_or = 83,                    /* and_or  */
  YYSYMBOL_exponent = 84,                  /* exponent  */
  YYSYMBOL_mulops = 85,                    /* mulops  */
  YYSYMBOL_addops = 86,                    /* addops  */
  YYSYMBOL_relop = 87,                     /* relop  */
  YYSYMBOL_number = 88,                    /* number  */
  YYSYMBOL_value = 89,                     /* value  */
  YYSYMBOL_90_14 = 90,                     /* $@14  */
  YYSYMBOL_91_15 = 91,                     /* $@15  */
  YYSYMBOL_92_16 = 92,                     /* $@16  */
  YYSYMBOL_return = 93,                    /* return  */
  YYSYMBOL_94_17 = 94                      /* $@17  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    42,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    90,    91,    92,    95,    96,    97,    98,
     101,   102,   105,   106,   109,   110,   113,   114,   114,   115,
     115,   116,   117,   117,   120,   121,   122,   126,   126,   126,
     129,   130,   131,   134,   134,   134,   138,   139,   140,   145,
     145,   146,   149,   150,   151,   152,   152,   153,   153,   156,
     156,   156,   201,   241,   241,   244,   245,   246,   249,   250,
     251,   255,   292,   295,   332,   335,   372,   373,   376,   377,
     380,   381,   384,   387,   388,   391,   392,   395,   396,   397,
     398,   399,   400,   403,   404,   407,   408,   409,   410,   410,
     411,   411,   412,   412,   416,   416,   418
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IMPORT", "FROM", "AS",
  "CONSOLELOG", "SCAN", "IF", "WHILE", "ELSE", "RETURN", "ELIF", "LET",
  "VAR", "CONST", "ADD", "SUB", "MULT", "DIV", "LOG", "GE", "LE", "GT",
  "LT", "EQ", "NE", "TRUE", "FALSE", "AND", "OR", "NUMBERTYPE",
  "STRINGTYPE", "BOOLEANTYPE", "FUNCTION", "INTEGER", "FLOAT",
  "STRINGVALUE", "POW", "IDENTIFIER", "'{'", "'}'", "';'", "','", "'('",
  "')'", "':'", "'='", "$accept", "main", "importList", "imports",
  "moduleList", "modules", "body", "block", "$@1", "$@2", "$@3",
  "console_outputs", "function", "$@4", "$@5", "parameterList",
  "parameter", "$@6", "$@7", "datatype", "else", "$@8", "condition", "$@9",
  "$@10", "statement", "$@11", "$@12", "$@13", "declaration", "init",
  "expression", "term", "factor", "base", "and_or", "exponent", "mulops",
  "addops", "relop", "number", "value", "$@14", "$@15", "$@16", "return",
  "$@17", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,     6,    25,    55,     4,   -46,   -46,    -7,     1,     7,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -17,   -46,
      55,   -46,     5,    15,   -46,    12,    19,    36,    -7,    17,
      18,    34,    38,    45,    -1,   112,   -46,   -46,   -46,    83,
      85,    50,    59,   -46,    95,    13,    70,    70,   -46,   -46,
      60,   -46,   -46,   -46,   -46,   -46,   -46,    -1,     0,    57,
     -46,    72,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
      -1,    69,    75,    79,   -46,    82,    81,    84,    94,     0,
     -16,    29,    56,   112,    87,    80,    96,    86,   -46,   -46,
      -8,   -46,   -46,    -1,   -46,   -46,    -1,   -46,    44,     0,
     -10,    88,   123,    99,   100,   -46,   -46,   -46,   -46,   103,
      70,    86,   105,    89,   101,   104,   -46,    57,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   111,   -46,   -46,    55,    66,
     -46,    55,   -46,   106,   107,   -46,    86,   102,   110,   113,
     114,   115,   116,    89,   108,    -1,   -46,   -46,   147,   -46,
     -10,    55,   -46,   -46,     0,   117,   -46,   -46,   -46,   149,
     118,   -46,   -46,   121,    55,    86,   -46,   122,   124,   -46,
     -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,    15,     4,    13,    12,     0,     0,    11,
       1,    22,    19,    17,    55,    56,    57,    27,    53,     2,
      15,    16,     0,     0,     3,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    21,    49,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    28,    92,
       0,    88,    90,    83,    84,    87,    86,     0,    52,    62,
      64,    67,    85,    68,    80,    79,    78,    77,    81,    82,
       0,     0,     0,     0,     8,     0,    87,    86,     0,    26,
      88,    90,     0,    44,     0,     0,     0,     0,    89,    91,
       0,    75,    76,     0,    73,    74,     0,    72,     0,    54,
       0,     0,     0,     0,     0,    46,    48,    70,    71,     0,
       0,     0,     0,    32,     0,     0,    69,    61,    63,    65,
      36,    37,    38,    50,     6,     0,     9,    23,    15,    42,
      43,    15,    33,     0,    31,    93,     0,    60,     0,     0,
       0,     0,     0,    32,     0,     0,    51,     7,    41,    18,
       0,    15,    30,    66,    59,    68,    39,    20,    34,    96,
       0,    35,    94,     0,    15,     0,    29,     0,     0,    40,
      95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   160,   -46,     3,    11,   -20,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,    22,   -46,   -46,   -46,    20,
     -46,   -46,   -43,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -42,    74,    73,    76,   -46,   -46,   -46,   -46,    90,
     -46,   -45,   -46,   -46,   -46,   -46,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     8,     9,    19,    20,    32,    31,
      30,    78,    21,    33,    85,   133,   134,   141,   161,   123,
     157,   160,    82,   105,   106,    22,    71,   137,    35,    23,
     146,    58,    59,    60,    61,   110,    98,    96,    93,    70,
      62,    63,    88,    89,    86,   163,   165
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    83,    83,    79,    84,    27,    49,     1,    91,    92,
      25,     5,    29,   -45,   -45,    90,    91,    92,    26,    50,
      49,   120,   121,   122,     5,    10,    51,    52,    99,   -45,
      34,    42,     6,    50,    53,    54,    55,   116,    56,    43,
      51,    52,   115,    57,    28,     6,     7,    37,    53,    54,
      76,    49,    77,    39,    38,    28,    44,    57,   -47,   -47,
      40,    11,    45,    12,    13,    83,   130,   129,    14,    15,
      16,    51,    52,    41,   -47,    94,    95,    49,    46,    53,
      54,    55,    47,    56,    48,   107,   108,    72,    57,    17,
      73,   144,    74,    49,    18,   107,   108,    80,    81,    75,
     155,   109,    28,   154,    87,    53,    54,    55,   139,    56,
      97,   140,   101,    51,    52,   100,   107,   108,   102,   103,
     168,    53,    54,    55,   113,    56,   -24,   125,   132,   -25,
     124,   159,   112,    64,    65,    66,    67,    68,    69,   104,
     114,   126,   127,   128,   167,   131,   135,   136,   138,   145,
     143,   142,   147,   153,   148,   149,   151,   156,   164,   -58,
     162,   150,   166,   169,    24,   152,   170,   117,     0,   118,
     158,     0,     0,   111,   119
};

static const yytype_int16 yycheck[] =
{
      20,    46,    47,    45,    47,     4,     7,     3,    16,    17,
       7,    18,     5,    29,    30,    57,    16,    17,     7,    20,
       7,    31,    32,    33,    18,     0,    27,    28,    70,    45,
      47,    28,    39,    20,    35,    36,    37,    45,    39,    28,
      27,    28,    87,    44,    43,    39,    40,    42,    35,    36,
      37,     7,    39,    41,    39,    43,    39,    44,    29,    30,
      41,     6,    44,     8,     9,   110,   111,   110,    13,    14,
      15,    27,    28,    37,    45,    18,    19,     7,    44,    35,
      36,    37,    44,    39,    39,    29,    30,     4,    44,    34,
       5,   136,    42,     7,    39,    29,    30,    27,    28,     4,
     145,    45,    43,   145,    44,    35,    36,    37,   128,    39,
      38,   131,    37,    27,    28,    46,    29,    30,    39,    37,
     165,    35,    36,    37,    44,    39,    45,     4,    39,    45,
      42,   151,    45,    21,    22,    23,    24,    25,    26,    45,
      44,    42,    42,    40,   164,    40,    45,    43,    37,    47,
      43,    45,    42,    45,    41,    41,    40,    10,    40,    42,
      11,    46,    41,    41,     4,   143,    42,    93,    -1,    96,
     150,    -1,    -1,    83,    98
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    50,    51,    18,    39,    40,    52,    53,
       0,     6,     8,     9,    13,    14,    15,    34,    39,    54,
      55,    60,    73,    77,    50,    52,    53,     4,    43,     5,
      58,    57,    56,    61,    47,    76,    54,    42,    39,    41,
      41,    37,    52,    53,    39,    44,    44,    44,    39,     7,
      20,    27,    28,    35,    36,    37,    39,    44,    79,    80,
      81,    82,    88,    89,    21,    22,    23,    24,    25,    26,
      87,    74,     4,     5,    42,     4,    37,    39,    59,    79,
      27,    28,    70,    89,    70,    62,    92,    44,    90,    91,
      79,    16,    17,    86,    18,    19,    85,    38,    84,    79,
      46,    37,    39,    37,    45,    71,    72,    29,    30,    45,
      83,    87,    45,    44,    44,    89,    45,    80,    81,    82,
      31,    32,    33,    67,    42,     4,    42,    42,    40,    70,
      89,    40,    39,    63,    64,    45,    43,    75,    37,    54,
      54,    65,    45,    43,    89,    47,    78,    42,    41,    41,
      46,    40,    63,    45,    79,    89,    10,    68,    67,    54,
      69,    66,    11,    93,    40,    94,    41,    54,    89,    41,
      42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    56,    55,    57,
      55,    55,    58,    55,    59,    59,    59,    61,    62,    60,
      63,    63,    63,    65,    66,    64,    67,    67,    67,    69,
      68,    68,    70,    70,    70,    71,    70,    72,    70,    74,
      75,    73,    73,    76,    73,    77,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    89,    90,    89,
      91,    89,    92,    89,    94,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     7,     9,     5,     7,
       3,     1,     1,     1,     2,     0,     1,     0,     8,     0,
       9,     2,     0,     6,     1,     1,     1,     0,     0,    11,
       3,     1,     0,     0,     0,     5,     1,     1,     1,     0,
       5,     0,     3,     3,     1,     0,     2,     0,     2,     0,
       0,     7,     3,     0,     4,     1,     1,     1,     2,     2,
       0,     3,     1,     3,     1,     3,     6,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       0,     2,     0,     4,     0,     4,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* main: importList body  */
#line 87 "parser.y"
                      { (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "Program"); head = (yyval.treeNode).nd; }
#line 1744 "y.tab.c"
    break;

  case 3: /* importList: imports importList  */
#line 90 "parser.y"
                               { (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "ImportList"); }
#line 1750 "y.tab.c"
    break;

  case 4: /* importList: imports  */
#line 91 "parser.y"
          { (yyval.treeNode).nd = mknode(NULL, (yyvsp[0].treeNode).nd, "ImportList"); }
#line 1756 "y.tab.c"
    break;

  case 5: /* importList: %empty  */
#line 92 "parser.y"
  { (yyval.treeNode).nd = mknode(NULL, NULL, "ImportList"); }
#line 1762 "y.tab.c"
    break;

  case 6: /* imports: IMPORT '{' moduleList '}' FROM STRINGVALUE ';'  */
#line 95 "parser.y"
                                                        { (yyval.treeNode).nd = (yyvsp[-4].treeNode).nd; }
#line 1768 "y.tab.c"
    break;

  case 7: /* imports: IMPORT '{' modules '}' AS IDENTIFIER FROM STRINGVALUE ';'  */
#line 96 "parser.y"
                                                            { (yyval.treeNode).nd = (yyvsp[-6].treeNode).nd; }
#line 1774 "y.tab.c"
    break;

  case 8: /* imports: IMPORT moduleList FROM STRINGVALUE ';'  */
#line 97 "parser.y"
                                         { (yyval.treeNode).nd = (yyvsp[-3].treeNode).nd; }
#line 1780 "y.tab.c"
    break;

  case 9: /* imports: IMPORT modules AS IDENTIFIER FROM STRINGVALUE ';'  */
#line 98 "parser.y"
                                                    { (yyval.treeNode).nd = (yyvsp[-5].treeNode).nd; }
#line 1786 "y.tab.c"
    break;

  case 10: /* moduleList: moduleList ',' moduleList  */
#line 101 "parser.y"
                                      { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "ModuleList"); }
#line 1792 "y.tab.c"
    break;

  case 11: /* moduleList: modules  */
#line 102 "parser.y"
          { (yyval.treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 1798 "y.tab.c"
    break;

  case 14: /* body: block body  */
#line 109 "parser.y"
                 {(yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "Scope"); }
#line 1804 "y.tab.c"
    break;

  case 15: /* body: %empty  */
#line 110 "parser.y"
  { (yyval.treeNode).nd = mknode(NULL, NULL, "EndOfScope"); }
#line 1810 "y.tab.c"
    break;

  case 16: /* block: function  */
#line 113 "parser.y"
                { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd; }
#line 1816 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 114 "parser.y"
       { add('K');}
#line 1822 "y.tab.c"
    break;

  case 18: /* block: WHILE $@1 '(' condition ')' '{' body '}'  */
#line 114 "parser.y"
                                                  { (yyval.treeNode).nd = mknode((yyvsp[-4].treeNode).nd, (yyvsp[-1].treeNode).nd, (yyvsp[-7].treeNode).name); }
#line 1828 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 115 "parser.y"
     { add('K');}
#line 1834 "y.tab.c"
    break;

  case 20: /* block: IF $@2 '(' condition ')' '{' body '}' else  */
#line 115 "parser.y"
                                                      { struct node *iff = mknode((yyvsp[-5].treeNode).nd, (yyvsp[-2].treeNode).nd, (yyvsp[-8].treeNode).name); (yyval.treeNode).nd = mknode(iff, (yyvsp[0].treeNode).nd, "conditionalBranch"); }
#line 1840 "y.tab.c"
    break;

  case 21: /* block: statement ';'  */
#line 116 "parser.y"
                { (yyval.treeNode).nd = (yyvsp[-1].treeNode).nd; }
#line 1846 "y.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 117 "parser.y"
             { add('K');}
#line 1852 "y.tab.c"
    break;

  case 23: /* block: CONSOLELOG $@3 '(' console_outputs ')' ';'  */
#line 117 "parser.y"
                                                      { struct node *data = mknode(NULL, NULL, (yyvsp[-2].treeNode).name); (yyval.treeNode).nd = mknode(NULL, data, "ConsoleLog"); }
#line 1858 "y.tab.c"
    break;

  case 24: /* console_outputs: STRINGVALUE  */
#line 120 "parser.y"
                             { add('C');}
#line 1864 "y.tab.c"
    break;

  case 25: /* console_outputs: IDENTIFIER  */
#line 121 "parser.y"
                             { check_declaration((yyvsp[0].treeNode2).name);}
#line 1870 "y.tab.c"
    break;

  case 26: /* console_outputs: expression  */
#line 122 "parser.y"
                             { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd; }
#line 1876 "y.tab.c"
    break;

  case 27: /* $@4: %empty  */
#line 126 "parser.y"
                   { add('F'); }
#line 1882 "y.tab.c"
    break;

  case 28: /* $@5: %empty  */
#line 126 "parser.y"
                                            { add('I'); }
#line 1888 "y.tab.c"
    break;

  case 29: /* function: FUNCTION $@4 IDENTIFIER $@5 '(' parameterList ')' '{' body return '}'  */
#line 126 "parser.y"
                                                                                                    {  (yyvsp[-2].treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-1].treeNode).nd, "FunctionBody"); struct node *main = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-5].treeNode).nd, (yyvsp[-8].treeNode2).name); (yyval.treeNode2).nd = mknode((yyvsp[-10].treeNode).nd, main, "Function"); }
#line 1894 "y.tab.c"
    break;

  case 30: /* parameterList: parameter ',' parameterList  */
#line 129 "parser.y"
                                           { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "ParameterList"); }
#line 1900 "y.tab.c"
    break;

  case 31: /* parameterList: parameter  */
#line 130 "parser.y"
            { (yyval.treeNode).nd = (yyvsp[0].treeNode).nd; }
#line 1906 "y.tab.c"
    break;

  case 32: /* parameterList: %empty  */
#line 131 "parser.y"
  { (yyval.treeNode).nd = (yyval.treeNode).nd = mknode(NULL, NULL, "Parameter"); }
#line 1912 "y.tab.c"
    break;

  case 33: /* $@6: %empty  */
#line 134 "parser.y"
                      {store_name();}
#line 1918 "y.tab.c"
    break;

  case 34: /* $@7: %empty  */
#line 134 "parser.y"
                                                   {add('I');}
#line 1924 "y.tab.c"
    break;

  case 35: /* parameter: IDENTIFIER $@6 ':' datatype $@7  */
#line 134 "parser.y"
                                                               {(yyvsp[-1].treeNode).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name); (yyvsp[-4].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-4].treeNode2).name); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[-4].treeNode2).nd, "Parameter");}
#line 1930 "y.tab.c"
    break;

  case 36: /* datatype: NUMBERTYPE  */
#line 138 "parser.y"
                     { insert_type(); }
#line 1936 "y.tab.c"
    break;

  case 37: /* datatype: STRINGTYPE  */
#line 139 "parser.y"
             { insert_type(); }
#line 1942 "y.tab.c"
    break;

  case 38: /* datatype: BOOLEANTYPE  */
#line 140 "parser.y"
              { insert_type(); }
#line 1948 "y.tab.c"
    break;

  case 39: /* $@8: %empty  */
#line 145 "parser.y"
           { add('K');}
#line 1954 "y.tab.c"
    break;

  case 40: /* else: ELSE $@8 '{' body '}'  */
#line 145 "parser.y"
                                     {  struct node *cond = mknode(NULL, NULL, "EndOfConditional"); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, cond, (yyvsp[-4].treeNode).name); }
#line 1960 "y.tab.c"
    break;

  case 41: /* else: %empty  */
#line 146 "parser.y"
  { (yyval.treeNode).nd = NULL; }
#line 1966 "y.tab.c"
    break;

  case 42: /* condition: condition and_or condition  */
#line 149 "parser.y"
                                      { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, (yyvsp[-1].treeNode).name); }
#line 1972 "y.tab.c"
    break;

  case 43: /* condition: value relop value  */
#line 150 "parser.y"
                    { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name);}
#line 1978 "y.tab.c"
    break;

  case 44: /* condition: value  */
#line 151 "parser.y"
        { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd;}
#line 1984 "y.tab.c"
    break;

  case 45: /* $@9: %empty  */
#line 152 "parser.y"
       { add('K');}
#line 1990 "y.tab.c"
    break;

  case 46: /* condition: TRUE $@9  */
#line 152 "parser.y"
                    {(yyval.treeNode).nd = NULL; }
#line 1996 "y.tab.c"
    break;

  case 47: /* $@10: %empty  */
#line 153 "parser.y"
        { add('K');}
#line 2002 "y.tab.c"
    break;

  case 48: /* condition: FALSE $@10  */
#line 153 "parser.y"
                     {(yyval.treeNode).nd = NULL; }
#line 2008 "y.tab.c"
    break;

  case 49: /* $@11: %empty  */
#line 156 "parser.y"
                                  { store_name(); }
#line 2014 "y.tab.c"
    break;

  case 50: /* $@12: %empty  */
#line 156 "parser.y"
                                                                 {add('I');}
#line 2020 "y.tab.c"
    break;

  case 51: /* statement: declaration IDENTIFIER $@11 ':' datatype $@12 init  */
#line 156 "parser.y"
                                                                                  {
    (yyvsp[-2].treeNode).nd = mknode(NULL, NULL, (yyvsp[-2].treeNode).name); //making for datatype
	(yyvsp[-5].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-5].treeNode2).name); //making for identifier
	(yyvsp[-6].treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-5].treeNode2).nd, (yyvsp[-6].treeNode).name); //making for the declaration
	int t = check_types((yyvsp[-2].treeNode).name, (yyvsp[0].treeNode2).type); //here we're checking types
	// printf("%s\n", $5.name);
	// printf("%s\n", $6.type);
	// printf("%d\n", t);
	if(t>0) {
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
		if(t == 1) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration: number and string\n", countn+1);
			sem_errors++;
        }
		else if(t == 2) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration: string and number\n", countn+1);
			sem_errors++;
        }  
		else if(t == 3) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration: number and boolean\n", countn+1);
			sem_errors++;
        }  
		else if(t == 4) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration: boolean and number\n", countn+1);
			sem_errors++;
        }  
		else if(t == 5) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration: boolean and string\n", countn+1);
			sem_errors++;
        }  
		else if(t == 6) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration: string and boolean\n", countn+1);
			sem_errors++;
        }   
		else {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		(yyval.treeNode).nd = mknode((yyvsp[-5].treeNode2).nd, (yyvsp[0].treeNode2).nd, "Initialisation");
		
	}
		
	}
#line 2070 "y.tab.c"
    break;

  case 52: /* statement: IDENTIFIER '=' expression  */
#line 201 "parser.y"
                            { 
	if(check_declaration((yyvsp[-2].treeNode2).name)){
		(yyvsp[-2].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-2].treeNode2).name);  
		char *id_type = get_type((yyvsp[-2].treeNode2).name); 
		if(strcmp(id_type, (yyvsp[0].treeNode2).type)) {
			//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;	
			int t =  check_types(id_type,(yyvsp[0].treeNode2).type); 
			if(t>0) { 
			if(t == 1) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment: number and string\n", countn+1); 
				sem_errors++;
			}
			else if(t == 2) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment: string and number\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 3) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment: number and boolean\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 4) {
				 sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment: boolean and number\n", countn+1); 
				 sem_errors++;
			}  
			else if(t == 5) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment: boolean and string\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 6) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment: string and boolean\n", countn+1); 
				sem_errors++;
			}   
        }
		}
		else {
			(yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, "="); 
		}
	}
	
	}
#line 2115 "y.tab.c"
    break;

  case 53: /* $@13: %empty  */
#line 241 "parser.y"
             { check_declaration((yyvsp[0].treeNode2).name); }
#line 2121 "y.tab.c"
    break;

  case 54: /* statement: IDENTIFIER $@13 relop expression  */
#line 241 "parser.y"
                                                              { (yyvsp[-3].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-3].treeNode2).name); (yyval.treeNode).nd = mknode((yyvsp[-3].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name ); }
#line 2127 "y.tab.c"
    break;

  case 55: /* declaration: LET  */
#line 244 "parser.y"
                 { add('K');}
#line 2133 "y.tab.c"
    break;

  case 56: /* declaration: VAR  */
#line 245 "parser.y"
      { add('K');}
#line 2139 "y.tab.c"
    break;

  case 57: /* declaration: CONST  */
#line 246 "parser.y"
        { add('K');}
#line 2145 "y.tab.c"
    break;

  case 58: /* init: '=' value  */
#line 249 "parser.y"
                { (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); }
#line 2151 "y.tab.c"
    break;

  case 59: /* init: '=' expression  */
#line 250 "parser.y"
                 { (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); }
#line 2157 "y.tab.c"
    break;

  case 60: /* init: %empty  */
#line 251 "parser.y"
  { sprintf((yyval.treeNode2).type, "%s", "null"); (yyval.treeNode2).nd = mknode(NULL, NULL, "NULL"); strcpy((yyval.treeNode2).name, "NULL"); }
#line 2163 "y.tab.c"
    break;

  case 61: /* expression: expression addops term  */
#line 255 "parser.y"
                                    { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;
		if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf((yyval.treeNode2).type, "%s", (yyvsp[-2].treeNode2).type);
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name);
	}
}
#line 2205 "y.tab.c"
    break;

  case 62: /* expression: term  */
#line 292 "parser.y"
       { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2211 "y.tab.c"
    break;

  case 63: /* term: term mulops factor  */
#line 295 "parser.y"
                          { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;
		if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf((yyval.treeNode2).type, "%s", (yyvsp[-2].treeNode2).type);
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name);
	}
	}
#line 2253 "y.tab.c"
    break;

  case 64: /* term: factor  */
#line 332 "parser.y"
         { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2259 "y.tab.c"
    break;

  case 65: /* factor: base exponent base  */
#line 335 "parser.y"
                            { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;
		if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: number + string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: string + number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: boolean + number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: boolean + string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: number + boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression: string + boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf((yyval.treeNode2).type, "%s", (yyvsp[-2].treeNode2).type);
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode2).name);
	}
	}
#line 2301 "y.tab.c"
    break;

  case 66: /* factor: LOG '(' value ',' value ')'  */
#line 372 "parser.y"
                              {(yyval.treeNode2).nd = mknode((yyvsp[-3].treeNode2).nd, (yyvsp[-1].treeNode2).nd, (yyvsp[-5].treeNode).name); }
#line 2307 "y.tab.c"
    break;

  case 67: /* factor: base  */
#line 373 "parser.y"
       { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2313 "y.tab.c"
    break;

  case 68: /* base: value  */
#line 376 "parser.y"
              { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2319 "y.tab.c"
    break;

  case 69: /* base: '(' expression ')'  */
#line 377 "parser.y"
                      { strcpy((yyval.treeNode2).name, (yyvsp[-1].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[-1].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[-1].treeNode2).nd; }
#line 2325 "y.tab.c"
    break;

  case 70: /* and_or: AND  */
#line 380 "parser.y"
             { (yyval.treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2331 "y.tab.c"
    break;

  case 71: /* and_or: OR  */
#line 381 "parser.y"
     { (yyval.treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2337 "y.tab.c"
    break;

  case 83: /* number: INTEGER  */
#line 403 "parser.y"
                { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "%s", "number"); add('N'); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2343 "y.tab.c"
    break;

  case 84: /* number: FLOAT  */
#line 404 "parser.y"
        { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "%s", "number"); add('N'); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2349 "y.tab.c"
    break;

  case 85: /* value: number  */
#line 407 "parser.y"
              {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name);}
#line 2355 "y.tab.c"
    break;

  case 86: /* value: IDENTIFIER  */
#line 408 "parser.y"
             { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); char *id_type = get_type((yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", id_type); check_declaration((yyvsp[0].treeNode2).name); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name); }
#line 2361 "y.tab.c"
    break;

  case 87: /* value: STRINGVALUE  */
#line 409 "parser.y"
              { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "string"); add('C'); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2367 "y.tab.c"
    break;

  case 88: /* $@14: %empty  */
#line 410 "parser.y"
       { add('K');}
#line 2373 "y.tab.c"
    break;

  case 89: /* value: TRUE $@14  */
#line 410 "parser.y"
                    {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name);}
#line 2379 "y.tab.c"
    break;

  case 90: /* $@15: %empty  */
#line 411 "parser.y"
        { add('K');}
#line 2385 "y.tab.c"
    break;

  case 91: /* value: FALSE $@15  */
#line 411 "parser.y"
                     {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name);}
#line 2391 "y.tab.c"
    break;

  case 92: /* $@16: %empty  */
#line 412 "parser.y"
       { add('K');}
#line 2397 "y.tab.c"
    break;

  case 93: /* value: SCAN $@16 '(' ')'  */
#line 412 "parser.y"
                           { (yyval.treeNode2).nd = mknode(NULL, NULL, "scan"); }
#line 2403 "y.tab.c"
    break;

  case 94: /* $@17: %empty  */
#line 416 "parser.y"
               { add('K');}
#line 2409 "y.tab.c"
    break;

  case 95: /* return: RETURN $@17 value ';'  */
#line 416 "parser.y"
                                       { (yyvsp[-3].treeNode).nd = mknode(NULL, NULL, "return"); (yyval.treeNode).nd = mknode((yyvsp[-3].treeNode).nd, (yyvsp[-1].treeNode2).nd, "ReturnStatement"); }
#line 2415 "y.tab.c"
    break;

  case 96: /* return: %empty  */
#line 418 "parser.y"
  { (yyval.treeNode).nd = NULL; }
#line 2421 "y.tab.c"
    break;


#line 2425 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 422 "parser.y"



int main() {
    extern FILE *yyin, *yyout;
   
    int p = -1;
    p = yyparse();
    if(p)
        printf("Parsing Successful\n");
    printf("\033[4mParse Tree\033[24m\n");
	printBT(head);
    printf("\n\n");

    printSymbolTable();

    printSemanticErrors();

    return p;
}

int yyerror(const char *msg)
{
    extern int yylineno;
    printf("%sParsing Failed\nLine Number: %d,%s\n",BOLDRED,yylineno,msg);
    exit(0);
    return 0;
}

void printBTHelper(char* prefix, struct node* ptr, int isLeft) {
    if( ptr != NULL ) {
        printf("%s",prefix);
        if(isLeft) { printf("├──"); } 
		else { printf("└──"); }
        printf("%s",ptr->token);
		printf("\n");
		char* addon = isLeft ? "│   " : "    ";
    	int len2 = strlen(addon);
    	int len1 = strlen(prefix);
    	char* result = (char*)malloc(len1 + len2 + 1);
    	strcpy(result, prefix);
    	strcpy(result + len1, addon);
		printBTHelper(result, ptr->left, 1);
		printBTHelper(result, ptr->right, 0);
    	free(result);
    }
}

void printBT(struct node* ptr) {
	printf("\n");
    printBTHelper("", ptr, 0);    
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void printSymbolTable(){
	printf("\033[4mSymbol Table\033[24m\n");

	int i=0;

	for(i=0; i<count; i++) {
		printf("Line No:\033[1m\033[34m%d\033[0m \t\033[1m\033[32m%s\033[0m \t\t\t\033[1m\033[35m%s\033[0m \t\t\033[1m\033[34m%s\033[0m \t\n", symbol_table[i].line_no, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].id_name);
	}

	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
}


void printSemanticErrors() {
	printf("\033[4mSemantic Errors\033[24m\n");
	if(sem_errors>0) {
        printf(BOLDRED);
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("%s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
}


int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
}

int check_declaration(char *c) {
    q = search(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage\n", countn+1, c);
		sem_errors++;
		return 0;
    }
	return 1;
}

void check_return_type(char *value) {
	char *main_datatype = get_type("main");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "int") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
		return ;
	}
	else {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
		sem_errors++;
	}
}

int check_types(char *type1, char *type2){
	// declaration with no initialization
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "number") && !strcmp(type2, "string"))
		return 1;
	if(!strcmp(type1, "string") && !strcmp(type2, "number"))
		return 2;
	if(!strcmp(type1, "number") && !strcmp(type2, "boolean"))
		return 3;
	if(!strcmp(type1, "boolean") && !strcmp(type2, "number"))
		return 4;
	if(!strcmp(type1, "boolean") && !strcmp(type2, "string"))
		return 5;
	if(!strcmp(type1, "string") && !strcmp(type2, "boolean"))
		return 6;
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}


void add(char c) {
	if(c == 'I'){
		for(int i=0; i<10; i++){
			if(!strcmp(reserved[i], strdup(id_name))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword\n", countn+1, id_name);
				sem_errors++;
				return;
			}
		}
	}
	char *qtext;
	if(c =='I') qtext = id_name;
	else qtext = yytext;
    q=search(qtext);
	if(!q) {
		if(c == 'H') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'I') {
			symbol_table[count].id_name=strdup(id_name);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("Value");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Constant");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
			count++;
		}
		else if(c == 'N') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("number");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("NumberLiteral");
			count++;
		}
    }
    else if(c == 'I' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed\n", countn+1, id_name);
		sem_errors++;
    }
}

void insert_type() {
	strcpy(type, yytext);
}

void store_name() {
	strcpy(id_name, yytext);
	//printf("IDENTIFIER NAME: %s\n", id_name);
}
