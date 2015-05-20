

#include "Vector.h"

#include <iostream>

using namespace Kona;
using namespace std;

int main () {
    cout << "KonaVector test application!" << endl;

    Point start_point(0, 0);
    Point end_point(1, 1);

    Vector vector1(&start_point, &end_point);
}
