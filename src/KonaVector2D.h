
#ifndef KONAVECTOR2D_H
#define KONAVECTOR2D_H

#include "KonaPoint.h"
#include "KonaVector.h"

namespace Kona {

class Vector2D {

private:
    Point position;
    Vector vector;

public:
    Vector2D(Vector, Point);
    Point getPosition();
    Vector getVector();
    Point calcIntersectPoint(Vector2D);

};

} // end of namespace

#endif /* KONAVECTOR_H */
