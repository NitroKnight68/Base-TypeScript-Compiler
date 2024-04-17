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
    int count = 0; // Added declaration for count
    int q; // Added declaration for q
    int sem_errors = 0;
    int label = 0;
    char buff[100];
    char errors[10][100];
    char reserved[10][20] = {"number", "import", "async", "string", "void", "if", "else", "for", "while", "return"};
    
    void insert_type();
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

#line 133 "y.tab.c"

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
    IDENTIFIER = 292,              /* IDENTIFIER  */
    STRINGVALUE = 293,             /* STRINGVALUE  */
    POW = 294                      /* POW  */
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
#define IDENTIFIER 292
#define STRINGVALUE 293
#define POW 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "parser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} treeNode; 

    struct var_name2 {
        char name[100];
        struct node* nd;
        char type[8];
    } treeNode2;

#line 277 "y.tab.c"

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
  YYSYMBOL_IDENTIFIER = 37,                /* IDENTIFIER  */
  YYSYMBOL_STRINGVALUE = 38,               /* STRINGVALUE  */
  YYSYMBOL_POW = 39,                       /* POW  */
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
  YYSYMBOL_datatype = 66,                  /* datatype  */
  YYSYMBOL_else = 67,                      /* else  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_condition = 69,                 /* condition  */
  YYSYMBOL_70_8 = 70,                      /* $@8  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_73_10 = 73,                     /* $@10  */
  YYSYMBOL_74_11 = 74,                     /* $@11  */
  YYSYMBOL_75_12 = 75,                     /* $@12  */
  YYSYMBOL_declaration = 76,               /* declaration  */
  YYSYMBOL_init = 77,                      /* init  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_term = 79,                      /* term  */
  YYSYMBOL_factor = 80,                    /* factor  */
  YYSYMBOL_base = 81,                      /* base  */
  YYSYMBOL_and_or = 82,                    /* and_or  */
  YYSYMBOL_exponent = 83,                  /* exponent  */
  YYSYMBOL_mulops = 84,                    /* mulops  */
  YYSYMBOL_addops = 85,                    /* addops  */
  YYSYMBOL_relop = 86,                     /* relop  */
  YYSYMBOL_number = 87,                    /* number  */
  YYSYMBOL_value = 88,                     /* value  */
  YYSYMBOL_89_13 = 89,                     /* $@13  */
  YYSYMBOL_90_14 = 90,                     /* $@14  */
  YYSYMBOL_91_15 = 91,                     /* $@15  */
  YYSYMBOL_return = 92,                    /* return  */
  YYSYMBOL_93_16 = 93                      /* $@16  */
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
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

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
       0,    85,    85,    88,    89,    90,    93,    94,    95,    96,
      99,   100,   103,   104,   107,   108,   111,   112,   112,   113,
     113,   114,   115,   115,   118,   119,   120,   124,   124,   124,
     127,   128,   129,   132,   132,   136,   137,   138,   143,   143,
     144,   147,   148,   149,   150,   150,   151,   151,   154,   154,
     171,   171,   184,   184,   187,   188,   189,   192,   193,   194,
     198,   206,   209,   218,   221,   229,   230,   233,   234,   237,
     238,   241,   244,   245,   248,   249,   252,   253,   254,   255,
     256,   257,   260,   261,   264,   265,   266,   267,   267,   268,
     268,   269,   269,   273,   273,   275
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
  "IDENTIFIER", "STRINGVALUE", "POW", "'{'", "'}'", "';'", "','", "'('",
  "')'", "':'", "'='", "$accept", "main", "importList", "imports",
  "moduleList", "modules", "body", "block", "$@1", "$@2", "$@3",
  "console_outputs", "function", "$@4", "$@5", "parameterList",
  "parameter", "$@6", "datatype", "else", "$@7", "condition", "$@8", "$@9",
  "statement", "$@10", "$@11", "$@12", "declaration", "init", "expression",
  "term", "factor", "base", "and_or", "exponent", "mulops", "addops",
  "relop", "number", "value", "$@13", "$@14", "$@15", "return", "$@16", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    -9,    22,    63,    17,   -47,   -47,    -4,     1,    60,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,
      63,   -47,    15,    33,   -47,   -28,    40,    46,    -4,    59,
      48,    64,    67,    62,    70,    99,   -47,   -47,   -47,    85,
     102,    68,    75,   -47,   122,    -1,    66,    66,   -47,    18,
     -47,   -47,   -47,   -47,   -47,   -47,    18,    81,    90,    92,
     -47,    93,   -47,    86,   -47,   -47,   -47,   -47,    87,    89,
      18,    91,    13,    42,   -47,    96,   -47,   -47,   -22,   -13,
     -47,   -47,    34,    99,    53,    94,    13,    13,    55,    95,
     135,    98,    97,    78,   -47,   -47,    -5,   100,   -47,   -47,
      18,   -47,   -47,    18,   -47,    14,   -47,   -47,   -47,   -47,
     104,    66,    78,   105,   109,   -47,   -47,   -47,   101,   -47,
     111,   -47,   106,   107,   -47,   -47,    42,   -47,   -47,    63,
      45,   -47,    63,   -47,   108,   112,    18,   -47,   110,   -47,
      78,   113,   115,   114,   117,   109,    13,   116,   -47,   118,
     137,   -47,    55,    63,   -47,   -47,   -47,   -47,   -47,   148,
     121,   -47,   123,    63,    78,   -47,   124,   120,   -47,   -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,    15,     4,    13,    12,     0,     0,    11,
       1,    22,    19,    17,    54,    55,    56,    27,    52,     2,
      15,    16,     0,     0,     3,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    21,    48,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    28,     0,
      79,    78,    77,    76,    80,    81,     0,     0,     0,     0,
       8,     0,    91,     0,    87,    89,    82,    83,    85,    86,
       0,     0,    26,    61,    63,    66,    84,    67,    87,    89,
      85,    86,     0,    43,     0,     0,    51,    53,     0,     0,
       0,     0,     0,     0,    88,    90,     0,     0,    74,    75,
       0,    72,    73,     0,    71,     0,    45,    47,    69,    70,
       0,     0,     0,     0,    32,    35,    36,    37,    59,     6,
       0,     9,     0,     0,    68,    23,    60,    62,    64,    15,
      41,    42,    15,    33,     0,    31,     0,    49,     0,    92,
       0,     0,     0,     0,     0,    32,    58,    67,     7,     0,
      40,    18,     0,    15,    30,    65,    38,    20,    34,    95,
       0,    93,     0,    15,     0,    29,     0,     0,    39,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   162,   -47,    11,    52,   -20,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,    23,   -47,   -47,    19,   -47,
     -47,   -43,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -46,    69,    71,    65,   -47,   -47,   -47,   -47,    84,   -47,
     -45,   -47,   -47,   -47,   -47,   -47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     8,     9,    19,    20,    32,    31,
      30,    71,    21,    33,    85,   134,   135,   143,   118,   157,
     160,    82,   106,   107,    22,    57,    34,    35,    23,   137,
      72,    73,    74,    75,   111,   105,   103,   100,    56,    76,
      77,    94,    95,    92,   162,   164
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    83,    83,    86,    84,    27,    62,   -44,   -44,     5,
      87,    98,    99,    39,     5,    28,   -46,   -46,    25,    63,
       1,    62,    10,   -44,    96,    62,    64,    65,     6,    98,
      99,     7,   -46,     6,    66,    67,    68,    69,    63,    42,
     124,    64,    65,    70,    28,    64,    65,   -50,   123,    66,
      67,    80,    81,    66,    67,    80,    81,    37,    70,    26,
     101,   102,    70,   108,   109,    29,    83,   131,   130,    11,
      38,    12,    13,    62,   108,   109,    14,    15,    16,   110,
      43,    40,   108,   109,    41,    62,   115,   116,   117,    58,
     146,   147,    45,    78,    79,   149,    44,    17,   113,    48,
      18,    66,    67,    80,    81,    64,    65,    59,    46,   141,
      60,    47,   142,    66,    67,    80,    81,    49,    28,   167,
      50,    51,    52,    53,    54,    55,    61,    88,    89,    90,
      93,    91,   -25,   159,   -24,   104,    97,   119,   114,   120,
     121,   122,   125,   166,   129,   132,   133,   156,   136,   138,
     140,   139,   148,   144,   150,   145,   151,   153,   -57,   161,
     152,   163,   169,   155,   165,   168,    24,   112,   154,   126,
     128,   158,     0,     0,   127
};

static const yytype_int16 yycheck[] =
{
      20,    46,    47,    49,    47,     4,     7,    29,    30,    18,
      56,    16,    17,    41,    18,    43,    29,    30,     7,    20,
       3,     7,     0,    45,    70,     7,    27,    28,    37,    16,
      17,    40,    45,    37,    35,    36,    37,    38,    20,    28,
      45,    27,    28,    44,    43,    27,    28,    47,    93,    35,
      36,    37,    38,    35,    36,    37,    38,    42,    44,     7,
      18,    19,    44,    29,    30,     5,   111,   112,   111,     6,
      37,     8,     9,     7,    29,    30,    13,    14,    15,    45,
      28,    41,    29,    30,    38,     7,    31,    32,    33,     4,
     136,   136,    44,    27,    28,   140,    37,    34,    45,    37,
      37,    35,    36,    37,    38,    27,    28,     5,    44,   129,
      42,    44,   132,    35,    36,    37,    38,    47,    43,   164,
      21,    22,    23,    24,    25,    26,     4,    46,    38,    37,
      44,    38,    45,   153,    45,    39,    45,    42,    44,     4,
      42,    44,    42,   163,    40,    40,    37,    10,    47,    38,
      43,    45,    42,    45,    41,    43,    41,    40,    42,    11,
      46,    40,    42,    45,    41,    41,     4,    83,   145,   100,
     105,   152,    -1,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    50,    51,    18,    37,    40,    52,    53,
       0,     6,     8,     9,    13,    14,    15,    34,    37,    54,
      55,    60,    72,    76,    50,    52,    53,     4,    43,     5,
      58,    57,    56,    61,    74,    75,    54,    42,    37,    41,
      41,    38,    52,    53,    37,    44,    44,    44,    37,    47,
      21,    22,    23,    24,    25,    26,    86,    73,     4,     5,
      42,     4,     7,    20,    27,    28,    35,    36,    37,    38,
      44,    59,    78,    79,    80,    81,    87,    88,    27,    28,
      37,    38,    69,    88,    69,    62,    78,    78,    46,    38,
      37,    38,    91,    44,    89,    90,    78,    45,    16,    17,
      85,    18,    19,    84,    39,    83,    70,    71,    29,    30,
      45,    82,    86,    45,    44,    31,    32,    33,    66,    42,
       4,    42,    44,    88,    45,    42,    79,    80,    81,    40,
      69,    88,    40,    37,    63,    64,    47,    77,    38,    45,
      43,    54,    54,    65,    45,    43,    78,    88,    42,    88,
      41,    41,    46,    40,    63,    45,    10,    67,    66,    54,
      68,    11,    92,    40,    93,    41,    54,    88,    41,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    56,    55,    57,
      55,    55,    58,    55,    59,    59,    59,    61,    62,    60,
      63,    63,    63,    65,    64,    66,    66,    66,    68,    67,
      67,    69,    69,    69,    70,    69,    71,    69,    73,    72,
      74,    72,    75,    72,    76,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    83,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    87,    87,    88,    88,    88,    89,    88,    90,
      88,    91,    88,    93,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     7,     9,     5,     7,
       3,     1,     1,     1,     2,     0,     1,     0,     8,     0,
       9,     2,     0,     6,     1,     1,     1,     0,     0,    11,
       3,     1,     0,     0,     4,     1,     1,     1,     0,     5,
       0,     3,     3,     1,     0,     2,     0,     2,     0,     6,
       0,     4,     0,     4,     1,     1,     1,     2,     2,     0,
       3,     1,     3,     1,     3,     6,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       2,     0,     4,     0,     4,     0
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
#line 85 "parser.y"
                      { (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "Program"); head = (yyval.treeNode).nd; }
#line 1737 "y.tab.c"
    break;

  case 3: /* importList: imports importList  */
#line 88 "parser.y"
                               { (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "ImportList"); }
#line 1743 "y.tab.c"
    break;

  case 4: /* importList: imports  */
#line 89 "parser.y"
          { (yyval.treeNode).nd = mknode(NULL, (yyvsp[0].treeNode).nd, "ImportList"); }
#line 1749 "y.tab.c"
    break;

  case 5: /* importList: %empty  */
#line 90 "parser.y"
  { (yyval.treeNode).nd = mknode(NULL, NULL, "ImportList"); }
#line 1755 "y.tab.c"
    break;

  case 6: /* imports: IMPORT '{' moduleList '}' FROM STRINGVALUE ';'  */
#line 93 "parser.y"
                                                        { (yyval.treeNode).nd = (yyvsp[-4].treeNode).nd; }
#line 1761 "y.tab.c"
    break;

  case 7: /* imports: IMPORT '{' modules '}' AS IDENTIFIER FROM STRINGVALUE ';'  */
#line 94 "parser.y"
                                                            { (yyval.treeNode).nd = (yyvsp[-6].treeNode).nd; }
#line 1767 "y.tab.c"
    break;

  case 8: /* imports: IMPORT moduleList FROM STRINGVALUE ';'  */
#line 95 "parser.y"
                                         { (yyval.treeNode).nd = (yyvsp[-3].treeNode).nd; }
#line 1773 "y.tab.c"
    break;

  case 9: /* imports: IMPORT modules AS IDENTIFIER FROM STRINGVALUE ';'  */
#line 96 "parser.y"
                                                    { (yyval.treeNode).nd = (yyvsp[-5].treeNode).nd; }
#line 1779 "y.tab.c"
    break;

  case 10: /* moduleList: moduleList ',' moduleList  */
#line 99 "parser.y"
                                      { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "ModuleList"); }
#line 1785 "y.tab.c"
    break;

  case 11: /* moduleList: modules  */
#line 100 "parser.y"
          { (yyval.treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 1791 "y.tab.c"
    break;

  case 14: /* body: block body  */
#line 107 "parser.y"
                 {(yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "Scope"); }
#line 1797 "y.tab.c"
    break;

  case 15: /* body: %empty  */
#line 108 "parser.y"
  { (yyval.treeNode).nd = mknode(NULL, NULL, "EndOfScope"); }
#line 1803 "y.tab.c"
    break;

  case 16: /* block: function  */
#line 111 "parser.y"
                { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd; }
#line 1809 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 112 "parser.y"
       { add('K');}
#line 1815 "y.tab.c"
    break;

  case 18: /* block: WHILE $@1 '(' condition ')' '{' body '}'  */
#line 112 "parser.y"
                                                  { (yyval.treeNode).nd = mknode((yyvsp[-4].treeNode).nd, (yyvsp[-1].treeNode).nd, (yyvsp[-7].treeNode).name); }
#line 1821 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 113 "parser.y"
     { add('K');}
#line 1827 "y.tab.c"
    break;

  case 20: /* block: IF $@2 '(' condition ')' '{' body '}' else  */
#line 113 "parser.y"
                                                      { struct node *iff = mknode((yyvsp[-5].treeNode).nd, (yyvsp[-2].treeNode).nd, (yyvsp[-8].treeNode).name); (yyval.treeNode).nd = mknode(iff, (yyvsp[0].treeNode).nd, "conditionalBranch"); }
#line 1833 "y.tab.c"
    break;

  case 21: /* block: statement ';'  */
#line 114 "parser.y"
                { (yyval.treeNode).nd = (yyvsp[-1].treeNode).nd; }
#line 1839 "y.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 115 "parser.y"
             { add('K');}
#line 1845 "y.tab.c"
    break;

  case 23: /* block: CONSOLELOG $@3 '(' console_outputs ')' ';'  */
#line 115 "parser.y"
                                                      { struct node *data = mknode(NULL, NULL, (yyvsp[-2].treeNode).name); (yyval.treeNode).nd = mknode(NULL, data, "ConsoleLog"); }
#line 1851 "y.tab.c"
    break;

  case 24: /* console_outputs: STRINGVALUE  */
#line 118 "parser.y"
                             { add('C');}
#line 1857 "y.tab.c"
    break;

  case 25: /* console_outputs: IDENTIFIER  */
#line 119 "parser.y"
                             { check_declaration((yyvsp[0].treeNode).name);}
#line 1863 "y.tab.c"
    break;

  case 27: /* $@4: %empty  */
#line 124 "parser.y"
                   { add('F'); }
#line 1869 "y.tab.c"
    break;

  case 28: /* $@5: %empty  */
#line 124 "parser.y"
                                            { add('I'); }
#line 1875 "y.tab.c"
    break;

  case 29: /* function: FUNCTION $@4 IDENTIFIER $@5 '(' parameterList ')' '{' body return '}'  */
#line 124 "parser.y"
                                                                                                    {  (yyvsp[-2].treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-1].treeNode).nd, "FunctionBody"); struct node *main = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-5].treeNode).nd, (yyvsp[-8].treeNode).name); (yyval.treeNode2).nd = mknode((yyvsp[-10].treeNode).nd, main, "Function"); }
#line 1881 "y.tab.c"
    break;

  case 30: /* parameterList: parameter ',' parameterList  */
#line 127 "parser.y"
                                           { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "ParameterList"); }
#line 1887 "y.tab.c"
    break;

  case 31: /* parameterList: parameter  */
#line 128 "parser.y"
            { (yyval.treeNode).nd = (yyvsp[0].treeNode).nd; }
#line 1893 "y.tab.c"
    break;

  case 32: /* parameterList: %empty  */
#line 129 "parser.y"
  { (yyval.treeNode).nd = (yyval.treeNode).nd = mknode(NULL, NULL, "Parameter"); }
#line 1899 "y.tab.c"
    break;

  case 33: /* $@6: %empty  */
#line 132 "parser.y"
                      { add('I');}
#line 1905 "y.tab.c"
    break;

  case 34: /* parameter: IDENTIFIER $@6 ':' datatype  */
#line 132 "parser.y"
                                                {(yyvsp[0].treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); (yyvsp[-3].treeNode).nd = mknode(NULL, NULL, (yyvsp[-3].treeNode).name); (yyval.treeNode).nd = mknode((yyvsp[0].treeNode).nd, (yyvsp[-3].treeNode).nd, "Parameter");}
#line 1911 "y.tab.c"
    break;

  case 35: /* datatype: NUMBERTYPE  */
#line 136 "parser.y"
                     { insert_type(); }
#line 1917 "y.tab.c"
    break;

  case 36: /* datatype: STRINGTYPE  */
#line 137 "parser.y"
             { insert_type(); }
#line 1923 "y.tab.c"
    break;

  case 37: /* datatype: BOOLEANTYPE  */
#line 138 "parser.y"
              { insert_type(); }
#line 1929 "y.tab.c"
    break;

  case 38: /* $@7: %empty  */
#line 143 "parser.y"
           { add('K');}
#line 1935 "y.tab.c"
    break;

  case 39: /* else: ELSE $@7 '{' body '}'  */
#line 143 "parser.y"
                                     {  struct node *cond = mknode(NULL, NULL, "EndOfConditional"); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, cond, (yyvsp[-4].treeNode).name); }
#line 1941 "y.tab.c"
    break;

  case 40: /* else: %empty  */
#line 144 "parser.y"
  { (yyval.treeNode).nd = NULL; }
#line 1947 "y.tab.c"
    break;

  case 41: /* condition: condition and_or condition  */
#line 147 "parser.y"
                                      { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, (yyvsp[-1].treeNode).name); }
#line 1953 "y.tab.c"
    break;

  case 42: /* condition: value relop value  */
#line 148 "parser.y"
                    { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name);}
#line 1959 "y.tab.c"
    break;

  case 43: /* condition: value  */
#line 149 "parser.y"
        { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd;}
#line 1965 "y.tab.c"
    break;

  case 44: /* $@8: %empty  */
#line 150 "parser.y"
       { add('K');}
#line 1971 "y.tab.c"
    break;

  case 45: /* condition: TRUE $@8  */
#line 150 "parser.y"
                    {(yyval.treeNode).nd = NULL; }
#line 1977 "y.tab.c"
    break;

  case 46: /* $@9: %empty  */
#line 151 "parser.y"
        { add('K');}
#line 1983 "y.tab.c"
    break;

  case 47: /* condition: FALSE $@9  */
#line 151 "parser.y"
                     {(yyval.treeNode).nd = NULL; }
#line 1989 "y.tab.c"
    break;

  case 48: /* $@10: %empty  */
#line 154 "parser.y"
                                  { add('I');}
#line 1995 "y.tab.c"
    break;

  case 49: /* statement: declaration IDENTIFIER $@10 ':' datatype init  */
#line 154 "parser.y"
                                                                 {
    (yyvsp[-1].treeNode).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name); //making for datatype
	(yyvsp[-4].treeNode).nd = mknode(NULL, NULL, (yyvsp[-4].treeNode).name); //making for identifier
	(yyvsp[-5].treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[-4].treeNode).nd, (yyvsp[-5].treeNode).name); //making for the declaration
	int t = check_types((yyvsp[-1].treeNode).name, (yyvsp[0].treeNode2).type); //here we're checking types
	// printf("%s\n", $5.name);
	// printf("%s\n", $6.type);
	// printf("%d\n", t);
	if(t>0) {
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
	} 
	else {
		(yyval.treeNode).nd = mknode((yyvsp[-4].treeNode).nd, (yyvsp[0].treeNode2).nd, "Initialisation");
		
	}
		
	}
#line 2017 "y.tab.c"
    break;

  case 50: /* $@11: %empty  */
#line 171 "parser.y"
             {  }
#line 2023 "y.tab.c"
    break;

  case 51: /* statement: IDENTIFIER $@11 '=' expression  */
#line 171 "parser.y"
                                 { 
	if(check_declaration((yyvsp[-3].treeNode).name)){
		(yyvsp[-3].treeNode).nd = mknode(NULL, NULL, (yyvsp[-3].treeNode).name);  
		char *id_type = get_type((yyvsp[-3].treeNode).name); 
		if(strcmp(id_type, (yyvsp[0].treeNode2).type)) {
			sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;	
		}
		else {
			(yyval.treeNode).nd = mknode((yyvsp[-3].treeNode).nd, (yyvsp[0].treeNode2).nd, "="); 
		}
	}
	
	}
#line 2041 "y.tab.c"
    break;

  case 52: /* $@12: %empty  */
#line 184 "parser.y"
             { check_declaration((yyvsp[0].treeNode).name); }
#line 2047 "y.tab.c"
    break;

  case 53: /* statement: IDENTIFIER $@12 relop expression  */
#line 184 "parser.y"
                                                              { (yyvsp[-3].treeNode).nd = mknode(NULL, NULL, (yyvsp[-3].treeNode).name); (yyval.treeNode).nd = mknode((yyvsp[-3].treeNode).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name ); }
#line 2053 "y.tab.c"
    break;

  case 54: /* declaration: LET  */
#line 187 "parser.y"
                 { add('K');}
#line 2059 "y.tab.c"
    break;

  case 55: /* declaration: VAR  */
#line 188 "parser.y"
      { add('K');}
#line 2065 "y.tab.c"
    break;

  case 56: /* declaration: CONST  */
#line 189 "parser.y"
        { add('K');}
#line 2071 "y.tab.c"
    break;

  case 57: /* init: '=' value  */
#line 192 "parser.y"
                { (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); }
#line 2077 "y.tab.c"
    break;

  case 58: /* init: '=' expression  */
#line 193 "parser.y"
                 { (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); }
#line 2083 "y.tab.c"
    break;

  case 59: /* init: %empty  */
#line 194 "parser.y"
  { sprintf((yyval.treeNode2).type, "%s", "null"); (yyval.treeNode2).nd = mknode(NULL, NULL, "NULL"); strcpy((yyval.treeNode2).name, "NULL"); }
#line 2089 "y.tab.c"
    break;

  case 60: /* expression: expression addops term  */
#line 198 "parser.y"
                                    { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);
	} 
	else {
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name);
	}
}
#line 2102 "y.tab.c"
    break;

  case 61: /* expression: term  */
#line 206 "parser.y"
       { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2108 "y.tab.c"
    break;

  case 62: /* term: term mulops factor  */
#line 209 "parser.y"
                          { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
	} 
	else {
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name);
	}

	}
#line 2122 "y.tab.c"
    break;

  case 63: /* term: factor  */
#line 218 "parser.y"
         { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2128 "y.tab.c"
    break;

  case 64: /* factor: base exponent base  */
#line 221 "parser.y"
                            { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
	} 
	else {
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode2).name);
	}
	}
#line 2141 "y.tab.c"
    break;

  case 65: /* factor: LOG '(' value ',' value ')'  */
#line 229 "parser.y"
                              {(yyval.treeNode2).nd = mknode((yyvsp[-3].treeNode2).nd, (yyvsp[-1].treeNode2).nd, (yyvsp[-5].treeNode).name); }
#line 2147 "y.tab.c"
    break;

  case 66: /* factor: base  */
#line 230 "parser.y"
       { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2153 "y.tab.c"
    break;

  case 67: /* base: value  */
#line 233 "parser.y"
              { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; }
#line 2159 "y.tab.c"
    break;

  case 68: /* base: '(' expression ')'  */
#line 234 "parser.y"
                      { strcpy((yyval.treeNode2).name, (yyvsp[-1].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[-1].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[-1].treeNode2).nd; }
#line 2165 "y.tab.c"
    break;

  case 69: /* and_or: AND  */
#line 237 "parser.y"
             { (yyval.treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2171 "y.tab.c"
    break;

  case 70: /* and_or: OR  */
#line 238 "parser.y"
     { (yyval.treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2177 "y.tab.c"
    break;

  case 82: /* number: INTEGER  */
#line 260 "parser.y"
                { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "%s", "number"); add('C'); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2183 "y.tab.c"
    break;

  case 83: /* number: FLOAT  */
#line 261 "parser.y"
        { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "%s", "number"); add('C'); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2189 "y.tab.c"
    break;

  case 84: /* value: number  */
#line 264 "parser.y"
              {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name);}
#line 2195 "y.tab.c"
    break;

  case 85: /* value: IDENTIFIER  */
#line 265 "parser.y"
             { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); char *id_type = get_type((yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "%s", id_type); check_declaration((yyvsp[0].treeNode).name); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2201 "y.tab.c"
    break;

  case 86: /* value: STRINGVALUE  */
#line 266 "parser.y"
              { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "string"); add('C'); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name); }
#line 2207 "y.tab.c"
    break;

  case 87: /* $@13: %empty  */
#line 267 "parser.y"
       { add('K');}
#line 2213 "y.tab.c"
    break;

  case 88: /* value: TRUE $@13  */
#line 267 "parser.y"
                    {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name);}
#line 2219 "y.tab.c"
    break;

  case 89: /* $@14: %empty  */
#line 268 "parser.y"
        { add('K');}
#line 2225 "y.tab.c"
    break;

  case 90: /* value: FALSE $@14  */
#line 268 "parser.y"
                     {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name);}
#line 2231 "y.tab.c"
    break;

  case 91: /* $@15: %empty  */
#line 269 "parser.y"
       { add('K');}
#line 2237 "y.tab.c"
    break;

  case 92: /* value: SCAN $@15 '(' ')'  */
#line 269 "parser.y"
                           { (yyval.treeNode2).nd = mknode(NULL, NULL, "scan"); }
#line 2243 "y.tab.c"
    break;

  case 93: /* $@16: %empty  */
#line 273 "parser.y"
               { add('K');}
#line 2249 "y.tab.c"
    break;

  case 94: /* return: RETURN $@16 value ';'  */
#line 273 "parser.y"
                                       { (yyvsp[-3].treeNode).nd = mknode(NULL, NULL, "return"); (yyval.treeNode).nd = mknode((yyvsp[-3].treeNode).nd, (yyvsp[-1].treeNode2).nd, "ReturnStatement"); }
#line 2255 "y.tab.c"
    break;

  case 95: /* return: %empty  */
#line 275 "parser.y"
  { (yyval.treeNode).nd = NULL; }
#line 2261 "y.tab.c"
    break;


#line 2265 "y.tab.c"

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

#line 279 "parser.y"



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
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))
		return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))
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
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword\n", countn+1, yytext);
				sem_errors++;
				return;
			}
		}
	}
    q=search(yytext);
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
			symbol_table[count].id_name=strdup(yytext);
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
    }
    else if(c == 'I' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed\n", countn+1, yytext);
		sem_errors++;
    }
}



void insert_type() {
	strcpy(type, yytext);
}
