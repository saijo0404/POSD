#include "../../src/builder/shape_builder.h"
#include "../../src/builder/scanner.h"
#include "../../src/builder/shape_parser.h"

TEST(PaserTest, Paser) {
    std::string input = "CompoundShape (Circle (Vector ((0.00, 0.00), (5.00, 0.00))), CompoundShape (Triangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00)))))";
    ShapeBuilder builder;
    Scanner scanner;
    ShapeParser parser(input);
    parser.parse();
    std::vector<Shape*> results = parser.getResult();
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (5.00, 0.00))), CompoundShape (Triangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00)))))", results.at(0)->info());
}

TEST(PaserTest, MultiPaser) {
    std::string input = "Circle (Vector ((0.00, 0.00), (5.00, 0.00))), CompoundShape (Triangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))))";
    ShapeBuilder builder;
    Scanner scanner;
    ShapeParser parser(input);
    parser.parse();
    std::vector<Shape*> results = parser.getResult();
    ASSERT_EQ("Circle (Vector ((0.00, 0.00), (5.00, 0.00)))", results.at(0)->info());
    ASSERT_EQ("CompoundShape (Triangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))))", results.at(1)->info());
}