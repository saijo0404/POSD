#include "../../src/builder/scanner.h"

TEST(ScannerTest, Scanner) {

    std::string input = "CompoundShape (Circle (Vector ((0.00, 0.00), (5.00, 0.00))), CompoundShape (Triangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (5.00, 0.00)), Vector ((0.00, 0.00), (0.00, 5.00)))))";
    Scanner scanner(input);
    ASSERT_EQ("CompoundShape", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(5, scanner.nextDouble());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("CompoundShape", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Triangle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(5, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(5, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Rectangle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(5, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(5, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
}

TEST(ScannerTest, Next) {
    std::string input = "";
    Scanner scanner(input);
    ASSERT_ANY_THROW(scanner.next());
}

TEST(ScannerTest, NextDouble) {
    std::string input = "";
    Scanner scanner(input);
    ASSERT_ANY_THROW(scanner.nextDouble());
}