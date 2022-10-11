#ifndef VEC2_HPP
#define VEC2_HPP

#include "box2d/box2d.h"
#include "glm/glm.hpp"
#include <string>
#include <iostream>
#include "vec2i.hpp"

namespace jleg{
    class vec2{
        public:
            float x;
            float y;
            vec2();
            vec2(float _x, float _y);
            vec2(double _x, double _y);
            vec2(b2Vec2 _b2vec2);
            vec2(glm::vec2 _glmvec2);
            b2Vec2 to_box2d();
            glm::vec2 to_glm();

            std::string printable();
            vec2 operator+(vec2 _by);
            vec2 operator*(float _by);
            vec2 operator*(vec2 _by);
            vec2 operator+(vec2i _by);
            vec2 operator/(float _by);
    };
};

#endif
