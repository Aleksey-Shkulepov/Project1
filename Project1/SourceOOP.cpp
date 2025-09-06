#define _CRT_SECURE_NO_WARNINGS

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
	PointNew() : x(0), y(0), z(0) { }
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

int main()
{
	//ofstream out("PointNew.txt");
	//ifstream in("PointNew.txt");
	//PointNew p(1, 2, 3);
	//cout << p.getX() << endl;
	//cout << p << endl;
	//cin >> p;
	//cout << p << endl;
	//p.save(out);
	//p.load(in);
	//cout << "load - " << p << endl;

	//Student st;
	//st.setName("lalala");
	//st.print();
}