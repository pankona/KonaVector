

#include "Vector.h"

#include <iostream>

using namespace Kona;
using namespace std;

int main () {
    cout << "KonaVector test application!" << endl;

    Point start_point1(0, 0);
    Point end_point1(1, 1);
    Vector vector1(start_point1, end_point1);

    Point start_point2(0, 0);
    Point end_point2(1, 1);
    Vector vector2(start_point2, end_point2);

    vector1.show();
    vector2.show();

    Vector vector3;
    vector3 = vector1 + vector2;
    vector3.show();
}
