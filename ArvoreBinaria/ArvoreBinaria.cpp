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

	std::cout << "Em ordem: ";
	
	tree->print_tree(tree->get_root());

	std::cout << std::endl;
	
	std::cout << "Existe 13: " << tree->has(13) << std::endl;

	std::cout << "Tamanho: " << tree->length() << std::endl;

	tree->remove(6);

	std::cout << "Existe 6: " << tree->has(6) << std::endl;

	std::cout << "Tamanho: " << tree->length() << std::endl;

	std::cout << "Em ordem: ";

	tree->print_tree(tree->get_root());

	std::cout << std::endl;
}
