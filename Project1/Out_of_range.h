#pragma once

#include "fullstd.h"
#include "mystd.h"

namespace mystd {

    class Out_of_range : public exception
    {
    private:
        const char* message;

    public:
        Out_of_range(const char* msg) : message(msg) {}
        Out_of_range() : message("Index out of range") {}

        const char* what() const noexcept override
        {
            return message;
        }
    };
}
