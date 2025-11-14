#pragma once

#include "Shape.h"

namespace hw26_10_25 {

    class Rectangle : public Shape {
        float width, height;

    public:
        Rectangle(float x, float y, float w, float h) : Shape("Rectangle", x, y), width(w), height(h) {}
        float area() override {
            return width * height;
        }
        void info() override {
            Shape::info();
            cout << "Width: " << width << ", Height: " << height << endl;
        }
    };

}