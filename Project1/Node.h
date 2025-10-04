#pragma once

template<class T, class TPri = int>
class Node
{
	T value;
	TPri priority;
	Node* pNext;

	Node(T val) : value(val), next(nullptr) {}
	Node(T val, TPri pri) : value(val), priority(pri), next(nullptr) {}
};

