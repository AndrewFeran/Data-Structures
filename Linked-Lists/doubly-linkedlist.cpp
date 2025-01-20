/*
Create a doubly linked list data type
*/
#include <iostream>

// make the node structure
template <typename T>
struct Node {
    Node* nextNode;
    Node* prevNode;
    T value;
};

// define the functions
template <typename T>
Node<T>* createLinkedList(T* arr, int size);
template <typename T>
void traverseLinkedList(Node<T>* node, int direction);
template <typename T>
Node<T>* insertHead(Node<T>* head, T value);
template <typename T>
Node<T>* insertTail(Node<T>* head, T value);

int main() {
    int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 10;

    std::cout << "Create the list" << std::endl;
    Node<int>* head = createLinkedList(test, size);
    traverseLinkedList(head, 1);

    std::cout << std::endl << "Insert -1 at the head" << std::endl;
    head = insertHead(head, -1);
    traverseLinkedList(head, 1);

    std::cout << std::endl << "Insert 10 at the tail and reverse" << std::endl;
    Node<int>* tail = insertTail(head, 10);
    traverseLinkedList(tail, -1);

    return 0;
}

template <typename T>
// function for creating new obj from array and returning the header
Node<T>* createLinkedList(T* arr, int size) {
    Node<T>* head = new Node<T>();
    // pre set previous header to nullptr
    head->prevNode = nullptr;
    Node<T>* current = head;

    for (int i = 0; i < size; i++) {
        current->value = *(arr+i);
        
        if (i == size-1) current->nextNode = nullptr;
        else {
            current->nextNode = new Node<T>();
            current->nextNode->prevNode = current;
            current = current->nextNode;
        }
    }

    return head;
}

template <typename T>
// function for traversing linked list
void traverseLinkedList(Node<T>* node, int direction) {
    if (direction == 1) {
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->nextNode;
        }
    }
    else if (direction == -1) {
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->prevNode;
        }
    }

    return;
}

template <typename T>
// function to insert at the begining and return new head ptr
Node<T>* insertHead(Node<T>* head, T value) {
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->nextNode = head;
    newNode->prevNode = nullptr;
    return newNode;
}

template <typename T>
// function to insert at the end and return new tail ptr
Node<T>* insertTail(Node<T>* start, T value) {
    Node<T>* tail = start;

    while (tail->nextNode != nullptr) {
        tail = tail->nextNode;
    }

    tail->nextNode = new Node<T>;
    tail->nextNode->prevNode = tail;
    tail = tail->nextNode;
    tail->value = value;

    return tail;
}