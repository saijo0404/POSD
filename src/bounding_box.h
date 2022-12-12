#pragma once

#include <set>
#include <string>
#include <cfloat>
#include "shape.h"

class BoundingBox {
private:
    Point _max;
    Point _min;

public:
    BoundingBox(std::set<Point> points) : _max(calMaximumPoint(points)), _min(calMinimumPoint(points)){
        //_max = calMaximumPoint(points);
        //_min = calMinimumPoint(points);
    }

    ~BoundingBox() {
        /*delete _max;
        delete _min;*/
    }

    Point calMaximumPoint(std::set<Point> &points) {
        double tmpx = -1*DBL_MAX;
        double tmpy = -1*DBL_MAX;
        for (std::set<Point>::const_iterator it = points.begin(); it != points.end(); it++) {
            if ( tmpx < (*it).x() ) { tmpx = (*it).x(); }
            if ( tmpy < (*it).y() ) { tmpy = (*it).y(); }
        }
        Point tmp(tmpx,tmpy);
        return tmp;
    }

    Point calMinimumPoint(std::set<Point> &points) {
        double tmpx = DBL_MAX;
        double tmpy = DBL_MAX;
        for (std::set<Point>::const_iterator it = points.begin(); it != points.end(); it++) { 
            if ( tmpx > (*it).x() ) { tmpx = (*it).x(); }
            if ( tmpy > (*it).y() ) { tmpy = (*it).y(); }
        } 
        Point tmp(tmpx,tmpy);
        return tmp;
        //return new Point(tmpx,tmpy);
    }

    Point max() { return _max; }

    Point min() { return _min; }

    bool collide(BoundingBox *box) {
        if ( (_max.x() < box->min().x()) || (_min.x() > box->max().x()) || (_max.y() < box->min().y()) || (_min.y() > box->max().y()) ){
            return false;
        }
        return true;
    }
};