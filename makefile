.PHONY: clean test

all: directories ut_main

TEST = test/ut_point.h \
		test/ut_two_dimensional_vector.h \
		test/ut_triangle.h \
		test/ut_rectangle.h \
		test/ut_circle.h \
		test/ut_shape.h

SRC = src/point.h \
		src/two_dimensional_vector.h \
		src/triangle.h \
		src/rectangle.h \
		src/circle.h \
		src/shape.h

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++17 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

test: all
	bin/ut_all
