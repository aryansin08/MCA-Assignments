%{
    #include <stdio.h>
    #include <string.h>
    int num_words = 0;
%}

%%
([a-zA-Z0-9])*	{num_words++;}
%%

int main() 
{
    yyin = fopen("input.txt", "r");
    yylex();
    printf("No. of words: %d\n", num_words);
    return 0;
}

int yywrap() 
{
    return 1;
}
