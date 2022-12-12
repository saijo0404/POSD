#include "../src/shape.h"
#include "../src/circle.h"

TEST(ShapeTest, Info) {
    Point point1(1.3449, -1.999);
    Point point2(6.0, 7);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector);

    ASSERT_EQ("Circle (Vector ((1.34, -2.00), (6.00, 7.00)))", circle->info());
    delete circle;
}

TEST(ShapeTest, Area) {
    Point point1(0, 0);
    Point point2(0, 1);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector);

    ASSERT_NEAR(1 * 1 * M_PI, circle->area(), 0.01);
    delete circle;
}

TEST(ShapeTest, Perimeter) {
    Point point1(0, 0);
    Point point2(0, 1);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector);

    ASSERT_NEAR(2 * 1 * M_PI, circle->perimeter(), 0.01);
    delete circle;
}