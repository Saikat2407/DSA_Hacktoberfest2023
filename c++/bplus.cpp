#include <iostream>
#include <vector>

const int ORDER = 3;  // Adjust the order of the tree here

struct Node {
    bool isLeaf;
    std::vector<int> keys;
    union {
        std::vector<Node*> children; // Internal node
        Node* nextLeaf;             // Leaf node
    };
    
    Node() : isLeaf(true), keys(0), nextLeaf(nullptr) {}
};

class BPlusTree {
public:
    BPlusTree() {
        root = nullptr;
    }

    void insert(int key) {
        if (!root) {
            root = new Node;
            root->keys.push_back(key);
        } else {
            Node* newChild = nullptr;
            int median = insertRecursive(root, key, newChild);

            if (median != -1) {
                Node* newRoot = new Node;
                newRoot->keys.push_back(median);
                newRoot->children.push_back(root);
                newRoot->children.push_back(newChild);
                root = newRoot;
            }
        }
    }

    bool search(int key) {
        return searchRecursive(root, key);
    }

    void print() {
        printRecursive(root);
        std::cout << std::endl;
    }

private:
    Node* root;

    int insertRecursive(Node* node, int key, Node*& newChild) {
        if (node->isLeaf) {
            insertSorted(node->keys, key);
            if (node->keys.size() <= ORDER) {
                return -1; // No split required
            }
            // Split leaf node
            int median = node->keys[node->keys.size() / 2];
            newChild = new Node;
            newChild->keys.assign(node->keys.begin() + node->keys.size() / 2, node->keys.end());
            node->keys.resize(node->keys.size() / 2);
            node->nextLeaf = newChild;
            return median;
        } else {
            int index = findChildIndex(node, key);
            int median = insertRecursive(node->children[index], key, newChild);

            if (median != -1) {
                insertSorted(node->keys, median);
                insertSorted(node->children, index + 1, newChild);
                if (node->keys.size() <= ORDER) {
                    return -1; // No split required
                }
                // Split internal node
                int mid = node->keys.size() / 2;
                median = node->keys[mid];
                newChild = new Node;
                newChild->isLeaf = false;
                newChild->keys.assign(node->keys.begin() + mid + 1, node->keys.end());
                newChild->children.assign(node->children.begin() + mid + 1, node->children.end());
                node->keys.resize(mid);
                node->children.resize(mid + 1);
                return median;
            }
        }
        return -1;
    }

    bool searchRecursive(Node* node, int key) {
        if (!node) return false;

        int index = findChildIndex(node, key);

        if (index < node->keys.size() && node->keys[index] == key) {
            return true;
        } else if (node->isLeaf) {
            return false;
        } else {
            return searchRecursive(node->children[index], key);
        }
    }

    void printRecursive(Node* node) {
        if (!node) return;
        
        for (int i = 0; i < node->keys.size(); ++i) {
            std::cout << node->keys[i] << " ";
        }
        
        if (!node->isLeaf) {
            for (int i = 0; i < node->children.size(); ++i) {
                printRecursive(node->children[i]);
            }
        }
    }

    void insertSorted(std::vector<int>& vec, int key) {
        auto it = std::lower_bound(vec.begin(), vec.end(), key);
        vec.insert(it, key);
    }

    void insertSorted(std::vector<Node*>& vec, int index, Node* node) {
        vec.insert(vec.begin() + index, node);
    }

    int findChildIndex(Node* node, int key) {
        int index = 0;
        while (index < node->keys.size() && key >= node->keys[index]) {
            ++index;
        }
        return index;
    }
};

int main() {
    BPlusTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(1);
    tree.insert(9);

    tree.print();

    std::cout << "Search 5: " << (tree.search(5) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 7: " << (tree.search(7) ? "Found" : "Not Found") << std::endl;

    return 0;
}