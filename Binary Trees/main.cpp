/*
Construct a binary tree and print it based on an array
*/
#include <iostream>
#include "Node.hpp"
using namespace std;

void arrToTree(int* arr, Node &root, int size);
void printArr(int* arr);
void printTree(Node &root);

int main() {
    // Node root(0);
    // root.setLeft(1);
    // root.setRight(2);
    // root.getLeft()->setLeft(3);
    
    
    // std::cout << root.getValue() << " " << root.getLeft()->getValue() << " " <<
    //     root.getRight()->getValue() << " " << root.getLeft()->getLeft()->getValue() << std::endl;

    // test case 1
    const int size1 = 10;
    int arr1[size1] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Node root1(arr1[0]);
    root1.setLeft(1);
    root1.setRight(2);
    root1.getLeft()->setLeft(3);
    // arrToTree(arr1, root1, size1);
    printTree(root1);

    return 0;
}

void arrToTree(const int* arr, Node &root, int size) {

}
void printArr(const int* arr) {

}
void printTree(Node &root) {
    bool run = 1;
    cout << root.getValue();
    while (run) {
        
    }
}