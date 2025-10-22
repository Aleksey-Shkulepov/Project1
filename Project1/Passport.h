#pragma once

#include "fullstd.h"
#include "mystd.h"

struct visa
{
	String country;
	String dateOfIssue;

	friend ostream& operator<< (ostream& out, const visa& obj)
	{
		out << obj.country << " ";
		out << obj.dateOfIssue << "\n";
		return out;
	}
};

class Passport
{
protected:
	String name;
	String surname;
	String birthday;
	String serialId;
	String dateOfIssue;
public:
	Passport(String name, String surname, String birthday, String serialId, String dateOfIssue) 
		: name(name), surname(surname), birthday(birthday), serialId(serialId), dateOfIssue(dateOfIssue) {};
	virtual ~Passport() = default;
	virtual void info() const = 0;
};

class UkrainianPassport : public Passport
{
private:
	String patronymic;
public:
	UkrainianPassport(String name, String surname, String patronymic, String birthday, String serialId, String dateOfIssue)
		: patronymic(patronymic), Passport(name, surname, birthday, serialId, dateOfIssue)
	{}
	~UkrainianPassport() {}
	void info() const override
	{
		cout << "Info:\n";
		cout << "Name         : " << name << "\n";
		cout << "Surname      : " << surname << "\n";
		cout << "Patronymic   : " << patronymic << "\n";
		cout << "Birthday     : " << birthday << "\n";
		cout << "Serial id    : " << serialId << "\n";
		cout << "Date of issue: " << dateOfIssue << "\n";
	}
};

class UkrainianForeignPassport : public Passport
{
private:
	List<visa> visaList;
public:
	UkrainianForeignPassport(String name, String surname, String birthday, String serialId, String dateOfIssue) 
		: Passport(name, surname, birthday, serialId, dateOfIssue)
	{}
	~UkrainianForeignPassport() {};

	void info() const override
	{
		cout << "Info:\n";
		cout << "Name         : " << name << "\n";
		cout << "Surname      : " << surname << "\n";
		cout << "Birthday     : " << birthday << "\n";
		cout << "Serial id    : " << serialId << "\n";
		cout << "Date of issue: " << dateOfIssue << "\n";
	}
	void addVisa(visa visa)
	{
		visaList.push_front(visa);
	}
	void addVisa()
	{
		visa temp;
		cout << "Enter country: ";
		cin >> temp.country;
		cout << "Enter date of issue: ";
		cin >> temp.dateOfIssue;
		addVisa(temp);
	}
	void showVisa()
	{
		visaList.print();
	}
};

