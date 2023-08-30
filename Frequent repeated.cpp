#include <stdio.h>
#include <stdbool.h>

// Function to find and print the count of frequently repeated numbers
void printFrequentCounts(int arr[], int size) {
    bool visited[size];
    int count[size];

    for (int i = 0; i < size; i++) {
        visited[i] = false;
        count[i] = 1;
    }

    for (int i = 0; i < size; i++) {
        if (visited[i]) {
            continue;
        }

        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count[i]++;
            }
        }
    }

    printf("Frequently repeated numbers and their counts:\n");
    for (int i = 0; i < size; i++) {
        if (count[i] > 1) {
            printf("%d appeared %d times\n", arr[i], count[i]);
        }
    }
}

int main() {
    int input[] = { 1, 2, 3, 2, 4, 1, 3, 5, 5, 1 };
    int size = sizeof(input) / sizeof(input[0]);

    printFrequentCounts(input, size);

    return 0;
}
n