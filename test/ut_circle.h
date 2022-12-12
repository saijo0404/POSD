#include "../src/circle.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/factory/list_iterator_factory.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"

TEST(CircleTest, Radius) {
    Point point1(0, 0);
    Point point2(0, 1);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Circle circle(twoDimensionalVector);

    ASSERT_NEAR(1, circle.radius(), 0.001);
}

TEST(CircleTest, Info) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Circle circle(twoDimensionalVector);

    ASSERT_EQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))", circle.info());
}

TEST(CircleTest, Perimeter) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Circle circle(twoDimensionalVector);

    ASSERT_NEAR(4.48773, circle.perimeter(), 0.001);
}

TEST(CircleTest, Area) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Circle circle(twoDimensionalVector);

    ASSERT_NEAR(1.60267, circle.area(), 0.001);
}

TEST(CircleTest, AddShape) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector);
    ASSERT_ANY_THROW(circle->addShape(circle));
    delete circle;
}

TEST(CircleTest, DeleteShape) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector);
    ASSERT_ANY_THROW(circle->deleteShape(circle));
    delete circle;
}

TEST(CircleTest, GetPoints) {
    Point point1(0, 0);
    Point point2(0, 5);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector);

    std::set<Point> points = circle->getPoints();
    std::set<Point> truepoint;
    Point point3(-5,-5);
    Point point4(5,5);

    std::set<Point>::const_iterator it = points.begin();
    ASSERT_EQ(point3.info(),(*it).info());
    it++;
    ASSERT_EQ(point4.info(),(*it).info());
    delete circle;
}

TEST(CircleTest, Factory) {
    Point point1(0, 0);
    Point point2(0, 5);
    TwoDimensionalVector twoDimensionalVector(point1, point2);
    Shape* circle = new Circle(twoDimensionalVector);

    Iterator* it = circle->createIterator(IteratorFactory::getInstance("List"));
    ASSERT_TRUE(it->isDone());
    delete it;
    it = circle->createIterator(IteratorFactory::getInstance("DFS"));
    ASSERT_TRUE(it->isDone());
    delete it;
    it = circle->createIterator(IteratorFactory::getInstance("BFS"));
    ASSERT_TRUE(it->isDone());
    delete it;
    delete circle;
}