#include "../src/compound_shape.h"

TEST(CompountShapeTest, Area) {
    std::list<Shape*> shapes = {
        new Circle(
         new TwoDimensionalVector(
                new Point(0, 0),
                new Point(0, 1)
            )
        ),
        new Rectangle(
            new TwoDimensionalVector(
                new Point(0, 3), new Point(0, 0)
            ),
            new TwoDimensionalVector(
                new Point(0, 0), new Point(1, 0)
            )
        )
    };
    CompoundShape compoundshape(shapes);

    ASSERT_NEAR(1 * 1 * M_PI + 3 * 1, compoundshape.area(), 0.01);
}

TEST(CompountShapeTest, Perimeter) {
    std::list<Shape*> shapes = {
        new Circle(
         new TwoDimensionalVector(
                new Point(0, 0),
                new Point(0, 1)
            )
        ),
        new Rectangle(
            new TwoDimensionalVector(
                new Point(0, 3), new Point(0, 0)
            ),
            new TwoDimensionalVector(
                new Point(0, 0), new Point(1, 0)
            )
        )
    };
    CompoundShape compoundshape(shapes);

    ASSERT_NEAR(2 * 1 * M_PI + 8, compoundshape.perimeter(), 0.01);
}

TEST(CompountShapeTest, Info) {
    std::list<Shape*> shapes = {
        new Circle(
         new TwoDimensionalVector(
                new Point(1.3449, -1.999),
                new Point(6.0, 7)
            )
        ),
        new Rectangle(
            new TwoDimensionalVector(
                new Point(-3, 3), new Point(-1, 3)
            ),
            new TwoDimensionalVector(
                new Point(-1, 3), new Point(-1, -1)
            )
        )
    };
    CompoundShape compoundshape(shapes);

    ASSERT_EQ("CompoundShape (Circle (Vector ((1.34, -2.00), (6.00, 7.00))), Rectangle (Vector ((-3.00, 3.00), (-1.00, 3.00)), Vector ((-1.00, 3.00), (-1.00, -1.00))))", compoundshape.info());
}

TEST(CompountShapeTest, DeleteShape) {
    std::list<Shape*> shapes = {
        new Circle(
         new TwoDimensionalVector(
                new Point(1.3449, -1.999),
                new Point(6.0, 7)
            )
        ),
        new Rectangle(
            new TwoDimensionalVector(
                new Point(-3, 3), new Point(-1, 3)
            ),
            new TwoDimensionalVector(
                new Point(-1, 3), new Point(-1, -1)
            )
        )
    };
    CompoundShape compoundshape(shapes);
    compoundshape.deleteShape(new Circle(new TwoDimensionalVector(new Point(1.3449, -1.999),new Point(6.0, 7))));

    ASSERT_EQ("CompoundShape (Rectangle (Vector ((-3.00, 3.00), (-1.00, 3.00)), Vector ((-1.00, 3.00), (-1.00, -1.00))))", compoundshape.info());
}

TEST(CompountShapeTest, AddShape) {
    std::list<Shape*> shapes = {
        new Circle(
         new TwoDimensionalVector(
                new Point(1.3449, -1.999),
                new Point(6.0, 7)
            )
        ),
        new Rectangle(
            new TwoDimensionalVector(
                new Point(-3, 3), new Point(-1, 3)
            ),
            new TwoDimensionalVector(
                new Point(-1, 3), new Point(-1, -1)
            )
        )
    };
    CompoundShape compoundshape(shapes);
    compoundshape.addShape(new Circle(new TwoDimensionalVector(new Point(1.3449, -1.999),new Point(6.0, 8))));

    ASSERT_EQ("CompoundShape (Circle (Vector ((1.34, -2.00), (6.00, 7.00))), Rectangle (Vector ((-3.00, 3.00), (-1.00, 3.00)), Vector ((-1.00, 3.00), (-1.00, -1.00))), Circle (Vector ((1.34, -2.00), (6.00, 8.00))))", compoundshape.info());
}

TEST(CompountShapeTest, DFSIterator) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(p1, p4);

    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec1));
    cs1->addShape(new Rectangle(vec1,vec2));

    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(vec3));
    cs2->addShape(cs1);

    Iterator* it = cs2->createDFSIterator();
    it ->first();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI + 25, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(25, it->currentItem()->area());
}

TEST(CompountShapeTest, BFSIterator) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);
    TwoDimensionalVector* vec3 = new TwoDimensionalVector(p1, p4);

    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec1));
    cs1->addShape(new Rectangle(vec1,vec2));

    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(vec3));
    cs2->addShape(cs1);

    Iterator* it = cs2->createBFSIterator();
    it ->first();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI + 25, it->currentItem()->area());
    it->next();
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
    it->next();
    ASSERT_EQ(25, it->currentItem()->area());
}

TEST(CompountShapeTest, GetPoint) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);

    TwoDimensionalVector* vec1 = new TwoDimensionalVector(p1, p2);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(p1, p3);

    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec1));
    cs1->addShape(new Rectangle(vec1,vec2));

    std::set<const Point*> result = cs1->getPoints();
    ASSERT_EQ(5,result.size());
}
