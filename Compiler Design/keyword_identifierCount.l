%{#include<iostream.h>
int identifier=0;
int keywords=0;
char ch=0;
%}
digit[0-9]
letter[a-zA-Z_]


%%
"while"|"if"|"else" {keywords++;}   
"int"|"float" {keywords++;}    
{letter}({letter}|{digit})* {
 identifier++;
}


%%
int main()
{
 yyin=fopen("comments.cpp","r");
 yylex();
 printf("Count of Identifiers: %d\n",identifier);
 printf("Count of Keywords: %d",keywords);
 return 0;
}


yywrap(){}