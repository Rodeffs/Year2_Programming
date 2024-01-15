#pragma once

class Node {
private:
	int value;

	Node* leftChild;

	Node* rightChild;

public:
	explicit Node(int val = 0, Node* left = nullptr, Node* right = nullptr) : value{val}, leftChild{left}, rightChild{right} {}

	int getValue();

	Node* getLeft();

	Node* getRight();

	void setValue(int val);

	void setLeft(Node* left);

	void setRight(Node* right);

	Node& operator=(Node& other);
};
