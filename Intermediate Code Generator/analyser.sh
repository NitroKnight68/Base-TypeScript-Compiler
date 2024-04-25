#! /bin/sh
lex lexer.l
yacc -v -d parser.y --warning=none
gcc y.tab.c -o lexer.out -lm -Wno-format-security
./lexer.out < $1
