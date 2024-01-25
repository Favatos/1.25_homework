#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T value) : value(value), left(nullptr), right(nullptr) {}
};
void printIndent(int level) {
    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
}
template <typename T>
void printTree(Node<T>* node, int level = 0) {
    if (node == nullptr) {
        return;
    }

    printTree(node->right, level + 1);

    printIndent(level);
    cout << node->value << endl;

    printTree(node->left, level + 1);
}
template <typename T>
Node<T>* insertNode(Node<T>* node, T value) {
    if (node == nullptr) {
        return new Node<T>(value);
    }

    if (value < node->value) {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }

    return node;
}
template <typename T>
void search(Node<T>* a, T key) {
    Node* current = a;
    while (current->value != key) {
        if (key < current->value) {
            current = current->left;
        }
        else current = current->right;
    }
    return current;
}

template <typename T>
Node<T>* findMax(Node<T>* ptr) {
    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }
    return ptr;
}

template <typename T>
void deleteNode(Node<T>*& root, T key) {
    if (root == nullptr) {
        return;
    }
    if (key < root->value) {
        deleteNode(root->left, key);
    }
    else if (key > root->value) {
        deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left && root->right) {
            Node<T>* p = findMax(root->left);
            root->value = p->value;
            deleteNode(root->left, p->value);
        }
        else {
            Node<T>* p = (root->left) ? root->left : root->right;
            Node<T>* curr = root;
            root = p;
            delete curr;
        }
    }
}

int main() {
    Node<int>* root = nullptr;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    printTree(root);
    cout << endl;
    deleteNode(root, 1);
    printTree(root);

    return 0;
}
