import random

class Node:
    def __init__(self, key):
        self.key = key
        self.priority = random.randint(0, 100)  # Assign a random priority
        self.left = None
        self.right = None

class Treap:
    def __init__(self):
        self.root = None

    def rotate_right(self, y):
        x = y.left
        T2 = x.right

        x.right = y
        y.left = T2

        return x

    def rotate_left(self, x):
        y = x.right
        T2 = y.left

        y.left = x
        x.right = T2

        return y

    def insert(self, root, key):
        if not root:
            return Node(key)

        if key <= root.key:
            root.left = self.insert(root.left, key)

            if root.left.priority > root.priority:
                root = self.rotate_right(root)
        else:
            root.right = self.insert(root.right, key)

            if root.right.priority > root.priority:
                root = self.rotate_left(root)

        return root

    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print("Key: " + str(root.key) + ", Priority: " + str(root.priority))
            self.inorder(root.right)

if __name__ == "__main__":
    treap = Treap()

    # Insert keys with random priorities
    treap.root = treap.insert(treap.root, 10)
    treap.root = treap.insert(treap.root, 20)
    treap.root = treap.insert(treap.root, 5)

    # Print inorder traversal
    treap.inorder(treap.root)
