#pragma once

#include "fullstd.h"
#include "mystd.h"

class FileManager
{
public:
	virtual void Display(String path) {
        ifstream in(path.to_char());
        if (!in) return;

        String line;
        while (in >> line) 
            cout << line << endl;

        in.close();
	}
};

class ASCIIFileManager : public FileManager
{
public:
    virtual void Display(String path) override {
        ifstream in(path.to_char());
        if (!in) return;

        char ch;
        while (in >> ch)
            cout << std::hex << (int)ch << " ";

        in.close();
    }
};

class BinaryFileManager : public FileManager
{
public:
    virtual void Display(String path) override {
        ifstream in(path.to_char());
        if (!in) return;

        char ch;
        while (in >> ch)
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(ch) << " ";
        in.close();
    }
};