#include "Node.cpp"

#include <iostream>
using namespace std;

int main() {
    Node* root = new Node(3);
    root->insert(root, 1);
    root->insert(root, 7);
    root->insert(root, 0);
    root->insert(root, 83);
    root->insert(root, 35);
    root->insert(root, 234);
    root->insert(root, 89);
    root->insert(root, 21);
    root->insert(root, 64);

    root->inorder(root);
    cout << endl;

    root->del(root, 35);
    root->inorder(root);



    return 0;
}