#pragma once

#include "Queue.h"

namespace mystd {

	template<typename T, typename TPri = int>
	class PriorityQueue : public Queue<T, TPri>
	{
	public:
		void enqueue(const T& value) override { enqueue(value, TPri()); };
		void enqueue(const T& value, TPri pri);
	};

	template<typename T, typename TPri>
	void PriorityQueue<T, TPri>::enqueue(const T& value, TPri pri)
	{
		gNode<T, TPri>* newGNode = new gNode<T, TPri>(value, pri);

		if (this->size == 0)
		{
			this->first = this->last = newGNode;
			this->size++;
			return;
		}

		if (pri > this->first->priority)
		{
			newGNode->pNext = this->first;
			this->first = newGNode;
		}
		else if (pri <= this->last->priority)
		{
			this->last->pNext = newGNode;
			this->last = newGNode;
		}
		else
		{
			gNode<T, TPri>* pos = this->first;
			while (pri <= pos->pNext->priority)
			{
				pos = pos->pNext;
			}

			newGNode->pNext = pos->pNext;
			pos->pNext = newGNode;
		}
		this->size++;
	}
}