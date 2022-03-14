%{
#include <stdio.h>

void yyerror (const char *str) {
	fprintf(stderr, "error: %s\n", str);
}

int yywrap() {
	return 1;
}

main() {
	yyparse();
}

%}

%%

%token DELETE FROM IDENTIFIER WHERE ANDOR;

line: delete using '\n' { printf("Syntax Correct\n"); };

delete: DELETE;

using: FROM IDENTIFIER WHERE condition | FROM IDENTIFIER;

op : '=' | '<' | '>' ;

condition: IDENTIFIER op IDENTIFIER | IDENTIFIER op IDENTIFIER ANDOR condition ;

%%