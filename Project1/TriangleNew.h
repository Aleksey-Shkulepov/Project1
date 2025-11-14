#pragma once

#include "Shape.h"

namespace hw26_10_25 {

    class Triangle : public Shape {
        float a, b, c;

    public:
        Triangle(float x, float y, float a, float b, float c) : Shape("Triangle", x, y), a(a), b(b), c(c) {}

        float area() override {
            float s = (a + b + c) / 2.0f;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }

        void info() override {
            Shape::info();
            cout << "Sides: a=" << a << ", b=" << b << ", c=" << c << endl;
        }
    };

}