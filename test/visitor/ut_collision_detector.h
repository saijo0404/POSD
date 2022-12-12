#include "../../src/visitor/collision_detector.h"

TEST(CollisionTest, VisitCircle) {
    Point p1(0, 0);
    Point p2(0, 5);
    Point p3(5, 0);

    TwoDimensionalVector vec1(p1, p2);
    TwoDimensionalVector vec2(p1, p3);
    
    Shape *dart = new Circle(vec1); // the target shape
    Shape *bullseyes = new Circle(vec1);; // the shapes composed of a tree structure
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    ASSERT_EQ(bullseyes,scores[0]);
    delete dart;
    delete bullseyes;
    delete visitor;
}

TEST(CollisionTest, VisitTriangle) {
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);
    TwoDimensionalVector vec1(point1, point2);
    TwoDimensionalVector vec2(point1, point3);

    Shape *dart = new Triangle(vec1, vec2); // the target shape
    Shape *bullseyes = new Triangle(vec1, vec2);; // the shapes composed of a tree structure
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    ASSERT_EQ(bullseyes,scores[0]);
    delete dart;
    delete bullseyes;
    delete visitor;
}

TEST(CollisionTest, VisitRectangle) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-5, 0);
    TwoDimensionalVector vec1(point1, point2);
    TwoDimensionalVector vec2(point1, point3);
    TwoDimensionalVector vec3(point1, point4);

    Shape *dart = new Rectangle(vec1, vec2); // the target shape
    Shape *bullseyes = new Rectangle(vec1, vec3); // the shapes composed of a tree structure
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    ASSERT_EQ(bullseyes,scores[0]);
    delete dart;
    delete bullseyes;
    delete visitor;
}

TEST(CollisionTest, VisitCompoundShape) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-5, 0);
    TwoDimensionalVector vec1(point1, point2);
    TwoDimensionalVector vec2(point1, point3);

    Shape* circle = new Circle(vec1);
    Shape* triangle = new Triangle(vec1, vec2);

    Shape *dart = new Rectangle(vec1, vec2); // the target shape
    Shape *bullseyes = new CompoundShape(); // the shapes composed of a tree structure
    bullseyes->addShape(circle);
    bullseyes->addShape(triangle);
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    std::vector<Shape *>::iterator it=scores.begin();
    ASSERT_EQ(circle,*it);
    ++it;
    ASSERT_EQ(triangle,*it);

    delete dart;
    delete bullseyes;
    delete visitor;
}

TEST(CollisionTest, VisitCompoundShape2) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-7, 0);
    Point point5(-7, 1);
    Point point6(-8, 0);
    TwoDimensionalVector vec1(point1, point2);
    TwoDimensionalVector vec2(point1, point3);
    TwoDimensionalVector vec3(point4, point5);
    TwoDimensionalVector vec4(point4, point6);

    Shape* circle = new Circle(vec1);
    Shape* triangle = new Triangle(vec1, vec2);

    Shape *dart = new Rectangle(vec3, vec4); // the target shape
    Shape *bullseyes = new CompoundShape(); // the shapes composed of a tree structure
    bullseyes->addShape(circle);
    bullseyes->addShape(triangle);
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    ASSERT_EQ(0,scores.size());

    delete dart;
    delete bullseyes;
    delete visitor;
}