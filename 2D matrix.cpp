#include <stdio.h>

// Function to find the largest element in a 2D matrix
int findLargestElement(int matrix[][3], int rows, int cols) {
    int largest = matrix[0][0]; // Initialize largest with the first element

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }
        }
    }

    return largest;
}

int main() {
    int matrix[][3] = {
        { 7, 2, 9 },
        { 4, 5, 1 },
        { 8, 6, 3 }
    };

    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    int largestElement = findLargestElement(matrix, rows, cols);

    printf("The largest element in the matrix is: %d\n", largestElement);

    return 0;
}
