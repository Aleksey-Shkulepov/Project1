#pragma once

#include "SOSL.h"

#include "Apartment.h"

namespace hw17_09_25 {

	class House {
	private:
		Apartment* apartments;
		unsigned int apartments_size;
	public:
		House(Apartment* a, unsigned int a_s)
			: apartments_size(a_s) 
		{
			apartments = new Apartment[apartments_size];
			for (size_t i = 0; i < apartments_size; i++)
				apartments[i] = a[i];
		}

		House() : apartments(nullptr), apartments_size(0) {}

		House(const House& obj) {
			this->apartments_size = obj.apartments_size;

			this->apartments = new Apartment[this->apartments_size];
			for (size_t i = 0; i < apartments_size; i++)
			{
				apartments[i] = obj.apartments[i];
			}
		}

		~House() { delete[] apartments; }

		void setApartments(Apartment* a, unsigned int a_s)
		{
			delete[] apartments;
			apartments_size = a_s;
			apartments = new Apartment[apartments_size];
			for (size_t i = 0; i < apartments_size; i++)
				apartments[i] = a[i];
		}

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
			for (int i = 0; i < apartments_size; ++i) {
				cout << "Apartment " << i + 1 << endl;
				apartments[i].print();
			}
		}
	};

}