#include "../../src/iterator/list_compound_iterator.h"
#include "../../src/iterator/factory/list_iterator_factory.h"

class ListCompoundIteratorTest : public ::testing::Test {
protected:
    Point *p1, *p2, *p3;
    TwoDimensionalVector *vec1, *vec2;
    Shape *cir1, *rect;
    CompoundShape *cs1, *cs2;
    Iterator *it;

    void SetUp() override {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);

        vec1 = new TwoDimensionalVector(*p1, *p2);
        vec2 = new TwoDimensionalVector(*p1, *p3);

        cir1 = new Circle(*vec1);
        rect = new Rectangle(*vec1, *vec2);

        Shape *shapes1[] = {cir1, rect};
        cs1 = new CompoundShape(shapes1, 2);

        it = cs1->createIterator(IteratorFactory::getInstance("List"));
    }

    void TearDown() override {
        delete it;
        delete cs1;
        delete p1;
        delete p2;
        delete p3;
        delete vec1;
        delete vec2;
    }
};

TEST_F(ListCompoundIteratorTest, ConstructorWithListIteratorFactory) {
    it->first();
    ASSERT_EQ(cir1->area(), it->currentItem()->area());
    it->next();
    ASSERT_EQ(rect->area(), it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(ListCompoundIteratorTest, Next) {
    it->first();
    ASSERT_EQ(cir1->area(), it->currentItem()->area());
    it->next();
    ASSERT_EQ(rect->area(), it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(ListCompoundIteratorTest, CurrentItem) {
    it->first();
    ASSERT_EQ(cir1, it->currentItem());
    it->next();
    ASSERT_EQ(rect, it->currentItem());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(ListCompoundIteratorTest, IsDone) {
    it->first();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(ListCompoundIteratorTest, GetInstance) {
    it->first();
    ASSERT_EQ(cir1->area(), it->currentItem()->area());
    it->next();
    ASSERT_EQ(rect->area(), it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}