#pragma once

template<typename T>
class Node
{
public:
	Node();
	Node(T _value);

	Node* prev = nullptr;
	Node* next = nullptr;

	T value;

};

template <typename T>
Node<T>::Node() {
	prev = nullptr;
	next = nullptr;
	value = -1;
}
template <typename T>
Node<T>::Node(T _value) {
	prev = nullptr;
	next = nullptr;
	value = _value;
}


