#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct StackNode** top, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct StackNode** top) {
    if (*top == NULL) {
        return -1; // Stack is empty
    }

    int data = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to add the bottom-most and top-most elements of two stacks
int addBottomTop(struct StackNode* stack1, struct StackNode* stack2) {
    int bottom1, bottom2, top1, top2;
    
    // Pop the bottom-most element from stack1
    while (stack1->next != NULL) {
        stack1 = stack1->next;
    }
    bottom1 = pop(&stack1);
    
    // Pop the bottom-most element from stack2
    while (stack2->next != NULL) {
        stack2 = stack2->next;
    }
    bottom2 = pop(&stack2);

    // Pop the top-most element from stack1
    top1 = pop(&stack1);

    // Pop the top-most element from stack2
    top2 = pop(&stack2);

    return bottom1 + bottom2;
}

int main() {
    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);

    push(&stack2, 4);
    push(&stack2, 5);
    push(&stack2, 6);

    int result = addBottomTop(stack1, stack2);

    printf("Sum of bottom-most and top-most elements: %d\n", result);

    return 0;
}
