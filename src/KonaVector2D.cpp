
#include "KonaVector2D.h"
#include <iostream>

using namespace Kona;
using namespace std;


Vector2D::Vector2D(Vector in_v, Point in_p) {
    this->vector = in_v;
    this->position = in_p;
}

Point
Vector2D::getPosition() {
    return this->position;
}

Vector
Vector2D::getVector() {
    return this->vector;
}

Point
Vector2D::calcIntersectPoint(Vector2D in_v) {

    Point a1, a2, b1, b2;
    a1 = this->position;
    a2.x = a1.x + this->vector.getTerminal().x;
    a2.y = a1.y + this->vector.getTerminal().y;

    b1 = in_v.getPosition();
    b2.x = b1.x + in_v.getVector().getTerminal().x;
    b2.y = b1.y + in_v.getVector().getTerminal().y;

    double r, s;
    double denominator = (a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x);


    if(denominator == 0) {
        return Point(0, 0);
    }

    double numeratorR = (a1.y - b1.y) * (b2.x - b1.x) - (a1.x - b1.x) * (b2.y - b1.y);
    r = numeratorR / denominator;

    double numeratorS = (a1.y - b1.y) * (a2.x - a1.x) - (a1.x - b1.x) * (a2.y - a1.y);
    s = numeratorS / denominator;

    if(r < 0 || r > 1 || s<0 || s > 1) {
        return Point(0, 0);
    }

    Point ret;
    ret.x = (float)(a1.x + (r * (a2.x - a1.x)));
    ret.y = (float)(a1.y + (r * (a2.y - a1.y)));
    return ret;
}
