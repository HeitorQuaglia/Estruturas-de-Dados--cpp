#include "Tree.h"
#include <iostream>

Tree::Tree()
{
	this->root = nullptr;
}

void Tree::insert(int value)
{
	if (this->root == nullptr) {
		root = new Node(value);
	}
	else {
		this->insertAux(this->root, value);
	} 
}

void Tree::insertAux(Node* node, int value)
{
	if (value < node->get_value()) {
		if (node->get_left() == nullptr) {
			Node* newNode = new Node(value);
			node->set_left(newNode);
		}
		else {
			this->insertAux(node->get_left(), value);
		}
	}
	else if (value > node->get_value()) {
		if (node->get_right() == nullptr) {
			Node* newNode = new Node(value);
			node->set_right(newNode);
		}
		else {
			this->insertAux(node->get_right(), value);
		}
	}
}

Node* Tree::get_root()
{
	return this->root;
}

void Tree::printTree(Node* node)
{
	if (node != nullptr) {
		printTree(node->get_left());
		std::cout << node->get_value() << " ";
		printTree(node->get_right());
	}
}