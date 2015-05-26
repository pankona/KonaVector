
#include "Vector.h"

using namespace Kona;

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
