%{ 
    #include <stdio.h>
    #include "lex.yy.c"
    int yylex();
    int yyerror();
%} 

%token NUMBER ID RELOP BOOL Q C STRING NL
%left '+' '-'
%left '*' '/'
%left RELOP
%right Q
%right C
%%
S : ternary NL   { 
            printf("%s",yytext);
            printf("\nValid Ternary Expression\n"); 
            return 0; 
        };
ternary: expression Q expression C expression
    ;
expression: ID
    | '(' expression ')'
    | terminal
    | expression RELOP expression 
    ;
terminal: BOOL
    | NUMBER
    | STRING
    ;
%%

int main() 
{ 
	printf("Enter the expression : \n");
	yyparse(); 
    return 0;
} 

int yyerror(char* s) 
{ 
	printf("\nInvalid Ternary Expression.\n"); 
} 