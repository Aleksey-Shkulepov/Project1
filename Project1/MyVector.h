﻿#pragma once

using namespace std;

#include<iostream>
#include<Windows.h>
#include<iomanip>

template<typename T>
class myVector {
private:
    T* arr;
    size_t s;
public:
    /// Перегрузка оператора [] (индексирования)
    T& operator[] (size_t index)
    {
        return arr[index];
    }

    /// Перегрузка оператора = (присваивания)
    myVector& operator = (const myVector& other)
    {
        this->s = other.s;

        delete this->arr;

        this->arr = new T[other.s];

        for (size_t i = 0; i < other.s; i++)
        {
            this->arr[i] = other.arr[i];
        }

        return *this;
    }

    /// Конструктор копирования
    myVector(const myVector& other)
    {
        this->s = other.s;

        this->arr = new T[other.s];

        for (size_t i = 0; i < other.s; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    /// Конструктор по умол.
    myVector()
    {
        arr = nullptr;
        s = 0;
    }

    /// Конструктор с параметрами
    myVector(size_t s, T n = 0)
    {
        this->s = s;

        this->arr = new T[s];

        for (size_t i = 0; i < s; i++)
        {
            arr[i] = n;
        }
    }

    /// Деструктор
    ~myVector()
    {
        delete[] arr;
    }

    /// Добавляет указанный элемент в конец вектора
    void add(T elem) {
        T* newArr = new T[s + 1];

        for (size_t i = 0; i < s; i++)
            newArr[i] = arr[i];
        newArr[s] = elem;

        delete[] arr;
        arr = newArr;

        this->s++;
    }

    /// Вставляет элемент на указанную позицую вектора
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

    /// Удаляет элемент вектора на указаной позиции
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

    /// Расширяет вектор до n-го размера элементов
    void resize(size_t s, T value = 0) {
        T* newArr = new T[s];

        size_t min_s = (s < this->s) ? s : this->s;

        for (size_t i = 0; i < min_s; i++)
            newArr[i] = arr[i];
        for (size_t i = min_s; i < s; i++)
            newArr[i] = value;

        delete[] arr;
        arr = newArr;

        this->s = s;
    }

    /// Заполняет вектор рандомными числами от мин(по умол. 0) до макс(по умол. 9)
    void fill(T min = 0, T max = 9)
    {
        for (auto i = 0; i < s; i++)
        {
            arr[i] = rand() % ((int)max - (int)min + 1) + min;
        }
    }

    template<class T>
    bool asc(T a, T b) {
        return a > b;
    }

    /// Сортирует вектор, по умол. от мин до макс
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

    /// Выводит вектор в консоль
    void print() const {
        for (size_t i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /// Возвращает размер вектора
    int get_size() const {
        return this->s;
    }
};