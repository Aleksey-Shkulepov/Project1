#pragma once

#include "fullstd.h"
#include "mystd.h"
#include <bitset>

namespace hw26_10_25 {

    class FileManager
    {
    public:
        virtual ~FileManager() = default;

        virtual void Display(const String& path) {
            ifstream in(path.to_char(), ios::binary);
            if (!in) return;

            String line;
            while (in >> line)
                cout << line << endl;

            in.close();
        }
    };

}