%{
#include <stdio.h>
int scanfs=0, printfs=0;
%}

%option noyywrap

scanf    "scanf"
printf   "printf"

%%
{scanf}  { scanfs++; printf("READ"); }
{printf} { printfs++; printf("WRITE"); }
.|\n     { ECHO; }
%%

int main() {
    printf("Enter C code line by line (type 'exit' to quit):\n");
    char buffer[1024];
    while(1) {
        printf("> ");
        if(!fgets(buffer, sizeof(buffer), stdin)) break;
        if(strncmp(buffer, "exit", 4) == 0) break;
        
        yy_scan_string(buffer);
        yylex();
        yy_delete_buffer(YY_CURRENT_BUFFER);
    }
    printf("\nTotal replacements:\nscanf→READ: %d\nprintf→WRITE: %d\n",
           scanfs, printfs);
    return 0;
}
