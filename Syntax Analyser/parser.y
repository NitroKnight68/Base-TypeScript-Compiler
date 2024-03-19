%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    #define BOLDRED "\033[1m\033[31m"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();
    

    struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);

    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
%}


%union { 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} treeNode; 
}

%token <treeNode> CONSOLELOG SCAN IF WHILE ELSE RETURN ELIF LET VAR CONST ADD SUB MULT DIV LOG POW GE LE GT LT EQ NE TRUE FALSE AND OR NUMBERTYPE STRINGTYPE BOOLEANTYPE FUNCTION INTEGER FLOAT IDENTIFIER STRINGVALUE

%type <treeNode> function entry parameter datatype body block else condition statement declaration init expression term factor base exponent mulops addops relop number value return and_or
%define parse.error verbose 

%%

function: FUNCTION IDENTIFIER '(' parameter ')' '{' body return '}' { struct node *main = mknode($7.nd, $8.nd, $2.name); $$.nd = mknode($1.nd, main, "Function"); head = $$.nd; } 
;

parameter: parameter ',' parameter
| IDENTIFIER ':' datatype
|
;

datatype: NUMBERTYPE
| STRINGTYPE
| BOOLEANTYPE
;

body: block body {$$.nd = mknode($1.nd, $2.nd, "Scope");}
| { $$.nd = mknode(NULL, NULL, "EndOfScope"); }
;

block: WHILE '(' condition ')''{' body '}' { $$.nd = mknode($3.nd, $6.nd, $1.name); }
| IF '(' condition ')''{' body '}' else { struct node *iff = mknode($3.nd, $6.nd, $1.name); $$.nd = mknode(iff, $8.nd, "conditionalBranch"); }
| statement ';' { $$.nd = $1.nd; }
| CONSOLELOG '(' STRINGVALUE ')' ';' { struct node *data = mknode(NULL, NULL, $3.name); $$.nd = mknode(NULL, data, "ConsoleLog"); }
| CONSOLELOG '(' IDENTIFIER ')' ';' { struct node *data = mknode(NULL, NULL, $3.name); $$.nd = mknode(NULL, data, "ConsoleLog"); }
;

else: ELSE '{' body '}' {  struct node *cond = mknode(NULL, NULL, "EndOfConditional"); $$.nd = mknode($3.nd, cond, $1.name); }
| { $$.nd = NULL; }
;

condition: condition and_or condition { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| value relop value { $$.nd = mknode($1.nd, $3.nd, $2.name);}
| value { $$.nd = $1.nd;}
| TRUE {$$.nd = NULL; }
| FALSE {$$.nd = NULL; }
;

statement: declaration IDENTIFIER ':' datatype init {$4.nd = mknode(NULL, NULL, $4.name); $2.nd = mknode(NULL, NULL, $2.name); $1.nd = mknode($4.nd, $2.nd, $1.name); $$.nd = mknode($1.nd, $5.nd, "Initialisation");} 
| IDENTIFIER '=' expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $3.nd, "="); }
| IDENTIFIER relop expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $3.nd, $2.name ); }
;

declaration: LET
| VAR
| CONST
;

init: '=' value { $$.nd = $2.nd;}
| '=' expression { $$.nd = $2.nd;}
| { $$.nd = NULL; }
;


expression : expression addops term { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| term { $$.nd = $1.nd;}
;

term : term mulops factor { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| factor {$$.nd = $1.nd;}
; 

factor : base exponent base { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| LOG '(' value ',' value ')' {$$.nd = mknode($3.nd, $5.nd, $1.name); }
| base {$$.nd = $1.nd;}
;

base : value {$$.nd = $1.nd;}
| '(' expression ')' {$$.nd = $2.nd;}
;

and_or : AND { $$.nd = mknode(NULL, NULL, $1.name); }
| OR { $$.nd = mknode(NULL, NULL, $1.name); }
;

exponent: POW
;

mulops: MULT
| DIV
;

addops: ADD 
| SUB 
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

number: INTEGER
| FLOAT
;

value: number {$$.nd = mknode(NULL, NULL, $1.name);}
| IDENTIFIER {$$.nd = mknode(NULL, NULL, $1.name);}
| STRINGVALUE {$$.nd = mknode(NULL, NULL, $1.name);}
| TRUE {$$.nd = mknode(NULL, NULL, $1.name);}
| FALSE {$$.nd = mknode(NULL, NULL, $1.name);}
| SCAN '('')' { $$.nd = mknode(NULL, NULL, "scan"); }
;

return: RETURN value ';'  { $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $2.nd, "ReturnStatement"); }
| { $$.nd = NULL; } 
;

%%


int main() {
    extern FILE *yyin, *yyout;
   
    int p = -1;
    p = yyparse();
    if(p)
        printf("Parsing Successful\n");
    printf("\033[4mParse Tree\033[24m");
    printf("\n\n");
	printBT(head);
    printf("\n\n");

    
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