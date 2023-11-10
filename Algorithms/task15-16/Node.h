#pragma once

class Node {
private:
	int value;

public:
	Node* leftChild;

	Node* rightChild;

	explicit Node(int val = 0, Node* left = nullptr, Node* right = nullptr) : value{val}, leftChild{left}, rightChild{right} {}

	void setValue(int val);

	int getValue();

	Node& operator=(Node& other);
};
