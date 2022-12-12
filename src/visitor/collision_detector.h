#pragma once

#include "shape_visitor.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include "../bounding_box.h"
#include "../iterator/factory/bfs_iterator_factory.h"
#include <vector>

class CollisionDetector : public ShapeVisitor {
private:
    Shape* detectionShape ;
    std::vector<Shape *> _collideResult;
    BoundingBox *_targetBoundingBox;

public:
    CollisionDetector(Shape *shape) {
        detectionShape = shape;
        _targetBoundingBox = new BoundingBox(shape->getPoints());
    }

    ~CollisionDetector() { delete _targetBoundingBox; }

    void visitCircle(Circle *circle) override {
        BoundingBox* bb = new BoundingBox(circle->getPoints());
        if ( _targetBoundingBox->collide(bb) ){ _collideResult.push_back(circle); }
        delete bb;
    }

    void visitTriangle(Triangle *triangle) override {
        BoundingBox* bb = new BoundingBox(triangle->getPoints());
        if ( _targetBoundingBox->collide(bb) ){ _collideResult.push_back(triangle); }
        delete bb;
    }

    void visitRectangle(Rectangle *rectangle) override {
        BoundingBox* bb = new BoundingBox(rectangle->getPoints());
        if ( _targetBoundingBox->collide(bb) ){ _collideResult.push_back(rectangle); }
        delete bb;
    }

    void visitCompoundShape(CompoundShape *compoundShape) override {
        Iterator* it = compoundShape->createIterator(IteratorFactory::getInstance("List"));
        for ( it->first();!it->isDone();it->next() ) {
            BoundingBox* bb = new BoundingBox(it->currentItem()->getPoints());
            if ( _targetBoundingBox->collide(bb) ){
                it->currentItem()->accept(this);
            }
            delete bb;
        }
        delete it;
    }

    std::vector<Shape *> collidedShapes() const { return _collideResult; }
};