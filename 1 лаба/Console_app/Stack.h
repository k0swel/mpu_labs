#pragma once
#include "Node.h"

template<typename T>
class Stack
{
public:
	Stack();
	Stack(T value);
	void push(T symbol);
	void pop(); 
	T top();
	void clear();
	

	bool isEmpty();

public:
	Node<T>* root;
	int size;
	 
};

