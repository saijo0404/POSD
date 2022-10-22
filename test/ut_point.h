#include "../src/point.h"

TEST(PointTest, Info) {
    Point point(-4.586, -3.471);

    ASSERT_EQ("(-4.59, -3.47)", point.info());
}

TEST(PointTest, X) {
    Point point(-4.586, -3.471);

    ASSERT_NEAR(-4.586, point.x(), 0.001);
}

TEST(PointTest, Y) {
    Point point(-4.586, -3.471);

    ASSERT_NEAR(-3.471, point.y(), 0.001);
}

TEST(PointTest, OperatorTrue) {
    Point point1(-4.586, -3.471);
    Point point2(-4.586, -3.471);

    ASSERT_EQ(true, point1==point2);
}

TEST(PointTest, OperatorFalse) {
    Point point1(-4.586, -3.471);
    Point point2(-4.586, -2.471);
    
    ASSERT_EQ(false, point1==point2);
}