
#ifndef POINT_H
#define POINT_H

namespace Kona {

class Point {

public:
    int x;
    int y;

    Point() {
        this->x = 0;
        this->y = 0;
    };

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };

    Point&
    operator= (const Point& in_p) {
        if (this != &in_p) {
            this->x = in_p.x;
            this->y = in_p.y;
        }
        return *this;
    }

    bool
    operator== (const Point& in_p) {
       return this->x == in_p.x && this->y == in_p.y;
    }

    bool
    operator!= (const Point& in_p) {
       return this->x != in_p.x || this->y != in_p.y;
    }

};

} // end of namespace

#endif /* POINT_H */
