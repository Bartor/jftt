%{

    #include<stdio.h>
    int yylex();
    int yywrap();

    int wc = 0, lc = 0;

%}

%%

^[[:blank:]]+   ;
[[:blank:]]+$   ;
[[:blank:]]+    { printf(" "); }

[a-zA-Z]+       { ECHO; wc++; }
\n              { printf("\n"); lc++; }

%%

int yywrap() {
    printf("\nWords: %d\nLines: %d\n", wc, lc);
    return 1;
}

int main() {
    return yylex();
}