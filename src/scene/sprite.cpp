#include "sprite.hpp"

namespace jleg{
    sprite::sprite(){
        //do nothing
    };

    sprite::sprite(const char* _texture){
        this->tex = texture(_texture);
    };

    void sprite::update(){
        drawer.draw(this->tex, this->get_global_model_matrix());
    };
};
