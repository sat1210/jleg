#ifndef CHARACTER_BODY_HPP
#define CHARACTER_BODY_HPP

// #include "box2d/box2d.h"
// #include "glm/glm.hpp"
#include "node.hpp"
#include "vec2.hpp"
#include "physics.hpp"


namespace jleg{
    class character_body : public node{
        public:
            vec2 size;
            b2Body* body;
            character_body();
            character_body(jleg::vec2 _position, jleg::vec2 _size);
            void set_velocity(jleg::vec2 _velocity);
            bool is_on_floor();
    };
};

#endif
// b2World world(gravity); //move to physics
//_world should be implemented in physics and #include "physics.hpp"

                // b2FixtureDef fixture_def;
                // fixture_def.shape = &dynamic_box;
                // fixture_def.density = 1.0f;
                // fixture_def.friction = 0.3f;

                // body->CreateFixture(&fixture_def);
                // b2PolygonShape shape;
