#pragma once

/// <summary>
/// General Node
/// </summary>
template<class T, class TPri = int>
struct gNode
{
	T value;
	TPri priority;
	gNode* pNext;

	gNode(T val, TPri pri) : value(val), priority(pri), pNext(nullptr) {}
};


