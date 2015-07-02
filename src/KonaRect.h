
#ifndef KONARECT_H
#define KONARECT_H

#include "KonaVector2D.h"

namespace Kona {

class Rect {
    private:
        Vector2D sides[4];

    public:
        enum RectSide {
            LEFT   = 0,
            RIGHT  = 1,
            TOP    = 2,
            BOTTOM = 3
        };
        Rect();
        Rect(Vector2D left, Vector2D right);
        bool containsPoint(Point);
        bool intersectsVector2D(Vector2D, Point* out_intersectPoint);
        void show();
};

} // end of namespace

#endif /* KONARECT_H */
