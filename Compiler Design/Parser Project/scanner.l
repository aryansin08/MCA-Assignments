%{ 
    #include "y.tab.h"
    //extern int yylval;
%} 

%%
\"(\\.|[^"\\])*\"      {printf("%s string\n",yytext);return STRING;}
[0-9]+\.?[0-9]*  { 
            //yylval = atoi(yytext); 
            printf("%d number\n",atoi(yytext));
            return NUMBER;
        }
"true"|"false"   {printf("%s boolean\n",yytext);return BOOL;}
[a-zA-Z_][a-zA-Z0-9_]*   {printf("%s identifier\n",yytext); return ID;}
"?"     {printf("%s Question Mark\n",yytext);return Q;}
":"     {printf("%s Colon\n",yytext);return C;}
"<"|"<="|">"|">="|"=="|"!="|"+"|"-"|"*"|"/"|"="     {printf("%s operator\n",yytext);return RELOP;}
[\t ]+       {printf("%s space or tab\n",yytext);}
\n          {printf("%s newLine\n",yytext);return NL;}
.           {printf("%s other chars\n",yytext);return *yytext;}
%%
int yywrap()
{
    return 1;
}
