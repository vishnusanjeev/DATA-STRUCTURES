#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 5

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

List graph[MAX_VERTICES];

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph[src].head;
    graph[src].head = newNode;
}

int minEdgesBFS(int start, int end) {
    bool visited[MAX_VERTICES] = { false };
    int distance[MAX_VERTICES] = { 0 };

    visited[start] = true;
    distance[start] = 0;

    // Initialize BFS queue
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];
        Node* temp = graph[current].head;

        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                distance[temp->vertex] = distance[current] + 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    return distance[end];
}

int main() {
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(4, 5);
    addEdge(3, 5);

    int startVertex = 1;
    int endVertex = 5;

    int minEdges = minEdgesBFS(startVertex, endVertex);

    printf("Minimum edges from vertex %d to %d: %d\n", startVertex, endVertex, minEdges);

    return 0;
}

