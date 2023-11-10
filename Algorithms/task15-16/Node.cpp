#include "Node.h"

void Node::setValue(int val) {
	this->value = val;
}

int Node::getValue() {
	return this->value;
}

Node& Node::operator=(Node& other) {
	this->value = other.getValue();
	this->leftChild = other.leftChild;
	this->rightChild = other.rightChild;
	return *this;
}
