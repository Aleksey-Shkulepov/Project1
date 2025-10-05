#pragma once

#include "fullstd.h" 

/// ������� ��� ����������� ������
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
    // �������
    void setPIB(const char* s) { delete[] pib; pib = mystrcpy(s); }
    void setBirthDate(const char* s) { delete[] birthDate; birthDate = mystrcpy(s); }
    void setPhone(const char* s) { delete[] phone; phone = mystrcpy(s); }
    void setCity(const char* s) { delete[] city; city = mystrcpy(s); }
    void setCountry(const char* s) { delete[] country; country = mystrcpy(s); }
    void setUniversity(const char* s) { delete[] university; university = mystrcpy(s); }
    void setUnivCity(const char* s) { delete[] univCity; univCity = mystrcpy(s); }
    void setUnivCountry(const char* s) { delete[] univCountry; univCountry = mystrcpy(s); }
    void setGroupNumber(int num) { groupNumber = num; }

    // �������
    const char* getPIB() { return pib; }
    const char* getBirthDate() { return birthDate; }
    const char* getPhone() { return phone; }
    const char* getCity() { return city; }
    const char* getCountry() { return country; }
    const char* getUniversity() { return university; }
    const char* getUnivCity() { return univCity; }
    const char* getUnivCountry() { return univCountry; }
    int getGroupNumber() { return groupNumber; }

    // ����
    void input() {
        char buffer[200];

        cout << "������ ϲ�: ";
        cin.getline(buffer, 200); setPIB(buffer);

        cout << "������ ���� ����������: ";
        cin.getline(buffer, 200); setBirthDate(buffer);

        cout << "������ �������: ";
        cin.getline(buffer, 200); setPhone(buffer);

        cout << "������ ���� ����������: ";
        cin.getline(buffer, 200); setCity(buffer);

        cout << "������ ����� ����������: ";
        cin.getline(buffer, 200); setCountry(buffer);

        cout << "������ ���������� ������: ";
        cin.getline(buffer, 200); setUniversity(buffer);

        cout << "������ ���� ����������� �������: ";
        cin.getline(buffer, 200); setUnivCity(buffer);

        cout << "������ ����� ����������� �������: ";
        cin.getline(buffer, 200); setUnivCountry(buffer);

        cout << "������ ����� �����: ";
        cin >> groupNumber;
        cin.ignore();
    }

    // ����� 
    void print() {
        cout << "ϲ�: " << (pib ? pib : "") << endl;
        cout << "���� ����������: " << (birthDate ? birthDate : "") << endl;
        cout << "�������: " << (phone ? phone : "") << endl;
        cout << "̳���: " << (city ? city : "") << endl;
        cout << "�����: " << (country ? country : "") << endl;
        cout << "����������: " << (university ? university : "") << endl;
        cout << "̳��� �����������: " << (univCity ? univCity : "") << endl;
        cout << "����� �����������: " << (univCountry ? univCountry : "") << endl;
        cout << "����� �����: " << groupNumber << endl;
    }

    // ����������
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

