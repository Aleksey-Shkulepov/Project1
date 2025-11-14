#pragma once

#include "mystd.h"

namespace hw26_10_25 {

	class Shape
	{
		String type;
		float x, y;

	public:
		Shape(String type, float x, float y) : type(type), x(x), y(y) {}
		virtual ~Shape() {}
		virtual float area() = 0;
		virtual void info()
		{
			cout << "Type : " << type << ", (" << x << ", " << y << ")" << endl;
		}
	};
}