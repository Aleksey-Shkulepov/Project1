#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

template<typename T>
class Value;

class BaseValue {
public:
    virtual void print() const = 0;
    virtual ~BaseValue() = default;
};

template<typename T>
class Value : public BaseValue {
    T data;
public:
    Value(const T& val) : data(val) {}

    void print() const override {
        std::cout << data << std::endl;
    }

    T get() const {
        return data;
    }
};

class AnyTypeList {
    std::vector<std::shared_ptr<BaseValue>> items;

public:
    AnyTypeList() = default;

    template<typename T>
    void add(const T& val) {
        items.push_back(std::make_shared<Value<T>>(val));
    }

    void deleteLast() {
        if (!items.empty())
            items.pop_back();
    }

    void clear() {
        items.clear();
    }

    bool empty() const {
        return items.empty();
    }

    size_t size() const {
        return items.size();
    }

    void insert(size_t index) {
        if (index < items.size())
            items.erase(items.begin() + index);
    }

    std::shared_ptr<BaseValue> at(size_t index) const {
        if (index >= items.size())
            throw std::out_of_range("Index out of range");
        return items[index];
    }

    std::shared_ptr<BaseValue> operator[](size_t index) const {
        return items[index];
    }

    template<typename T>
    T get(size_t index) const {
        auto ptr = std::dynamic_pointer_cast<Value<T>>(items.at(index));
        if (!ptr)
            throw std::bad_cast();
        return ptr->get();
    }

    void printAll() const {
        for (const auto& item : items)
            item->print();
    }
};