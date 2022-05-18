#include "sprite.hpp"

namespace jleg{
    sprite::sprite(){
        this->name = "Sprite";
    };

    sprite::sprite(const char* _texture){
        this->name = "Sprite";
        this->tex = texture(_texture);
        this->tex.centered = true;
    };

    void sprite::update(){
        drawer.draw(this->tex, this->get_global_model_matrix());
    };
};
