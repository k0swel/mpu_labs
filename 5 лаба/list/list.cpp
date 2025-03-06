// list.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "list.h"

template<class T>
int List<T>::get_size() const {
	return this->size;
}

template<class T>
List<T>::List() { }

template<class T>
List<T>::List(T value) {
	this->push_back(value);
}

template<class T>
List<T>::List(const List<T>& spisok) {
	Node<T>* current_el_of_spisok = spisok.front;
	while (this->size != spisok.size) {
		Node<T> new_elem = Node<T>(current_el_of_spisok->get_value());
		this->push_back(current_el_of_spisok->get_value());
		current_el_of_spisok = current_el_of_spisok->get_next();
	}
}

template<class T>
void List<T>::push_front(T value) {
	if (this->size == 0) {// если список изначально пустой
		Node<T>* first_element = new Node<T>(value);
		this->front = first_element;
		this->back = first_element;
	}
	else {
		// инициализируем новое начало листа
		Node<T>* new_front = new Node<T>(value);
		new_front->set_next(this->front);
		this->front->set_prev(new_front);

		// делаем новый элемент началом
		this->front = new_front;
	}
	this->size++;
}

template<class T>
void List<T>::push_back(T value) {
	if (this->size == 0) {// если список изначально пустой
		Node<T>* first_element = new Node<T>(value);
		this->front = first_element;
		this->back = first_element;
	}
	else {
		// инициализируем новый конец листа
		Node<T>* new_back = new Node<T>(value);
		new_back->set_prev(this->back);
		this->back->set_next(new_back);

		// делаем новый элемент началом
		this->back = new_back;
	}
	this->size++;
}

template<class T>
void List<T>::pop_front() {
	Node<T>* new_front = front->get_next();
	delete this->front;
	this->front = new_front;
	this->size--;
}

template<class T>
void List<T>::pop_back() {
	Node<T>* new_back = back->get_prev();
	delete this->back;
	this->back = new_back;
	this->size--;
}

template<class T>
void List<T>::sort(List<T>& spisok) {
	int size = spisok.size;
	for (int index_one = 0; index_one < size - 1; index_one++) {
		Node<T>* first_el = spisok.front;
		Node<T>* second_el = spisok.front->get_next();
		for (int index_two = 0; index_two < size - 1 - index_one; index_two++) {
			if (first_el->get_value() > second_el->get_value()) {
				T temp_value = first_el->get_value();
				first_el->set_value(second_el->get_value());
				second_el->set_value(temp_value);
			}
			first_el = second_el;
			second_el = second_el->get_next();
		}
	}
}

template<class T>
void List<T>::insert(T value, int position) {
	if (position > size - 1) throw "too large position!";
	Node<T>* middle_element = this->front;
	for (int i = 0; i <= position; i++) {
		if (i == position) {
			Node<T>* prev_element = middle_element->get_prev();
			Node<T>* next_element = middle_element->get_next();

			Node<T>* new_element = new Node<T>(value);
			if (middle_element->get_prev() == nullptr) { // если вставляем элемент в начало списка
				new_element->set_next(middle_element);
				middle_element->set_prev(new_element);
				this->front = new_element;
			}

			else if (middle_element->get_next() == nullptr) { // если вставляем элемент в конец списка
				new_element->set_prev(middle_element);
				middle_element->set_next(new_element);
				this->back = new_element;
			}

			else {
				prev_element->set_next(new_element);
				new_element->set_prev(prev_element);
				new_element->set_next(middle_element);
				middle_element->set_prev(new_element);
			}
			break;
		}
		middle_element = middle_element->get_next();
	}
}

template<class T>
void List<T>::append(const List<T>& list) {
	Node<T>* last_el_source_list = this->back;
	last_el_source_list->set_next(list.front);
	this->size = this->size + list.size;
}


template<class T>
Node<T>* List<T>::get_front() {
	return this->front;
}

template<class T>
Node<T>* List<T>::get_back() {
	return this->back;
}

template<class T>
T List<T>::operator[](int index) const {
	int count = 0;
	Node<T>* element = this->front;
	while (element != nullptr) {
		if (count == index) {
			return element->get_value();
		}
		element = element->get_next();
		count++;
	}
	throw "The argument is not correct!";
}

