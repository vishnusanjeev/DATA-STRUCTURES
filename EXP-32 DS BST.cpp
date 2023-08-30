#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the kth smallest value in the binary search tree
void kthSmallestValue(struct TreeNode* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) {
        return;
    }

    // Traverse the left subtree
    kthSmallestValue(root->left, k, count, result);

    // Process the current node
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    // Traverse the right subtree
    kthSmallestValue(root->right, k, count, result);
}

int main() {
    struct TreeNode* root = NULL;

    // Insert elements into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Find the kth smallest value
    int k = 3; // Change k as needed
    int count = 0;
    int result = 0;
    kthSmallestValue(root, k, &count, &result);

    printf("The %dth smallest value is: %d\n", k, result);

    return 0;
}
