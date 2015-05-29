
#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

namespace Kona {

class Vector {

private:
    Point start;
    Point end;

public:
    Vector() : start(), end() {}
    Vector(const Point& in_start, const Point& in_end);
    Vector(int in_length, int in_angle);
    ~Vector();
    Vector& operator=(Vector& in_v);
    Vector& operator+(Vector& in_v);
    int getLength();
    int getAngle();
    void show();
};

} // end of namespace

#endif /* VECTOR_H */
