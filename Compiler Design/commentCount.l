
%{
int single=0, multiline =0;
%}


%%


"//".*"\n" { single++;}
"/*".*[\n]*.*"*/" { multiline++;}
.;

%%


int main()
{
 yyin = fopen("comments.cpp","r");
 yylex(); //calling the rules section
 printf(" Single line comments = %d, multiline comments = %d", single, multiline);
 fclose(yyin);
}

int yywrap()	{
	return 1;
}