#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "vec2.hpp"
#include "box2d/box2d.h"
#include <iostream>

namespace jleg{
    // namespace physics{
    enum body_type{
        STATIC_BODY,
        CHARACTER_BODY
    };
    extern float cell_size;
    extern int velocity_iterations;
    extern int position_iterations;
    extern float time_step;
    extern vec2 gravity;
    extern b2World world;
    void init_physics(vec2 _gravity);
    void step();
    b2Body* create_body(body_type type, vec2 _position, vec2 _size);
    // };
};

#endif

// physics(vec2 _gravity);

// const unsigned int CELL_SIZE = 16;
// void step();
// extern int cell_size;
// extern int velocity_iterations;
// extern int position_iterations;
// extern float time_step;
// extern vec2 gravity; //move to physics
// extern b2World world; //move to physics
// void init(vec2 _gravity);
// void create_body(int type, vec2 _size){
