#pragma once

#include <set>
#include <string>

class BoundingBox
{
private:
    Point *_max;
    Point *_min;

public:
    BoundingBox(std::set<const Point *> points) {
        _max = calMaximumPoint(points);
        _min = calMinimumPoint(points);
    }

    Point *calMaximumPoint(const std::set<const Point *> points) {
        double tmpx = -1*DBL_MAX;
        double tmpy = -1*DBL_MAX;
        for (std::set<const Point *>::const_iterator it = points.begin(); it != points.end(); it++) {
            if ( tmpx < (*it)->x() ) { tmpx = (*it)->x(); }
            if ( tmpy < (*it)->y() ) { tmpy = (*it)->y(); }
        }
        _max = new Point(tmpx,tmpy);
        return _max;
    }

    Point *calMinimumPoint(const std::set<const Point *> points) {
        double tmpx = DBL_MAX;
        double tmpy = DBL_MAX;
        for (std::set<const Point *>::const_iterator it = points.begin(); it != points.end(); it++) { 
            if ( tmpx > (*it)->x() ) { tmpx = (*it)->x(); }
            if ( tmpy > (*it)->y() ) { tmpy = (*it)->y(); }
        } 
        _min = new Point(tmpx,tmpy);
        return _min;
    }

    const Point *max() { return _max; }

    const Point *min() { return _min; }

    bool collide(BoundingBox *box) {
        if ( (_max->x() < box->min()->x()) || (_min->x() > box->max()->x()) || (_max->y() < box->min()->y()) || (_min->y() > box->max()->y()) ){
            return false;
        }
        return true;
    }
};
