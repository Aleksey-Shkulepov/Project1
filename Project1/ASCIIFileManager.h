#pragma once

#include "FileManager.h"

namespace hw26_10_25 {

    class ASCIIFileManager : public FileManager
    {
    public:
        virtual void Display(const String& path) override {
            ifstream in(path.to_char());
            if (!in) return;

            char ch;
            while (in >> ch)
                cout << " " << dec << static_cast<int>(static_cast<unsigned char>(ch));
            cout << endl;

            in.close();
        }
    };

}