//#pragma once
//
//#include "fullstd.h"
//
//namespace mystd {
//
//	template<typename T>
//	class ForwardList
//	{
//	public:
//		ForwardList();
//		~ForwardList();
//		ForwardList(initializer_list<T> list);
//		ForwardList(const ForwardList& obj);
//		ForwardList operator=(const ForwardList& obj);
//
//		void push_front(const T& data);
//		void push_back(const T& data);
//		void insert(const T& data, int index);
//
//		void pop_front();
//		void pop_back();
//		void remove(int index);
//
//		size_t get_size() const { return size; }
//		void clear();
//
//		T& operator[](const size_t index) const;
//	private:
//
//		template<typename T>
//		class Node
//		{
//		public:
//			Node* pNext;
//			T data;
//			Node(T data = T(), Node* pNext = nullptr)
//			{
//				this->data = data;
//				this->pNext = pNext;
//			}
//		};
//
//		size_t size;
//		Node<T>* head;
//	};
//
//	template<typename T>
//	ForwardList<T>::ForwardList()
//	{
//		size = 0;
//		head = nullptr;
//	}
//
//	template<typename T>
//	ForwardList<T>::~ForwardList()
//	{
//		clear();
//	}
//
//	template<typename T>
//	ForwardList<T>::ForwardList(initializer_list<T> list)
//	{
//	}
//
//	template<typename T>
//	ForwardList<T>::ForwardList(const ForwardList& obj)
//	{
//	}
//
//	template<typename T>
//	ForwardList<T> ForwardList<T>::operator=(const ForwardList& obj)
//	{
//		return ForwardList();
//	}
//
//	template<typename T>
//	void ForwardList<T>::pop_front()
//	{
//		Node<T>* temp = head;
//
//		head = head->pNext;
//		delete temp;
//
//		size--;
//	}
//
//	template<typename T>
//	void ForwardList<T>::pop_back()
//	{
//	}
//
//	template<typename T>
//	void ForwardList<T>::remove(int index)
//	{
//	}
//
//	template<typename T>
//	void ForwardList<T>::push_front(const T& data)
//	{
//		if (size == 0) {
//			head =
//		}
//	}
//
//	template<typename T>
//	void ForwardList<T>::push_back(const T& data)
//	{
//		if (head == nullptr)
//		{
//			head = new Node<T>(data);
//		}
//		else
//		{
//			Node<T>* current = this->head;
//
//			while (current->pNext != nullptr)
//			{
//				current = current->pNext;
//			}
//			current->pNext = new Node<T>(data);
//		}
//
//		size++;
//	}
//
//	template<typename T>
//	void ForwardList<T>::insert(const T& data, int index)
//	{
//	}
//
//	template<typename T>
//	void ForwardList<T>::clear()
//	{
//		while (size)
//		{
//			pop_front();
//		}
//	}
//
//	template<typename T>
//	T& ForwardList<T>::operator[](const size_t index) const
//	{
//		size_t counter = 0;
//		Node<T>* current = this->head;
//
//		while (current != nullptr)
//		{
//			if (counter == index)
//			{
//				return current->data;
//			}
//			current = current->pNext;
//			counter++;
//		}
//	}
//}
//
