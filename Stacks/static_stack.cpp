// This is the linked list implementation of a stack data structure (on the heap)
#include <iostream>
using namespace std;

template <typename T>
struct Stack {
    Node<T>* top = nullptr;    
};

template <typename T>
struct Node {
    T value;
    Node<T>* next = nullptr;
};

template <typename T>
void push(Stack<T> &stack, T val);
template <typename T>
T pop(Stack<T> &stack);
template <typename T>
T peek(const Stack<T> &stack);
template <typename T>
bool isEmpty(const Stack<T> &stack);

int main() {
    Stack<int> test;

    return 0;
}

template <typename T>
void push(Stack<T> &stack, T val) {

}

template <typename T>
T pop(Stack<T> &stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    return stack.arr[stack.top--];
}

template <typename T>
T peek(const Stack<T> &stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty" << endl;
        exit(1);
    }
    return stack.arr[stack.top];
}

template <typename T>
bool isEmpty(const Stack<T> &stack) {
    if (stack.top == nullptr) return true;
    return false;
}