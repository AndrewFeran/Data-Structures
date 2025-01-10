#include "Node.hpp"

// make new node
Node::Node(int _value): value(_value) {}
// get/set value of node
int Node::getValue() { return value; }
void Node::setValue(int _value) { value = _value; }
// get reference to node to the left/right
Node* Node::getLeft() { return Left; }
Node* Node::getRight() { return Right; }
// these initialize a new node at the left or right position
void Node::setLeft(int _value) { Left = new Node(_value); }
void Node::setRight(int _value) { Right = new Node(_value); }