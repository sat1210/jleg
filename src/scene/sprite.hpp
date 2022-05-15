#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "stb_image.h"
#include "node.hpp"
#include "texture.hpp"
#include "sprite_drawer.hpp"

namespace jleg{
    class sprite : public node{
        public:
            texture tex;
            sprite_drawer drawer;
            sprite();
            sprite(const char* _texture);
            void update();
    };
};

#endif
