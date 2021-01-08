  
%{ 
#include<stdio.h>
int string_literal = 0;
%} 
  
/*Rule Section*/

%% 
(\"(\\.|[^"\\])*\") {string_literal++;}
%% 
  
int main() 
{ 
	yyin = fopen("input.cpp", "r");
    // The function that starts the analysis 
    yylex(); 
      
    printf("\nNo. of string literals = %d\n", string_literal);   
    return 0;
      
}

int yywrap()	{
	return 1;
}
