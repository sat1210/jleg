#ifndef STATIC_BODY_HPP
#define STATIC_BODY_HPP

// #include "box2d/box2d.h"
// #include "glm/glm.hpp"
#include "node.hpp"
#include "vec2.hpp"
#include "physics.hpp"
#include <iostream>

namespace jleg{
    class static_body : public node{
        public:
            static_body();
            static_body(jleg::vec2 _position, jleg::vec2 _size);
            jleg::vec2 size;
            b2Body* body;
    };
}

#endif
