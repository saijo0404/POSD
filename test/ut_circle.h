#include "../src/circle.h"


TEST(CircleTest, testRadius) {
    Point point1(0, 0);
    Point point2(0, 1);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_NEAR(1, circle.radius(), 0.001);
}

TEST(CircleTest, testInfo) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_EQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))", circle.info());
}

TEST(CircleTest, testPerimeter) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_NEAR(4.48773, circle.perimeter(), 0.001);
}

TEST(CircleTest, testArea) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_NEAR(1.60267, circle.area(), 0.001);
}