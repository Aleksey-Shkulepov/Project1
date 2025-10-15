#pragma once

#include "fullstd.h"

namespace mystd {
	inline void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	template<typename T>
	class ForwardList
	{
	public:
		ForwardList();
		~ForwardList();
		ForwardList(initializer_list<T> list);
		ForwardList(const ForwardList& obj);
		ForwardList operator=(const ForwardList& obj);

		void push_front(const T& value);
		void push_back(const T& value);
		void insert(const T& value, int index);

		void pop_front();
		void pop_back();
		void remove(int index);

		size_t get_size() const { return size; }
		void clear();
		void print();
		void print(int x, int y, int count);
		int find(const T& value);

		bool is_empty() const { return size == 0; }

		T& operator[](const size_t index);
		const T& operator[](const size_t index) const;
		ForwardList operator+=(const ForwardList& obj);
		ForwardList operator+(const ForwardList& obj);
	private:

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

		Node<T>* getNode(int index)
		{
			Node<T>* pos = first;
			for (size_t i = 0; i < index; i++)
			{
				pos = pos->pNext;
			} 
			return pos;
		}

		size_t size = 0;
		Node<T>* first = nullptr;
		Node<T>* last = nullptr;
	};

	template<typename T>
	ForwardList<T>::ForwardList()
	{}

	template<typename T>
	ForwardList<T>::~ForwardList()
	{
		clear();
	}

	template<typename T>
	ForwardList<T>::ForwardList(initializer_list<T> list)
	{
		for (const auto& v : list) {
			push_back(v);
		}
	}

	template<typename T>
	ForwardList<T>::ForwardList(const ForwardList& obj)
	{
		Node<T>* temp = obj.first;
		while (temp) {
			push_back(temp->value);
			temp = temp->pNext;
		}
	}

	template<typename T>
	ForwardList<T> ForwardList<T>::operator=(const ForwardList& obj)
	{
		if (this == &obj) return *this;
		clear();
		Node<T>* temp = obj.first;
		while (temp) {
			push_back(temp->value);
			temp = temp->pNext;
		}
		return *this;
	}

	template<typename T>
	void ForwardList<T>::pop_front()
	{
		if (size > 0) {
			Node<T>* temp = first;
			first = first->pNext;
			delete temp;
			size--;
		}
	}

	template<typename T>
	void ForwardList<T>::pop_back()
	{
		if (size > 0) {
			last = getNode(size - 2);
			delete last->pNext;
			last->pNext = nullptr;
			size--;
		}
	}

	template<typename T>
	void ForwardList<T>::remove(int index)
	{
		if (index < 0 || index <= size) {
			return;
		}
		if (index == 0) {
			pop_front();
		}
		else if (index == size - 1) {
			pop_back();
		}
		else {
			Node<T>* pos = getNode(index - 1);
			Node<T>* temp = pos->pNext;
			pos->pNext = pos->pNext->pNext;
			delete temp;
			size--;
		}
	}

	template<typename T>
	void ForwardList<T>::push_front(const T& value)
	{
		Node<T>* newNode = new Node<T>(value, first);
		first = newNode;
		if (size == 0) {
			last = first;
		}
		size++;
	}

	template<typename T>
	void ForwardList<T>::push_back(const T& value)
	{
		Node<T>* newNode = new Node<T>(value, nullptr);
		if (size == 0) {
			first = last = newNode;
		}
		else {
			last->pNext = newNode;
			last = newNode;
		}
		size++;
	}

	template<typename T>
	void ForwardList<T>::insert(const T& value, int index)
	{
		if (index >= size) throw mystd::Out_of_range("Index out of range");

		if (index == 0) 
		{
			push_front(value);
		}
		else if (index == size) 
		{
			push_back(value);
		}
		else 
		{
			Node<T>* newNode = new Node<T>(value);
			Node<T>* pos = getNode(index-1);
			newNode->pNext = pos->pNext;
			pos->pNext = newNode;
			size++;
		}
	}

	template<typename T>
	void ForwardList<T>::clear()
	{
		Node<T>* temp = first;
		while (temp) {
			first = first->pNext;
			delete temp;
			temp = first;
		}
		size = 0;
	}

	template<typename T>
	void ForwardList<T>::print()
	{
		Node<T>* temp = first;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->pNext;
		}
		cout << endl;
	}

	template<typename T>
	int ForwardList<T>::find(const T& value)
	{
		Node<T>* temp = first;
		for (size_t i = 0; i < size; i++)
		{
			if (temp->value == value)
			{
				return i;
			}
			temp = temp->pNext;
		}
		return -1;
	}

	template<typename T>
	T& ForwardList<T>::operator[](const size_t index)
	{
		if (index >= size) throw mystd::Out_of_range("Index out of range");
		return getNode(index)->value;
	}

	template<typename T>
	const T& ForwardList<T>::operator[](const size_t index) const
	{
		if (index >= size) throw mystd::Out_of_range("Index out of range");
		return getNode(index)->value;
	}

	template<typename T>
	ForwardList<T> ForwardList<T>::operator+=(const ForwardList& obj)
	{
		Node<T>* temp = obj.first;
		while (temp) {
			this->push_back(temp->value);
			temp = temp->pNext;
		}
		return *this;
	}

	template<typename T>
	ForwardList<T> ForwardList<T>::operator+(const ForwardList& obj)
	{
		ForwardList<T> result(*this);
		result += obj;
		return result;
	}

	template<class T>
	void ForwardList<T>::print(int x, int y, int count)
	{
		Node<T>* temp = first;
		if (count != -1)
		{
			if (size > count)
				temp = getNode(size - count);
		}
		while (temp)
		{
			gotoxy(x, y++);
			cout << temp->value;
			temp = temp->pNext;
		}
		cout << endl;
	}

}

