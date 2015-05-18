
#include "Vector.h"

namespace Kona {

Vector::copyPoint (Point in_src, Point* out_dst) {
    out_dest->x = in_src.x;
    out_dest->y = in_src.y;
}

Vector::Vector (Point in_start, Point* in_end) {
    copyPoint (in_start, &start);
    copyPoint (in_end, &end);
}

} // end of namespace
