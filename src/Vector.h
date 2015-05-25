
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
    Vector(const Point& start, const Point& end);
    ~Vector();
};

} // end of namespace

#endif /* VECTOR_H */
