#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char filename1[100], filename2[100];
    char ch;

    // Input source and destination file names
    printf("Enter the source file name: ");
    scanf("%s", filename1);
    printf("Enter the destination file name: ");
    scanf("%s", filename2);

    // Open the source file in read mode
    fp1 = fopen(filename1, "r");
    if (fp1 == NULL) {
        printf("Error: Could not open source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    fp2 = fopen(filename2, "w");
    if (fp2 == NULL) {
        printf("Error: Could not open destination file.\n");
        fclose(fp1);
        return 1;
    }

    // Copy contents character by character
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    printf("File copied successfully.\n");

    // Close both files
    fclose(fp1);
    fclose(fp2);

    return 0;
}

