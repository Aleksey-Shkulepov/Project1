#pragma once

#include "fullstd.h"
#include <initializer_list>

#include "gNode.h"

namespace mystd {

	template<typename T, typename TPri = int>
	class Queue
	{
	protected:
		gNode<T, TPri>* first = nullptr;
		gNode<T, TPri>* last = nullptr;
		size_t size = 0;
	public:
		Queue() = default;
		Queue(initializer_list<T> list);
		Queue(const Queue& obj);
		Queue& operator=(const Queue& obj);

		virtual		 ~Queue() { clear(); }
		virtual void enqueue(const T& value);

		T* front()    const;
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
		gNode<T, TPri>* temp = obj.first;
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

		gNode<T, TPri>* temp = obj.first;
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
			first = last = new gNode<T, TPri>(value);
		}
		else {
			last->pNext = new gNode<T, TPri>(value);
			last = last->pNext;
		}
		size++;
	}

	template<class T, typename TPri>
	void Queue<T, TPri>::dequeue()
	{
		if (size > 0) {
			gNode<T, TPri>* temp = first;
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
		gNode<T, TPri>* temp = first;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->pNext;
		}
		cout << endl;
	}

	template<class T, typename TPri>
	void Queue<T, TPri>::clear()
	{
		gNode<T, TPri>* temp = first;
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
}