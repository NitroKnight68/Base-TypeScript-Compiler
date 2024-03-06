%{
    #include <bits/stdc++.h>
    #include "colors.h"
    using namespace std;

    #define TOKEN(t) TokenType(t, string(yytext, yyleng))
    #define INCREMENT loc.col += yyleng
    #define ERRORMESSAGE(e) cerr << BOLDRED << "Line : " << loc.line << ", Col : " << loc.col << BOLDRED << "\t" << e << " \"" << BOLDRED << string(yytext,yyleng) << "\"" << RESET << endl

    extern FILE* yyin;
    struct LocationType {
        int col = 0;
        int line = 0;
    };
    
    LocationType loc;

    /* Tokens */
    enum TokenNames {
        IMPORT, FROM,
        LET, CONST, VAR,
        FUNCTION, ASYNC, ARROW,
        IF, ELSE, FOR, WHILE,
        RETURN, BREAK, CONTINUE,
        INTEGER, FLOAT, BOOLEAN, STRINGVALUE,
        ANYTYPE, NUMBERTYPE, STRINGTYPE, BOOLEANTYPE, UNDEFINED,
        TYPE, DATATYPE, IDENTIFIER,
        LEFTROUND, RIGHTROUND, LEFTCURLY, RIGHTCURLY,
        SEMICOLON, COLON, COMMA, PERIOD,
        AND, OR, NOT,
        UNION, INTERSECTION,
        EQUAL, DOUBLEEQUAL, NOTEQUAL, 
        LESSTHAN, LESSEQUAL, GREATERTHAN, GREATEREQUAL,
        PLUS, MINUS, MULTIPLY, DIVIDE,
        CONSOLELOG,
        SINGLECOMMENT, MULTICOMMENT,
    };

    struct TokenType {
        TokenNames tokenName;
        string literal;
        LocationType locationData;
        TokenType(TokenNames tokName, string lit): tokenName(tokName), literal(lit), locationData(loc){}
    };

    vector<TokenType> tokenList;
    unordered_map<TokenNames,string> tokenMap = {
        {IMPORT, "IMPORT"}, {FROM, "FROM"},
        {LET, "LET"}, {CONST, "CONST"}, {VAR, "VAR"},
        {FUNCTION, "FUNCTION"}, {ASYNC, "ASYNC"}, {ARROW, "ARROW"},
        {IF, "IF"}, {ELSE, "ELSE"}, {FOR, "FOR"}, {WHILE, "WHILE"},
        {RETURN, "RETURN"}, {BREAK, "BREAK"}, {CONTINUE, "CONTINUE"},
        {INTEGER, "INTEGER"}, {FLOAT, "FLOAT"}, {BOOLEAN, "BOOLEAN"}, {STRINGVALUE, "STRINGVALUE"},
        {ANYTYPE, "ANYTYPE"}, {NUMBERTYPE, "NUMBERTYPE"}, {STRINGTYPE, "STRINGTYPE"}, {BOOLEANTYPE, "BOOLEANTYPE"}, {UNDEFINED, "UNDEFINED"},
        {TYPE, "TYPE"}, {DATATYPE, "DATATYPE"}, {IDENTIFIER, "IDENTIFIER"},
        {LEFTROUND, "LEFTROUND"}, {RIGHTROUND, "RIGHTROUND"}, {LEFTCURLY, "LEFTCURLY"}, {RIGHTCURLY, "RIGHTCURLY"},
        {SEMICOLON, "SEMICOLON"}, {COLON, "COLON"}, {COMMA, "COMMA"}, {PERIOD, "PERIOD"},
        {AND, "AND"}, {OR, "OR"}, {NOT, "NOT"},
        {UNION, "UNION"}, {INTERSECTION, "INTERSECTION"},
        {EQUAL, "EQUAL"}, {DOUBLEEQUAL, "DOUBLEEQUAL"}, {NOTEQUAL, "NOTEQUAL"},
        {LESSTHAN, "LESSTHAN"}, {LESSEQUAL, "LESSEQUAL"}, {GREATERTHAN, "GREATERTHAN"}, {GREATEREQUAL, "GREATEREQUAL"},
        {PLUS, "PLUS"}, {MINUS, "MINUS"}, {MULTIPLY, "MULTIPLY"}, {DIVIDE, "DIVIDE"},
        {CONSOLELOG, "CONSOLELOG"},
        {SINGLECOMMENT, "SINGLECOMMENT"}, {MULTICOMMENT, "MULTICOMMENT"},
    };

    extern "C" int yywrap() { return 1; }
    bool errorFlag = false;
%}

/* Rules */
%%

[ \t]                       { loc.col++; }
[\n]                        { loc.line++; loc.col = 0; }
"import"					{ INCREMENT; tokenList.push_back(TOKEN(IMPORT)); }
"from"					    { INCREMENT; tokenList.push_back(TOKEN(FROM)); }
"let"					    { INCREMENT; tokenList.push_back(TOKEN(LET)); }
"const"					    { INCREMENT; tokenList.push_back(TOKEN(CONST)); }
"var"					    { INCREMENT; tokenList.push_back(TOKEN(VAR)); }
"function"				    { INCREMENT; tokenList.push_back(TOKEN(FUNCTION)); }
"async"					    { INCREMENT; tokenList.push_back(TOKEN(ASYNC)); }
"=>"					    { INCREMENT; tokenList.push_back(TOKEN(ARROW)); }
"if" 					    { INCREMENT; tokenList.push_back(TOKEN(IF)); }
"else" 					    { INCREMENT; tokenList.push_back(TOKEN(ELSE)); }
"for"					    { INCREMENT; tokenList.push_back(TOKEN(FOR)); }
"while"					    { INCREMENT; tokenList.push_back(TOKEN(WHILE)); }
"return"					{ INCREMENT; tokenList.push_back(TOKEN(RETURN)); }
"break"					    { INCREMENT; tokenList.push_back(TOKEN(BREAK)); }
"continue"					{ INCREMENT; tokenList.push_back(TOKEN(CONTINUE)); }
[0-9_]{1,5}                 { INCREMENT; tokenList.push_back(TOKEN(INTEGER)); }
[0-9_]+\.[0-9_]*            { INCREMENT; tokenList.push_back(TOKEN(FLOAT)); }
("true"|"false")            { INCREMENT; tokenList.push_back(TOKEN(BOOLEAN)); }
["].*["] 				    { INCREMENT; tokenList.push_back(TOKEN(STRINGVALUE)); }
"any"    			        { INCREMENT; tokenList.push_back(TOKEN(ANYTYPE)); }
"number"    			    { INCREMENT; tokenList.push_back(TOKEN(NUMBERTYPE)); }
"string"				    { INCREMENT; tokenList.push_back(TOKEN(STRINGTYPE)); }
"boolean"				    { INCREMENT; tokenList.push_back(TOKEN(BOOLEANTYPE)); }
"undefined"				    { INCREMENT; tokenList.push_back(TOKEN(UNDEFINED)); }
"type"                      { INCREMENT; tokenList.push_back(TOKEN(TYPE)); }
[:][ ]*[a-zA-z]+            { INCREMENT; tokenList.push_back(TOKEN(DATATYPE)); }
[_$a-zA-Z][_a-zA-Z0-9$]*    { INCREMENT; tokenList.push_back(TOKEN(IDENTIFIER)); }
"("                         { INCREMENT; tokenList.push_back(TOKEN(LEFTROUND)); }
")"                         { INCREMENT; tokenList.push_back(TOKEN(RIGHTROUND)); }
"{"                         { INCREMENT; tokenList.push_back(TOKEN(LEFTCURLY)); }
"}"                         { INCREMENT; tokenList.push_back(TOKEN(RIGHTCURLY)); }
";"					        { INCREMENT; tokenList.push_back(TOKEN(SEMICOLON)); }
":" 					    { INCREMENT; tokenList.push_back(TOKEN(COLON)); }
"," 					    { INCREMENT; tokenList.push_back(TOKEN(COMMA)); }
"." 					    { INCREMENT; tokenList.push_back(TOKEN(PERIOD)); }
"&&"                        { INCREMENT; tokenList.push_back(TOKEN(AND)); }
"||"                        { INCREMENT; tokenList.push_back(TOKEN(OR)); }
"!"						    { INCREMENT; tokenList.push_back(TOKEN(NOT)); }
"|"                         { INCREMENT; tokenList.push_back(TOKEN(UNION)); }
"&"                         { INCREMENT; tokenList.push_back(TOKEN(INTERSECTION)); }
"="                         { INCREMENT; tokenList.push_back(TOKEN(EQUAL)); }
"=="                        { INCREMENT; tokenList.push_back(TOKEN(DOUBLEEQUAL)); }
"!="                        { INCREMENT; tokenList.push_back(TOKEN(NOTEQUAL)); }
"<"                         { INCREMENT; tokenList.push_back(TOKEN(LESSTHAN)); }
"<="                        { INCREMENT; tokenList.push_back(TOKEN(LESSEQUAL)); }
">"                         { INCREMENT; tokenList.push_back(TOKEN(GREATERTHAN)); }
">="                        { INCREMENT; tokenList.push_back(TOKEN(GREATEREQUAL)); }
"+"                         { INCREMENT; tokenList.push_back(TOKEN(PLUS)); }
"-"                         { INCREMENT; tokenList.push_back(TOKEN(MINUS)); }
"*"                         { INCREMENT; tokenList.push_back(TOKEN(MULTIPLY)); }
"/"                         { INCREMENT; tokenList.push_back(TOKEN(DIVIDE)); }
"console.log(".*")"         { INCREMENT; tokenList.push_back(TOKEN(CONSOLELOG)); }
[/][/].*                    { INCREMENT; tokenList.push_back(TOKEN(SINGLECOMMENT)); }
[/][*](.|\n)*.*[*][/]       { INCREMENT; tokenList.push_back(TOKEN(MULTICOMMENT)); }

.                           { ERRORMESSAGE("Unrecognised Symbol"); errorFlag = true; yyterminate(); }
[0-9]+[_a-zA-Z$]*           { ERRORMESSAGE("Invalid Identifier"); errorFlag = true; yyterminate(); }

%%

/* Main Function */
int main() {
	yyin = fopen("input.ts", "r");
	yylex();
	if(errorFlag) {
		cerr << BOLDRED << UNDERLINE << "Error generated" << RESET << endl;
		return 1;
	}
	bool displayLines = true;
	for(auto &x: tokenList){
		if(displayLines){
			cout << " Line: " << BOLDBLUE << x.locationData.line << RESET << ", Col: " << BOLDBLUE << x.locationData.col << RESET << "\t";
		}
		cout << BOLDMAGENTA << x.literal << "\t\t\t" << BOLDGREEN << tokenMap.at(x.tokenName) << RESET << "\n";
	}
}
