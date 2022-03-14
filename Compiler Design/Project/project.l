%{
#include <stdio.h>
#include "project.tab.h"
extern int yylval;
%}

%%
(d|D)(e|E)(l|L)(e|E)(t|T)(e|E)			return DELETE;     // delete case insensitive
(f|F)(r|R)(o|O)(m|M)					return FROM;			// from case insensitive
(w|W)(H|h)(e|E)(r|R)(e|E)				return WHERE;    // where case insensitive  
(A|a)(n|N)(d|D)							return ANDOR;    // and case insensitive  
(o|O)(r|R)								return ANDOR;    // or case insensitive  
[=]										return *yytext;
[<]										return *yytext;
[>]										return *yytext;
[a-zA-Z][a-zA-Z0-9]*					return IDENTIFIER;
\n										return *yytext;
[ \t]+					
%%