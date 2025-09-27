#pragma once

#include "SOSL.h"

#include "Human.h"

class Apartment {
private:
	Human* owners;
	unsigned int owners_size;
	int number;
	float square;
public:
	Apartment(Human* o, unsigned int o_s, int n, float s)
		: owners(o), owners_size(o_s), number(n), square(s) {}

	Apartment() : owners(nullptr), owners_size(0), number(0), square(0) {}

	~Apartment() { delete[] owners; }

	void setOwners(Human* o, unsigned int o_s) { owners = o; owners_size = o_s; }
	void setNumber(int n)   { number = n; }
	void setSquare(float s) { square = s; }

	Human* getOwners() const { return owners; }
	int    getNumber() const { return number; }
	float  getSquare() const { return square; }

	void save(ofstream& out) const {
		out.write((char*)this, sizeof Apartment);
		for (int i = 0; i < owners_size; ++i) owners[i].save(out);
	}
	void load(ifstream& in) {
		in.read((char*)this, sizeof Apartment);
		owners = new Human[owners_size];
		for (int i = 0; i < owners_size; ++i) owners[i].load(in);
	}
	void print() const {
		for (int i = 0; i < owners_size; ++i) owners[i].print();
		cout << "Номер: " << number << ", площадь" << square << "\n";
	}
};

