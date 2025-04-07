#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
#define NUM_KEYWORDS (sizeof(keywords)/sizeof(keywords[0]))

int isKeyword(const char *word) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void printUpper(const char *word) {
    for (int i = 0; word[i]; i++) {
        putchar(toupper(word[i]));
    }
    printf("\n");
}

int main() {
    FILE *inputFile;
    char word[100];
    int c, i = 0;

    inputFile = fopen("input.c", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    printf("Keywords found in the file (in uppercase):\n");
    
    while ((c = fgetc(inputFile)) != EOF) {
        if (isalpha(c)) {
            word[i++] = c;
        } else {
            if (i > 0) {
                word[i] = '\0';
                if (isKeyword(word)) {
                    printUpper(word);
                }
                i = 0;
            }
        }
    }

    // Check for keyword at end of file
    if (i > 0) {
        word[i] = '\0';
        if (isKeyword(word)) {
            printUpper(word);
        }
    }

    fclose(inputFile);
    return 0;
}
