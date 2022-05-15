#ifndef VEC2_HPP
#define VEC2_HPP

#include "box2d/box2d.h"
#include "glm/glm.hpp"

namespace jleg{
    class vec2{
        public:
            float x;
            float y;
            vec2();
            vec2(float _x, float _y);
            vec2(b2Vec2 _b2vec2);
            vec2(glm::vec2 _glmvec2);
            b2Vec2 to_box2d();
            glm::vec2 to_glm();
            vec2 operator+(vec2 _by);
            vec2 operator*(float _by);
            vec2 operator*(vec2 _by);
            // void from_box2d(b2Vec2 _b2vec2);
            // void from_glm(glm::vec2 _glmvec2);
    };
};

#endif
