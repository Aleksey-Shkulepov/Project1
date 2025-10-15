#pragma once

#include <iostream>

enum DayOfWeek
{
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

std::ostream& operator<<(std::ostream& out, const DayOfWeek& dw)
{
	switch (dw)
	{
	case Sunday:   out << "Sunday";    break;
	case Monday:   out << "Monday";    break;
	case Tuesday:  out << "Tuesday";   break;
	case Wednesday:out << "Wednesday"; break;
	case Thursday: out << "Thursday";  break;
	case Friday:   out << "Friday";    break;
	case Saturday: out << "Saturday";  break;
	}return out;
}

class DateTime
{
	//time_t timestamp;
	tm dt;

public:
	DateTime(tm& dt);
	DateTime(int year, int month, int day);
	DateTime(int year, int month, int day, int hour, int minute, int second);
	static      DateTime now();
	static bool isLeapYear(int year);
	int         getYear() const;
	int         getMonth() const;
	int         getDay() const;
	int         getHour() const;
	int         getMinute() const;
	int         getSecond() const;
	int         getDayOfYear() const;
	time_t      getTimestamp() const;
	DayOfWeek   getDayOfWeek() const;
	DateTime& addSecond(int value);
	DateTime& addMinutes(int value);
	DateTime& addHours(int value);
	DateTime& addDays(int value);
	DateTime& addMonths(int value);
	DateTime& addYears(int value);
	int         compareTo(const DateTime& datetime) const;
	const char* to_string(const char* format) const;
	const char* to_fullDateTime() const;
	const char* to_longDateTime() const;
	const char* to_shortDateTime() const;
	const char* to_time() const;
	const char* to_longDate() const;
	const char* to_shortDate() const;

	friend std::ostream& operator<<(std::ostream& out, const DateTime& datetime);
};


inline DateTime::DateTime(tm& dt)
{
	this->dt = dt;
}


inline DateTime::DateTime(int year, int month, int day) : DateTime(year, month, day, 0, 0, 0)
{

}


inline DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
{
	dt.tm_year = year - 1900;
	dt.tm_mon = month - 1;
	dt.tm_mday = day;
	dt.tm_hour = hour;
	dt.tm_min = minute;
	dt.tm_sec = second;
	mktime(&dt);
}


/// <summary>
/// Поточна дата і час
/// </summary>
/// <returns>12 December 2025, 12:34:20</returns>
DateTime DateTime::now()
{
	time_t timestamp = time(NULL);
	tm dt;
	localtime_s(&dt, &timestamp);
	return DateTime(dt);
}

/// <summary>
/// Метод перевіряє чи є рік високосним
/// </summary>
/// <param name="year"> - рік</param>
/// <returns>True/False</returns>
inline bool DateTime::isLeapYear(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}


inline int DateTime::getYear() const
{
	return dt.tm_year + 1900;
}


inline int DateTime::getMonth() const
{
	return dt.tm_mon + 1;
}


inline int DateTime::getDay() const
{
	return dt.tm_mday;
}


inline int DateTime::getHour() const
{
	return dt.tm_hour;
}


inline int DateTime::getMinute() const
{
	return dt.tm_min;
}


inline int DateTime::getSecond() const
{
	return dt.tm_sec;
}


inline int DateTime::getDayOfYear() const
{
	return dt.tm_yday + 1;
}

inline time_t DateTime::getTimestamp() const
{
	tm temp = dt;
	return mktime(&temp);
}


inline DateTime& DateTime::addSecond(int value)
{
	dt.tm_sec += value;
	mktime(&dt);
	return *this;
}


inline DateTime& DateTime::addMinutes(int value)
{
	dt.tm_min += value;
	mktime(&dt);
	return *this;
}


inline DateTime& DateTime::addHours(int value)
{
	dt.tm_hour += value;
	mktime(&dt);
	return *this;
}


inline DateTime& DateTime::addDays(int value)
{
	dt.tm_mday += value;
	mktime(&dt);
	return *this;
}


inline DateTime& DateTime::addMonths(int value)
{
	dt.tm_mon += value;
	mktime(&dt);
	return *this;
}


inline DateTime& DateTime::addYears(int value)
{
	dt.tm_year += value;
	mktime(&dt);
	return *this;
}


inline DayOfWeek DateTime::getDayOfWeek() const
{
	return (DayOfWeek)dt.tm_wday;
}

/// <summary>
/// Порівняння двох дат
/// </summary>
/// <param name="datetime"></param>
/// <returns>1 - більший, хто викликав метод, 0 - дати рівні, -1 - більший параметр методу</returns>
inline int DateTime::compareTo(const DateTime& datetime) const
{
	tm t1 = dt;
	tm t2 = datetime.dt;
	time_t dt1 = mktime(&t1);
	time_t dt2 = mktime(&t2);
	if (dt1 > dt2)
		return 1;
	else if (dt1 < dt2)
		return -1;
	return 0;
}


/// <summary>
/// Форматування дати за зразком
/// </summary>
/// <param name="format"> - Рядок форматування
/// </param>
/// <param name="%a"> - Коротке зображення дня тижня        Fri</param>
/// <param name="%A"> - Повне зображення дня тижня          Friday</param>
/// <param name="">%b - Коротке представлення назви місяця  Dec</param>
/// <param name="">%B - Повне представлення назви місяця	December</param>
/// <param name="">%m - Номер місяця	                    10</param>
/// <param name="">%d - День місяця з нулем на початку	    09</param>
/// <param name="">%e - День місяця з пробілами на початку	 9</param>
/// <param name="">%H - 24 - годинний формат годин	        14</param>
/// <param name="">%I - 12 - годинний формат годин	        02</param>
/// <param name="">%M - Хвилин протягом години	            30</param>
/// <param name="">%p - AM або PM	                        PM</param>
/// <param name="">%S - Секунди протягом хвилини	        01</param>
/// <param name="">%y - 2 - значне представлення року	    23</param>
/// <param name="">%Y - 4 - значне представлення року     2023</param>
/// <returns>Рядок у бажаному форматі</returns>
inline const char* DateTime::to_string(const char* format) const
{
	char* buff = new char[100];
	strftime(buff, 100, format, &dt);
	int len = strlen(buff) + 1;
	char* buff2 = new char[len];
	strcpy_s(buff2, len, buff);
	delete[] buff;
	return buff2;
}


/// <summary>
/// Повний формат дати
/// </summary>
/// <returns>12 December 2025, 12:34:20, Monday</returns>
inline const char* DateTime::to_fullDateTime() const
{
	return to_string("%d %B %Y, %H:%M:%S, %A");
}


/// <summary>
/// Довгий формат дати і часу
/// </summary>
/// <returns>12 December 2025, 12:34:20</returns>
inline const char* DateTime::to_longDateTime() const
{
	return to_string("%d %B %Y, %H:%M:%S");
}


/// <summary>
/// Короткий формат дати і часу
/// </summary>
/// <returns>12.10.2024, 15:12:00</returns>
inline const char* DateTime::to_shortDateTime() const
{
	return to_string("%d.%m.%Y, %H:%M:%S");
}

/// <summary>
/// Короткий формат часу
/// </summary>
/// <returns>15:12:00</returns>
inline const char* DateTime::to_time() const
{
	return to_string("%H:%M:%S");
}

/// <summary>
/// Довгий формат дати
/// </summary>
/// <returns>12 October 2024</returns>
inline const char* DateTime::to_longDate() const
{
	return to_string("%d %B %Y");
}


/// <summary>
/// Короткий формат дати
/// </summary>
/// <returns>10.12.2024</returns>
inline const char* DateTime::to_shortDate() const
{
	return to_string("%d.%m.%Y");
}


std::ostream& operator<<(std::ostream& out, const DateTime& datetime)
{
	out << datetime.to_longDateTime();
	return out;
}

