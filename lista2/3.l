%{
    #include <stdio.h>
    int yylex();
    int yywrap();

    int docs = 0;
%}

%x IN_COMMENT
%x IN_DOCS

docSingleLine \/\/(\/|!).*
docMultilineOpen \/\*(\*|!)

singleLine \/\/.*
multilineOpen \/\*

multilineClose \*\/

%%

{docSingleLine}         { if (docs) ECHO; }
{singleLine}            ;
{docMultilineOpen}      { if (docs) ECHO; BEGIN(IN_DOCS); }
{multilineOpen}         { BEGIN(IN_COMMENT); }

<IN_DOCS>{
.|\n                    { if(docs) ECHO; }
{multilineClose}        { if(docs) ECHO; BEGIN(INITIAL); }
}

<IN_COMMENT>{
.|\n                    ;
{multilineClose}        { BEGIN(INITIAL); }
}

%%

int yywrap() {
    return 1;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        docs = 1;
    }
    return yylex();
}