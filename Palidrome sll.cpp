#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the end of the linked list
void insert(struct Node** head, char data) {
    struct Node* newNode = newNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to check if the given string is a palindrome using SLL
bool isPalindrome(struct Node* head) {
    char stack[100];
    int top = -1;

    struct Node* current = head;
    while (current != NULL) {
        stack[++top] = current->data;
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        if (stack[top] != current->data) {
            return false;
        }
        top--;
        current = current->next;
    }

    return true;
}

int main() {
    struct Node* head = NULL;
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        insert(&head, str[i]);
    }

    if (isPalindrome(head)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
