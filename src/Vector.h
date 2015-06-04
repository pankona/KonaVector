
#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

namespace Kona {

class Vector {

private:
    Point terminal;

public:
    Vector() : terminal() {}
    Vector(const Point& in_end);
    Vector(int in_length, int in_angle);
    ~Vector();
    Vector& operator=(const Vector& in_v);
    Vector operator+(const Vector& in_v);
    Vector& operator+=(const Vector& in_v);
    bool operator==(Vector& in_v);
    bool operator!=(Vector& in_v);
    int getLength();
    int getAngle();
    void setLength(int in_length);
    void setAngle(int in_angle);
    void show();
    Point& getTerminal();
};

} // end of namespace

#endif /* VECTOR_H */
