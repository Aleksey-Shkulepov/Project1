#pragma once

#include "Shape.h"

namespace hw26_10_25 {

	class Circle : public Shape
	{
		float radius;

	public:
		Circle(float x, float y, float radius) : radius(radius), Shape("Circle", x, y) {}
		virtual float area() override
		{
			return 3.1415192 * radius * radius;
		}

		virtual void info() override
		{
			Shape::info();
			cout << "Radius : " << radius << endl;
		}
	};

}