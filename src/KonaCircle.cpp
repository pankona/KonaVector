
#include "KonaCircle.h"
#include <iostream>
#include <cmath>
#include <float.h>

using namespace std;
using namespace Kona;

#define ALMOST_ZERO (0.0001)
#define IS_ALMOST_ZERO(x) \
    (floatCompare(std::abs(x), ALMOST_ZERO) == 1)

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
    float distance = std::abs(in_v2d.cross(this->center) / in_v2d.getLength());

    if (distance > this->radius) {
        return 0;
    }

    Vector2D vectorFromCenter;
    float atan2, acos;
    Point p1, p2;
    if(in_v2d.cross(this->center) > 0) {
        vectorFromCenter = calcVector2DfromCenter(std::abs(in_v2d.cross(this->center) / in_v2d.getLength()),
                                                  in_v2d.getAngle() - 90);
        atan2 = std::atan2(vectorFromCenter.getTerminalPosition().y - center.y,
                           vectorFromCenter.getTerminalPosition().x - center.x);
        acos  = std::acos(vectorFromCenter.getLength() / radius);
        p1 = Point(center.x + radius * std::cos(atan2 + acos), center.y + radius * std::sin(atan2 + acos));
        p2 = Point(center.x + radius * std::cos(atan2 - acos), center.y + radius * std::sin(atan2 - acos));
    } else if (in_v2d.cross(this->center) < 0) {
        vectorFromCenter = calcVector2DfromCenter(std::abs(in_v2d.cross(this->center) / in_v2d.getLength()),
                                                  in_v2d.getAngle() + 90);
        atan2 = std::atan2(vectorFromCenter.getTerminalPosition().y - center.y,
                           vectorFromCenter.getTerminalPosition().x - center.x);
        acos  = std::acos(vectorFromCenter.getLength() / radius);
        p1 = Point(center.x + radius * std::cos(atan2 + acos), center.y + radius * std::sin(atan2 + acos));
        p2 = Point(center.x + radius * std::cos(atan2 - acos), center.y + radius * std::sin(atan2 - acos));
    } else {
        vectorFromCenter = Vector2D(Vector(radius, in_v2d.getAngle()), center);
        p1 = vectorFromCenter.getTerminalPosition();

        vectorFromCenter.setAngle(vectorFromCenter.getAngle() + 180);
        p2 = vectorFromCenter.getTerminalPosition();
    }

    // substitute 0 if the value is almost 0
    if (IS_ALMOST_ZERO(p1.x)) p1.x = 0;
    if (IS_ALMOST_ZERO(p1.y)) p1.y = 0;
    if (IS_ALMOST_ZERO(p2.x)) p2.x = 0;
    if (IS_ALMOST_ZERO(p2.y)) p2.y = 0;

#if 0
    std::cout << "p1 = (" << p1.x << ", " << p1.y << ")"<< std::endl;
    std::cout << "p2 = (" << p2.x << ", " << p2.y << ")"<< std::endl;
    std::cout << "distance to p1 = " << in_v2d.distanceToPoint(p1) << std::endl;
    std::cout << "distance to p2 = " << in_v2d.distanceToPoint(p2) << std::endl;
#endif

    if (IS_ALMOST_ZERO(in_v2d.distanceToPoint(p1)) && 
        IS_ALMOST_ZERO(in_v2d.distanceToPoint(p2))) {
        if (p1 == p2) {
            *out_p1 = p1;
            return 1;
        } else {
            *out_p1 = p1;
            *out_p2 = p2;
            return 2;
        }
    } else if (!IS_ALMOST_ZERO(in_v2d.distanceToPoint(p1)) && 
               IS_ALMOST_ZERO(in_v2d.distanceToPoint(p2))) {
        *out_p1 = p2;
        return 1;
    } else if (IS_ALMOST_ZERO(in_v2d.distanceToPoint(p1)) && 
               !IS_ALMOST_ZERO(in_v2d.distanceToPoint(p2))) {
        *out_p1 = p1;
        return 1;
    }

    return 0;
}
void
Circle::show() {
}

