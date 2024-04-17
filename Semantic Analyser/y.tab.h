/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 158 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
