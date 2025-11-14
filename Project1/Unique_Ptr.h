#pragma once

template<class T>
class Unique_Ptr
{
	T* ptr;
public:
	explicit Unique_Ptr(T* ptr) : ptr(ptr) {}
	~Unique_Ptr() { delete ptr; }

	Unique_Ptr(const Unique_Ptr& obj) = delete;
	Unique_Ptr& operator=(const Unique_Ptr& obj) = delete;
	Unique_Ptr(Unique_Ptr&& obj) {
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}
	Unique_Ptr& operator=(Unique_Ptr&& obj)
	{
		if (this != &obj)
		{
			delete ptr;
			ptr = obj.ptr;
			obj.ptr = nullptr;
		}
		return *this;
	}

	T& operator*() { return *ptr };
	T* operator->() { return ptr };
};