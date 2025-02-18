#pragma once
#include "Node.h"

template <typename T>
class Deque
{
public:
    Deque();

    bool is_empty();
    int size();

    void push_back(T value);
    void push_front(T value);
    void pop_front();
    void pop_back();
    Node<T>* front();
    Node<T>* back();
    void clear();
private:
    Node<T>* first;
    Node<T>* last;
    int size_deque;
};

// Определения методов класса Deque

template <typename T>
Deque<T>::Deque() {
    this->first = nullptr;
    this->last = nullptr;
    this->size_deque = 0;
}

template <typename T>
bool Deque<T>::is_empty() {
    if (first == nullptr and last == nullptr)
        return true;
    return false;
}

template <typename T>
int Deque<T>::size() {
    return this->size_deque;
}

template <typename T>
void Deque<T>::push_back(T value) {
    Node<T>* new_last = new Node<T>(value);
    if (is_empty()) {
        this->last = new_last;
        this->first = new_last;
    }
    else if (size() == 1) {
        new_last->prev = last;
        first->next = new_last;
        this->last = new_last;
    }
    else {
        new_last->prev = last;
        last->next = new_last;
        this->last = new_last;
    }
    size_deque++;
}

template <typename T>
void Deque<T>::push_front(T value) {
    Node<T>* new_first = new Node<T>(value);
    if (is_empty()) {
        this->first = new_first;
        this->last = new_first;
    }
    else if (size() == 1) {
        new_first->next = first;
        first->prev = first;
        this->first = new_first;
    }
    else {
        first->prev = new_first;
        new_first->next = first;
        first = new_first;
    }
}

template <typename T>
void Deque<T>::pop_front() {
    if (this->first == this->last) {
        delete last;
        this->first = this->last = nullptr;
    }
    else {
        Node<T>* new_first = this->first->next;
        first->next->prev = nullptr;
        delete first;
        this->first = new_first;
    }
    this->size_deque--;
}

template <typename T>
void Deque<T>::pop_back() {
    if (this->first == this->last) {
        delete last;
        this->first = this->last = nullptr;
    }
    else {
        Node<T>* new_last = last->prev;
        last->prev->next = nullptr;
        delete last;
        this->last = new_last;
    }
    this->size_deque--;
}

template <typename T>
Node<T>* Deque<T>::front() {
    if (!is_empty())
        return first;
    throw "Deque is empty!";
}

template <typename T>
Node<T>* Deque<T>::back() {
    if (!is_empty())
        return last;
    throw "Deque is empty!";
}

template<typename T>
void Deque<T>::clear() {
    while (!is_empty()) {
        pop_back();
    }
}
