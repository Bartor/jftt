%option noyywrap
%{
    #include "calc.tab.hpp"
    int yylex();
%}

escapedNewline \\\n

%%
^#(.|{escapedNewline})*\n   ;
{escapedNewline}            ;
[[:blank:]]+                ;
[0-9]+                      { yyval = atoi(yytext); return VALUE; }
\+                          { return PLUS; }
-                           { return MINUS; }
\*                          { return MULT; }
\/                          { return DIV; }
%                           { return MOD; }
\^                          { return POW; }
\(                          { return BRACKET_OPEN; }
\)                          { return BRACKET_CLOSE; }
\n                          { return EOL; }
.                           { return ERR; }
%%