#pragma once

#include "SOSL.h" 

class new_PointNew {
    int x, y, z;

public:
    new_PointNew() : x(0), y(0), z(0) {}
    new_PointNew(int x) : x(x), y(0), z(0) {}
    new_PointNew(int x, int y) : x(x), y(y), z(0) {}
    new_PointNew(int x, int y, int z) : x(x), y(y), z(z) {}

    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }

    void save(ofstream& out) const {
        out.write((char*)this, sizeof(new_PointNew));
    }

    void load(ifstream& in) {
        in.read((char*)this, sizeof(new_PointNew));
    }

    friend ostream& operator<<(ostream& os, const new_PointNew& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }

    friend istream& operator>>(istream& in, new_PointNew& obj) {
        in >> obj.x >> obj.y >> obj.z;
        return in;
    }
};
