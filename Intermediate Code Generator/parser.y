%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>
    #include "lex.yy.c"

    #define BOLDRED "\033[1m\033[31m"
    #define BOLDBLUE "\033[1m\033[34m"
    #define BOLDCYAN "\033[1m\033[36m"
    #define BOLDYELLOW "\033[1m\033[33m"
    #define BOLDMAGENTA "\033[1m\033[35m"
    #define BOLDGREEN "\033[1m\033[32m"
    #define RESET "\033[0m"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();
    float get_value(char *var);
    void set_value(char *var, float value);

    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token;
        float value;
    };
    
    struct node* mknode(struct node *left, struct node *right, char *token, float value);
    void printBT(struct node*);

    struct dataType {
        char *id_name;
        char *data_type;
        char *type;
        int   line_no;
        float  value;
    } symbol_table[100];

    char type[100]; // Added declaration for type
	char id_name[100];
    int count = 0; // Added declaration for count
    int q; // Added declaration for q
    int sem_errors = 0;

    int label = 0;
	int ic_idx = 0;
    int param_idx = 0;
	int temp_var = 0;
	int is_loop = 0;

    char buff[400];
    char errors[10][100];
    char reserved[10][20] = {"number", "import", "async", "string", "void", "if", "else", "for", "while", "return"};
    char icg[50][100];
    char func_buff[200];
    char func_params[20][200];

    void insert_type();
	void store_name();
    void add(char c);
    int search(char *);

    void printBTHelper(char* prefix, struct node* ptr, int isLeft);
    void printBT(struct node* ptr);
    void printSymbolTable();
	void printSemanticErrors();
	void printIntermediateCode();

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
        float value;
	} treeNode; 

    struct var_name2 {
        char name[100];
        struct node* nd;
        char type[8];
        float value;
    } treeNode2;

	struct var_name3 {
		char name[100];
		struct node* nd;
		char if_body[5];
		char else_body[5];
		char after_else_body[5];
        float value;
	} treeNode3;
}

%token <treeNode>  IMPORT FROM AS CONSOLELOG SCAN IF WHILE ELSE RETURN ELIF LET VAR CONST ADD SUB MULT DIV LOG GE LE GT LT EQ NE TRUE FALSE AND OR NUMBERTYPE STRINGTYPE BOOLEANTYPE FUNCTION INTEGER FLOAT STRINGVALUE INC DEC FOR
%token <treeNode2> POW IDENTIFIER
%type  <treeNode>  main importList imports moduleList modules parameter parameterList datatype body block console_outputs else statement declaration mulops addops relop return and_or 
%type  <treeNode2> init expression value number term factor base exponent function
%type  <treeNode3> condition
%define parse.error verbose 

%%

main: importList body { $$.nd = mknode($1.nd, $2.nd, "Program", 0); head = $$.nd; }
;


importList: imports importList { $$.nd = mknode($1.nd, $2.nd, "ImportList", 0); }
| imports { $$.nd = mknode(NULL, $1.nd, "ImportList", 0); }
| { $$.nd = mknode(NULL, NULL, "ImportList", 0); }
;


imports: IMPORT '{' moduleList '}' FROM STRINGVALUE ';' { $$.nd = $3.nd; }
| IMPORT '{' modules '}' AS IDENTIFIER FROM STRINGVALUE ';' { $$.nd = $3.nd; }
| IMPORT moduleList FROM STRINGVALUE ';' { $$.nd = $2.nd; }
| IMPORT modules AS IDENTIFIER FROM STRINGVALUE ';' { $$.nd = $2.nd; }
;


moduleList: moduleList ',' moduleList { $$.nd = mknode($1.nd, $3.nd, "ModuleList", 0); }
| modules { $$.nd = mknode(NULL, NULL, $1.name, 0); }
;


modules: IDENTIFIER
| MULT
;


body: block body {$$.nd = mknode($1.nd, $2.nd, "Scope", 0); }
| { $$.nd = mknode(NULL, NULL, "EndOfScope", 0); }
;

        
block: function { $$.nd = $1.nd; }
| WHILE { add('K'); is_loop = 1;} '(' condition ')''{' body '}' { 
	$$.nd = mknode($4.nd, $7.nd, $1.name, 0); 
	sprintf(icg[ic_idx++], "%s", buff);
    sprintf(icg[ic_idx++], BOLDMAGENTA);
	sprintf(icg[ic_idx++], "\nJUMP to %s\n", $4.if_body);
    sprintf(icg[ic_idx++], BOLDBLUE);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body);
    sprintf(icg[ic_idx++], BOLDGREEN);
}
| FOR { add('K'); is_loop = 1;}'(' statement ';' condition ';' statement ')' '{' body '}' {
	struct node *temp = mknode($6.nd, $8.nd, "Condition", 0);
    struct node *temp2 = mknode($4.nd, temp, "Initialisation", 0);  
    $$.nd = mknode(temp2, $11.nd, $1.name, 0);
	sprintf(icg[ic_idx++], "%s", buff);
    sprintf(icg[ic_idx++], BOLDMAGENTA);
	sprintf(icg[ic_idx++], "\nJUMP to %s\n", $6.if_body);
    sprintf(icg[ic_idx++], BOLDBLUE);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", $6.else_body);
    sprintf(icg[ic_idx++], BOLDGREEN);
}
| IF { add('K'); is_loop = 0;}  '(' condition ')' {
    sprintf(icg[ic_idx++], BOLDBLUE);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body);
    sprintf(icg[ic_idx++], BOLDGREEN);
} '{' body '}' {
    sprintf(icg[ic_idx++], BOLDMAGENTA);
    sprintf(icg[ic_idx++], "\nJUMP to %s\n", $4.after_else_body);
    sprintf(icg[ic_idx++], BOLDBLUE);
    sprintf(icg[ic_idx++], "\nLABEL  %s:\n", $4.else_body);
    sprintf(icg[ic_idx++], BOLDGREEN);
} else { 
	struct node *iff = mknode($4.nd, $8.nd, $1.name, 0); 
	$$.nd = mknode(iff, $11.nd, "conditionalBranch", 0); 
    sprintf(icg[ic_idx++], BOLDBLUE);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.after_else_body);
    sprintf(icg[ic_idx++], BOLDGREEN);
}
| statement ';' { $$.nd = $1.nd; }
| CONSOLELOG { add('K');} '(' console_outputs ')' ';' { struct node *data = mknode(NULL, NULL, $4.name, 0); $$.nd = mknode(NULL, data, "ConsoleLog", 0); } 
;


console_outputs: STRINGVALUE { add('C');}
| IDENTIFIER  { check_declaration($1.name);}
| expression  { $$.nd = $1.nd; }
;


function: FUNCTION { add('F'); } IDENTIFIER { add('I'); } '(' parameterList ')' '{' body return '}' {
    $9.nd = mknode($9.nd, $10.nd, "FunctionBody", 0);
    struct node *main = mknode($9.nd, $6.nd, $3.name, 0);
    $$.nd = mknode($1.nd, main, "Function", 0);
    sprintf(func_buff, "FUNCTION BEGIN %s\n", $3.name);
}  
;


parameterList: parameter ',' parameterList { $$.nd = mknode($1.nd, $3.nd, "ParameterList", 0); sprintf(func_params[param_idx++], "PARAM %s\n", $1.name); }
| parameter { $$.nd = $1.nd; sprintf(func_params[param_idx++], "PARAM %s\n", $1.name); }
| { $$.nd = $$.nd = mknode(NULL, NULL, "Parameter", 0); }
;


parameter: IDENTIFIER {store_name();} ':' datatype {add('I');} {$4.nd = mknode(NULL, NULL, $4.name, 0); $1.nd = mknode(NULL, NULL, $1.name, 0); $$.nd = mknode($4.nd, $1.nd, "Parameter", 0);}
;


datatype: NUMBERTYPE { insert_type(); }
| STRINGTYPE { insert_type(); }
| BOOLEANTYPE { insert_type(); }
;


else: ELSE { add('K');} '{' body '}' {  struct node *cond = mknode(NULL, NULL, "EndOfConditional", 0); $$.nd = mknode($4.nd, cond, $1.name, 0); }
| { $$.nd = NULL; }
;


condition: condition and_or condition { $$.nd = mknode($1.nd, $3.nd, $2.name, 0); }
| value relop value { 
	$$.nd = mknode($1.nd, $3.nd, $2.name, 0);
	if(is_loop) {
		sprintf($$.if_body, "L%d", label++);
        sprintf(icg[ic_idx++], BOLDBLUE);
		sprintf(icg[ic_idx++], "\nLABEL %s:", $$.if_body);
        sprintf(icg[ic_idx++], BOLDGREEN);
		sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", $1.name, $2.name, $3.name, label);
		sprintf($$.else_body, "L%d", label++);
	} else {
		sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", $1.name, $2.name, $3.name, label, label+1);
		sprintf($$.if_body, "L%d", label++);
		sprintf($$.else_body, "L%d", label++);
		sprintf($$.after_else_body, "L%d", label++);
	}
}
| value { $$.nd = $1.nd;}
| TRUE { add('K');} {$$.nd = NULL; }
| FALSE { add('K');} {$$.nd = NULL; }
;


statement: declaration IDENTIFIER { store_name(); } ':' datatype {add('I');} init {
    $5.nd = mknode(NULL, NULL, $5.name, 0); //making for datatype
	$2.nd = mknode(NULL, NULL, $2.name, 0); //making for identifier
	$1.nd = mknode($5.nd, $2.nd, $1.name, 0); //making for the declaration
	int t = check_types($5.name, $7.type); //here we're checking types
	// printf("%s\n", $5.name);
	// printf("%s\n", $6.type);
	// printf("%d\n", t);
	if(t>0) {
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1);sem_errors++;
		if(t == 1) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - number and string\n", countn+1);
			sem_errors++;
        }
		else if(t == 2) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - string and number\n", countn+1);
			sem_errors++;
        }  
		else if(t == 3) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - number and boolean\n", countn+1);
			sem_errors++;
        }  
		else if(t == 4) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - boolean and number\n", countn+1);
			sem_errors++;
        }  
		else if(t == 5) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - boolean and string\n", countn+1);
			sem_errors++;
        }  
		else if(t == 6) {
            sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration - string and boolean\n", countn+1);
			sem_errors++;
        }   
		else {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Declaration\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		$$.nd = mknode($2.nd, $7.nd, "Initialisation", 0);
		
	}
    $2.value = $7.value;
    $2.nd->value = $7.value;
    set_value($2.name, $7.value);
	sprintf(icg[ic_idx++], "%s = %s\n", $2.name, $7.name);
} 
| IDENTIFIER '=' expression { 
	if(check_declaration($1.name)) {
		$1.nd = mknode(NULL, NULL, $1.name, 0);  
		char *id_type = get_type($1.name); 
		if(strcmp(id_type, $3.type)) {
			//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;	
			int t =  check_types(id_type,$3.type); 
			if(t>0) { 
			if(t == 1) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - number and string\n", countn+1); 
				sem_errors++;
			}
			else if(t == 2) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - string and number\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 3) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - number and boolean\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 4) {
				 sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - boolean and number\n", countn+1); 
				 sem_errors++;
			}  
			else if(t == 5) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - boolean and string\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 6) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Assignment - string and boolean\n", countn+1); 
				sem_errors++;
			}   
        }
		}
		else {
			$$.nd = mknode($1.nd, $3.nd, "=", 0);
            $1.value = $3.value;
            $1.nd->value = $3.value;
            set_value($1.name, $3.value);
            sprintf(icg[ic_idx++], "%s = %s\n", $1.name, $3.name);
		}
	}
}
| IDENTIFIER relop expression { 
	if(check_declaration($1.name)) {
		//$1.nd = mknode(NULL, NULL, $1.name);  
		char *id_type = get_type($1.name); 
		if(strcmp(id_type, $3.type)) {
			int t =  check_types(id_type,$3.type); 
			if(t>0) { 
			if(t == 1) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - number and string\n", countn+1); 
				sem_errors++;
			}
			else if(t == 2) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - string and number\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 3) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - number and boolean\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 4) {
				 sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - boolean and number\n", countn+1); 
				 sem_errors++;
			}  
			else if(t == 5) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - boolean and string\n", countn+1); 
				sem_errors++;
			}  
			else if(t == 6) {
				sprintf(errors[sem_errors], "Line %d: Type Mismatch in Relational Operation - string and boolean\n", countn+1); 
				sem_errors++;
			}   
        }
	}
	$1.nd = mknode(NULL, NULL, $1.name, 0); 
	$$.nd = mknode($1.nd, $3.nd, $2.name, 0); 
	}
}
| IDENTIFIER INC { 
	if(check_declaration($1.name)){
		char* x=get_type($1.name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot increment type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	$1.nd = mknode(NULL, NULL, $1.name, 0); $2.nd = mknode(NULL, NULL, $2.name, 0); $$.nd = mknode($1.nd, $2.nd, "Iterator", 0);
	sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var);
	temp_var++;
}
| IDENTIFIER DEC {
	if(check_declaration($1.name)){
		char* x=get_type($1.name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot decrement type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	$1.nd = mknode(NULL, NULL, $1.name, 0); $2.nd = mknode(NULL, NULL, $2.name, 0); $$.nd = mknode($1.nd, $2.nd, "Iterator", 0); 
	sprintf(buff,"t%d = %s + 1\n%s = t%d\n",temp_var,$1.name,$1.name,temp_var); temp_var++;
}
| INC IDENTIFIER { 
	if(check_declaration($1.name)){
		char* x=get_type($1.name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot decrement type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	$1.nd = mknode(NULL, NULL, $1.name, 0); $2.nd = mknode(NULL, NULL, $2.name, 0); $$.nd = mknode($1.nd, $2.nd, "Iterator", 0);
	sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var); temp_var++;
}
| DEC IDENTIFIER { 
	if(check_declaration($1.name)){
		char* x=get_type($1.name); 
		if(strcmp(x, "number") != 0) { 
			sprintf(errors[sem_errors], "Line %d: Cannot decrement type %s (only number)\n", countn+1, x); 
			sem_errors++;
		} 
	}
	$1.nd = mknode(NULL, NULL, $1.name, 0); $2.nd = mknode(NULL, NULL, $2.name, 0); $$.nd = mknode($1.nd, $2.nd, "Iterator", 0);
	sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var); temp_var++;
}
;


declaration: LET { add('K');}
| VAR { add('K');}
| CONST { add('K');}
;


init: '=' value { $$.nd = $2.nd; sprintf($$.type, "%s", $2.type); strcpy($$.name, $2.name); $$.value = $2.value; $$.nd->value = $2.value; }
| '=' expression { $$.nd = $2.nd; sprintf($$.type, "%s", $2.type); strcpy($$.name, $2.name); $$.value = $2.value; $$.nd->value = $2.value; }
| { sprintf($$.type, "%s", "null"); $$.nd = mknode(NULL, NULL, "NULL", 0); strcpy($$.name, "NULL"); }
;


expression : expression addops term { 
	if(strcmp($1.type, $3.type)){
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;
		if(!strcmp($1.type, "number") && !strcmp($3.type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "string") && !strcmp($3.type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "boolean") && !strcmp($3.type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "boolean") && !strcmp($3.type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "number") && !strcmp($3.type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "string") && !strcmp($3.type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name, 0);
	}
	sprintf($$.name, "t%d", temp_var);
	temp_var++;
    $$.value = $1.value + $3.value;
    $$.nd->value = $$.value;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
}
| term { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; $$.value = $1.value; $$.nd->value = $1.value; }
;


term : term mulops factor { 
	if(strcmp($1.type, $3.type)){
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;
		if(!strcmp($1.type, "number") && !strcmp($3.type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "string") && !strcmp($3.type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "boolean") && !strcmp($3.type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "boolean") && !strcmp($3.type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "number") && !strcmp($3.type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "string") && !strcmp($3.type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name, 0);
	}
	sprintf($$.name, "t%d", temp_var);
	temp_var++;
    $$.value = $1.value * $3.value;
    $$.nd->value = $$.value;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
}
| factor { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; $$.nd->value = $1.value; }
; 


factor : base exponent base { 
	if(strcmp($1.type, $3.type)){
		//sprintf(errors[sem_errors], "Line %d: Type mismatch in expression\n", countn+1); sem_errors++;
		if(!strcmp($1.type, "number") && !strcmp($3.type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "string") && !strcmp($3.type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "boolean") && !strcmp($3.type, "number")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and number\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "boolean") && !strcmp($3.type, "string")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - boolean and string\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "number") && !strcmp($3.type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - number and boolean\n", countn+1);
			sem_errors++;
		}
		else if(!strcmp($1.type, "string") && !strcmp($3.type, "boolean")) {
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression - string and boolean\n", countn+1);
			sem_errors++;
		}
		else{
			sprintf(errors[sem_errors], "Line %d: Type Mismatch in Expression.\n", countn+1);
			sem_errors++;
		}
	} 
	else {
		sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name, 0);
	}
	sprintf($$.name, "t%d", temp_var);
	temp_var++;
    $$.value = pow($1.value, $3.value);
    $$.nd->value = $$.value;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
}
| LOG '(' value ',' value ')' {$$.nd = mknode($3.nd, $5.nd, $1.name, 0); }
| base { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; $$.value = $1.value; $$.nd->value = $1.value; }
;


base : value  { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; $$.value = $1.value; $$.nd->value = $1.value; }
| '(' expression ')'  { strcpy($$.name, $2.name); sprintf($$.type, "%s", $2.type); $$.nd = $2.nd; }
;


and_or : AND { $$.nd = mknode(NULL, NULL, $1.name, 0); }
| OR { $$.nd = mknode(NULL, NULL, $1.name, 0); }
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


number: INTEGER {
    strcpy($$.name, $1.name);
    sprintf($$.type, "%s", "number");
    add('N');
    $$.nd = mknode(NULL, NULL, $1.name, atoi($1.name));
    $$.value = atoi($1.name);
}
| FLOAT {
    strcpy($$.name, $1.name);
    sprintf($$.type, "%s", "number");
    add('N');
    $$.nd = mknode(NULL, NULL, $1.name, atof($1.name)); 
    $$.value = atof($1.name);
}
;


value: number { $$.nd = mknode(NULL, NULL, $1.name, 0); }
| IDENTIFIER {
    strcpy($$.name, $1.name);
    char *id_type = get_type($1.name);
    sprintf($$.type, "%s", id_type);
    check_declaration($1.name);
    $$.nd = mknode(NULL, NULL, $1.name, 0);
    q = search($1.name);
    if(q==-1) {
        $$.value = get_value($1.name);
        $$.nd->value = $$.value;
    }
}
| STRINGVALUE { strcpy($$.name, $1.name); sprintf($$.type, "string"); add('C'); $$.nd = mknode(NULL, NULL, $1.name, 0); }
| TRUE { add('K');} {$$.nd = mknode(NULL, NULL, $1.name, 0);}
| FALSE { add('K');} {$$.nd = mknode(NULL, NULL, $1.name, 0);}
| SCAN { add('K');} '('')' { $$.nd = mknode(NULL, NULL, "scan", 0); }
;


return: RETURN { add('K');} value ';'  { 
    $1.nd = mknode(NULL, NULL, "return", 0);
    $$.nd = mknode($1.nd, $3.nd, "ReturnStatement", 0);
    sprintf(icg[ic_idx++], BOLDYELLOW);
    sprintf(icg[ic_idx++], "\nRETURN %s\n", $3.name);
}
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

	printIntermediateCode();
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
        if(ptr->value != 0) {
            printf("%s",ptr->token);
            printf(BOLDMAGENTA);
            printf(" (Value -> %0.1f)",ptr->value);
            printf(RESET);
        }
        else {
            printf("%s",ptr->token);
        }
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

struct node* mknode(struct node *left, struct node *right, char *token, float value) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	newnode->value = value;
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

void printIntermediateCode() {
	printf("\n\n");
    printf(RESET);
	printf("\033[4mIntermediate Code Generation\033[24m\n");
    printf(BOLDYELLOW);
    printf("%s", func_buff);
    for(int i = 0; i < param_idx; i++) {
        printf("%s", func_params[i]);
    }
    printf(BOLDGREEN);
    printf("\n");
	for(int i = 0; i < ic_idx; i++){
		printf("%s", icg[i]);
	}
}

float get_value(char *var){
    for(int i=0; i<count; i++) {
        if(!strcmp(symbol_table[i].id_name, var)) {
            return symbol_table[i].value;
        }
    }
    return 0;
}

void set_value(char *var, float value){
    for(int i=0; i<count; i++) {
        if(!strcmp(symbol_table[i].id_name, var)) {
            symbol_table[i].value = value;
            return;
        }
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
	if(!strcmp(type1, "number") && !strcmp(type2, "string"))
		return 1;
	if(!strcmp(type1, "string") && !strcmp(type2, "number"))
		return 2;
	if(!strcmp(type1, "number") && !strcmp(type2, "boolean"))
		return 3;
	if(!strcmp(type1, "boolean") && !strcmp(type2, "number"))
		return 4;
	if(!strcmp(type1, "boolean") && !strcmp(type2, "string"))
		return 5;
	if(!strcmp(type1, "string") && !strcmp(type2, "boolean"))
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
			if(!strcmp(reserved[i], strdup(id_name))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword\n", countn+1, id_name);
				sem_errors++;
				return;
			}
		}
	}
	char *qtext;
	if(c =='I') qtext = id_name;
	else qtext = yytext;
    q=search(qtext);
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
			symbol_table[count].id_name=strdup(id_name);
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
		else if(c == 'N') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("number");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("NumberLiteral");
			count++;
		}
    }
    else if(c == 'I' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed\n", countn+1, id_name);
		sem_errors++;
    }
}

void insert_type() {
	strcpy(type, yytext);
}

void store_name() {
	strcpy(id_name, yytext);
}