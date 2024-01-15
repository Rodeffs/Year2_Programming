#include "Node.h"

int Node::getValue() {
	return this->value;
}

Node* Node::getLeft() {
	return this->leftChild;
}

Node* Node::getRight() {
	return this->rightChild;
}

void Node::setValue(int val) {
	this->value = val;
}

void Node::setLeft(Node* left) {
	this->leftChild = left;
}

void Node::setRight(Node* right) {
	this->rightChild = right;
}

Node& Node::operator=(Node& other) {
	this->value = other.getValue();
	this->leftChild = other.getLeft();
	this->rightChild = other.getRight();
	return *this;
}
