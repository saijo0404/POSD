#include "../../src/shape.h"
#include "../../src/rectangle.h"
#include "../../src/circle.h"
#include "../../src/triangle.h"
#include "../../src/compound_shape.h"
#include "../../src/graphics/sdl_adapter.h"
#include "mock_sdl_renderer.h"

class SDLAdapterTest : public ::testing::Test {
protected:
    MockSDLRenderer *mockSDLRenderer;

    void SetUp() override { mockSDLRenderer = new MockSDLRenderer(); }

    void TearDown() override { delete mockSDLRenderer; }
};

TEST_F(SDLAdapterTest, Init) {
    Canvas *canvas = new SDLAdapter(500, 500, mockSDLRenderer);
    ASSERT_TRUE(mockSDLRenderer->isInitCalled());
    delete canvas;
}

TEST_F(SDLAdapterTest, DrawCircle) {
    Point p1(0, 0), p2(1, 1);
    TwoDimensionalVector v(p1, p2);
    Circle cir(v);
    Canvas *canvas = new SDLAdapter(500, 500, mockSDLRenderer);
    canvas->drawCircle(&cir);
    const double *calledArgs = mockSDLRenderer->renderDrawCircleCalledArgs();
    ASSERT_NEAR(0, calledArgs[0], 0.001);
    ASSERT_NEAR(0, calledArgs[1], 0.001);
    ASSERT_NEAR(1.414, calledArgs[2], 0.001);
    delete canvas;
}

TEST_F(SDLAdapterTest, DrawTriangle) {
    Point p1(0, 0), p2(0, 3), p3(3,0);
    TwoDimensionalVector v1(p1, p2);
    TwoDimensionalVector v2(p1, p3);
    Triangle tri(v1,v2);
    Canvas *canvas = new SDLAdapter(500, 500, mockSDLRenderer);
    canvas->drawTriangle(&tri);
    double calledSize = mockSDLRenderer->renderDrawLinesCalledSize();
    ASSERT_EQ(6, calledSize);
    const double *calledPoints = mockSDLRenderer->renderDrawLinesCalledPoints();
    ASSERT_NEAR(0, calledPoints[0], 0.001);
    ASSERT_NEAR(0, calledPoints[1], 0.001);
    ASSERT_NEAR(0, calledPoints[2], 0.001);
    ASSERT_NEAR(3, calledPoints[3], 0.001);
    ASSERT_NEAR(3, calledPoints[4], 0.001);
    ASSERT_NEAR(0, calledPoints[5], 0.001);
    delete[] calledPoints;
    delete canvas;
}

TEST_F(SDLAdapterTest, DrawRectangle) {
    Point p1(0, 0), p2(0, 5), p3(5, 0);
    TwoDimensionalVector v1(p1, p2), v2(p1, p3);
    Rectangle rect(v1, v2);
    Canvas *canvas = new SDLAdapter(500, 500, mockSDLRenderer);
    canvas->drawRectangle(&rect);
    double calledSize = mockSDLRenderer->renderDrawLinesCalledSize();
    ASSERT_EQ(8, calledSize);
    const double *calledPoints = mockSDLRenderer->renderDrawLinesCalledPoints();
    ASSERT_NEAR(0, calledPoints[0], 0.001);
    ASSERT_NEAR(0, calledPoints[1], 0.001);
    ASSERT_NEAR(0, calledPoints[2], 0.001);
    ASSERT_NEAR(5, calledPoints[3], 0.001);
    ASSERT_NEAR(5, calledPoints[4], 0.001);
    ASSERT_NEAR(5, calledPoints[5], 0.001);
    ASSERT_NEAR(5, calledPoints[6], 0.001);
    ASSERT_NEAR(0, calledPoints[7], 0.001);
    delete[] calledPoints;
    delete canvas;
}

TEST_F(SDLAdapterTest, Display){
    Canvas *canvas = new SDLAdapter(500, 500, mockSDLRenderer);
    canvas->display();
    ASSERT_TRUE(mockSDLRenderer->isRenderPresentCalled());
    delete canvas;
}