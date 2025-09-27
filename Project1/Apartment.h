#pragma once

#include "SOSL.h"

#include "Human.h"

namespace hw17_09_25 {

	class Apartment {
	private:
		Human* owners;
		unsigned int owners_size;
		int number;
		float square;
	public:
		Apartment(Human* o, unsigned int o_s, int n, float s)
			: owners_size(o_s), number(n), square(s) 
		{
			owners = new Human[owners_size];
			for (size_t i = 0; i < owners_size; i++)
				owners[i] = o[i];
		}

		Apartment() : owners(nullptr), owners_size(0), number(0), square(0) {}

		Apartment(const Apartment& obj) {
			this->number = obj.number;
			this->square = obj.square;
			this->owners_size = obj.owners_size;

			this->owners = new Human[this->owners_size];
			for (size_t i = 0; i < owners_size; i++)
			{
				owners[i] = Human(obj.owners[i]);
			}
		}

		~Apartment() { delete[] owners; }

		void setOwners(Human* o, unsigned int o_s) { 
			delete[] owners; 
			owners_size = o_s;
			owners = new Human[owners_size];
			for (size_t i = 0; i < owners_size; i++)
				owners[i] = o[i];
		}
		void setNumber(int n) { number = n; }
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
			for (int i = 0; i < owners_size; ++i) { 
				cout << "Owner " << i + 1 << endl;
				owners[i].print();
			}
			cout << "Номер: " << number << ", площадь" << square << "\n";
		}
	};

}