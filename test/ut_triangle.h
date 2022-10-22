#include "../src/triangle.h"
#include "../src/iterator/factory/list_iterator_factory.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"

TEST(TriangleTest, IllegalTriangle) {
    Point point1(5, 8);
    Point point2(8, 11);
    Point point3(5, 11);
    Point point4(6, 12);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    
    ASSERT_THROW(Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2), std::runtime_error);
}

TEST(TriangleTest, Info) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))", triangle.info());
}

TEST(TriangleTest, Perimeter) {
    Point point1(1.777, 0);
    Point point2(3, 0);
    Point point3(2, 1.77777);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_NEAR(5.054423835604, triangle.perimeter(), 0.001);
}

TEST(TriangleTest, Area) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_NEAR(6, triangle.area(), 0.001);
}

TEST(TriangleTest, CreateDFSIterator) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_TRUE(triangle.createDFSIterator()->isDone());
}

TEST(TriangleTest, CreateBFSIterator) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Triangle triangle(&twoDimensionalVector1,&twoDimensionalVector2);

    ASSERT_TRUE(triangle.createBFSIterator()->isDone());
}

TEST(TriangleTest, AddShape) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Shape* triangle = new Triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    ASSERT_THROW(triangle->addShape(triangle),std::runtime_error);
}

TEST(TriangleTest, DeleteShape) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Shape* triangle = new Triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    ASSERT_THROW(triangle->deleteShape(triangle),std::runtime_error);
}

TEST(TriangleTest, GetPoints) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Shape* triangle = new Triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    std::set<const Point*> points = triangle->getPoints();

    ASSERT_NE(points.end(),points.find(&point1));
    ASSERT_NE(points.end(),points.find(&point2));
    ASSERT_NE(points.end(),points.find(&point3));
}

TEST(TriangleTest, Factory) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    Point point4(3, 0);
    TwoDimensionalVector twoDimensionalVector1(&point1, &point2);
    TwoDimensionalVector twoDimensionalVector2(&point3, &point4);
    Shape* triangle = new Triangle(&twoDimensionalVector1,&twoDimensionalVector2);
    
    ASSERT_TRUE(triangle->createIterator(new ListIteratorFactory())->isDone());
    ASSERT_TRUE(triangle->createIterator(new DFSIteratorFactory())->isDone());
    ASSERT_TRUE(triangle->createIterator(new BFSIteratorFactory())->isDone());
}