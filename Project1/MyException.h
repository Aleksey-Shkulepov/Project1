#pragma once

#include <exception>
#include <string>

using namespace std;

class my_out_of_range : public exception
{
private:
    string message;

public:
    my_out_of_range(const string& msg = "Index out of range") : message(msg) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

