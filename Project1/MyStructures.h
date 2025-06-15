#pragma once

///15.06.25 h/w



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