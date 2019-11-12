%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "stack/stack.h"
    int yylex();
    int yywrap();

    Stack* stack;
    int error = 0;

    int power(int base, unsigned int exponent) {
        int res = 1;
        for (int i = 0; i < exponent; i++) res *= base;
        return res;
    }
%}

%x ISERROR

%%
-?[0-9]+        push(stack, atoi(yytext));
\+              {
                    push(stack, pop(stack, &error) + pop(stack, &error));
                    if (error) {
                        printf("Too few arguments\n");
                        BEGIN(ISERROR);
                    }
                }

\-              {
                    int m1 = pop(stack, &error);
                    int m2 = pop(stack, &error);
                    push(stack, m2 - m1);
                    if (error) {
                        printf("Too few arguments\n");
                        BEGIN(ISERROR);
                    }
                }

\*              {
                    push(stack, pop(stack, &error) * pop(stack, &error));
                    if (error) {
                        printf("Too few arguments\n");
                        BEGIN(ISERROR);
                    }
                }

\/              {
                    int divisor = pop(stack, &error);
                    int divided = pop(stack, &error);
                    if (error) {
                        printf("Too few arguments\n");
                        BEGIN(ISERROR);
                    } else if (divisor == 0) {
                        printf("Can't divide by 0\n");
                        BEGIN(ISERROR);
                    } else {
                        push(stack, divided / divisor);
                            if (error) {
                            printf("Too few arguments\n");
                            BEGIN(ISERROR);
                        }
                    }
                }

\%              {
                    int divisor = pop(stack, &error);
                    int divided = pop(stack, &error);
                    if (error) {
                        printf("Too few arguments\n");
                        BEGIN(ISERROR);
                    } else if (divisor == 0) {
                        printf("Can't divide by 0\n");
                        BEGIN(ISERROR);
                    } else {
                        push(stack, divided % divisor);
                            if (error) {
                            printf("Too few arguments\n");
                            BEGIN(ISERROR);
                        }
                    }
                }

\^              {
                    int exp = pop(stack, &error);
                    if (error) {
                        printf("Too few arguments\n");
                        BEGIN(ISERROR);
                    } else if (exp < 0) {
                        printf("Can't rise to negative power\n");
                        BEGIN(ISERROR);
                    } else {
                        push(stack, power(pop(stack, &error), exp));
                            if (error) {
                            printf("Too few arguments\n");
                            BEGIN(ISERROR);
                        }
                    }
                }

\n              {
                    if (stack->index == 1) printf("Result: %d\n", pop(stack, &error));
                    else {
                        printf("Too much arguments\n");
                        while (stack->index) {
                            pop(stack, &error);
                        }
                        error = 0;
                    }
                }

[^[:blank:]]    printf("Symbol not regonized: %s", yytext);
[[:blank:]]     ;

<ISERROR>.*     ;
<ISERROR>\n     {
                    error = 0;
                    free(stack->memory);
                    free(stack);
                    stack = new_stack(32);
                    BEGIN(INITIAL);
}

%%

int yywrap() {
    return 1;
}

int main() {
    stack = new_stack(32);
    return yylex();
}