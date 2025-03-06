#pragma once
#include "Node.cpp"
template<class T>
class List {
public:
	explicit List(const List<T>& spisok);
	List();
	explicit List(T Value); /*- констуктор, в который мы заносим первым какое-то значение*/
	void pop_front();
	void pop_back();
	void push_front(T value);
	void push_back(T value);
	void insert(T value, int position); // не готово
	void append(const List<T>& list); // не готово
	T operator[](int index) const;
	void sort(List<T>& spisok);
	Node<T>* get_front();
	Node<T>* get_back();

	int get_size() const;
private:
	Node<T>* front;
	Node<T>* back;
	int size = 0;
};
