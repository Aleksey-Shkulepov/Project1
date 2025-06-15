#pragma once

///15.06.25-18.06.25 h/w



struct fraction 
{
	int numerator;
	int denominator;

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


enum TransmissionType {
	MANUAL,
	AUTOMATIC,
	ROBOTIC,
	CVT
};

const char* getTransmissionName(TransmissionType type) {
	switch (type) {
	case MANUAL: return "Механика";
	case AUTOMATIC: return "Автомат";
	case ROBOTIC: return "Роботизированая";
	case CVT: return "Вариатор";
	default: return "Такого типа коробки передач не существует";
	}
}

struct Car
{
	float length;
	float clearance;
	float engineVolume;
	int enginePower;
	float wheelDiameter;
	char color[30];
	TransmissionType transmission;

	void set(float l, float c, float ev, int ep, float wd, const char* clr, TransmissionType tr) {
		length = l;
		clearance = c;
		engineVolume = ev;
		enginePower = ep;
		wheelDiameter = wd;
		strcpy(color, clr);
		transmission = tr;
	}

	friend ostream& operator<<(ostream& os, const Car& fr);
};

Car searchByColor(Car* cars, size_t size, const char* targetColor) {
	for (size_t i = 0; i < size; i++)
		if (strcmp(cars[i].color, targetColor) == 0) 
			return cars[i];
}

ostream& operator<<(ostream& os, const Car& obj)
{
	os << "Длина: " << obj.length << endl;
	os << "Клиренс: " << obj.clearance << endl;
	os << "Обьем двигателя: " << obj.engineVolume << endl;
	os << "Мощность двигателя: " << obj.enginePower << endl;
	os << "Диаметр колес: " << obj.wheelDiameter << endl;
	os << "Цвет: " << obj.color << endl;
	os << "Коробка передач: " << getTransmissionName(obj.transmission) << endl;
	return os;
}

///14.06.25 lesson

struct Point
{
	int x, y;
	char name;

	void print()
	{
		cout << name << "(" << x << ", " << y << ")" << endl;
	}
};

double len2Point(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

struct Date
{
	int day;
	int month;
	int year;

	void print()
	{
		if (day < 10)
			cout << 0;
		cout << day << ".";
		if (month < 10)
			cout << 0;
		cout << month << "." << year << endl;
	}


	char* to_string()
	{
		char* str = new char[11];
		str[0] = day / 10 + 48;
		str[1] = day % 10 + 48;
		str[2] = '.';
		str[3] = month / 10 + 48;
		str[4] = month % 10 + 48;
		str[5] = '.';
		str[6] = year / 1000 + 48;
		str[7] = year / 100 % 10 + 48;
		str[8] = year / 10 % 10 + 48;
		str[9] = year % 10 + 48;
		str[10] = '\0';
		return str;
	}
};

struct Human
{
	char* name;
	Date birthDay;
};

///12.06.25-15.06.25 My first structure

struct Abonent
{
    char* name = nullptr;
    unsigned long long phone = 0;
};

Abonent* searchByName(Abonent* user, size_t size, const char* name) {
    for (size_t i = 0; i < size; i++)
        if (strcmp(user[i].name, name) == 0)
            return &user[i];
    return nullptr;
}

Abonent* searchByPhone(Abonent* user, size_t size, unsigned long long phone) {
    for (size_t i = 0; i < size; i++)
        if (user[i].phone == phone)
            return &user[i];
    return nullptr;
}

void editContact(Abonent* user, size_t size, const char* name, unsigned long long phone) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(user[i].name, name) == 0 || user[i].phone == phone) {
            strcpy(user[i].name, name);
            user[i].phone = phone;
        }
    }
}