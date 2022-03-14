%{
   #include<stdio.h>
   #include<stdlib.h>
   int yylex();
   int yyerror();
%}

%token Num Id NewLine
%left '+' '-'
%left '*' '/'

%%

start: expr NewLine {printf("\nThis Expression is Valid. \n\n");exit(0);}
      ;

expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | Num
    | Id
    ;

%%

int yyerror(char const *s)
{
   printf("\n\nSorry! This is an Invalid Expressions.\n");
   printf("----------------------------------------------\n");
   return 1;
}

int main()
{
   printf("----------------------------------------------\n");
   printf("\n\nEnter any Arithmetic Expression : ");
   yyparse();
   return 0;
   
}   
   