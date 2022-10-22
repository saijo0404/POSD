#include "../../src/visitor/collision_detector.h"

TEST(CollisionTest, VisitCircle) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    
    Shape *dart = new Circle(vec1); // the target shape
    Shape *bullseyes = new Circle(vec1);; // the shapes composed of a tree structure
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    ASSERT_EQ(bullseyes,scores[0]);
}

TEST(CollisionTest, VisitTriangle) {
    Point* point1 = new Point(0, 0);
    Point* point2 = new Point(3, 0);
    Point* point3 = new Point(3, 4);
    TwoDimensionalVector* vec1 = new TwoDimensionalVector(point1, point2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(point1, point3);

    Shape *dart = new Triangle(vec1, vec2); // the target shape
    Shape *bullseyes = new Triangle(vec1, vec2);; // the shapes composed of a tree structure
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    ASSERT_EQ(bullseyes,scores[0]);
}

TEST(CollisionTest, VisitRectangle) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-5, 0);
    TwoDimensionalVector* vec1 = new TwoDimensionalVector(&point1, &point2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(&point1, &point3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(&point1, &point4);

    Shape *dart = new Rectangle(vec1, vec2); // the target shape
    Shape *bullseyes = new Rectangle(vec1, vec3); // the shapes composed of a tree structure
    CollisionDetector* visitor = new CollisionDetector(dart);
    bullseyes->accept(visitor);
    std::vector<Shape *> scores = visitor->collidedShapes();
    ASSERT_EQ(bullseyes,scores[0]);
}

TEST(CollisionTest, VisitCompoundShape) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-5, 0);
    TwoDimensionalVector* vec1 = new TwoDimensionalVector(&point1, &point2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(&point1, &point3);

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
}

TEST(CollisionTest, VisitCompoundShape2) {
    Point point1(0, 0);
    Point point2(0, 5);
    Point point3(5, 0);
    Point point4(-7, 0);
    Point point5(-7, 1);
    Point point6(-8, 0);
    TwoDimensionalVector* vec1 = new TwoDimensionalVector(&point1, &point2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(&point1, &point3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(&point4, &point5);
    TwoDimensionalVector* vec4 = new TwoDimensionalVector(&point4, &point6);

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
}