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

// Function to insert a new node at the end of the linked list
struct ListNode* insertAtEnd(struct ListNode* head, int data) {
    struct ListNode* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

// Function to insert a new node after a specific node
void insertAfter(struct ListNode* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    
    struct ListNode* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
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
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    printf("Linked list after insertion at beginning:\n");
    printLinkedList(head);

    // Insert nodes at the end
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("Linked list after insertion at end:\n");
    printLinkedList(head);

    // Insert a node after a specific node
    struct ListNode* nodeToInsertAfter = head->next; // Insert after the second node
    insertAfter(nodeToInsertAfter, 10);

    printf("Linked list after insertion after a specific node:\n");
    printLinkedList(head);

    return 0;
}
