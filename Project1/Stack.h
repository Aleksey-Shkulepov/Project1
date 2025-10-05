#pragma once

#include "fullstd.h"

namespace mystd {

	template<typename T, size_t maxSize = 100>
	class Stack
	{
		template<typename T>
		class Node
		{
		public:
			Node* pNext;
			T value;
			Node(T value = T(), Node* pNext = nullptr)
			{
				this->value = value;
				this->pNext = pNext;
			}
		};

		Node<T>* first = nullptr;
		size_t size = 0;
	public:
		Stack();

		~Stack();

		Stack(const Stack& obj);

		Stack& operator=(const Stack& obj);

		bool push(const T& value);

		void pop();

		T& peek();

		bool isEmpty() const;

		bool isFull() const;

		size_t get_size() const;

		void print() const;

		void clear();
	};

	template<typename T, size_t maxSize>
	Stack<T, maxSize>::Stack()
	{
		size = 0;
		first = nullptr;
	}

	template<typename T, size_t maxSize>
	Stack<T, maxSize>::~Stack()
	{
		clear();
	}

	template<typename T, size_t maxSize>
	Stack<T, maxSize>::Stack(const Stack& obj)
	{
		Node<T>* objFirst = obj.first;
		Node<T>* pFirst = nullptr;
		Node<T>* newNode = nullptr;

		this->first = new Node<T>(objFirst->value);
		pFirst = this->first;
		objFirst = objFirst->pNext;

		while (objFirst) {
			newNode = new Node<T>(objFirst->value);
			pFirst->pNext = newNode;
			pFirst = newNode;
			objFirst = objFirst->pNext;
		}
		pFirst->pNext = nullptr;
		size = obj.size;
	}

	template<typename T, size_t maxSize>
	Stack<T, maxSize>& Stack<T, maxSize>::operator=(const Stack& obj)
	{
		if (this == &obj)
			return *this;

		clear();

		if (obj.first == nullptr) {
			first = nullptr;
			size = 0;
			return *this;
		}

		Node<T>* objFirst = obj.first;
		Node<T>* pFirst = nullptr;
		Node<T>* newNode = nullptr;

		this->first = new Node<T>(objFirst->value);
		pFirst = this->first;
		objFirst = objFirst->pNext;

		while (objFirst) {
			newNode = new Node<T>(objFirst->value);
			pFirst->pNext = newNode;
			pFirst = newNode;
			objFirst = objFirst->pNext;
		}
		pFirst->pNext = nullptr;
		size = obj.size;

		return *this;
	}

	template<typename T, size_t maxSize>
	bool Stack<T, maxSize>::push(const T& value)
	{
		if (size == maxSize) {
			return false;
		}
		if (size == 0) {
			first = new Node<T>(value);
		}
		else {
			Node<T>* newNode = new Node<T>(value);
			newNode->pNext = first;
			first = newNode;
		}
		size++;
		return true;
	}

	template<typename T, size_t maxSize>
	T& Stack<T, maxSize>::peek()
	{
		return first->value;
	}

	template<typename T, size_t maxSize>
	bool Stack<T, maxSize>::isEmpty() const
	{
		return size == 0;
	}

	template<typename T, size_t maxSize>
	bool Stack<T, maxSize>::isFull() const
	{
		return size == maxSize;
	}

	template<typename T, size_t maxSize>
	inline size_t Stack<T, maxSize>::get_size() const
	{
		return size;
	}

	template<typename T, size_t maxSize>
	void Stack<T, maxSize>::print() const
	{
		Node<T>* current = first;
		while (current != nullptr) {
			cout << current->value << " ";
			current = current->pNext;
		}
		cout << endl;
	}

	template<typename T, size_t maxSize>
	void Stack<T, maxSize>::clear()
	{
		Node<T>* temp = first;
		while (temp) {
			first = first->pNext;
			delete temp;
			temp = first;
		}
		size = 0;
	}

	template<typename T, size_t maxSize>
	void Stack<T, maxSize>::pop()
	{
		if (size > 0) {
			Node<T>* temp = first;

			first = first->pNext;
			delete temp;

			size--;
		}
	}
}