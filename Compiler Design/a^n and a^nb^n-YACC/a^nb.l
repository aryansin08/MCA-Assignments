%{
	#include "y.tab.h"
		/* Program to accept string of the language (a^nb) n>=5*/ 
%}

%%
a return A;
b return B;
. return *yytext;
\n return NEWLINE;
%%

int yywrap()
{
	return 1;
}

