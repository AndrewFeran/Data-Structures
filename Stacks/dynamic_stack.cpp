// This is the linked list implementation of a stack data structure (on the heap)
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* next = nullptr;
    Node(T value, Node<T>* next) : value(value), next(next) {}
};

template <typename T>
struct Stack {
    Node<T>* top = nullptr;
    // a size counter could be kept but its not necessary for most basic implementations
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
    push(test, 1);
    push(test, 2);
    cout << pop(test) << "\n";
    cout << pop(test) << "\n";
    cout << pop(test) << "\n";


    return 0;
}

template <typename T>
void push(Stack<T> &stack, T val) {
    if (stack.top == nullptr) {
        stack.top = new Node<T>(val, nullptr);
        return;
    }
    stack.top = new Node<T>(val, stack.top);
}

template <typename T>
T pop(Stack<T> &stack) { // curently does not hndle deletions
    if (isEmpty(stack)) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    T value = stack.top->value;
    stack.top = stack.top->next;
    return value;
}

template <typename T>
T peek(const Stack<T> &stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    return stack.top->value;
}

template <typename T>
bool isEmpty(const Stack<T> &stack) {
    if (stack.top == nullptr) return 1;
    return 0;
}