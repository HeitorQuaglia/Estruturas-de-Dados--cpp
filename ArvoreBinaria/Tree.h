#pragma once
#include "Node.h"
class Tree
{
private:
	Node* root;
	bool has_aux(Node* node, int value);
	void insert_aux(Node* node, int value);
	int count(Node* node);
public:
	Tree();
	void insert(int value);
	Node* get_root();
	void print_tree(Node* node);
	bool has(int value);
	int length();
};

