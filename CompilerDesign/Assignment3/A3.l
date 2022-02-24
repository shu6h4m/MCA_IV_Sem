%{
	#include<stdio.h>
	int chabi;
%}

%%
[a-z] { char c = yytext[0];
		c += chabi;
		if (c > 'z') c -= 26;
		fprintf (yyout,"%c", c);
	  }

[A-Z] { char c = yytext[0];
		c += chabi;
		if (c > 'Z') c -= 26;
		fprintf (yyout,"%c", c);
	  }
%%

int main()
{
	printf("Enter your key: ");
	scanf("%d",&chabi);
	yyin=fopen("plain.txt","r");
    yyout = fopen("cipher.txt", "w");
	yylex();
    return 0;
}

int yywrap()
{
    return 1;
}