// This is the array implementation of a stack data structure (on the stack)
#include <iostream>
using namespace std;

template <typename T>
struct Stack {
    unsigned size;
    int top = -1;
    T* arr;

    // Constructor
    Stack(unsigned size) : size(size), arr(new T[size]) {}

    // Destructor
    ~Stack() { delete[] arr; }
};

template <typename T>
void push(Stack<T> &stack, T val);
template <typename T>
T pop(Stack<T> &stack);
template <typename T>
T peek(const Stack<T> &stack);
template <typename T>
bool isEmpty(const Stack<T> &stack);
template <typename T>
bool isFull(const Stack<T> &stack);


int main() {
    Stack<int> test(10);
    
    for(int i = 0; i < 10; i++) {
        push(test, i);
    }

    for(int i = 0; i < 11; i++) {
        cout << pop(test) << " ";
    }

    return 0;
}

template <typename T>
void push(Stack<T> &stack, T val) {
    if (isFull(stack)) {
        cout << "Stack overflow" << endl;
        exit(1);
    }
    stack.arr[++stack.top] = val;
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
    if (stack.top == -1) return true;
    return false;
}

template <typename T>
bool isFull(const Stack<T> &stack) {
    if (stack.top == stack.size-1) return true;
    return false;
}