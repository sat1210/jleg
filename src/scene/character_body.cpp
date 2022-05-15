#include "character_body.hpp"

jleg::character_body::character_body(){
    //do nothing
};

jleg::character_body::character_body(jleg::vec2 _position, jleg::vec2 _size){
    this->size = _size;
    this->position = _position;

    this->body = jleg::create_body(jleg::CHARACTER_BODY, this->position, this->size);
};

// jleg::physics::body_type type = jleg::physics::CHARACTER_BODY;
    // b2BodyDef body_def;
    // body_def.type = b2_dynamicBody;
    // body_def.position.Set(this->position.x, this->position.y);
    //
    // this->body = _world->CreateBody(&body_def);
    // this->body->SetFixedRotation(true);
    //
    // b2PolygonShape dynamic_box;
    // dynamic_box.SetAsBox(this->size.x / 2.0f, this->size.y / 2.0f);
    //
    // this->body->CreateFixture(&dynamic_box, 1.0f);
    // b2FixtureDef fixture_def;
    // fixture_def.shape = &dynamic_box;
    // fixture_def.density = 1.0f;
    // fixture_def.friction = 0.3f;
