#include "static_body.hpp"

jleg::static_body::static_body(){
    //do nothing
};

jleg::static_body::static_body(jleg::vec2 _position, jleg::vec2 _size){
    this->size = _size;
    this->position = _position;

    this->body = jleg::create_body(jleg::STATIC_BODY, this->position, this->size);

};

// jleg::physics::body_type type = jleg::physics::STATIC_BODY;
// b2BodyDef ground_body_def;
// ground_body_def.position.Set(this->position.x, this->position.y);;
//
// this->body = _world->CreateBody(&ground_body_def);
//
// b2PolygonShape ground_box;
// ground_box.SetAsBox(this->size.x / 2.0f, this->size.y / 2.0f);
//
// this->body->CreateFixture(&ground_box, 0.0f);
