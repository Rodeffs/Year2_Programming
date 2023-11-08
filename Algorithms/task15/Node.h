#pragma once

class Node {
private:
	int value;

public:
	Node* leftChild;

	Node* rightChild;

	Node(int val, Node* left, Node* right) : value{val}, leftChild{left}, rightChild{right} {}

	Node(int val);
};
