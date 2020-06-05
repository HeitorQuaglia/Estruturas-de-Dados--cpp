#pragma once
#include "Node.h"
class Tree
{
private:
	Node* root;
public:
	Tree();
	void insert(int value);
	void insertAux(Node* node, int value);
	Node* get_root();
	void printTree(Node* node);
};

