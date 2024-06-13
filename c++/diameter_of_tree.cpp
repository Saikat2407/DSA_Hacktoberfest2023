#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to calculate the height of a binary tree
int calculateHeight(TreeNode* root, int& diameter) {
    if (root == NULL) {
        return 0;
    }

    // Recursively calculate the heights of the left and right subtrees
    int leftHeight = calculateHeight(root->left, diameter);
    int rightHeight = calculateHeight(root->right, diameter);

    // Update the diameter if a new longer path is found
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current subtree
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateHeight(root, diameter);
    return diameter;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int result = diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << result << endl;

    return 0;
}
