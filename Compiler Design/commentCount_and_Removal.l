%{ 
#include<stdio.h>
int single = 0;
int multi = 0;
%} 
  
/*Rule Section*/

%% 
(\"(\\.|[^"\\])*\") {fprintf(yyout,"%s",yytext);}
\/\/.* {printf("Single Line Comment : %s\n",yytext); single++;}
"/*"([^*]|\*+[^*/])*\*+"/" {printf("Multi Line Comment : %s\n",yytext); multi++;}
%% 
  
int main() 
{ 
	yyin = fopen("comments.cpp", "r");
	yyout=fopen("out.cpp","w");
    // The function that starts the analysis 
    yylex(); 
    printf("\nNo. of single line comments = %d\n", single);
    printf("\nNo. of multi line comments = %d\n", multi);   
    return 0;
      
}

int yywrap()	{
	return 1;
}