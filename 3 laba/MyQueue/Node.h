#pragma once

template<class T>
class Node
{
public:
	Node();
	Node(T value);
	~Node();
	T get_value();
	void set_next(Node<T>* el);
	Node<T>* get_next();
private:
	T value = 0;
	Node<T>* next = nullptr;
};

