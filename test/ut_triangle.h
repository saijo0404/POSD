#include "../src/triangle.h"

TEST(TriangleTest, testIllegalTriangle) {
    Point point1(5, 8);
    Point point2(8, 11);
    Point point3(5, 11);
    Point point4(6, 12);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    
    ASSERT_THROW(Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2), std::runtime_error);
}

TEST(TriangleTest, testInfo) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))", triangle.info());
}

TEST(TriangleTest, testPerimeter) {
    Point point1(1.777, 0);
    Point point2(3, 0);
    Point point3(2, 1.77777);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_NEAR(5.054423835604, triangle.perimeter(), 0.001);
}

TEST(TriangleTest, testArea) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_NEAR(6, triangle.area(), 0.001);
}