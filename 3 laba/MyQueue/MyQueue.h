#pragma once
#include "Node.cpp"
template<class T>
class MyQueue
{
public:
	~MyQueue();
	void push_back(T value);
	void pop_front();
	T get_front();
	T get_back();
	int size();
private:
	int length = 0;
	Node<T>* back = nullptr;
	Node<T>* front = nullptr;
};

