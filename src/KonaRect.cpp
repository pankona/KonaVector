
#include "KonaRect.h"
#include <iostream>

using namespace std;
using namespace Kona;

Rect::Rect() {
    sides[0] = Vector2D(Vector(Point(0, 0)), Point(0, 0));
    sides[1] = Vector2D(Vector(Point(0, 0)), Point(0, 0));
    sides[2] = Vector2D(Vector(Point(0, 0)), Point(0, 0));
    sides[3] = Vector2D(Vector(Point(0, 0)), Point(0, 0));
}

Rect::Rect(Vector2D in_left, Vector2D in_right) {
    sides[LEFT]   = Vector2D(in_left.getStartPosition(), in_left.getTerminalPosition());
    sides[RIGHT]  = Vector2D(in_right.getStartPosition(), in_right.getTerminalPosition());
    sides[TOP]    = Vector2D(in_left.getTerminalPosition(), in_right.getTerminalPosition());
    sides[BOTTOM] = Vector2D(in_left.getStartPosition(), in_right.getStartPosition());
}

bool
Rect::containsPoint(Point in_p) {
    if (sides[LEFT].cross(in_p)   <= 0 &&
        sides[RIGHT].cross(in_p)  >= 0 &&
        sides[TOP].cross(in_p)    <= 0 &&
        sides[BOTTOM].cross(in_p) >= 0) {
        return true;
    }

    return false;
}

bool
Rect::intersectsVector2D(Vector2D in_v2d, Point* out_intersectPoint) {

    if (in_v2d.calcIntersectPoint(sides[LEFT], out_intersectPoint)) {
        return true;
    } else if (in_v2d.calcIntersectPoint(sides[RIGHT], out_intersectPoint)) {
        return true;
    } else if (in_v2d.calcIntersectPoint(sides[TOP], out_intersectPoint)) {
        return true;
    } else if (in_v2d.calcIntersectPoint(sides[BOTTOM], out_intersectPoint)) {
        return true;
    }
    return false;
}

void
Rect::show() {
    cout << "LEFT  : "; sides[LEFT].show();
    cout << "RIGHT : "; sides[RIGHT].show();
    cout << "TOP   : "; sides[TOP].show();
    cout << "BOTTOM: "; sides[BOTTOM].show();
}
