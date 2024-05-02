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
    #include <math.h>
    #include "lex.yy.c"

    #define BOLDRED "\033[1m\033[31m"
    #define BOLDBLUE "\033[1m\033[34m"
    #define BOLDCYAN "\033[1m\033[36m"
    #define BOLDYELLOW "\033[1m\033[33m"
    #define BOLDMAGENTA "\033[1m\033[35m"
    #define BOLDGREEN "\033[1m\033[32m"
    #define RESET "\033[0m"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();
    float get_value(char *var);
    void set_value(char *var, float value);

    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token;
        float value;
    };
    
    struct node* mknode(struct node *left, struct node *right, char *token, float value);
    void printBT(struct node*);

    struct dataType {
        char *id_name;
        char *data_type;
        char *type;
        int   line_no;
        float  value;
    } symbol_table[100];

    char type[100]; // Added declaration for type
	char id_name[100];
    int count = 0; // Added declaration for count
    int q; // Added declaration for q
    int sem_errors = 0;

    int label = 0;
	int ic_idx = 0;
    int param_idx = 0;
	int temp_var = 0;
	int is_loop = 0;
	int is_array = 0;
	int temp_arr = 0;

    char buff[400];
    char errors[10][100];
    char reserved[10][20] = {"number", "import", "async", "string", "void", "if", "else", "for", "while", "return"};
    char icg[100][200];

    void insert_type();
	void store_name();
    void add(char c);
    int search(char *);

    void printBTHelper(char* prefix, struct node* ptr, int isLeft);
    void printBT(struct node* ptr);
    void printSymbolTable();
	void printSemanticErrors();
	void printIntermediateCode();

    int check_declaration(char *);
    void check_return_type(char *);
    int check_types(char *, char *);
    char *get_type(char *);
	void insert_type();
    
    extern int countn;

#line 151 "y.tab.c"

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
    NUMBERARRAYTYPE = 289,         /* NUMBERARRAYTYPE  */
    STRINGARRAYTYPE = 290,         /* STRINGARRAYTYPE  */
    BOOLEANARRAYTYPE = 291,        /* BOOLEANARRAYTYPE  */
    FUNCTION = 292,                /* FUNCTION  */
    INTEGER = 293,                 /* INTEGER  */
    FLOAT = 294,                   /* FLOAT  */
    STRINGVALUE = 295,             /* STRINGVALUE  */
    INC = 296,                     /* INC  */
    DEC = 297,                     /* DEC  */
    FOR = 298,                     /* FOR  */
    POW = 299,                     /* POW  */
    IDENTIFIER = 300               /* IDENTIFIER  */
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
#define NUMBERARRAYTYPE 289
#define STRINGARRAYTYPE 290
#define BOOLEANARRAYTYPE 291
#define FUNCTION 292
#define INTEGER 293
#define FLOAT 294
#define STRINGVALUE 295
#define INC 296
#define DEC 297
#define FOR 298
#define POW 299
#define IDENTIFIER 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 82 "parser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
        float value;
	} treeNode; 

    struct var_name2 {
        char name[100];
        struct node* nd;
        int temp_arr;
        char type[10];
        float value;
    } treeNode2;

	struct var_name3 {
		char name[100];
        char type[10];
        int temp_arr;
		struct node* nd;
		char if_body[5];
		char else_body[5];
		char after_else_body[5];
        float value;
        int tlist[10];
        int tlistsize;
        int flistsize;
        int flist[10];
        int label_for_while_start;
	} treeNode3;

	struct var_name4 { 
        int next_quad;
	} treeNode4; 

#line 330 "y.tab.c"

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
  YYSYMBOL_NUMBERARRAYTYPE = 34,           /* NUMBERARRAYTYPE  */
  YYSYMBOL_STRINGARRAYTYPE = 35,           /* STRINGARRAYTYPE  */
  YYSYMBOL_BOOLEANARRAYTYPE = 36,          /* BOOLEANARRAYTYPE  */
  YYSYMBOL_FUNCTION = 37,                  /* FUNCTION  */
  YYSYMBOL_INTEGER = 38,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 39,                     /* FLOAT  */
  YYSYMBOL_STRINGVALUE = 40,               /* STRINGVALUE  */
  YYSYMBOL_INC = 41,                       /* INC  */
  YYSYMBOL_DEC = 42,                       /* DEC  */
  YYSYMBOL_FOR = 43,                       /* FOR  */
  YYSYMBOL_POW = 44,                       /* POW  */
  YYSYMBOL_IDENTIFIER = 45,                /* IDENTIFIER  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_main = 57,                      /* main  */
  YYSYMBOL_importList = 58,                /* importList  */
  YYSYMBOL_imports = 59,                   /* imports  */
  YYSYMBOL_moduleList = 60,                /* moduleList  */
  YYSYMBOL_modules = 61,                   /* modules  */
  YYSYMBOL_body = 62,                      /* body  */
  YYSYMBOL_block = 63,                     /* block  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_65_2 = 65,                      /* $@2  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_67_4 = 67,                      /* $@4  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_console_outputs = 72,           /* console_outputs  */
  YYSYMBOL_function = 73,                  /* function  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_procedure = 76,                 /* procedure  */
  YYSYMBOL_argumentList = 77,              /* argumentList  */
  YYSYMBOL_argument = 78,                  /* argument  */
  YYSYMBOL_79_11 = 79,                     /* $@11  */
  YYSYMBOL_parameterList = 80,             /* parameterList  */
  YYSYMBOL_parameter = 81,                 /* parameter  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
  YYSYMBOL_datatype = 84,                  /* datatype  */
  YYSYMBOL_else = 85,                      /* else  */
  YYSYMBOL_86_14 = 86,                     /* $@14  */
  YYSYMBOL_M = 87,                         /* M  */
  YYSYMBOL_condition = 88,                 /* condition  */
  YYSYMBOL_89_15 = 89,                     /* $@15  */
  YYSYMBOL_90_16 = 90,                     /* $@16  */
  YYSYMBOL_statement = 91,                 /* statement  */
  YYSYMBOL_92_17 = 92,                     /* $@17  */
  YYSYMBOL_93_18 = 93,                     /* $@18  */
  YYSYMBOL_assign = 94,                    /* assign  */
  YYSYMBOL_declaration = 95,               /* declaration  */
  YYSYMBOL_init = 96,                      /* init  */
  YYSYMBOL_list = 97,                      /* list  */
  YYSYMBOL_integerList = 98,               /* integerList  */
  YYSYMBOL_expression = 99,                /* expression  */
  YYSYMBOL_term = 100,                     /* term  */
  YYSYMBOL_factor = 101,                   /* factor  */
  YYSYMBOL_base = 102,                     /* base  */
  YYSYMBOL_exponent = 103,                 /* exponent  */
  YYSYMBOL_mulops = 104,                   /* mulops  */
  YYSYMBOL_addops = 105,                   /* addops  */
  YYSYMBOL_relop = 106,                    /* relop  */
  YYSYMBOL_number = 107,                   /* number  */
  YYSYMBOL_value = 108,                    /* value  */
  YYSYMBOL_109_19 = 109,                   /* $@19  */
  YYSYMBOL_110_20 = 110,                   /* $@20  */
  YYSYMBOL_111_21 = 111,                   /* $@21  */
  YYSYMBOL_array = 112,                    /* array  */
  YYSYMBOL_return = 113,                   /* return  */
  YYSYMBOL_114_22 = 114                    /* $@22  */
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
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  233

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      50,    51,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    48,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   132,   133,   134,   138,   139,   140,   141,
     145,   146,   150,   151,   155,   156,   160,   161,   162,   162,
     162,   185,   185,   185,   210,   210,   220,   210,   238,   239,
     239,   243,   244,   245,   249,   249,   249,   256,   259,   260,
     261,   264,   264,   265,   268,   269,   270,   274,   274,   274,
     278,   279,   280,   281,   282,   283,   287,   287,   288,   292,
     302,   325,   348,   385,   397,   398,   398,   399,   399,   403,
     403,   403,   447,   496,   501,   506,   542,   554,   565,   576,
     589,   593,   597,   600,   601,   602,   606,   607,   608,   612,
     616,   619,   622,   623,   631,   672,   676,   717,   721,   762,
     763,   767,   768,   777,   781,   782,   786,   787,   791,   792,
     793,   794,   795,   796,   800,   807,   817,   818,   830,   831,
     831,   832,   832,   833,   833,   834,   837,   850,   850,   857
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
  "STRINGTYPE", "BOOLEANTYPE", "NUMBERARRAYTYPE", "STRINGARRAYTYPE",
  "BOOLEANARRAYTYPE", "FUNCTION", "INTEGER", "FLOAT", "STRINGVALUE", "INC",
  "DEC", "FOR", "POW", "IDENTIFIER", "'{'", "'}'", "';'", "','", "'('",
  "')'", "':'", "'='", "'['", "']'", "$accept", "main", "importList",
  "imports", "moduleList", "modules", "body", "block", "$@1", "$@2", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "console_outputs", "function", "$@9",
  "$@10", "procedure", "argumentList", "argument", "$@11", "parameterList",
  "parameter", "$@12", "$@13", "datatype", "else", "$@14", "M",
  "condition", "$@15", "$@16", "statement", "$@17", "$@18", "assign",
  "declaration", "init", "list", "integerList", "expression", "term",
  "factor", "base", "exponent", "mulops", "addops", "relop", "number",
  "value", "$@19", "$@20", "$@21", "array", "return", "$@22", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,    10,    35,   199,    22,   -99,   -99,    -5,     1,    40,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    18,    32,
     -99,   130,   -99,   199,   -99,   -99,    33,    56,    42,   -99,
     -33,    66,    53,    -5,    69,    83,    94,    95,   103,   -99,
     -99,   100,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
      97,    44,    78,    78,   -99,   -99,   -99,    78,   136,   155,
     113,   116,   -99,   166,   119,   159,   159,   -99,    16,   -99,
     -99,   -99,   -99,   -99,   -99,   120,   125,   128,   -99,   -99,
     -99,   135,   -18,    78,   -99,   -99,    17,    50,   -99,   134,
     -99,    19,   120,     7,    17,   139,    17,    48,   148,   147,
     -99,   153,   144,    61,   149,    17,    81,    90,   159,    58,
     246,   186,   138,   167,   235,   170,   169,   -99,   -99,   -99,
     178,    97,   183,    -9,   -99,   -99,    78,   -99,   -99,    78,
     -99,    52,   -99,   250,   179,   225,   182,   184,   -99,   -99,
     173,   229,   -99,   -99,   -99,    78,   -99,   188,   159,   180,
     -99,   -99,   189,   -99,    50,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   195,   -99,   -99,   -99,   159,
     159,   193,    17,   197,   -99,   196,   200,    46,   -99,   183,
     211,   217,    46,    46,   199,   199,   214,   202,   188,   226,
     222,    -1,   -99,   -99,   228,   231,   250,   199,   -99,    16,
     -99,   241,   -99,    17,    79,   -99,   -99,   -99,   276,   239,
     242,   237,   283,   -99,   -99,   247,   249,   241,   -99,   -99,
     -99,   183,   -99,   199,   -99,   251,   248,   252,   199,   -99,
     -99,   253,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    15,     4,    13,    12,     0,     0,    11,
       1,    29,    24,    18,    83,    84,    85,    34,     0,     0,
      21,     0,     2,    15,    16,    17,     0,     0,     0,     3,
       0,    11,     0,     0,     0,     0,     0,     0,     0,    78,
      79,     0,   111,   110,   109,   108,   112,   113,    76,    77,
      40,     0,     0,     0,    14,    28,    69,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    35,     0,   123,
     119,   121,   114,   115,   118,    41,     0,    39,   116,    43,
     125,     0,   117,     0,    82,    72,    80,    95,    97,   100,
     101,   125,   117,     0,    75,     0,    73,   125,     0,     0,
       8,     0,   118,   117,     0,    33,   119,   121,     0,     0,
       0,   101,     0,     0,     0,     0,     0,   120,   122,    42,
       0,    40,     0,     0,   106,   107,     0,   104,   105,     0,
     103,     0,   126,     0,     0,     0,     0,     0,    66,    68,
       0,     0,    59,    59,    25,     0,    19,    46,     0,     0,
      37,    38,     0,   102,    94,    96,    98,    50,    51,    52,
      53,    54,    55,    70,     6,     0,     9,    30,    63,     0,
       0,     0,    62,     0,    47,     0,    45,    22,   124,     0,
      89,     0,    60,    61,    15,    15,     0,     0,    46,     0,
       0,    91,    71,     7,     0,     0,     0,    15,    44,     0,
      99,     0,    88,    87,   101,    26,    20,    48,   129,     0,
      93,     0,    58,    49,   127,     0,     0,     0,    90,    56,
      27,     0,    36,    15,    92,     0,     0,     0,    15,   128,
      23,     0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   294,   -99,    14,    45,   -22,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     254,   181,   -99,   -99,   115,   -99,   -99,   -99,   105,   -99,
     -99,   161,   -62,   -99,   -99,   -65,   -99,   -99,   -99,   -99,
     -99,   -99,    89,   -42,   185,   187,   176,   -99,   -99,   -99,
     -98,   -99,   -48,   -99,   -99,   -99,    -3,   -99,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     8,     9,    22,    23,    37,   173,
      41,   189,    36,   171,   212,    35,   104,    24,    38,   113,
      25,    76,    77,   119,   175,   176,   186,   213,   163,   220,
     225,   169,   109,   138,   139,    26,    95,   180,    85,    27,
     192,   202,   211,   110,    87,    88,    89,   131,   129,   126,
      53,    78,    90,   117,   118,   116,    80,   215,   221
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    54,    79,   115,   112,    32,    69,   124,   125,    86,
      93,    94,   145,     5,    58,    96,    33,   111,   111,    81,
      28,    30,   105,   124,   125,     1,    70,    71,     5,    14,
      15,    16,    50,   124,   125,    10,    52,    72,    73,    74,
       6,   123,   153,   145,    92,    34,   140,    61,    91,    83,
      33,    69,    31,   201,    97,     6,     7,    18,    19,    69,
     111,   114,   132,    39,    81,    28,   141,   -81,   127,   128,
     -81,    70,    71,    79,   152,   142,   143,    40,    62,    70,
      71,    55,    72,    73,    74,    69,   177,   142,   143,    82,
      72,    73,    74,    60,    83,    57,   -74,    92,    81,   -74,
     111,    56,    83,   172,    69,    70,    71,   182,   183,   144,
     -65,   -65,   -32,    59,    63,    52,    72,    73,    74,   -67,
     -67,   111,   111,    92,    70,    71,    69,   -86,    83,   -65,
     -86,   190,   -65,    64,   209,    72,    73,    74,   -67,    81,
      98,   -67,    75,   204,    65,    66,    70,    71,    67,   203,
      68,    42,    43,    44,    45,    46,    47,    72,    73,   102,
      99,   100,   194,   195,   103,    33,    69,   142,   143,    83,
     101,    48,    49,   226,    52,   208,   120,   121,   130,    81,
      50,    28,    28,    51,    52,   122,   106,   107,   134,   146,
      69,   133,   135,   136,    28,   -31,    28,    72,    73,    74,
     137,   227,   142,   143,    92,    11,   231,    12,    13,   108,
      70,    71,    14,    15,    16,   -64,   -64,   147,   148,   149,
      28,    72,    73,    74,   168,    28,   150,   164,    92,   165,
     166,   178,   167,   174,   -64,   181,    17,   -64,   179,   184,
      18,    19,    20,   185,    21,   124,   125,   187,   197,   188,
      42,    43,    44,    45,    46,    47,    42,    43,    44,    45,
      46,    47,   124,   125,   191,   193,   196,    42,    43,    44,
      45,    46,    47,   200,   199,   205,    48,    49,   206,   210,
     153,   157,   158,   159,   160,   161,   162,   214,    51,    52,
     216,   217,   218,   219,   222,   223,   229,   228,    29,   230,
     232,   207,   151,   198,   170,    84,   224,   156,     0,     0,
       0,   154,     0,     0,     0,     0,   155
};

static const yytype_int16 yycheck[] =
{
       3,    23,    50,    68,    66,     4,     7,    16,    17,    51,
      52,    53,   110,    18,    47,    57,    49,    65,    66,    20,
      23,     7,    64,    16,    17,     3,    27,    28,    18,    13,
      14,    15,    50,    16,    17,     0,    54,    38,    39,    40,
      45,    83,    51,   141,    45,     5,   108,    33,    51,    50,
      49,     7,     7,    54,    57,    45,    46,    41,    42,     7,
     108,    45,    55,    45,    20,    68,   108,    48,    18,    19,
      51,    27,    28,   121,   122,    29,    30,    45,    33,    27,
      28,    48,    38,    39,    40,     7,   148,    29,    30,    45,
      38,    39,    40,    40,    50,    53,    48,    45,    20,    51,
     148,    45,    50,   145,     7,    27,    28,   169,   170,    51,
      29,    30,    51,    47,    45,    54,    38,    39,    40,    29,
      30,   169,   170,    45,    27,    28,     7,    48,    50,    48,
      51,   179,    51,    50,   199,    38,    39,    40,    48,    20,
       4,    51,    45,   191,    50,    50,    27,    28,    45,   191,
      50,    21,    22,    23,    24,    25,    26,    38,    39,    40,
       5,    48,   184,   185,    45,    49,     7,    29,    30,    50,
       4,    41,    42,   221,    54,   197,    51,    49,    44,    20,
      50,   184,   185,    53,    54,    50,    27,    28,    40,    51,
       7,    52,    45,    40,   197,    51,   199,    38,    39,    40,
      51,   223,    29,    30,    45,     6,   228,     8,     9,    50,
      27,    28,    13,    14,    15,    29,    30,    50,    48,    50,
     223,    38,    39,    40,    51,   228,    48,    48,    45,     4,
      48,    51,    48,    45,    48,    40,    37,    51,    49,    46,
      41,    42,    43,    46,    45,    16,    17,    51,    46,    49,
      21,    22,    23,    24,    25,    26,    21,    22,    23,    24,
      25,    26,    16,    17,    53,    48,    52,    21,    22,    23,
      24,    25,    26,    51,    48,    47,    41,    42,    47,    38,
      51,    31,    32,    33,    34,    35,    36,    11,    53,    54,
      51,    49,    55,    10,    47,    46,    48,    46,     4,    47,
      47,   196,   121,   188,   143,    51,   217,   131,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,   129
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    57,    58,    59,    18,    45,    46,    60,    61,
       0,     6,     8,     9,    13,    14,    15,    37,    41,    42,
      43,    45,    62,    63,    73,    76,    91,    95,   112,    58,
      60,    61,     4,    49,     5,    71,    68,    64,    74,    45,
      45,    66,    21,    22,    23,    24,    25,    26,    41,    42,
      50,    53,    54,   106,    62,    48,    45,    53,    47,    47,
      40,    60,    61,    45,    50,    50,    50,    45,    50,     7,
      27,    28,    38,    39,    40,    45,    77,    78,   107,   108,
     112,    20,    45,    50,    76,    94,    99,   100,   101,   102,
     108,   112,    45,    99,    99,    92,    99,   112,     4,     5,
      48,     4,    40,    45,    72,    99,    27,    28,    50,    88,
      99,   108,    88,    75,    45,    91,   111,   109,   110,    79,
      51,    49,    50,    99,    16,    17,   105,    18,    19,   104,
      44,   103,    55,    52,    40,    45,    40,    51,    89,    90,
      88,    99,    29,    30,    51,   106,    51,    50,    48,    50,
      48,    77,   108,    51,   100,   101,   102,    31,    32,    33,
      34,    35,    36,    84,    48,     4,    48,    48,    51,    87,
      87,    69,    99,    65,    45,    80,    81,    88,    51,    49,
      93,    40,    88,    88,    46,    46,    82,    51,    49,    67,
     108,    53,    96,    48,    62,    62,    52,    46,    80,    48,
      51,    54,    97,    99,   108,    47,    47,    84,    62,    91,
      38,    98,    70,    83,    11,   113,    51,    49,    55,    10,
      85,   114,    47,    46,    98,    86,   108,    62,    46,    48,
      47,    62,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    65,
      63,    66,    67,    63,    68,    69,    70,    63,    63,    71,
      63,    72,    72,    72,    74,    75,    73,    76,    77,    77,
      77,    79,    78,    78,    80,    80,    80,    82,    83,    81,
      84,    84,    84,    84,    84,    84,    86,    85,    85,    87,
      88,    88,    88,    88,    88,    89,    88,    90,    88,    92,
      93,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      94,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   102,   102,   103,   104,   104,   105,   105,   106,   106,
     106,   106,   106,   106,   107,   107,   108,   108,   108,   109,
     108,   110,   108,   111,   108,   108,   112,   114,   113,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     7,     9,     5,     7,
       3,     1,     1,     1,     2,     0,     1,     1,     0,     0,
       9,     0,     0,    13,     0,     0,     0,    11,     2,     0,
       6,     1,     1,     1,     0,     0,    11,     5,     3,     1,
       0,     0,     2,     1,     3,     1,     0,     0,     0,     5,
       1,     1,     1,     1,     1,     1,     0,     5,     0,     0,
       4,     4,     3,     3,     1,     0,     2,     0,     2,     0,
       0,     7,     3,     3,     3,     3,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     0,
       3,     0,     3,     1,     3,     1,     3,     1,     3,     6,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     2,     0,     4,     1,     4,     0,     4,     0
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
#line 128 "parser.y"
                      { (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "Program", 0); head = (yyval.treeNode).nd; }
#line 1875 "y.tab.c"
    break;

  case 3: /* importList: imports importList  */
#line 132 "parser.y"
                               { (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "ImportList", 0); }
#line 1881 "y.tab.c"
    break;

  case 4: /* importList: imports  */
#line 133 "parser.y"
          { (yyval.treeNode).nd = mknode(NULL, (yyvsp[0].treeNode).nd, "ImportList", 0); }
#line 1887 "y.tab.c"
    break;

  case 5: /* importList: %empty  */
#line 134 "parser.y"
  { (yyval.treeNode).nd = mknode(NULL, NULL, "ImportList", 0); }
#line 1893 "y.tab.c"
    break;

  case 6: /* imports: IMPORT '{' moduleList '}' FROM STRINGVALUE ';'  */
#line 138 "parser.y"
                                                        { (yyval.treeNode).nd = (yyvsp[-4].treeNode).nd; }
#line 1899 "y.tab.c"
    break;

  case 7: /* imports: IMPORT '{' modules '}' AS IDENTIFIER FROM STRINGVALUE ';'  */
#line 139 "parser.y"
                                                            { (yyval.treeNode).nd = (yyvsp[-6].treeNode).nd; }
#line 1905 "y.tab.c"
    break;

  case 8: /* imports: IMPORT moduleList FROM STRINGVALUE ';'  */
#line 140 "parser.y"
                                         { (yyval.treeNode).nd = (yyvsp[-3].treeNode).nd; }
#line 1911 "y.tab.c"
    break;

  case 9: /* imports: IMPORT modules AS IDENTIFIER FROM STRINGVALUE ';'  */
#line 141 "parser.y"
                                                    { (yyval.treeNode).nd = (yyvsp[-5].treeNode).nd; }
#line 1917 "y.tab.c"
    break;

  case 10: /* moduleList: moduleList ',' moduleList  */
#line 145 "parser.y"
                                      { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "ModuleList", 0); }
#line 1923 "y.tab.c"
    break;

  case 11: /* moduleList: modules  */
#line 146 "parser.y"
          { (yyval.treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name, 0); }
#line 1929 "y.tab.c"
    break;

  case 14: /* body: block body  */
#line 155 "parser.y"
                 {(yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode).nd, "Scope", 0); }
#line 1935 "y.tab.c"
    break;

  case 15: /* body: %empty  */
#line 156 "parser.y"
  { (yyval.treeNode).nd = mknode(NULL, NULL, "EndOfScope", 0); }
#line 1941 "y.tab.c"
    break;

  case 16: /* block: function  */
#line 160 "parser.y"
                { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd; }
#line 1947 "y.tab.c"
    break;

  case 17: /* block: procedure  */
#line 161 "parser.y"
            { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd; }
#line 1953 "y.tab.c"
    break;

  case 18: /* $@1: %empty  */
#line 162 "parser.y"
        { add('K'); is_loop = 1;}
#line 1959 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 162 "parser.y"
                                                    {
    sprintf(icg[ic_idx++], BOLDBLUE);
    sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++);
    sprintf(icg[ic_idx++], BOLDGREEN);
    for(int i = 0; i <(yyvsp[-1].treeNode3).tlistsize; i++){
        char temp[40];
        sprintf(temp, "\033[1m\033[35mGOTO L%d\n\033[1m\033[32m", label - 1);
        strcat(icg[(yyvsp[-1].treeNode3).tlist[i]], temp);
    }
}
#line 1974 "y.tab.c"
    break;

  case 20: /* block: WHILE $@1 '(' condition ')' $@2 '{' body '}'  */
#line 171 "parser.y"
               { 
    (yyval.treeNode).nd = mknode((yyvsp[-5].treeNode3).nd, (yyvsp[-1].treeNode).nd, (yyvsp[-8].treeNode).name, 0);
    sprintf(icg[ic_idx++], BOLDMAGENTA);
    sprintf(icg[ic_idx++], "JUMP TO L%d\n", (yyvsp[-5].treeNode3).label_for_while_start);
    sprintf(icg[ic_idx++], BOLDGREEN);
    for(int i=0;i<(yyvsp[-5].treeNode3).flistsize;i++){
        char temp[40];
        sprintf(temp, "\033[1m\033[35mGOTO L%d\n\033[1m\033[32m", label);
        strcat(icg[(yyvsp[-5].treeNode3).flist[i]], temp);
    }
    sprintf(icg[ic_idx++], BOLDBLUE);
	sprintf(icg[ic_idx++], "\nLABEL L%d:\n",label++);
    sprintf(icg[ic_idx++], BOLDGREEN);
}
#line 1993 "y.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 185 "parser.y"
      { add('K'); is_loop = 1;}
#line 1999 "y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 185 "parser.y"
                                                           {
    sprintf(icg[ic_idx++], BOLDBLUE);
    sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++);
    sprintf(icg[ic_idx++], BOLDGREEN);
    for(int i = 0; i <(yyvsp[0].treeNode3).tlistsize; i++){
        char temp[40];
        sprintf(temp, "\033[1m\033[35mGOTO L%d\n\033[1m\033[32m", label - 1);
        strcat(icg[(yyvsp[0].treeNode3).tlist[i]], temp);
    }
}
#line 2014 "y.tab.c"
    break;

  case 23: /* block: FOR $@3 '(' statement ';' condition $@4 ';' statement ')' '{' body '}'  */
#line 194 "parser.y"
                                 {
	struct node *temp = mknode((yyvsp[-7].treeNode3).nd, (yyvsp[-4].treeNode).nd, "Condition", 0);
    struct node *temp2 = mknode((yyvsp[-9].treeNode).nd, temp, "Initialisation", 0);  
    (yyval.treeNode).nd = mknode(temp2, (yyvsp[-1].treeNode).nd, (yyvsp[-12].treeNode).name, 0);
    sprintf(icg[ic_idx++], BOLDMAGENTA);
    sprintf(icg[ic_idx++], "JUMP TO L%d\n", (yyvsp[-7].treeNode3).label_for_while_start);
    sprintf(icg[ic_idx++], BOLDGREEN);
    for(int i = 0; i < (yyvsp[-7].treeNode3).flistsize; i++){
        char temp[40];
        sprintf(temp, "\033[1m\033[35mGOTO L%d\n\033[1m\033[32m", label);
        strcat(icg[(yyvsp[-7].treeNode3).flist[i]], temp);
    }
    sprintf(icg[ic_idx++], BOLDBLUE);
	sprintf(icg[ic_idx++], "\nLABEL L%d:\n",label++);
    sprintf(icg[ic_idx++], BOLDGREEN);
}
#line 2035 "y.tab.c"
    break;

  case 24: /* $@5: %empty  */
#line 210 "parser.y"
     { add('K'); is_loop = 0;}
#line 2041 "y.tab.c"
    break;

  case 25: /* $@6: %empty  */
#line 210 "parser.y"
                                                  { 
        sprintf(icg[ic_idx++], BOLDBLUE);
        sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++);
        sprintf(icg[ic_idx++], BOLDGREEN);
        for(int i = 0; i < (yyvsp[-1].treeNode3).tlistsize; i++){
            char temp[40];
            sprintf(temp, "\033[1m\033[35mGOTO L%d\n\033[1m\033[32m", label - 1);
            strcat(icg[(yyvsp[-1].treeNode3).tlist[i]], temp);
        }
}
#line 2056 "y.tab.c"
    break;

  case 26: /* $@7: %empty  */
#line 220 "parser.y"
             {
    sprintf(icg[ic_idx++], BOLDMAGENTA);
    sprintf(icg[ic_idx++],"JUMP TO L%d\n", label+1);
    sprintf(icg[ic_idx++], BOLDBLUE);
    sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++);
    sprintf(icg[ic_idx++], BOLDGREEN);
    for(int i=0;i<(yyvsp[-5].treeNode3).flistsize;i++){
        char temp[40];
        sprintf(temp, "\033[1m\033[35mGOTO L%d\n\033[1m\033[32m", label-1);
        sprintf(icg[(yyvsp[-5].treeNode3).flist[i]], temp);
    }
}
#line 2073 "y.tab.c"
    break;

  case 27: /* block: IF $@5 '(' condition ')' $@6 '{' body '}' $@7 else  */
#line 231 "parser.y"
       { 
    struct node *iff = mknode((yyvsp[-7].treeNode3).nd, (yyvsp[-3].treeNode).nd, (yyvsp[-10].treeNode).name,0); 
    (yyval.treeNode).nd = mknode(iff, (yyvsp[0].treeNode).nd, "conditionalBranch",0); 
    sprintf(icg[ic_idx++], BOLDBLUE);
    sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++);
    sprintf(icg[ic_idx++], BOLDGREEN);
}
#line 2085 "y.tab.c"
    break;

  case 28: /* block: statement ';'  */
#line 238 "parser.y"
                { (yyval.treeNode).nd = (yyvsp[-1].treeNode).nd; }
#line 2091 "y.tab.c"
    break;

  case 29: /* $@8: %empty  */
#line 239 "parser.y"
             { add('K');}
#line 2097 "y.tab.c"
    break;

  case 30: /* block: CONSOLELOG $@8 '(' console_outputs ')' ';'  */
#line 239 "parser.y"
                                                      { struct node *data = mknode(NULL, NULL, (yyvsp[-2].treeNode).name, 0); (yyval.treeNode).nd = mknode(NULL, data, "ConsoleLog", 0); }
#line 2103 "y.tab.c"
    break;

  case 31: /* console_outputs: STRINGVALUE  */
#line 243 "parser.y"
                             { add('C');}
#line 2109 "y.tab.c"
    break;

  case 32: /* console_outputs: IDENTIFIER  */
#line 244 "parser.y"
              { check_declaration((yyvsp[0].treeNode2).name);}
#line 2115 "y.tab.c"
    break;

  case 33: /* console_outputs: expression  */
#line 245 "parser.y"
              { (yyval.treeNode).nd = (yyvsp[0].treeNode2).nd; }
#line 2121 "y.tab.c"
    break;

  case 34: /* $@9: %empty  */
#line 249 "parser.y"
                   { add('F'); }
#line 2127 "y.tab.c"
    break;

  case 35: /* $@10: %empty  */
#line 249 "parser.y"
                                            { add('I'); }
#line 2133 "y.tab.c"
    break;

  case 36: /* function: FUNCTION $@9 IDENTIFIER $@10 '(' parameterList ')' '{' body return '}'  */
#line 249 "parser.y"
                                                                                                    {
    (yyvsp[-2].treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-1].treeNode).nd, "FunctionBody", 0);
    struct node *main = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-5].treeNode).nd, (yyvsp[-8].treeNode2).name, 0);
    (yyval.treeNode2).nd = mknode((yyvsp[-10].treeNode).nd, main, "Function", 0);
}
#line 2143 "y.tab.c"
    break;

  case 37: /* procedure: IDENTIFIER '(' argumentList ')' ';'  */
#line 256 "parser.y"
                                               { (yyvsp[-4].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-4].treeNode2).name, 0); (yyval.treeNode2).nd = mknode((yyvsp[-4].treeNode2).nd, (yyvsp[-2].treeNode).nd, "FunctionCall", 0); sprintf(icg[ic_idx++], BOLDYELLOW); sprintf(icg[ic_idx++], "\nFUNCTION CALL %s\n", (yyvsp[-4].treeNode2).name); sprintf(icg[ic_idx++], BOLDGREEN); }
#line 2149 "y.tab.c"
    break;

  case 38: /* argumentList: argument ',' argumentList  */
#line 259 "parser.y"
                                        { check_declaration((yyvsp[-2].treeNode).name); (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "ArgumentList", 0); }
#line 2155 "y.tab.c"
    break;

  case 39: /* argumentList: argument  */
#line 260 "parser.y"
           { check_declaration((yyvsp[0].treeNode).name); (yyval.treeNode).nd = (yyvsp[0].treeNode).nd; }
#line 2161 "y.tab.c"
    break;

  case 40: /* argumentList: %empty  */
#line 261 "parser.y"
  { (yyval.treeNode).nd = (yyval.treeNode).nd = mknode(NULL, NULL, "Argument", 0); }
#line 2167 "y.tab.c"
    break;

  case 41: /* $@11: %empty  */
#line 264 "parser.y"
                     {store_name();}
#line 2173 "y.tab.c"
    break;

  case 42: /* argument: IDENTIFIER $@11  */
#line 264 "parser.y"
                                     { (yyvsp[-1].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode2).name, 0); (yyval.treeNode).nd = mknode(NULL, (yyvsp[-1].treeNode2).nd, "Argument", 0); }
#line 2179 "y.tab.c"
    break;

  case 43: /* argument: value  */
#line 265 "parser.y"
        { (yyvsp[0].treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name, 0); (yyval.treeNode).nd = mknode(NULL, (yyvsp[0].treeNode2).nd, "Argument", 0); }
#line 2185 "y.tab.c"
    break;

  case 44: /* parameterList: parameter ',' parameterList  */
#line 268 "parser.y"
                                           { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "ParameterList", 0); sprintf(icg[ic_idx++], BOLDYELLOW); sprintf(icg[ic_idx++], "PARAM %s\n", (yyvsp[-2].treeNode).name); sprintf(icg[ic_idx++], BOLDGREEN); }
#line 2191 "y.tab.c"
    break;

  case 45: /* parameterList: parameter  */
#line 269 "parser.y"
            { (yyval.treeNode).nd = (yyvsp[0].treeNode).nd; sprintf(icg[ic_idx++], BOLDYELLOW); sprintf(icg[ic_idx++], "\nPARAM %s\n", (yyvsp[0].treeNode).name); sprintf(icg[ic_idx++], BOLDGREEN); }
#line 2197 "y.tab.c"
    break;

  case 46: /* parameterList: %empty  */
#line 270 "parser.y"
  { (yyval.treeNode).nd = (yyval.treeNode).nd = mknode(NULL, NULL, "Parameter", 0); }
#line 2203 "y.tab.c"
    break;

  case 47: /* $@12: %empty  */
#line 274 "parser.y"
                      {store_name();}
#line 2209 "y.tab.c"
    break;

  case 48: /* $@13: %empty  */
#line 274 "parser.y"
                                                   {add('I');}
#line 2215 "y.tab.c"
    break;

  case 49: /* parameter: IDENTIFIER $@12 ':' datatype $@13  */
#line 274 "parser.y"
                                                               {(yyvsp[-1].treeNode).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name, 0); (yyvsp[-4].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-4].treeNode2).name, 0); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[-4].treeNode2).nd, "Parameter", 0);}
#line 2221 "y.tab.c"
    break;

  case 50: /* datatype: NUMBERTYPE  */
#line 278 "parser.y"
                     { insert_type(); }
#line 2227 "y.tab.c"
    break;

  case 51: /* datatype: STRINGTYPE  */
#line 279 "parser.y"
             { insert_type(); }
#line 2233 "y.tab.c"
    break;

  case 52: /* datatype: BOOLEANTYPE  */
#line 280 "parser.y"
              { insert_type(); }
#line 2239 "y.tab.c"
    break;

  case 53: /* datatype: NUMBERARRAYTYPE  */
#line 281 "parser.y"
                  { insert_type(); }
#line 2245 "y.tab.c"
    break;

  case 54: /* datatype: STRINGARRAYTYPE  */
#line 282 "parser.y"
                  { insert_type(); }
#line 2251 "y.tab.c"
    break;

  case 55: /* datatype: BOOLEANARRAYTYPE  */
#line 283 "parser.y"
                   { insert_type(); }
#line 2257 "y.tab.c"
    break;

  case 56: /* $@14: %empty  */
#line 287 "parser.y"
           { add('K');}
#line 2263 "y.tab.c"
    break;

  case 57: /* else: ELSE $@14 '{' body '}'  */
#line 287 "parser.y"
                                     {  struct node *cond = mknode(NULL, NULL, "EndOfConditional", 0); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, cond, (yyvsp[-4].treeNode).name, 0); }
#line 2269 "y.tab.c"
    break;

  case 58: /* else: %empty  */
#line 288 "parser.y"
  { (yyval.treeNode).nd = NULL; }
#line 2275 "y.tab.c"
    break;

  case 59: /* M: %empty  */
#line 292 "parser.y"
   { 
    (yyval.treeNode4).next_quad = ic_idx; 
    char new1[100];
    sprintf(new1, "%d:\033[1m\033[32m", ic_idx);
    char new2[100];
    sprintf(new2, "\033[1m\033[34m\nLABEL S");
    strcat(new2, new1);
    strcpy(icg[ic_idx], new2);
 }
#line 2289 "y.tab.c"
    break;

  case 60: /* condition: condition AND M condition  */
#line 302 "parser.y"
                                     { 
	(yyval.treeNode3).nd = mknode((yyvsp[-3].treeNode3).nd, (yyvsp[0].treeNode3).nd, "AND",0); 
	for (int i = 0; i < (yyvsp[-3].treeNode3).tlistsize; i++) {
        char temp[40];
        sprintf(temp, "%d\n\033[1m\033[32m", (yyvsp[-1].treeNode4).next_quad);
        char temp2[100];
        sprintf(temp2,"\033[1m\033[35mGOTO S");
        strcat(temp2, temp);
        strcat(icg[(yyvsp[-3].treeNode3).tlist[i]], temp2);
    }
    (yyval.treeNode3).tlistsize = 0;
    (yyval.treeNode3).flistsize = 0;
    for (int i = 0; i < (yyvsp[0].treeNode3).tlistsize; i++) {
        (yyval.treeNode3).tlist[(yyval.treeNode3).tlistsize++] = (yyvsp[0].treeNode3).tlist[i];
    }
    for (int i = 0; i < (yyvsp[-3].treeNode3).flistsize; i++) {
        (yyval.treeNode3).flist[(yyval.treeNode3).flistsize++] = (yyvsp[-3].treeNode3).flist[i];
    }
    for(int i=0;i<(yyvsp[0].treeNode3).flistsize;i++){
        (yyval.treeNode3).flist[(yyval.treeNode3).flistsize++] = (yyvsp[0].treeNode3).flist[i];
    }
	(yyval.treeNode3).label_for_while_start = (yyvsp[-3].treeNode3).label_for_while_start;
}
#line 2317 "y.tab.c"
    break;

  case 61: /* condition: condition OR M condition  */
#line 325 "parser.y"
                           { 
	(yyval.treeNode3).nd = mknode((yyvsp[-3].treeNode3).nd, (yyvsp[0].treeNode3).nd, "OR",0);
    for (int i = 0; i < (yyvsp[-3].treeNode3).flistsize; i++) {
        char temp[40];
        sprintf(temp, "%d\n\033[1m\033[32m", (yyvsp[-1].treeNode4).next_quad);
        char temp2[100];
        sprintf(temp2, "\033[1m\033[35mGOTO S");
        strcat(temp2, temp);
        strcat(icg[(yyvsp[-3].treeNode3).flist[i]], temp2);
    }
    (yyval.treeNode3).tlistsize = 0;
    (yyval.treeNode3).flistsize = 0;
    for (int i = 0; i < (yyvsp[-3].treeNode3).tlistsize; i++) {
        (yyval.treeNode3).tlist[(yyval.treeNode3).tlistsize++] = (yyvsp[-3].treeNode3).tlist[i];
    }
    for (int i = 0; i < (yyvsp[0].treeNode3).tlistsize; i++) {
        (yyval.treeNode3).tlist[(yyval.treeNode3).tlistsize++] = (yyvsp[0].treeNode3).tlist[i];
    }
    for(int i=0;i<(yyvsp[0].treeNode3).flistsize;i++){
        (yyval.treeNode3).flist[(yyval.treeNode3).flistsize++] = (yyvsp[0].treeNode3).flist[i];
    }
	(yyval.treeNode3).label_for_while_start = (yyvsp[-3].treeNode3).label_for_while_start;
}
#line 2345 "y.tab.c"
    break;

  case 62: /* condition: expression relop expression  */
#line 348 "parser.y"
                              { 
	(yyval.treeNode3).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name, 0);
    char ifstt[400];
    if(is_loop) {
        (yyval.treeNode3).label_for_while_start = label;
        sprintf(icg[ic_idx++], BOLDBLUE);
        sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++);
        sprintf(icg[ic_idx++], BOLDGREEN);
        is_loop = 0;
    }
    
    if (is_array == 0) {
        if (strcmp((yyvsp[-1].treeNode).name, "==") == 0) {
            sprintf(ifstt, "if %s %s %s ", (yyvsp[-2].treeNode2).name, "==", (yyvsp[0].treeNode2).name);
        } else if (strcmp((yyvsp[-1].treeNode).name, "==") == 0) {
            sprintf(ifstt, "if %s %s %s ", (yyvsp[-2].treeNode2).name, "!=", (yyvsp[0].treeNode2).name);
        } else {
            sprintf(ifstt, "if %s %s %s ", (yyvsp[-2].treeNode2).name, (yyvsp[-1].treeNode).name, (yyvsp[0].treeNode2).name);
        }
    } else {
        if (strcmp((yyvsp[-1].treeNode).name, "==") == 0) {
            sprintf(ifstt, "if u%d %s u%d ", (yyvsp[-2].treeNode2).temp_arr, "==", (yyvsp[0].treeNode2).temp_arr);
        } else if (strcmp((yyvsp[-1].treeNode).name, "=!=") == 0) {
            sprintf(ifstt, "if u%d %s u%d ", (yyvsp[-2].treeNode2).temp_arr, "!=", (yyvsp[0].treeNode2).temp_arr);
        } else {
            sprintf(ifstt, "if u%d %s u%d ", (yyvsp[-2].treeNode2).temp_arr, (yyvsp[-1].treeNode).name, (yyvsp[0].treeNode2).temp_arr);
        }
        is_array = 0;
    }

    sprintf(ifstt, "\nif %s %s %s\n", (yyvsp[-2].treeNode2).name, (yyvsp[-1].treeNode).name, (yyvsp[0].treeNode2).name);
    strcat(icg[ic_idx++], ifstt);
    (yyval.treeNode3).tlistsize = 0;
    (yyval.treeNode3).flistsize = 0;
    (yyval.treeNode3).tlist[(yyval.treeNode3).tlistsize++] = ic_idx - 1;
    (yyval.treeNode3).flist[(yyval.treeNode3).flistsize++] = ic_idx++;
}
#line 2387 "y.tab.c"
    break;

  case 63: /* condition: '(' condition ')'  */
#line 385 "parser.y"
                    { 
    (yyval.treeNode3).nd = (yyvsp[-1].treeNode3).nd; 
    (yyval.treeNode3).tlistsize = (yyvsp[-1].treeNode3).tlistsize;
    (yyval.treeNode3).flistsize = (yyvsp[-1].treeNode3).flistsize;
    for(int i=0;i<(yyvsp[-1].treeNode3).tlistsize;i++){
        (yyval.treeNode3).tlist[i] = (yyvsp[-1].treeNode3).tlist[i];
    }
    for(int i=0;i<(yyvsp[-1].treeNode3).flistsize;i++){
        (yyval.treeNode3).flist[i] = (yyvsp[-1].treeNode3).flist[i];
    }
	(yyval.treeNode3).label_for_while_start = (yyvsp[-1].treeNode3).label_for_while_start;
}
#line 2404 "y.tab.c"
    break;

  case 64: /* condition: value  */
#line 397 "parser.y"
        { (yyval.treeNode3).nd = (yyvsp[0].treeNode2).nd;}
#line 2410 "y.tab.c"
    break;

  case 65: /* $@15: %empty  */
#line 398 "parser.y"
       { add('K');}
#line 2416 "y.tab.c"
    break;

  case 66: /* condition: TRUE $@15  */
#line 398 "parser.y"
                    {(yyval.treeNode3).nd = NULL; }
#line 2422 "y.tab.c"
    break;

  case 67: /* $@16: %empty  */
#line 399 "parser.y"
        { add('K');}
#line 2428 "y.tab.c"
    break;

  case 68: /* condition: FALSE $@16  */
#line 399 "parser.y"
                     {(yyval.treeNode3).nd = NULL; }
#line 2434 "y.tab.c"
    break;

  case 69: /* $@17: %empty  */
#line 403 "parser.y"
                                  { store_name(); }
#line 2440 "y.tab.c"
    break;

  case 70: /* $@18: %empty  */
#line 403 "parser.y"
                                                                 {add('I');}
#line 2446 "y.tab.c"
    break;

  case 71: /* statement: declaration IDENTIFIER $@17 ':' datatype $@18 init  */
#line 403 "parser.y"
                                                                                  {
    (yyvsp[-2].treeNode).nd = mknode(NULL, NULL, (yyvsp[-2].treeNode).name, 0); //making for datatype
	(yyvsp[-5].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-5].treeNode2).name, 0); //making for identifier
	(yyvsp[-6].treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[-5].treeNode2).nd, (yyvsp[-6].treeNode).name, 0); //making for the declaration
	int t = check_types((yyvsp[-2].treeNode).name, (yyvsp[0].treeNode2).type); //here we're checking types
	if(t>0) {
		if(t == 1) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - number and string\n", countn+1);
			sem_errors++;
        }
		else if(t == 2) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - string and number\n", countn+1);
			sem_errors++;
        }  
		else if(t == 3) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - number and boolean\n", countn+1);
			sem_errors++;
        }  
		else if(t == 4) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - boolean and number\n", countn+1);
			sem_errors++;
        }  
		else if(t == 5) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - boolean and string\n", countn+1);
			sem_errors++;
        }  
		else if(t == 6) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - string and boolean\n", countn+1);
			sem_errors++;
        }   
		else {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		(yyval.treeNode).nd = mknode((yyvsp[-5].treeNode2).nd, (yyvsp[0].treeNode2).nd, "Initialisation", 0);
		
	}
    (yyvsp[-5].treeNode2).value = (yyvsp[0].treeNode2).value;
    (yyvsp[-5].treeNode2).nd->value = (yyvsp[0].treeNode2).value;
    set_value((yyvsp[-5].treeNode2).name, (yyvsp[0].treeNode2).value);
	sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-5].treeNode2).name, (yyvsp[0].treeNode2).name);
}
#line 2495 "y.tab.c"
    break;

  case 72: /* statement: IDENTIFIER '=' assign  */
#line 447 "parser.y"
                        { 
	if(check_declaration((yyvsp[-2].treeNode2).name)) {
        if(is_array == 0) {
            (yyvsp[-2].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-2].treeNode2).name, 0);  
            char *id_type = get_type((yyvsp[-2].treeNode2).name); 
            if(strcmp(id_type, (yyvsp[0].treeNode2).type)) {
                int t =  check_types(id_type,(yyvsp[0].treeNode2).type); 
                if(t>0) { 
                    if(t == 1) {
                        sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - number and string\n", countn+1); 
                        sem_errors++;
                    }
                    else if(t == 2) {
                        sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - string and number\n", countn+1); 
                        sem_errors++;
                    }  
                    else if(t == 3) {
                        sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - number and boolean\n", countn+1); 
                        sem_errors++;
                    }  
                    else if(t == 4) {
                        sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - boolean and number\n", countn+1); 
                        sem_errors++;
                    }  
                    else if(t == 5) {
                        sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - boolean and string\n", countn+1); 
                        sem_errors++;
                    }  
                    else if(t == 6) {
                        sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - string and boolean\n", countn+1); 
                        sem_errors++;
                    }   
                }
            }
            else {
                (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, "=", 0);
                (yyvsp[-2].treeNode2).value = (yyvsp[0].treeNode2).value;
                (yyvsp[-2].treeNode2).nd->value = (yyvsp[0].treeNode2).value;
                set_value((yyvsp[-2].treeNode2).name, (yyvsp[0].treeNode2).value);
                sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-2].treeNode2).name, (yyvsp[0].treeNode2).name);
            }
        }
        else {
            is_array = 0;
            (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd,"=", 0);
            sprintf(icg[ic_idx++],"%s = u%d\n", (yyvsp[-2].treeNode2).name, (yyvsp[0].treeNode2).temp_arr);
        }
	}
}
#line 2549 "y.tab.c"
    break;

  case 73: /* statement: array '=' expression  */
#line 496 "parser.y"
                       {
    is_array = 0;
    (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, "=", 0);
    sprintf(icg[ic_idx++], "u%d = %s\n", (yyvsp[-2].treeNode2).temp_arr, (yyvsp[0].treeNode2).name);
}
#line 2559 "y.tab.c"
    break;

  case 74: /* statement: array '=' array  */
#line 501 "parser.y"
                  {
    is_array = 0;
    (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, "=", 0);
    sprintf(icg[ic_idx++], "u%d = u%d\n", (yyvsp[-2].treeNode2).temp_arr, (yyvsp[0].treeNode2).temp_arr);
}
#line 2569 "y.tab.c"
    break;

  case 75: /* statement: IDENTIFIER relop expression  */
#line 506 "parser.y"
                              { 
	if(check_declaration((yyvsp[-2].treeNode2).name)) {
		char *id_type = get_type((yyvsp[-2].treeNode2).name); 
		if(strcmp(id_type, (yyvsp[0].treeNode2).type)) {
			int t =  check_types(id_type,(yyvsp[0].treeNode2).type); 
			if(t>0) { 
			if(t == 1) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - number and string\n", countn+1); 
				sem_errors++;
			}
			else if(t == 2) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - string and number\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 3) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - number and boolean\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 4) {
				 sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - boolean and number\n", countn+1); 
				 sem_errors++;
			}  
			else if(t == 5) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - boolean and string\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 6) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - string and boolean\n", countn+1); 
				sem_errors++;
			}   
        }
	}
	(yyvsp[-2].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-2].treeNode2).name, 0); 
	(yyval.treeNode).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name, 0); 
	}
}
#line 2610 "y.tab.c"
    break;

  case 76: /* statement: IDENTIFIER INC  */
#line 542 "parser.y"
                 { 
	if(check_declaration((yyvsp[-1].treeNode2).name)){
		char* x=get_type((yyvsp[-1].treeNode2).name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot increment type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	(yyvsp[-1].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode2).name, 0); (yyvsp[0].treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name, 0); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode2).nd, (yyvsp[0].treeNode).nd, "Iterator", 0);
	sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[-1].treeNode2).name, (yyvsp[-1].treeNode2).name, temp_var);
	temp_var++;
}
#line 2627 "y.tab.c"
    break;

  case 77: /* statement: IDENTIFIER DEC  */
#line 554 "parser.y"
                 {
	if(check_declaration((yyvsp[-1].treeNode2).name)){
		char* x=get_type((yyvsp[-1].treeNode2).name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot decrement type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	(yyvsp[-1].treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode2).name, 0); (yyvsp[0].treeNode).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name, 0); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode2).nd, (yyvsp[0].treeNode).nd, "Iterator", 0); 
	sprintf(buff,"t%d = %s + 1\n%s = t%d\n",temp_var,(yyvsp[-1].treeNode2).name,(yyvsp[-1].treeNode2).name,temp_var); temp_var++;
}
#line 2643 "y.tab.c"
    break;

  case 78: /* statement: INC IDENTIFIER  */
#line 565 "parser.y"
                 { 
	if(check_declaration((yyvsp[-1].treeNode).name)){
		char* x=get_type((yyvsp[-1].treeNode).name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot decrement type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	(yyvsp[-1].treeNode).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name, 0); (yyvsp[0].treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name, 0); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode2).nd, "Iterator", 0);
	sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[0].treeNode2).name, (yyvsp[0].treeNode2).name, temp_var); temp_var++;
}
#line 2659 "y.tab.c"
    break;

  case 79: /* statement: DEC IDENTIFIER  */
#line 576 "parser.y"
                 { 
	if(check_declaration((yyvsp[-1].treeNode).name)){
		char* x=get_type((yyvsp[-1].treeNode).name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot decrement type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	(yyvsp[-1].treeNode).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name, 0); (yyvsp[0].treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name, 0); (yyval.treeNode).nd = mknode((yyvsp[-1].treeNode).nd, (yyvsp[0].treeNode2).nd, "Iterator", 0);
	sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[0].treeNode2).name, (yyvsp[0].treeNode2).name, temp_var); temp_var++;
}
#line 2675 "y.tab.c"
    break;

  case 80: /* assign: expression  */
#line 589 "parser.y"
                   {
    strcpy((yyval.treeNode2).type, (yyvsp[0].treeNode2).type);
    (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd;
}
#line 2684 "y.tab.c"
    break;

  case 81: /* assign: array  */
#line 593 "parser.y"
        {
    (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd;
    (yyval.treeNode2).temp_arr = (yyvsp[0].treeNode2).temp_arr;
}
#line 2693 "y.tab.c"
    break;

  case 83: /* declaration: LET  */
#line 600 "parser.y"
                 { add('K');}
#line 2699 "y.tab.c"
    break;

  case 84: /* declaration: VAR  */
#line 601 "parser.y"
      { add('K');}
#line 2705 "y.tab.c"
    break;

  case 85: /* declaration: CONST  */
#line 602 "parser.y"
        { add('K');}
#line 2711 "y.tab.c"
    break;

  case 86: /* init: '=' value  */
#line 606 "parser.y"
                { (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); (yyval.treeNode2).value = (yyvsp[0].treeNode2).value; (yyval.treeNode2).nd->value = (yyvsp[0].treeNode2).value; }
#line 2717 "y.tab.c"
    break;

  case 87: /* init: '=' expression  */
#line 607 "parser.y"
                 { (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); (yyval.treeNode2).value = (yyvsp[0].treeNode2).value; (yyval.treeNode2).nd->value = (yyvsp[0].treeNode2).value; }
#line 2723 "y.tab.c"
    break;

  case 88: /* init: '=' list  */
#line 608 "parser.y"
           {
    (yyval.treeNode2).nd = mknode(NULL, NULL, "[]", 0);
    is_array = 1;
}
#line 2732 "y.tab.c"
    break;

  case 89: /* init: %empty  */
#line 612 "parser.y"
  { sprintf((yyval.treeNode2).type, "%s", "null"); (yyval.treeNode2).nd = mknode(NULL, NULL, "NULL", 0); strcpy((yyval.treeNode2).name, "NULL"); }
#line 2738 "y.tab.c"
    break;

  case 90: /* list: '[' integerList ']'  */
#line 616 "parser.y"
                          {

}
#line 2746 "y.tab.c"
    break;

  case 92: /* integerList: INTEGER ',' integerList  */
#line 622 "parser.y"
                                     { (yyval.treeNode).nd = mknode((yyvsp[-2].treeNode).nd, (yyvsp[0].treeNode).nd, "IntegerList", 0); }
#line 2752 "y.tab.c"
    break;

  case 93: /* integerList: INTEGER  */
#line 623 "parser.y"
          { (yyval.treeNode).nd = (yyvsp[0].treeNode).nd; }
#line 2758 "y.tab.c"
    break;

  case 94: /* expression: expression addops term  */
#line 631 "parser.y"
                                    { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf((yyval.treeNode2).type, "%s", (yyvsp[-2].treeNode2).type);
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name, 0);
	}
	sprintf((yyval.treeNode2).name, "t%d", temp_var);
	temp_var++;
    (yyval.treeNode2).value = (yyvsp[-2].treeNode2).value + (yyvsp[0].treeNode2).value;
    (yyval.treeNode2).nd->value = (yyval.treeNode2).value;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.treeNode2).name, (yyvsp[-2].treeNode2).name, (yyvsp[-1].treeNode).name, (yyvsp[0].treeNode2).name);
}
#line 2804 "y.tab.c"
    break;

  case 95: /* expression: term  */
#line 672 "parser.y"
       { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; (yyval.treeNode2).value = (yyvsp[0].treeNode2).value; (yyval.treeNode2).nd->value = (yyvsp[0].treeNode2).value; }
#line 2810 "y.tab.c"
    break;

  case 96: /* term: term mulops factor  */
#line 676 "parser.y"
                          { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf((yyval.treeNode2).type, "%s", (yyvsp[-2].treeNode2).type);
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode).name, 0);
	}
	sprintf((yyval.treeNode2).name, "t%d", temp_var);
	temp_var++;
    (yyval.treeNode2).value = (yyvsp[-2].treeNode2).value * (yyvsp[0].treeNode2).value;
    (yyval.treeNode2).nd->value = (yyval.treeNode2).value;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.treeNode2).name, (yyvsp[-2].treeNode2).name, (yyvsp[-1].treeNode).name, (yyvsp[0].treeNode2).name);
}
#line 2856 "y.tab.c"
    break;

  case 97: /* term: factor  */
#line 717 "parser.y"
         { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; (yyval.treeNode2).nd->value = (yyvsp[0].treeNode2).value; }
#line 2862 "y.tab.c"
    break;

  case 98: /* factor: base exponent base  */
#line 721 "parser.y"
                            { 
	if(strcmp((yyvsp[-2].treeNode2).type, (yyvsp[0].treeNode2).type)){
		if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "boolean") && !strcmp((yyvsp[0].treeNode2).type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "number") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp((yyvsp[-2].treeNode2).type, "string") && !strcmp((yyvsp[0].treeNode2).type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf((yyval.treeNode2).type, "%s", (yyvsp[-2].treeNode2).type);
		(yyval.treeNode2).nd = mknode((yyvsp[-2].treeNode2).nd, (yyvsp[0].treeNode2).nd, (yyvsp[-1].treeNode2).name, 0);
	}
	sprintf((yyval.treeNode2).name, "t%d", temp_var);
	temp_var++;
    (yyval.treeNode2).value = pow((yyvsp[-2].treeNode2).value, (yyvsp[0].treeNode2).value);
    (yyval.treeNode2).nd->value = (yyval.treeNode2).value;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.treeNode2).name, (yyvsp[-2].treeNode2).name, (yyvsp[-1].treeNode2).name, (yyvsp[0].treeNode2).name);
}
#line 2908 "y.tab.c"
    break;

  case 99: /* factor: LOG '(' value ',' value ')'  */
#line 762 "parser.y"
                              {(yyval.treeNode2).nd = mknode((yyvsp[-3].treeNode2).nd, (yyvsp[-1].treeNode2).nd, (yyvsp[-5].treeNode).name, 0); }
#line 2914 "y.tab.c"
    break;

  case 100: /* factor: base  */
#line 763 "parser.y"
       { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; (yyval.treeNode2).value = (yyvsp[0].treeNode2).value; (yyval.treeNode2).nd->value = (yyvsp[0].treeNode2).value; }
#line 2920 "y.tab.c"
    break;

  case 101: /* base: value  */
#line 767 "parser.y"
              { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[0].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; (yyval.treeNode2).value = (yyvsp[0].treeNode2).value; (yyval.treeNode2).nd->value = (yyvsp[0].treeNode2).value; }
#line 2926 "y.tab.c"
    break;

  case 102: /* base: '(' expression ')'  */
#line 768 "parser.y"
                      { strcpy((yyval.treeNode2).name, (yyvsp[-1].treeNode2).name); sprintf((yyval.treeNode2).type, "%s", (yyvsp[-1].treeNode2).type); (yyval.treeNode2).nd = (yyvsp[-1].treeNode2).nd; }
#line 2932 "y.tab.c"
    break;

  case 114: /* number: INTEGER  */
#line 800 "parser.y"
                {
    strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name);
    sprintf((yyval.treeNode2).type, "%s", "number");
    add('N');
    (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name, atoi((yyvsp[0].treeNode).name));
    (yyval.treeNode2).value = atoi((yyvsp[0].treeNode).name);
}
#line 2944 "y.tab.c"
    break;

  case 115: /* number: FLOAT  */
#line 807 "parser.y"
        {
    strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name);
    sprintf((yyval.treeNode2).type, "%s", "number");
    add('N');
    (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name, atof((yyvsp[0].treeNode).name)); 
    (yyval.treeNode2).value = atof((yyvsp[0].treeNode).name);
}
#line 2956 "y.tab.c"
    break;

  case 116: /* value: number  */
#line 817 "parser.y"
              { (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name, 0); }
#line 2962 "y.tab.c"
    break;

  case 117: /* value: IDENTIFIER  */
#line 818 "parser.y"
             {
    strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode2).name);
    char *id_type = get_type((yyvsp[0].treeNode2).name);
    sprintf((yyval.treeNode2).type, "%s", id_type);
    check_declaration((yyvsp[0].treeNode2).name);
    (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode2).name, 0);
    q = search((yyvsp[0].treeNode2).name);
    if(q==-1) {
        (yyval.treeNode2).value = get_value((yyvsp[0].treeNode2).name);
        (yyval.treeNode2).nd->value = (yyval.treeNode2).value;
    }
}
#line 2979 "y.tab.c"
    break;

  case 118: /* value: STRINGVALUE  */
#line 830 "parser.y"
              { strcpy((yyval.treeNode2).name, (yyvsp[0].treeNode).name); sprintf((yyval.treeNode2).type, "string"); add('C'); (yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[0].treeNode).name, 0); }
#line 2985 "y.tab.c"
    break;

  case 119: /* $@19: %empty  */
#line 831 "parser.y"
       { add('K');}
#line 2991 "y.tab.c"
    break;

  case 120: /* value: TRUE $@19  */
#line 831 "parser.y"
                    {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name, 0);}
#line 2997 "y.tab.c"
    break;

  case 121: /* $@20: %empty  */
#line 832 "parser.y"
        { add('K');}
#line 3003 "y.tab.c"
    break;

  case 122: /* value: FALSE $@20  */
#line 832 "parser.y"
                     {(yyval.treeNode2).nd = mknode(NULL, NULL, (yyvsp[-1].treeNode).name, 0);}
#line 3009 "y.tab.c"
    break;

  case 123: /* $@21: %empty  */
#line 833 "parser.y"
       { add('K');}
#line 3015 "y.tab.c"
    break;

  case 124: /* value: SCAN $@21 '(' ')'  */
#line 833 "parser.y"
                           { (yyval.treeNode2).nd = mknode(NULL, NULL, "scan", 0); }
#line 3021 "y.tab.c"
    break;

  case 125: /* value: array  */
#line 834 "parser.y"
        { (yyval.treeNode2).nd = (yyvsp[0].treeNode2).nd; strcpy((yyval.treeNode2).type,(yyvsp[0].treeNode2).type); strcpy((yyval.treeNode2).name,(yyvsp[0].treeNode2).name); (yyval.treeNode2).temp_arr = (yyvsp[0].treeNode2).temp_arr; }
#line 3027 "y.tab.c"
    break;

  case 126: /* array: IDENTIFIER '[' expression ']'  */
#line 837 "parser.y"
                                     { 
    check_declaration((yyvsp[-3].treeNode2).name);
    char *id_type = get_type((yyvsp[-3].treeNode2).name);
    if(id_type != NULL) strcpy((yyval.treeNode2).type, id_type); 
    char temp[100] = "";
    (yyval.treeNode2).nd = mknode(NULL, NULL, (yyval.treeNode2).name, 0); 
    is_array = 1;
    (yyval.treeNode2).temp_arr = temp_arr++;
    sprintf(icg[ic_idx++], "t%d = 4 * %s\n", temp_var++, (yyvsp[-1].treeNode2).name);
    sprintf(icg[ic_idx++], "u%d = %s[t%d]\n", (yyval.treeNode2).temp_arr, (yyvsp[-3].treeNode2).name, temp_var - 1);
}
#line 3043 "y.tab.c"
    break;

  case 127: /* $@22: %empty  */
#line 850 "parser.y"
               { add('K');}
#line 3049 "y.tab.c"
    break;

  case 128: /* return: RETURN $@22 value ';'  */
#line 850 "parser.y"
                                       { 
    (yyvsp[-3].treeNode).nd = mknode(NULL, NULL, "return", 0);
    (yyval.treeNode).nd = mknode((yyvsp[-3].treeNode).nd, (yyvsp[-1].treeNode2).nd, "ReturnStatement", 0);
    sprintf(icg[ic_idx++], BOLDYELLOW);
    sprintf(icg[ic_idx++], "\nRETURN %s\n\n", (yyvsp[-1].treeNode2).name);
    sprintf(icg[ic_idx++], BOLDGREEN);
}
#line 3061 "y.tab.c"
    break;

  case 129: /* return: %empty  */
#line 857 "parser.y"
  { (yyval.treeNode).nd = NULL; }
#line 3067 "y.tab.c"
    break;


#line 3071 "y.tab.c"

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

#line 861 "parser.y"



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

	printIntermediateCode();
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
        if(ptr->value != 0) {
            printf("%s",ptr->token);
            printf(BOLDMAGENTA);
            printf(" (Value -> %0.1f)",ptr->value);
            printf(RESET);
        }
        else {
            printf("%s",ptr->token);
        }
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

struct node* mknode(struct node *left, struct node *right, char *token, float value) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	newnode->value = value;
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

void printIntermediateCode() {
	printf("\n\n");
    printf(RESET);
	printf("\033[4mIntermediate Code Generation (Before Optimisation)\033[24m\n");
    printf(BOLDGREEN);
    printf("\n");
	for(int i = 0; i < ic_idx; i++) {
		printf("%s", icg[i]);
	}

    FILE* icgFile = fopen("icg_base.txt", "w");
    fprintf(icgFile, "%s", BOLDGREEN);
    fprintf(icgFile, "\n");
    for(int i = 0; i < ic_idx; i++) {
        fprintf(icgFile, "%s", icg[i]);
    }
    fclose(icgFile);

	printf("\033[0m\033[4mIntermediate Code Generation (After Optimisation)\033[24m\n");
}

float get_value(char *var){
    for(int i=0; i<count; i++) {
        if(!strcmp(symbol_table[i].id_name, var)) {
            return symbol_table[i].value;
        }
    }
    return 0;
}

void set_value(char *var, float value){
    for(int i=0; i<count; i++) {
        if(!strcmp(symbol_table[i].id_name, var)) {
            symbol_table[i].value = value;
            return;
        }
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
}
