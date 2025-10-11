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
#include "myStructures.h"
#include "anyTypeArray.h"
#include "Bank.h"

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	int _gcd(int a, int b)
	{
		while (b != 0) {
			int t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	int _lcm(int a, int b)
	{
		return (a * b) / _gcd(a, b);
	}

	void _reduce() {
		int g = _gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
	}

	fraction operator+ (const fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		fraction fr;

		int common_denominator = _lcm(this->denominator, other.denominator);

		int multiplier1 = common_denominator / this->denominator;
		int multiplier2 = common_denominator / other.denominator;

		fr.numerator = this->numerator * multiplier1 + other.numerator * multiplier2;
		fr.denominator = common_denominator;

		fr._reduce();
		return fr;
	}

	fraction operator- (const fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		fraction fr;

		int common_denominator = _lcm(this->denominator, other.denominator);

		int multiplier1 = common_denominator / this->denominator;
		int multiplier2 = common_denominator / other.denominator;

		fr.numerator = this->numerator * multiplier1 - other.numerator * multiplier2;
		fr.denominator = common_denominator;

		fr._reduce();
		return fr;
	}

	fraction operator* (const fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		fraction fr;

		fr.numerator = this->numerator * other.numerator;
		fr.denominator = this->denominator * other.denominator;

		fr._reduce();
		return fr;
	}

	fraction operator/ (const fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		fraction fr;

		fr.numerator = this->numerator * other.denominator;
		fr.denominator = this->denominator * other.numerator;

		fr._reduce();
		return fr;
	}

	friend ostream& operator<<(ostream& os, const fraction& fr);
	friend istream& operator>>(istream& in, fraction& obj);
};

ostream& operator<<(ostream& os, const fraction& obj)
{
	os << obj.numerator << "/" << obj.denominator;
	return os;
}

istream& operator>>(istream& in, fraction& obj)
{
	char slash;

	in >> obj.numerator;
	in >> slash;

	if (slash != '/') {
		in.setstate(ios::failbit);
		return in;
	}

	in >> obj.denominator;
	return in;
}