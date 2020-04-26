#pragma once
#include <sstream>
#include <string>
#include <exception>

template <typename T>
class Node {
	T data;
	Node* next;
public:
	Node<T>(T data, Node* next) {
		this->data = data;
		this->next = next;
	}
	T get_data() {
		return this->data;
	}
	Node* get_next() {
		return this->next;
	}
	void set_next(Node* next) {
		this->next = next;
	}
};

template <typename T>
class Stack
{
	Node<T>* first;

public:
	Stack<T>() {
		this->first = nullptr;
	};
	bool is_empty() {
		if (this->first == nullptr) return true;
		return false;
	}
	void push(T data) {
		Node<T>* new_node = new Node<T>(data, this->first);
		new_node->set_next(this->first);
		this->first = new_node;
	}
	T pop() {
		if (this->is_empty()) throw std::exception("Queue is empty, pop is not possible");
		T data = this->first->get_data();
		Node<T>* free = this->first;
		this->first = this->first->get_next();
		delete free;
		return data;
	}
	T peek() {
		if (this->is_empty()) throw std::exception("Queue is empty, peek is not possible");
		return this->first->get_data();
	}
	int get_length() {
		if (this->is_empty()) return 0;
		int len = 0;
		Node<T>* aux = this->first;
		while (aux != nullptr) {
			len++;
			aux = aux->get_next();
		}
		return len;
	}
	void to_array(T(*arr)) {
		if (this->is_empty()) return;
		int length = this->get_length();
		Node<T>* aux = this->first;
		for (int i = 0; i < length; i++) {
			arr[i] = aux->get_data();
			aux = aux->get_next();
		}
	}
	std::string to_string() {
		Node<T>* prox = this->first;
		std::string res = "[ ";

		std::stringstream aux;
		while (prox != nullptr) {
			aux << prox->get_data() << " ";
			prox = prox->get_next();
		}

		res.append(aux.str());
		res.append("]");

		return res;
	}
	void clear() {
		Node<T>* free;
		Node<T>* next = this->first;

		while (next != nullptr) {
			free = next;
			next = next->get_next();
			delete free;
		}
		this->first = nullptr;
	}
};

