#pragma once

#include "fullstd.h"

namespace hw20_09_25 {

    class Worker {
        char* name;
        char* position;
        int yearStart;
        double salary;
    public:
        Worker() : name(nullptr), position(nullptr), yearStart(0), salary(0) {}

        Worker(const char* n, const char* pos, int y, double s)
            : yearStart(y), salary(s)
        {
            size_t n_s = strlen(n);
            name = new char[n_s + 1];
            strcpy_s(name, n_s + 1, n);

            size_t pos_s = strlen(pos);
            position = new char[pos_s + 1];
            strcpy_s(position, pos_s+1, pos);
        }

        Worker(const Worker& other)
            : yearStart(other.yearStart), salary(other.salary)
        {
            if (other.name) {
                size_t n_s = strlen(other.name);
                name = new char[n_s + 1];
                strcpy_s(name, n_s + 1, other.name);
            }
            else {
                name = nullptr;
            }

            if (other.position) {
                size_t pos_s = strlen(other.position);
                position = new char[pos_s + 1];
                strcpy_s(position, pos_s + 1, other.position);
            }
            else {
                position = nullptr;
            }
        }

        ~Worker() {
            delete[] name;
            delete[] position;
        }

        const char* getName()      const { return name; }
        const char* getPosition()  const { return position; }
        int         getYearStart() const { return yearStart; }
        double      getSalary()    const { return salary; }


        void setName(const char* n)
        {
            size_t n_s = strlen(n);
            name = new char[n_s + 1];
            strcpy_s(name, n_s + 1, n);
        }

        void setPosition(const char* p)
        {
            size_t p_s = strlen(p);
            position = new char[p_s + 1];
            strcpy_s(position, p_s + 1, p);
        }

        void setYearStart(int ys) { yearStart = ys; }
        void setSalary(int s) { salary = s; }

        void print() const {
            cout
                << "Name: " << name << endl
                << "Position: " << position << endl
                << "Working from " << yearStart << endl
                << "Salary: " << salary << endl
                << endl;
        }
    };

}