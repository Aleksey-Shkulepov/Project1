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

	Fraction operator+ (const Fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		Fraction fr;

		int common_denominator = _lcm(this->denominator, other.denominator);

		int multiplier1 = common_denominator / this->denominator;
		int multiplier2 = common_denominator / other.denominator;

		fr.numerator = this->numerator * multiplier1 + other.numerator * multiplier2;
		fr.denominator = common_denominator;

		fr._reduce();
		return fr;
	}

	Fraction operator- (const Fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		Fraction fr;

		int common_denominator = _lcm(this->denominator, other.denominator);

		int multiplier1 = common_denominator / this->denominator;
		int multiplier2 = common_denominator / other.denominator;

		fr.numerator = this->numerator * multiplier1 - other.numerator * multiplier2;
		fr.denominator = common_denominator;

		fr._reduce();
		return fr;
	}

	Fraction operator* (const Fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		Fraction fr;

		fr.numerator = this->numerator * other.numerator;
		fr.denominator = this->denominator * other.denominator;

		fr._reduce();
		return fr;
	}

	Fraction operator/ (const Fraction& other)
	{
		if (this->denominator == 0 || other.denominator == 0)
			throw exception("Знаменатель не может ровняться 0!");

		Fraction fr;

		fr.numerator = this->numerator * other.denominator;
		fr.denominator = this->denominator * other.numerator;

		fr._reduce();
		return fr;
	}

	friend ostream& operator<<(ostream& os, const Fraction& fr);
	friend istream& operator>>(istream& in, Fraction& obj);
};

ostream& operator<<(ostream& os, const Fraction& obj)
{
	os << obj.numerator << "/" << obj.denominator;
	return os;
}

istream& operator>>(istream& in, Fraction& obj)
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