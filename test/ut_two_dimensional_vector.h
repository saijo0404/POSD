#include "../src/two_dimensional_vector.h"

TEST(TwoDimensionalVectorTest, Constructor) {
    Point point1(-8.42, 3.42);
    Point point2(-3.38, 4.3);
    ASSERT_NO_THROW(TwoDimensionalVector twoDimensionalVector(&point1, &point2));
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    ASSERT_EQ(-8.42, twoDimensionalVector.a()->x());
    ASSERT_EQ(3.42, twoDimensionalVector.a()->y());
    ASSERT_EQ(-3.38, twoDimensionalVector.b()->x());
    ASSERT_EQ(4.3, twoDimensionalVector.b()->y());
}

TEST(TwoDimensionalVectorTest, Info) {
    Point point1(-8.42, 3.42);
    Point point2(-3.38, 4.3);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);

    ASSERT_EQ("Vector ((-8.42, 3.42), (-3.38, 4.30))", twoDimensionalVector.info());
}

TEST(TwoDimensionalVectorTest, Length) {
    Point point1(-8.42, 3.42);
    Point point2(-3.38, 4.3);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);

    ASSERT_NEAR(5.1162, twoDimensionalVector.length(), 0.001);
}

TEST(TwoDimensionalVectorTest, Dot) {
    Point point1(0, 0);
    Point point2(3, 0);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    ASSERT_NEAR(0, twoDimensionalVector.dot(&twoDimensionalVector2), 0.001);
}

TEST(TwoDimensionalVectorTest, Cross) {
    Point point1(-8.42, 3.42);
    Point point2(-3.38, 4.3);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);

    ASSERT_NEAR(0, twoDimensionalVector.cross(&twoDimensionalVector),0.001);
}