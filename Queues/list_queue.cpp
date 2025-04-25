#include "linked_list.hpp"
#include <iostream>
#include <string>

using namespace std;

template <typename T=string>
class Queue {
public:
    Node<T>* front = nullptr;
    Node<T>* back = nullptr;
    unsigned size = 0;

    void enqueue(T value) {
        if (isEmpty()) {
            front = createLinkedList(value);
            back = front;
            size++;
            return;
        }
        back = insertTail(front, value);
        size++;
        // Remove the traverseLinkedList call
    }
    
    T peek() {
        if (isEmpty()) {
            cerr << "Queue Underflow";
            exit(1);
        }
        return front->value;
    }
    
    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue Underflow";
            exit(1);
        }
        
        T value = front->value;
        Node<T>* temp = front;
        front = front->nextNode;
        delete temp;
        size--;
        
        // If queue is now empty, update back pointer too
        if (isEmpty()) {
            back = nullptr;
        }
        
        return value;
    }
    
    bool isEmpty() { return size == 0; }
};

int main() {
    Queue<string> test;

    while (true) {
        char option;
        string value;
        cout << "Enqueue (E), Peek (P), Dequeue (D): ";
        cin >> option;
        switch (option) {
            case 'E':
                cout << "Enter value: ";
                cin >> value;
                test.enqueue(value);
                break;
            case 'P':
                cout << test.peek() << endl;
                break;
            case 'D':
                cout << test.dequeue() << endl;
                break;
        }
    }

    return 0;
}