#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];

    inputFile = fopen("input.c", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.c", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Skip lines that start with #
        if (line[0] != '#') {
            fputs(line, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Preprocessor directives removed successfully.\n");
    return 0;
}
