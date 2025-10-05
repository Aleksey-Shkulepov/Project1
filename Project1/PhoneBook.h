#pragma once

#include "fullstd.h"

#include"Contact.h"

/// PhoneBook
class PhoneBook {
private:
    Contact* contacts;
    int size;

public:
    PhoneBook() : contacts(nullptr), size(0) {}

    // Добавить абонента
    void addContact(const Contact& c) {
        Contact* newArr = new Contact[size + 1];
        for (int i = 0; i < size; i++) {
            newArr[i] = contacts[i];
        }
        newArr[size] = c;
        delete[] contacts;
        contacts = newArr;
        size++;
    }

    // Удалить абонента по индексу
    void removeContact(int index) {
        if (index < 0 || index >= size) return;

        Contact* newArr = new Contact[size - 1];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (i == index) continue;
            newArr[j++] = contacts[i];
        }
        delete[] contacts;
        contacts = newArr;
        size--;
    }

    // Поиск по ПІБ
    int findByName(const char* name) {
        for (int i = 0; i < size; i++) {
            if (strcmp(contacts[i].getName(), name) == 0) return i;
        }
        return -1;
    }

    // Показать всех
    void showAll() {
        if (size == 0) {
            cout << "Телефонна книга пуста\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "=== Абонент " << i + 1 << " ===\n";
            contacts[i].print();
            cout << endl;
        }
    }

    // Сохранить в файл
    void saveToFile(const char* filename) {
        ofstream fout(filename, ios::binary);
        fout.write((char*)&size, sizeof(size));
        for (int i = 0; i < size; i++) {
            contacts[i].save(fout);
        }
        fout.close();
    }

    // Загрузить из файла
    void loadFromFile(const char* filename) {
        ifstream fin(filename, ios::binary);
        if (!fin.is_open()) return;

        delete[] contacts;
        fin.read((char*)&size, sizeof(size));
        contacts = new Contact[size];
        for (int i = 0; i < size; i++) {
            contacts[i].load(fin);
        }
        fin.close();
    }

    // Деструктор
    ~PhoneBook() {
        delete[] contacts;
    }
};

