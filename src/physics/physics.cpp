#include "physics.hpp"

namespace jleg{
    float cell_size = 16;
    int velocity_iterations = 1;
    int position_iterations = 1;
    float time_step = 1.0f / 144.0f;
    vec2 gravity = vec2(0.0f, -32.0f);
    b2World world(gravity.to_box2d());
    void init_physics(vec2 _gravity){
        gravity = _gravity;
        // world.SetGravity(_gravity.to_box2d());
    };
    void step(){
        world.Step(time_step, velocity_iterations, position_iterations);
    };
    b2Body* create_body(body_type type, vec2 _position, vec2 _size){
        //jank but cant be bothered
        b2BodyDef body_def;
        b2PolygonShape box;
        b2FixtureDef fixture;
        //maybe a local variable?
        //no
        b2Body* _body;
        switch (type){
            case CHARACTER_BODY:
                body_def.type = b2_dynamicBody;
                body_def.position.Set(_position.x / cell_size, _position.y / cell_size);
                _body = world.CreateBody(&body_def);
                _body->SetFixedRotation(true);
                box.SetAsBox(_size.x / 2.0f / cell_size, _size.y / 2.0f / cell_size);
                fixture.shape = &box;
                fixture.friction = 0.0f;
                fixture.density = 1.0f;
                _body->CreateFixture(&fixture);
                break;
            case STATIC_BODY:
                body_def.position.Set(_position.x / cell_size, _position.y / cell_size);
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
};
// jleg::physics::gravity = _gravity;
// jleg::physics::world = b2World(_gravity.to_box2d());
// std::cout << "static_body" << std::endl;

//static body

// this->body->CreateFixture(&ground_box, 0.0f);
// ground_box.SetAsBox(this->size.x / 2.0f, this->size.y / 2.0f);
// this->body = world->CreateBody(&ground_body_def);
//ground_body_def.position.Set(this->position.x, this->position.y);
//character_body

// this->body->CreateFixture(&dynamic_box, 1.0f);
// dynamic_box.SetAsBox(this->size.x / 2.0f, this->size.y / 2.0f);
// b2PolygonShape box;// b2PolygonShape dynamic_box;

//this->body->SetFixedRotation(true);
// this->body = _world->CreateBody(&body_def);
// std::cout << "character_body" << std::endl;//code is being ran
// body_def.position.Set(this->position.x, this->position.y);
//but body does not move
// b2BodyDef body_def;

// b2PolygonShape ground_box;
//b2BodyDef ground_body_def;
// std::cout << gravity.y;

// vec2 gravity;
// b2World world(vec2(0.0f, 0.0f).to_box2d());
// namespace physics{
// };

//static body
// this->size = _size;
// this->position = _position;

//character_body
// this->size = _size;
// this->position = _position;

// cell_size = 16;
// velocity_iterations = 2;
// position_iterations = 1;
// time_step = 1.0f / 60.0f;
// physics(vec2 _gravity);


// namespace jleg{
//     physics::physics(vec2 _gravity){
//         this->gravity = _gravity;
//         this->world = b2World(jleg::gravity.to_box2d());
//     };
//     void step(){
//         this->world.Step(this->time_step, this->velocity_iterations, this->position_iterations);
//     };
// }



// namespace jleg{
    //     void init(vec2 _gravity){
        //         gravity = _gravity;
        //         world = b2World(jleg::gravity.to_box2d());
        //         cell_size = 16;
        //         velocity_iterations = 2;
        //         position_iterations = 1;
        //         time_step = 1.0f / 60.0f;
        //     };
        //
        //     void step(){
            //         world.Step(jleg::time_step, jleg::velocity_iterations, jleg::position_iterations);
            //     };
            // };
            // };
