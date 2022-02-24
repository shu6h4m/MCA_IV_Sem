%{
	#include<stdio.h>
	int numchar=0;
	int numlines=0;
%}

%%
"\n"	{numchar++ ; numlines++;}
.	{numchar++;}
%%

int main()
{
	yyin=fopen("Hello.txt" , "r");
	yylex();
	printf("\n\nNumbers of line are %d\n",numlines);
	printf("\nNumber of Characters are %d\n",numchar);
	return 0;
}

int yywrap()
{
	return 1;
}