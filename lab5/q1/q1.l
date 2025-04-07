%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%option noyywrap

vowel    [aeiouAEIOU]
consonant [bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]

%%
{vowel}      { vowels++; }
{consonant}  { consonants++; }
.|\n         ;
%%

int main() {
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}
