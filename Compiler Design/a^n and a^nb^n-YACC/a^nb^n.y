%{ 
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror();
%}

%token A B NEWLINE

%%
START	: A S B NEWLINE {printf("String is in the language"); exit(0);}
		;
S : A S B
  | A B
  | {}
  ;
%%

int yyerror()
{
	printf("String is NOT in the language");
	return 1;
}

int main()
{
	printf("Language {a^nb^n, n>0}\n");
	printf("Enter a string: ");
	yyparse();
	return 0;
}
 