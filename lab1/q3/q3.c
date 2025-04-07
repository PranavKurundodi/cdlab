#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILENAME_LENGTH 256

int main() {
    char file1_name[MAX_FILENAME_LENGTH];
    char file2_name[MAX_FILENAME_LENGTH];
    char output_name[MAX_FILENAME_LENGTH];

    // Get input filenames from user
    printf("Enter first input filename: ");
    fgets(file1_name, MAX_FILENAME_LENGTH, stdin);
    file1_name[strcspn(file1_name, "\n")] = '\0'; // Remove newline

    printf("Enter second input filename: ");
    fgets(file2_name, MAX_FILENAME_LENGTH, stdin);
    file2_name[strcspn(file2_name, "\n")] = '\0'; // Remove newline

    printf("Enter output filename: ");
    fgets(output_name, MAX_FILENAME_LENGTH, stdin);
    output_name[strcspn(output_name, "\n")] = '\0'; // Remove newline

    FILE *file1 = fopen(file1_name, "r");
    FILE *file2 = fopen(file2_name, "r");
    FILE *output = fopen(output_name, "w");

    if (file1 == NULL) {
        printf("Error opening file: %s\n", file1_name);
        return 1;
    }
    if (file2 == NULL) {
        printf("Error opening file: %s\n", file2_name);
        fclose(file1);
        return 1;
    }
    if (output == NULL) {
        printf("Error creating output file: %s\n", output_name);
        fclose(file1);
        fclose(file2);
        return 1;
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int file1_has_more, file2_has_more;

    do {
        // Read from both files
        file1_has_more = fgets(line1, MAX_LINE_LENGTH, file1) != NULL;
        file2_has_more = fgets(line2, MAX_LINE_LENGTH, file2) != NULL;

        // Write lines alternately
        if (file1_has_more) {
            fputs(line1, output);
        }
        if (file2_has_more) {
            fputs(line2, output);
        }
    } while (file1_has_more || file2_has_more);

    fclose(file1);
    fclose(file2);
    fclose(output);

    printf("Files merged successfully to %s\n", output_name);
    return 0;
}
