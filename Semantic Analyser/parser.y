%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    #define BOLDRED "\033[1m\033[31m"
    #define BOLDBLUE "\033[1m\033[34m"
    #define BOLDMAGENTA "\033[1m\033[35m"
    #define BOLDGREEN "\033[1m\033[32m"
    #define RESET "\033[0m"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();

    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
    
    struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);

    struct dataType {
        char *id_name;
        char *data_type;
        char *type;
        int   line_no;
    } symbol_table[100];

    char type[100]; // Added declaration for type
    int count = 0; // Added declaration for count
    int q; // Added declaration for q
    int sem_errors = 0;
    int label = 0;
    char buff[100];
    char errors[10][100];
    char reserved[10][20] = {"number", "import", "async", "string", "void", "if", "else", "for", "while", "return"};
    
    void insert_type();
    void add(char c);
    int search(char *);


    void printBTHelper(char* prefix, struct node* ptr, int isLeft);
    void printBT(struct node* ptr);
    void printSymbolTable();
	void printSemanticErrors();

    int check_declaration(char *);
    void check_return_type(char *);
    int check_types(char *, char *);
    char *get_type(char *);
	void insert_type();
    
    extern int countn;
%}


%union { 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} treeNode; 

    struct var_name2 {
        char name[100];
        struct node* nd;
        char type[8];
    } treeNode2;
}

%token <treeNode>  IMPORT FROM AS CONSOLELOG SCAN IF WHILE ELSE RETURN ELIF LET VAR CONST ADD SUB MULT DIV LOG GE LE GT LT EQ NE TRUE FALSE AND OR NUMBERTYPE STRINGTYPE BOOLEANTYPE FUNCTION INTEGER FLOAT IDENTIFIER STRINGVALUE
%token <treeNode2> POW 
%type  <treeNode>  main importList imports moduleList modules parameter parameterList datatype body block console_outputs else condition statement declaration mulops addops relop return and_or 
%type  <treeNode2> init expression value number term factor base exponent function
%define parse.error verbose 

%%

main: importList body { $$.nd = mknode($1.nd, $2.nd, "Program"); head = $$.nd; }
;

importList: imports importList { $$.nd = mknode($1.nd, $2.nd, "ImportList"); }
| imports { $$.nd = mknode(NULL, $1.nd, "ImportList"); }
| { $$.nd = mknode(NULL, NULL, "ImportList"); }
;

imports: IMPORT '{' moduleList '}' FROM STRINGVALUE ';' { $$.nd = $3.nd; }
| IMPORT '{' modules '}' AS IDENTIFIER FROM STRINGVALUE ';' { $$.nd = $3.nd; }
| IMPORT moduleList FROM STRINGVALUE ';' { $$.nd = $2.nd; }
| IMPORT modules AS IDENTIFIER FROM STRINGVALUE ';' { $$.nd = $2.nd; }
;

moduleList: moduleList ',' moduleList { $$.nd = mknode($1.nd, $3.nd, "ModuleList"); }
| modules { $$.nd = mknode(NULL, NULL, $1.name); }
;

modules: IDENTIFIER
| MULT
;

body: block body {$$.nd = mknode($1.nd, $2.nd, "Scope"); }
| { $$.nd = mknode(NULL, NULL, "EndOfScope"); }
;
        
block: function { $$.nd = $1.nd; }
|WHILE { add('K');} '(' condition ')''{' body '}' { $$.nd = mknode($4.nd, $7.nd, $1.name); }
| IF { add('K');}  '(' condition ')''{' body '}' else { struct node *iff = mknode($4.nd, $7.nd, $1.name); $$.nd = mknode(iff, $9.nd, "conditionalBranch"); }
| statement ';' { $$.nd = $1.nd; }
| CONSOLELOG { add('K');} '(' console_outputs ')' ';' { struct node *data = mknode(NULL, NULL, $4.name); $$.nd = mknode(NULL, data, "ConsoleLog"); } 
;

console_outputs: STRINGVALUE { add('C');}
               | IDENTIFIER  { check_declaration($1.name);}
               | expression
               ;


function: FUNCTION { add('F'); } IDENTIFIER { add('I'); } '(' parameterList ')' '{' body return '}' {  $9.nd = mknode($9.nd, $10.nd, "FunctionBody"); struct node *main = mknode($9.nd, $6.nd, $3.name); $$.nd = mknode($1.nd, main, "Function"); }  
;

parameterList: parameter ',' parameterList { $$.nd = mknode($1.nd, $3.nd, "ParameterList"); }
| parameter { $$.nd = $1.nd; }
| { $$.nd = $$.nd = mknode(NULL, NULL, "Parameter"); }
;

parameter: IDENTIFIER { add('I');} ':' datatype {$4.nd = mknode(NULL, NULL, $4.name); $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($4.nd, $1.nd, "Parameter");}
;


datatype: NUMBERTYPE { insert_type(); }
| STRINGTYPE { insert_type(); }
| BOOLEANTYPE { insert_type(); }
;



else: ELSE { add('K');} '{' body '}' {  struct node *cond = mknode(NULL, NULL, "EndOfConditional"); $$.nd = mknode($4.nd, cond, $1.name); }
| { $$.nd = NULL; }
;

condition: condition and_or condition { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| value relop value { $$.nd = mknode($1.nd, $3.nd, $2.name);}
| value { $$.nd = $1.nd;}
| TRUE { add('K');} {$$.nd = NULL; }
| FALSE { add('K');} {$$.nd = NULL; }
;

statement: declaration IDENTIFIER { add('I');} ':' datatype init {
    $5.nd = mknode(NULL, NULL, $5.name); //making for datatype
	$2.nd = mknode(NULL, NULL, $2.name); //making for identifier
	$1.nd = mknode($5.nd, $2.nd, $1.name); //making for the declaration
	int t = check_types($5.name, $6.type); //here we're checking types
	// printf("%s\n", $5.name);
	// printf("%s\n", $6.type);
	// printf("%d\n", t);
	if(t>0) {
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
	} 
	else {
		$$.nd = mknode($2.nd, $6.nd, "Initialisation");
		
	}
		
	} 
| IDENTIFIER {  } '=' expression { 
	if(check_declaration($1.name)){
		$1.nd = mknode(NULL, NULL, $1.name);  
		char *id_type = get_type($1.name); 
		if(strcmp(id_type, $4.type)) {
			sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;	
		}
		else {
			$$.nd = mknode($1.nd, $4.nd, "="); 
		}
	}
	
	}
| IDENTIFIER { check_declaration($1.name); } relop expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $4.nd, $3.name ); }
;

declaration: LET { add('K');}
| VAR { add('K');}
| CONST { add('K');}
;

init: '=' value { $$.nd = $2.nd; sprintf($$.type, "%s", $2.type); strcpy($$.name, $2.name); }
| '=' expression { $$.nd = $2.nd; sprintf($$.type, "%s", $2.type); strcpy($$.name, $2.name); }
| { sprintf($$.type, "%s", "null"); $$.nd = mknode(NULL, NULL, "NULL"); strcpy($$.name, "NULL"); }
;


expression : expression addops term { 
	if(strcmp($1.type, $3.type)){
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;
	} 
	else {
		$$.nd = mknode($1.nd, $3.nd, $2.name);
	}
}
| term { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; }
;

term : term mulops factor { 
	if(strcmp($1.type, $3.type)){
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
	} 
	else {
		$$.nd = mknode($1.nd, $3.nd, $2.name);
	}

	}
| factor { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; }
; 

factor : base exponent base { 
	if(strcmp($1.type, $3.type)){
		sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
	} 
	else {
		$$.nd = mknode($1.nd, $3.nd, $2.name);
	}
	}
| LOG '(' value ',' value ')' {$$.nd = mknode($3.nd, $5.nd, $1.name); }
| base { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; }
;

base : value  { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; }
| '(' expression ')'  { strcpy($$.name, $2.name); sprintf($$.type, "%s", $2.type); $$.nd = $2.nd; }
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

number: INTEGER { strcpy($$.name, $1.name); sprintf($$.type, "%s", "number"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| FLOAT { strcpy($$.name, $1.name); sprintf($$.type, "%s", "number"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
;

value: number {$$.nd = mknode(NULL, NULL, $1.name);}
| IDENTIFIER { strcpy($$.name, $1.name); char *id_type = get_type($1.name); sprintf($$.type, "%s", id_type); check_declaration($1.name); $$.nd = mknode(NULL, NULL, $1.name); }
| STRINGVALUE { strcpy($$.name, $1.name); sprintf($$.type, "string"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| TRUE { add('K');} {$$.nd = mknode(NULL, NULL, $1.name);}
| FALSE { add('K');} {$$.nd = mknode(NULL, NULL, $1.name);}
| SCAN { add('K');} '('')' { $$.nd = mknode(NULL, NULL, "scan"); }
;


return: RETURN { add('K');} value ';'  { $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $3.nd, "ReturnStatement"); }
//{ $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $3.nd, "ReturnStatement"); } check_return_type($3.name);
| { $$.nd = NULL; } 
;


%%


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
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))
		return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))
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
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword\n", countn+1, yytext);
				sem_errors++;
				return;
			}
		}
	}
    q=search(yytext);
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
			symbol_table[count].id_name=strdup(yytext);
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
    }
    else if(c == 'I' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed\n", countn+1, yytext);
		sem_errors++;
    }
}


void insert_type() {
	strcpy(type, yytext);
}