#include <iostream>
#include "../../src/iterator/factory/bfs_iterator_factory.h"

class BFSCompoundIteratorTest : public ::testing::Test
{
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    CompoundShape *cs1, *cs2;
    Iterator* it;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(p1, p2);
        vec2 = new TwoDimensionalVector(p1, p3);
        vec3 = new TwoDimensionalVector(p1, p4);

        cs1 = new CompoundShape();
        cs1->addShape(new Circle(vec1));
        cs1->addShape(new Rectangle(vec1,vec2));

        cs2 = new CompoundShape();
        cs2->addShape(new Circle(vec3));
        cs2->addShape(cs1);

        it = cs2->createBFSIterator();
    }

    void TearDown() override
    {
        delete cs2;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete vec1;
        delete vec2;
        delete vec3;
        delete it;
    }
};

TEST_F(BFSCompoundIteratorTest, CurrentItemShouldBeCorrect)
{
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
}

TEST_F(BFSCompoundIteratorTest, NextShouldBeCorrect)
{
    it->next();
    ASSERT_EQ(5 * 5 * M_PI + 25, it->currentItem()->area());
}

TEST_F(BFSCompoundIteratorTest, IsDoneShouldBeCorrect)
{
    it->next();
    it->next();
    it->next();
    it->next();

    ASSERT_TRUE(it->isDone());
}

TEST_F(BFSCompoundIteratorTest, CurrentItemShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->next());
}

TEST_F(BFSCompoundIteratorTest, NextShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();
    it->next();
    
    ASSERT_ANY_THROW(it->currentItem());
}

TEST_F(BFSCompoundIteratorTest, BFSOrderShouldBeCorrectIfNoChildrenInCompound){
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(p1, p4);

    CompoundShape* cs1 = new CompoundShape();

    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(vec3));
    cs2->addShape(cs1);

    Iterator* it = cs2->createBFSIterator();
    it ->first();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(0, it->currentItem()->area());
}

TEST_F(BFSCompoundIteratorTest, BFSOrderShouldBeCorrectIfACircleInCompound){
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(p1, p4);

    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec3));

    Iterator* it = cs1->createBFSIterator();
    it->first();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(BFSCompoundIteratorTest, BFSOrderShouldBeCorrectWithMultipleCompoundShapes){
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(p1, p4);

    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec3));
    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(vec1));
    CompoundShape* cs3 = new CompoundShape();
    cs3->addShape(cs1);
    cs3->addShape(cs2);

    Iterator* it = cs3->createBFSIterator();
    it->first();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(BFSCompoundIteratorTest, BFSOrderShouldBeCorrectWithComplicatedTreeStructure){
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(p1, p4);

    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec3));
    cs1->addShape(new Rectangle(vec1,vec2));
    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(vec1));
    cs2->addShape(new Rectangle(vec3,vec2));
    CompoundShape* cs3 = new CompoundShape();
    cs3->addShape(cs1);
    cs3->addShape(cs2);

    Iterator* it = cs3->createBFSIterator();
    it->first();
    ASSERT_EQ(3 * 3 * M_PI + 25, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI + 15, it->currentItem()->area());
    it->next();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(25, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(15, it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(BFSCompoundIteratorTest, FactoryBFSOrderShouldBeCorrectWithMultipleCompoundShapes){
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(p1, p4);

    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec3));
    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(vec1));
    CompoundShape* cs3 = new CompoundShape();
    cs3->addShape(cs1);
    cs3->addShape(cs2);

    Iterator* it = cs3->createIterator(new BFSIteratorFactory());
    it->first();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}