%{
#include <stdio.h>
int words=0, chars=0, blanks=0, lines=1;
%}

%option noyywrap

word     [^ \t\n]+
blank    [ \t]
newline  \n

%%
{word}    { words++; chars += yyleng; }
{blank}   { blanks++; chars++; }
{newline} { lines++; chars++; }
.         { chars++; }
%%

int main() {
    printf("Enter text (press Enter then Ctrl+D to end):\n");
    yylex();
    printf("\nAnalysis Results:\n");
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    printf("Blanks: %d\n", blanks);
    printf("Lines: %d\n", lines);
    return 0;
}
