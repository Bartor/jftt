%{

    #include<stdio.h>
    int yylex();
    int yywrap();

    int wc = 0, lc = 0;

%}

%%

^[[:blank:]]+   ;
[[:blank:]]+$   ;
[[:blank:]]+    {printf(" ");}

[a-zA-Z]+       {ECHO; wc++}
\n              {printf("\n"); lc++;}

%%

int yywrap() {
    printf("\nWords: %d\nLines: %d", wc, lc);
    return 0;
}

int main() {
    return yylex();
}