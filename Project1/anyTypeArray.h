#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

// Базовый абстрактный класс для хранения значений разных типов
class BaseValue {
public:
    virtual void print() const = 0;
    virtual ~BaseValue() = default;
};

// Шаблонный класс-обертка для хранения значения любого типа
template<typename T>
class Value : public BaseValue {
    T data;
public:
    explicit Value(const T& val) : data(val) {}

    void print() const override {
        std::cout << data << std::endl;
    }

    T get() const {
        return data;
    }
};

// Контейнер для хранения объектов любого типа
class AnyTypeList {
    std::vector<std::shared_ptr<BaseValue>> items;

public:
    AnyTypeList() = default;

    // Добавление нового элемента любого типа
    template<typename T>
    void add(const T& val) {
        items.push_back(std::make_shared<Value<T>>(val));
    }

    // Удаление последнего элемента
    void deleteLast() {
        if (!items.empty())
            items.pop_back();
    }

    // Очистка списка
    void clear() {
        items.clear();
    }

    bool empty() const {
        return items.empty();
    }

    size_t size() const {
        return items.size();
    }

    void erase(size_t index) {
        if (index >= items.size())
            throw std::out_of_range("Index out of range");
        items.erase(items.begin() + index);
    }

    std::shared_ptr<BaseValue> at(size_t index) const {
        if (index >= items.size())
            throw std::out_of_range("Index out of range");
        return items[index];
    }

    // Оператор []
    std::shared_ptr<BaseValue> operator[](size_t index) const {
        return items.at(index);
    }

    // Шаблонный метод для получения значения конкретного типа
    template<typename T>
    T get(size_t index) const {
        auto ptr = std::dynamic_pointer_cast<Value<T>>(items.at(index));
        if (!ptr)
            throw std::bad_cast();
        return ptr->get();
    }

    // Печать всех элементов
    void printAll() const {
        for (const auto& item : items)
            item->print();
    }
};