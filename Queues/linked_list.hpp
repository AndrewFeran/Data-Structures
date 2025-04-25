/*
Create a queue based on linked list
*/
#include <iostream>

// make the node structure
template <typename T>
struct Node {
    Node* nextNode;
    T value;
};

// define the functions
template <typename T>
Node<T>* createLinkedList(T& value);
template <typename T>
void traverseLinkedList(Node<T>* node);
template <typename T>
Node<T>* insertHead(Node<T>* head, T value);
template <typename T>
Node<T>* insertTail(Node<T>* head, T value);

template <typename T>
// function for creating new obj from array and returning the header
Node<T>* createLinkedList(T& value) {
    Node<T>* head = new Node<T>();
    head->value = value;
    head->nextNode = nullptr;

    return head;
}

template <typename T>
// function for traversing linked list
void traverseLinkedList(Node<T>* node) {
    while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->nextNode;
    }
}

template <typename T>
// function to insert at the begining and return new head ptr
Node<T>* insertHead(Node<T>* head, T value) {
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->nextNode = head;
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
    tail = tail->nextNode;
    tail->value = value;

    return tail;
}