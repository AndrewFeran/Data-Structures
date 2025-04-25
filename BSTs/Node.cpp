#include <iostream>

class Node {
private:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
public:
    Node(int d) : data(d) {};
    Node* insert(Node* root, int value);
    void inorder(Node* root);
    bool search(Node* root, int value); 
    Node* del(Node* root, int value); 
    Node* min(Node* root);
};

Node* Node::insert(Node* root, int value) {
    // in the event node doesn't exist, add it
    if (!root) { return new Node(value); }
    if (value >= root->data)
        root->right = insert(root->right, value);
    else
        root->left = insert(root->left, value);
    return root;
}

void Node::inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

bool Node::search(Node* root, int value) {
    if (!root) return 0;
    if (value > root->data)
        return search(root->right, value);
    else if (value < root->data)
        return search(root->left, value);
    return 1;
}

Node* Node::del(Node* root, int value) {
    if (!root) return nullptr;
    if (value > root->data)
        root->right = del(root->right, value);
    else if (value < root->data)
        root->left = del(root->left, value);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        //if the node has one child (or no child)
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //if the node has one child (or no child)
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //if the node has two children (or no child)
        Node * temp = min(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

Node * Node::min(Node* root) {
    Node * current = root;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}