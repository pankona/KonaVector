
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
    Vector2D();
    Vector2D(Vector, Point);
    Vector2D(Point, Point);

    Vector2D& operator=(Vector2D in_v);

    Point getStartPosition();
    void setStartPosition(Point);

    Vector getVector();
    void setVector(Vector);

    Point getTerminalPosition();

    float getLength();
    void setLength(float);

    float getAngle();
    void setAngle(float);

    bool calcIntersectPoint(Vector2D, Point*);
    float distanceToPoint(Point);

    bool isTowardRight();
    bool isTowardLeft();
    bool isTowardUp();
    bool isTowardDown();

    float cross(Point);

    void show();
};

} // end of namespace

#endif /* KONAVECTOR_H */
