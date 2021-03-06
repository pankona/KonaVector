
#include "KonaVector2D.h"
#include <iostream>

using namespace Kona;
using namespace std;


Vector2D::Vector2D() {
    this->vector = Vector(Point(0, 0));
    this->position = Point(0, 0);
}

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

Vector2D&
Vector2D::operator=(Vector2D in_v) {
    this->vector = in_v.getVector();
    this->position = in_v.getStartPosition();
    return *this;
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
Vector2D::distanceToPoint(Point in_p) {
    Kona::Point p (in_p.x - position.x, in_p.y - position.y);
    return vector.distance(p);
}

float
Vector2D::getLength() {
    return vector.getLength();
}

void
Vector2D::setLength(float in_length) {
    vector.setLength(in_length);
}

float
Vector2D::getAngle() {
    return vector.getAngle();
}

void
Vector2D::setAngle(float in_angle) {
    vector.setAngle(in_angle);
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

float
Vector2D::cross(Point in_p) {
    Point p(in_p.x - position.x,
            in_p.y - position.y);
    Vector v(p);
    return vector.cross(v);
}

Vector2D
Vector2D::getStrechedVector(int in_stretchLength) {

    Kona::Vector2D startPosition(Kona::Vector(in_stretchLength, this->getAngle() + 180),
                                 this->getStartPosition());
    Kona::Vector2D terminalPosition(Kona::Vector(in_stretchLength, this->getAngle()),
                                    this->getTerminalPosition());
    return Kona::Vector2D(startPosition.getTerminalPosition(),
                          terminalPosition.getTerminalPosition());
}

void
Vector2D::show() {
    Point start, end;
    start = this->position;
    end = this->getTerminalPosition();

    cout << "(" << start.x << ", " << start.y << "), (" << end.x << ", "  << end.y << ")" << endl;
}

