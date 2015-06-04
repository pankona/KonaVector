
#include "Vector.h"
#include <iostream>
#include <cmath>

using namespace Kona;
using namespace std;

#define rad2deg(a) ((a) / 180.0 * M_PI)

Vector::Vector (const Point& in_terminal) {
    terminal = in_terminal;
}

Vector::Vector (const int in_length, const int in_angle) {
    float fx = cos (rad2deg(in_angle)) * in_length;
    float fy = sin (rad2deg(in_angle)) * in_length;

    terminal.x = (int) fx;
    terminal.y = (int) fy;
}

Vector::~Vector() {
    // nop
}

Vector&
Vector::operator= (Vector& in_v) {
    this->terminal = in_v.terminal;
    return *this;
}

Vector&
Vector::operator+ (Vector& in_v) {
    this->terminal.x += in_v.terminal.x;
    this->terminal.y += in_v.terminal.y;
    return *this;
}

int
Vector::getLength() {
    return (int) std::sqrt(terminal.x * terminal.x +
                           terminal.y * terminal.y);
}

int
Vector::getAngle() {
    double radian = std::atan2(terminal.y, terminal.x);
    int angle = (int) (radian * 180 / M_PI);
    return (int) angle;
}

void
Vector::setLength(int in_length) {
    int current_angle;

    current_angle = this->getAngle();
    Vector new_vector(in_length, current_angle);
    *this = new_vector;
}

void
Vector::setAngle(int in_angle) {
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


