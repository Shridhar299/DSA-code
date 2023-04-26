#include <stdio.h>
#include <stdlib.h>

#define R 10
#define C 1000

void read_user(char lines[R][C], int *num_lines);
void disp_long_line(char lines[R][C], int num_lines);

int main()
{
    char lines[R][C];
    int num_lines = 0;
    read_user(lines, &num_lines);
    disp_long_line(lines, num_lines);

    return 0;
}

void read_user(char lines[R][C], int *num_lines)
{
    int i;

    printf("Enter text lines (maximum %d lines):\n", R);

    for (i = 0; i < R; i++) {
        if (fgets(lines[i], C, stdin) == NULL) {
            break;
        }

        (*num_lines)++;
    }
}



void disp_long_line(char lines[R][C], int num_lines)
{
    int i, max_len = 0;
    char *longest_line;

    for (i = 0; i < num_lines; i++) {
        if (strlen(lines[i]) > max_len) {
            max_len = strlen(lines[i]);
            longest_line = lines[i];
        }
    }

    printf("The longest line is:\n%s\n", longest_line);
}
