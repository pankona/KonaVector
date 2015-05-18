
#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

namespace Kona {

class Vector {

private:
    Point start;
    Point end;
    void copyPoint(Point src, Point* dst);

public:
    Vector(Point start, Point end);
};

} // end of namespace

#endif /* VECTOR_H */
