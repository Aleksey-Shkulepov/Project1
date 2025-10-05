#pragma once

#include "fullstd.h"
#include "mystd.h"

namespace hw24_09_25 {

	class Airplane
	{
        String type;
        int passengers;
        int maxPassengers;
    public:
        Airplane() : passengers(0), maxPassengers(0), type(nullptr) {}
        Airplane(String t, int p, int m) : passengers(p), maxPassengers(m), type(t) {}

        bool operator==(const Airplane& other) const {
            return this->type == other.type;
        }

        Airplane& operator++() {
            if (passengers < maxPassengers) ++passengers;
            return *this;
        }

        Airplane& operator--() {
            if (passengers > 0) --passengers;
            return *this;
        }

        bool operator>(const Airplane& other) const {
            return maxPassengers > other.maxPassengers;
        }

        void print() const {
            cout << "Type: " << type << ", Passengers: " << passengers << "/" << maxPassengers << endl;
        }
	};

}