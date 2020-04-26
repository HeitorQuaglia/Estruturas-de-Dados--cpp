#pragma once

template <typename T>
class Node {
private:
	T data;
	Node<T>* previous;
	Node<T>* next;
public:
	Node(T data) {
		this->data = data;
		this->previous = nullptr;
		this->next = nullptr;
	}
	Node<T>* get_previous() {
		return this->previous;
	}
	void set_previous(Node<T>* previous) {
		this->previous = previous;
	}
	Node<T>* get_next() {
		return this->next;
	}
	void set_next(Node<T>* next) {
		this->next = next;
	}
};
template <typename T>
class Deque
{
private:
	Node<T>* head;
public:
	Deque() {
		this->head = new Node<T>();
		this->head->set_next(this->head);
		this->head->set_previous(this->head);
	}
	int get_length() {
		Node<T> *end = this->head;
		int len = 0;
		while (end != this->head)
		{
			len++;
			end = end->get_next();
		}
		return len;
	}
	void insert_end(T data) {
		Node<T>* new_node = new Node<T>(data);
		new_node->set_next(this->head);
		new_node->set_previous(this->head->get_previous());
		this->head->set_previous(new_node);
		new_node->get_previous()->set_next(new_node);
	}
};

