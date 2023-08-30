#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printRepeatedCharacterIndices(char arr[], int size) {
    bool visited[256] = { false }; // Assuming ASCII characters

    for (int i = 0; i < size; i++) {
        if (visited[arr[i]]) {
            printf("Character '%c' is repeated at index %d\n", arr[i], i);
        } else {
            visited[arr[i]] = true;
        }
    }
}

int main() {
    char input[] = "programming";

    int size = strlen(input);

    printf("Repeating characters and their indices:\n");
    printRepeatedCharacterIndices(input, size);

    return 0;
}
