#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long getFileSize(FILE *file) {
    fseek(file, 0, SEEK_END); // Move to end of file
    long size = ftell(file);   // Get current position (which is size)
    fseek(file, 0, SEEK_SET);  // Move back to beginning
    return size;
}

void reverseFileContents(const char *inputFile, const char *outputFile) {
    FILE *inFile, *outFile;
    char *buffer;
    long fileSize;
    size_t result;

    // Open input file in read mode
    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Get file size
    fileSize = getFileSize(inFile);
    printf("Size of input file: %ld bytes\n", fileSize);

    // Allocate memory for file content
    buffer = (char *)malloc(sizeof(char) * fileSize);
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        fclose(inFile);
        exit(1);
    }

    // Read file content into buffer
    result = fread(buffer, 1, fileSize, inFile);
    if (result != fileSize) {
        printf("Error reading file!\n");
        free(buffer);
        fclose(inFile);
        exit(1);
    }

    // Open output file in write mode
    outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        printf("Error opening output file!\n");
        free(buffer);
        fclose(inFile);
        exit(1);
    }

    // Write buffer in reverse order to output file
    for (long i = fileSize - 1; i >= 0; i--) {
        fputc(buffer[i], outFile);
    }

    // Clean up
    free(buffer);
    fclose(inFile);
    fclose(outFile);

    printf("File reversed successfully and saved to %s\n", outputFile);
}

int main() {
    char inputFileName[100], outputFileName[100];

    printf("Enter the input file name: ");
    scanf("%99s", inputFileName);
    
    printf("Enter the output file name: ");
    scanf("%99s", outputFileName);

    reverseFileContents(inputFileName, outputFileName);

    return 0;
}
