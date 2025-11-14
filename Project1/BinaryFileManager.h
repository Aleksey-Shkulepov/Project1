#pragma once

#include "FileManager.h"

namespace hw26_10_25 {

    class BinaryFileManager : public FileManager
    {
    public:
        virtual void Display(const String& path) override {
            ifstream in(path.to_char());
            if (!in) return;

            char ch;
            while (in >> ch)
                cout << bitset<8>(static_cast<unsigned char>(ch)) << endl;
            in.close();
        }
    };

}