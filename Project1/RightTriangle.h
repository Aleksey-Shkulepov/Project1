#pragma once

#include "Shape.h"

namespace hw26_10_25 {

    class RightTriangle : public Shape {
        float base, height;

    public:
        RightTriangle(float x, float y, float b, float h) : Shape("RightTriangle", x, y), base(b), height(h) {}
        float area() override {
            return 0.5f * base * height;
        }
        void info() override {
            Shape::info();
            cout << "Base: " << base << ", Height: " << height << endl;
        }
    };

}