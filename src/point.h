#pragma once

#include <cmath>
#include <string> 

class Point
{
private:
    double _x;
    double _y;

public:
    Point(double x, double y) {
        _x = x;
        _y = y;
    }
    ~Point() {}

    double x() const { return _x; }

    double y() const { return _y; }

    bool operator==(const Point &pt) const {
        int multiplier = pow(10, 2);
        return ((int)(_x * multiplier + 0.5) / (multiplier * 1.0)==(int)(pt._x * multiplier + 0.5) / (multiplier * 1.0)) && ((int)(_y * multiplier + 0.5) / (multiplier * 1.0)==(int)(pt._y * multiplier + 0.5) / (multiplier * 1.0));
    }

    std::string info() const {
        std::ostringstream ostr;
        ostr << "(" << std::showpoint << std::setprecision(2) << std::fixed << _x << ", " << std::showpoint << std::setprecision(2) << std::fixed << _y <<")";
        std::string s = ostr.str();
        return s;
    }
};
