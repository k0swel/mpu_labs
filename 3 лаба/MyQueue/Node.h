#pragma once

template<class T>
class Node
{
public:
	Node();
	Node(T value); // инициализируем объект, добавляемый в очередь, каким-то значением
	~Node();
	T get_value(); // получаем значение объекта очереди
	void set_next(Node<T>* el); // указываем объекту очереди ссылку на следующий элемент (из параметра)
	Node<T>* get_next(); // получаем значение следующего объекта очереди.
private:
	T value = 0;
	Node<T>* next = nullptr;
};

