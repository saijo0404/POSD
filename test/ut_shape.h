#include "../src/shape.h"
#include "../src/circle.h"

TEST(ShapeTest, Info) {
    Shape* circle = new Circle(new TwoDimensionalVector(new Point(1.3449, -1.999), new Point(6.0, 7)));

    ASSERT_EQ("Circle (Vector ((1.34, -2.00), (6.00, 7.00)))", circle->info());
}

TEST(ShapeTest, Area) {
    Shape* circle = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(0, 1)));

    ASSERT_NEAR(1 * 1 * M_PI, circle->area(), 0.01);
}

TEST(ShapeTest, Perimeter) {
    Shape* circle = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(0, 1)));

    ASSERT_NEAR(2 * 1 * M_PI, circle->perimeter(), 0.01);
}