#pragma once

#include "fullstd.h"

namespace hw17_09_25 {

    class Date {
    private:
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 12;
    public:
        Date(unsigned int d, unsigned int m, unsigned int y)
            : day(d), month(m), year(y) {
        }
        Date() : day(0), month(0), year(0) {}

        void setDay(unsigned int d) { day = d; }
        void setMonth(unsigned int m) { month = m; }
        void setYear(unsigned int y) { year = y; }

        unsigned int getDay()   const { return day; }
        unsigned int getMonth() const { return month; }
        unsigned int getYear()  const { return year; }


        void print() const {
            cout <<
                (day < 10 ? "0" : "")
                << day << '.'
                << (month < 10 ? "0" : "")
                << month << '.'
                << year << endl;
        }

        void save(ofstream& out) const {
            out.write((char*)this, sizeof(Date));
        }

        void load(ifstream& in) {
            in.read((char*)this, sizeof(Date));
        }
    };
}