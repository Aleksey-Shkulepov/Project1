#pragma once

#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdio>

#include "MyFunctions.h"
#include "mylibrary.h"
#include "myVector.h"
#include "myStructures.h"
#include "mylist.h"
#include "anyTypeArray.h"
#include "Bank.h"

using namespace std;

class PointNew {
	int x, y, z;

public:
	PointNew() : x(0), y(0), z(0) {}
	PointNew(int x) : x(x), y(0), z(0) {}
	PointNew(int x, int y) : x(x), y(y), z(0) {}
	PointNew(int x, int y, int z) : x(x), y(y), z(z) {}

	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return z; }

	void save(ofstream& out) const {
		out.write((char*)this, sizeof(PointNew));
	}

	void load(ifstream& in) {
		in.read((char*)this, sizeof(PointNew));
	}

	friend ostream& operator<<(ostream& os, const PointNew& p) {
		os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
		return os;
	}

	friend istream& operator>>(istream& in, PointNew& obj) {
		in >> obj.x >> obj.y >> obj.z;
		return in;
	}
};

//ostream& operator<<(ostream& os, const PointNew& obj)
//{
//	os << obj.x << "," << obj.y << "," << obj.z;
//	return os;
//}
//
//istream& operator>>(istream& in, PointNew& obj)
//{
//	char twoPoints;
//
//	in >> obj.x;
//	in >> twoPoints;
//
//	if (twoPoints != ';') {
//		in.setstate(ios::failbit);
//		return in;
//	}
//
//	in >> obj.y;
//	in >> twoPoints;
//
//	if (twoPoints != ';') {
//		in.setstate(ios::failbit);
//		return in;
//	}
//
//	in >> obj.z;
//	in >> twoPoints;
//
//	if (twoPoints != ';') {
//		in.setstate(ios::failbit);
//		return in;
//	}
//	return in;
//}

class Student
{
private:
	int id;
	char* name = nullptr;
	int age = 0;

public:



	void print()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	void setAge(int a)
	{
		if (a > 0 && a < 100)
			age = a;
	}

	int getAge()
	{
		return age;
	}

	void setName(const char* n)
	{
		size_t len = mylenstr(n) + 1;
		name = new char[len];
		strcpy_s(name, len, n);
	}

	char* getName()
	{
		return name;
	}
};

/// �� ����� ����� ���� 03.09.2025 ������

/// ������� ��� ����������� ������
char* mystrcpy(const char* src) {
    size_t len = mylenstr(src) + 1;
    char* dest = new char[len];
    strcpy_s(dest, len, src);
    return dest;
}

/// <summary>
/// ������
/// </summary>
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

/// <summary>
/// ����� ����� 2
/// </summary>
class new_PointNew {
    int x, y, z;

public:
    new_PointNew() : x(0), y(0), z(0) {}
    new_PointNew(int x) : x(x), y(0), z(0) {}
    new_PointNew(int x, int y) : x(x), y(y), z(0) {}
    new_PointNew(int x, int y, int z) : x(x), y(y), z(z) {}

    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }

    void save(ofstream& out) const {
        out.write((char*)this, sizeof(new_PointNew));
    }

    void load(ifstream& in) {
        in.read((char*)this, sizeof(new_PointNew));
    }

    friend ostream& operator<<(ostream& os, const new_PointNew& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }

    friend istream& operator>>(istream& in, new_PointNew& obj) {
        in >> obj.x >> obj.y >> obj.z;
        return in;
    }
};

/// �� ����� ����� ���� 06.09.2025 "ĸ����������"

class Contact {
private:
    char* name;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* extraInfo;

public:
    // ����������� � �����������
    Contact(const char* n, const char* h, const char* w, const char* m, const char* e)
        : name(nullptr), homePhone(nullptr), workPhone(nullptr), mobilePhone(nullptr), extraInfo(nullptr)
    {
        setName(n);
        setHomePhone(h);
        setWorkPhone(w);
        setMobilePhone(m);
        setExtraInfo(e);
    }

    // ����������� ��� ����.
    Contact() : name(nullptr), homePhone(nullptr), workPhone(nullptr),
        mobilePhone(nullptr), extraInfo(nullptr) {
    }

    // ����������
    ~Contact() {
        delete[] name;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] extraInfo;
    }

    // �������
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

    // �������
    const char* getName() const { return name ? name : ""; }
    const char* getHomePhone() const { return homePhone ? homePhone : ""; }
    const char* getWorkPhone() const { return workPhone ? workPhone : ""; }
    const char* getMobilePhone() const { return mobilePhone ? mobilePhone : ""; }
    const char* getExtraInfo() const { return extraInfo ? extraInfo : ""; }

    // ����
    void print() const {
        cout << "ϲ�: " << getName() << endl;
        cout << "�������: " << getHomePhone() << endl;
        cout << "�������: " << getWorkPhone() << endl;
        cout << "��������: " << getMobilePhone() << endl;
        cout << "��������� ����������: " << getExtraInfo() << endl;
        cout << "----------------------" << endl;
    }

    // ���������� � ����
    void save(ofstream& out) const {
        // ������� ������, ����� ����� ��?
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

    // ������������ � �����
    void load(ifstream& in) {
        // ������� ������, ����� ����� ��?
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


/// PhoneBook
class PhoneBook {
private:
    Contact* contacts;
    int size;

public:
    PhoneBook() : contacts(nullptr), size(0) {}

    // �������� ��������
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

    // ������� �������� �� �������
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

    // ����� �� ϲ�
    int findByName(const char* name) {
        for (int i = 0; i < size; i++) {
            if (strcmp(contacts[i].getName(), name) == 0) return i;
        }
        return -1;
    }

    // �������� ����
    void showAll() {
        if (size == 0) {
            cout << "��������� ����� �����\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "=== ������� " << i + 1 << " ===\n";
            contacts[i].print();
            cout << endl;
        }
    }

    // ��������� � ����
    void saveToFile(const char* filename) {
        ofstream fout(filename, ios::binary);
        fout.write((char*)&size, sizeof(size));
        for (int i = 0; i < size; i++) {
            contacts[i].save(fout);
        }
        fout.close();
    }

    // ��������� �� �����
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

    // ����������
    ~PhoneBook() {
        delete[] contacts;
    }
};