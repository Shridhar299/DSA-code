#include <stdio.h>

void read_mat(int *matrix, int rows, int cols);
void print_mat(int *matrix, int rows, int cols);
void Mult_mat(int *matrix1, int *matrix2, int *result, int rows1, int cols1, int rows2, int cols2);

int main()
{
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of matrix 1:\n");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns of matrix 2:\n");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Multiplication condition not satisfied\n");
        return 0;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    printf("Enter the elements of matrix 1:\n");
    read_mat(&matrix1[0][0], rows1, cols1);

    printf("Enter the elements of matrix 2:\n");
    read_mat(&matrix2[0][0], rows2, cols2);

    Mult_mat(&matrix1[0][0], &matrix2[0][0], &result[0][0], rows1, cols1, rows2, cols2);

    printf("The product of the matrices is:\n");
    print_mat(&result[0][0], rows1, cols2);

    return 0;
}

void read_mat(int *matrix, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", matrix + i * cols + j);
        }
    }
}

void print_mat(int *matrix, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

void Mult_mat(int *matrix1, int *matrix2, int *result, int rows1, int cols1, int rows2, int cols2)
{
    int i, j, k;

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            *(result + i * cols2 + j) = 0;
            for (k = 0; k < cols1; k++) {
                *(result + i * cols2 + j) += *(matrix1 + i * cols1 + k) * *(matrix2 + k * cols2 + j);
            }
        }
    }
}
