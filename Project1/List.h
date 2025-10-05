#pragma once

namespace mystd {

	template<typename T>
	class List
	{
	public:
		List();
		~List();

		void pop_front();
		void push_back(T data);
		unsigned int GetSize() { return size; }
		void clear();

		T& operator[](const unsigned int index);
	private:

		template<typename T>
		class Node
		{
		public:
			Node* pNext;
			T data;
			Node(T data = T(), Node* pNext = nullptr)
			{
				this->data = data;
				this->pNext = pNext;
			}
		};

		unsigned int size;
		Node<T>* head;
	};

	template<typename T>
	List<T>::List()
	{
		size = 0;
		head = nullptr;
	}

	template<typename T>
	List<T>::~List()
	{
		clear();
	}

	template<typename T>
	inline void List<T>::pop_front()
	{
		Node<T>* temp = head;

		head = head->pNext;
		delete temp;

		size--;
	}

	template<typename T>
	inline void List<T>::push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}

		size++;
	}

	template<typename T>
	inline void List<T>::clear()
	{
		while (size)
		{
			pop_front();
		}
	}

	template<typename T>
	T& List<T>::operator[](const unsigned int index)
	{
		unsigned int counter = 0;
		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
}