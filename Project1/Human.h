#pragma once

#include "fullstd.h"

#include "Date.h"

namespace hw17_09_25 {

	class Human {
	private:
		char* name;
		Date birthDay;
	public:
		Human(const char* n, Date bD) : birthDay(bD)
		{
			unsigned int s = strlen(n);
			name = new char[s + 1];
			strcpy_s(name, s + 1, n);
		}

		Human() : name(nullptr), birthDay() {}

		Human(const Human& obj) {
			if (obj.name) {
				unsigned int s = strlen(obj.name);
				name = new char[s + 1];
				strcpy_s(name, s + 1, obj.name);
			}
			else {
				name = nullptr;
			}
			this->birthDay = obj.birthDay;
		}

		Human& operator=(const Human& obj) {
			if (this == &obj) return *this;
			delete[] name;
			if (obj.name) {
				unsigned int s = strlen(obj.name);
				name = new char[s + 1];
				strcpy_s(name, s + 1, obj.name);
			}
			else {
				name = nullptr;
			}
			birthDay = obj.birthDay;
			return *this;
		}

		~Human() { delete[] name; name = nullptr; }

		void setName(const char* n) { 
			delete[] name;
			unsigned int s = strlen(n);
			name = new char[s + 1];
			strcpy_s(name, s + 1, n);
		}
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
			delete[] name;
			name = new char[len];
			in.read(name, len);
		}
		void print() const {
			cout << name << '\n';
			birthDay.print();
		}
	};

}