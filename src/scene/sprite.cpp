#include "sprite.hpp"

namespace jleg{
    sprite::sprite(){
        //do nothing
    };

    sprite::sprite(const char* _texture){
        this->tex = texture(_texture);
    };

    sprite::update(){
        // do nothing, yet
    };
}
