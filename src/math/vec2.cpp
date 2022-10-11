#include "vec2.hpp"


namespace jleg{
    vec2::vec2(){
        this->x = 0.0f;
        this->y = 0.0f;
    };

    vec2::vec2(float _x, float _y){
        this->x = _x;
        this->y = _y;
    };

    vec2::vec2(double _x, double _y){
        this->x = (float)_x;
        this->y = (float)_y;
    };


    vec2::vec2(b2Vec2 _b2vec2){
        this->x = _b2vec2.x;
        this->y = _b2vec2.y;
    };

    vec2::vec2(glm::vec2 _glmvec2){
        this->x = _glmvec2.x;
        this->y = _glmvec2.y;
    };

    b2Vec2 vec2::to_box2d(){
        return b2Vec2(this->x, this->y);
    };

    glm::vec2 vec2::to_glm(){
        return glm::vec2(this->x, this->y);
    };

    vec2 vec2::operator+(vec2 _by){
        return vec2(this->x + _by.x, this->y + _by.y);
    };

    vec2 vec2::operator+(vec2i _by){
        return vec2(this->x + (float)_by.x, this->y + (float)_by.y);
    };

    vec2 vec2::operator*(float _by){
        return vec2(this->x * _by, this->y * _by);
    };

    vec2 vec2::operator*(vec2 _by){
        return vec2(this->x * _by.x, this->y * _by.y);
    };

    vec2 vec2::operator/(float _by){
        return vec2(this->x / _by, this->y / _by);
    };


    std::string vec2::printable(){
        std::string output;
        output = "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
        return output;
    };
};
