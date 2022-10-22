#include "../src/circle.h"
#include "../src/iterator/factory/list_iterator_factory.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"


TEST(CircleTest, Radius) {
    Point point1(0, 0);
    Point point2(0, 1);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_NEAR(1, circle.radius(), 0.001);
}

TEST(CircleTest, Info) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_EQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))", circle.info());
}

TEST(CircleTest, Perimeter) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_NEAR(4.48773, circle.perimeter(), 0.001);
}

TEST(CircleTest, Area) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_NEAR(1.60267, circle.area(), 0.001);
}

TEST(CircleTest, CreateDFSIterator) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_TRUE(circle.createDFSIterator()->isDone());
}

TEST(CircleTest, CreateBFSIterator) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Circle circle(&twoDimensionalVector);

    ASSERT_TRUE(circle.createBFSIterator()->isDone());
}

TEST(CircleTest, AddShape) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Shape* circle = new Circle(&twoDimensionalVector);
    ASSERT_THROW(circle->addShape(circle),std::runtime_error);
}

TEST(CircleTest, DeleteShape) {
    Point point1(-4.284, 0.264);
    Point point2(-4.827, 0.728);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Shape* circle = new Circle(&twoDimensionalVector);
    ASSERT_THROW(circle->deleteShape(circle),std::runtime_error);
}

TEST(CircleTest, GetPoints) {
    Point point1(0, 0);
    Point point2(0, 5);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Shape* circle = new Circle(&twoDimensionalVector);

    std::set<const Point*> points = circle->getPoints();
    std::set<const Point*> truepoint;
    truepoint.insert(new Point(5,5));
    truepoint.insert(new Point(-5,-5));
    for ( std::set<const Point*>::const_iterator i = truepoint.begin(); i!=truepoint.end();i++ ) {
        bool flag = false;
        for ( std::set<const Point*>::const_iterator j = points.begin(); j!=points.end();j++ ){
            if ( (*i)->info()==(*j)->info() ){ flag = true; }
        }
        ASSERT_TRUE(flag);
    }
}

TEST(CircleTest, Factory) {
    Point point1(0, 0);
    Point point2(0, 5);
    TwoDimensionalVector twoDimensionalVector(&point1, &point2);
    Shape* circle = new Circle(&twoDimensionalVector);

    ASSERT_TRUE(circle->createIterator(new ListIteratorFactory())->isDone());
    ASSERT_TRUE(circle->createIterator(new DFSIteratorFactory())->isDone());
    ASSERT_TRUE(circle->createIterator(new BFSIteratorFactory())->isDone());
}