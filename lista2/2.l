%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int yylex();
    int yywrap();
    
    char* concat(const char* str1, const char* str2) {
        char* result = malloc(strlen(str1) + strlen(str2) + 1);
        
        strcpy(result, str1);
        strcat(result, str2);
        
        return result;
    }
    
    int wrongComment = 0;
    char* comment = "";
%}

%x IN_COMMENT
%x IN_CDATA
%x IN_PARAMETER

open \<!--
close -->

cdataOpen \<!\[CDATA\[
cdataClose ]]>

%%

\"              BEGIN(IN_PARAMETER);
<IN_PARAMETER>{
\"              { ECHO; BEGIN(INITIAL); } 
.               ECHO;
}


{cdataOpen}     { ECHO; BEGIN(IN_CDATA); }
<IN_CDATA>{
.|\n            ECHO;
{cdataClose}    { ECHO; BEGIN(INITIAL); }
}

{open}          { comment = "<--"; wrongComment = 0; BEGIN(IN_COMMENT); } 
<IN_COMMENT>{
{close}         { if (wrongComment) { printf("%s-->", comment); } comment = ""; wrongComment = 0; BEGIN(INITIAL); }
--              { wrongComment = 1; comment = concat(comment, yytext); }
.|\n            { comment = concat(comment, yytext); }
}

%%

int yywrap() {
    return 1;
}

int main() {
    return yylex();
}