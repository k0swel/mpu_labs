#include "pch.h"
#include "Node.h"
template<class T>
T Node<T>::get_value() {
	return this->value;
}

template<class T>
Node<T>::Node(T value) {
	this->value = value;
}

template<class T>
void Node<T>::set_prev(Node<T>* el) {
	this->prev = el;
}

template<class T>
void Node<T>::set_next(Node<T>* el) {
	this->next = el;
}

template<class T>
Node<T>* Node<T>::get_prev() {
	return this->prev;
}

template<class T>
Node<T>* Node<T>::get_next() {
	return this->next;
}

template<class T>
void Node<T>::set_value(T value) {
	this->value = value;
}
