#pragma once

#include "fullstd.h" 

/// функция для копирования строки
char* mystrcpy(const char* src) {
    size_t len = strlen(src) + 1;
    char* dest = new char[len];
    strcpy_s(dest, len, src);
    return dest;
}

class Student_New {
private:
    char* pib = nullptr;
    char* birthDate = nullptr;
    char* phone = nullptr;
    char* city = nullptr;
    char* country = nullptr;
    char* university = nullptr;
    char* univCity = nullptr;
    char* univCountry = nullptr;
    int groupNumber = 0;

public:
    // Сеттеры
    void setPIB(const char* s) { delete[] pib; pib = mystrcpy(s); }
    void setBirthDate(const char* s) { delete[] birthDate; birthDate = mystrcpy(s); }
    void setPhone(const char* s) { delete[] phone; phone = mystrcpy(s); }
    void setCity(const char* s) { delete[] city; city = mystrcpy(s); }
    void setCountry(const char* s) { delete[] country; country = mystrcpy(s); }
    void setUniversity(const char* s) { delete[] university; university = mystrcpy(s); }
    void setUnivCity(const char* s) { delete[] univCity; univCity = mystrcpy(s); }
    void setUnivCountry(const char* s) { delete[] univCountry; univCountry = mystrcpy(s); }
    void setGroupNumber(int num) { groupNumber = num; }

    // Геттеры
    const char* getPIB() { return pib; }
    const char* getBirthDate() { return birthDate; }
    const char* getPhone() { return phone; }
    const char* getCity() { return city; }
    const char* getCountry() { return country; }
    const char* getUniversity() { return university; }
    const char* getUnivCity() { return univCity; }
    const char* getUnivCountry() { return univCountry; }
    int getGroupNumber() { return groupNumber; }

    // Ввод
    void input() {
        char buffer[200];

        cout << "Введіть ПІБ: ";
        cin.getline(buffer, 200); setPIB(buffer);

        cout << "Введіть дату народження: ";
        cin.getline(buffer, 200); setBirthDate(buffer);

        cout << "Введіть телефон: ";
        cin.getline(buffer, 200); setPhone(buffer);

        cout << "Введіть місто проживання: ";
        cin.getline(buffer, 200); setCity(buffer);

        cout << "Введіть країну проживання: ";
        cin.getline(buffer, 200); setCountry(buffer);

        cout << "Введіть навчальний заклад: ";
        cin.getline(buffer, 200); setUniversity(buffer);

        cout << "Введіть місто навчального закладу: ";
        cin.getline(buffer, 200); setUnivCity(buffer);

        cout << "Введіть країну навчального закладу: ";
        cin.getline(buffer, 200); setUnivCountry(buffer);

        cout << "Введіть номер групи: ";
        cin >> groupNumber;
        cin.ignore();
    }

    // Вывод 
    void print() {
        cout << "ПІБ: " << (pib ? pib : "") << endl;
        cout << "Дата народження: " << (birthDate ? birthDate : "") << endl;
        cout << "Телефон: " << (phone ? phone : "") << endl;
        cout << "Місто: " << (city ? city : "") << endl;
        cout << "Країна: " << (country ? country : "") << endl;
        cout << "Університет: " << (university ? university : "") << endl;
        cout << "Місто університету: " << (univCity ? univCity : "") << endl;
        cout << "Країна університету: " << (univCountry ? univCountry : "") << endl;
        cout << "Номер групи: " << groupNumber << endl;
    }

    // Деструктор
    ~Student_New() {
        delete[] pib;
        delete[] birthDate;
        delete[] phone;
        delete[] city;
        delete[] country;
        delete[] university;
        delete[] univCity;
        delete[] univCountry;
    }
};

