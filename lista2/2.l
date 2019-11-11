%{
    #include <stdio.h>
    int yylex();
    int yywrap();
%}

%x INCOMMENT

%%

\<!--           BEGIN(INCOMMENT);
<ISCOMMENT> {
    \n|.        ;
    -->         BEGIN(INITIAL);
}

%%

int yywrap() {
    return 0;
}

int main() {
    return yylex();
}