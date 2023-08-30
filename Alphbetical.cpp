#include <stdio.h>
#include <string.h>

// Function to sort a string in alphabetical order
void sortString(char str[]) {
    int length = strlen(str);
    char temp;

    // Bubble sort algorithm for sorting characters
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // Swap characters
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove newline character from input
    inputString[strcspn(inputString, "\n")] = '\0';

    sortString(inputString);

    printf("Sorted string in alphabetical order: %s\n", inputString);

    return 0;
}
