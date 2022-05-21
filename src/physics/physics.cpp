#include "physics.hpp"

namespace jleg{
    float cell_size = 16;
    int velocity_iterations = 1;
    int position_iterations = 1;
    float time_step = 1.0f / 144.0f;
    float physics_time_step = 1.0f / 144.0f;
    vec2 gravity = vec2(0.0f, -32.0f);
    b2World world(gravity.to_box2d());
    void init_physics(vec2 _gravity){
        gravity = _gravity;
    };
    void step(){
        world.Step(time_step, velocity_iterations, position_iterations);
    };
    b2Body* create_body(body_type type, vec2 _position, vec2 _size){
        b2BodyDef body_def;
        b2PolygonShape box;
        b2FixtureDef fixture;
        b2Body* _body;
        switch (type){
            case CHARACTER_BODY:
                body_def.type = b2_dynamicBody;
                body_def.position.Set(_position.x / cell_size, _position.y / cell_size * -1.0f);
                _body = world.CreateBody(&body_def);
                _body->SetFixedRotation(true);
                box.SetAsBox(_size.x / 2.0f / cell_size, _size.y / 2.0f / cell_size);
                fixture.shape = &box;
                fixture.friction = 0.0f;
                fixture.density = 1.0f;
                _body->CreateFixture(&fixture);
                break;
            case STATIC_BODY:
                body_def.position.Set(_position.x / cell_size, _position.y / cell_size * -1.0f);
                _body = world.CreateBody(&body_def);
                box.SetAsBox(_size.x / 2.0f / cell_size, _size.y / 2.0f / cell_size);
                fixture.shape = &box;
                fixture.friction = 0.0f;
                fixture.density = 1.0f;
                _body->CreateFixture(&fixture);
                break;
        };
        return _body;
    };
    vec2 get_body_position(b2Body* _body){
        return vec2(_body->GetPosition()) * vec2(1.0f, -1.0f) * cell_size;
    };

};
