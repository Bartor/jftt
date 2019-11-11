%{
    #include <stdio.h>
    int yylex();
    int yywrap();

    int docs = 0;
%}

%x INCOMMENT

docSingleLine \/\/(\/|!).*\n
docMultilineOpen ^[[:blank:]]*\/\*(\*|!).*(\n)?

singleLine \/\/.*\n
multilineOpen ^[[:blank:]]*\/\*.*(\n)?

multilineClose (!|\*)?\*\/(\n)?

%%

{docSingleLine}         { if (docs) ECHO; }
{singleLine}            ;
{docMultilineOpen}      { if (docs) ECHO; else BEGIN(INCOMMENT); }
{multilineOpen}         { BEGIN(INCOMMENT); }

<INCOMMENT> {
    \n|.    ;
    {multilineClose}    { BEGIN(INITAIL); }
}

%%

int yywrap() {
    return 0;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        docs = 1;
    }
    return yylex();
}