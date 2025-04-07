#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    int lastWasSpace = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == ' ' || ch == '\t') {
            if (!lastWasSpace) {
                fputc(' ', outputFile);
                lastWasSpace = 1;
            }
        } else {
            fputc(ch, outputFile);
            lastWasSpace = 0;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File processed successfully.\n");
    return 0;
}
