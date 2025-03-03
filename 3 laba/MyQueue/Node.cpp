#include "pch.h"
#include "framework.h"
#include "Node.h"

template<class T>
Node<T>::Node() {}

template<class T> // инициализируем объект, добавляемый в очередь, каким-то значением
Node<T>::Node(T value) {
	this->value = value;
}

template<class T>
T Node<T>::get_value() { // получаем значение объекта очереди
	return this->value;
}
template<class T>
void Node<T>::set_next(Node<T>* el) { // указываем объекту очереди ссылку на следующий элемент (из параметра)
	this->next = el;
}

template<class T>
Node<T>* Node<T>::get_next() { // получаем значение следующего объекта очереди.
	return this->next;
}

template<class T>
Node<T>::~Node() {
}
