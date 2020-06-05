#include <iostream>
#include "Tree.h"

int main()
{
	Tree *tree = new Tree();

	tree->insert(8);
	tree->insert(10);
	tree->insert(14);
	tree->insert(13);

	tree->insert(3);
	tree->insert(1);
	tree->insert(6);
	tree->insert(4);
	tree->insert(7);

	std::cout << "Em ordem: " << std::endl;

	tree->printTree(tree->get_root());
}
