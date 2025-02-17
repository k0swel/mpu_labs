#include "pch.h"
#include "Stack.h"

template class Node<char>;
template class Stack<char>;

template <typename T>
Node<T>::Node() {
	this->value = 0;
	this->next = nullptr;
}

template <typename T>
Node<T>::Node(T value) {
	this->value = value;
}

template <typename T>
Stack<T>::Stack() {
	size = 0;
	root = nullptr;
}

template <typename T>
Stack<T>::Stack(T symbol) {
	Node<T>* node_object = new Node<T>(symbol);
	size = 1;
	root = node_object;
}

template <typename T>
void Stack<T>::push(T symbol) {
	if (isEmpty()) {
		Node<T>* node_object = new Node<T>(symbol);
		root = node_object;
		size++;
	}
	else {
		Node<T>* node_object = new Node<T>(symbol);
		node_object->next = root;
		root = node_object;
		size++;
	}
}

template <typename T>
T Stack<T>::top() {
	if (!isEmpty())
		return root->value;
	return (char)0;
}

template <typename T>
void Stack<T>::clear() {
	while (!isEmpty()) {
		pop();
	}
}

template <typename T>
void Stack<T>::pop() {
	if (!isEmpty()) {
		Node<T>* this_new_root = root->next;
		delete root;
		root = this_new_root;
		size--;
	}
	else throw "Stack is empty, sorry bro(";
}

template <typename T>
bool Stack<T>::isEmpty() {
	if (root == nullptr)
		return true;
	return false;
}