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
    CONSOLELOG = 258,              /* CONSOLELOG  */
    SCAN = 259,                    /* SCAN  */
    IF = 260,                      /* IF  */
    WHILE = 261,                   /* WHILE  */
    ELSE = 262,                    /* ELSE  */
    RETURN = 263,                  /* RETURN  */
    ELIF = 264,                    /* ELIF  */
    LET = 265,                     /* LET  */
    VAR = 266,                     /* VAR  */
    CONST = 267,                   /* CONST  */
    ADD = 268,                     /* ADD  */
    SUB = 269,                     /* SUB  */
    MULT = 270,                    /* MULT  */
    DIV = 271,                     /* DIV  */
    LOG = 272,                     /* LOG  */
    POW = 273,                     /* POW  */
    GE = 274,                      /* GE  */
    LE = 275,                      /* LE  */
    GT = 276,                      /* GT  */
    LT = 277,                      /* LT  */
    EQ = 278,                      /* EQ  */
    NE = 279,                      /* NE  */
    TRUE = 280,                    /* TRUE  */
    FALSE = 281,                   /* FALSE  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    NUMBERTYPE = 284,              /* NUMBERTYPE  */
    STRINGTYPE = 285,              /* STRINGTYPE  */
    BOOLEANTYPE = 286,             /* BOOLEANTYPE  */
    FUNCTION = 287,                /* FUNCTION  */
    INTEGER = 288,                 /* INTEGER  */
    FLOAT = 289,                   /* FLOAT  */
    IDENTIFIER = 290,              /* IDENTIFIER  */
    STRINGVALUE = 291              /* STRINGVALUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CONSOLELOG 258
#define SCAN 259
#define IF 260
#define WHILE 261
#define ELSE 262
#define RETURN 263
#define ELIF 264
#define LET 265
#define VAR 266
#define CONST 267
#define ADD 268
#define SUB 269
#define MULT 270
#define DIV 271
#define LOG 272
#define POW 273
#define GE 274
#define LE 275
#define GT 276
#define LT 277
#define EQ 278
#define NE 279
#define TRUE 280
#define FALSE 281
#define AND 282
#define OR 283
#define NUMBERTYPE 284
#define STRINGTYPE 285
#define BOOLEANTYPE 286
#define FUNCTION 287
#define INTEGER 288
#define FLOAT 289
#define IDENTIFIER 290
#define STRINGVALUE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} treeNode; 

#line 146 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
