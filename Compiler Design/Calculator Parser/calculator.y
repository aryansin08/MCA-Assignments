%{
#include<stdio.h>
#include<stdlib.h>
%}

%union
{
	float f;
}
%token FLOAT NEWLINE
%type <f> start expr FLOAT
%left '+' '-'
%left '*' '/'

%%

start: expr NEWLINE {
			printf("Valid Expression\nOutput: %f\n", $$);
			exit(0);
		    }
     ;

expr: expr '+' expr {$$=$1+$3;}
    | expr '-' expr {$$=$1-$3;}
    | expr '*' expr {$$=$1*$3;}
    | expr '/' expr {if ($3==0)
                     {
                       printf("Result is not defined.\n");
                       exit(1);
                     }
		     $$=$1/$3;
		    }
    | '('expr')'     {$$=$2;}
    | FLOAT
    | '-' expr       {$$=-$2;}
    | '+' expr       {$$=$2;}
    ;

%%

int yyerror(char const *s)
{
	printf("Expression is not valid");
	return 1;
}

int main()
{
	printf("Enter an arithmetic expression\n");
	yyparse();
	return 0;
}

