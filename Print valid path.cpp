#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 5

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

List graph[MAX_VERTICES];
bool visited[MAX_VERTICES];

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph[src].head;
    graph[src].head = newNode;
}

void printPath(int path[], int pathLength) {
    for (int i = 0; i < pathLength; ++i) {
        printf("%d", path[i]);
        if (i != pathLength - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void DFS(int current, int end, int path[], int pathLength) {
    visited[current] = true;
    path[pathLength++] = current;

    if (current == end) {
        printPath(path, pathLength);
    } else {
        Node* temp = graph[current].head;
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                DFS(neighbor, end, path, pathLength);
            }
            temp = temp->next;
        }
    }

    visited[current] = false; 
}

int main() {
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(4, 5);
    addEdge(3, 5);

    int startVertex = 1;
    int endVertex = 5;

    int path[MAX_VERTICES]; 
    int pathLength = 0;     

    printf("Valid paths from vertex %d to %d:\n", startVertex, endVertex);
    DFS(startVertex, endVertex, path, pathLength);

    return 0;
}
