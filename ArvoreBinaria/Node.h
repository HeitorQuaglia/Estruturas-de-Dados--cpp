#pragma once
class Node
{
private:
	Node *left, *right;
	int value;

public:
	Node(int value);
	int get_value();
	Node* get_left();
	Node* get_right();
	void set_left(Node* node);
	void set_right(Node* node);
};

