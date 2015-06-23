
#include "KonaVector.h"
#include "KonaVector2D.h"

#include <iostream>
#include <cmath>

using namespace Kona;
using namespace std;

#define ASSERT(x)                                \
        cout << "[" << __func__ << "]"           \
             << "[" << __LINE__ << "] ";         \
        if ((x)) {                              \
            cout << "." << endl; \
        } else {                                 \
            cout << "Assertion failed!" << endl; \
        }


int main () {
    cout << "KonaVector test application!" << endl;

    Point terminal1(1, 1);
    Vector vector1(terminal1);
    ASSERT(vector1.getAngle() == 45);
    ASSERT(vector1.getLength() == std::sqrt(1 + 1));
    cout << vector1.getLength() << endl;
    cout << std::sqrt(1 + 1) << endl;

    Point terminal2(1, 1);
    Vector vector2(terminal2);

    Vector vector3;
    vector3 = vector1 + vector2;
    ASSERT(vector1.getAngle() == 45);
    ASSERT(vector1.getLength() == (int)std::sqrt(1));
    ASSERT(vector2.getAngle() == 45);
    ASSERT(vector2.getLength() == (int)std::sqrt(1));
    ASSERT(vector3.getAngle() == 45);
    ASSERT(vector3.getLength() == (int)std::sqrt(4 + 4));

    Vector vector4 (1, 0);
    ASSERT(vector4.getAngle() == 0);
    ASSERT(vector4.getLength() == 1);

    Vector vector5 (1, 90);
    ASSERT(vector5.getAngle() == 90);
    ASSERT(vector5.getLength() == 1);

    Vector vector6 (2, 180);
    ASSERT(vector6.getAngle() == 180);
    ASSERT(vector6.getLength() == 2);

    Vector vector7 (2, 360);
    ASSERT(vector7.getAngle() == 0);
    ASSERT(vector7.getLength() == 2);

    vector7.setLength (3);
    ASSERT(vector7.getAngle() == 0);
    ASSERT(vector7.getLength() == 3);

    vector7.setAngle (90);
    ASSERT(vector7.getAngle() == 90);
    ASSERT(vector7.getLength() == 3);

    vector7.setAngle (180);
    ASSERT(vector7.getAngle() == 180);
    ASSERT(vector7.getLength() == 3);

    Vector vector8 (Point(1, 0));
    Vector vector9 (Point(0, 1));
    Vector vector10 = vector8 + vector9;
    ASSERT(vector10.getAngle() == 45);
    ASSERT(vector10.getLength() == (int) std::sqrt(1 + 1));

    vector8 += vector9;
    ASSERT(vector8.getAngle() == 45);
    ASSERT(vector8.getLength() == (int) std::sqrt(1 + 1));

    ASSERT(vector9.getAngle() == 90);
    ASSERT(vector9.getLength() == 1);

    ASSERT(vector8 == vector10)
    ASSERT(vector9 != vector10)
    vector8 = vector9;
    ASSERT(vector8 == vector9)
    ASSERT(vector8.getAngle() == 90);
    ASSERT(vector8.getLength() == 1);

    Point p1 (1, 1);
    Vector vector11 (Point(1, 0));
    ASSERT(vector11.distance (p1) == 1);

    Point p2 (0, 1);
    Point p3 (1, 1);
    Point p4 (-2, 1);
    Point p5 (3, 1);
    Vector vector12 (Point(1, 0));
    Vector vector13 (Point(2, 0));
    Vector vector14 (Point(3, 0));

    ASSERT(vector12.distance (p2) == 1);
    ASSERT(vector13.distance (p2) == 1);
    ASSERT(vector14.distance (p2) == 1);

    ASSERT(vector12.distance (p3) == 1);
    ASSERT(vector13.distance (p3) == 1);
    ASSERT(vector14.distance (p3) == 1);

    ASSERT(vector12.distance (p4) == 2);
    ASSERT(vector13.distance (p4) == 2);
    ASSERT(vector14.distance (p4) == 2);

    ASSERT(vector12.distance (p5) == 2);
    
    Point p6 (0, 1);
    Vector vector15 (Point(5, -2));
    ASSERT(vector15.distance (p6) == 1);


    cout << "Test for konaVector2D" << endl;
    Vector2D v2d1(Vector(Point(2, 2)), Point(0, 0));
    Vector2D v2d2(Vector(Point(1, -1)), Point(1, 1));
    Point ip;
    bool result;
    result = v2d1.calcIntersectPoint(v2d2, &ip);
    ASSERT(result);
    ASSERT(ip == Point(1, 1));

    return 0;
}
