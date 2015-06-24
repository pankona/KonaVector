
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
    Vector(float in_length, float in_angle);
    ~Vector();
    Vector& operator=(const Vector& in_v);
    Vector operator+(const Vector& in_v);
    Vector& operator+=(const Vector& in_v);
    bool operator==(Vector& in_v);
    bool operator!=(Vector& in_v);
    float getLength();
    float getAngle();
    void setLength(float in_length);
    void setAngle(float in_angle);
    float dot(Vector& in_v);
    float cross(Vector& in_v);
    float distance(Point& in_p);
    bool isTowardRight();
    bool isTowardLeft();
    bool isTowardUp();
    bool isTowardDown();
    void show();
    Point& getTerminal();
};

} // end of namespace

#endif /* KONAVECTOR_H */
