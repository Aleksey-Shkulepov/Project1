#pragma once

#include "mystd.h"
#include "fullstd.h"

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

enum Color {
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7,
	DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12,
	LightMagenta = 13, Yellow = 14, White = 15
};

enum class DEPARTMENT
{
	GENERAL, TRANSPORT, ECONOMICS, DIRECTOR
};

ostream& operator<<(ostream& out, const DEPARTMENT& d)
{
	switch (d)
	{
	case DEPARTMENT::GENERAL:   out << "GENERAL"; break;
	case DEPARTMENT::TRANSPORT: out << "TRANSPORT"; break;
	case DEPARTMENT::ECONOMICS: out << "ECONOMICS"; break;
	case DEPARTMENT::DIRECTOR:  out << "DIRECTOR"; break;
	}
	return out;
}

class TaskPrint
{
	string fName;
	size_t time_left;
	DEPARTMENT department;
	
	DateTime time = DateTime::now();
public:
	TaskPrint(string fn, size_t t, DEPARTMENT d) : fName(fn), time_left(t), department(d) {}
	TaskPrint() {}

	DEPARTMENT getDepartment()
	{
		return department;
	}

	size_t getTime()
	{
		return time_left;
	}

	DateTime getPrintTime()
	{
		return time;
	}

	friend ostream& operator<<(ostream& out, const TaskPrint& tp);
};

ostream& operator<<(ostream& out, const TaskPrint& tp)
{
	out << setw(10) << left << tp.department << setw(10) << tp.fName << " " << tp.time.to_time() << endl;
	return out;
}

class PrintServer
{
	string ip;
	PriorityQueue<TaskPrint, DEPARTMENT> qPrint;
	ForwardList<TaskPrint> lStats;

	TaskPrint* currentTask = nullptr;
	int leftTime = 0;
	int totalTime = 0;

public:
	PrintServer(string ip) : ip(ip) {}

	void addTask(TaskPrint tp)
	{
		qPrint.enqueue(tp, tp.getDepartment());
	}

	void work()
	{
		system("cls");
		SetColor(Color::White, Blue);
		cout << "PrintServer : " << ip << endl;
		cout << "--------------------------------" << endl << endl;
		SetColor(White, Blue);
		if (qPrint.get_size() > 0 && currentTask == nullptr)
		{
			currentTask = new TaskPrint(*qPrint.front());
			qPrint.dequeue();
			leftTime = currentTask->getTime();
		}


		cout << "Current document : left time - " << leftTime << endl;
		if (currentTask)
		{
			cout << *currentTask << endl;
		}
		else
		{
			cout << " " << endl;
		}

		cout << "Waiting : " << endl;
		cout << "-----------------------------" << endl;
		qPrint.print();

		gotoxy(32, 6);
		cout << "Printing : ";
		gotoxy(32, 7);
		cout << "------------------------------" << endl;
		lStats.print(32, 8, 10);

		leftTime--;
		totalTime++;
		if (leftTime < 0)
		{
			if (currentTask)
				lStats.push_back(*currentTask);
			currentTask = nullptr;
			leftTime = 0;
		}
		
		showStats();
	}

	void showStats() 
	{
		gotoxy(65, 6);
		cout << "Stats : " << endl;
		gotoxy(65, 7);
		cout << "------------------------------------" << endl;
		gotoxy(65, 8);
		cout << "General time printing: " << totalTime << " secs" << endl;
		gotoxy(65, 9);
		cout << "Count of printed documents: " << lStats.get_size() << endl;
		for (size_t i = 0; i < 4; i++)
		{
			size_t size = 0;
			gotoxy(65, 10+i);
			for (size_t j = 0; j < lStats.get_size(); j++)
				if(lStats[j].getDepartment() == (DEPARTMENT)i) size++;
			cout << "Count of printed " << (DEPARTMENT)i << " documents: " << size << endl;
		}
	}
};