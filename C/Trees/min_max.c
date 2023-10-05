#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(struct TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    struct TreeNode* root = NULL;
    root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    
    int min = findMin(root);
    int max = findMax(root);
    
    printf("Minimum element in the BST: %d\n", min);
    printf("Maximum element in the BST: %d\n", max);

    return 0;
}
