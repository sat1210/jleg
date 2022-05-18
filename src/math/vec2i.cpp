#include "vec2i.hpp"

namespace jleg{
    vec2i::vec2i(){
        this->x = 0;
        this->y = 0;
    };

    vec2i::vec2i(int _x, int _y){
        this->x = _x;
        this->y = _y;
    };

    std::string vec2i::printable(){
        std::string output;
        output = "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
        return output;
    };

    vec2i vec2i::operator+(vec2i _by){
        return vec2i(this->x + _by.x, this->y + _by.y);
    };

    vec2i vec2i::operator*(int _by){
        return vec2i(this->x*_by, this->y*_by);
    };
    
    vec2i vec2i ::operator*(vec2i _by){
        return vec2i(this->x * _by.x, this->y * _by.y);
    };
};
