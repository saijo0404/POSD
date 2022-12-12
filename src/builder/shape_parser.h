#pragma once
#include "./scanner.h"
#include "./shape_builder.h"
#include "../two_dimensional_vector.h"
#include <string>
#include <vector>

class ShapeParser{
private:
    Scanner *_scanner;
    ShapeBuilder *_builder;

public:
    ShapeParser(std::string input) {
        _scanner = new Scanner(input);
        _builder = new ShapeBuilder();
    }

    ~ShapeParser() {
        delete _scanner;
        delete _builder;
    }

    void parseCircle() {
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="Vector" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px1 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py1 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px2 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py2 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        Point p1(px1, py1);
        Point p2(px2, py2);
        _builder->buildCircle(p1, p2);
    }

    void parseTriangle() {
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="Vector" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px1 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py1 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px2 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py2 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        if ( _scanner->next()!="Vector" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px3 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py3 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px4 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py4 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        Point p1(px1, py1);
        Point p2(px2, py2);
        Point p3(px3, py3);
        Point p4(px4, py4);
        if ( p1.info()==p3.info() ){ _builder->buildTriangle(p1, p2, p4); }
        if ( p1.info()==p4.info() ){ _builder->buildTriangle(p1, p2, p3); }
        if ( p2.info()==p3.info() ){ _builder->buildTriangle(p2, p1, p4); }
        if ( p2.info()==p4.info() ){ _builder->buildTriangle(p2, p1, p4); }
    }

    void parseRectangle() {
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="Vector" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px1 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py1 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px2 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py2 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        if ( _scanner->next()!="Vector" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px3 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py3 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        double px4 = _scanner->nextDouble();
        if ( _scanner->next()!="," ){ throw std::string("error"); }
        double py4 = _scanner->nextDouble();
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        if ( _scanner->next()!=")" ){ throw std::string("error"); }
        Point p1(px1, py1);
        Point p2(px2, py2);
        Point p3(px3, py3);
        Point p4(px4, py4);
        if ( p1.info()==p3.info() ){ _builder->buildRectangle(p1, p2, p4); }
        if ( p1.info()==p4.info() ){ _builder->buildRectangle(p1, p2, p3); }
        if ( p2.info()==p3.info() ){ _builder->buildRectangle(p2, p1, p4); }
        if ( p2.info()==p4.info() ){ _builder->buildRectangle(p2, p1, p4); }
    }

    void parseCompoundShape(){
        if ( _scanner->next()!="(" ){ throw std::string("error"); }
        _builder->buildCompoundShape();
        std::string token;
        while (true){
            token = _scanner->next();
            if ( token=="Circle" ) { parseCircle(); }
            if ( token=="Triangle" ) { parseTriangle(); }
            if ( token=="Rectangle" ) { parseRectangle(); }
            if ( token=="CompoundShape" ) { parseCompoundShape(); }
            token = _scanner->next();
            if ( token!="," ) { break; }
        }
        if ( token!=")" ) { throw std::string("error"); }
        _builder->buildCompoundEnd();
    }

    void parse() {
        while( !_scanner->isDone() ) {
            std::string token = _scanner->next();
            if ( token=="Circle" ) { parseCircle(); }
            if ( token=="Triangle" ) { parseTriangle(); }
            if ( token=="Rectangle" ) { parseRectangle(); }
            if ( token=="CompoundShape" ) { parseCompoundShape(); }
        }
    }

    std::vector<Shape*> getResult() { return _builder->getResult(); }
};