#include "vec2.hpp"

jleg::vec2::vec2(){
    this->x = 0.0f;
    this->y = 0.0f;
};

jleg::vec2::vec2(float _x, float _y){
    this->x = _x;
    this->y = _y;
};

jleg::vec2::vec2(b2Vec2 _b2vec2){
    this->x = _b2vec2.x;
    this->y = _b2vec2.y;
};

jleg::vec2::vec2(glm::vec2 _glmvec2){
    this->x = _glmvec2.x;
    this->y = _glmvec2.y;
};

b2Vec2 jleg::vec2::to_box2d(){
    return b2Vec2(this->x, this->y);
};

glm::vec2 jleg::vec2::to_glm(){
    return glm::vec2(this->x, this->y);
};

jleg::vec2 jleg::vec2::operator+(jleg::vec2 _by){
    return vec2(this->x + _by.x, this->y + _by.y);
};

jleg::vec2 jleg::vec2::operator*(float _by){
    return vec2(this->x * _by, this->y * _by);
};

jleg::vec2 jleg::vec2::operator*(jleg::vec2 _by){
    return vec2(this->x * _by.x, this->y * _by.y);
};

// void jleg::vec2::from_box2d(b2Vec2 _b2vec2){
//     this->x = _b2vec2.x;
//     this->y = _b2vec2.y;
// };
//
// void jleg::vec2::from_glm(glm::vec2 _glmvec2){
//     this->x = _glmvec2.x;
//     this->y = _glmvec2.y;
// };
