#pragma once

#include "SOSL.h"

class String
{
	char* str = nullptr;
	size_t size;

public:
	String(int size = 80);
	String(const char* str);
	String(const String& obj);
	~String();
	void set();
	void set(const char* str);
	void print() const;
	size_t length() const;

	String& operator = (const String& other);
	bool operator == (const String& other);
	bool operator != (const String& other);


	friend ostream& operator<<(ostream& os, const String& fr);
};

ostream& operator<<(ostream& os, const String& str)
{
	os << str.str;
	return os;
}

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;

	set(other.str); 

	return *this;
}

//bool String::operator==(const String& other)
//{
//	if (this == &other)
//		return true;
//
//	if (this->size != other.size) return false;
//
//	return ;
//}
//
//
//String& String::operator!=(const String& other)
//{
//	if (this == &other)
//		return *this;
//
//	set(other.str);
//
//	return *this;
//}



String::String(int size)
{
	if (size < 0)
		size = 0;
	this->size = size;
	this->str = new char[size + 1];
	this->str[0] = '\0';
}

String::String(const char* str)
{
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy_s(this->str, size + 1, str);
}

String::String(const String& obj)
{
	size = obj.size;
	str = new char[size + 1];
	strcpy_s(str, size + 1, obj.str);
}

String::~String()
{
	if (str != nullptr)
		delete[] str;
}

void String::set()
{
	char buffer[1000];
	cin.getline(buffer, 1000);
	set(buffer);
}

void String::set(const char* str)
{
	if (str == nullptr)
	{
		if (this->str != nullptr)
			this->str[0] = '\0';
		size = 0;
		return;
	}
	size = strlen(str);
	if (this->str != nullptr)
		delete[] this->str;
	this->str = new char[size + 1];
	strcpy_s(this->str, size + 1, str);
}

void String::print() const
{
	if (str != nullptr)
		cout << str << endl;
}

size_t String::length() const
{
	return size;
}