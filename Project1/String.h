#pragma once

#include "fullstd.h"
#include "mystd.h"

namespace mystd {

    class String
    {
        char* str = nullptr;
        size_t size;

    public:
        String(int size = 0);
        String(const char* str);
        String(const String& obj);

        String& operator=(const String& obj);

        ~String();

        size_t get_length() const;
        const char* to_char() const;

        void save(ofstream& out) const;
        void load(ifstream& in);

        String operator+(const String& other) const;
        void operator+=(const String& other);

        void operator+=(char c);

        char operator[](int index) const;

        bool operator==(const String& other) const;
        bool operator!=(const String& other) const;
        bool operator>(const String& other)  const;
        bool operator<(const String& other)  const;
        bool operator>=(const String& other) const;
        bool operator<=(const String& other) const;

        friend ostream& operator<<(ostream& os, const String& obj);
        friend istream& operator>>(istream& is, String& obj);
        bool is_empty() const noexcept { return size == 0; }
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

    const char* String::to_char() const
    {
        return str;
    }

    void String::save(ofstream& out) const
    {
        out.write((const char*)&size, sizeof(size));
        out.write(str, size);
    }

    void String::load(ifstream& in)
    {
        size_t newSize;
        in.read((char*)&newSize, sizeof(newSize));

        char* newStr = new char[newSize + 1];
        in.read(newStr, newSize);
        newStr[newSize] = '\0';

        delete[] str;
        str = newStr;
        size = newSize;
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

    void String::operator+=(char c) {
        char* temp = new char[size + 2];
        if (str) {
            strcpy_s(temp, size + 2, str);
        }
        else {
            temp[0] = '\0';
        }
        temp[size] = c;
        temp[size + 1] = '\0';
        delete[] str;
        str = temp;
        ++size;
    }

    char String::operator[](int index) const
    {
        if (index < 0 || index >= size)
            throw mystd::Out_of_range();
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
}