#include <stdio.h>

int main() {
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int matrix[rows][columns];

    // Input the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of rows and columns
    int rowSum[rows];
    int columnSum[columns];

    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < columns; j++) {
            rowSum[i] += matrix[i][j];
        }
    }

    for (int j = 0; j < columns; j++) {
        columnSum[j] = 0;
        for (int i = 0; i < rows; i++) {
            columnSum[j] += matrix[i][j];
        }
    }

    // Display the sum of rows
    printf("Sum of rows:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }

    // Display the sum of columns
    printf("Sum of columns:\n");
    for (int j = 0; j < columns; j++) {
        printf("Column %d: %d\n", j + 1, columnSum[j]);
    }

    return 0;
}
