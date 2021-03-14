%{
	#include<stdlib.h>
	#include "y.tab.h"
%}

%%

[0-9]+(\.[0-9]+)? {yylval.f=atof(yytext); return FLOAT;}
. return *yytext;
\n return NEWLINE;

%%

int yywrap()
{
	return 1;
}