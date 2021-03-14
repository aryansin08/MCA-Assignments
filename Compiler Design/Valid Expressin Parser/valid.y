%{
	#include <stdio.h>
	#include <stdlib.h>
	int yylex();
	int yyerror();
%}

%token NUMBER ID NEWLINE
%left '+' '-'
%left '*' '/'

%%
start: expr NEWLINE {printf("Expression is valid.\n"); exit(0);}
	;
expr: expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| '(' expr ')'
	| NUMBER
	| ID
	;
%%

int yyerror() {
	printf("Expression is invalid\n");
	return 1;
}

int main() {
	printf("Enter the arithematic expression:\n");
	yyparse();
	return 0;
}
