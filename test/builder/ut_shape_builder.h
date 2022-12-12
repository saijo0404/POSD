#include "../../src/point.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/shape.h"
#include "../../src/builder/shape_builder.h"

TEST(BuilderTest, CicleBuilder) {
    const Point point1(0, 0);
    const Point point2(0, 1);

    ShapeBuilder builder;
    builder.buildCircle(point1,point2);
    
    ASSERT_EQ("Circle (Vector ((0.00, 0.00), (0.00, 1.00)))", builder.getResult()[0]->info());
    delete builder.getResult()[0];
}

TEST(BuilderTest, TriangleBuilder) {
    const Point point1(0, 0);
    const Point point2(3, 0);
    const Point point3(3, 4);

    ShapeBuilder builder;
    builder.buildTriangle(point1, point2, point3);
    
    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 0.00), (3.00, 4.00)))", builder.getResult()[0]->info());
    delete builder.getResult()[0];
}

TEST(BuilderTest, RectangleBuilder) {
    const Point point1(0, 0);
    const Point point2(5, 0);
    const Point point3(0, 5);

    ShapeBuilder builder;
    builder.buildRectangle(point1, point2, point3);
    
    ASSERT_EQ("Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00)))", builder.getResult()[0]->info());
    delete builder.getResult()[0];
}

TEST(BuilderTest, CompoundShapeBuilder) {
    const Point point1(0, 0);
    const Point point2(5, 0);
    const Point point3(0, 5);

    ShapeBuilder builder;
    builder.buildCompoundShape();
    builder.buildCircle(point1, point2);
    builder.buildCompoundShape();
    builder.buildTriangle(point1, point2, point3);
    builder.buildRectangle(point1, point2, point3);
    builder.buildCompoundEnd();
    builder.buildCompoundEnd();

    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (5.00, 0.00))), CompoundShape (Triangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00)))))", builder.getResult()[0]->info());
    delete builder.getResult()[0];
}

TEST(BuilderTest, MultiBuilder) {
    const Point point1(0, 0);
    const Point point2(5, 0);
    const Point point3(0, 5);

    ShapeBuilder builder;
    builder.buildRectangle(point1, point2, point3);
    
    const Point point4(0, 0);
    const Point point5(3, 0);
    const Point point6(3, 4);

    builder.buildTriangle(point4, point5, point6);
    ASSERT_EQ("Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00)))", builder.getResult()[0]->info());    
    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 0.00), (3.00, 4.00)))", builder.getResult()[1]->info());
    delete builder.getResult()[0];
    delete builder.getResult()[1];
}