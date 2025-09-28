#pragma once

#include "SOSL.h"
#include "mystd.h"

class String
{
    char* str = nullptr;
    size_t size;

public:
    String(int size = 80);
    String(const char* str);
    String(const String& obj);

    String& operator=(const String& obj);

    ~String();

    size_t get_length() const;
    char* to_char() const;

    String operator+(const String& other) const;
    void operator+=(const String& other);

    char operator[](int index);

    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator>(const String& other)  const;
    bool operator<(const String& other)  const;
    bool operator>=(const String& other) const;
    bool operator<=(const String& other) const;

    friend ostream& operator<<(ostream& os, const String& obj);
    friend istream& operator>>(istream& is, String& obj);
};

String::String(int size)
{
    if (size < 0) size = 0;
    this->size = size;
    str = new char[size + 1];
    str[0] = '\0';
}

String::String(const char* s)
{
    size = strlen(s);
    str = new char[size + 1];
    strcpy_s(str, size + 1, s);
}

String::String(const String& obj)
{
    size = obj.size;
    str = new char[size + 1];
    strcpy_s(str, size + 1, obj.str);
}

String& String::operator=(const String& other)
{
    if (this == &other) return *this;

    delete[] str;
    size = other.size;
    str = new char[size + 1];
    strcpy_s(str, size + 1, other.str);
    return *this;
}

String::~String()
{
    delete[] str;
}

size_t String::get_length() const
{
    return size;
}

char* String::to_char() const
{
    return str;
}

String String::operator+(const String& other) const
{
    String result(size + other.size);
    strcpy_s(result.str, result.size + 1, str);
    strcat_s(result.str, result.size + 1, other.str);
    return result;
}

void String::operator+=(const String& other)
{
    char* temp = new char[size + other.size + 1];
    strcpy_s(temp, size + 1, str);
    strcat_s(temp, size + other.size + 1, other.str);
    delete[] str;
    str = temp;
    size += other.size;
}

char String::operator[](int index)
{
    if (index < 0 || index >= size)
        throw my_out_of_range();
    return str[index];
}

bool String::operator==(const String& other) const
{
    return strcmp(str, other.str) == 0;
}

bool String::operator!=(const String& other) const
{
    return strcmp(str, other.str) != 0;
}

bool String::operator>(const String& other) const
{
    return strcmp(str, other.str) > 0;
}

bool String::operator<(const String& other) const
{
    return strcmp(str, other.str) < 0;
}

bool String::operator>=(const String& other) const
{
    return strcmp(str, other.str) >= 0;
}

bool String::operator<=(const String& other) const
{
    return strcmp(str, other.str) <= 0;
}

ostream& operator<<(ostream& os, const String& obj)
{
    os << obj.str;
    return os;
}

istream& operator>>(istream& in, String& obj)
{
    char buffer[1000];
    in.getline(buffer, 1000);

    delete[] obj.str;
    obj.size = strlen(buffer);
    obj.str = new char[obj.size + 1];
    strcpy_s(obj.str, obj.size + 1, buffer);

    return in;
}