#include "sprite.hpp"

namespace jleg{
    sprite::sprite(){
        this->name = "Sprite";
    };

    sprite::sprite(const char* _texture){
        this->name = "Sprite";
        this->tex = texture(_texture);
        this->tex.centered = true;
        this->drawer = jleg::drawer;
    };

    void sprite::update(){
        this->drawer.draw(this->tex, this->get_global_model_matrix());
    };
};
