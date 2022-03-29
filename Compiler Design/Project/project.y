%{
#include <stdio.h>
#include <stdlib.h>

void yyerror (char *str);
 

int yywrap() {
	return 1;
}

main() {
printf("\nEnter a sql statement\n");
	yyparse();
	system("pause");                
	return 0;    
}


void yyerror (char *str) {       
  printf("Invalid Statement \n");
}
%}

%%

%token DELETE FROM IDENTIFIER WHERE ANDOR CONDITION SEMICOLON TEXT NUMBER;

line: delete from using semicolon'\n' { printf("Syntax Correct\n\n");return 0;};

delete: DELETE;

from: FROM;

using: IDENTIFIER WHERE condition | 
		IDENTIFIER;

condition: IDENTIFIER CONDITION IDENTIFIER |
			IDENTIFIER CONDITION TEXT |
			IDENTIFIER CONDITION NUMBER |
			IDENTIFIER CONDITION IDENTIFIER ANDOR condition |
			IDENTIFIER CONDITION TEXT ANDOR condition |
			IDENTIFIER CONDITION NUMBER ANDOR condition ;

semicolon: SEMICOLON;
%%