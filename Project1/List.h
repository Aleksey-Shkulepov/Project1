#pragma once

#include "fullstd.h"

#include "Concepts.h"

namespace mystd {
	template<typename T>
	class List
	{
	private:
		template<typename T>
		class Node
		{
		public:
			Node* pNext;
			Node* pPrev;
			T value;
			Node(T value = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
			{
				this->value = value;
				this->pNext = pNext;
				this->pPrev = pPrev;
			}
		};

		Node<T>* getNode(int index)
		{
			Node<T>* pos;
			if (index < size / 2)
			{
				pos = first;
				for (size_t i = 0; i < index; i++)
				{
					pos = pos->pNext;
				}
			}
			else {
				pos = last;
				for (size_t i = 0; i < size - index - 1; i++)
				{
					pos = pos->pPrev;
				}
			}
			return pos;
		}

		size_t   size = 0;
		Node<T>* first = nullptr;
		Node<T>* last = nullptr;
	public:
		List();
		~List();
		List(initializer_list<T> list);
		List(const List& obj);
		List operator=(const List& obj);

		void push_front(const T& value);
		void push_back(const T& value);
		void insert(const T& value, int index);

		void pop_front();
		void pop_back();
		void remove(int index);

		T& at(size_t index) {
			if (index >= size) throw mystd::Out_of_range();
			return getNode(index)->value;
		}
		const T& at(size_t index) const {
			if (index >= size) throw mystd::Out_of_range();
			return getNode(index)->value;
		}

		T& front() {
			if (is_empty()) throw mystd::Out_of_range();
			return first->value;
		}
		const T& front() const {
			if (is_empty()) throw mystd::Out_of_range();
			return first->value;
		}

		T& back() {
			if (is_empty()) throw mystd::Out_of_range();
			return last->value;
		}
		const T& back() const {
			if (is_empty()) throw mystd::Out_of_range();
			return last->value;
		}

		Node<T>* getFirst() const { return first; }
		Node<T>* getLast() const { return last; }

		size_t get_size() const { return size; }
		void clear();
		void print();

		bool is_empty() const { return size == 0; }

		T& operator[](const size_t index);
		const T& operator[](const size_t index) const;
		List operator+=(const List& obj);
		List operator+(const List& obj);

		int find(const T& value);

		void for_each(void(*method)(T& value));

		/// <summary>
		/// Удаляет из списка диапазон элементов и возвращает их как новый список.
		/// </summary>
		/// <param name="index1">Начальный индекс (включительно) диапазона для вырезания.</param>
		/// <param name="index2">Конечный индекс (включительно) диапазона для вырезания.</param>
		/// <returns> Новый List[T], содержащий элементы с индексами от index1 до index2 включительно </returns>
		List splice(int index1, int index2);

		void save(ofstream& out) const requires HasSave<T>;
		void load(ifstream& in) requires HasLoad<T>;
	};

	template<typename T>
	List<T>::List()
	{}

	template<typename T>
	List<T>::~List()
	{
		clear();
	}

	template<typename T>
	List<T>::List(initializer_list<T> list)
	{
		for (T elem : list) {
			push_back(elem);
		}
	}

	template<typename T>
	List<T>::List(const List& obj)
	{
		Node<T>* temp = obj.first;
		while (temp) {
			push_back(temp->value);
			temp = temp->pNext;
		}
	}

	template<typename T>
	List<T> List<T>::operator=(const List& obj)
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
	void List<T>::pop_front()
	{
		if (size > 1) {
			first = first->pNext;
			delete first->pPrev;
			first->pPrev = nullptr;
		}
		else {
			delete first;
			first = last = nullptr;
		}
		size--;
	}

	template<typename T>
	void List<T>::pop_back()
	{
		if (size > 0) {
			if (size == 1) {
				delete first;
				first = last = nullptr;
				size = 0;
			}
			else {
				last = last->pPrev;
				delete last->pNext;
				last->pNext = nullptr;
			}
			size--;
		}
	}

	template<typename T>
	void List<T>::remove(int index)
	{
		if (index < 0 || index >= size) throw mystd::Out_of_range("Index out of range");
		if (index == 0)
		{
			this->pop_front();
		}
		else if (index == size - 1)
		{
			this->pop_back();
		}
		else
		{
			Node<T>* pos = getNode(index-1);
			Node<T>* temp = pos->pNext;
			pos->pNext = pos->pNext->pNext;
			pos->pNext->pPrev = pos;
			delete temp;
			size--;
		}
	}

	template<typename T>
	void List<T>::push_front(const T& value)
	{
		if (size == 0) {
			first = last = new Node<T>(value);
		}
		else {
			Node<T>* newNode = new Node<T>(value);
			newNode->pNext = first;
			first->pPrev = newNode;
			first = newNode;
		}
		size++;
	}

	template<typename T>
	void List<T>::push_back(const T& value)
	{
		if (size == 0) {
			first = last = new Node<T>(value);
		}
		else {
			last->pNext = new Node<T>(value);
			last->pNext->pPrev = last;
			last = last->pNext;
		}
		size++;
	}

	template<typename T>
	void List<T>::insert(const T& value, int index)
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
			Node<T>* pos = getNode(index);
			Node<T>* newNode = new Node<T>(value);
			newNode->pNext = pos->pNext;
			newNode->next->prev = newNode;
			pos->next = newNode;
			newNode->prev = pos;
			size++;
		}
	}

	template<typename T>
	void List<T>::clear()
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
	void List<T>::print()
	{
		Node<T>* temp = first;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->pNext;
		}
		cout << endl;
	}

	template<typename T>
	int List<T>::find(const T& value)
	{
		Node<T>* temp = first;
		size_t i = 0;
		while (temp) {
			if (temp->value == value) return i;
			temp = temp->pNext;
			i++;
		}
		return -1;
	}

	template<typename T>
	inline void List<T>::for_each(void(*method)(T& value))
	{
		Node<T>* temp = first;
		while (temp) {
			method(temp->value);
			temp = temp->pNext;
		}
	}

	template<typename T>
	inline List<T> List<T>::splice(int index1, int index2)
	{ 
		List<T> newList;
		if (index2 < index1) return newList;
		if (index1 >= size) return newList;

		Node<T>* start = getNode(index1);
		Node<T>* end = getNode(index2);
		if (!start or !end) return newList;

		Node<T>* before = start->pPrev;
		Node<T>* after = end->pNext;

		if (before) before->pNext = after; else first = after;
		if (after) after->pPrev = before; else last = before;

		size_t count = index2 - index1 + 1;
		Node<T>* cur = start;
		for (size_t i = 0; i < count; i++) {
			newList.push_back(cur->value);
			cur = cur->pNext;
		}
		size -= count;
		return newList;
	}

	template<typename T>
	T& List<T>::operator[](const size_t index)
	{
		if (index >= size) throw mystd::Out_of_range("Index out of range");
		return getNode(index)->value;
	}

	template<typename T>
	const T& List<T>::operator[](const size_t index) const
	{
		if (index >= size) throw mystd::Out_of_range("Index out of range");
		return getNode(index)->value;
	}

	template<typename T>
	List<T> List<T>::operator+=(const List& obj)
	{
		Node<T>* temp = obj.first;
		while (temp) {
			this->push_back(temp->value);
			temp = temp->pNext;
		}
		return *this;
	}

	template<typename T>
	List<T> List<T>::operator+(const List& obj)
	{
		List<T> result(*this);
		result += obj;
		return result;
	}

	template<typename T>
	inline void List<T>::save(ofstream& out) const requires HasSave<T>
	{
		size_t sz = get_size();
		out.write((const char*)&sz, sizeof(sz));

		auto node = first;
		while (node) {
			node->value.save(out);
			node = node->pNext;
		}
	}

	template<typename T>
	inline void List<T>::load(ifstream& in) requires HasLoad<T>
	{
		size_t sz;
		in.read((char*)&sz, sizeof(sz));
		clear();

		for (size_t i = 0; i < sz; ++i) {
			T obj;
			obj.load(in);
			push_back(obj);
		}
	}
}

