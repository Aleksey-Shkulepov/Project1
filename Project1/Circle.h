#pragma once

#include "fullstd.h"

namespace hw24_09_25 {

	class Circle
	{
        double radius;
    public:
        Circle() : radius(0) {}
        Circle(double r) : radius(r) {}

        bool operator==(const Circle& other) const {
            return radius == other.radius;
        }

        bool operator>(const Circle& other) const { 
            return (radius) > (other.radius);
        } 

        Circle& operator+=(double value) {
            radius += value;
            return *this;
        }

        Circle& operator-=(double value) {
            radius -= value;
            if (radius < 0) radius = 0;
            return *this;
        }

        void print() const {
            cout << "Radius: " << radius << endl;
        }
	};

}