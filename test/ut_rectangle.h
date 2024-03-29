#include "../src/rectangle.h"
#include "../src/iterator/factory/list_iterator_factory.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"

TEST(RectangleTest, Rule) {
    Point point1(0, 0);
    Point point2(0, 3);
    Point point3(0, 0);
    Point point4(1, 3);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);

    ASSERT_ANY_THROW(Rectangle rectangle(twoDimensionalVector1,twoDimensionalVector2));
}

TEST(RectangleTest, Info) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Rectangle rectangle(twoDimensionalVector1,twoDimensionalVector2);

    ASSERT_EQ("Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))", rectangle.info());
}

TEST(RectangleTest, Length) {
    Point point1(-2, 1);
    Point point2(-2, 3);
    Point point3(-2, 1);
    Point point4(-1, 1);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Rectangle rectangle(twoDimensionalVector1,twoDimensionalVector2);

    ASSERT_NEAR(2, rectangle.length(), 0.001);
}

TEST(RectangleTest, Width) {
    Point point1(-2, 1);
    Point point2(-2, 3);
    Point point3(-2, 1);
    Point point4(-1, 1);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Rectangle rectangle(twoDimensionalVector1,twoDimensionalVector2);

    ASSERT_NEAR(1, rectangle.width(), 0.001);
}

TEST(RectangleTest, Perimeter) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Rectangle rectangle(twoDimensionalVector1,twoDimensionalVector2);

    ASSERT_NEAR(14.1596, rectangle.perimeter(), 0.001);
}

TEST(RectangleTest, Area) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Rectangle rectangle(twoDimensionalVector1,twoDimensionalVector2);

    ASSERT_NEAR(12.5309, rectangle.area(), 0.001);
}

TEST(RectangleTest, AddShape) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Shape* rectangle = new Rectangle(twoDimensionalVector1,twoDimensionalVector2);
    ASSERT_ANY_THROW(rectangle->addShape(rectangle));
    delete rectangle;
}

TEST(RectangleTest, DeleteShape) {
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-2, 1);
    Point point4(-1.47, 4.5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point3, point4);
    Shape* rectangle = new Rectangle(twoDimensionalVector1,twoDimensionalVector2);
    ASSERT_ANY_THROW(rectangle->deleteShape(rectangle));
    delete rectangle;
}

TEST(RectangleTest, GetPoints) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(5, 5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    Shape* rectangle = new Rectangle(twoDimensionalVector1,twoDimensionalVector2);
    
    std::set<Point> points = rectangle->getPoints();

    ASSERT_NE(points.end(),points.find(point1));
    ASSERT_NE(points.end(),points.find(point2));
    ASSERT_NE(points.end(),points.find(point3));
    bool flag = false;
    for ( std::set<Point>::const_iterator i = points.begin(); i!=points.end();i++ ){
        if ( (*i).info()==point4.info() ){ flag = true; }
    }
    ASSERT_TRUE(flag);
    delete rectangle;
}

TEST(RectangleTest, Factory) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(5, 5);
    TwoDimensionalVector twoDimensionalVector1(point1, point2);
    TwoDimensionalVector twoDimensionalVector2(point1, point3);
    Shape* rectangle = new Rectangle(twoDimensionalVector1,twoDimensionalVector2);
    
    Iterator* it = rectangle->createIterator(IteratorFactory::getInstance("List"));
    ASSERT_TRUE(it->isDone());
    delete it;
    it = rectangle->createIterator(IteratorFactory::getInstance("DFS"));
    ASSERT_TRUE(it->isDone());
    delete it;
    it = rectangle->createIterator(IteratorFactory::getInstance("BFS"));
    ASSERT_TRUE(it->isDone());
    delete it;
    delete rectangle;
}