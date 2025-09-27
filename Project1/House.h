#pragma once

#include "SOSL.h"

#include "Apartment.h"

class House {
private:
	Apartment* apartments;
	unsigned int apartments_size;
public:
	House(Apartment* a, unsigned int a_s)
		: apartments(a), apartments_size(a_s) {}

	House() : apartments(nullptr), apartments_size(0) {}

	~House() { delete[] apartments; }

	void setApartments(Apartment* a, unsigned int a_s) 
		{ apartments = a; apartments_size = a_s; }

	Apartment* getApartments() const { return apartments; }

	void save(ofstream& out) const {
		out.write((char*)&apartments_size, sizeof apartments_size);
		for (int i = 0; i < apartments_size; ++i) apartments[i].save(out);
	}
	void load(ifstream& in) {
		in.read((char*)&apartments_size, sizeof apartments_size);
		apartments = new Apartment[apartments_size];
		for (int i = 0; i < apartments_size; ++i) apartments[i].load(in);
	}
	void print() const {
		for (int i = 0; i < apartments_size; ++i) apartments[i].print();
	}
};

