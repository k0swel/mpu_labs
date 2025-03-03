// MyQueue.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "MyQueue.h"
template<class T>
void MyQueue<T>::push_back(T value) { // помещаем элемент в конец очереди
	if (this->size() == 0) {
		Node<T>* new_back_and_new_front = new Node<T>(value);
		this->back = new_back_and_new_front;
		this->front = new_back_and_new_front;
		this->length++;
	}
	else {
		Node<T>* new_back = new Node<T>(value);
		this->back->set_next(new_back);
		this->back = new_back;
		this->length++;
	}
}

template<class T>
void MyQueue<T>::pop_front() { // удаляем элемент с начала очереди
	if (this->size() != 0) {
		Node<T>* new_front = this->front->get_next();
		delete this->front;
		this->front = new_front;
		this->length--;
	}
	else {
		throw "Queue is empty!";
	}
}

template<class T>
int MyQueue<T>::size() { // получаем размер очереди
	return this->length;
}

template<class T>
T MyQueue<T>::get_front() { // получаем значение переднего элемента очереди 
	return this->front->get_value();
}

template<class T>
T MyQueue<T>::get_back() { // получаем значение последнего элемента очереди
	return this->back->get_value();
}
template<class T>
MyQueue<T>::~MyQueue() { // деструктор, удаляем динамические объекты, дабы избежать утечку памяти.
	while (this->size() > 0) {
		pop_front();
	}
}