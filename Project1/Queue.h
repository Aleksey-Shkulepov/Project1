#pragma once

#include "SOSL.h"

#include "initializer_list"
#include "Node.h"

template<typename T, typename TPri>
class Queue
{
protected:
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t size = 0;
public:
	Queue() = default;
	Queue(initializer_list<T> list);
	Queue(const Queue& obj);
	Queue& operator=(const Queue& obj);

	virtual		 ~Queue() { clear(); }
	virtual void enqueue(const T& value);

	T*     front()    const;
	size_t get_size() const;
	bool   isEmpty()  const;

	void dequeue();
	void clear();
	void loop();
	void print() const;
};

template<class T, typename TPri>
Queue<T, TPri>::Queue(const Queue& obj)
{
	Node<T>* temp = obj.first;
	while (temp) {
		this->enqueue(temp->value);
		temp = temp->pNext;
	}
}

template<class T, typename TPri>
inline Queue<T, TPri>& Queue<T, TPri>::operator=(const Queue& obj)
{
	if (this == &obj)
		return *this;

	this->clear();

	Node<T>* temp = obj.first;
	while (temp) {
		this->enqueue(temp->value);
		temp = temp->pNext;
	}

	return *this;
}

template<class T, typename TPri>
void Queue<T, TPri>::enqueue(const T& value)
{
	if (size == 0) {
		first = last = new Node<T>(value);
	}
	else {
		last->pNext = new Node<T>(value);
		last = last->pNext;
	}
	size++;
}

template<class T, typename TPri>
void Queue<T, TPri>::dequeue()
{
	if (size > 0) {
		Node<T>* temp = first;
		first = first->pNext;
		delete temp;
		size--;
	}
}

template<class T, typename TPri>
T* Queue<T, TPri>::front() const
{
	return &first->value;
}

template<class T, typename TPri>
bool Queue<T, TPri>::isEmpty() const
{
	return size == 0;
}

template<class T, typename TPri>
size_t Queue<T, TPri>::get_size() const
{
	return size;
}

template<class T, typename TPri>
void Queue<T, TPri>::print() const
{
	Node<T>* temp = first;
	while (temp) {
		cout << temp->value << " ";
		temp = temp->pNext;
	}
	cout << endl;
}

template<class T, typename TPri>
void Queue<T, TPri>::clear()
{
	Node<T>* temp = first;
	while (temp) {
		first = first->pNext;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T, typename TPri>
void Queue<T, TPri>::loop()
{
	if (size > 1) 
	{
		last->pNext = first;
		first = first->pNext;
		last = last->pNext;
		last->pNext = nullptr;
	}
}

template<class T, typename TPri>
Queue<T, TPri>::Queue(initializer_list<T> list)
{
	for (const T& item : list)
	{
		enqueue(item);
	}
}