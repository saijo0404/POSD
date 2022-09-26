#include "../src/rectangle.h"

TEST(RectangleTest, testRule) {
    Point point1(0, 0);
    Point point2(0, 3);
    Point point3(0, 0);
    Point point4(1, 3);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);

    ASSERT_THROW(Rectangle rectangle(&twoDimensionalVector1,&twoDimensionalVector2), std::runtime_error);
}
TEST(RectangleTest, testInfo) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Rectangle rectangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_EQ("Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))", rectangle.info());
}

TEST(RectangleTest, testPerimeter) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Rectangle rectangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_NEAR(14.1596, rectangle.perimeter(), 0.001);
}

TEST(RectangleTest, testArea) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Rectangle rectangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_NEAR(12.5309, rectangle.area(), 0.001);
}