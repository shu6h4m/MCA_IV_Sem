%{
	#include<stdio.h>
	int sinLine=0 , mulLine=0;
	
%}


%%

["]([^"]|\\(.|\n))*["] {}
"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/" 	{ mulLine++;}
"//"(.*)[\n]+				{sinLine++;}
.|"\n"	{};

%%


int main()
{
	yyin=fopen("comments.cpp","r");
	yylex();
    	printf("\n\nSingle line comments in given file are : %d",sinLine);
	printf("\nMultiline comments in the given file are: %d",mulLine);
	printf("\n\n");
	return 0;
}

int yywrap()
{
    return 1;
}