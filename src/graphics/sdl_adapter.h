#pragma once

#include "./canvas.h"
#include "./sdl/sdl.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include <set>

class SDLAdapter : public Canvas
{
private:
    SDL *_sdl;

public:
    SDLAdapter(int width, int height, SDL *sdl) : _sdl(sdl) {
        if (width <= 0 || height <= 0) { throw "SDLAdapter error."; }
        _sdl->init(width, height);
    }

    void drawCircle(Circle *cir) override {
        std::set<Point> points = cir->getPoints();
        const Point &p1 = *std::next(points.begin(), 0);
        const Point &p2 = *std::next(points.begin(), 1);
        double x = (p1.x() + p2.x()) / 2;
        double y = (p1.y() + p2.y()) / 2;
        double radius = cir->radius();
        _sdl->renderDrawCircle(x, y, radius);
    }

    void drawTriangle(Triangle *tri) override {
        std::set<Point> points = tri->getPoints();
        double *pxpy = new double[6];
        int i = 0;
        for (std::set<Point>::iterator it = points.begin(); it != points.end(); it++){
            pxpy[i] = (*it).x();
            pxpy[i + 1] = (*it).y();
            i += 2;
        }
        _sdl->renderDrawLines(pxpy, 6);
    }

    void drawRectangle(Rectangle *rect) override {
        std::set<Point> points = rect->getPoints();
        double *pxpy = new double[8];
        pxpy[0] = (*std::prev(points.begin(), -0)).x();
        pxpy[1] = (*std::prev(points.begin(), -0)).y();
        pxpy[2] = (*std::prev(points.begin(), -1)).x();
        pxpy[3] = (*std::prev(points.begin(), -1)).y();
        pxpy[4] = (*std::prev(points.begin(), -3)).x();
        pxpy[5] = (*std::prev(points.begin(), -3)).y();
        pxpy[6] = (*std::prev(points.begin(), -2)).x();
        pxpy[7] = (*std::prev(points.begin(), -2)).y();
        _sdl->renderDrawLines(pxpy, 8);
    }

    void display() override { _sdl->renderPresent(); }
};
