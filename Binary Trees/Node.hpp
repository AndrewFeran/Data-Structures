#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    int value;
    Node* Left;
    Node* Right;
public:
    Node(int _value); // make new node

    int getValue(); // get value of node
    void setValue(int _value); // set value of node

    Node* getLeft(); // get reference to node to the left
    Node* getRight(); // get reference to node to the right

    // these initialize a new node at the left or right position
    void setLeft(int _value); // set the left node's value
    void setRight(int _value); // set the right node's value
};

#endif