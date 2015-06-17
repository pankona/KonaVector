
#include "KonaVector.h"
#include <iostream>
#include <cmath>

using namespace Kona;
using namespace std;

#define rad2deg(a) ((a) / 180.0 * M_PI)

Vector::Vector (const Point& in_terminal) {
    terminal = in_terminal;
}

Vector::Vector (const float in_length, const float in_angle) {
    float fx = cos (rad2deg(in_angle)) * in_length;
    float fy = sin (rad2deg(in_angle)) * in_length;

    terminal.x = fx;
    terminal.y = fy;
}

Vector::~Vector() {
    // nop
}

Vector&
Vector::operator= (const Vector& in_v) {
    this->terminal = in_v.terminal;
    return *this;
}

Vector
Vector::operator+ (const Vector& in_v) {
    Vector new_vector;
    new_vector.getTerminal().x = this->terminal.x + in_v.terminal.x;
    new_vector.getTerminal().y = this->terminal.y + in_v.terminal.y;
    return new_vector;
}

Vector&
Vector::operator+= (const Vector& in_v) {
    this->terminal.x += in_v.terminal.x;
    this->terminal.y += in_v.terminal.y;
    return *this;
}

bool
Vector::operator== (Vector& in_v) {
    return this->getTerminal() == in_v.getTerminal();
}

bool
Vector::operator!= (Vector& in_v) {
    return this->getTerminal() != in_v.getTerminal();
}

float
Vector::dot (Vector& in_v) {
    Point this_p = this->getTerminal();
    Point in_v_p = in_v.getTerminal();

    return this_p.x * in_v_p.x + this_p.y * in_v_p.y;;
}

float
Vector::cross (Vector& in_v) {
    Point this_p = this->getTerminal();
    Point in_v_p = in_v.getTerminal();

    return this_p.x * in_v_p.y - this_p.y * in_v_p.x;
}

static float
distanceOfPointToPoint (Point& in_p1, Point& in_p2) {
    
    float deltaX = in_p2.x - in_p1.x;
    float deltaY = in_p2.y - in_p1.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

float
Vector::distance (Point& in_p) {

    if (this->getLength() == 0) {
        // avoid 0 divide
        return 0;
    }

    Vector vector(in_p);
    float cosx = this->dot (vector) / this->getLength();
    if (cosx < 0) {
        Point p(0, 0);
        return distanceOfPointToPoint (in_p, p);
    } else if (cosx > this->getLength()) {
        return distanceOfPointToPoint (in_p, this->getTerminal());
    }

    Vector new_vector(in_p);
    float cross_prod = cross (new_vector);
    return cross_prod / this->getLength();
}

float
Vector::getLength() {
    return std::sqrt(terminal.x * terminal.x + terminal.y * terminal.y);
}

float
Vector::getAngle() {
    double radian = std::atan2(terminal.y, terminal.x);
    float angle = radian * 180 / M_PI;
    return angle;
}

void
Vector::setLength(float in_length) {
    int current_angle;

    current_angle = this->getAngle();
    Vector new_vector(in_length, current_angle);
    *this = new_vector;
}

void
Vector::setAngle(float in_angle) {
    float current_length;

    current_length = this->getLength();
    Vector new_vector(current_length, in_angle);
    *this = new_vector;
}

void
Vector::show () {
         cout << "("
              << this->terminal.x
              << ", "
              << this->terminal.y
              << ")"
              << endl;
}

Point&
Vector::getTerminal() {
    return terminal;
}


