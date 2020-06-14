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
		this->insert_aux(this->root, value);
	}
}

void Tree::insert_aux(Node* node, int value)
{
	if (value < node->get_value()) {
		if (node->get_left() == nullptr) {
			Node* newNode = new Node(value);
			node->set_left(newNode);
		}
		else {
			this->insert_aux(node->get_left(), value);
		}
	}
	else if (value > node->get_value()) {
		if (node->get_right() == nullptr) {
			Node* newNode = new Node(value);
			node->set_right(newNode);
		}
		else {
			this->insert_aux(node->get_right(), value);
		}
	}
}

Node* Tree::get_root()
{
	return this->root;
}

void Tree::print_tree(Node* node)
{
	if (node != nullptr) {
		print_tree(node->get_left());
		std::cout << node->get_value() << " ";
		print_tree(node->get_right());
	}
}

bool Tree::has(int value)
{
	return has_aux(this->root, value);
}

bool Tree::has_aux(Node* node, int value) {
	if (node == nullptr) {
		return false;
	}
	if (node->get_value() == value) {
		return true;
	}
	if (node->get_value() > value) {
		return this->has_aux(node->get_left(), value);
	}
	return this->has_aux(node->get_right(), value);
}
