#include "../../src/shape.h"
#include "../../src/rectangle.h"
#include "../../src/compound_shape.h"
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/factory/dfs_iterator_factory.h"


class DFSCompoundIteratorTest : public ::testing::Test {
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    CompoundShape *cs1, *cs2;
    Iterator* it;

    void SetUp() override{
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(*p1, *p2);
        vec2 = new TwoDimensionalVector(*p1, *p3);
        vec3 = new TwoDimensionalVector(*p1, *p4);

        cs1 = new CompoundShape();
        cs1->addShape(new Circle(*vec1));
        cs1->addShape(new Rectangle(*vec1,*vec2));

        cs2 = new CompoundShape();
        cs2->addShape(new Circle(*vec3));
        cs2->addShape(cs1);

        it = cs2->createIterator(IteratorFactory::getInstance("DFS"));
    }

    void TearDown() override{
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

TEST_F(DFSCompoundIteratorTest, CurrentItemShouldBeCorrect) { 
    // ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area()); 
}

TEST_F(DFSCompoundIteratorTest, NextShouldBeCorrect) {
    it->next();
    ASSERT_EQ(5 * 5 * M_PI + 25, it->currentItem()->area());
}

TEST_F(DFSCompoundIteratorTest, IsDoneShouldBeCorrect) {
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(DFSCompoundIteratorTest, CurrentItemShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->next());
}

TEST_F(DFSCompoundIteratorTest, NextShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->currentItem());
}