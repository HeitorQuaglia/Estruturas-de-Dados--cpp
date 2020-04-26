#include <iostream>
#include "stack.h"

int main() {
	Stack<int>* stack = new Stack<int>();
	
	stack->push(1);
	stack->push(2);
	stack->push(3);

	std::cout << stack->to_string() << std::endl;

	int data = stack->pop();

	std::cout << "Popped: " << data << std::endl;

	std::cout << stack->to_string() << std::endl;

	data = stack->peek();

	std::cout << "Peeked: " << data << std::endl;

	std::cout << stack->to_string() << std::endl;
	
	int length = stack->get_length();
	int* arr = new int[length];

	stack->to_array(arr);

	std::cout << "To Array: ";
	for (int i = 0; i < stack->get_length(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	stack->clear();
	std::cout << stack->to_string() << std::endl;
}