%{
    #include <stdio.h>
    int yylex();
    int yywrap();
%}

%x INCOMMENT

open \<!--
close -->

%%

{open}          BEGIN(INCOMMENT);
<INCOMMENT>{
.|\n            ;
{close}         BEGIN(INITIAL);
}

%%

int yywrap() {
    return 1;
}

int main() {
    return yylex();
}