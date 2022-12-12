#pragma once

#include <string>
#include <vector>

class Scanner {
private:
    std::string _input;
    std::string::size_type pos = 0;
    std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "Vector", "(", ")", ","};

public:
    Scanner(std::string input = ""): _input(input) {}

    void skipWhiteSpace() { while(_input[pos] == ' ') { pos++; } }

    std::string next() {
        std::string result = "";
        if ( isDone() ) { throw std::string("No more token to return"); }
        for( auto token : tokenList ) {
            if( _input.compare(pos,token.length(),token)==0 ) {
                pos += token.length();
                result = token;
                break;
            }
        }
        if( result=="" ) { pos++; }
        return result;
    }

    double nextDouble() {
        std::string result = "";
        double sign = 1.0;
        if ( isDone() ) { throw std::string("No more double to return"); }
        if ( _input[pos] == '-' ) { sign = -1; }
        while (true) {
            if( (_input[pos]<='9' && _input[pos]>='0' ) || _input[pos]=='.' ) {
                result = result + _input[pos];
                pos++;
            }
            else { break; }
        }
        if( result=="" ) { pos++; }
        while (true) {
            skipWhiteSpace();
            if( (_input[pos]<='9' && _input[pos]>='0' ) || _input[pos]=='.' ) {
                result = result + _input[pos];
                pos++;
            }
            else { break; }
        }
        return sign*std::stod(result);
    }

    bool isDone() {
        skipWhiteSpace();
        return pos == _input.length();
    }
};