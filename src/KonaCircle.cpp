
#include "KonaCircle.h"
#include <iostream>
#include <cmath>
#include <float.h>

using namespace Kona;

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
                           Point* out_p1,
                           Point* out_p2) {
    //if( v.length>r ){
    //    //距離が半径より大きい場合、交点なし
    //    return [];
    //}else if( v.length<r ){
    //    //交点が２つ
    //    var drad:Number;
    //    var irad:Number;
    //    if( dv.length>0 ){
    //        //距離ベクトルの角度
    //        drad = Math.atan2( v.y, v.x );
    //        //距離ベクトルから交点の角度
    //        irad = Math.acos( v.length/r );
    //    }else{
    //        drad = Math.atan2( b, a );
    //        irad = Math.PI/2;
    //    }
    //    return [ new Point( x + r*Math.cos(drad+irad), y + r*Math.sin(drad+irad) ),
    //           new Point( x + r*Math.cos(drad-irad), y + r*Math.sin(drad-irad) ) ];
    //}else{
    //    //接線
    //    v.offset( x, y );
    //    return [ v ];
    //}

    float distance = in_v2d.distanceToPoint(this->center);

    if (distance < this->radius) {
        // there're two cross points
        std::cout << in_v2d.cross(this->center) << std::endl;
        return 2;
    }

    if (distance == this->radius) {
        // there's one cross point
        if(in_v2d.cross(this->center) > 0) {
            std::cout << "center is on left of vector2d" << std::endl;
        } else if (in_v2d.cross(this->center) < 0) {
            std::cout << "center is on right of vector2d" << std::endl;
        } else {
            std::cout << "center is on vector2d" << std::endl;
        }
    }

    return 0;
}
void
Circle::show() {
}

