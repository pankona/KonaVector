
#ifndef KONAVECTOR_H
#define KONAVECTOR_H

#include "KonaPoint.h"

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
    int dot(Vector& in_v);
    int cross(Vector& in_v);
    void show();
    Point& getTerminal();
};

} // end of namespace

#endif /* KONAVECTOR_H */
