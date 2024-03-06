#! /bin/sh
lex -o lexer.cpp lexer.l
g++ lexer.cpp -o lexer.out
./lexer.out
