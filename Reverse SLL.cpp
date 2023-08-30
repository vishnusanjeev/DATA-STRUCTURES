#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct ListNode* insertAtBeginning(struct ListNode* head, int data) {
    struct ListNode* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to reverse a singly linked list
struct ListNode* reverseLinkedList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Change next of current node
        prev = current; // Move prev to current node
        current = next; // Move current to next node
    }

    return prev; // New head of reversed list
}

// Function to print the linked list
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    printf("Original linked list:\n");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("Reversed linked list:\n");
    printLinkedList(head);

    return 0;
}
