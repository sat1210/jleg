#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "stb_image.h"
#include "node.hpp"
#include "texture.hpp"

namespace jleg{
    class sprite : public node{
        public:
            texture tex;
            sprite();
            sprite(const char* _texture);
            update();
    };
};

#endif
