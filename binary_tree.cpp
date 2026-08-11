#include <iostream>

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    Node *root;

    Node* insert(Node *node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    void inorder(Node *node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void printInorder() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) tree.insert(v);
    tree.printInorder();
    return 0;
}