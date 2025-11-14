#pragma once

#include "Shape.h"

namespace hw26_10_25 {

    class Trapezoid : public Shape {
        float a, b, height;

    public:
        Trapezoid(float x, float y, float a, float b, float h) : Shape("Trapezoid", x, y), a(a), b(b), height(h) {}
        float area() override {
            return 0.5f * (a + b) * height;
        }
        void info() override {
            Shape::info();
            cout << "Side a: " << a << ", Side b: " << b << ", Height: " << height << endl;
        }
    };

}