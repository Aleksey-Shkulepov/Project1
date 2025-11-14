#pragma once

#include "FileManager.h"

#include "ASCIIFileManager.h"
#include "BinaryFileManager.h"

#include "Employer.h"

#include "Manager.h"
#include "President.h"
#include "WorkerNew.h"

#include "Shape.h"

#include "CircleNew.h"
#include "Rectangle.h"
#include "RightTriangle.h"
#include "Trapezoid.h"
#include "TriangleNew.h"

namespace hw26_10_25 {

	void main() {
		List<Employer*> listEmployers = { new Manager("Vasya", 10), new President("Misha", "Ukraine"), new Worker("Danya", "Uborshik")};

		for (auto& e : listEmployers)
			e->Print();

		List<Shape*> listShapes = {new Circle(0, 0, 5), new Rectangle(1, 2, 3, 4), new RightTriangle(2, 3, 3, 4), new Trapezoid(0, 0, 3, 5, 2), new Triangle(0 ,0, 3, 4 ,5) };
		
		for (auto& s : listShapes)
			{ s->info(); cout << "Area: " << s->area() << endl; }

		List<FileManager*> listFileManagers = { new FileManager, new ASCIIFileManager, new BinaryFileManager};

		for (auto& fm : listFileManagers)
			fm->Display("Concepts.h");
	}

}