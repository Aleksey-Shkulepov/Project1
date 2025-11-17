#pragma once

#include "String.h"

struct Train {
    int number;
    DateTime departureTime;
    String destination;

    friend ostream& operator<<(ostream& os, const Train& fr);
    friend istream& operator>>(istream& in, Train& obj);
};

ostream& operator<<(ostream& os, const Train& obj)
{
	os 
	<< "Number: "		 << obj.number << endl 
	<< "DepartureTime: " << obj.departureTime << endl
	<< "Destination: "   << obj.destination << endl;
	return os;
}

istream& operator>>(istream& in, Train& obj)
{
	cout << "Number(int): "; in >> obj.number; cin.ignore();
	cout << "DepartureTime(DateTime): " << endl; in >> obj.departureTime; cin.ignore();
	cout << "Destination(String): "; in >> obj.destination;

	return in;
}