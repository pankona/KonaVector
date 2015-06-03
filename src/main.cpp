

#include "Vector.h"

#include <iostream>
#include <cmath>

using namespace Kona;
using namespace std;

#define ASSERT(x)                                \
        cout << "[" << __func__ << "]"           \
             << "[" << __LINE__ << "] ";         \
        if (!(x)) {                              \
            cout << "Assertion failed!" << endl; \
        } else {                                 \
            cout << "Assertion passed!" << endl; \
        }


int main () {
    cout << "KonaVector test application!" << endl;

    Point terminal1(1, 1);
    Vector vector1(terminal1);
    ASSERT(vector1.getAngle() == 45);
    ASSERT(vector1.getLength() == (int)std::sqrt(1));
    

    Point terminal2(1, 1);
    Vector vector2(terminal2);

    Vector vector3;
    vector3 = vector1 + vector2;
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

    return 0;

}
