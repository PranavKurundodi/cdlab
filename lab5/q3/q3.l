%{
#include <stdio.h>
int pos_int=0, neg_int=0, pos_float=0, neg_float=0;
%}

%option noyywrap

digit    [0-9]
int      [+-]?{digit}+
float    [+-]?{digit}*\.{digit}+([eE][+-]?{digit}+)?

%%
{int}    { if (yytext[0] == '-') neg_int++; else pos_int++; }
{float}  { if (yytext[0] == '-') neg_float++; else pos_float++; }
.|\n     ;
%%

int main() {
    printf("Enter numbers (Ctrl+D to end):\n");
    yylex();
    printf("+Int: %d\n-Int: %d\n+Float: %d\n-Float: %d\n",
           pos_int, neg_int, pos_float, neg_float);
    return 0;
}
