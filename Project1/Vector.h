#pragma once

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <initializer_list>
#include <type_traits>
#include <cstdlib>
#include <limits>

#include "String.h"
#include "Concepts.h"
#include "Iterator_Traits.h"

namespace mystd {

    template<typename T>
    class Vector {
    private:
        T* arr = nullptr;
        size_t s = 0;

        static T* allocate_and_copy(const T* src, size_t n) {
            if (n == 0) return nullptr;
            T* newArr = new T[n];
            for (size_t i = 0; i < n; ++i) newArr[i] = src[i];
            return newArr;
        }

    public:
        class iterator {
        public:
            using difference_type = long long;
            using pointer = T*;
            using reference = T&;

            iterator(T* p = nullptr) : ptr(p) {}
            reference operator*()  const { return *ptr; }
            pointer   operator->() const { return ptr; }

            iterator& operator++()    { ++ptr; return *this; }
            iterator  operator++(int) { iterator tmp = *this; ++*this; return tmp; }
            iterator& operator--()    { --ptr; return *this; }
            iterator  operator--(int) { iterator tmp = *this; --*this; return tmp; }

            iterator        operator+(difference_type d) const { return iterator(ptr + d); }
            iterator        operator-(difference_type d) const { return iterator(ptr - d); }
            difference_type operator-(const iterator& o) const { return (difference_type)(ptr - o.ptr); }
            reference       operator[](size_t i)         const { return ptr[i]; }

            bool operator==(const iterator& o) const { return ptr == o.ptr; }
            bool operator!=(const iterator& o) const { return ptr != o.ptr; }
            bool operator<(const iterator& o)  const { return ptr < o.ptr; }
            bool operator>(const iterator& o)  const { return ptr > o.ptr; }
            bool operator<=(const iterator& o) const { return ptr <= o.ptr; }
            bool operator>=(const iterator& o) const { return ptr >= o.ptr; }

            T* get() const { return ptr; }

        private:
            T* ptr;
        };

        class const_iterator {
        public:
            using difference_type = long long;
            using pointer = const T*;
            using reference = const T&;

            const_iterator(const T* p = nullptr) : ptr(const_cast<T*>(p)) {}
            const_iterator(const iterator& it) : ptr(it.get()) {}

            reference operator*() const { return *ptr; }
            pointer operator->()  const { return ptr; }

            const_iterator& operator++()    { ++ptr; return *this; }
            const_iterator  operator++(int) { const_iterator tmp = *this; ++*this; return tmp; }
            const_iterator& operator--()    { --ptr; return *this; }
            const_iterator  operator--(int) { const_iterator tmp = *this; --*this; return tmp; }

            const_iterator  operator+(difference_type d)       const { return const_iterator(ptr + d); }
            const_iterator  operator-(difference_type d)       const { return const_iterator(ptr - d); }
            difference_type operator-(const const_iterator& o) const { return (difference_type)(ptr - o.ptr); }
            reference       operator[](size_t i)               const { return ptr[i]; }

            bool operator==(const const_iterator& o) const { return ptr == o.ptr; }
            bool operator!=(const const_iterator& o) const { return ptr != o.ptr; }
            bool operator<(const const_iterator& o)  const { return ptr < o.ptr; }
            bool operator>(const const_iterator& o)  const { return ptr > o.ptr; }
            bool operator<=(const const_iterator& o) const { return ptr <= o.ptr; }
            bool operator>=(const const_iterator& o) const { return ptr >= o.ptr; }

        private:
            T* ptr;
        };

        Vector() noexcept = default;

        explicit Vector(size_t n, const T& value = T()) {
            s = n;
            if (s) {
                arr = new T[s];
                for (size_t i = 0; i < s; ++i) arr[i] = value;
            }
        }

        Vector(initializer_list<T> il) {
            s = il.size();
            if (s) {
                arr = new T[s];
                size_t i = 0;
                for (auto& v : il) arr[i++] = v;
            }
        }

        Vector(const Vector& other) {
            s = other.s;
            arr = allocate_and_copy(other.arr, s);
        }

        void swap(Vector& other) noexcept {
            std::swap(arr, other.arr);
            std::swap(s, other.s);
        }

        Vector(Vector&& other) noexcept {
            arr = other.arr;
            s = other.s;
            other.arr = nullptr;
            other.s = 0;
        }

        ~Vector() {
            delete[] arr;
            arr = nullptr;
            s = 0;
        }

        Vector& operator=(Vector other) noexcept(std::is_nothrow_move_constructible<T>::value) {
            swap(other);
            return *this;
        }

        T& operator[](size_t index) {
            return arr[index];
        }
        const T& operator[](size_t index) const {
            return arr[index];
        }

        T& at(size_t index) {
            if (index >= s) throw mystd::Out_of_range();
            return arr[index];
        }
        const T& at(size_t index) const {
            if (index >= s) throw mystd::Out_of_range();
            return arr[index];
        }

        T& front() {
            if (is_empty()) throw mystd::Out_of_range();
            return arr[0];
        }
        const T& front() const {
            if (is_empty()) throw mystd::Out_of_range();
            return arr[0];
        }

        T& back() {
            if (is_empty()) throw mystd::Out_of_range();
            return arr[s - 1];
        }
        const T& back() const {
            if (is_empty()) throw mystd::Out_of_range();
            return arr[s - 1];
        }

        size_t get_size() const noexcept { return s; }
        bool is_empty() const noexcept { return s == 0; }

        void clear() noexcept {
            delete[] arr;
            arr = nullptr;
            s = 0;
        }

        void push_back(const T& value) {
            T* newArr = new T[s + 1];
            for (size_t i = 0; i < s; ++i) newArr[i] = arr[i];
            newArr[s] = value;
            delete[] arr;
            arr = newArr;
            ++s;
        }

        void pop_back() {
            if (s == 0) return;
            if (s == 1) {
                delete[] arr;
                arr = nullptr;
                s = 0;
                return;
            }
            T* newArr = new T[s - 1];
            for (size_t i = 0; i < s - 1; ++i) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            --s;
        }

        void resize(size_t new_size, const T& value = T()) {
            if (new_size == s) return;
            if (new_size == 0) {
                clear();
                return;
            }
            T* newArr = new T[new_size];
            size_t min_s = (new_size < s) ? new_size : s;
            for (size_t i = 0; i < min_s; ++i) newArr[i] = arr[i];
            for (size_t i = min_s; i < new_size; ++i) newArr[i] = value;
            delete[] arr;
            arr = newArr;
            s = new_size;
        }

        bool insert(T elem, size_t pos) {
            if (pos >= this->s)
                return false;

            T* newArr = new T[s + 1];

            for (size_t i = 0, j = 0; i < s + 1; i++)
                newArr[i] = (i != pos) ? arr[j++] : elem;

            delete[] arr;
            arr = newArr;

            this->s++;
        }

        bool pop(size_t pos) {
            if (pos >= this->s)
                return false;

            T* newArr = new T[s - 1];

            for (size_t i = 0, j = 0; i < s; i++)
                if (i != pos) newArr[j++] = arr[i];

            delete[] arr;
            arr = newArr;

            this->s--;
        }

        iterator insert(const_iterator pos_c, const T& value) {
            size_t pos = pos_c - arr;
            if (pos > s) pos = s;
            T* newArr = new T[s + 1];
            for (size_t i = 0, j = 0; i < s + 1; ++i) {
                if (i == pos) {
                    newArr[i] = value;
                }
                else {
                    newArr[i] = arr[j++];
                }
            }
            delete[] arr;
            arr = newArr;
            ++s;
            return arr + pos;
        }

        iterator erase(const_iterator pos_c) {
            if (pos_c < begin() || pos_c >= end()) throw mystd::Out_of_range("Vector::erase out of range");
            size_t pos = pos_c - arr;
            if (s == 1) {
                clear();
                return end();
            }
            T* newArr = new T[s - 1];
            for (size_t i = 0, j = 0; i < s; ++i) {
                if (i == pos) continue;
                newArr[j++] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            --s;
            return arr + pos;
        }


        template<class T>
        bool asc(T a, T b) {
            return a > b;
        }

        void sort(bool(*comp)(T, T) = asc)
        {
            for (size_t i = 0; i < s - 1; i++)
            {
                for (size_t j = 0; j < s - 1 - i; j++)
                {
                    if (comp(arr[j], arr[j + 1])) swap(arr[j], arr[j + 1]);
                }
            }
        }

        void print() const {
            for (size_t i = 0; i < s; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        iterator begin() noexcept { return iterator(arr); }
        iterator end()   noexcept { return iterator(arr + s); }

        const_iterator begin()  const noexcept { return const_iterator(arr); }
        const_iterator end()    const noexcept { return const_iterator(arr + s); }
        const_iterator cbegin() const noexcept { return const_iterator(arr); }
        const_iterator cend()   const noexcept { return const_iterator(arr + s); }

        void save(ofstream& out) const requires HasSave<T>;
        void load(ifstream& in) requires HasLoad<T>;

        Vector operator+(const Vector& other) const;
    };

    template<typename T>
    Vector<T> Vector<T>::operator+(const Vector& other) const {
        Vector result;
        result.s = this->s + other.s;
        if (result.s == 0) return result;

        result.arr = new T[result.s];
        for (size_t i = 0; i < this->s; ++i)
            result.arr[i] = this->arr[i];
        for (size_t i = 0; i < other.s; ++i)
            result.arr[this->s + i] = other.arr[i];

        return result;
    }

    template<typename T>
    void swap(Vector<T>& a, Vector<T>& b) noexcept {
        a.swap(b);
    }

    template<typename T>
    inline void Vector<T>::save(ofstream& out) const requires HasSave<T>
    {
        out.write((const char*)&s, sizeof(s));
        for (size_t i = 0; i < s; ++i)
            this->at(i).save(out);
    }

    template<typename T>
    inline void Vector<T>::load(ifstream& in) requires HasLoad<T>
    {
        in.read((char*)&s, sizeof(s));
        clear();
        for (size_t i = 0; i < s; ++i) {
            T obj; obj.load(in); push_back(obj);
        }
    }
}
