#pragma once

#include "SOSL.h"

#include "Date.h"

class Human {
private:
	char* name;
	Date birthDay;
public:
	Human(char* n, Date bD)
		: name(n), birthDay(bD) {
	}

	Human() : name(nullptr), birthDay() {}

	~Human() { delete[] name; }

	void setName(const char* n) { strcpy_s(name, strlen(n), n); }
	void setBirthDay(Date bD) { birthDay = bD; }

	char* getName()     const { return name; }
	Date  getBirthDay() const { return birthDay; }

	void save(ofstream& out) const {
		birthDay.save(out);
		unsigned short len = strlen(name) + 1;
		out.write((char*)&len, sizeof len);
		out.write(name, len);
	}
	void load(ifstream& in) {
		birthDay.load(in);
		unsigned short len;
		in.read((char*)&len, sizeof len);
		name = new char[len];
		in.read(name, len);
	}
	void print() const {
		cout << name << '\n';
		birthDay.print();
	}
};

