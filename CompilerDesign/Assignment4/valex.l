%{

  #include "valex.tab.h"

%}

%%

[0-9]+                    return Num;
[a-zA-Z_][A-Za-z_0-9]*    return Id;
.                         return *yytext;
\n                        return NewLine;

%%

int yywrap(){
  return 1;
}  
