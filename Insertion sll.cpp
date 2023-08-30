#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to insert a new node at the end of a linked list
struct ListNode* insert(struct ListNode* head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

// Function to find the length of a linked list
int length(struct ListNode* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find the intersection point of two linked lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    // Move the longer list's pointer to the same level as the shorter one
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }

    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // Traverse both lists until they meet at the intersection
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

int main() {
    struct ListNode* listA = NULL;
    struct ListNode* listB = NULL;
    struct ListNode* intersection = NULL;

    // Create the first linked list: 1 -> 3 -> 5 -> 7
    listA = insert(listA, 1);
    listA = insert(listA, 3);
    listA = insert(listA, 5);
    listA = insert(listA, 7);

    // Create the second linked list: 2 -> 4 -> 6
    listB = insert(listB, 2);
    listB = insert(listB, 4);
    listB = insert(listB, 6);

    // Make an intersection point (common node)
    struct ListNode* commonNode = insert(NULL, 8);
    listA->next->next->next->next = commonNode;
    listB->next->next->next = commonNode;

    intersection = getIntersectionNode(listA, listB);

    if (intersection != NULL) {
        printf("Intersection point: %d\n", intersection->val);
    } else {
        printf("No intersection found.\n");
    }

    return 0;
}
