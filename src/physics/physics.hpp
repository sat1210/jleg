#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "vec2.hpp"
#include "box2d/box2d.h"
#include <iostream>

namespace jleg{
    enum body_type{
        STATIC_BODY,
        CHARACTER_BODY
    };
    extern float cell_size;
    extern int velocity_iterations;
    extern int position_iterations;
    extern float time_step;
    extern float physics_time_step;
    extern vec2 gravity;
    extern b2World world;
    void init_physics(vec2 _gravity);
    void step();
    b2Body* create_body(body_type type, vec2 _position, vec2 _size);
    vec2 get_body_position(b2Body* _body);
};

#endif
