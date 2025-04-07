#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int characters = 0, lines = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        // Check for new line character
        if (ch == '\n') {
            lines++;
        }
    }
    // Close the file
    fclose(file);
    // Print the results
    printf("Number of lines: %d\n", lines);
    printf("Number of characters: %d\n", characters);

    return 0;
}
