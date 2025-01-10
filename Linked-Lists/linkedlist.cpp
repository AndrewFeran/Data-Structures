/*
Create a linked list data type
*/
#include <iostream>

template <typename T>
struct Node {
    Node* nextNode;
    T value;
};

int main() {

    // create the root for an integer list
    Node<int> root;
    // create a pointer for modifications
    Node<int>* copy = &root;

    // build out the linked list
    for (int i = 0; i < 10; i++) {
        copy->value = i;
        if (i < 10) { // only make next node if within size
            copy->nextNode = new Node<int>;
            copy = copy->nextNode;
        }
    }

    // start back at the root
    copy = &root;

    // loop through and print
    for (int i = 0; i < 10; i++) {
        std::cout << copy->value << " ";
        copy = copy->nextNode;
    }

    return 0;
}