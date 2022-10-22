#include "../../src/iterator/list_compound_iterator.h"
#include "../../src/iterator/factory/list_iterator_factory.h"

TEST(ListCompoundIteratorTest, ConstructorWithListIteratorFactory) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);

    Shape* circle = new Circle(vec1);
    Shape* rectangle = new Rectangle(vec1,vec2);
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(circle);
    cs1->addShape(rectangle);

    Iterator* it = cs1->createIterator(new ListIteratorFactory());
    it->first();
    ASSERT_EQ(circle->area(), it->currentItem()->area());
    it->next();
    ASSERT_EQ(rectangle->area(), it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST(ListCompoundIteratorTest, Next) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);

    Shape* circle = new Circle(vec1);
    Shape* rectangle = new Rectangle(vec1,vec2);
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(circle);
    cs1->addShape(rectangle);

    Iterator* it = cs1->createIterator(new ListIteratorFactory());
    it->first();
    ASSERT_EQ(circle->area(), it->currentItem()->area());
    it->next();
    ASSERT_EQ(rectangle->area(), it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST(ListCompoundIteratorTest, CurrentItem) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);

    Shape* circle = new Circle(vec1);
    Shape* rectangle = new Rectangle(vec1,vec2);
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(circle);
    cs1->addShape(rectangle);

    Iterator* it = cs1->createIterator(new ListIteratorFactory());
    it->first();
    ASSERT_EQ(circle, it->currentItem());
    it->next();
    ASSERT_EQ(rectangle, it->currentItem());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST(ListCompoundIteratorTest, IsDone) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);

    Shape* circle = new Circle(vec1);
    Shape* rectangle = new Rectangle(vec1,vec2);
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(circle);
    cs1->addShape(rectangle);

    Iterator* it = cs1->createIterator(new ListIteratorFactory());
    it->first();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_TRUE(it->isDone());
}