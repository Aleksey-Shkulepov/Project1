#pragma once

#include "fullstd.h" 

class Contact {
private:
    char* name;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* extraInfo;

public:
    // Конструктор з параметрами
    Contact(const char* n, const char* h, const char* w, const char* m, const char* e)
        : name(nullptr), homePhone(nullptr), workPhone(nullptr), mobilePhone(nullptr), extraInfo(nullptr)
    {
        setName(n);
        setHomePhone(h);
        setWorkPhone(w);
        setMobilePhone(m);
        setExtraInfo(e);
    }

    // Конструктор пол умол.
    Contact() : name(nullptr), homePhone(nullptr), workPhone(nullptr),
        mobilePhone(nullptr), extraInfo(nullptr) {
    }

    // Деструктор
    ~Contact() {
        delete[] name;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] extraInfo;
    }

    // Сеттеры
    void setName(const char* n) {
        delete[] name;
        if (n) {
            size_t len = strlen(n) + 1;
            name = new char[len];
            strcpy_s(name, len, n);
        }
        else name = nullptr;
    }

    void setHomePhone(const char* h) {
        delete[] homePhone;
        if (h) {
            size_t len = strlen(h) + 1;
            homePhone = new char[len];
            strcpy_s(homePhone, len, h);
        }
        else homePhone = nullptr;
    }

    void setWorkPhone(const char* w) {
        delete[] workPhone;
        if (w) {
            size_t len = strlen(w) + 1;
            workPhone = new char[len];
            strcpy_s(workPhone, len, w);
        }
        else workPhone = nullptr;
    }

    void setMobilePhone(const char* m) {
        delete[] mobilePhone;
        if (m) {
            size_t len = strlen(m) + 1;
            mobilePhone = new char[len];
            strcpy_s(mobilePhone, len, m);
        }
        else mobilePhone = nullptr;
    }

    void setExtraInfo(const char* e) {
        delete[] extraInfo;
        if (e) {
            size_t len = strlen(e) + 1;
            extraInfo = new char[len];
            strcpy_s(extraInfo, len, e);
        }
        else extraInfo = nullptr;
    }

    // Геттери
    const char* getName() const { return name ? name : ""; }
    const char* getHomePhone() const { return homePhone ? homePhone : ""; }
    const char* getWorkPhone() const { return workPhone ? workPhone : ""; }
    const char* getMobilePhone() const { return mobilePhone ? mobilePhone : ""; }
    const char* getExtraInfo() const { return extraInfo ? extraInfo : ""; }

    // Вивід
    void print() const {
        cout << "ПІБ: " << getName() << endl;
        cout << "Домашній: " << getHomePhone() << endl;
        cout << "Робочий: " << getWorkPhone() << endl;
        cout << "Мобільний: " << getMobilePhone() << endl;
        cout << "Додаткова інформація: " << getExtraInfo() << endl;
        cout << "----------------------" << endl;
    }

    // Збереження в файл
    void save(ofstream& out) const {
        // обычная лямбда, пусть будет да?
        auto saveString = [&](const char* str) {
            size_t len = str ? strlen(str) : 0;
            out.write((char*)&len, sizeof(len));
            if (len > 0) out.write(str, len);
            };
        saveString(name);
        saveString(homePhone);
        saveString(workPhone);
        saveString(mobilePhone);
        saveString(extraInfo);
    }

    // Завантаження з файлу
    void load(ifstream& in) {
        // обычная лямбда, пусть будет да?
        auto loadString = [&](char*& str) {
            delete[] str;
            size_t len;
            in.read((char*)&len, sizeof(len));
            if (len > 0) {
                str = new char[len + 1];
                in.read(str, len);
                str[len] = '\0';
            }
            else {
                str = nullptr;
            }
            };
        loadString(name);
        loadString(homePhone);
        loadString(workPhone);
        loadString(mobilePhone);
        loadString(extraInfo);
    }
};
