#! /bin/sh
lex lexer.l
yacc -v -d parser.y --warning=none
gcc y.tab.c -o lexer.out
./lexer.out < input.ts
