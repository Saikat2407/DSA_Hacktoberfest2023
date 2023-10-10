# Finding the Size of the Largest BST in Java

This Java code demonstrates how to find the size of the largest Binary Search Tree (BST) within a given binary tree using a recursive approach.

## Important Points

- Define a `TreeNode` class to represent individual nodes in the binary tree.

- Create a `BSTInfo` class to store information about each subtree, including size, minimum value, maximum value, and whether it's a valid BST.

- Define a `BinaryTree` class to represent the binary tree, with methods to find the size of the largest BST.

- The `largestBSTSize` method in the `BinaryTree` class initiates the process of finding the largest BST.

- The `largestBSTHelper` method is a recursive function that determines whether a subtree is a valid BST and calculates its size.

- The `main` method demonstrates how to use the `BinaryTree` class to find the size of the largest BST within a binary tree.

```java
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
        left = null;
        right = null;
    }
}

class BSTInfo {
    int size;
    int min;
    int max;
    boolean isBST;

    public BSTInfo(int size, int min, int max, boolean isBST) {
        this.size = size;
        this.min = min;
        this.max = max;
        this.isBST = isBST;
    }
}

class BinaryTree {
    TreeNode root;

    public BinaryTree() {
        root = null;
    }

    // Function to find the size of the largest BST within a binary tree
    public int largestBSTSize() {
        BSTInfo info = largestBSTHelper(root);
        return info.size;
    }

    private BSTInfo largestBSTHelper(TreeNode node) {
        if (node == null) {
            return new BSTInfo(0, Integer.MAX_VALUE, Integer.MIN_VALUE, true);
        }

        BSTInfo leftInfo = largestBSTHelper(node.left);
        BSTInfo rightInfo = largestBSTHelper(node.right);

        if (leftInfo.isBST && rightInfo.isBST && node.val > leftInfo.max && node.val < rightInfo.min) {
            int size = 1 + leftInfo.size + rightInfo.size;
            int min = Math.min(node.val, leftInfo.min);
            int max = Math.max(node.val, rightInfo.max);
            return new BSTInfo(size, min, max, true);
        } else {
            // If the current subtree is not a BST, return the maximum size from its children
            return new BSTInfo(Math.max(leftInfo.size, rightInfo.size), 0, 0, false);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new TreeNode(10);
        tree.root.left = new TreeNode(5);
        tree.root.right = new TreeNode(15);
        tree.root.left.left = new TreeNode(1);
        tree.root.left.right = new TreeNode(8);
        tree.root.right.right = new TreeNode(7);

        int largestBSTSize = tree.largestBSTSize();
        System.out.println("Size of the largest BST: " + largestBSTSize);
    }
}
```
In this code, the `BinaryTree` class represents the binary tree, and the `largestBSTSize` method finds the size of the largest BST within the binary tree. The `largestBSTHelper` method is a recursive helper function that returns information about the BST rooted at the current node. The `BSTInfo` class is used to store information about each subtree, including its size, minimum, maximum, and whether it is a valid BST.
