#include "../src/bounding_box.h"

TEST(BoundingBoxTest, Constructor) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    std::set<const Point*> points;
    points.insert(p1);
    points.insert(p2);
    points.insert(p3);
    points.insert(p4);
    BoundingBox* bb = new BoundingBox(points);

    Point* max = new Point(5,5);
    Point* min = new Point(0,0);
    ASSERT_EQ(max->info(),bb->max()->info());
    ASSERT_EQ(min->info(),bb->min()->info());
}

TEST(BoundingBoxTest, Max) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    std::set<const Point*> points;
    points.insert(p1);
    points.insert(p2);
    points.insert(p3);
    points.insert(p4);
    BoundingBox* bb = new BoundingBox(points);

    Point* max = new Point(5,5);
    ASSERT_EQ(max->info(),bb->max()->info());
}

TEST(BoundingBoxTest, Min) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    std::set<const Point*> points;
    points.insert(p1);
    points.insert(p2);
    points.insert(p3);
    points.insert(p4);
    BoundingBox* bb = new BoundingBox(points);

    Point* min = new Point(0,0);
    ASSERT_EQ(min->info(),bb->min()->info());
}

TEST(BoundingBoxTest, CalMaximumPoint) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    std::set<const Point*> points;
    points.insert(p1);
    points.insert(p2);
    points.insert(p3);
    points.insert(p4);
    BoundingBox* bb = new BoundingBox(points);

    Point* max = new Point(5,5);
    ASSERT_EQ(max->info(),bb->calMaximumPoint(points)->info());
}

TEST(BoundingBoxTest, CalMinimumPoint) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    std::set<const Point*> points;
    points.insert(p1);
    points.insert(p2);
    points.insert(p3);
    points.insert(p4);
    BoundingBox* bb = new BoundingBox(points);

    Point* max = new Point(0,0);
    ASSERT_EQ(max->info(),bb->calMinimumPoint(points)->info());
}

TEST(BoundingBoxTest, RectangleBoundingBox) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(5, 5);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point1, &point3);
    Shape* rectangle = new Rectangle(&twoDimensionalVector1,&twoDimensionalVector2);
    
    std::set<const Point*> points = rectangle->getPoints();
    BoundingBox* bb = new BoundingBox(points);

    ASSERT_EQ(point1.info(),bb->calMinimumPoint(points)->info());
    ASSERT_EQ(point4.info(),bb->calMaximumPoint(points)->info());
}

TEST(BoundingBoxTest, CircleBoundingBox) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 5);
    Point point4(-5, -5);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    Shape* circle = new Circle(&twoDimensionalVector1);
    
    std::set<const Point*> points = circle->getPoints();
    BoundingBox* bb = new BoundingBox(points);

    ASSERT_EQ(point4.info(),bb->calMinimumPoint(points)->info());
    ASSERT_EQ(point3.info(),bb->calMaximumPoint(points)->info());
}

TEST(BoundingBoxTest, TriangleBoundingBox) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Shape* triangle = new Triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    std::set<const Point*> points = triangle->getPoints();
    
    BoundingBox* bb = new BoundingBox(points);

    ASSERT_EQ(point1.info(),bb->calMinimumPoint(points)->info());
    ASSERT_EQ(point3.info(),bb->calMaximumPoint(points)->info());
}

TEST(BoundingBoxTest, RectangleCollide) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(0, -5);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point1, &point3);
    TwoDimensionalVector twoDimensionalVector3(&point1, &point4);
    Shape* rectangle1 = new Rectangle(&twoDimensionalVector1,&twoDimensionalVector2);
    Shape* rectangle2 = new Rectangle(&twoDimensionalVector3,&twoDimensionalVector2);
    BoundingBox* bb1 = new BoundingBox(rectangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(rectangle2->getPoints());
    
    ASSERT_TRUE(bb1->collide(bb2));
}

TEST(BoundingBoxTest, RectangleNotCollide) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-4, -4);
    Point point5(-4, -3);
    Point point6(-3, -4);

    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point1, &point3);
    TwoDimensionalVector twoDimensionalVector3(&point4, &point5);
    TwoDimensionalVector twoDimensionalVector4(&point4, &point6);
    Shape* rectangle1 = new Rectangle(&twoDimensionalVector1,&twoDimensionalVector2);
    Shape* rectangle2 = new Rectangle(&twoDimensionalVector3,&twoDimensionalVector4);
    BoundingBox* bb1 = new BoundingBox(rectangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(rectangle2->getPoints());
    
    ASSERT_FALSE(bb1->collide(bb2));
}

TEST(BoundingBoxTest, TriangleCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, -4);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point1, &point3);
    TwoDimensionalVector twoDimensionalVector3(&point1, &point4);
    Shape* triangle1 = new Triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    Shape* triangle2 = new Triangle(&twoDimensionalVector1,&twoDimensionalVector3);
    BoundingBox* bb1 = new BoundingBox(triangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(triangle2->getPoints());
    
    ASSERT_TRUE(bb1->collide(bb2));
}

TEST(BoundingBoxTest, TriangleNotCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(-1, 0);
    Point point5(-4, 0);
    Point point6(-4, 4);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point1, &point3);
    TwoDimensionalVector twoDimensionalVector3(&point4, &point5);
    TwoDimensionalVector twoDimensionalVector4(&point4, &point6);
    Shape* triangle1 = new Triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    Shape* triangle2 = new Triangle(&twoDimensionalVector3,&twoDimensionalVector4);
    BoundingBox* bb1 = new BoundingBox(triangle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(triangle2->getPoints());
    
    ASSERT_FALSE(bb1->collide(bb2));
}

TEST(BoundingBoxTest, CircleCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(4, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point1, &point3);
    Shape* circle1 = new Circle(&twoDimensionalVector1);
    Shape* circle2 = new Circle(&twoDimensionalVector2);
    BoundingBox* bb1 = new BoundingBox(circle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(circle2->getPoints());
    
    ASSERT_TRUE(bb1->collide(bb2));
}

TEST(BoundingBoxTest, CircleNotCollide) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(0, -10);
    Point point4(0, -11);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Shape* circle1 = new Circle(&twoDimensionalVector1);
    Shape* circle2 = new Circle(&twoDimensionalVector2);
    BoundingBox* bb1 = new BoundingBox(circle1->getPoints());
    BoundingBox* bb2 = new BoundingBox(circle2->getPoints());
    
    ASSERT_FALSE(bb1->collide(bb2));
}