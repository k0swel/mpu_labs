#pragma once

template<typename T>
class Node
{
public:
	Node();
	Node(T value);

	T value;
	Node* next = nullptr;
};


