
#ifndef KONACIRCLE_H
#define KONACIRCLE_H

#include "KonaPoint.h"
#include "KonaVector2D.h"

namespace Kona {

class Circle {
    private:
        Point center;
        float radius;

    public:
        Circle();
        Circle(Point, float);
        Circle& operator=(Circle);
        int intersectsVector2D(Vector2D, Point* out_p1, Point* out_p2);
        void show();
};

} // end of namespace

#endif /* KONACIRCLE_H */
