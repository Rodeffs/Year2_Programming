#include "Node.h"

Node::Node() {
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}

Node::Node(int val) {
	this->value = val;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}

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
