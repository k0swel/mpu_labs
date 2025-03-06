#pragma once

template<class T>
class Node
{
public:
	
	Node(T value);
	T get_value();
	void set_prev(Node<T>* el);
	void set_next(Node<T>* el);
	Node<T>* get_prev();
	Node<T>* get_next();
	void set_value(T value);

private:
	Node* next;
	Node* prev;
	T value;
};

