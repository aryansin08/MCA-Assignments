%{
	int integers = 0;
	int floating = 0;
%}

/* Rule Section */
DIGIT [0-9] 
%% 
  
\+?{DIGIT}+             integers++; 
-{DIGIT}+               integers++; 
  
\+?{DIGIT}*\.{DIGIT}+   floating++; 
-{DIGIT}*\.{DIGIT}+     floating++; 
. ;    
%%

int main()	{
	yyin = fopen("input.txt", "r");
    // The function that starts the analysis 
    yylex(); 
	printf("No of Integers are %d", integers);
	printf("\nNo of Floating Point Numbers are %d", floating);  
    return 0;
      
}

int yywrap()	{
	return 1;
}