#pragma once

#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdio>

#include "MyFunctions.h"
#include "mylibrary.h"
#include "myVector.h"
#include "myStructures.h"
#include "mylist.h"
#include "anyTypeArray.h"
#include "Bank.h"
#include "String.h"

using namespace std;

class Reservoir
{
	String name;
	ReservoirType reservoirType;
	
	long double width;
	long double length;
	long double MAX_depth;

public:
	Reservoir() : name(nullptr), width(0), length(0), MAX_depth(0), reservoirType(ReservoirType::NOTYPE){};
	Reservoir(String name) : name(name), width(0), length(0), MAX_depth(0), reservoirType(ReservoirType::NOTYPE) {};
	Reservoir(String name, double width, double length, double MAX_depth, ReservoirType reservoirType)
		: name(name), width(width), length(length), MAX_depth(MAX_depth), reservoirType(reservoirType) {};
	//Reservoir(const String& other); На будущее

	long double get_approximate_size() const{ return width * length * MAX_depth; };
	long double get_square() const { return width * length;  };
	bool is_type_the_same(Reservoir res2);
	bool is_square_the_same(Reservoir res2);

	String get_name() const { return name; }
	ReservoirType get_reservoirType() const { return reservoirType; }

	long double get_width() const { return width; }
	long double get_length() const { return length; }
	long double get_MAX_depth() const { return MAX_depth; }

	void set_name(String name) { this->name = name; }
	void set_reservoirType(ReservoirType reservoirType) { this->reservoirType = reservoirType; }

	void set_width(double width) { this->width = width; }
	void set_length(double length) { this->length = length; }
	void set_MAX_depth(double MAX_depth) { this->MAX_depth = MAX_depth; }

	void print() const {
		cout << this;
	}

	friend ostream& operator<<(ostream& os, const Reservoir& rv);
};

ostream& operator<<(ostream& os, const Reservoir& rv) {
	os << "name: " << rv.name 
	<< "ReservoirType: " << getReservoirTypeName(rv.reservoirType)
	<< "width: " << rv.width
	<< "length: " << rv.length
	<< "MAX_depth: " << rv.MAX_depth;
	return os;
}

bool Reservoir::is_type_the_same(Reservoir res2) {
	return this->reservoirType == res2.reservoirType;
}

bool Reservoir::is_square_the_same(Reservoir res2) {
	if (is_type_the_same(res2)) return false;
	return this->get_square() == res2.get_square();
}


enum class ReservoirType
{
	OCEAN,
	SEA,
	RIVER,
	LAKE,
	POND,
	PUDDLE,
	NOTYPE = -1
};


const char* getReservoirTypeName(ReservoirType type)
{
	switch (type)
	{
	case ReservoirType::OCEAN:  return "OCEAN";  break;
	case ReservoirType::SEA:    return "SEA";    break;
	case ReservoirType::RIVER:  return "RIVER";  break;
	case ReservoirType::LAKE:   return "LAKE";   break;
	case ReservoirType::POND:   return "POND";   break;
	case ReservoirType::PUDDLE: return "PUDDLE"; break;
	}
}