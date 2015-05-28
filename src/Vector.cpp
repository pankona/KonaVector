
#include "Vector.h"
#include <iostream>

using namespace Kona;
using namespace std;

Vector::Vector (const Point& in_start, const Point& in_end) {
    start = in_start;
    end = in_end;
}

Vector::~Vector() {
    // nop
}

Vector&
Vector::operator= (Vector& in_v) {
    this->start = in_v.start;
    this->end = in_v.end;
    return *this;
}

Vector&
Vector::operator+ (Vector& in_v) {
    this->start.x += in_v.start.x;
    this->start.y += in_v.start.y;
    this->end.x   += in_v.end.x;
    this->end.y   += in_v.end.y;
    return *this;
}

void
Vector::show () {
    cout << "(" << this->start.x << ", " << this->start.y << "), " 
         << "(" << this->end.x   << ", " << this->end.y   << ")" 
         << endl;
}


