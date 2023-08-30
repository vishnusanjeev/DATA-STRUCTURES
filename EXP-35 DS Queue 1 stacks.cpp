#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure for a stack
struct Stack {
    struct StackNode* top;
};

// Function to create a new stack node
struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return -1; // Stack is empty
    }

    int data = stack->top->data;
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Queue structure using two stacks
struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->stack1->top == NULL && queue->stack2->top == NULL) {
        return -1; // Queue is empty
    }

    if (queue->stack2->top == NULL) {
        while (queue->stack1->top != NULL) {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue();
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    
    enqueue(queue, 4);
    
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    
    return 0;
}
