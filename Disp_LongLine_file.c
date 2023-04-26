#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 100 // Maximum length of a line in characters
#define NUM_LINES 10 // Number of lines to read

int main() {
    FILE *fp;
    char line[LINE_LENGTH];
    char longest_lines[LINE_LENGTH];
    int longest_length = 0;
    int current_length;
    int line_count = 0;

    // Open the file in read mode
    fp = fopen("input.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read each line from the file until we reach the end of the file or read the desired number of lines
    while (fgets(line, LINE_LENGTH, fp) != NULL && line_count < NUM_LINES) {
        // Determine the length of the current line
        current_length = strlen(line);

        // If the current line is longer than the previous longest line(s), replace them
        if (current_length > longest_length) {
            longest_length = current_length;
            strcpy(longest_lines, line);
        } else if (current_length == longest_length) {
            // If the current line has the same length as the previous longest line(s), append it
            strcat(longest_lines, line);
        }

        // Increment the line count
        line_count++;
    }

    // Print the longest line(s)
    printf("The longest line among the first %d lines in the file:\n%s", NUM_LINES, longest_lines);

    // Close the file
    fclose(fp);

    return 0;
}
