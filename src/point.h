#pragma once

#include <cmath>
#include <string>

class Point {
private:
    double _x;
    double _y;

public:
    Point(double x, double y) : _x(x), _y(y) {}
    ~Point() {}

    double x() const { return _x; }

    double y() const { return _y; }

    bool operator==(const Point &pt) const { return (fabs(_x - pt.x()) < 0.001) && (fabs(_y - pt.y()) < 0.001); }
    //bool operator==(const Point pt) const { return (fabs(_x - pt.x()) < 0.001) && (fabs(_y - pt.y()) < 0.001); }
    bool operator==(const Point* pt) const { return (fabs(_x - pt->x()) < 0.001) && (fabs(_y - pt->y()) < 0.001); }

    bool operator<(const Point &pt) const { return _x < pt.x() || (_x == pt.x() && _y < pt.y()); }

    std::string info() const {
        /*std::ostringstream ostr;
        ostr << "(" << std::showpoint << std::setprecision(2) << std::fixed << _x << ", " << std::showpoint << std::setprecision(2) << std::fixed << _y <<")";
        std::string s = ostr.str();
        return s;*/
        char info[100];
        sprintf(info, "(%.2f, %.2f)", _x, _y);
        return info;
    }
};
