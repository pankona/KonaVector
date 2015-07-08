
#include "KonaVector.h"
#include "KonaVector2D.h"
#include "KonaRect.h"
#include "KonaCircle.h"

#include <iostream>
#include <cmath>
#include <float.h>
#include <algorithm>

using namespace Kona;
using namespace std;

static bool failedCaseExists = false;

#define ASSERT(x)                                \
        if ((x)) {                               \
            cout << ".";                         \
        } else {                                 \
        cout << "[" << __func__ << "]"           \
             << "[" << __LINE__ << "] ";         \
            cout << "Assertion failed!" << endl; \
            failedCaseExists = true;             \
        }

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

static void
TestForKonaRect() {
    cout << endl;
    cout << "@@@ Test for KonaRect @@@" << endl;

    Rect rect(Vector2D(Vector(Point(0, 2)), Point(0, 0)), 
              Vector2D(Vector(Point(0, 2)), Point(2, 0)));
    ASSERT(rect.containsPoint(Point(1, 1)));
    ASSERT(rect.containsPoint(Point(0, 1)));
    ASSERT(rect.containsPoint(Point(1, 0)));
    ASSERT(rect.containsPoint(Point(0, 0)));
    ASSERT(rect.containsPoint(Point(2, 2)));
    ASSERT(rect.containsPoint(Point(2, 0)));
    ASSERT(rect.containsPoint(Point(0, 2)));
    ASSERT(!rect.containsPoint(Point(3, 3)));
    ASSERT(!rect.containsPoint(Point(-1, 0)));
    ASSERT(!rect.containsPoint(Point(0, -1)));
    ASSERT(!rect.containsPoint(Point(-1, -1)));

    Point intersectPoint;
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(1, -1)), &intersectPoint));
    ASSERT(intersectPoint.x == 1 && intersectPoint.y == 0);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(0, 0)), &intersectPoint));
    ASSERT(intersectPoint.x == 0 && intersectPoint.y == 2);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(2, 0)), &intersectPoint));
    ASSERT(intersectPoint.x == 2 && intersectPoint.y == 2);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(1, 1)), &intersectPoint));
    ASSERT(intersectPoint.x == 1 && intersectPoint.y == 2);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(-1, 1)), &intersectPoint));
    ASSERT(intersectPoint.x == 0 && intersectPoint.y == 1);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(1, 1)), &intersectPoint));
    ASSERT(intersectPoint.x == 2 && intersectPoint.y == 1);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(0, 2)), &intersectPoint));
    ASSERT(intersectPoint.x == 0 && intersectPoint.y == 2);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(0, -2)), &intersectPoint));
    ASSERT(intersectPoint.x == 0 && intersectPoint.y == 0);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(2, -2)), &intersectPoint));
    ASSERT(intersectPoint.x == 2 && intersectPoint.y == 0);
    ASSERT(rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(2, 2)), &intersectPoint));
    ASSERT(intersectPoint.x == 2 && intersectPoint.y == 2);
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(-1, 0)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(0, -3)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(1, -3)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(2, -3)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(0, 2)), Point(3, 0)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(-3, 0)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(-3, 1)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(-3, 2)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(-3, -1)), &intersectPoint));
    ASSERT(!rect.intersectsVector2D(Vector2D(Vector(Point(2, 0)), Point(-3, -2)), &intersectPoint));
}

static void
TestForKonaCircle() {
    cout << endl;
    cout << "@@@ Test for KonaCircle @@@" << endl;

    Circle circle(Point(0, 0), 2);

    Point p1, p2;
    ASSERT(circle.intersectsVector2D(Vector2D(Point(3, -3), Point(3, 3)), &p1, &p2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(0, -1), Point(0, 1)), &p1, &p2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(2, -1), Point(2, 1)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 2) == 0 && floatCompare(p1.y, 0)  == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(1, -2), Point(1, 2)), &p1, &p2) == 2);
    ASSERT(floatCompare(p1.x, 1) == 0 && floatCompare(p1.y, std::sqrt(3)) == 0);
    ASSERT(floatCompare(p2.x, 1) == 0 && floatCompare(p2.y, -1 * std::sqrt(3)) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(0, 0), Point(0, 4)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, 2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-1, -3), Point(3, 1)), &p1, &p2) == 2);
    ASSERT(floatCompare(p1.x, 2) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(floatCompare(p2.x, 0) == 0 && floatCompare(p2.y, -2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(0, 2), Point(2, 0)), &p1, &p2) == 2);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, 2) == 0);
    ASSERT(floatCompare(p2.x, 2) == 0 && floatCompare(p2.y, 0) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-2, 0), Point(0, 2)), &p1, &p2) == 2);
    ASSERT(floatCompare(p1.x, -2) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(floatCompare(p2.x, 0) == 0 && floatCompare(p2.y, 2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-2, 0), Point(0, -2)), &p1, &p2) == 2);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, -2) == 0);
    ASSERT(floatCompare(p2.x, -2) == 0 && floatCompare(p2.y, 0) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(2, -2), Point(2, 2)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 2) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-2, 2), Point(2, 2)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, 2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-2, -2), Point(-2, 2)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, -2) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-2, -2), Point(2, -2)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, -2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-2, 0), Point(-3, 0)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, -2) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(0, 3), Point(0, 2)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, 2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(3, 0), Point(2, 0)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 2) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(0, -3), Point(0, -2)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, -2) == 0);

    circle = Circle(Point(2, 0), 2);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(-1, -1), Point(-1, 1)), &p1, &p2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(0, -1), Point(0, 1)), &p1, &p2) == 1);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(0, 0), Point(2, 2)), &p1, &p2) == 2);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(floatCompare(p2.x, 2) == 0 && floatCompare(p2.y, 2) == 0);
    ASSERT(circle.intersectsVector2D(Vector2D(Point(2, 2), Point(0, 0)), &p1, &p2) == 2);
    ASSERT(floatCompare(p1.x, 0) == 0 && floatCompare(p1.y, 0) == 0);
    ASSERT(floatCompare(p2.x, 2) == 0 && floatCompare(p2.y, 2) == 0);
}

int main () {
    cout << "KonaVector test application!" << endl;

    cout << "@@@ Test for KonaVector @@@" << endl;
    Point terminal1(1, 1);
    Vector vector1(terminal1);
    ASSERT(vector1.getAngle() == 45);
    ASSERT(floatCompare(vector1.getAngle(), 45) == 0);
    ASSERT(vector1.isTowardRight());
    ASSERT(vector1.isTowardUp());
    ASSERT(!vector1.isTowardLeft());
    ASSERT(!vector1.isTowardDown());
    Point terminal2(1, 1);
    Vector vector2(terminal2);
    ASSERT(vector2.isTowardRight());
    ASSERT(vector2.isTowardUp());
    ASSERT(!vector2.isTowardLeft());
    ASSERT(!vector2.isTowardDown());

    Vector vector3;
    vector3 = vector1 + vector2;
    ASSERT(vector1.getAngle() == 45);
    ASSERT(floatCompare(vector1.getLength(), std::sqrt(1 + 1)) == 0);
    ASSERT(vector2.getAngle() == 45);
    ASSERT(floatCompare(vector2.getLength(), std::sqrt(1 + 1)) == 0);
    ASSERT(vector3.getAngle() == 45);
    ASSERT(floatCompare(vector3.getLength(), std::sqrt(4 + 4)) == 0);
    ASSERT(vector3.isTowardRight());
    ASSERT(vector3.isTowardUp());
    ASSERT(!vector3.isTowardLeft());
    ASSERT(!vector3.isTowardDown());

    Vector vector4 (1, 0);
    ASSERT(floatCompare(vector4.getAngle(), 0) == 0);
    ASSERT(vector4.getLength() == 1);
    ASSERT(vector4.isTowardRight());
    ASSERT(!vector4.isTowardUp());
    ASSERT(!vector4.isTowardDown());

    Vector vector5 (1, 90);
    ASSERT(floatCompare(vector5.getAngle(), 90) == 0);
    ASSERT(vector5.getLength() == 1);
    ASSERT(!vector5.isTowardRight());
    ASSERT(!vector5.isTowardLeft());
    ASSERT(vector5.isTowardUp());
    ASSERT(!vector5.isTowardDown());

    Vector vector6 (2, 180);
    ASSERT(floatCompare(vector6.getAngle(), 180) == 0);
    ASSERT(vector6.getLength() == 2);
    ASSERT(!vector6.isTowardRight());
    ASSERT(vector6.isTowardLeft());
    ASSERT(!vector6.isTowardUp());
    ASSERT(!vector6.isTowardDown());

    Vector vector7 (2, 360);
    ASSERT(vector7.getAngle() == 0);
    ASSERT(vector7.getLength() == 2);
    ASSERT(vector7.isTowardRight());
    ASSERT(!vector7.isTowardLeft());
    ASSERT(!vector7.isTowardUp());
    ASSERT(!vector7.isTowardDown());

    vector7.setLength (3);
    ASSERT(vector7.getAngle() == 0);
    ASSERT(vector7.getLength() == 3);

    vector7.setAngle (90);
    ASSERT(floatCompare(vector7.getAngle(), 90) == 0);
    ASSERT(vector7.getLength() == 3);

    vector7.setAngle (180.0);
    ASSERT(floatCompare(vector7.getAngle(), 180.0) == 0);
    ASSERT(vector7.getLength() == 3);
    ASSERT(!vector7.isTowardRight());
    ASSERT(vector7.isTowardLeft());
    ASSERT(!vector7.isTowardUp());
    ASSERT(!vector7.isTowardDown());

    Vector vector8 (Point(1, 0));
    Vector vector9 (Point(0, 1));
    Vector vector10 = vector8 + vector9;
    ASSERT(floatCompare(vector10.getAngle(), 45) == 0);
    ASSERT(floatCompare(vector10.getLength(), std::sqrt(1 + 1)) == 0);

    vector8 += vector9;
    ASSERT(floatCompare(vector8.getAngle(), 45) == 0);
    ASSERT(floatCompare(vector8.getLength(), std::sqrt(1 + 1)) == 0);

    ASSERT(floatCompare(vector9.getAngle(), 90) == 0);
    ASSERT(vector9.getLength() == 1);

    ASSERT(vector8 == vector10)
    ASSERT(vector9 != vector10)
    vector8 = vector9;
    ASSERT(vector8 == vector9)
    ASSERT(floatCompare(vector8.getAngle(), 90) == 0);
    ASSERT(vector8.getLength() == 1);

    Point p1 (1, 1);
    Vector vector11 (Point(1, 0));
    ASSERT(vector11.distance (p1) == 1);

    Point p2 (0, 1);
    Point p3 (1, 1);
    Point p4 (-2, 1);
    Point p5 (3, 1);
    Vector vector12 (Point(1, 0));
    Vector vector13 (Point(2, 0));
    Vector vector14 (Point(3, 0));

    ASSERT(vector12.distance (p2) == 1);
    ASSERT(vector13.distance (p2) == 1);
    ASSERT(vector14.distance (p2) == 1);

    ASSERT(vector12.distance (p3) == 1);
    ASSERT(vector13.distance (p3) == 1);
    ASSERT(vector14.distance (p3) == 1);

    ASSERT(floatCompare(vector12.distance (p4), std::sqrt(4 + 1)) == 0);
    ASSERT(floatCompare(vector13.distance (p4), std::sqrt(4 + 1)) == 0);
    ASSERT(floatCompare(vector14.distance (p4), std::sqrt(4 + 1)) == 0);
    ASSERT(floatCompare(vector12.distance (p5), std::sqrt(4 + 1)) == 0);

    Point p6 (0, 1);
    Vector vector15 (Point(5, -2));
    ASSERT(vector15.distance (p6) == 1);

    cout << endl;
    cout << "@@@ Test for KonaVector2D @@@" << endl;
    Vector2D v2d1(Vector(Point(2, 2)), Point(0, 0));
    ASSERT(v2d1.isTowardRight());
    ASSERT(!v2d1.isTowardLeft());
    ASSERT(v2d1.isTowardUp());
    ASSERT(!v2d1.isTowardDown());

    Vector2D v2d2(Vector(Point(1, -1)), Point(1, 1));
    ASSERT(v2d2.isTowardRight());
    ASSERT(!v2d2.isTowardLeft());
    ASSERT(!v2d2.isTowardUp());
    ASSERT(v2d2.isTowardDown());
    Point ip;
    bool result;
    result = v2d1.calcIntersectPoint(v2d2, &ip);
    ASSERT(result);
    ASSERT(ip == Point(1, 1));

    Vector2D v2d3(Vector(Point(2, 2)), Point(0, 0));
    Point p7(1, 0);
    ASSERT(v2d3.cross(p7) < 0);
    p7 = Point(0, 1);
    ASSERT(v2d3.cross(p7) > 0);
    p7 = Point(1, 1);
    ASSERT(v2d3.cross(p7) == 0);
    v2d3 = Vector2D(Vector(Point(2, 2)), Point(2, 2));
    p7 = Point(1, 0);
    ASSERT(v2d3.cross(p7) < 0);
    p7 = Point(0, 1);
    ASSERT(v2d3.cross(p7) > 0);
    p7 = Point(1, 1);
    ASSERT(v2d3.cross(p7) == 0);
    v2d3 = Vector2D(Vector(Point(2, 2)), Point(-2, -2));
    p7 = Point(1, 0);
    ASSERT(v2d3.cross(p7) < 0);
    p7 = Point(0, 1);
    ASSERT(v2d3.cross(p7) > 0);
    p7 = Point(1, 1);
    ASSERT(v2d3.cross(p7) == 0);

    TestForKonaRect();
    TestForKonaCircle();

    cout << endl;
    if (failedCaseExists) {
        cout << "there's failed case!" << endl;
        return 1;
    }
    cout << "all assertion passed!" << endl;
    return 0;
}
