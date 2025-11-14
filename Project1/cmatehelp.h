#pragma once

#include <iostream>
#include <initializer_list>
#include <stdexcept>

using namespace std;

template<class T, class TPri = int>
struct Node
{
    T value;
    TPri priority;
    Node* next;
    Node* prev;

    Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    Node(T val, TPri pri) : value(val), priority(pri), next(nullptr), prev(nullptr) {}
};

template<class T>
class List
{
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    size_t size = 0;

    Node<T>* getNode(int index) const;

public:
    List();
    List(initializer_list<T> list);
    ~List();
    List(const List& list);
    List& operator=(const List& list);

    void push_front(const T& value);
    void push_back(T& value);
    void push_back(T&& value);
    void insert(const T& value, int index);

    void pop_front();
    void pop_back();
    void remove(int index);

    T& front();
    T& back();
    T& at(int index);
    T& operator[](int index) const;

    void clear();
    void print() const;

    size_t length() const;

    List operator+(const List& list);
    void operator+=(const List& list);

    int find(const T& value);

    void for_each(void(*method)(T& value));

    List splice(int index1, int index2);
};

template<class T>
size_t List<T>::length() const
{
    return size;
}

template<class T>
Node<T>* List<T>::getNode(int index) const
{
    Node<T>* pos = nullptr;
    if (index < size / 2)
    {
        pos = first;
        for (int i = 0; i < index; i++)
            pos = pos->next;
    }
    else
    {
        pos = last;
        for (int i = size - 1; i > index; i--)
            pos = pos->prev;
    }
    return pos;
}

template<class T>
List<T>::List() {}

template<class T>
List<T>::List(initializer_list<T> list)
{
    for (const T& elem : list)
        push_back(elem);
}

template<class T>
List<T>::~List()
{
    clear();
}

template<class T>
List<T>::List(const List& list)
{
    Node<T>* temp = list.first;
    while (temp)
    {
        T val = temp->value;
        push_back(val);
        temp = temp->next;
    }
}

template<class T>
List<T>& List<T>::operator=(const List<T>& list)
{
    if (this == &list)
        return *this;

    clear();
    Node<T>* temp = list.first;
    while (temp)
    {
        T val = temp->value;
        push_back(val);
        temp = temp->next;
    }
    return *this;
}

template<class T>
void List<T>::push_front(const T& value)
{
    try
    {
        Node<T>* newNode = new Node<T>(value);
        if (size == 0)
        {
            first = last = newNode;
        }
        else
        {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        size++;
    }
    catch (const bad_alloc&)
    {
        throw;
    }
}

template<class T>
void List<T>::push_back(T& value)
{
    try
    {
        if (size == 0)
        {
            first = last = new Node<T>(value);
        }
        else
        {
            last->next = new Node<T>(value);
            last->next->prev = last;
            last = last->next;
        }
        size++;
    }
    catch (const bad_alloc&)
    {
        throw;
    }
}

template<class T>
void List<T>::push_back(T&& value)
{
    try
    {
        Node<T>* newNode = new Node<T>(move(value));
        if (size == 0)
        {
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
        size++;
    }
    catch (const bad_alloc&)
    {
        throw;
    }
}

template<class T>
void List<T>::insert(const T& value, int index)
{
    if (index < 0 || index > size)
        throw out_of_range("index out of range");

    if (index == 0)
    {
        push_front(value);
    }
    else if (index == size)
    {
        push_back(value);
    }
    else
    {
        Node<T>* pos = getNode(index - 1);
        Node<T>* newNode = new Node<T>(value);
        newNode->next = pos->next;
        pos->next->prev = newNode;
        pos->next = newNode;
        newNode->prev = pos;
        size++;
    }
}

template<class T>
void List<T>::clear()
{
    Node<T>* temp = first;
    while (temp)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
    last = nullptr;
    size = 0;
}

template<class T>
void List<T>::print() const
{
    Node<T>* temp = first;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<class T>
void List<T>::pop_front()
{
    if (size == 0)
        return;

    Node<T>* temp = first->next;
    delete first;
    first = temp;
    size--;
    if (first)
        first->prev = nullptr;
    else
        last = nullptr;
}

template<class T>
void List<T>::pop_back()
{
    if (size == 0)
        return;

    if (size == 1)
    {
        delete first;
        first = last = nullptr;
        size = 0;
        return;
    }

    Node<T>* temp = last->prev;
    delete last;
    last = temp;
    last->next = nullptr;
    size--;
}

template<class T>
void List<T>::remove(int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("index out of range");

    if (index == 0)
        pop_front();
    else if (index == size - 1)
        pop_back();
    else
    {
        Node<T>* pos = getNode(index - 1);
        Node<T>* temp = pos->next;
        pos->next = temp->next;
        temp->next->prev = pos;
        delete temp;
        size--;
    }
}

template<class T>
T& List<T>::front()
{
    if (size == 0)
        return nullptr;
    return first->value;
}

template<class T>
T& List<T>::back()
{
    if (size == 0)
        return nullptr;
    return last->value;
}

template<class T>
T& List<T>::at(int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("index out of range");
    return getNode(index)->value;
}

template<class T>
T& List<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw out_of_range("index out of range");
    return getNode(index)->value;
}

template<class T>
void List<T>::for_each(void(*method)(T& value))
{
    Node<T>* temp = first;
    while (temp)
    {
        method(temp->value);
        temp = temp->next;
    }
}

template<class T>
List<T> List<T>::splice(int index1, int index2)
{
    if (index1 < 0 || index2 >= size || index1 > index2)
        throw out_of_range("invalid range");

    List<T> result;
    for (int i = index1; i <= index2; i++)
        result.push_back(this->at(i));
    return result;
}