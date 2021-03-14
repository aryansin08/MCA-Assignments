%{ 
#include<stdio.h>
int key;
%} 
  
/*Rule Section*/

%%
([A-Za-z]) {fprintf(yyout,"%c",(yytext[0]+key))%26;}
%% 
  
int main() 
{ 
	scanf("%d", &key);
	yyin = fopen("plain.txt", "r");
	yyout=fopen("cipher.txt","w");
    // The function that starts the analysis 
    yylex();   
    return 0;
      
}

int yywrap()	{
	return 1;
}