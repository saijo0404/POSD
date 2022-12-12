#include "../../src/shape.h"
#include "../../src/rectangle.h"
#include "../../src/compound_shape.h"
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/factory/bfs_iterator_factory.h"

class BFSCompoundIteratorTest : public ::testing::Test {
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    Shape *cir1, *cir2, *rect;
    CompoundShape *cs1, *cs2, *cs3;
    Iterator *it;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(*p1, *p2);
        vec2 = new TwoDimensionalVector(*p1, *p3);
        vec3 = new TwoDimensionalVector(*p1, *p4);

        cir1 = new Circle(*vec1);
        cir2 = new Circle(*vec3);
        rect = new Rectangle(*vec1,*vec2); 

        cs1 = new CompoundShape();
        cs1->addShape(cir1);
        cs1->addShape(rect);

        cs2 = new CompoundShape();
        cs2->addShape(cir2);
        cs2->addShape(cs1);
        it = cs2->createIterator(IteratorFactory::getInstance("BFS"));
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

TEST_F(BFSCompoundIteratorTest, CurrentItemShouldBeCorrect){
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
}

TEST_F(BFSCompoundIteratorTest, NextShouldBeCorrect){
    it->next();
    ASSERT_EQ(5 * 5 * M_PI + 25, it->currentItem()->area());
}

TEST_F(BFSCompoundIteratorTest, IsDoneShouldBeCorrect){
    it->next();
    it->next();
    it->next();
    it->next();

    ASSERT_TRUE(it->isDone());
}

TEST_F(BFSCompoundIteratorTest, CurrentItemShouldThrowExceptionWhenIsDone){
    it->next();
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->next());
}

TEST_F(BFSCompoundIteratorTest, NextShouldThrowExceptionWhenIsDone){
    it->next();
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->currentItem());
}