
#include "KonaCircle.h"
#include <iostream>
#include <cmath>
#include <float.h>

using namespace Kona;

// private functions
Vector2D
Circle::calcVector2DfromCenter(float in_length, float in_angle) {
    return Vector2D(Vector(in_length, in_angle), this->center);
}

// public functions
static int
floatCompare (float a, float b) {
    if (a == b ||
        std::abs(a - b) < std::max(a , b) * FLT_EPSILON) {
       return 0;
    } else if (a > b) {
       return -1;
    } else {
        return 1;
    }
}

Circle::Circle() {
    center = Point(0, 0);
    radius = 0;
}

Circle::Circle(Point in_center, float in_radius) {
    center = in_center;
    radius = in_radius;
}

Circle&
Circle::operator=(Circle in_circle) {
   this->center = in_circle.center; 
   this->radius = in_circle.radius; 
   return *this;
}


int
Circle::intersectsVector2D(Vector2D in_v2d,
                           Point* out_p1, Point* out_p2) {
    float distance = in_v2d.cross(this->center) / in_v2d.getLength();
    if (distance > this->radius) {
        return 0;
    }

    Vector2D vectorFromCenter;
    float atan2, acos;
    if(in_v2d.cross(this->center) > 0) {
        vectorFromCenter = calcVector2DfromCenter(std::abs(in_v2d.cross(this->center) / in_v2d.getLength()),
                                                  in_v2d.getAngle() - 90);
        atan2 = std::atan2(vectorFromCenter.getTerminalPosition().y, vectorFromCenter.getTerminalPosition().x);
        acos  = std::acos(vectorFromCenter.getLength() / radius);
    } else if (in_v2d.cross(this->center) < 0) {
        vectorFromCenter = calcVector2DfromCenter(std::abs(in_v2d.cross(this->center) / in_v2d.getLength()),
                                                  in_v2d.getAngle() + 90);
        atan2 = std::atan2(vectorFromCenter.getTerminalPosition().y, vectorFromCenter.getTerminalPosition().x);
        acos  = std::acos(vectorFromCenter.getLength() / radius);
    } else {
        atan2 = std::atan2(-1, in_v2d.getTerminalPosition().y / in_v2d.getTerminalPosition().x);
        acos  = M_PI / 2;
    }
    Point p1(center.x + radius * std::cos(atan2 + acos), center.y + radius * std::sin(atan2 + acos));
    Point p2(center.x + radius * std::cos(atan2 - acos), center.y + radius * std::sin(atan2 - acos));

    // substitute 0 if the value is almost 0
    if (floatCompare(std::abs(p1.x), 0.00001) == 1) p1.x = 0;
    if (floatCompare(std::abs(p1.y), 0.00001) == 1) p1.y = 0;
    if (floatCompare(std::abs(p2.x), 0.00001) == 1) p2.x = 0;
    if (floatCompare(std::abs(p2.y), 0.00001) == 1) p2.y = 0;

    if (floatCompare(in_v2d.distanceToPoint(p1), 0) == 0 && 
        floatCompare(in_v2d.distanceToPoint(p2), 0) == 0) {
        if (p1 == p2) {
            *out_p1 = p1;
            return 1;
        } else {
            *out_p1 = p1;
            *out_p2 = p2;
            return 2;
        }
    } else if (floatCompare(in_v2d.distanceToPoint(p1), 0) != 0 && 
               floatCompare(in_v2d.distanceToPoint(p2), 0) == 0) {
        *out_p1 = p2;
        return 1;
    } else if (floatCompare(in_v2d.distanceToPoint(p1), 0) == 0 && 
               floatCompare(in_v2d.distanceToPoint(p2), 0) != 0) {
        *out_p1 = p1;
        return 1;
    }

    return 0;
}
void
Circle::show() {
}

