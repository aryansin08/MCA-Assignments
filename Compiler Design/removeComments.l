%{ 
	#include<stdio.h>
%}
  
start \/\* 
end  \*\/ 
  
/*Rule Section*/ 
%% 
   
\/\/(.*) ;  
{start}.*{end} ; 
  
%% 
  
/*Driver function*/ 
int main() 
{ 
yyin=fopen("comments.cpp","r"); 
yyout=fopen("out.c","w"); 
/*call the yylex function.*/ 
yylex(); 
return 0; 
}