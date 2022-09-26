#include "../src/point.h"

TEST(PointTest, testInfo) {
    Point point(-4.586, -3.471);

    ASSERT_EQ("(-4.59, -3.47)", point.info());
}

TEST(PointTest, testOperatorTrue) {
    Point point1(-4.586, -3.471);
    Point point2(-4.586, -3.471);

    ASSERT_EQ(true, point1==point2);
}

TEST(PointTest, testOperatorFalse) {
    Point point1(-4.586, -3.471);
    Point point2(-4.586, -2.471);
    
    ASSERT_EQ(false, point1==point2);
}