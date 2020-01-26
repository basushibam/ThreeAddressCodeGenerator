/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
