#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue node
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Queue is empty
    }
    
    int data = queue->front->data;
    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return data;
}

// Stack structure using two queues
struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

// Function to initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    enqueue(stack->q1, data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->q1->front == NULL) {
        return -1; // Stack is empty
    }
    
    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    
    int data = dequeue(stack->q1);
    
    // Swap q1 and q2
    struct Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    
    return data;
}

int main() {
    struct Stack* stack = createStack();
    
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    
    push(stack, 4);
    
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    
    return 0;
}
