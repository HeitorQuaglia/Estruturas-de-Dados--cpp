#include "Node.h"

Node::Node(int value)
{
	this->value = value;
	this->left = this->right = nullptr;
}

int Node::get_value()
{
	return this->value;
}

Node* Node::get_left()
{
	return this->left;
}

Node* Node::get_right()
{
	return this->right;
}

void Node::set_left(Node* node)
{
	this->left = node;
}

void Node::set_right(Node* node)
{
	this->right = node;
}
