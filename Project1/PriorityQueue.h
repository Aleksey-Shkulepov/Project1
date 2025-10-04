#pragma once

#include "Queue.h"

template<typename T, typename TPri = int>
class PriorityQueue : public Queue<T, TPri>
{
public:
	void enqueue(const T& value, TPri pri) override;
};

template<typename T, typename TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, TPri pri)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);

	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (priority > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else if (priority <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else
	{
		Node<T, TPri>* pos = first;
		while (priority <= pos->next->priority)
		{
			pos = pos->next;
		}

		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;
}