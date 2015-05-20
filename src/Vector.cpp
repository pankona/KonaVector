
#include "Vector.h"

using namespace Kona;

Vector::Vector (Point* in_start, Point* in_end) {
    start = new Point (in_start->x, in_start->y);
    end = new Point (in_end->x, in_end->y);
}
