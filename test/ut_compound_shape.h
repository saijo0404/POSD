#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/iterator/factory/list_iterator_factory.h"

class CompoundShapeTest : public ::testing::Test{
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    Shape *cir1, *cir2, *rect;
    CompoundShape *cs1, *cs2, *cs3;

    void SetUp() override {
        p1 = new Point(0, 0);
        p2 = new Point(0, 1);
        p3 = new Point(0, 3);
        p4 = new Point(1, 0);

        vec1 = new TwoDimensionalVector(*p1, *p2);
        vec2 = new TwoDimensionalVector(*p3, *p1);
        vec3 = new TwoDimensionalVector(*p1, *p4);
        cir1 = new Circle(*vec1);
        rect = new Rectangle(*vec2, *vec3);

        Shape *sp1[] = {cir1, rect};
        cs1 = new CompoundShape(sp1, 2);
    }

    void TearDown() override {
        delete cs1;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete vec1;
        delete vec2;
        delete vec3;
    }
};

TEST_F(CompoundShapeTest, Area) {
    ASSERT_NEAR(1 * 1 * M_PI + 3 * 1, cs1->area(), 0.01);
}

TEST_F(CompoundShapeTest, Perimeter) {
    ASSERT_NEAR(2 * 1 * M_PI + 8, cs1->perimeter(), 0.01);
}

TEST_F(CompoundShapeTest, Info) {
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 1.00))), Rectangle (Vector ((0.00, 3.00), (0.00, 0.00)), Vector ((0.00, 0.00), (1.00, 0.00))))", cs1->info());
}

TEST_F(CompoundShapeTest, AddAndDeleteShape) {
    Shape *shapes[] = {};
    CompoundShape *cs = new CompoundShape(shapes, 0);
    Shape *c1 = new Circle(*vec1);
    Shape *c2 = new Circle(*vec3);

    cs->addShape(c1);
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 1.00))))", cs->info());
    cs->addShape(c2);
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 1.00))), Circle (Vector ((0.00, 0.00), (1.00, 0.00))))", cs->info());
    cs->deleteShape(c2);
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 1.00))))", cs->info());

    delete cs;
}

TEST_F(CompoundShapeTest, GetPoint) {
    std::set<Point> points = cs1->getPoints();
    ASSERT_EQ(6,points.size());
    std::set<Point>::const_iterator it = points.begin();
    ASSERT_EQ("(-1.00, -1.00)",(*it).info());
    ++it;
    ASSERT_EQ("(0.00, 0.00)",(*it).info());
    ++it;
    ASSERT_EQ("(0.00, 3.00)",(*it).info());
    ++it;
    ASSERT_EQ("(1.00, 0.00)",(*it).info());
    ++it;
    ASSERT_EQ("(1.00, 1.00)",(*it).info());
    ++it;
    ASSERT_EQ("(1.00, 3.00)",(*it).info());
}

TEST_F(CompoundShapeTest, DFSIterator) {
    Iterator* it = cs1->createIterator(IteratorFactory::getInstance("DFS"));
    it ->first();
    ASSERT_EQ(1 * 1 * M_PI, it->currentItem()->area());
    it ->next();
    ASSERT_EQ(3 * 1 , it->currentItem()->area());
    it ->next();
    ASSERT_TRUE(it ->isDone());
    delete it;
}

TEST_F(CompoundShapeTest, BFSIterator) {
    Iterator* it = cs1->createIterator(IteratorFactory::getInstance("BFS"));
    it ->first();
    ASSERT_EQ(1 * 1 * M_PI, it->currentItem()->area());
    it ->next();
    ASSERT_EQ(3 * 1 , it->currentItem()->area());
    it ->next();
    ASSERT_TRUE(it ->isDone());
    delete it;
}
