
#include "KonaVector2D.h"
#include <iostream>

using namespace Kona;
using namespace std;


Vector2D::Vector2D(Vector in_v, Point in_startPoint) {
    this->vector = in_v;
    this->position = in_startPoint;
}

Vector2D::Vector2D(Point in_startPoint, Point in_endPoint) {
    this->position = in_startPoint;

    float deltaX = in_endPoint.x - in_startPoint.x;
    float deltaY = in_endPoint.y - in_startPoint.y;
    this->vector = Vector(Point(deltaX, deltaY));
}

Point
Vector2D::getStartPosition() {
    return this->position;
}

void
Vector2D::setStartPosition(Point in_p) {
    this->position = in_p;
}

Vector
Vector2D::getVector() {
    return this->vector;
}

void
Vector2D::setVector(Vector in_v) {
    this->vector = in_v;
}

Point
Vector2D::getTerminalPosition() {
    return Point(position.x + vector.getTerminal().x,
                 position.y + vector.getTerminal().y);
}

bool
Vector2D::calcIntersectPoint(Vector2D in_v, Point* out_point) {

    if (out_point == NULL) {
        return false;
    }

    Point a1, a2, b1, b2;
    a1 = this->position;
    a2 = this->getTerminalPosition();

    b1 = in_v.getStartPosition();
    b2 = in_v.getTerminalPosition();

    float r, s;
    float denominator = (a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x);

    if(denominator == 0) {
        return false;
    }

    float numeratorR = (a1.y - b1.y) * (b2.x - b1.x) - (a1.x - b1.x) * (b2.y - b1.y);
    r = numeratorR / denominator;

    float numeratorS = (a1.y - b1.y) * (a2.x - a1.x) - (a1.x - b1.x) * (a2.y - a1.y);
    s = numeratorS / denominator;

    if(r < 0 || r > 1 || s < 0 || s > 1) {
        return false;
    }

    out_point->x = a1.x + (r * (a2.x - a1.x));
    out_point->y = a1.y + (r * (a2.y - a1.y));
    return true;
}

float
Vector2D::getLength() {
    return vector.getLength();
}

float
Vector2D::getAngle() {
    return vector.getAngle();
}

bool
Vector2D::isTowardRight() {
    return vector.isTowardRight();
}
bool
Vector2D::isTowardLeft() {
    return vector.isTowardLeft();
}
bool
Vector2D::isTowardUp() {
    return vector.isTowardUp();
}
bool
Vector2D::isTowardDown() {
    return vector.isTowardDown();
}

void
Vector2D::show() {
    Point start, end;
    start = this->position;
    end = this->getTerminalPosition();

    cout << "(" << start.x << ", " << start.y << "), (" << end.x << ", "  << end.y << ")" << endl;
}

