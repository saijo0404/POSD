#pragma once

#include "../../../src/graphics/drag_and_drop/drag_and_drop.h"

class MockDragAndDrop : public DragAndDrop
{
private:
    double _dragX, _dragY;
    double _moveX, _moveY;
    double _dropX, _dropY;

public:
    void grab(double x, double y) override
    {
        _dragX = x;
        _dragY = y;
    }

    void move(double x, double y) override
    {
        _moveX = x;
        _moveY = y;
    }

    void drop(double x, double y) override
    {
        _dropX = x;
        _dropY = y;
    }

    double getDragX() const
    {
        return _dragX;
    }
    double getMoveX() const
    {
        return _moveX;
    }
    double getDropX() const
    {
        return _dropX;
    }
    double getDragY() const
    {
        return _dragY;
    }
    double getMoveY() const
    {
        return _moveY;
    }
    double getDropY() const
    {
        return _dropY;
    }
};