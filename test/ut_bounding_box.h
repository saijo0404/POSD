#include <vector>
#include <set>
#include "../src/bounding_box.h"

class BoundingBoxTest : public ::testing::Test {
protected:
    Point *p1, *p2, *p3, *p4;
    std::set<Point> points;
    BoundingBox *bb;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);
        points.insert(*p1);
        points.insert(*p2);
        points.insert(*p3);
        points.insert(*p4);
        bb = new BoundingBox(points);
    }
    void TearDown() override
    {
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete bb;
    }
};

TEST_F(BoundingBoxTest, Constructor) {
    Point* max = new Point(5,5);
    Point* min = new Point(0,0);
    ASSERT_EQ(max->info(),bb->max().info());
    ASSERT_EQ(min->info(),bb->min().info());

    delete max;
    delete min;
}

TEST_F(BoundingBoxTest, Max) {
    Point* max = new Point(5,5);
    ASSERT_EQ(max->info(),bb->max().info());
    delete max;
}

TEST_F(BoundingBoxTest, Min) {
    Point* min = new Point(0,0);
    ASSERT_EQ(min->info(),bb->min().info());
    delete min;
}

TEST_F(BoundingBoxTest, CalMaximumPoint) {
    Point* max = new Point(5,5);
    Point result = bb->calMaximumPoint(points);
    ASSERT_EQ(max->info(),result.info());
    delete max;
}

TEST_F(BoundingBoxTest, CalMinimumPoint) {
    Point* min = new Point(0,0);
    Point result = bb->calMinimumPoint(points);
    ASSERT_EQ(min->info(),result.info());
    delete min;
}

TEST_F(BoundingBoxTest, RectangleBoundingBox) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(5, 5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    Shape* rectangle = new Rectangle(twoDimensionalVector1,twoDimensionalVector2);
    
    std::set<Point> points = rectangle->getPoints();
    BoundingBox* bb1 = new BoundingBox(points);

    Point result = bb1->calMinimumPoint(points);
    Point result1 = bb1->calMaximumPoint(points);
    ASSERT_EQ(point1.info(),result.info());
    ASSERT_EQ(point4.info(),result1.info());

    delete rectangle;
    delete bb1;
}

TEST_F(BoundingBoxTest, CircleBoundingBox) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 5);
    Point point4(-5, -5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector1);
    
    std::set<Point> points = circle->getPoints();
    BoundingBox* bb1 = new BoundingBox(points);

    Point result = bb1->calMinimumPoint(points);
    Point result1 = bb1->calMaximumPoint(points);
    ASSERT_EQ(point4.info(),result.info());
    ASSERT_EQ(point3.info(),result1.info());

    delete circle;
    delete bb1;
}

TEST_F(BoundingBoxTest, TriangleBoundingBox) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Shape* triangle = new Triangle(twoDimensionalVector1,twoDimensionalVector2);
    std::set<Point> points = triangle->getPoints();
    
    BoundingBox* bb1 = new BoundingBox(points);

    Point result = bb1->calMinimumPoint(points);
    Point result1 = bb1->calMaximumPoint(points);
    ASSERT_EQ(point1.info(),result.info());
    ASSERT_EQ(point3.info(),result1.info());

    delete triangle;
    delete bb1;
}

TEST_F(BoundingBoxTest, RectangleCollide) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(0, -5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    TwoDimensionalVector twoDimensionalVector3(point1, point4);
    Shape* rectangle1 = new Rectangle(twoDimensionalVector1,twoDimensionalVector2);
    Shape* rectangle2 = new Rectangle(twoDimensionalVector3,twoDimensionalVector2);
    BoundingBox* bb1 = new BoundingBox(rectangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(rectangle2->getPoints());
    
    ASSERT_TRUE(bb1->collide(bb2));
    delete rectangle1;
    delete rectangle2;
    delete bb1;
    delete bb2;
}

TEST_F(BoundingBoxTest, RectangleNotCollide) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-4, -4);
    Point point5(-4, -3);
    Point point6(-3, -4);

    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    TwoDimensionalVector twoDimensionalVector3(point4, point5);
    TwoDimensionalVector twoDimensionalVector4(point4, point6);
    Shape* rectangle1 = new Rectangle(twoDimensionalVector1,twoDimensionalVector2);
    Shape* rectangle2 = new Rectangle(twoDimensionalVector3,twoDimensionalVector4);
    BoundingBox* bb1 = new BoundingBox(rectangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(rectangle2->getPoints());
    
    ASSERT_FALSE(bb1->collide(bb2));
    delete rectangle1;
    delete rectangle2;
    delete bb1;
    delete bb2;
}

TEST_F(BoundingBoxTest, TriangleCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, -4);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    TwoDimensionalVector twoDimensionalVector3(point1, point4);
    Shape* triangle1 = new Triangle(twoDimensionalVector1,twoDimensionalVector2);
    Shape* triangle2 = new Triangle(twoDimensionalVector1,twoDimensionalVector3);
    BoundingBox* bb1 = new BoundingBox(triangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(triangle2->getPoints());
    
    ASSERT_TRUE(bb1->collide(bb2));
    delete triangle1;
    delete triangle2;
    delete bb1;
    delete bb2;
}

TEST_F(BoundingBoxTest, TriangleNotCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(-1, 0);
    Point point5(-4, 0);
    Point point6(-4, 4);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    TwoDimensionalVector twoDimensionalVector3(point4, point5);
    TwoDimensionalVector twoDimensionalVector4(point4, point6);
    Shape* triangle1 = new Triangle(twoDimensionalVector1,twoDimensionalVector2);
    Shape* triangle2 = new Triangle(twoDimensionalVector3,twoDimensionalVector4);
    BoundingBox* bb1 = new BoundingBox(triangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(triangle2->getPoints());
    
    ASSERT_FALSE(bb1->collide(bb2));
    delete triangle1;
    delete triangle2;
    delete bb1;
    delete bb2;
}

TEST_F(BoundingBoxTest, CircleCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(4, 0);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    Shape* circle1 = new Circle(twoDimensionalVector1);
    Shape* circle2 = new Circle(twoDimensionalVector2);
    BoundingBox* bb1 = new BoundingBox(circle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(circle2->getPoints());
    
    ASSERT_TRUE(bb1->collide(bb2));
    delete circle1;
    delete circle2;
    delete bb1;
    delete bb2;
}

TEST_F(BoundingBoxTest, CircleNotCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(0, -10);
    Point point4(0, -11);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Shape* circle1 = new Circle(twoDimensionalVector1);
    Shape* circle2 = new Circle(twoDimensionalVector2);
    BoundingBox* bb1 = new BoundingBox(circle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(circle2->getPoints());
    
    ASSERT_FALSE(bb1->collide(bb2));
    delete circle1;
    delete circle2;
    delete bb1;
    delete bb2;
}