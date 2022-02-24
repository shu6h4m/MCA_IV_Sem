%{
  #include<stdio.h>
  void yyerror();
%}
  
  
%token Num
  
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'


%%
  
Start: Expr					{printf("\nResult=%d\n", $$); return 0; };
 
Expr:Expr'+'Expr {$$=$1+$3;}

	|Expr'-'Expr {$$=$1-$3;}

	|Expr'*'Expr {$$=$1*$3;}

	|Expr'/'Expr {$$=$1/$3;}

	|Expr'%'Expr {$$=$1%$3;}

	|'('Expr')' {$$=$2;}

	| Num	{$$=$1;}
;
  
%%
  

int main()
{
   printf("\nEnter Arithmetic Expression\n");
   yyparse();
   return 0;
}

void yyerror()
{
   printf("\nEntered arithmetic expression is Invalid\n\n");
}