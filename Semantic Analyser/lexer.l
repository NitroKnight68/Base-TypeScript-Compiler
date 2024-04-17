%{    
     #include "y.tab.h"
     int countn=0;
%}

%option yylineno
%option noinput nounput

%%

"console.log"		{ strcpy(yylval.treeNode.name,(yytext)); return CONSOLELOG; }
"import"		{ strcpy(yylval.treeNode.name,(yytext)); return IMPORT; }
"from"		{ strcpy(yylval.treeNode.name,(yytext)); return FROM; }
"as"		{ strcpy(yylval.treeNode.name,(yytext)); return AS; }

"if"      { strcpy(yylval.treeNode.name,(yytext)); return IF; }
"else"		{ strcpy(yylval.treeNode.name,(yytext)); return ELSE; }
"return" 		   { strcpy(yylval.treeNode.name,(yytext)); return RETURN; }
"else if"      { strcpy(yylval.treeNode.name,(yytext)); return ELIF; }
"let"	      { strcpy(yylval.treeNode.name,(yytext)); return LET; }
"var"	      { strcpy(yylval.treeNode.name,(yytext)); return VAR; }
"const"	      { strcpy(yylval.treeNode.name,(yytext)); return CONST; }
"+"		      { strcpy(yylval.treeNode.name,(yytext)); return ADD; }
"-"		      { strcpy(yylval.treeNode.name,(yytext)); return SUB; }
"*"		      { strcpy(yylval.treeNode.name,(yytext)); return MULT; }
"/"		      { strcpy(yylval.treeNode.name,(yytext)); return DIV; }
"log"		      { strcpy(yylval.treeNode.name,(yytext)); return LOG; }
"exp"		      { strcpy(yylval.treeNode.name,(yytext)); return POW; }
"while"       { strcpy(yylval.treeNode.name,(yytext)); return WHILE; }

">="		      { strcpy(yylval.treeNode.name,(yytext)); return GE; }
"<="		      { strcpy(yylval.treeNode.name,(yytext)); return LE; }
">"		      { strcpy(yylval.treeNode.name,(yytext)); return GT; }
"<"		      { strcpy(yylval.treeNode.name,(yytext)); return LT; }
"=="		      { strcpy(yylval.treeNode.name,(yytext)); return EQ; }
"!="		      { strcpy(yylval.treeNode.name,(yytext)); return NE; }

"true"		   { strcpy(yylval.treeNode.name,(yytext)); return TRUE; }
"false"		      { strcpy(yylval.treeNode.name,(yytext)); return FALSE; }
"&&"		      { strcpy(yylval.treeNode.name,(yytext)); return AND; }
"||"		      { strcpy(yylval.treeNode.name,(yytext)); return OR; }

"number"		      { strcpy(yylval.treeNode.name,(yytext)); return NUMBERTYPE; }
"string"		      { strcpy(yylval.treeNode.name,(yytext)); return STRINGTYPE; }
"boolean"		   { strcpy(yylval.treeNode.name,(yytext)); return BOOLEANTYPE; }
"function"		   { strcpy(yylval.treeNode.name,(yytext)); return FUNCTION; }

[/][/].*                    { ; }
[/][*](.|\n)*.*[*][/]       { ; }
[ \t]*			{ ; }
[\n]			   { countn++; }

[0-9][0-9_]*             { strcpy(yylval.treeNode.name,(yytext)); return INTEGER; }            
[0-9]+\.[0-9_]*        { strcpy(yylval.treeNode.name,(yytext)); return FLOAT; }    
[_$a-zA-Z][_a-zA-Z0-9$]*  { strcpy(yylval.treeNode.name,(yytext)); return IDENTIFIER; }

["].*["]                    { strcpy(yylval.treeNode.name,(yytext)); return STRINGVALUE; }

";"|"="|","|"{"|"}"|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|":"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">" { strcpy(yylval.treeNode.name,(yytext));return yytext[0];}


%%

int yywrap(void) {
   return 1;
}