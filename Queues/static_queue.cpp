#include <iostream>
using namespace std;

class Queue {
public:
    int front = 0;
    int back = -1;
    unsigned size = 0;
    unsigned capacity = 0;
    int* arr;

    Queue(unsigned cap) : capacity(cap) { arr = new int[capacity]; }

    ~Queue() { delete[] arr; }

    void enqueue(int value) {
        if (isFull()) {
            cerr << "Stack Overflow";
            return;
        }
        if (isEmpty()) {
            front = back = 0;
            arr[0] = value;
            size++;
            return;
        }
        back = (back + 1) % capacity;
        arr[back] = value;
        size++;
    }
    int peek() {
        if (isEmpty()) {
            cerr << "Stack Underflow";
            exit(1);
        }
        return arr[front];
    }
    int dequeue() {
        if (isEmpty()) {
            cerr << "Stack Underflow";
            exit(1);
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }
    
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};

int main () {
    Queue test(5);

    while (true) {
        char option;
        int value;
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